function Stab = Chi23_Stability(Stat)

    [E_vectors_raw,E_values_raw]  =  ...
        eigs(@(x)Stat.Met.Stab_Matrix(x,Stat),...
                            4*Stat.Space.N,4*Stat.Space.N,'largestreal');

    Stab.E_values         = diag(E_values_raw);%*Stat.Eq.norm
    Stab.E_vectors        = E_vectors_raw(:,real(Stab.E_values) > 0);%*Stat.Eq.norm
            
        
end