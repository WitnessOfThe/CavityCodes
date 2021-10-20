function Ham = LLE_Bloch_Hamiltonean(Stat)
    if Stat.In.mu_bl ~= 1
        Ham.k      = [-floor(1/2*Stat.In.mu_bl):1:floor(1/2*Stat.In.mu_bl)];    
        Ham.Values = zeros(size(Ham.k,2),2*Stat.Space.N);
    else
        Ham.k      = 0;    
        Ham.Values = zeros(size(Ham.k,2),2*Stat.Space.N);
    end
    for i = 1:size(Ham.k,2)
        
        Stat.In.k                     = Ham.k(i);
        
        [Vectors_raw,Values_raw]  = eigs(@(x)Stat.Met.Stab_Matrix(x,Stat)...
            ,2*Stat.Space.N,2*Stat.Space.N,'largestreal');
                
        Ham.Values(i,:)          = diag(Values_raw);
        
        for ival = 1:size( Ham.Values(i,:),2)
%            Ham.S(i,ival) = conj(Vectors_raw(:,ival)).'*(diag([ones(1,Stat.Space.N),-ones(1,Stat.Space.N)]))*Vectors_raw(:,ival);
            Ham.S(i,ival) = trapz( abs(Vectors_raw(1:Stat.Space.N,ival)).^2-abs(Vectors_raw(Stat.Space.N+1:Stat.Space.N*2,ival)).^2);
            Ham.S(i,ival) = Ham.S(i,ival)/abs(Ham.S(i,ival));
        end
%        [~,in_im]                 = maxk(real(Stab.Values(i,:) ),1);        

         Ham.Vk(i).Vectors        = Vectors_raw;%;
        
    end

  
end
