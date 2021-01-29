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
        while Exitflag ~= 0
            
            Exitflag = 0;
            i = i+1;
            
            if i >= 2
                
                L_L_1(i)    = L_L_1(i-1);
                
            end
                        
            Slv_0 = Slv;
            Breakflag = 1;
            
            while (L_L.Par.step_tol < x_step) && Breakflag == 1
                
                x_step    =  L_L.Par.step_inc*x_step;
                x          = x + sg*x_step;
                L_L_1(i)             = step_eq(L_L_1(i),x);
                                       
                [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,L_L_1(i));

                [i,norm(eps_f),x_step]
                
                L_L_1(i)             = L_L.Met.Prop_Gen(Slv,L_L_1(i));     
                
                if i>= 2
                    [Breakflag] = L_L.Met.Newton_Fail_Check(L_L_1(i-1:i),i,x,Exitflag);
                else
                    [Breakflag] = L_L.Met.Newton_Fail_Check(L_L_1(i),i,x,Exitflag);
                end
                if Breakflag == 1 
                    
                    Slv        = Slv_0;
                    x          = x - sg*x_step;
                    x_step     = x_step*L_L.Par.step_dec;            
                   
                end
                
                
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
        
        L_L_1(i+1:end) = [];
        
    
        
        
    
        function Stat   = step_eq(Stat,x)
            
            Stat.Eq.(Stat.Par.variable) = x;
            Stat.In.(Stat.Par.variable) = Stat.Eq.norm*Stat.Eq.(Stat.Par.variable);
            Stat = Stat.Met.Norm(Stat);

        end
      
    end
