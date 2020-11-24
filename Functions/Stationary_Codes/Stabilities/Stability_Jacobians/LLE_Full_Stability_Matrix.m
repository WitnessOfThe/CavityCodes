    function g = LLE_Full_Stability_Matrix(x,L_L)
    
        mask           = L_L.Eq.mask;
        
        psi_hat        = L_L.Sol.Psi_k'*L_L.Space.N;
        V              = 0;
        
        f_psi          = ifft(psi_hat);    
        
        
        x_psi_1          = ifft(x(1:L_L.Space.N));
        x_psi_2          = ifft(x(L_L.Space.N+1:2*L_L.Space.N));
        

 
        L                   = L_L.Eq.L             + L_L.Space.k.*V;
        
        g_1(1:L_L.Space.N,1)    = L.'.*x(1:L_L.Space.N) - ...
             L_L.Eq.gamma_Kerr.'.*fft( 2*abs(f_psi).^2.*x_psi_1 + f_psi.^2.*x_psi_2);
        g_2(1:L_L.Space.N,1)   = -conj(L).'.*x(L_L.Space.N+1:2*L_L.Space.N) + ...
             L_L.Eq.gamma_Kerr.'.*fft( 2*abs(f_psi).^2.*x_psi_2 + conj(f_psi.^2).*x_psi_1);
        
        g     = [mask.'.*g_1;mask.'.*g_2];
        
    end
