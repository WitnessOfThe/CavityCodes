function Stat_In_Guess_Chi_3_LLE_From_Dyn(L_L)
    
    x0  = [real(L_L.Temp.Sol.Psi(end,:)),imag(L_L.Temp.Sol.Psi(end,:)),0];
    [x,eps_f,SolveFlag] =    L_L.Stat.Met.Newton(L_L.Stat,x0);
        
end