function L_L =  Chi_3_LLE_Start_Point_Stat(L_L)
    
    L_L.Temp.In.Psi_Start = L_L.Stat.Sol.Psi_k*L_L.Temp.Space.N;
    L_L.Temp.In.t_start      = 0;
    L_L.Stat.Sol.Psi_k(L_L.Stat.Sol.Psi_k< 1E-10) = 1E-6;
end
