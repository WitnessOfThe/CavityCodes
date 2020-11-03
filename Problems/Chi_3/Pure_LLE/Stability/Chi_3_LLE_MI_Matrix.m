    function  M = Chi_3_LLE_MI_Matrix(L_L,i,j)
   
          Delta_p = L_L.Eq.delta;
          for i_k = 2:size(L_L.Eq.D,2)
        
                Delta_p = Delta_p+ 1/factorial(i_k)*L_L.Space.k(i).^i_k*L_L.Eq.D(i_k);
        
          end
          Delta_m = L_L.Eq.delta;
          for i_k = 2:size(L_L.Eq.D,2)
        
                Delta_m = Delta_m + 1/factorial(i_k)*(-L_L.Space.k(i)).^i_k*L_L.Eq.D(i_k);
        
          end
  
            g_1_1   = -1i*Delta_p- L_L.Eq.kappa_vector(i)/2  + 2*1i.*abs(L_L.Sol.Psi(j)).^2*L_L.Eq.gamma_Kerr(i);
            g_1_2   = 1i.*L_L.Sol.Psi(j).^2*L_L.Eq.gamma_Kerr(i);
            
            g_2_1   = conj(g_1_2);
            g_2_2   =  1i*Delta_m -L_L.Eq.kappa_vector(i)/2 - 2*1i.*abs(L_L.Sol.Psi(j)).^2*L_L.Eq.gamma_Kerr(i);
            
            
            M = [g_1_1,g_1_2;
                g_2_1,g_2_2];
 
    end
