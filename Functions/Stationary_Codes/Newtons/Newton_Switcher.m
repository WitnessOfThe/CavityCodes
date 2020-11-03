function [x0,eps_f,Output]    = Newton_Switcher(x0,Stat)

    switch func2str(Stat.Met.Newton)
        
        case 'Newton_Manual_bicgstab'
            
            [x0,eps_f,Output]   = Stat.Met.Newton(Stat,x0);
            
        case 'fsolve'
            
            Dir                 = Finite_Derivatives(Stat.Space.N,Stat.Space.dphi);
            [x0,eps_f,Output,~] = Stat.Met.Newton(@(x)Stat.Met.Equation(Dir,Stat,x),x0,Stat.Par.fsolveoptions);
             eps_f = sum(eps_f);           
    end
    
end


