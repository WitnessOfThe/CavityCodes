function L_L = Stat_In_Guess_Chi_3_LLE_From_Dyn(L_L)
    
    x0                  = [real(L_L.Temp.Sol.Psi(end,:))*L_L.Temp.Space.N,imag(L_L.Temp.Sol.Psi(end,:))*L_L.Temp.Space.N,0];
    [x,eps_f,SolveFlag] =    L_L.Stat.Met.Newton(L_L.Stat,x0)
    L_L.Stat            = Chi3_LLE_Stat_Prop_Gen(x,L_L.Stat);    
    
end
