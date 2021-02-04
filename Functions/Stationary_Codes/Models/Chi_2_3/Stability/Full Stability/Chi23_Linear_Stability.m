    function f = Chi23_Linear_Stability(x,Stat)
    
        mask                = Stat.Eq.mask;
                    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        xo              = (x(1:Stat.Space.N) + 1i*x(Stat.Space.N+1:2*Stat.Space.N)).';
        xe              = (x(2*Stat.Space.N+1:Stat.Space.N*3) + 1i*x(3*Stat.Space.N+1:4*Stat.Space.N)).';
        
        xoS             = ifft(xo);
        xeS             = ifft(xe);
        
        Psio_hat        = Stat.Sol.Psi_o;
        Psie_hat        = Stat.Sol.Psi_e;
        
        Psio            = ifft(Psio_hat);
        Psie            = ifft(Psie_hat);
        
        V               = Stat.Sol.V;
                
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
        L1      = -1i*( xo.*(Stat.Eq.Lo + V*Stat.Space.k) );
        NL1     =  1i*Stat.Eq.gam2o.*fft( Psie.*conj(xoS) + conj(Psio).*xeS ) +...
                1i*Stat.Eq.gam3o.*fft(...
                2*(abs(Psio).^2 + abs(Psie).^2 ).*xoS + Psio.^2.*conj(xoS) + ...
                        2*conj(Psie).*Psio.*xoS+2*Psio.*Psie.*conj(xeS));
        
        L2      = -1i*( xe.*(Stat.Eq.Le + V*Stat.Space.k) );
        NL2     =  1i*Stat.Eq.gam2e.*fft( 2*Psio.*xoS ) +...
                1i*Stat.Eq.gam3e.*fft(...
                2*( abs(Psio).^2 + abs(Psie).^2 ).*xeS + Psie.^2.*conj(xeS) + ...
                        2*conj(Psio).*Psie.*xoS + 2*Psio.*Psie.*conj(xoS));

        
        Eq1     = mask.*( L1 + NL1 );
        
        Eq2     = mask.*( L2 + NL2 );
        
        
        Eq1R(1:Stat.Space.N,1) = real(Eq1);
        Eq1I(1:Stat.Space.N,1) = imag(Eq1);
        Eq2R(1:Stat.Space.N,1) = real(Eq2);
        Eq2I(1:Stat.Space.N,1) = imag(Eq2);
        
        f       = [Eq1R;Eq1I;Eq2R;Eq2I];%\;
        
    end
