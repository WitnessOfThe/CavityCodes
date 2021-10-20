    function g = LLE_Bloch_Full_Stability_Matrix(x,Stat)
    
        mask           = 1;% L_L.Eq.mask;
        
        psi_hat        = Stat.Sol.Psi_k.'*Stat.Space.N;
        
        f_psi          = ifft(psi_hat);    
        
        
        x_psi_1          = ifft(x(1:Stat.Space.N));
        x_psi_2          = ifft(x(Stat.Space.N+1:2*Stat.Space.N));
        
       L_pl  = Stat.Eq.delta;
       L_mn  = -Stat.Eq.delta;
       
       i=2;
           L_pl = L_pl - (1i)^i*(Stat.Space.k+Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i) ;
           L_mn = L_mn + (1i)^i*(Stat.Space.k+Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i);
       i=3;
           L_pl = L_pl + 1i*(1i)^i*( Stat.Space.k+Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i) ;
           L_mn = L_mn + 1i*(1i)^i*(Stat.Space.k+Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i);
       
           L_pl = L_pl + 1i*1i*(Stat.Space.k+Stat.In.k)*Stat.Sol.V;
           L_mn = L_mn + 1i*1i*(Stat.Space.k+Stat.In.k)*Stat.Sol.V;
           
           L_pl  =   L_pl.'.*x(1:Stat.Space.N)                ;
           L_mn =    L_mn.'.*x(Stat.Space.N+1:2*Stat.Space.N) ;

           
%        L_pl                   = L_L.Eq.L + 1/2*L_L.In.k^2*L_L.In.Fin_D+L_L.In.k*L_L.In.Fin_D*L_L.Space.k+(L_L.In.k+L_L.Space.k)*L_L.Sol.V;
 %       L_mn                   = L_L.Eq.L + 1/2*L_L.In.k^2*L_L.In.Fin_D-L_L.In.k*L_L.In.Fin_D*L_L.Space.k+(-L_L.In.k+L_L.Space.k)*L_L.Sol.V;
        
        g_1(1:Stat.Space.N,1)    =      L_pl  - 1i*Stat.Eq.kappa/2.*x(1:Stat.Space.N) ...
                            -  Stat.Eq.gamma_Kerr.'.*fft(2*abs(f_psi).^2.*x_psi_1+f_psi.^2.*x_psi_2);
        g_2(1:Stat.Space.N,1)   =       L_mn  - 1i*Stat.Eq.kappa/2.*x(Stat.Space.N+1:2*Stat.Space.N)...
            +   Stat.Eq.gamma_Kerr.'.*fft(2*abs(f_psi).^2.*x_psi_2 + conj(f_psi.^2).*x_psi_1);
        
        g     = -1i.*[mask.'.*g_1;mask.'.*g_2];
        
    end
