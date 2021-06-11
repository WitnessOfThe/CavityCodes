    function L_L_1 = BranchTurning(Slv_start,x_0,L_L,sg)

        Slv        = Slv_start;
        i          = 0;
        Exitflag   = 1;
        x_step     = L_L.Par.first_step;
        x          = x_0;
        L_L_1      = L_L;
        
%         for iii = 1:L_L.Par.i_max
%             
%             L_L_1(iii) =  L_L;
%             
%         end
        
        while Exitflag ~= 0
            
            Exitflag = 0;
            i = i+1;
            
            if i >= 2
                
                L_L_1(i)    = L_L_1(i-1);
                
            end
                        
            Slv_0     = Slv;
            FlagReduce = 1;
           
            while  FlagReduce == 1 
        
                x_step     = L_L.Par.step_inc*x_step;
                
                if abs(x_step) > L_L.Par.max_step
                    x_step = L_L.Par.max_step;
                end
                x          = x + sg*x_step;
                L_L_1(i)   = step_eq(L_L_1(i),x);
                  
                %evalute solution
                [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,L_L_1(i));

                [i,norm(eps_f),x_step]
                
                L_L_1(i).Sol.eps_f = eps_f;
                L_L_1(i)           = L_L.Met.Prop_Gen(Slv,L_L_1(i));     
                
                if i == 1
                    
                    [FlagReduce,FlagStop,Logic] = L_L.Met.Newton_Fail_Check(L_L_1(i),i,x_step);
                    
                end                
                if i == 2 
                    
                    [FlagReduce,FlagStop,Logic] = L_L.Met.Newton_Fail_Check(L_L_1(i-1:i),i,x_step);
                    
                end
                if i >= 3
                    
                    [FlagReduce,FlagStop,Logic] = L_L.Met.Newton_Fail_Check(L_L_1(i-2:i),i,x_step);
                    
                end
                    
                
                L_L_1(i).Logic = Logic;
                
                 
                if FlagReduce
                    
                    Slv        = Slv_0;
                    x          = x - sg*x_step;
                    x_step     = x_step*L_L.Par.step_dec;            
                   
                end
                
                if FlagStop
                    
                    Exitflag = 0;
                    break;
                    
                end
                                
                if Logic.TurnTime  == 1 && FlagReduce == 0
                                        Exitflag = 0;
                            break;          
      
                       for it = 1:size(L_L_1,2)
                         maxvec(it) = real(L_L_1(it).Sol.Psi_k(1));
                         devec(it) =  L_L_1(it).Eq.(L_L_1(it).Par.variable);
                      end

                     [Slv,L_L_Turn]    = Turning_Regime(Slv,L_L_1(i));
                     
                     if size(L_L_Turn,2) == 1
                            Exitflag = 0;
                            break;          
                     end
                     Nturn = size(L_L_Turn,2);
                     x =L_L_Turn(end).Eq.(L_L_Turn(end).Par.variable);
                     x_step = abs(L_L_Turn(end).Eq.(L_L_Turn(end).Par.variable)...
                         -L_L_Turn(end-1).Eq.(L_L_Turn(end).Par.variable));
                     sg = sign(L_L_Turn(end).Eq.(L_L_Turn(end).Par.variable)...
                         -L_L_Turn(end-1).Eq.(L_L_Turn(end).Par.variable));   
                     L_L_1(i+1:i+Nturn)   =  L_L_Turn;   
                     i = i + Nturn;
                     
                     if L_L_Turn(end).Logic.Resid == 1 || L_L_Turn(end).Logic.rCW
                        Exitflag = 0;
                        break;
                     end
