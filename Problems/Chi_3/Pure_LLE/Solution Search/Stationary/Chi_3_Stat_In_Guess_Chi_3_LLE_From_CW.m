function L_L = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW(L_L,N_Mode)

    L_L.CW.In    = L_L.Stat.In;
    
    L_L.CW       = L_L.CW.Met.Norm(L_L.CW,N_Mode);    
    L_L.Stat     = L_L.CW.Met.Norm(L_L.Stat,N_Mode);    
    
    L_L.CW       = L_L.CW.Met.Solve(L_L.CW,L_L.Stat.Space.N);
    L_L.CW.In.g  = L_L.CW.Sol.g(L_L.Stat.Par.CW_num)*L_L.CW.Eq.norm;
    
    L_L.CW      = L_L.CW.Met.Mi_Formula(L_L.CW,L_L.Stat.Space.N);    
    
    L_L.Stat.In.Psi_Start = ones(1,L_L.Stat.Space.N)*1E-3*(1+1i);
	L_L.Stat.In.Psi_Start(L_L.CW.An.Omega_mu(1,1:end/2) == 0)    = 1;
	L_L.Stat.In.Psi_Start(L_L.CW.An.Omega_mu(1,end/2+1:end) == 0)    = 1i;
    
	
    L_L.Stat.In.Psi_Start(1) = L_L.CW.Sol.Psi(L_L.Stat.Par.CW_num)*L_L.Stat.Space.N;
    L_L.Stat.In.t_start      = 0;
    
    x0                       = [real(L_L.Stat.In.Psi_Start),imag(L_L.Stat.In.Psi_Start),0];
    [x,eps_f,SolveFlag]      =    L_L.Stat.Met.Newton(L_L.Stat,x0);
    eps_f
    L_L.Stat                 = Chi3_LLE_Stat_Prop_Gen(x,L_L.Stat);    
    
end
