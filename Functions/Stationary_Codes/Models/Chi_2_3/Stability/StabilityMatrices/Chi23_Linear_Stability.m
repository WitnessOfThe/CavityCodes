    function f = Chi23_Linear_Stability(x,Stat)
    
%         xo                  = (x(1:Stat.Space.N) +...
%                                          1i*x(Stat.Space.N+1:2*Stat.Space.N)).';
%         xe                  = (x(2*Stat.Space.N+1:3*Stat.Space.N) +...
%                                          1i*x(3*Stat.Space.N+1:4*Stat.Space.N)).';
%         
%         xV                   = x(end);   %    
%         
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
%         
%         Psio        = Stat.Sol.Psi_o;
%         Psie        = Stat.Sol.Psi_e;
%         
%         
%        
%         abs_psi2        = abs(Psio).^2;
%         [~,max_ind]     = max(abs_psi2);
%                 
%         V               = Stat.Sol.V;
%                 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
%        L1      = ifft( fft(xo).*(Stat.Eq.Lo - V*Stat.Space.k) );
%         
%         NL1     =  - (Stat.Eq.gam2o.*( Psie.*conj(xo) + conj(Psio).*xe ) +...
%                  Stat.Eq.gam3o.*(...
%                  2*(abs(Psio).^2 + abs(Psie).^2 ).*xo + Psio.^2.*conj(xo) + ...
%                          2*conj(Psie).*Psio.*xo + 2*Psio.*Psie.*conj(xe)));
%         
%         L2      = ifft( fft(xe).*(Stat.Eq.Le - V*Stat.Space.k));
%         
%         NL2     =  - (Stat.Eq.gam2e.*( 2*Psio.*xo ) +...
%                  Stat.Eq.gam3e.*( 2*conj(Psio).*Psie.*xo + 2*Psio.*Psie.*conj(xo)...
%                  + 2*( abs(Psio).^2 + abs(Psie).^2 ).*xe + Psie.^2.*conj(xe)) );
%         
%         Eq1     = -1i*( L1 + NL1 );
%             
%         Eq2     = -1i*( L2 + NL2 );
%                 
%         Eq1R(1:Stat.Space.N,1) = real(Eq1);
%         Eq1I(1:Stat.Space.N,1) = imag(Eq1);
%         Eq2R(1:Stat.Space.N,1) = real(Eq2);
%         Eq2I(1:Stat.Space.N,1) = imag(Eq2);
%         
%         f       = [Eq1R;Eq1I;Eq2R;Eq2I];%\;
        mask                = Stat.Eq.mask;
            
        xo                  = mask.*(x(1:Stat.Space.N) +...
                                         1i*x(Stat.Space.N+1:2*Stat.Space.N)).';
        xe                  = mask.*(x(2*Stat.Space.N+1:3*Stat.Space.N) +...
                                         1i*x(3*Stat.Space.N+1:4*Stat.Space.N)).';
        
        xV                   = x(end);   %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        xoS             = ifft(xo);        
        xeS             = ifft(xe);
        
        Psio_hat        = Stat.Space.N*Stat.Sol.Psi_o;
        Psie_hat        = Stat.Space.N*Stat.Sol.Psi_e;
        
        Psio            = ifft(Psio_hat);
        Psie            = ifft(Psie_hat);
        
        V               = Stat.Sol.V;
        
        abs_psi2        = abs(Psio).^2;
        [~,max_ind]     = max(abs_psi2);
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
        L1      = ( xo.*(Stat.Eq.Lo - V*Stat.Space.k) );
        
        NL1     =  - fft(Stat.Eq.gam2o.*( Psie.*conj(xoS) + conj(Psio).*xeS ) +...
                Stat.Eq.gam3o.*(...
                2*(abs(Psio).^2 + abs(Psie).^2 ).*xoS + Psio.^2.*conj(xoS) + ...
                        2*conj(Psie).*Psio.*xoS + 2*Psio.*Psie.*conj(xeS)));
        
        L2      = ( xe.*(Stat.Eq.Le - V*Stat.Space.k));
        
        NL2     =  - fft(Stat.Eq.gam2e.*( 2*Psio.*xoS ) +...
                Stat.Eq.gam3e.*( 2*conj(Psio).*Psie.*xoS + 2*Psio.*Psie.*conj(xoS)...
                + 2*( abs(Psio).^2 + abs(Psie).^2 ).*xeS + Psie.^2.*conj(xeS))) ;
        
        Eq1     = -1i*mask.*( L1 + NL1 );
            
        Eq2     = -1i*mask.*( L2 + NL2 );
        
        
        Eq1R = real(Eq1).';
        Eq1I = imag(Eq1).';
        
        Eq2R = real(Eq2).';
        Eq2I = imag(Eq2).';
        
        f       = [Eq1R;Eq1I;Eq2R;Eq2I];%\;        
    end
