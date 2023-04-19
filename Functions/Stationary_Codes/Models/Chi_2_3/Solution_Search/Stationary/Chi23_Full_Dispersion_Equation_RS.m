   function f = Chi23_Full_Dispersion_Equation_RS(x,Stat)
    
        mask                = 1;%Stat.Eq.mask;
            
        xo               = x(1:Stat.Space.N) +...
                                 1i*x(Stat.Space.N+1:2*Stat.Space.N);
                             
        xe               = x(2*Stat.Space.N+1:3*Stat.Space.N) +...
                               1i*x(3*Stat.Space.N+1:4*Stat.Space.N);
         
        V               = x(end);   %    
        [~,ind]         = max(abs(imag(xo)));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        L1     = ifft(mask.*(Stat.Eq.Lo - V*Stat.Space.k).*fft(xo));
        NL1    =  - ifft(Stat.Eq.gam2o.*fft(xe.*conj(xo)) + ...
                            Stat.Eq.gam3o.*fft((abs(xo).^2+2*abs(xe).^2).*xo) );
        
        L2     = ifft(mask.*(Stat.Eq.Le - V*Stat.Space.k).*fft(xe));
        NL2    =  - ifft(Stat.Eq.gam2e.*fft(xo.^2)  +...
                        Stat.Eq.gam3e.*fft((2*abs(xo).^2 + abs(xe).^2).*xe) ) ;
        Pump   = 1i/2*Stat.Eq.ko*Stat.In.H_f;

        f_1    = ( L1 + NL1 + Pump);        
        f_2    = ( L2 + NL2 );
        
%       f_3    = ifft(mask.*1i.*Stat.Space.k.*fft(x(1:Stat.Space.N)),'symmetric');
       f_3    = ifft(1i.*Stat.Space.k.*fft(imag(xo)),'symmetric');
                
        f     = [real(f_1).';imag(f_1).';real(f_2).';imag(f_2).';f_3(ind).'];%\;
        
    end