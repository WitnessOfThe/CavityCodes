function Stat = Chi_3_LLE_Turing_MI_Boundary(Stat,mu)
    

    Stat = Generate_G_Coeff(Stat,mu);
    nu_max = mu/2;
    
    Stat.Space_nu    = Define_Space_Cavity(nu_max,2*pi);
    
    Stat.In.Delta_nu_pm = 
    Stat.In.Delta_nu    =
    
    
    
      
    
    
end
function Stat = Generate_G_Coeff(Stat,mu)
    
    ind_index(1) = find(Stat.Space.k ==   mu);
    ind_index(2) = find(Stat.Space.k == - mu);
    
    Stat.In.G_0  = Stat.In.gamma*abs(Stat.Sol.Psi_k(1)).^2;
    Stat.In.G_mu = Stat.In.gamma*abs(Stat.Sol.Psi_k(ind_index)).^2;
    Stat.In.phi  = 2*angle(Stat.Sol.Psi_k(1)) ...
        + angle(Stat.Sol.Psi_k(ind_index(1))) - angle(conj(Stat.Sol.Psi_k(ind_index(2))));
    Stat.In.alpha_0  =  angle(Stat.Sol.Psi_k(1));
    Stat.In.alpha_pl = angle(Stat.Sol.Psi_k(ind_index(1)));
    Stat.In.alpha_mn = angle(Stat.Sol.Psi_k(ind_index(2)));
    
end