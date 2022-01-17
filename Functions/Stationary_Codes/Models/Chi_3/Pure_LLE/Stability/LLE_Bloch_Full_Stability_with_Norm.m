function Stab = LLE_Bloch_Full_Stability_with_Norm(St)

    if St.In.mu_bl ~= 1
        
        k          = 0:1:St.In.mu_bl/2;    
        Values     = zeros(size(k,2),2*St.Space.N);
        ValuesStar = zeros(size(k,2),2*St.Space.N);
        
    else
        
        k          = 0;    
        Values     = zeros(size(k,2),2*St.Space.N);
        ValuesStar = zeros(size(k,2),2*St.Space.N);
        
    end
    for i = 1:size(k,2)
        
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
    
    clear Values 
    clear ValuesStar
    clear Vk
    for ik = 1:size(Stab.Values,1)

        [~,ind_tt]      = find(abs(imag((Stab.Values(ik,:))))   < 50 );
        [~,ind_tt_Star] = find(abs(imag((Stab.Values(ik,:))))   < 50 );

        Values(ik,1:size(ind_tt,2))          = Stab.Values(ik,ind_tt);
        ValuesStar(ik,1:size(ind_tt_Star,2)) = Stab.ValuesStar(ik,ind_tt_Star);

        Vk(ik).Vectors                  =  Stab.Vk(ik).Vectors(:,ind_tt);
        Vk(ik).VectorsStar              =  Stab.Vk(ik).VectorsStar(:,ind_tt_Star);

    end

    Stab.Vk = Vk;
    Stab.Values = Values;
    Stab.ValuesStar = ValuesStar;
    
end
