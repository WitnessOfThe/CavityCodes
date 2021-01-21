function Stat_In_Guess_Chi_3_LLE_From_Dyn(L_L)
    
    x0  = [real(L_L.Temp.Sol.Psi),imag(L_L.Temp.Sol.Psi)];
    x   = Newton_Switcher(x0,L_L);
        
end