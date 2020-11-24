    function g = LLE_Bloch_Liniar_Decomposition(x,Psi,L_L)
    
        mask           = L_L.Eq.mask_bl;
        psi_hat        = Psi(1:L_L.Space_bl.N).' + 1i*Psi(L_L.Space_bl.N+1:2*L_L.Space_bl.N).';
        V              = 0;%
        
        f_psi          = ifft(psi_hat);    
        abs_psi_2      = abs(f_psi).^2;
        [~,max_ind]    = max(abs_psi_2);
        
%%

        x_v_hat        = x(end);
        x_psi_hat      = x(1:L_L.Space_bl.N) + 1i*x(L_L.Space_bl.N+1:2*L_L.Space_bl.N);
        
        x_psi          = ifft(x_psi_hat);
        

%%
 
       omega_j             = L_L.In.Fin_D*(L_L.In.mu_bl*L_L.Space_bl.k).^2;  

       L                   = (L_L.Eq.delta + omega_j );
        
%%
        Eq = (1i*L_L.Space_bl.k.'.*V -  1i*L.').*x_psi_hat + ...
             1i*L_L.Eq.gamma_Kerr.'.*fft( 2*abs_psi_2.*x_psi + f_psi.^2.*conj(x_psi) )...
                                    + 1i.*L_L.Space_bl.k.'.*x_v_hat.*psi_hat;% ,^
                                
        g_1(1:L_L.Space_bl.N,1)   = real(Eq);
                                        
        g_2(1:L_L.Space_bl.N,1)   = imag(Eq);
        
%        g_3(1:L_L.Space.N,1)   = ifft(1i.*mask.'.*L_L.Space_bl.k.'.*fft( conj(f_psi).*x_psi + f_psi.*conj(x_psi) ) ,'symmetric');
        
        g     = [mask.'.*g_1;mask.'.*g_2];%
        
    end
