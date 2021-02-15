    function Stab = Chi23_Stability(Stat)

    Stat.Sol          = change_sol(Stat);
    
    Stat.In.mu_bl     = 1;
    Stat              = Stat.Met.Norm(Stat);
    
    [E_vectors_raw,E_values_raw]  =  ...
        eigs(@(x)Stat.Met.Stab_Matrix(x,Stat),...
                            4*Stat.Space.N,4*Stat.Space.N,'largestreal','Tolerance',1E-15);

    Stab.E_values         = diag(E_values_raw);%*Stat.Eq.norm
    Stab.E_vectors        = E_vectors_raw(:,real(Stab.E_values) > 0);%*Stat.Eq.norm
            
        
    end
    function Sol = change_sol(Stat)
    
        Psio = 1E-20*ones(1,Stat.Space.N);
        Psie = 1E-20*ones(1,Stat.Space.N);
        Psio(1)     = Stat.Sol.Psi_o(1);
        Psie(1)     = Stat.Sol.Psi_e(1);
        
        for i = 2:round(Stat.Space.N/Stat.In.mu_bl)
            
            Psio(1+(i-1)*Stat.In.mu_bl)     = Stat.Sol.Psi_o(i);
            Psie(1+(i-1)*Stat.In.mu_bl)     = Stat.Sol.Psi_e(i);
            Psio(end-(i-1)*Stat.In.mu_bl+1) = Stat.Sol.Psi_o(end-(i-2));
            Psie(end-(i-1)*Stat.In.mu_bl+1) = Stat.Sol.Psi_e(end-(i-2));
            
        end
        
        Sol.Psi_o  = Psio;
        Sol.Psi_e  = Psie;
        Sol.V  = Stat.Sol.V;
        
    end
