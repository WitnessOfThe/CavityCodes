function Stab = LLE_Bloch_Full_Stability(Stat)
    if Stat.In.mu_bl ~= 1
%        Stab.k      = [-floor(Stat.In.mu_bl):1:floor(Stat.In.mu_bl)];    

        Stab.k      = [-floor(Stat.In.mu_bl)*2:1:floor(Stat.In.mu_bl)*2];    
        Stab.Values = zeros(size(Stab.k,2),2*Stat.Space.N);
    else
        Stab.k      = 0;    
        Stab.Values = zeros(size(Stab.k,2),2*Stat.Space.N);
    end
    for i = 1:size(Stab.k,2)
        
        Stat.In.k                     = Stab.k(i);
        
        [Vectors_raw,Values_raw]  = eigs(@(x)Stat.Met.Stab_Matrix(x,Stat)...
            ,2*Stat.Space.N,2*Stat.Space.N,'largestreal');
                
        Stab.Values(i,:)          = diag(Values_raw)*Stat.Eq.norm;        
        [~,in_im]                 = maxk(real(Stab.Values(i,:) ),4*30);        

        Stab.Vk(i).Vectors        = Vectors_raw(:,in_im);%;
        
    end

  
end
