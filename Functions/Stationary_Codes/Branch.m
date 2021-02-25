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
        Turn_Count = 0;
        while Exitflag ~= 0
            
            Exitflag = 0;
            i = i+1;
            
            if i >= 2
                
                L_L_1(i)    = L_L_1(i-1);
                
            end
                        
            Slv_0 = Slv;
            Breakflag = 1;
            
            while (L_L.Par.step_tol < x_step) && Breakflag == 1 
                
                x_step     =  L_L.Par.step_inc*x_step;
                x          = x + sg*x_step;
                L_L_1(i)   = step_eq(L_L_1(i),x);
                                       
                [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,L_L_1(i));

                [i,norm(eps_f),x_step]
                
                L_L_1(i)             = L_L.Met.Prop_Gen(Slv,L_L_1(i));     
                
                if i>= 2
                    
                    [Breakflag,Logic] = L_L.Met.Newton_Fail_Check(L_L_1(i-1:i),i,x,Exitflag);
               %     L_L_1(i-1).Fail_Check  = Logic;
                else
                    
                    [Breakflag,Logic] = L_L.Met.Newton_Fail_Check(L_L_1(i),i,x,Exitflag);
                    
                end
                if Breakflag == 1 
                    
                    Slv        = Slv_0;
                    x          = x - sg*x_step;
                    x_step     = x_step*L_L.Par.step_dec;            
                   
                end
                
                if (L_L.Par.step_tol > x_step) && Breakflag == 1 && L_L.Par.Turning == 1 && Logic(1).r_1 ~= 1 && Turn_Count == 0
                
                    L_L_1(i)   = step_eq(L_L_1(i),x);
                    [Slv,sg,L_L_Turn]               = Turning_Regime(Slv,sg,L_L_1(i));                 
                    
                    i  = i + 1;
                    L_L_1(i) = L_L_Turn(end);
                    
                    x_step = L_L.Par.step_tol*3.01;
                    sg   = - sg;
                    Turn_Count = 1;

                    L_L_1(i).Met.Equation             = L_L.Met.Equation;             
                    L_L_1(i).Met.Liniar_Decomposition = L_L.Met.Liniar_Decomposition;
                    L_L_1(i).Met.Preconditioner       = L_L.Met.Preconditioner;            
                    [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,L_L_1(i));
                    L_L_1(i)             = L_L.Met.Prop_Gen(Slv,L_L_1(i));     
                    
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
    
        function [Slv,sg,Stat] = Turning_Regime(Slv_Start,sg,Stat)
            Slv  = [Slv_Start,0];
            
            Stat.Met.Equation             = Stat.Met.Equation_Mod;             
            Stat.Met.Liniar_Decomposition = Stat.Met.Liniar_Decomposition_Mod;
            Stat.Met.Preconditioner       = Stat.Met.Preconditioner_Mod;            
            Stat.Eq.PsioMax               = Stat.Met.Evaluate_trend(L_L_1(i-10:i),1);            
            [Slv,eps_f,Exitflag]          = Newton_Switcher(Slv,Stat(1));
            
            if eps_f > 1E-6
                
                Slv  = [Slv_Start,0];
                Stat(1).Eq.PsioMax           = Stat(1).Met.Evaluate_trend(L_L_1(i-10:i),-1);            
                [Slv,eps_f,Exitflag]      = Newton_Switcher(Slv,Stat(1)); 

                
            end
            
            ii=1;
            
                Stat(ii+1)            = Stat(1);
                Stat(ii+1)            = confirm_step_eq(Slv,Stat(2));
                Stat(ii+1)            = Stat(ii+1).Met.Prop_Gen(Slv,Stat(2));     
                Stat(ii+1).Eq.PsioMax = Stat(ii).Met.Evaluate_trend(Stat(1:2),1);
                
            for ii = 2:15
                
                [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,Stat(ii));                 
                Stat(ii+1)           = Stat(ii);
                Stat(ii+1)           = confirm_step_eq(Slv,Stat(ii+1));
                Stat(ii+1)           = Stat(ii+1).Met.Prop_Gen(Slv,Stat(ii+1));     
                Stat(ii+1).Eq.PsioMax  = Stat(ii).Met.Evaluate_trend(Stat(ii:ii+1),1);
                
            end
            Slv(end) = [];
        end
    end
    
