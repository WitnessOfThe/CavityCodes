function L_L = MI(L_L)
    
    tt  = eig(L_L.Met.MI_Matrix(L_L,1,1));
    
    Value = zeros(size(tt,1),L_L.Space.N);
    
    for j = 1:size(L_L.Sol.CW.Psi)
        
        if ~isnan(L_L.Sol.CW.Psi(j)) 
            
            for i = 1:L_L.Space.N
                
                tt = eig(L_L.Met.MI_Matrix(L_L,i,j));
                
                Value(i,1:size(tt,1)) = tt;
                
            end
            
                L_L.Sol.CW.Stab(j).Value   = Value;
                
        else
           
           L_L.Sol.CW.Stab(j).Value          = sparse(size(tt,1),L_L.Space.N);
           
        end
       
    end


        
end
