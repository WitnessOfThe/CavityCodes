    function L_L_1 = Branch(Slv_start,x_0,L_L,sg)

        Slv        = Slv_start;
        i          = 0;
        Exitflag   = 1;
        x_step     = L_L.Par.first_step;
        x          = x_0;
        L_L_1      = L_L;
        
        for iii = 1:L_L.Par.i_max
            
            L_L_1(iii) =  L_L;
            
        end
        Turn = 0;
         i_turn = 0;
        while Exitflag ~= 0
            
            Exitflag = 0;
            i = i+1;
            
            if i >= 2
                
                L_L_1(i)    = L_L_1(i-1);
                
            end
                        
            Slv_0 = Slv;
            Breakflag = 1;
           
            while  Breakflag == 1 
                
                x_step     =  L_L.Par.step_inc*x_step;
                x          = x + sg*x_step;
                L_L_1(i)   = step_eq(L_L_1(i),x);
                                       
                [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,L_L_1(i));

                [i,norm(eps_f),x_step]
                
                L_L_1(i)             = L_L.Met.Prop_Gen(Slv,L_L_1(i));     
                
                if i>= 2
                    
                    [Breakflag,Logic] = L_L.Met.Newton_Fail_Check(L_L_1(i-1:i),i,x,Exitflag,x_step);
            
                else
                    
                    [Breakflag,Logic] = L_L.Met.Newton_Fail_Check(L_L_1(i),i,x,Exitflag);
                    
                end
                
                L_L_1(i).Logic = Logic;
                
                 
                if Breakflag == 1 
                    
                    Slv        = Slv_0;
                    x          = x - sg*x_step;
                    x_step     = x_step*L_L.Par.step_dec;            
                   
                end
                if Logic.rCW &&  Logic.r_tol
                    Exitflag = 0;
                    break;
                end


                if Logic.r_tol == 1
                    Exitflag = 0;
                    break;
                end
                
%                 if Logic.r_9 && L_L.Par.Turning == 1
%                     Turn = 1;
%                     i_turn = i_turn +1; 
%                     if i_turn > 1
%                         Turn =0;
%                         Exitflag = 0;
%                         break;
%                     end
%                 end
%                 
%                 if Turn == 1
%                 
%                     L_L_1(i)   = step_eq(L_L_1(i),x);
%                     [Slv,sg,L_L_Turn]               = Turning_Regime(Slv,sg,L_L_1(i));                 
%                     
%                     i  = i + 1;
%                     L_L_1(i) = L_L_Turn(end);
%                     
%                     sg   = - sg;
%                     Turn = 0;
% 
%                     [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,L_L_1(i));
%                     L_L_1(i)             = L_L.Met.Prop_Gen(Slv,L_L_1(i));     
%                     
%                 end
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
    
        function [Slv,sg,Stat] = Turning_Regime(Slv_Start,sg,Stat)
            Slv  = [Slv_Start,0];
            
            Stat.Met.Equation             = L_L.Met.Equation_Mod;             
            Stat.Met.Liniar_Decomposition = L_L.Met.Liniar_Decomposition_Mod;
            Stat.Met.Preconditioner       = L_L.Met.Preconditioner_Mod;            
            Stat.Eq.PsioMax               = L_L.Met.Evaluate_trend(L_L_1(i-3:i),1);            
            
            ii = 1;
            Flag = 0;
            
            while Flag == 0
                
                ii                    = ii + 1;
                Stat(ii)              =  Stat(ii-1);
                [Slv,eps_f,Exitflag]  = Newton_Switcher(Slv,Stat(ii)); 
                Stat(ii)              = confirm_step_eq(Slv,Stat(ii));
                Stat(ii)              = Stat(ii).Met.Prop_Gen(Slv, Stat(ii)); 
                Stat(ii).Eq.PsioMax   = Stat(ii).Met.Evaluate_trend(Stat(ii-1:ii),ii);            
                
                if ii >= 2
                    [Flag,Logic] = Stat(ii).Met.Newton_Turning_Fail_Check(Stat(ii-1:ii),ii,Exitflag);
                else
                    [Flag,Logic] = Stat(ii).Met.Newton_Turning_Fail_Check(Stat(ii),ii,Exitflag);
                end
                Stat(ii).Logic  = Logic;
            end
            
            Stat(end).Met.Equation             = L_L.Met.Equation;             
            Stat(end).Met.Liniar_Decomposition = L_L.Met.Liniar_Decomposition;
            Stat(end).Met.Preconditioner       = L_L.Met.Preconditioner;            
            Slv(end) = [];
            
            end
    end
    
