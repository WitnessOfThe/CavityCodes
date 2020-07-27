function In =  Chi_3_LLE_Start_Point_CW(L_L)

	In.Psi_Start    = 1E-7*ones(1,L_L.Temp.Space.N);
    In.Psi_Start(1) = L_L.CW.Sol.Psi(L_L.Temp.Par.CW_num)*L_L.Temp.Space.N;
    In.t_start      = 0;
    
end
