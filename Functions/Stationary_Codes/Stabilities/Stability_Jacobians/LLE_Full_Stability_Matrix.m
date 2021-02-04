    function g = LLE_Full_Stability_Matrix(x,L_L)
    
        mask           = L_L.Eq.mask;
        
       psi_hat        = L_L.Sol.Psi_k.'*L_L.Space.N;
        V              = L_L.Sol.V;
        
        f_psi          = ifft(psi_hat);    
        abs_psi_2      = abs(f_psi).^2;
        
        x_psi_hat            = x(1:L_L.Space.N) + 1i*x(L_L.Space.N+1:2*L_L.Space.N);
        
        x_psi               = ifft(x_psi_hat);
        x_psi_s             =(conj(x_psi));
       L                   = L_L.Eq.L - V*L_L.Space.k ;
         

        Eq = (-  1i*L.').*x_psi_hat + ...
             1i*L_L.Eq.gamma_Kerr.'.*fft( 2*abs_psi_2.*x_psi + f_psi.^2.*x_psi_s );% ,^
                                
        g_1(1:L_L.Space.N,1)   = real(Eq);
                                        
        g_2(1:L_L.Space.N,1)   = imag(Eq);
        
        
        g     = [mask.'.*g_1;mask.'.*g_2];
%         psi_hat        = L_L.Sol.Psi_k.'*L_L.Space.N;
%         V              = L_L.Sol.V;
%         
%         f_psi          = ifft(psi_hat);    
%          mask           = L_L.Eq.mask;
%         
%         x_psi_1          = ifft(x(1:L_L.Space.N));
%         x_psi_2          = ifft(x(L_L.Space.N+1:2*L_L.Space.N));
%         
% 
%  
%         L                   = L_L.Eq.L  ;
%         
%         g_1(1:L_L.Space.N,1)    =  ( -  1i*(L-V*L_L.Space.k ).').*x(1:L_L.Space.N)        +...
%              1i*L_L.Eq.gamma_Kerr.'.*fft( 2*abs(f_psi).^2.*x_psi_1 + f_psi.^2.*x_psi_2);
%          
%         g_2(1:L_L.Space.N,1)   = conj(-  1i*(L-V*L_L.Space.k ).').*x(L_L.Space.N+1:2*L_L.Space.N) - ...
%              1i*L_L.Eq.gamma_Kerr.'.*fft( 2*abs(f_psi).^2.*x_psi_2 + conj(f_psi).^2.*x_psi_1);
%         
%         g     = [mask.'.*g_1;mask.'.*g_2];

    end
