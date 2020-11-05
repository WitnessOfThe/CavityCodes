function L_L =  Chi_3_LLE_Start_Point_Stat(L_L)
    
    L_L.Temp.In.Psi_Start = L_L.Stat.Sol.Psi_k*L_L.Temp.Space.N;
    L_L.Temp.In.t_start      = 0;
    L_L.Temp.In.Psi_Start(abs(L_L.Temp.In.Psi_Start)< 1E-8) = 1E-8;
end
