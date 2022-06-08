function Stab = LLE_Bloch_Full_Stability(Stat)
    if Stat.In.mu_bl ~= 1
%        Stab.k      = [-floor(Stat.In.mu_bl*2):1:floor(Stat.In.mu_bl*2)];    

        Stab.k      = [-2*floor(Stat.In.mu_bl):1:2*floor(Stat.In.mu_bl)];    
        Stab.Values = zeros(size(Stab.k,2),2*Stat.Space.N);
    else
        Stab.k      = 0;    
        Stab.Values = zeros(size(Stab.k,2),2*Stat.Space.N);
    end
    for i = 1:size(Stab.k,2)
        
        Stat.In.k                     = Stab.k(i);
        
        [Vectors_raw,Values_raw]  = eigs(@(x)Stat.Met.Stab_Matrix(x,Stat)...
            ,2*Stat.Space.N,2*Stat.Space.N,'largestreal');
%        [Vectors_raw,Values_raw]  = eig(Stat.Met.Stab_Matrix(Stat));
                
        Stab.Values(i,:)          = diag(Values_raw)*Stat.Eq.norm;   
%         Stab.Snorm(i,:)           = zeros(1,2*Stat.Space.N);
%         ValuesStar                =  conj(Stab.Values(i,:));
%         for ival = 1:2*Stat.Space.N 
%            indB =  ival;
%            [dd,indC] = min(abs(imag(ValuesStar) - imag(Stab.Values(i,indB)) ));
%            Stab.Snorm(i,ival)   = Vectors_raw(:,indC)'*Vectors_raw(:,indB);
%         end
%        [~,in_im]                 = maxk(real(Stab.Values(i,:) ),1);        
%
        Stab.Vk(i).Vectors        = Vectors_raw;%;
        
    end

  
end
