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
            
            Pert_vect             = E_vectors_raw(1:Stat.Space.N,:)+ conj(E_vectors_raw(Stat.Space.N+1:2*Stat.Space.N,:));
            
            Pert_vect(10*log10(abs(Pert_vect).^2) <= -200)            = 0;
            Pert_vect(10*log10(abs(Pert_vect).^2) > -200)             = 1;
            ii = 0;
            
            [~,ind_zero] = min(abs(Stab.E_values));
            
            for i = 1:Stat.Space.N*2
                
                if Stab.E_values(i) ~= 0
                    
                    ii = ii + 1;
                    if ind_zero ~= i
                        
                        lam(ii,:) = Stab.E_values(i)*Pert_vect(:,i).';
                        
                    else
                        
                        lam(ii,:) = 0*Pert_vect(:,i).';                        
                        
                    end                
                end            
                
            end
            
            
            for i =1:Stat.Space.N
                
                tt                 = unique(lam(:,i));      
                tt                 = tt( tt~=0 );
                Stab.Dres_Spec.lam(1:size(tt,1),i) = tt;
                
            end
            
            Stab.Dres_Spec.lam(Stab.Dres_Spec.lam ==0+1i*0) = NaN+1i*NaN;
            
end

