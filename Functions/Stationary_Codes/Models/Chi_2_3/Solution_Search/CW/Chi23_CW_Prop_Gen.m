function CW = Chi23_CW_Prop_Gen(x0,CW)

    CW(1).Sol.Psi_o     = x0(1) + 1i*x0(2);
    CW(1).Sol.Psi_e     = x0(3) + 1i*x0(4);
    
    CW(1).Sol.Omega     = abs(CW(1).Sol.Psi_o)*CW.In.Omega_Star/CW.In.H_Star;
    
end