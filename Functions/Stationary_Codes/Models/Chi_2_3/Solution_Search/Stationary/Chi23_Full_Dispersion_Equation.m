    function f = Chi23_Full_Dispersion_Equation(x,Stat)
    
        mask                = Stat.Eq.mask;
            
        xo                  = x(1:Stat.Space.N) +...
                                         1i*x(Stat.Space.N+1:2*Stat.Space.N);
        xe                  = x(2*Stat.Space.N+1:3*Stat.Space.N) +...
                                         1i*x(3*Stat.Space.N+1:4*Stat.Space.N);
        
        V                   = x(end);   %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        xoS             = ifft(xo);        
        xeS             = ifft(xe);
        
        abs_psi2        = abs(xoS).^2;
        [~,max_ind]     = max(abs_psi2);
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        Pump(1) = 1/2*Stat.Eq.ko*Stat.In.H*Stat.Space.N;
        
        L1     = -1i*(Stat.Eq.Lo + V*Stat.Space.k).*xo;
        NL1    =  1i*Stat.Eq.gam2o.*fft(xeS.*conj(xoS)) + 1i*Stat.Eq.gam3o.*fft( (abs(xoS).^2 + 2*abs(xeS).^2).*xoS );
        
        L2     = -1i*(Stat.Eq.Le + V*Stat.Space.k).*xe;
        NL2    =  1i*Stat.Eq.gam2e.*fft(xoS.^2) + 1i*Stat.Eq.gam3e.*fft( (2*abs(xoS).^2 + abs(xeS).^2).*xeS);


        f_1    = mask.*( L1 + NL1 );
        f_1(1) = f_1(1) + Pump;
        
        f_2    = mask.*( L2 + NL2 );
        f_3    = ifft(mask.*1i.*Stat.Space.k.*fft(abs_psi2),'symmetric');
        
        f     = [real(f_1).';imag(f_1).';real(f_2).';imag(f_2).';f_3(max_ind).'];%\;
        
    end
