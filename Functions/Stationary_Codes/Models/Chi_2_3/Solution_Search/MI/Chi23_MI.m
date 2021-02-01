function Stab = Chi23_MI(CW)
        
    for j = 1:size(CW.Sol.Omega,1)
        
        Stab(j).Value    = zeros(CW.Space.N,4);
%        Stab(j).Vector   = zeros(4,CW.Space.N);
        
        if ~isnan(CW.Sol.Omega(j)) 
            
            for i = 1:CW.Space.N
                
                [~,tt_val] = eig(CW.Met.MI_Matrix(CW,i,j));
                
                Stab(j).Value(i,1:size(tt_val,1)) = -1i*diag(tt_val);
         %       Stab(j).Vector(:,i)               = tt_vect;
                
            end                
        else
           
           Stab(j).Value    = sparse(CW.Space.N,2);
         %  Stab(j).Vector   = sparse(4,CW.Space.N*2);
           
        end
       
    end
  
end
