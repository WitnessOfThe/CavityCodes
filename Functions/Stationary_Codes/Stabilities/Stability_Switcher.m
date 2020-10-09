function Stab = Stability_Switcher(Stat)

  %  switch Delta.Equation_string
        
%         case 'Raman'
% 
%             to_find_eig =  L_Raman(Stat);
%             %    tic
%             %                [E_vectors_raw,E_values_raw]  = eig(full(to_find_eig));
%             
%             [E_vectors_raw,E_values_raw]  =  eigs(@(t)L_L_Raman_Jacobian_Stability(Space.k,Space.N,Stat.Eq.d,Stat.Eq.gamma,Stat.Eq.h,Stat.Eq.delta,Stat.Raman.omega,Stat.Raman.gamma,Stat.Raman.alpha,Stat.Raman.mu,Slv,t'),4*Space.N,4*Space.N,'largestreal');
%             E_values_raw = diag(E_values_raw);
%             E_values  = E_values_raw;
%             E_vectors = E_vectors_raw(:,1:4);
%             
%             format short e;
%             zero = min(abs(E_values));
% 
%         case 'Kerr'
% 
%             Matrix                        = Stability_Matrix_Kerr(Dir,Stat);
%             [E_vectors_raw,E_values_raw]  = eig(full(Matrix));
%             E_values_raw                  = diag(E_values_raw);
% %               figure;plot(real(E_values_raw ),imag(E_values_raw ),'Marker','.','LineStyle','none')
% 
%             [~,Ind]                                     = sort(real((E_values_raw)),'descend');         
%             Stat.Solution.Linear_Stability.E_values         = E_values_raw(Ind(1:end));         
%             Stat.Solution.Linear_Stability.E_vectors        = E_vectors_raw(:,Ind(1:4));
%             format short e;
   %         
   %     case  'Kerr_Full_Dispersion'

            [E_vectors_raw,E_values_raw]  =  eigs(@(x)LLE_Full_Stability(x,Stat),2*Stat.Space.N,2*Stat.Space.N,'largestreal');
            
            Stab.E_values         =  diag(E_values_raw)*Stat.Eq.norm;
            Stab.E_vectors        = E_vectors_raw(:,real(Stab.E_values*Stat.Eq.norm) > 0);
            
    
end

