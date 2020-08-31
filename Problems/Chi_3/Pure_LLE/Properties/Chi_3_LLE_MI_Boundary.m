function CW = Chi_3_LLE_MI_Boundary(CW,N)
    
    CW = CW.Met.Norm(CW,N);    
    CW.In.Delta  =     CW.In.delta + 1/2*CW.Space.k.^2*CW.In.D(2);
    
    g(1,:) = 2/3*CW.In.Delta + 1/3*sqrt( CW.In.Delta.^2 - 3/4*CW.In.kappa.^2 );
    g(2,:) = 2/3*CW.In.Delta - 1/3*sqrt( CW.In.Delta.^2 - 3/4*CW.In.kappa.^2 );
    

    CW.In.H_MI_Tongue  =   real(sqrt( (g + 4*g.*(CW.In.delta - g).^2/CW.In.kappa.^2)/CW.In.gamma ));
    

    for i = 1:CW.Space.N-1
        
       if CW.In.H_MI_Tongue (1,i) == CW.In.H_MI_Tongue(2,i)
           
           CW.In.H_MI_Tongue (:,i)   = 0;
           
       end
        
%         if CW.Space.k(i) >= 0 
%             
%            if CW.In.H_MI_Tongue (1,i) > CW.In.H_MI_Tongue (2,i+1)
%                
%                 CW.In.H_MI_Tongue (2,i+1:(end/2-1)) = 0;
%                 CW.In.H_MI_Tongue (1,i:(end/2-1)) = 0;
%                 
%            end
%            
%         end        
    end
    
    
    CW.In.H_MI_Tongue(CW.In.H_MI_Tongue==0) = NaN;    
    
    CW.In.W_MI_Tongue    = CW.In.H_MI_Tongue.^2*pi/CW.In.eta/CW.In.Finess;
    
    
end
