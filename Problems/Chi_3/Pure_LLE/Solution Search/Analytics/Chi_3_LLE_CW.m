    function CW = Chi_3_LLE_CW(CW,N_Mode)
    %% Solution of Equation
        CW = CW.Met.Norm(CW,N_Mode);
        
        coef       = [CW.Eq.gamma_3^2,-2*CW.Eq.delta*CW.Eq.gamma_3,CW.Eq.delta.^2+(CW.Eq.kappa_vector(1)/2).^2,-CW.Eq.h.^2];
      
        psi_amp_sq                        = roots( coef );
        psi_amp_sq(imag(psi_amp_sq) ~= 0) = NaN;
        
        CW.Sol.Psi    = CW.Eq.h./(CW.Eq.delta - 1i*CW.Eq.kappa_vector(1)/2 -CW.Eq.gamma_3*psi_amp_sq);
%       CW.Solution.CW.Q      = CW.Eq.gamma_3*CW.Raman.mu.*psi_amp_sq;
        
    end
    
