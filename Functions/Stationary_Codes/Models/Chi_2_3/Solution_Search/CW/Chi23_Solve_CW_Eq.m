function CW = Chi23_Solve_CW_Eq(CW)

    CW = CW.Met.Norm(CW);       
    
    [Slv,eps_f,Output]      = Newton_Switcher([real(CW.Sol.Psi_o),imag(CW.Sol.Psi_o),real(CW.Sol.Psi_e),imag(CW.Sol.Psi_e)],CW);
    
    CW(1).Sol.Flag      = Output;
    CW(1).Sol.eps       = eps_f; 
       
end
