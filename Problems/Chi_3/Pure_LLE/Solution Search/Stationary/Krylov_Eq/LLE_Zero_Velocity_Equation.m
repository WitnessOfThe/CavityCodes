    function f = LLE_Zero_Velocity_Equation(x,L_L)
    
        mask                = L_L.Eq.mask;
        
        psi_hat             = x(1:L_L.Space.N) +...
                                         1i*x(L_L.Space.N+1:2*L_L.Space.N);
        
        V                   = 0;   %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        f_psi               = ifft(mask.*psi_hat);
        
        abs_psi_2           = abs(f_psi).^2;
        
        [~,max_ind]         = max(abs_psi_2);
 
        omega_j             = L_L.Eq.omega_j;
     
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        Nonliniar_term =    1i.*fft(abs_psi_2.*f_psi).*L_L.Eq.gamma_Kerr;
        Pump           =    zeros(1,L_L.Space.N);
        Pump(1)        =    L_L.Eq.h*L_L.Space.N;
        Liniar_term    =    1i.*(L_L.Space.k.*V - L_L.Eq.delta - omega_j).*psi_hat;%
        
        
        Eq    = Liniar_term + Nonliniar_term +1i*Pump;
        
        f_1   = mask.*real(Eq);
        f_2   = mask.*imag(Eq);
        f_3   = ifft(mask.*1i.*L_L.Space.k.*fft(abs_psi_2),'symmetric');
        
        f     = [f_1.';f_2.'];%\;
        
    end