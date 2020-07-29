function L_L = Stability_Switcher(Dir,Delta,L_L)

    switch Delta.Equation_string
        
        case 'Raman'

            to_find_eig =  L_Raman(L_L);
            %    tic
            %                [E_vectors_raw,E_values_raw]  = eig(full(to_find_eig));
            
            [E_vectors_raw,E_values_raw]  =  eigs(@(t)L_L_Raman_Jacobian_Stability(Space.k,Space.N,L_L.Eq.d,L_L.Eq.gamma,L_L.Eq.h,L_L.Eq.delta,L_L.Raman.omega,L_L.Raman.gamma,L_L.Raman.alpha,L_L.Raman.mu,Slv,t'),4*Space.N,4*Space.N,'largestreal');
            E_values_raw = diag(E_values_raw);
            E_values  = E_values_raw;
            E_vectors = E_vectors_raw(:,1:4);
            
            format short e;
            zero = min(abs(E_values));

        case 'Kerr'

            Matrix                        = Stability_Matrix_Kerr(Dir,L_L);
            [E_vectors_raw,E_values_raw]  = eig(full(Matrix));
            E_values_raw                  = diag(E_values_raw);
%               figure;plot(real(E_values_raw ),imag(E_values_raw ),'Marker','.','LineStyle','none')

            [~,Ind]                                     = sort(real((E_values_raw)),'descend');         
            L_L.Solution.Linear_Stability.E_values         = E_values_raw(Ind(1:end));         
            L_L.Solution.Linear_Stability.E_vectors        = E_vectors_raw(:,Ind(1:4));
            format short e;
            
        case  'Kerr_Full_Dispersion'

            [E_vectors_raw,E_values_raw]  =  eigs(@(x)LLE_Full_Stability(x,L_L),2*L_L.Space.N,2*L_L.Space.N,'largestreal');
            E_values_raw = diag(E_values_raw);
            E_values    = E_values_raw;
            E_vectors   = E_vectors_raw(:,1:4);
            
            L_L.Solution.Linear_Stability.E_values         = E_values;         
            L_L.Solution.Linear_Stability.E_vectors        = E_vectors;
            
            format short e;
            zero = min(abs(E_values));
            format short e;

    end
    
end

