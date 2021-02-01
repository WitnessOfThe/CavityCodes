function CW = Chi23_CW_Normalization(CW)
%% Define Space 

    Fundamental_Constants;
    N         = CW.In.N;
    CW.Space  = Define_Space_Cavity(N,2*pi);
        
%%

    CW.In.delta_e = CW.In.delta_o - CW.In.eps;
    CW.In.H       = sqrt(CW.In.eta*CW.In.Finess*CW.In.W/pi);    
    norm          = CW.In.ko;

    CW.In.Omega_f    =  CW.In.delta_o - 1i*CW.In.ko/2;
    CW.In.Omega_s    =  8*(CW.In.delta_e - 1i*CW.In.ke/2);
    CW.In.Omega_Star    =  sqrt(2*CW.In.ke*CW.In.ko);
    
%%
    CW.Eq.delta_o         = CW.In.delta_o/norm;
    CW.Eq.delta_e         = CW.In.delta_e/norm;
    CW.Eq.eps             = CW.In.eps/norm;
    
    CW.Eq.ko             = CW.In.ko/norm;                                
    CW.Eq.ke             = CW.In.ke/norm;       
    
    CW.Eq.gam2o          = CW.In.gam2o/norm;
    CW.Eq.gam2e          = CW.In.gam2e/norm;
    
    CW.Eq.gam3o          = CW.In.gam3o/norm;
    CW.Eq.gam3e          = CW.In.gam3e/norm;
    
    CW.Eq.Do              = CW.In.Do/norm;% Dispersion Coefficients,-4E3
    CW.Eq.De              = CW.In.De/norm;% Dispersion Coefficients,-4E3
    CW.Eq.d               = (CW.In.De(1)-CW.In.Do(1))/norm;
    
    CW.Eq.norm            = norm;
    
end
