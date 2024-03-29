function L_L = Stat_In_Guess_Chi_3_LLE_From_Dyn(L_L,N_mode)

    L_L.Stat.In    = L_L.Temp.In;
    
    L_L.Stat       = L_L.CW.Met.Norm(L_L.Stat,N_mode);    
    
    Psi                         = zeros(1,N_mode);    
    Psi(L_L.Temp.Eq.mode_range) = L_L.Temp.Sol.Psi(end,:);
    
    x0                  = [real(Psi),imag(Psi),0]*L_L.Temp.Space.N;
    
    [x,eps_f,SolveFlag] =    L_L.Stat.Met.Newton(L_L.Stat,x0);
    eps_f
    L_L.Stat            = Chi3_LLE_Stat_Prop_Gen(x,L_L.Stat);    
    
end
