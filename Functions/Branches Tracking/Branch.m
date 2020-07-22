    function L_L_1 = Branch(Dir,Slv_start,x_0,Delta,L_L,sg,Equation,options)

        Slv        = (Slv_start);
        i          = 0;
        Exitflag   = 1;
        x_step     = Delta.first_step;
        x          = x_0;
        L_L_1      = L_L;
        
        while Exitflag ~= 0
            
            Exitflag = 0;
            i = i+1;
            
            if i>=2
                
                L_L_1(i)    = L_L_1(i-1);
                
            end
                        
            x_step = 1.01*x_step;
            x     = sg*x_step + x;
            
%             while x < 0
%                 x     = - sg*x_step + x;
%                 x_step = x_step/2;
%                 x     = sg*x_step + x;
%             end
            
            Slv_0 = Slv;
            
            while (Exitflag == 0) && (Delta.step_tol < x_step)
                
                L_L_1(i)             = step_eq(L_L_1(i),x);
                                       
                [Slv,eps_f,Exitflag] = Newton_Switcher(Dir,Slv,L_L_1(i),Delta,Equation,options);

                [i,norm(eps_f),x_step];
                L_L_1(i).Solution    = struct;
                L_L_1(i)             = Prop_gen(L_L_1(i),Slv,Delta);     
                
                [Breakflag,L_L_1] = fail_check_step_sizing(L_L_1,i);
                
                if Breakflag == 1 || (Exitflag <= 0)
                    
                    Exitflag = 0;
                    
                end
                
                if (Exitflag <= 0) 
                    
                    Slv        = Slv_0;
                    x          = x - sg*x_step;
                    x_step     = x_step*0.25;
                    x          = x + sg*x_step;
                    
                end
                
                
            end
            


            [Breakflag,L_L_1] = fail_check(L_L_1,i);
            
            if Breakflag == 1
                
                break;
                
            end
            
            switch Delta.Stability
                
                case 'Yes'
                    
                    L_L_1(i).Solution.Linear_Stability = struct;
                    L_L_1(i)                           = Stability_Switcher(Dir,Delta,L_L_1(i));
                    
                case 'No'
                    
                    L_L_1(i).Solution.Linear_Stability.E_values  = NaN;
                    L_L_1(i).Solution.Linear_Stability.E_vectors = NaN;
                    
            end
            
            L_L_1(i).Eq.V_cr = 0;
            L_L_1(i)         = CW   (L_L_1(i));     
       %     L_L_1(i)         = CW_Stability(L_L_1(i));     
            
            
        end
        
        L_L_1(end) = [];
        
        function [Flag,L_L] = fail_check(L_L,i)
            
            if i>=3
                
                Logic.r_1 = 0;%isequal(L_L(i).Solution.Amplitude,L_L(i-1).Solution.Amplitude);
                Logic.r_2 = 0; 
                
            else
                
                Logic.r_1 = 0;
                Logic.r_2 = 0;
                
            end
            
            Logic.r_3  =  Exitflag == 0;
            Logic.r_4  = 0;%isnan(eps_f);
            Logic.r_5  = max(abs(L_L(i).Solution.Psi)) - min(abs(L_L(i).Solution.Psi)) < 1E-18;
            Logic.r_6  = i == Delta.i_max;
            Logic.r_7 = isequal(Delta.variable,'delta') && L_L(i).Eq.delta <= 0;
            Logic.r_8 = isequal(Delta.variable,'gamma') && L_L(i).Eq.gamma < 0;
            
            L_L(i).Failreason = Logic;
            
            Flag = (Logic.r_1 || Logic.r_2 || Logic.r_3 || Logic.r_4 || Logic.r_5 || Logic.r_6 || Logic.r_7 || Logic.r_8);
            
        end
        
        function [Flag,L_L] = fail_check_step_sizing(L_L,i)

            Flag =0;
            
            if i>=3
                
                Flag = ~(abs(L_L(i).Solution.Amplitude-L_L(i-1).Solution.Amplitude) <= 3*abs(L_L(i-1).Solution.Amplitude-L_L(i-2).Solution.Amplitude));
                
            end 
            
        end
    
        function L_L   = step_eq(L_L,x)
            
            switch Delta.variable
                
                case 'delta'
                    
                    L_L.Eq.delta = x;
                    
                case 'kappa'
                    
                    L_L.Eq.kappa = x;
                    
                case 'h'
                    
                    L_L.Eq.h     = x;
                    
            end
            
        end
      
    end
