    function f = LLE_Zero_Velocity_Equation_Turndelta(x,Stat)
    
        mask                = Stat.Eq.mask;
        
        psi_hat             = [Stat.Eq.PsioMax*Stat.Space.N,x(2:Stat.Space.N)]  +...
                                         1i*x(Stat.Space.N+1:2*Stat.Space.N);
        
        delta               = x(1);   %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        f_psi               = ifft(mask.*psi_hat);
        
        abs_psi_2           = abs(f_psi).^2;
        
        [~,max_ind]         = max(abs_psi_2);
 
     
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        Nonliniar_term =    1i.*fft(abs_psi_2.*f_psi).*Stat.Eq.gamma_Kerr;
        Pump           =    zeros(1,Stat.Space.N);
        Pump(1)        =    -(-1i)*-1i*Stat.Eq.h*Stat.Space.N;
        Liniar_term    =    1i.*(- (Stat.Eq.L +   delta) ).*psi_hat;%
        
        
        Eq    = Liniar_term + Nonliniar_term +Pump;
        
        f_1   = mask.*real(Eq);
        f_2   = mask.*imag(Eq);
        
        
%        f_3    =  x(1)/Stat.Space.N - Stat.Eq.PsioMax;
        
        
        f     = [f_1.';f_2.'];%\;
     
    end
