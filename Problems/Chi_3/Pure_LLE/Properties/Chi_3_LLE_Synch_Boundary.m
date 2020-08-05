function CW = Chi_3_LLE_Synch_Boundary(CW)
    

    CW.In.Delta  =     CW.In.delta + 1/2*CW.Space.k.^2*CW.In.D(2);
    
    g(1,:) =     CW.In.Delta;
    g(2,:) = 1/3*CW.In.Delta;
        
    CW.In.H_Synch    = real(sqrt( (g + 4*g.*(CW.In.delta - g).^2/CW.In.kappa.^2)/CW.In.gamma ));
    for i = 1:CW.Space.N
       if CW.In.H_Synch (1,i) == CW.In.H_Synch (2,i)
           CW.In.H_Synch (:,i) = NaN;
       end
    end

    CW.In.W_Synch    = CW.In.H_Synch.^2*pi/CW.In.eta/CW.In.Finess;
    
end
