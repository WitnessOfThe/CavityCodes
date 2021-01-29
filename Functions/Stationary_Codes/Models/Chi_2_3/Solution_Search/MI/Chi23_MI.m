function CW = Chi23_MI(CW)
        
    for j = 1:size(CW.Sol.Psi)
        
        CW.Stab(j).Value    = zeros(1,CW.Space.N*2);
        CW.Stab(j).Vector   = zeros(4,CW.Space.N*2);
        
        if ~isnan(CW.Sol.Psi(j)) 
            
            for i = 1:CW.Space.N*2
                
                [tt_vect,tt_val] = eig(CW.Met.MI_Matrix(CW,i,j));
                
                CW.Stab(j).Value(i,1:size(tt_val,1)) = -1i*diag(tt_val);
                CW.Stab(j).Vector(:,i)               = tt_vect;
                
            end                
        else
           
           CW.Stab(j).Value    = sparse(CW.Space.N,2);
           CW.Stab(j).Vector   = sparse(4,CW.Space.N*2);
           
        end
       
    end


        
end
