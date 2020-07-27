    function  M = Chi_3_LLE_MI_Matrix(L_L,i,j)
            V = 0;
            g_1_1   = 1i*V*L_L.Space.k(i)-1i*L_L.Space.k(i).^2.*L_L.Eq.D(2)/2  - 1i*1/6*L_L.Space.k(i).^3.*L_L.Eq.D(3) - 1i*1/6/4*L_L.Space.k(i).^4.*L_L.Eq.D(4) - 1i*L_L.Eq.delta - L_L.Eq.kappa_vector(i)/2  + 2*1i.*abs(L_L.Sol.Psi(j)).^2*L_L.Eq.gamma_Kerr(i);
            g_1_2   = 1i.*L_L.Sol.Psi(j).^2*L_L.Eq.gamma_Kerr(i);
            
            g_2_1   = conj(g_1_2);
            g_2_2   = 1i*V*L_L.Space.k(i) +1i*L_L.Space.k(i).^2.*L_L.Eq.D(2)/2  - 1i*1/6*L_L.Space.k(i).^3.*L_L.Eq.D(3) + 1i*1/6/4*L_L.Space.k(i).^4.*L_L.Eq.D(4) + 1i*L_L.Eq.delta -L_L.Eq.kappa_vector(i)/2 - 2*1i.*abs(L_L.Sol.Psi(j)).^2*L_L.Eq.gamma_Kerr(i);
            
            
            M = [g_1_1,g_1_2;
                g_2_1,g_2_2];
 
    end
