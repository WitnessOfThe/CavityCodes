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
                    
                    L_L_1(i).Sol.Linear_Stability = struct;
                    L_L_1(i).Stab                 = Stability_Switcher(L_L_1(i));
                    
                case 0
                    
                    L_L_1(i).Stab.E_values  = NaN;
                    L_L_1(i).Stab.E_vectors = NaN;
                    
            end
                                   
        end
        
        L_L_1(i+1:end) = [];
        
    
        
        
    
        function Stat   = step_eq(Stat,x)
            
            Stat.Eq.(Stat.Par.variable) = x;
            Stat.In.(Stat.Par.variable) = Stat.Eq.norm*Stat.Eq.(Stat.Par.variable);
            Stat = Stat.Met.Norm(Stat);

        end
        function Stat  = confirm_step_eq(Slv,Stat)
            
            Stat.Eq.(Stat.Par.variable) = Stat.Eq.(Stat.Par.variable)+ Slv(end);
            Stat.In.(Stat.Par.variable) = Stat.Eq.norm*Stat.Eq.(Stat.Par.variable);
            Stat                        = Stat.Met.Norm(Stat);

        end
    
        function [Slv,Stat] = Turning_Regime(Slv_Start,Stat)
            Slv  = [Slv_Start,0];
            
            Stat.Met.Equation             = L_L.Met.Equation_Mod;             
            Stat.Met.Liniar_Decomposition = L_L.Met.Liniar_Decomposition_Mod;
            Stat.Met.Preconditioner       = L_L.Met.Preconditioner_Mod;            
            
            ii = 1;
            Flag = 0;
            
            if Stat.Logic.Dir.y3-Stat.Logic.Dir.y2 ~= 0 || ~isnan(Stat.Logic.Dir.d12)
                Stat(ii).Eq.PsioMax = Stat(ii).Logic.Dir.y3 ...
                    + Stat.Logic.Dir.y3-Stat.Logic.Dir.y2; 
            else
                               Stat(ii).Eq.PsioMax = Stat(ii).Logic.Dir.y3 ...
                    + (Stat.Logic.Dir.y2-Stat.Logic.Dir.y1)/10; 
            end
            
            smcoeff   = 1;
            
            while ii < 1400
                
                ii                    = ii + 1;
                Stat(ii)              = Stat(ii-1);         
                
                [Slv,eps_f,Exitflag]  = Newton_Switcher(Slv,Stat(ii)); 
                [ii,eps_f,Exitflag]
                
                Stat(ii)              = confirm_step_eq(Slv,Stat(ii));
                Stat(ii)              = Stat(ii).Met.Prop_Gen(Slv,Stat(ii));                 
                
                 if ii == 2
                    [~,~,Stat(ii).Logic] = L_L.Met.Newton_Fail_Check(Stat(ii-1:ii)...
                        ,ii,abs(Stat(ii).Eq.(Stat(ii).Par.variable)-Stat(ii-1).Eq.(Stat(ii-1).Par.variable)));
                 end        
                 if ii > 2
                    [~,~,Stat(ii).Logic] = L_L.Met.Newton_Fail_Check(Stat(ii-2:ii)...
                        ,ii,abs(Stat(ii).Eq.(Stat(ii).Par.variable)-Stat(ii-1).Eq.(Stat(ii-1).Par.variable)));
                 end
                 
                 Stat(ii).Logic.Turning = 1;
                 
                 
                 if abs(Stat(ii).Logic.Dir.d12) < 0.5 && ii > 10
                     break;
                 end       
                 if Stat(ii).Logic.rCW 
                     break;
                 end                        
%                  if eps_f > 1
%                      Stat(ii) = [];
%                      ii = ii-1;
%                      break;
%                  end                        
                 if eps_f > 1E-8
                     Stat(ii) = [];
                     ii = ii-1;
                     Slv = [real(ifft(Stat(end).Sol.Psi_o)),imag(ifft(Stat(end).Sol.Psi_o)),real(ifft(Stat(end).Sol.Psi_e)),imag(ifft(Stat(end).Sol.Psi_e)),Stat(end).Sol.V/Stat(end).Space.N,0]*Stat(end).Space.N;
                     smcoeff = smcoeff*0.1;
                     if smcoeff <= 1E-10
                          break;
                     end
                 else
                     
                     smcoeff = smcoeff*1.01;
                     
                 end
                 if ii >=2
                     
                    absstep = max(abs(ifft(Stat(ii).Sol.Psi_o*Stat(ii).Space.N)).^2) ...
                        -  max(abs(ifft(Stat(ii-1).Sol.Psi_o*Stat(ii-1).Space.N)).^2);
                    if absstep == 0 
                        absstep = 1E-8*sign(Stat(1).Logic.Dir.y2-Stat(1).Logic.Dir.y1);
                    end
                    Stat(ii).Eq.PsioMax = max(abs(ifft(Stat(ii).Sol.Psi_o*Stat(ii).Space.N)).^2) ...
                         + absstep*smcoeff;                 
                     
                 else
                     
                    Stat(ii).Eq.PsioMax = Stat(ii).Logic.Dir.y3 ...
                    + (Stat.Logic.Dir.y2-Stat.Logic.Dir.y1)*smcoeff; 
                
                 end
            end
 %% if something wrong
            for it = 1:size(Stat,2)
                maxvec(it) = max(abs(ifft(Stat(it).Sol.Psi_o*Stat(end).Space.N)).^2);
                devec(it) =  Stat(it).Eq.(Stat(it).Par.variable);
            end
            
            %%
            Stat(end).Met.Equation             = L_L.Met.Equation;             
            Stat(end).Met.Liniar_Decomposition = L_L.Met.Liniar_Decomposition;
            Stat(end).Met.Preconditioner       = L_L.Met.Preconditioner;            
            Slv(end) = [];
            
            [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,Stat(end));
            Stat(end)              = Stat(end).Met.Prop_Gen(Slv,Stat(end));                 

            
        end
    end
    
