    function f = LLE_Zero_Velocity_Equation(x,L_L)
    
        mask                = L_L.Eq.mask;
        
        psi_hat             = x(1:L_L.Space.N) +...
                                         1i*x(L_L.Space.N+1:2*L_L.Space.N);
        
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        f_psi               = ifft(mask.*psi_hat);
        [~,max_ind]         = max(abs(f_psi));
%        f_psi               = circshift(f_psi,max_ind);
        
 %       psi_hat             = fft(psi_hat);
        
        abs_psi_2           = abs(f_psi).^2;
        
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        Nonliniar_term =    1i.*fft(abs_psi_2.*f_psi).*L_L.Eq.gamma_Kerr;
        Pump           =    zeros(1,L_L.Space.N);
        Pump(1)        =    -(-1i)*-1i*L_L.Eq.h*L_L.Space.N;
        Liniar_term    =    1i.*(- L_L.Eq.L ).*psi_hat;%
        
        
        Eq    = Liniar_term + Nonliniar_term +Pump;
        
        f_1   = mask.*real(Eq);
        f_2   = mask.*imag(Eq);
        
        f     = [f_1.';f_2.'];%\;
     
    end
