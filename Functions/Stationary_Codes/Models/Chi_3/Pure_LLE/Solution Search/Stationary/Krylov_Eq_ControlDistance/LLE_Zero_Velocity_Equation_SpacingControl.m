    function f = LLE_Zero_Velocity_Equation_SpacingControl(x,L_L)
    
        mask                = L_L.Eq.mask;
        
        psi_hat             = x(1:L_L.Space.N) +...
                                         1i*x(L_L.Space.N+1:2*L_L.Space.N);
        
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        f_psi               = ifft(mask.*psi_hat);
        
        abs_psi_2           = abs(f_psi).^2;
        
        [Peak,max_ind]         = max(abs_psi_2);
        
%        Distnace            = abs(L_L.Space.phi(max_ind(1))-L_L.Space.phi(max_ind(2)));
     
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        Nonliniar_term =    1i.*fft(abs_psi_2.*f_psi).*L_L.Eq.gamma_Kerr;
        Pump           =    zeros(1,L_L.Space.N);
        Pump(1)        =    -(-1i)*-1i*L_L.Eq.h*L_L.Space.N;
        Liniar_term    =    1i.*(- L_L.Eq.L ).*psi_hat;%
        
        
        Eq    = Liniar_term + Nonliniar_term +Pump;
        
        f_1   = mask.*real(Eq);
        f_2   = mask.*imag(Eq);
   %    f_3   = real(f_psi(L_L.In.indphi(1))) - real(f_psi(L_L.In.indphi(2))) ;

         f_3   = abs_psi_2- Peak;
 %        f_3   = ifft(mask.*1i.*L_L.Space.k.*fft(real(f_psi)),'symmetric');
        f     = [f_1.';f_2.';f_3(L_L.In.indphi(1));f_3(L_L.In.indphi(2))];%\;
     
    end
