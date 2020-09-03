function CW = Chi_3_LLE_MI_Formula(CW,N)
    
    CW = CW.Met.Norm(CW,N);    
    
    CW.In.Delta  =     CW.In.delta + 1/2*CW.Space.k.^2*CW.In.D(2);

    CW.An.Lambda_mu(1,:) = sqrt(3*( CW.In.Delta - CW.In.g).*(CW.In.g - 1/3*CW.In.Delta));
    CW.An.Lambda_mu(2,:) = -CW.An.Lambda_mu(1,:);

    CW.An.Omega_mu(1,:) = sqrt(3*(CW.In.g - CW.In.Delta).*(CW.In.g - 1/3*CW.In.Delta));
    CW.An.Omega_mu(2,:) = -CW.An.Omega_mu(1,:);
    
    CW.An.Omega_mu(1,(1/3*CW.In.Delta < CW.In.g) & (CW.In.Delta > CW.In.g)) = 0;
    CW.An.Omega_mu(2,(1/3*CW.In.Delta < CW.In.g) & (CW.In.Delta > CW.In.g)) = 0;
        
    CW.An.Lambda_mu(1,(1/3*CW.In.Delta > CW.In.g) & (CW.In.g > CW.In.Delta) ) = 0;
    CW.An.Lambda_mu(2,(1/3*CW.In.Delta > CW.In.g) & (CW.In.g > CW.In.Delta) ) = 0;
    
    CW.An.lambda_mu = - 1/2*CW.In.kappa - (CW.An.Lambda_mu+1i*CW.An.Omega_mu); 
    
end
