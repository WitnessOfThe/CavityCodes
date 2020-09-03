    function L_L = CW(L_L)
    
        coef       = [L_L.Eq.gamma_3^2,-2*L_L.Eq.delta*L_L.Eq.gamma_3,L_L.Eq.delta.^2+(L_L.Eq.kappa_vector(L_L.In.pump_index)/2).^2,-L_L.Eq.h.^2];
      
        psi_amp_sq = roots( coef );
        psi_amp_sq(imag(psi_amp_sq) ~= 0) = NaN;
        
        L_L.Sol.Psi    = L_L.Eq.h./(L_L.Eq.delta - 1i*L_L.Eq.kappa_vector(L_L.In.pump_index)/2 -L_L.Eq.gamma_3*psi_amp_sq);
        L_L.Sol.Q      = L_L.Eq.gamma_3*L_L.Raman.mu.*psi_amp_sq;
        
    end
