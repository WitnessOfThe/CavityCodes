function [x0,eps_f,Output]    = Newton_Switcher(x0,L_L)

    switch Delta.Newton
        
        case 'fsolve'
            
            [x0,eps_f,Output,~] = fsolve(@(x)Equation(Dir,L_L,x),x0,options);
            
        case 'Manual'
            
            [x0,eps_f,Output]   = Newton_Manual(L_L,x0);
            
        case 'Bc_Grad'
            
            [x0,eps_f,Output]   = Newton_Manual_bicgstab(L_L,x0);
            
    end
    
end


