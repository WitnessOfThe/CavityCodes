    function f = Chi23_Full_Dispersion_Liniar_Decomposition_RS(x,Psi,Stat)
                
        xo                  = (x(1:Stat.Space.N) +...
                                         1i*x(Stat.Space.N+1:2*Stat.Space.N)).';
        xe                  = (x(2*Stat.Space.N+1:3*Stat.Space.N) +...
                                         1i*x(3*Stat.Space.N+1:4*Stat.Space.N)).';
        
        xV                   = x(end);   %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
        Psio        = Psi(1:Stat.Space.N) + ...
                                1i*Psi(Stat.Space.N+1:2*Stat.Space.N);
        Psie        = Psi(2*Stat.Space.N+1:3*Stat.Space.N) + ...
                                        1i*Psi(3*Stat.Space.N+1:4*Stat.Space.N);
        
        
        V               = Psi(end);
        
        abs_psi2        = abs(Psio).^2;
        [~,max_ind]     = max(abs_psi2);
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
        L1      = ifft( fft(xo).*(Stat.Eq.Lo - V*Stat.Space.k) - Stat.Space.k.*xV.*fft(Psio));
        
        NL1     =  - (Stat.Eq.gam2o.*( Psie.*conj(xo) + conj(Psio).*xe ) +...
                  Stat.Eq.gam3o.*(...
                 2*(abs(Psio).^2 + abs(Psie).^2 ).*xo + Psio.^2.*conj(xo) + ...
                         2*conj(Psie).*Psio.*xo + 2*Psio.*Psie.*conj(xe)));
        
        L2      = ifft( fft(xe).*(Stat.Eq.Le - V*Stat.Space.k) - Stat.Space.k.*xV.*fft(Psie) );
        
        NL2     =  - (Stat.Eq.gam2e.*( 2*Psio.*xo ) +...
                 Stat.Eq.gam3e.*( 2*conj(Psio).*Psie.*xo + 2*Psio.*Psie.*conj(xo)...
                  + 2*( abs(Psio).^2 + abs(Psie).^2 ).*xe + Psie.^2.*conj(xe)) );
        
        Eq1     = ( L1 + NL1 );
            
        Eq2     = ( L2 + NL2 );
        
        Eq3     = ifft(1i*Stat.Space.k.*fft( conj(Psio).*xo + Psio.*conj(xo)) ,'symmetric');
        
        Eq1R = real(Eq1).';
        Eq1I = imag(Eq1).';
        
        Eq2R = real(Eq2).';
        Eq2I = imag(Eq2).';
        
        f       = [Eq1R;Eq1I;Eq2R;Eq2I;Eq3(max_ind).'];%\;
        
    end