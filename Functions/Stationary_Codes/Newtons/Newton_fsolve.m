function [x0,eps_f,Output]    = Newton_fsolve(x0,L_L)
            
            [x0,eps_f,Output,~] = fsolve(@(x)Equation(L_L,x),x0);
            
end


