    function f = Chi23_Full_Dispersion_Liniar_Decomposition(x,Psi,Stat)
    
        mask                = Stat.Eq.mask;
            
        xo                  = mask.*(x(1:Stat.Space.N) +...
                                         1i*x(Stat.Space.N+1:2*Stat.Space.N)).';
        xe                  = mask.*(x(2*Stat.Space.N+1:3*Stat.Space.N) +...
                                         1i*x(3*Stat.Space.N+1:4*Stat.Space.N)).';
        
        xV                   = x(end);   %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        xoS             = ifft(xo);        
        xeS             = ifft(xe);
        
        Psio_hat        = Psi(1:Stat.Space.N) + ...
                                1i*Psi(Stat.Space.N+1:2*Stat.Space.N);
        Psie_hat        = Psi(2*Stat.Space.N+1:3*Stat.Space.N) + ...
                                        1i*Psi(3*Stat.Space.N+1:4*Stat.Space.N);
        
        Psio            = ifft(Psio_hat);
        Psie            = ifft(Psie_hat);
        
        V               = Psi(end);
        
        abs_psi2        = abs(Psio).^2;
        [~,max_ind]     = max(abs_psi2);
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
        L1      = ( xo.*(Stat.Eq.Lo - V*Stat.Space.k) - Stat.Space.k.*xV.*Psio_hat);
        
        NL1     =  - fft(Stat.Eq.gam2o.*( Psie.*conj(xoS) + conj(Psio).*xeS ));% +...
             %   Stat.Eq.gam3o.*(...
              %  2*(abs(Psio).^2 + abs(Psie).^2 ).*xoS + Psio.^2.*conj(xoS) + ...
               %         2*conj(Psie).*Psio.*xoS + 2*Psio.*Psie.*conj(xeS)));
        
        L2      = ( xe.*(Stat.Eq.Le - V*Stat.Space.k) - Stat.Space.k.*xV.*Psie_hat);
        
        NL2     =  - fft(Stat.Eq.gam2e.*( 2*Psio.*xoS ));% +...
           %     Stat.Eq.gam3e.*( 2*conj(Psio).*Psie.*xoS + 2*Psio.*Psie.*conj(xoS)...
             %   + 2*( abs(Psio).^2 + abs(Psie).^2 ).*xeS + Psie.^2.*conj(xeS)) );
        
        Eq1     = mask.*( L1 + NL1 );
            
        Eq2     = mask.*( L2 + NL2 );
        
        Eq3     = ifft(1i.*mask.'.*Stat.Space.k.*fft( conj(Psio).*xoS + Psio.*conj(xoS)) ,'symmetric');
        
        Eq1R = real(Eq1).';
        Eq1I = imag(Eq1).';
        
        Eq2R = real(Eq2).';
        Eq2I = imag(Eq2).';
        
        f       = [Eq1R;Eq1I;Eq2R;Eq2I;Eq3(max_ind).'];%\;
        
    end
