    function  M = Chi_3_LLE_MI_Matrix(L_L,i,j)
   
    ome_rev              = zeros(1,L_L.Space.N);
    ome_rev(2:end/2)     = fliplr(L_L.In.omega_int(end/2+2:end));
    ome_rev(end/2+3:end) = fliplr(L_L.In.omega_int(2:end/2-1));
    ome_rev(1)           = L_L.In.omega_int(1);
    
    Delta_p  = (L_L.In.delta + L_L.In.omega_int)/L_L.In.kappa;
    Delta_m  = (L_L.In.delta + ome_rev)/L_L.In.kappa;
  
    g_1_1   = -1i*Delta_p(i)- L_L.Eq.kappa_vector(i)/2  + 2*1i.*abs(L_L.Sol.Psi(j)).^2*L_L.Eq.gamma_Kerr(i);
    g_1_2   =  1i.*L_L.Sol.Psi(j).^2*L_L.Eq.gamma_Kerr(i);

    g_2_1   =  conj(g_1_2);
    g_2_2   =  1i*Delta_m(i) - L_L.Eq.kappa_vector(i)/2 - 2*1i.*abs(L_L.Sol.Psi(j)).^2*L_L.Eq.gamma_Kerr(i);
            
    M = [g_1_1,g_1_2;
         g_2_1,g_2_2];
 
    end
