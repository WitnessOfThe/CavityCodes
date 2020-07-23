function L_L = Chi_3_LLE_Normalization(L_L)

        Fundamental_Constants;
        L_L.Dispersion.D       = L_L.In.D;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        m_p                    = round(L_L.In.omega_p/L_L.In.D(1));
        
        L_L.Dispersion.omega   =  L_L.In.omega_p;
        
        for i = 1:size(L_L.Dispersion.D,2)
            
            L_L.Dispersion.omega = L_L.Dispersion.omega + L_L.Space.k.^i.*...
                L_L.Dispersion.D(i)/factorial(i);
            
        end
        

        L_L.In.Finess          = L_L.In.D(1)/L_L.In.kappa;
        coeff                  = L_L.In.norm_coeff;
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        L_L.Dispersion.eff_index = 1:L_L.Space.N;
        
        L_L.Eq.delta        = L_L.In.delta/coeff;
        L_L.Eq.kappa        = L_L.In.kappa/coeff;
        L_L.Eq.kappa_vector = L_L.Eq.kappa;
        L_L.In.pump_index   = 1;
        L_L.Eq.gamma_3      = L_L.In.gamma/coeff;
        L_L.Eq.omega        = L_L.Dispersion.omega/coeff;
        L_L.Eq.omega_p      = L_L.In.omega_p/coeff;
        
        L_L.Eq.h            = 1/2*L_L.In.kappa*sqrt(L_L.In.Finess*L_L.In.P...
            /pi*L_L.In.eta)/coeff;
        


        L_L.Eq.D            = L_L.Dispersion.D/coeff;
        
        L_L.Eq.Raman.mu        = 0.18;
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        

    L_L.Eq.Shifted.omega_j      =  (L_L.Dispersion.omega - L_L.In.omega_p... 
    - L_L.Dispersion.D(1)*L_L.Space.k)/coeff - 1i*L_L.Eq.kappa/2;  
    L_L.Eq.Shifted.gamma_Kerr   =  L_L.Eq.gamma_3*ones(1,L_L.Space.N);
    L_L.Eq.Shifted.mask         =  ones(1,L_L.Space.N);
    L_L.Eq.Shifted.kappa_vector =  ones(1,L_L.Space.N)*L_L.Eq.kappa;
    L_L.Eq.Shifted.mode_range   =  [1:350,(L_L.Space.N-350):L_L.Space.N];

end
