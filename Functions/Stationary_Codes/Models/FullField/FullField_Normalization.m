function Temp = FullField_Normalization(D)
%% Define Space 

    Fundamental_Constants;
%%

    Temp.In.N              = D.In.N;

    m                                                = 0:Temp.In.N-1;
    for im =1:size(D.m,2)
        Temp.Eq.mode_range(im)    = find(m == D.m(im));
    end
    Temp.Space  = Define_Space_Cavity(D.In.N*2,2*pi);
    Temp.In.Pump.m_p       = D.In.m_p;

    Temp.In.Pump.ind_pump  = find(D.m == Temp.In.Pump.m_p);

    Temp.In.omega          = D.omega; %- D.D1(Temp.In.Pump.ind_pump)*D.m;
    Temp.In.kappa          = D.kappa;
    Temp.In.gamma2         = D.gamma2;
    Temp.In.gamma3         = D.gamma3;
    Temp.In.f_off          = D.In.f_off;
    Temp.In.W          =     D.In.W;
    Temp.In.m              = D.m;
    
    Temp.In.Pump.D1       = D.D1(Temp.In.Pump.ind_pump);
    Temp.In.Pump.Finesse  = D.D1(Temp.In.Pump.ind_pump)/Temp.In.kappa(Temp.In.Pump.ind_pump);
    Temp.In.Pump.omega_p  = Temp.In.omega(Temp.In.Pump.ind_pump) - D.In.delta;%- D.D1(Temp.In.Pump.ind_pump)*D.m(Temp.In.Pump.ind_pump);
    Temp.In.Pump.delta    = D.In.delta;
    Temp.In.Pump.H        = sqrt(D.In.eta*Temp.In.Pump.Finesse*D.In.W/pi/2);    
    Temp.In.g             = D.In.g;


        
%%
%    norm                  = Temp.In.omega(Temp.In.Pump.ind_pump);
    norm                  = Temp.In.kappa(Temp.In.Pump.ind_pump);

    Temp.Eq.norm          = norm;


    Temp.Eq.Pump.m_p       = D.In.m_p;
    Temp.Eq.Pump.ind_pump  = find(D.m == Temp.In.Pump.m_p);
    Temp.Eq.Pump.D1       = D.D1(Temp.In.Pump.ind_pump)/Temp.Eq.norm;

    Temp.Eq.omega          = Temp.In.omega/Temp.Eq.norm;
    Temp.Eq.kappa          = Temp.In.kappa/Temp.Eq.norm;
    Temp.Eq.gamma2         = Temp.In.gamma2/Temp.Eq.norm;
    Temp.Eq.gamma3         = Temp.In.gamma3/Temp.Eq.norm ;
    Temp.Eq.m              = Temp.In.m;
    Temp.Eq.g              = D.In.g;
    
    Temp.Eq.Pump.omega_p   = Temp.In.Pump.omega_p/Temp.Eq.norm;
    Temp.Eq.Pump.delta     = Temp.Eq.omega(Temp.In.Pump.ind_pump) - Temp.Eq.Pump.omega_p;
    Temp.Eq.Pump.H         = Temp.In.Pump.H;     

end
