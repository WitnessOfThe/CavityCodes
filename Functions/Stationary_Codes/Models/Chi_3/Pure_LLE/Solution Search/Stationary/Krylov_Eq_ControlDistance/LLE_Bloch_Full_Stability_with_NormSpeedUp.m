function Stab = LLE_Bloch_Full_Stability_with_NormSpeedUp(St)

        k          =[-7.75000000000000,-7.50000000000000,-7.25000000000000,-7,-6.75000000000000,-6.50000000000000,-6.25000000000000,-6,-5.75000000000000,-5.50000000000000,-5.25000000000000,-5,-4.75000000000000,-4.50000000000000,-4.25000000000000,-4,-3.75000000000000,-3.50000000000000,-3.25000000000000,-3,-2.75000000000000,-2.50000000000000,-2.25000000000000,-2,-1.75000000000000,-1.50000000000000,-1.25000000000000,-1,-0.750000000000000,-0.500000000000000,-0.250000000000000,0,0.250000000000000,0.500000000000000,0.750000000000000,1,1.25000000000000,1.50000000000000,1.75000000000000,2,2.25000000000000,2.50000000000000,2.75000000000000,3,3.25000000000000,3.50000000000000,3.75000000000000,4,4.25000000000000,4.50000000000000,4.75000000000000,5,5.25000000000000,5.50000000000000,5.75000000000000,6,6.25000000000000,6.50000000000000,6.75000000000000,7,7.25000000000000,7.50000000000000,7.75000000000000,8];    
        
        Values     = zeros(size(k,2),2*St.Space.N);
        ValuesStar = zeros(size(k,2),2*St.Space.N);
        FF = dftmtx(St.Space.N);
        FI = conj(FF)/St.Space.N;
        
        parfor i = 1:size(k,2)
            
%             Vectors         = zeros(2*St.Space.N);
%             Valuestemp      = zeros(2*St.Space.N);
%             VectorsStar     = zeros(2*St.Space.N);
%             ValuesStartemp  = zeros(2*St.Space.N);
            
            Stat                       = St;
            Stat.Met                   = [];
            Stat.In.k                  = k(i);
            [Vectors,Valuestemp,VectorsStar,ValuesStartemp] = LLE_Bloch_StabilitySpeedUp_mex(Stat,FF,FI);
%            [Vectors,Valuestemp]           = eig(Stat.Met.Stab_Matrix(Stat));
 %           [VectorsStar,ValuesStartemp]   = eig(Stat.Met.Stab_MatrixConj(Stat));
            
            Values(i,:)               = diag(Valuestemp)*Stat.Eq.norm;   
            ValuesStar(i,:)           = diag(ValuesStartemp)*Stat.Eq.norm;   
        
            Vk(i).Vectors        = NaN;%;Vectors
            Vk(i).VectorsStar    = NaN;%VectorsStar;
        
        end
    
    Stab.k          = k;
    Stab.Values     = Values;
    Stab.ValuesStar = ValuesStar;
    Stab.Vk         = Vk;
    
%     clear Values 
%     clear ValuesStar
%     clear Vk
%     for ik = 1:size(Stab.Values,1)
% 
%         [~,ind_tt]      = find(abs(imag((Stab.Values(ik,:))))   < 50 );
%         [~,ind_tt_Star] = find(abs(imag((Stab.Values(ik,:))))   < 50 );
% 
%         Values(ik,1:size(ind_tt,2))          = Stab.Values(ik,ind_tt);
%         ValuesStar(ik,1:size(ind_tt_Star,2)) = Stab.ValuesStar(ik,ind_tt_Star);
% 
%         Vk(ik).Vectors                  =  Stab.Vk(ik).Vectors(:,ind_tt);
%         Vk(ik).VectorsStar              =  Stab.Vk(ik).VectorsStar(:,ind_tt_Star);
% 
%     end
% 
%     Stab.Vk = Vk;
%     Stab.Values = Values;
%     Stab.ValuesStar = ValuesStar;
    
end
