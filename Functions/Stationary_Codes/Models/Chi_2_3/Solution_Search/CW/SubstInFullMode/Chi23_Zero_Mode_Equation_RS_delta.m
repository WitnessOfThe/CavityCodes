    function f = Chi23_Zero_Mode_Equation_RS_delta(x,Stat)
    
            
        xo                  = [Stat.Eq.PsioMax] + ...
                                 1i*x(2);
                             
        xe                  = x(3) + ...
                               1i*x(4);
        
        delta               = x(1);     %    
        
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
        L1     = ((Stat.Eq.Lo(1) +   delta ).*(xo));
        
        NL1    =  - (Stat.Eq.gam2o.*xe.*conj(xo) + ...
                            Stat.Eq.gam3o.*(abs(xo).^2 + 2*abs(xe).^2).*xo);
        
        L2     = ((Stat.Eq.Le(1) + 2*delta ).*(xe));
        NL2    =  - (Stat.Eq.gam2e.*xo.^2  + ...
                        Stat.Eq.gam3e.*(2*abs(xo).^2 + abs(xe).^2).*xe);
        
        Pump   = 1i/2*Stat.Eq.ko*Stat.In.H_f;

        f_1    = ( L1 + NL1+ Pump );        
        f_2    = ( L2 + NL2  );
        
        f     = [real(f_1).';imag(f_1).';real(f_2).';imag(f_2).'];%\;
        
    end