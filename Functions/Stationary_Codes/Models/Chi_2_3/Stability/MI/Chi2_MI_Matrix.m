function  M = Chi2_MI_Matrix(CW,i,j)

    switch func2str(CW.Met.MI_Matrix)
        
        case 'Chi2_MI_Matrix'
            Psi_o = abs(CW.Sol.Omega(j)./CW.In.Omega_Star*CW.In.H_Star);
            Psi_e = abs(CW.Sol.Omega(j).^2/CW.In.Omega_s/CW.In.gam2o); 
            
        case 'Chi23_MI_Matrix'
            
            Psi_o = CW.Sol.Psi_o;
            Psi_e = CW.Sol.Psi_e;
            
    end
    
    g_1_1 = CW.In.kMI(i).^2*CW.Eq.Do(2)/2-1i*1/2*CW.Eq.ko+CW.Eq.delta_o;
    g_1_2 = -sqrt(2*CW.Eq.gam2o*CW.Eq.gam2e)*Psi_o; 
    g_1_3 = -CW.Eq.gam2o*conj(Psi_e); 
    g_1_4 = 0; 
    
    g_2_1 = -sqrt(2*CW.Eq.gam2o*CW.Eq.gam2e)*conj(Psi_o);
    g_2_2 = CW.In.kMI(i)*CW.Eq.d+CW.In.kMI(i).^2*CW.Eq.De(2)/2-1i*1/2*CW.Eq.ke+CW.Eq.delta_e; 
    g_2_3 = 0; 
    g_2_4 = 0; 
    
    g_3_1 = CW.Eq.gam2o*(Psi_e);
    g_3_2 = 0; 
    g_3_3 = -CW.In.kMI(i).^2*CW.Eq.Do(2)/2-1i*1/2*CW.Eq.ko-CW.Eq.delta_o; 
    g_3_4 = sqrt(2*CW.Eq.gam2o*CW.Eq.gam2e)*conj(Psi_o); 

    g_4_1 = 0;
    g_4_2 = 0; 
    g_4_3 = sqrt(2*CW.Eq.gam2o*CW.Eq.gam2e)*(Psi_o); 
    g_4_4 = CW.In.kMI(i)*CW.Eq.d-CW.In.kMI(i).^2*CW.Eq.De(2)/2-1i*1/2*CW.Eq.ke-CW.Eq.delta_e; 
    
    M = [g_1_1,g_1_2,g_1_3,g_1_4;
         g_2_1,g_2_2,g_2_3,g_2_4;
         g_3_1,g_3_2,g_3_3,g_3_4;
         g_4_1,g_4_2,g_4_3,g_4_4];

end
