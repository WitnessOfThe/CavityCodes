    function g = LLE_Full_Dispersion_Linear_Decomposition_TurnDelta(x,Psi,Stat)
    
       mask           = 1;
        psi_hat         = [Stat.Eq.PsioMax*Stat.Space.N,Psi(2:Stat.Space.N)].' + 1i*Psi(Stat.Space.N+1:2*Stat.Space.N).';
         V              = Psi(end);%
        
        f_psi          = ifft(psi_hat);    
        abs_psi_2      = abs(f_psi).^2;
        [~,max_ind]    = max(abs(real(f_psi)));
        
        delta          = Psi(1);
        xd             = x(1); 
        
%%

        x_v_hat              = x(end);
        x_psi_hat            = x(1:Stat.Space.N) + 1i*x(Stat.Space.N+1:2*Stat.Space.N);
        
        x_psi                = ifft(x_psi_hat);
        

%%  
       L                      = Stat.Eq.L ;
        
%%
        Eq = (1i*Stat.Space.k.'.*V -  1i*(L.'+delta)).*x_psi_hat +(-  1i*psi_hat).*xd + ...
             1i*Stat.Eq.gamma_Kerr.'.*fft( 2*abs_psi_2.*x_psi + f_psi.^2.*conj(x_psi) )...
                                    + 1i.*Stat.Space.k.'.*x_v_hat.*psi_hat;% ,^
                                
        g_1(1:Stat.Space.N,1)   = real(Eq);
                                        
        g_2(1:Stat.Space.N,1)   = imag(Eq);
        
        g_3(1:Stat.Space.N,1)   = ifft(1i.*mask.'.*Stat.Space.k.'.*fft(real(x_psi) ) ,'symmetric');
        
        g     = [mask.'.*g_1;mask.'.*g_2;g_3(max_ind)];%
        
    end
