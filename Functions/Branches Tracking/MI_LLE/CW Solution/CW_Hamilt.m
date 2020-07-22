    function L_L = CW_Hamilt(L_L)
    
        coef       = [L_L.Eq.gamma_3^2,0, - L_L.Eq.delta,L_L.Eq.h];      
        psi_amp_sq = roots(coef);
        psi_amp_sq(imag(psi_amp_sq)~=0) = NaN;
        L_L.Solution.CW.Psi    = psi_amp_sq;
        
    end
