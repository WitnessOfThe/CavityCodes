function Temp = FullField_Normalization(D)
%% Define Space 

    Fundamental_Constants;

%%


    Temp.In.Pump.m_p       = D.In.m_p;
    Temp.In.Pump.ind_pump  = find(D.m == Temp.In.Pump.m_p);

    Temp.In.omega          = D.omega - D.D1(Temp.In.Pump.ind_pump)*D.m;
    Temp.In.kappa          = D.kappa;
    Temp.In.gamma2         = D.gamma2;
    Temp.In.gamma3         = D.gamma3;
    Temp.In.m              = D.m;
    
    Temp.In.Pump.Finesse  = D.D1(Temp.In.Pump.ind_pump)/Temp.In.kappa(Temp.In.Pump.ind_pump);
    Temp.In.Pump.omega_p  = D.omega(Temp.In.Pump.ind_pump) - D.In.delta;
    Temp.In.Pump.delta    = D.In.delta;
    Temp.In.Pump.H        = sqrt(D.In.eta*Temp.In.Pump.Finesse*D.In.W/pi/2);    



        
%%
    norm                  = Temp.In.omega(Temp.In.Pump.ind_pump);

    Temp.Eq.norm          = norm;

    Temp.Eq.Pump.m_p       = D.In.m_p;
    Temp.Eq.Pump.ind_pump  = find(D.m == Temp.In.Pump.m_p);

    Temp.Eq.omega          = Temp.In.omega/Temp.Eq.norm;
    Temp.Eq.kappa          = Temp.In.kappa/Temp.Eq.norm;
    Temp.Eq.gamma2         = Temp.In.gamma2/Temp.Eq.norm;
    Temp.Eq.gamma3         = Temp.In.gamma3/Temp.Eq.norm ;
    Temp.Eq.m              = Temp.In.m;
    
    Temp.Eq.Pump.omega_p   = Temp.In.Pump.omega_p/Temp.Eq.norm;
    Temp.Eq.Pump.delta     = Temp.In.Pump.delta/Temp.Eq.norm;
    Temp.Eq.Pump.H         = Temp.In.Pump.H;        
end
