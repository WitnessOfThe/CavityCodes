function f = Chi23_Zero_Mode_Liniar_Decomposition_RS_delta(x,Psi,Stat)
                
    xo                  = (0 +...
                                     1i*x(2)).';
    xe                  = (x(3) +...
                                     1i*x(4)).';

    xd                   = x(1);   %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
    Psio        = [Stat.Eq.PsioMax] + ...
                            1i*Psi(2);
    Psie        = Psi(3) + ...
                                    1i*Psi(4);


    delta           = Psi(1);

        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
    L1      = ( (xo).*(Stat.Eq.Lo(1) + delta )    ) + xd.*Psio;

    NL1     =  - (Stat.Eq.gam2o.*( Psie.*conj(xo) + conj(Psio).*xe ) +...
              Stat.Eq.gam3o.*(...
             2*(abs(Psio).^2 + abs(Psie).^2 ).*xo + Psio.^2.*conj(xo) + ...
                     2*conj(Psie).*Psio.*xo + 2*Psio.*Psie.*conj(xe)));

    L2      = ( (xe).*(Stat.Eq.Le(1) + 2*delta))+ 2*xd.*Psie;

    NL2     =  - (Stat.Eq.gam2e.*( 2*Psio.*xo ) +...
             Stat.Eq.gam3e.*( 2*conj(Psio).*Psie.*xo + 2*Psio.*Psie.*conj(xo)...
              + 2*( abs(Psio).^2 + abs(Psie).^2 ).*xe + Psie.^2.*conj(xe)) );

    Eq1     =  L1 + NL1;

    Eq2     =  L2 + NL2;

        
    Eq1R = real(Eq1).';
    Eq1I = imag(Eq1).';

    Eq2R = real(Eq2).';
    Eq2I = imag(Eq2).';

    f       = [Eq1R;Eq1I;Eq2R;Eq2I];%\;

end
