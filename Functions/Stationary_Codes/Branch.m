    function L_L_1 = Branch(Slv_start,x_0,L_L,sg)

        Slv        = Slv_start;
        i          = 0;
        Exitflag   = 1;
        x_step     = L_L.Par.first_step;
        x          = x_0;
        L_L_1      = L_L;
        
        while Exitflag ~= 0
            
            Exitflag = 0;
            i = i+1;
            
            if i >= 2
                
                L_L_1(i)    = L_L_1(i-1);
                
            end
                        
            x_step = L_L.Par.step_inc+x_step;
            x     = sg*x_step + x;
                  
            Slv_0 = Slv;
            
            while (Exitflag == 0) && (L_L.Par.step_tol < x_step)
                
                L_L_1(i)             = step_eq(L_L_1(i),x);
                                       
                [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,L_L_1(i));

                [i,norm(eps_f),x_step]
                
                L_L_1(i)             = L_L.Met.Prop_Gen(Slv,L_L_1(i));     
                
                [Breakflag,L_L_1] = fail_check_step_sizing(L_L_1,i);
                
                
                if Breakflag == 1 || (Exitflag <= 0)
                    
                    Exitflag = 0;
                    
                end
                
                [Breakflag,L_L_1] = L_L.Met.Newton_Fail_Check(L_L_1,i,x,Exitflag);
                
                if Breakflag == 1 || (Exitflag <= 0)
                    
                    Exitflag = 0;
                    
                end
                
                if (Exitflag <= 0) 
                    
                    Slv        = Slv_0;
                    x          = x - sg*x_step;
                    x_step     = x_step*L_L.Par.step_dec;
                    x          = x + sg*x_step;
                    
                end
                
                
            end
                       
            if Breakflag == 1
                
                break;
                
            end
            
            switch L_L.Par.Stability
                
                case 'Yes'
                    
                    L_L_1(i).Sol.Linear_Stability = struct;
                    L_L_1(i).Stab                 = Stability_Switcher(L_L_1(i));
                    
                case 'No'
                    
                    L_L_1(i).Stab.E_values  = NaN;
                    L_L_1(i).Stab.E_vectors = NaN;
                    
            end
                                   
        end
        
        L_L_1(end) = [];
        
        function [Flag,L_L] = fail_check(L_L,i)
            
           Logic.r_1 = sum(abs(L_L(i).Sol.Psi_k(2:end)).^2) <= 1E-10;
            
           Logic.r_2  = ~(L_L(i).Par.top_boundary >= x) ;            
           Logic.r_4  = ~(L_L(i).Par.bot_boundary <= x);
           Logic.r_3  =  Exitflag == 0;
           Logic.r_5  = max(abs(L_L(i).Sol.Psi_k)) - min(abs(L_L(i).Sol.Psi_k)) < 1E-10;
           Logic.r_6  = i == L_L(i).Par.i_max;
%            Logic.r_7 = isequal(L_L.Par.variable,'delta') && L_L(i).Eq.delta <= 0;
 %           Logic.r_8 = isequal(L_L.Par.variable,'gamma') && L_L(i).Eq.gamma < 0;
            
            L_L(i).Failreason = Logic;
            
            Flag = (Logic.r_1 || Logic.r_2 || Logic.r_3 || Logic.r_4 || Logic.r_5 || Logic.r_6 );%|| Logic.r_7 || Logic.r_8
            
        end
        
        function [Flag,L_L] = fail_check_step_sizing(L_L,i)

            Flag =0;
            
%            if i >= 3
                
 %               Flag = ~(abs(L_L(i).Sol.Amplitude-L_L(i-1).Sol.Amplitude) <= 3*abs(L_L(i-1).Sol.Amplitude-L_L(i-2).Sol.Amplitude));
                
  %          end 
            
        end
    
        function Stat   = step_eq(Stat,x)
            
            Stat.Eq.(Stat.Par.variable) = x;
            Stat.In.(Stat.Par.variable) = Stat.Eq.norm*Stat.Eq.(Stat.Par.variable);
            Stat = Stat.Met.Norm(Stat);

        end
      
    end
