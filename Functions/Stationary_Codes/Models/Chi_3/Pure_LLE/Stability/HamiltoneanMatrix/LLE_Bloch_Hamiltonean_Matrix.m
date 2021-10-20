    function g = LLE_Bloch_Hamiltonean_Matrix(x,L_L)
    
        mask           = 1;% L_L.Eq.mask;
        
        psi_hat        = L_L.Sol.Psi_k.'*L_L.Space.N;
        
        f_psi          = ifft(psi_hat);    
        
        
        x_psi_1          = ifft(x(1:L_L.Space.N));
        x_psi_2          = ifft(x(L_L.Space.N+1:2*L_L.Space.N));
        
       L_pl  = L_L.Eq.delta;
       L_mn  = L_L.Eq.delta;
       
       for i = 2:size(L_L.In.D,2)
            
           L_pl = L_pl +(L_L.Space.k+L_L.In.k).^i.*L_L.Eq.D(i)/factorial(i) ;
           L_mn = L_mn +(-L_L.Space.k-L_L.In.k).^i.*L_L.Eq.D(i)/factorial(i);
               
       end
       
%       for i = 3
%             
%           L_pl = L_pl +(L_L.Space.k+L_L.In.k).^i.*L_L.Eq.D(i)/factorial(i) ;
%           L_mn = L_mn +(-L_L.Space.k-L_L.In.k).^i.*L_L.Eq.D(i)/factorial(i);
%                
%       end
           L_pl = L_pl-  (L_L.Space.k+L_L.In.k)*L_L.Sol.V;
           L_mn = L_mn- (-L_L.Space.k-L_L.In.k)*L_L.Sol.V;
           
 %         L_pl  =    L_pl ;                    
%           L_mn =  - L_mn ;
%        L_pl                   = L_L.Eq.L + 1/2*L_L.In.k^2*L_L.In.Fin_D+L_L.In.k*L_L.In.Fin_D*L_L.Space.k+(L_L.In.k+L_L.Space.k)*L_L.Sol.V;
 %       L_mn                   = L_L.Eq.L + 1/2*L_L.In.k^2*L_L.In.Fin_D-L_L.In.k*L_L.In.Fin_D*L_L.Space.k+(-L_L.In.k+L_L.Space.k)*L_L.Sol.V;
        
        g_1(1:L_L.Space.N,1)    = (L_pl.'.*x(1:L_L.Space.N) - ...
             L_L.Eq.gamma_Kerr.'.*fft( 2*abs(f_psi).^2.*x_psi_1 + 0*f_psi.^2.*x_psi_2));
        g_2(1:L_L.Space.N,1)   =  (L_mn.'.*x(L_L.Space.N+1:2*L_L.Space.N) - ...
             L_L.Eq.gamma_Kerr.'.*fft( 2*abs(f_psi).^2.*x_psi_2 + 0*conj(f_psi.^2).*x_psi_1));
        
        g     = [mask.'.*g_1;mask.'.*g_2];
        
    end
