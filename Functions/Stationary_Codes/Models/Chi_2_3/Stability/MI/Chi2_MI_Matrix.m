function  M = Chi2_MI_Matrix(CW,i,j)
    
    g_1_1 = CW.Space.k(i).^2*CW.Eq.D_o(2)/2-1/2*CW.Eq.k_o+CW.Eq.delta_o;
    g_1_2 = -sqrt(2*CW.Eq.gam2o*CW.Eq.gam2e)*CW.Sol.Psi_o(j); 
    g_1_3 = -CW.Eq.gam2o*conj(CW.Sol.Psi_e(j)); 
    g_1_4 = 0; 
    
    g_2_1 = -sqrt(2*CW.Eq.gam2o*CW.Eq.gam2e)*conj(CW.Sol.Psi_o(j));
    g_2_2 = CW.Space.k(i)*CW.Eq.d+CW.Space.k(i).^2*CW.Eq.D_e(2)/2-1/2*CW.Eq.k_e+CW.Eq.delta_e; 
    g_2_3 = 0; 
    g_2_4 = 0; 
    
    g_3_1 = CW.Eq.gam2o*(CW.Sol.Psi_e(j));
    g_3_2 = 0; 
    g_3_3 = -CW.Space.k(i).^2*CW.Eq.D_o(2)/2-1/2*CW.Eq.k_o-CW.Eq.delta_o; 
    g_3_4 = sqrt(2*CW.Eq.gam2o*CW.Eq.gam2e)*conj(CW.Sol.Psi_o(j)); 

    g_4_1 = 0;
    g_4_2 = 0; 
    g_4_3 = sqrt(2*CW.Eq.gam2o*CW.Eq.gam2e)*(CW.Sol.Psi_o(j)); 
    g_4_4 = CW.Space.k(i)*CW.Eq.d-CW.Space.k(i).^2*CW.Eq.D_e(2)/2-1/2*CW.Eq.k_e-CW.Eq.delta_e; 
    
    M = [g_1_1,g_1_2,g_1_3,g_1_4;
         g_2_1,g_2_2,g_2_3,g_2_4;
         g_3_1,g_3_2,g_3_3,g_3_4;
         g_4_1,g_4_2,g_4_3,g_4_4];

end
