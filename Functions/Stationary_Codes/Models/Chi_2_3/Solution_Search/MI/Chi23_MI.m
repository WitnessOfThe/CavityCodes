function Stab = Chi23_MI(CW)
        
    for j = 1:size(CW.Sol.Psi_o,1)
        
        Stab(j).Value    = zeros(size(CW.In.kMI,2),4);
        
        if ~isnan(CW.Sol.Psi_o(j)) 
            
            for i = 1:size(CW.In.kMI,2)
                
                Stab(j).Vector(i).V = zeros(4,4);
                [tt_vect,tt_val] = eig(CW.Met.MI_Matrix(CW,i,j));
                
                Stab(j).Value(i,1:size(tt_val,1)) = -1i*diag(tt_val);
                Stab(j).Vector(i).V               = tt_vect;
                
            end                
        else
           
           Stab(j).Value    = sparse(size(CW.In.kMI,2),2);
           Stab(j).Vector   = NaN;
           
        end
       
    end
  
end
