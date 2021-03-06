    function g = LLE_Zero_Vel_Liniar_Decomposition(x,Psi,L_L)
    
       mask           = L_L.Eq.mask;
       psi_hat        = Psi(1:L_L.Space.N).' + 1i*Psi(L_L.Space.N+1:2*L_L.Space.N).';
        
       f_psi          = ifft(psi_hat);    
       abs_psi_2      = abs(f_psi).^2;
        
%%

        x_psi_hat            = x(1:L_L.Space.N) + 1i*x(L_L.Space.N+1:2*L_L.Space.N);        
        x_psi                = ifft(x_psi_hat);
         
        
%%
        Eq = (-  1i*L_L.Eq.L.').*x_psi_hat + ...
             1i*L_L.Eq.gamma_Kerr.'.*fft( 2*abs_psi_2.*x_psi + f_psi.^2.*conj(x_psi) );% ,^
                                
        g_1(1:L_L.Space.N,1)   = real(Eq);                                        
        g_2(1:L_L.Space.N,1)   = imag(Eq);
        
        g     = [mask.'.*g_1;mask.'.*g_2];%
        
        
    end
