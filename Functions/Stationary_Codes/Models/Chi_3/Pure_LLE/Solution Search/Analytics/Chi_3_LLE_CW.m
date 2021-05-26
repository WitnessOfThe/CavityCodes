    function CW = Chi_3_LLE_CW(CW)
    %% Solution of Equation
    

        CW = CW.Met.Norm(CW);
        
        coef       = [CW.Eq.gamma_3^2,-2*CW.Eq.delta*CW.Eq.gamma_3,CW.Eq.delta.^2+(CW.Eq.kappa_vector(1)/2).^2,-CW.Eq.h.^2];
      
        psi_amp_sq                        = roots( coef );
        psi_amp_sq(imag(psi_amp_sq) ~= 0) = NaN;
        
        CW.Sol.Psi    = -1i*CW.Eq.h./(CW.Eq.delta - 1i*CW.Eq.kappa_vector(1)/2 -CW.Eq.gamma_3*psi_amp_sq);
        CW.Sol.g      = abs(CW.Sol.Psi).^2*CW.Eq.gamma_3;
%       CW.Solution.CW.Q      = CW.Eq.gamma_3*CW.Raman.mu.*psi_amp_sq;
        
    end
    
