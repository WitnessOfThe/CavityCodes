function CW = MI(CW)
    
    tt  = eig(CW.Met.MI_Matrix(CW,1,1));
    
    Value = zeros(size(tt,1),CW.Space.N);
    
    for j = 1:size(CW.Sol.Psi)
        
        if ~isnan(CW.Sol.Psi(j)) 
            
            for i = 1:CW.Space.N
                
                tt = eig(CW.Met.MI_Matrix(CW,i,j));
                
                Value(i,1:size(tt,1)) = tt;
                
            end
            
                Sol.CW.Stab(j).Value   = Value;
                
        else
           
           CW.Sol.Stab(j).Value          = sparse(size(tt,1),Space.N);
           
        end
       
    end


        
end
