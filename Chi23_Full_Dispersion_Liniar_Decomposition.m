    function f = Chi23_Full_Dispersion_Liniar_Decomposition(x,Psi,Stat)
    
        mask                = Stat.Eq.mask;
            
        xo                  = (x(1:Stat.Space.N) +...
                                         1i*x(Stat.Space.N+1:2*Stat.Space.N)).';
        xe                  = (x(2*Stat.Space.N+1:3*Stat.Space.N) +...
                                         1i*x(3*Stat.Space.N+1:4*Stat.Space.N)).';
        
        xV                   = x(end);   %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        xoS             = ifft(xo);        
        xeS             = ifft(xe);
        
        Psio_hat        = Psi(1:Stat.Space.N)+1i*Psi(Stat.Space.N+1:2*Stat.Space.N);
        Psie_hat        = Psi(2*Stat.Space.N+1:3*Stat.Space.N)+1i*Psi(3*Stat.Space.N+1:4*Stat.Space.N);
        
        Psio            = ifft(Psio_hat);
        Psie            = ifft(Psie_hat);
        
        V               = Psi(end);
        
        abs_psi2        = abs(ifft(Psio_hat)).^2;
        [~,max_ind]     = max(abs_psi2);
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
        L1      = -1i*( xo.*(Stat.Eq.Lo + V*Stat.Space.k) + xV.*Psio_hat);
        NL1     =  1i*Stat.Eq.gam2o.*fft( Psie.*conj(xoS) + conj(Psio).*xeS ) +...
                1i*Stat.Eq.gam3o.*fft(...
                2*(abs(Psio).^2 + abs(Psie).^2 ).*xoS + Psio.^2.*conj(xoS) + ...
                        2*conj(Psie).*Psio.*xoS+2*Psio.*Psie.*conj(xeS));
        
        L2      = -1i*( xe.*(Stat.Eq.Le + V*Stat.Space.k) + xV.*Psie_hat);
        NL2     =  1i*Stat.Eq.gam2e.*fft( 2*Psio.*xoS ) +...
                1i*Stat.Eq.gam3e.*fft(...
                2*(abs(Psio).^2 + abs(Psie).^2 ).*xeS + Psie.^2.*conj(xeS) + ...
                        2*conj(Psio).*Psie.*xoS+2*Psio.*Psie.*conj(xoS));

        
        Eq1     = mask.*( L1 + NL1 );
        
        Eq2     = mask.*( L2 + NL2 );
        
        Eq3   = ifft(1i.*mask.'.*Stat.Space.k.*fft( conj(Psio).*xoS + Psio.*conj(xoS) ) ,'symmetric');
        
        Eq1R(1:Stat.Space.N,1) = real(Eq1);
        Eq1I(1:Stat.Space.N,1) = imag(Eq1);
        Eq2R(1:Stat.Space.N,1) = real(Eq1);
        Eq2I(1:Stat.Space.N,1) = imag(Eq2);
        
        f       = [Eq1R;Eq1I;Eq2R;Eq2I;Eq3(max_ind).'];%\;
        
    end
