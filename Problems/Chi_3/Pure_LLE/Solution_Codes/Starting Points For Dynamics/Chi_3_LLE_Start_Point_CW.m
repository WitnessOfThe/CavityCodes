function L_L =  Chi_3_LLE_Start_Point_CW(L_L,i)

	L_L.Sol.Temp.Psi_Start    = 1E-7*ones(1,L_L.Space.N);
    L_L.Sol.Temp.Psi_Start(1) = L_L.Sol.CW.Psi(i)*L_L.Space.N;
        
end
