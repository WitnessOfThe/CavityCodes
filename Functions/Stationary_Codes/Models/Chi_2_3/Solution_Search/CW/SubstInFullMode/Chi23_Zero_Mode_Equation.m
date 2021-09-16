    function f = Chi23_Zero_Mode_Equation(x,Stat)
    
        mask                = Stat.Eq.mask;
            
        xo                  = x(1) +...
                                 1i*x(2);
                             
        xe                  = x(3) +...
                               1i*x(4);     
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        Pump(1) = 1i/2*Stat.Eq.ko*Stat.In.H_f;
        
        L1     = (Stat.Eq.Lo(1)).*xo;
        NL1    =  - (Stat.Eq.gam2o.*xe.*conj(xo)+ ...
                       Stat.Eq.gam3o.*(abs(xo).^2 + 2*abs(xe).^2).*xo );
        
        L2     = (Stat.Eq.Le(1)).*xe;
        NL2    =  - fft(Stat.Eq.gam2e.*xo.^2 + ...
                      Stat.Eq.gam3e.*(2*abs(xo).^2 + abs(xe).^2).*xe );
 
        f_1    = mask.*( L1 + NL1 );
        f_1(1) = f_1(1) + Pump;
        
        f_2    = mask.*( L2 + NL2 );
        
        f     = [real(f_1).';imag(f_1).';real(f_2).';imag(f_2).'];%\;
        
    end
