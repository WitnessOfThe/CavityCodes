function f = LLE_Full_Dispersion_Equation_Turnd3(x,Stat)
    
        mask                = 1;
        
        psi_hat             = [Stat.Eq.PsioMax*Stat.Space.N,x(2:Stat.Space.N)]  +...
                                         1i*x(Stat.Space.N+1:2*Stat.Space.N);
        
        delta               = x(1);   %    
        V                   = x(end);   %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        f_psi               = ifft(mask.*psi_hat);
        
        abs_psi_2           = abs(f_psi).^2;
        
        [~,max_ind]         = max(abs(real(f_psi)));
 
     
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        Nonliniar_term =    1i.*fft(abs_psi_2.*f_psi).*Stat.Eq.gamma_Kerr;
        Pump           =    zeros(1,Stat.Space.N);
        Pump(1)        =    -(-1i)*-1i*Stat.Eq.h*Stat.Space.N;
        Liniar_term    =    1i.*(Stat.Space.k.*V - Stat.Eq.L  +   delta).*psi_hat;%
        
        
        Eq    = Liniar_term + Nonliniar_term +Pump;
        
        f_1   = mask.*real(Eq);
        f_2   = mask.*imag(Eq);
        f_3   = ifft(mask.*1i.*Stat.Space.k.*fft(real(f_psi)),'symmetric');
        
        f     = [f_1.';f_2.';f_3(max_ind).'];%\;

    
end