%                     i  = i + 1;
%                     L_L_1(i) = L_L_Turn(end);
%                     
%                     sg   = - sg;
%                     Turn = 0;
% 
%                     [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,L_L_1(i));
%                     L_L_1(i)             = L_L.Met.Prop_Gen(Slv,L_L_1(i));     
                    
                end
            end
                       
            
            switch L_L.Par.Stability
                
                case 1
                    
                    L_L_1(i).Stab                 = Stability_Switcher(L_L_1(i));
                    
                case 0
                    
                    L_L_1(i).Stab.E_values  = NaN;
                    L_L_1(i).Stab.E_vectors = NaN;
                    
            end
                                   
        end
        
        L_L_1(i+1:end) = [];
        
    
        
        
    
        function Stat   = step_eq(Stat,x)
            switch Stat.Par.variable
                case 'Fin_D'
                            Stat.In.Fin_D     = x;
                            Stat.In.kappa     = Stat.In.D(2)/Stat.In.Fin_D;
                            Stat.In.delta     = Stat.In.kappa*Stat.Eq.delta;
                            Stat.In.P         = Stat.In.W_WStar*pi/(Stat.In.eta*Stat.In.D(1)/Stat.In.kappa)*Stat.In.kappa/Stat.In.gamma; 
                            Stat = Stat.Met.Norm(Stat);
                otherwise
                    
                    Stat.Eq.(Stat.Par.variable) = x;
                    Stat.In.(Stat.Par.variable) = Stat.Eq.norm*Stat.Eq.(Stat.Par.variable);
                    Stat = Stat.Met.Norm(Stat);
                    
            end
        end
       
        function [Slv,Stat] = Turning_Regime(Slv_Start,Stat)
            Slv  = [0,Slv_Start(2:end)];
            
            Stat.Met.Equation             = L_L.Met.Equation_Mod;             
            Stat.Met.Liniar_Decomposition = L_L.Met.Liniar_Decomposition_Mod;
            Stat.Met.Preconditioner       = L_L.Met.Preconditioner_Mod;            
         %   Stat.Par.Newton_tol           = 1e-11;
            ii = 1;
            Flag = 0;
            
            if Stat.Logic.Dir.y3-Stat.Logic.Dir.y2 ~= 0 || ~isnan(Stat.Logic.Dir.d12)
                Stat(ii).Eq.PsioMax = Stat(ii).Logic.Dir.y3 ...
                    + Stat.Logic.Dir.y3-Stat.Logic.Dir.y2; 
            else
                               Stat(ii).Eq.PsioMax = Stat(ii).Logic.Dir.y3 ...
                    + (Stat.Logic.Dir.y2-Stat.Logic.Dir.y1); 
            end
            
            smcoeff   = 1.1;
            
            while ii < 1400
                
                ii                    = ii + 1;
                Stat(ii)              = Stat(ii-1);         
                Slv_prev = Slv;
                [Slv,eps_f,Exitflag]  = Newton_Switcher(Slv,Stat(ii)); 
                [ii,eps_f,Exitflag]
                
                Stat(ii)              = Stat(ii).Met.Prop_Gen(Slv,Stat(ii));                 
                
                 if ii == 2
                    [~,~,LogicT] = L_L.Met.Newton_Fail_Check(Stat(ii-1:ii)...
                        ,ii,abs(Stat(ii).Eq.(Stat(ii).Par.variable)-Stat(ii-1).Eq.(Stat(ii-1).Par.variable)));
                 end        
                 if ii > 2
                    [~,~,LogicT] = L_L.Met.Newton_Fail_Check(Stat(ii-2:ii)...
                        ,ii,abs(Stat(ii).Eq.(Stat(ii).Par.variable)-Stat(ii-1).Eq.(Stat(ii-1).Par.variable)));
                 end
                 
                 Stat(ii).Logic = LogicT;
                 Stat(ii).Logic.Turning = 1;
                 
                 
                 if abs(Stat(ii).Logic.Dir.d11) < 1 && ii > 10
                     break;
                 end       
                 if Stat(ii).Logic.rCW 
                     break;
                 end                        
                 if eps_f > Stat(1).Par.Newton_tol 
                     Stat(ii) = [];
                     ii = ii-1;
                     Slv = Slv_prev;
                     smcoeff = smcoeff*0.1;
                     if smcoeff <= 1E-10
                          break;
                     end
                 else
                     
                     smcoeff = smcoeff;
                     
                 end
                 if ii >=3
                     
                    absstep = Stat(ii).Logic.Dir.y3 - Stat(ii).Logic.Dir.y2;
                    
                    if absstep == 0 
                        absstep = 1E-9*sign(Stat(1).Logic.Dir.y2-Stat(1).Logic.Dir.y1);
                    end
                    
                    Stat(ii).Eq.PsioMax = Stat(ii).Logic.Dir.y3  + absstep*smcoeff;                 
    
                 end
                if  ii == 2
                     
                    Stat(ii).Eq.PsioMax = Stat(ii).Logic.Dir.y2 ...
                    + (Stat(ii).Logic.Dir.y2-Stat(ii).Logic.Dir.y1)*smcoeff; 
                
                 end
                 if  ii == 1
                     
                Stat(ii).Eq.PsioMax = Stat(ii).Logic.Dir.y3 ...
                    + (Stat.Logic.Dir.y3-Stat.Logic.Dir.y2)*smcoeff; 
                
                 end
                  
            end
 %% if something wrong
            devec =  [];   
            maxvec = [];
            for it = 1:size(Stat,2)
                maxvec(it) = real(Stat(it).Sol.Psi_k(1));
                devec(it) =  Stat(it).Eq.(Stat(it).Par.variable);
            end
            
            %%
            Stat(end).Met.Equation             = L_L.Met.Equation;             
            Stat(end).Met.Liniar_Decomposition = L_L.Met.Liniar_Decomposition;
            Stat(end).Met.Preconditioner       = L_L.Met.Preconditioner;    
            
            Slv(1)                             = Stat(end).Eq.PsioMax*Stat(end).Space.N;
            [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,Stat(end));
            Stat(end)            = Stat(end).Met.Prop_Gen(Slv,Stat(end));                 

            
        end
    end
    
