function Stab = LLE_Full_Stability(Stat)

            [E_vectors_raw,E_values_raw]  =  eigs(@(x)Stat.Met.Stab_Matrix(x,Stat),2*Stat.Space.N,2*Stat.Space.N,'largestreal');
            
            Stab.E_values         =  diag(E_values_raw)*Stat.Eq.norm;
            
            Stab.E_vectors        = E_vectors_raw(:,real(Stab.E_values*Stat.Eq.norm) > 0);
            
            Pert_vect             = E_vectors_raw(1:Stat.Space.N,:) + conj(E_vectors_raw(Stat.Space.N+1:2*Stat.Space.N,:));
            
            Pert_vect(10*log10(abs(Pert_vect).^2) <= -200)            = 0;
            Pert_vect(10*log10(abs(Pert_vect).^2) > -200)             = 1;
            
            ii = 0;
            Stab.E_values(Stab.E_values == 0) = NaN+1i*NaN;
            
            [~,ind_zero] = min(abs(Stab.E_values));
     %       Stab.E_values(ind_zero) = 0;
           [~,SIND]              =   sort(real(Stab.E_values),'descend');
            Stab.E_values = Stab.E_values(SIND);
            
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
             Stab.E_values(isnan( Stab.E_values)) = [];
            Stab.Dres_Spec.lam(Stab.Dres_Spec.lam == 0+1i*0) = NaN+1i*NaN;
  
end