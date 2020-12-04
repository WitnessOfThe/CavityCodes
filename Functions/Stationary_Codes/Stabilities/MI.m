function CW = MI(CW)
    
    CW  = CW.Met.Solve(CW);

    Value = zeros(CW.Space.N,2);
    
    for j = 1:size(CW.Sol.Psi)
        
        if ~isnan(CW.Sol.Psi(j)) 
            
            for i = 1:CW.Space.N
                
                [tt_vect,tt_val] = eig(CW.Met.MI_Matrix(CW,i,j));
                
                Value(i,1:size(tt_val,1)) = diag(tt_val);
                Vect(i).Vect              = tt_vect;
            end
            
                CW.Stab(j).Value   = Value;
                CW.Stab(j).Vector  = Vect;
                
        else
           
           CW.Stab(j).Value          = sparse(CW.Space.N,2);
           
        end
       
    end


        
end
