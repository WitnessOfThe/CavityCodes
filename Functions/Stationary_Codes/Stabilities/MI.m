function CW = MI(CW,N_mode)
    
    CW  = CW.Met.Solve(CW,N_mode);

    Value = zeros(CW.Space.N,2);
    
    for j = 1:size(CW.Sol.Psi)
        
        if ~isnan(CW.Sol.Psi(j)) 
            
            for i = 1:CW.Space.N
                
                tt = eig(CW.Met.MI_Matrix(CW,i,j));
                
                Value(i,1:size(tt,1)) = tt;
                
            end
            
                CW.Stab(j).Value   = Value;
                
        else
           
           CW.Stab(j).Value          = sparse(CW.Space.N,2);
           
        end
       
    end


        
end
