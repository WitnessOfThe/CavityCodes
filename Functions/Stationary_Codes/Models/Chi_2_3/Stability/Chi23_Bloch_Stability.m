function Stab = Chi23_Bloch_Stability(Stat)
            
    n = [0:1:floor(Stat.In.mu_bl/2)];
    
    for i = 1:size(n,2)
        
        Stat.In.n                     = n(i);
        
        [E_vectors_raw,E_values_raw]  = eigs(@(x)Stat.Met.Stab_Matrix(x,Stat)...
            ,4*Stat.Space.N,4*Stat.Space.N,'largestreal');
        
        E_vectors                     = (E_vectors_raw(1:Stat.Space.N,:))...
            + conj( E_vectors_raw(Stat.Space.N+1:2*Stat.Space.N,:));
        Stab(i).mum = zeros(1,size(E_vectors,2));
        
        for i_k = 1:size(E_vectors,2)
            
            [~,Ind]       = max(abs(E_vectors(:,i_k)));
            Stab(i).mum(1,i_k) = Stat.Space.k(Ind);
            
        end
        
        [Stab(i).mum,Sort_I] = sort(Stab(i).mum,'ascend');
        
        Stab(i).In.n                  = n(i);
        Stab(i).E_values              = diag(E_values_raw)*Stat.Eq.norm;
        [~,in_im]                     = maxk(real(Stab(i).E_values),1);
        Stab(i).E_vectors             =E_vectors_raw(:,in_im);%;
        
   %     Stab(i).E_values      = Stab(i).E_values(Sort_I);        
    %    Stab(i).E_values(Stab(i).E_values == 0 + 1i*0) = NaN+1i*NaN;
  %      if n(i) == 0
   %         [~,ind_zero ] = min(abs(Stab(i).E_values ));
    %        Stab(i).E_values(ind_zero)      = 0;
    %    end
     %   Stab(i).E_vectors     = Stab(i).E_vectors(:,Sort_I);

    end

  
end
