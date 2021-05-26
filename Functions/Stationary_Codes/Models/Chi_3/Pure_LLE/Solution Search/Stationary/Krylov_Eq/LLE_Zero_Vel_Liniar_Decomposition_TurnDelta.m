    function g = LLE_Zero_Vel_Liniar_Decomposition_TurnDelta(x,Psi,Stat)
    
        mask            = Stat.Eq.mask;
        psi_hat         = [Stat.Eq.PsioMax*Stat.Space.N,Psi(2:Stat.Space.N)].' + 1i*Psi(Stat.Space.N+1:2*Stat.Space.N).';
        
        f_psi          = ifft(psi_hat);    
        abs_psi_2      = abs(f_psi).^2;
        
        delta          = Psi(1);
        xd             = x(1); 
        
%%

        x_psi_hat            = [0;x(2:Stat.Space.N)] + 1i*x(Stat.Space.N+1:2*Stat.Space.N);        
        x_psi                = ifft(x_psi_hat);
         
        
%%
        Eq = (-  1i*(Stat.Eq.L+delta).').*x_psi_hat + (-  1i*psi_hat).*xd + ...
             1i*Stat.Eq.gamma_Kerr.'.*fft( 2*abs_psi_2.*x_psi + f_psi.^2.*conj(x_psi) );
                                
        g_1(1:Stat.Space.N,1)   = real(Eq);                                        
        g_2(1:Stat.Space.N,1)   = imag(Eq);

        
%        Eq4     = x(1)/Stat.Space.N ;
        
        g     = [g_1;g_2];%
        
        
    end
