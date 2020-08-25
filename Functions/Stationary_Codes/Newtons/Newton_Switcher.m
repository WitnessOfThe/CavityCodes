function [x0,eps_f,Output]    = Newton_Switcher(x0,L_L)

            
            [x0,eps_f,Output]   = L_L.Met.Newton(L_L,x0);
            
            
    
end


function [x0,eps_f,Output] = fsolve_man_switch(L_L,x0)

            [x0,eps_f,Output,~] = fsolve(@(x)Equation(Dir,L_L,x),x0,L_L.Stat.Par.options);

    
end
