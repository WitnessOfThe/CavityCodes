function Stab = LLE_Bloch_Full_Stability_with_Norm(St)

    if St.In.mu_bl ~= 1
        
        k          = [-floor(St.In.mu_bl):0.25:floor(St.In.mu_bl)-1];    
        Values     = zeros(size(k,2),2*St.Space.N);
        ValuesStar = zeros(size(k,2),2*St.Space.N);
        
    else
        
        k          = 0;    
        Values     = zeros(size(k,2),2*St.Space.N);
        ValuesStar = zeros(size(k,2),2*St.Space.N);
        
    end
    parfor i = 1:size(k,2)
        
        Stat                       = St;                     
        Stat.In.k                  = k(i);
        
        [Vectors,Valuestemp]           = eig(Stat.Met.Stab_Matrix(Stat));
        [VectorsStar,ValuesStartemp]   = eig(Stat.Met.Stab_MatrixConj(Stat));
        Values(i,:)               = diag(Valuestemp)*Stat.Eq.norm;   
        ValuesStar(i,:)           = diag(ValuesStartemp)*Stat.Eq.norm;   
        
%         Stab.Snorm(i,:)           = zeros(1,2*Stat.Space.N);
%         for ival = 1:2*Stat.Space.N 
%             Stab.Snorm(i,ival)       = VectorsStar(:,ival)'*Vectors(:,ival);                      
%         end

        Vk(i).Vectors        = Vectors;%;
        Vk(i).VectorsStar    = VectorsStar;%;
        
    end
    
    Stab.k          = k;
    Stab.Values     = Values;
    Stab.ValuesStar = ValuesStar;
    Stab.Vk         = Vk;
    
end
