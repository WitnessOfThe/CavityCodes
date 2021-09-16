    function f = Chi23_Full_Dispersion_Equation_RS_delta(x,Stat)
    
        mask                = Stat.Eq.mask;
            
        xo                  = [Stat.Eq.PsioMax,x(2:Stat.Space.N)] + ...
                                 1i*x(Stat.Space.N+1:2*Stat.Space.N);
                             
        xe                  = x(2*Stat.Space.N+1:3*Stat.Space.N) + ...
                               1i*x(3*Stat.Space.N+1:4*Stat.Space.N);
        
        V                   = x(end);   %    
        delta               = x(1);     %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
         [~,ind]         = max(abs(real(xo)));
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%        Pump(1) = 1i/2*Stat.Eq.ko*Stat.In.H*Stat.Space.N;
        
        L1     = ifft((Stat.Eq.Lo +   delta - V*Stat.Space.k).*fft(xo));
        
        NL1    =  - (Stat.Eq.gam2o.*xe.*conj(xo) + ...
                            Stat.Eq.gam3o.*(abs(xo).^2 + 2*abs(xe).^2).*xo);
        
        L2     = ifft((Stat.Eq.Le + 2*delta - V*Stat.Space.k).*fft(xe));
        NL2    =  - (Stat.Eq.gam2e.*xo.^2  + ...
                        Stat.Eq.gam3e.*(2*abs(xo).^2 + abs(xe).^2).*xe);
        
        Pump   = 1i/2*Stat.Eq.ko*Stat.In.H_f;

        f_1    = ( L1 + NL1+ Pump );        
        f_2    = ( L2 + NL2  );
        
        f_3    = ifft(1i.*Stat.Space.k.*fft(real(xo)),'symmetric');
        
%        [Max_o,max_ind] = max(abs_psi2);
        
     %   f_4    = Max_o - Stat.Eq.PsioMax;
        
        f     = [real(f_1).';imag(f_1).';real(f_2).';imag(f_2).';f_3(ind).'];%\;
        
    end