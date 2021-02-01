function  M = Chi23_MI_Matrix(CW,i,j)

    M1 = Chi2_MI_Matrix(CW,i,j);
    
    g_1_1 = - 2*CW.Eq.gam3o*(abs(CW.Sol.Psi_o(j)).^2+abs(CW.Sol.Psi_e(j)).^2);
    g_1_2 = - 2*sqrt(2)*CW.Eq.gam3o/sqrt(CW.Eq.gam2o/CW.Eq.gam2e)*conj(CW.Sol.Psi_o(j))*CW.Sol.Psi_e(j);    
    g_1_3 = - CW.Eq.gam3o*conj(CW.Sol.Psi_o(j).^2);
    g_1_4 = - 2*sqrt(2)*CW.Eq.gam3o/sqrt(CW.Eq.gam2o/CW.Eq.gam2e)*conj(CW.Sol.Psi_o(j)*CW.Sol.Psi_e(j));
    
    g_2_1 = - sqrt(2)*CW.Eq.gam3e*sqrt(CW.Eq.gam2o/CW.Eq.gam2e)*CW.Sol.Psi_o(j)*conj(CW.Sol.Psi_e(j));
    g_2_2 = - 2*CW.Eq.gam3e*(abs(CW.Sol.Psi_o(j)).^2+abs(CW.Sol.Psi_e(j)).^2);    
    g_2_3 = - sqrt(2)*CW.Eq.gam3e*sqrt(CW.Eq.gam2o/CW.Eq.gam2e)*conj(CW.Sol.Psi_o(j)*CW.Sol.Psi_e(j));
    g_2_4 = - CW.Eq.gam3e*(conj(CW.Sol.Psi_e(j)).^2); 
    
    g_3_1 =   CW.Eq.gam3o*CW.Sol.Psi_o(j).^2;
    g_3_2 =   2*sqrt(2)*CW.Eq.gam3o/sqrt(CW.Eq.gam2o/CW.Eq.gam2e)*CW.Sol.Psi_o(j)*CW.Sol.Psi_e(j);    
    g_3_3 =   2*CW.Eq.gam3o*(abs(CW.Sol.Psi_o(j)).^2+abs(CW.Sol.Psi_e(j)).^2);
    g_3_4 =   2*sqrt(2)*CW.Eq.gam3o/sqrt(CW.Eq.gam2o/CW.Eq.gam2e)*conj(CW.Sol.Psi_e(j))*CW.Sol.Psi_o(j);
    
    g_4_1 =   sqrt(2)*CW.Eq.gam3e*sqrt(CW.Eq.gam2o/CW.Eq.gam2e)*CW.Sol.Psi_o(j)*CW.Sol.Psi_e(j);
    g_4_2 =   CW.Eq.gam3e*(CW.Sol.Psi_e(j)).^2;    
    g_4_3 =   sqrt(2)*CW.Eq.gam3e*sqrt(CW.Eq.gam2o/CW.Eq.gam2e)*conj(CW.Sol.Psi_o(j))*CW.Sol.Psi_e(j);
    g_4_4 =   2*CW.Eq.gam3e*(abs(CW.Sol.Psi_o(j)).^2+abs(CW.Sol.Psi_e(j)).^2);
    
    M = [g_1_1,g_1_2,g_1_3,g_1_4;
         g_2_1,g_2_2,g_2_3,g_2_4;
         g_3_1,g_3_2,g_3_3,g_3_4;
         g_4_1,g_4_2,g_4_3,g_4_4];
     
     M = M1+M;

end
