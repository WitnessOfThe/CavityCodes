function CW = Chi23_CW_Normalization(CW)
%% Define Space 

    Fundamental_Constants;
    N         = CW.In.N;
    CW.Space  = Define_Space_Cavity(N,2*pi);
        
%%

    CW.In.delta_e = CW.In.delta_o - CW.In.eps;
    CW.In.H       = sqrt(CW.In.eta*CW.In.Finess*CW.In.W/pi);    
    norm          = CW.In.k_o;

    CW.In.Omega_f    =  CW.In.delta_o - 1i*CW.In.k_o/2;
    CW.In.Omega_s    =  8*(CW.In.delta_e - 1i*CW.In.k_e/2);
    CW.In.Omega_Star    =  sqrt(2*CW.In.k_e*CW.In.k_o);
    
%%
    CW.Eq.delta_o         = CW.In.delta_o/norm;
    CW.Eq.delta_e         = CW.In.delta_e/norm;
    CW.Eq.eps             = CW.In.eps/norm;
    
    CW.Eq.k_o             = CW.In.k_o/norm;                                
    CW.Eq.k_e             = CW.In.k_e/norm;       
    
    CW.Eq.gam2_o          = CW.In.gam2_o/norm;
    CW.Eq.gam2_e          = CW.In.gam2_e/norm;
    
    CW.Eq.gam3_o          = CW.In.gam3_o/norm;
    CW.Eq.gam3_e          = CW.In.gam3_e/norm;
    
    CW.Eq.Do              = CW.In.Do/norm;% Dispersion Coefficients,-4E3
    CW.Eq.De              = CW.In.De/norm;% Dispersion Coefficients,-4E3
    CW.Eq.norm            = norm;
    
end
