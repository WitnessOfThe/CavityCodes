    function g = LLE_Full_Stability(x,L_L)
    
        mask           = L_L.Eq.Shifted.mask;
        
        psi_hat        = L_L.Solution.E_j';
        V              = L_L.Solution.V;
        
        f_psi          = ifft(psi_hat);    
        
        x_psi_hat            = x(1:L_L.Space.N) + 1i*x(L_L.Space.N+1:2*L_L.Space.N);        
        x_psi                = ifft(x_psi_hat);
        

        omega_j             = L_L.Eq.Shifted.omega_j;  
 
       L                   = (L_L.Eq.delta + omega_j );
        
        Eq = (1i*L_L.Space.k.'.*V -  1i*L.').*x_psi_hat + ...
             1i*L_L.Eq.Shifted.gamma_Kerr.'.*fft( 2*abs(f_psi).^2.*x_psi + f_psi.^2.*conj(x_psi));
                                
        g_1(1:L_L.Space.N,1)   = real(Eq);
                                        
        g_2(1:L_L.Space.N,1)   = imag(Eq);
        
        g     = [mask.'.*g_1;mask.'.*g_2];
        
    end
