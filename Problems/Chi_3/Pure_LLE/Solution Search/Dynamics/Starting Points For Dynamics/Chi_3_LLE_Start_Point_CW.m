function L_L =  Chi_3_LLE_Start_Point_CW(L_L)

    L_L.CW.In           = L_L.Temp.In;
    
    L_L.CW       = L_L.CW.Met.Solve(L_L.CW,L_L.Temp.Space.N);
    L_L.CW.In.g  = L_L.CW.Sol.g(L_L.Temp.Par.CW_num)*L_L.CW.Eq.norm;
    
    L_L.CW      = L_L.CW.Met.Mi_Formula(L_L.CW,L_L.Temp.Space.N);    
    
    L_L.Temp.In.Psi_Start = ones(1,L_L.Temp.Space.N)*1E-10;
	L_L.Temp.In.Psi_Start(L_L.CW.An.Omega_mu(1,:) == 0)    = 1E-2;
	L_L.Temp.In.Psi_Start( 1:(end/2) )    = -1i*10*L_L.Temp.In.Psi_Start( 1:(end/2) );
    
    L_L.Temp.In.Psi_Start(1) = L_L.CW.Sol.Psi(L_L.Temp.Par.CW_num)*L_L.Temp.Space.N;
    L_L.Temp.In.t_start      = 0;
    
end
