function f = Chi23_Full_Dispersion_Liniar_Decomposition_RS_delta(x,Psi,Stat)
                
    xo                  = ([0;x(2:Stat.Space.N)] +...
                                     1i*x(Stat.Space.N+1:2*Stat.Space.N)).';
    xe                  = (x(2*Stat.Space.N+1:3*Stat.Space.N) +...
                                     1i*x(3*Stat.Space.N+1:4*Stat.Space.N)).';

    xV                   = x(end);   %    
    xd                   = x(1);   %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
    Psio        = [Stat.Eq.PsioMax,Psi(2:Stat.Space.N)] + ...
                            1i*Psi(Stat.Space.N+1:2*Stat.Space.N);
    Psie        = Psi(2*Stat.Space.N+1:3*Stat.Space.N) + ...
                                    1i*Psi(3*Stat.Space.N+1:4*Stat.Space.N);


    V               = Psi(end);
    delta           = Psi(1);

    [~,ind_real]     = max(abs(imag(Psio)));
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
    L1      = ifft( fft(xo).*(Stat.Eq.Lo + delta - V*Stat.Space.k) + ...
                                      - Stat.Space.k.*xV.*fft(Psio) ) + xd.*Psio;

        NL1     =  - ifft(Stat.Eq.gam2o.*fft( Psie.*conj(xo) + conj(Psio).*xe ) +...
                  Stat.Eq.gam3o.*fft(...
                 2*(abs(Psio).^2 + abs(Psie).^2 ).*xo + Psio.^2.*conj(xo) + ...
                         2*conj(Psie).*Psio.*xe + 2*Psio.*Psie.*conj(xe) ) );
%        NL1     =  - ifft(Stat.Eq.gam2o.*fft( Psie.*conj(xo) + conj(Psio).*xe ) +...
 %                 Stat.Eq.gam3o.*fft(...
  %               2*(abs(Psio).^2 + abs(Psie).^2 ).*xo + Psio.^2.*conj(xo) ) );

    L2      = ifft( fft(xe).*(Stat.Eq.Le + 2*delta- V*Stat.Space.k)  ...
                                - Stat.Space.k.*xV.*fft(Psie) )+ 2*xd.*Psie;

        NL2     =  - ifft(Stat.Eq.gam2e.*fft( 2*Psio.*xo ) +...
                 Stat.Eq.gam3e.*fft( 2*conj(Psio).*Psie.*xo + 2*Psio.*Psie.*conj(xo)...
                  + 2*( abs(Psio).^2 + abs(Psie).^2 ).*xe + Psie.^2.*conj(xe)) );
  %      NL2     =  - ifft(Stat.Eq.gam2e.*fft( 2*Psio.*xo ) +...
   %              Stat.Eq.gam3e.*fft( ...
    %              + 2*( abs(Psio).^2 + abs(Psie).^2 ).*xe + Psie.^2.*conj(xe)) );

    Eq1     =  L1 + NL1;

    Eq2     =  L2 + NL2;

    Eq3     = ifft(1i*Stat.Space.k.*fft( imag(xo) ) ,'symmetric');
        
 %       Eq4     = conj(Psio(max_ind)).*xo(max_ind) + conj(xo(max_ind)).*Psio(max_ind);
        
    Eq1R = real(Eq1).';
    Eq1I = imag(Eq1).';

    Eq2R = real(Eq2).';
    Eq2I = imag(Eq2).';

    f       = [Eq1R;Eq1I;Eq2R;Eq2I;Eq3(ind_real).'];%\;

end
