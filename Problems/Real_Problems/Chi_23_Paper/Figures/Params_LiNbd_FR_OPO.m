function In = Params_LiNbd_FR_OPO

    In.eta             = 0.5;                                
    In.ko             = 2*pi*1E6;                                
    In.ke             = 2*pi*4E6;       
    
    In.gam2o          = 2*pi*300E6;
    In.gam2e          = 2*pi*300E6;
    
    In.gam3o          = 0;%2*pi*300E3;
    In.gam3e          = 0;%2*pi*300E3;
    
    In.Do              = 2*pi*[16.92E9,-65E3];% Dispersion Coefficients,-4E3
    In.De              = 2*pi*[15.86E9,-144E3];% Dispersion Coefficients,-4E3
    
    In.Finess         = In.Do(1)/In.ko;
    In.Finess_e       = In.De(1)/In.ke;
    
    In.H_Star       = sqrt(In.ko*In.ke/4/In.gam2o/In.gam2e);
    In.Wf_Star      = (In.H_Star^2*pi/In.eta/In.Finess);
    In.Ws_Star      = (In.H_Star^2*pi/In.eta/In.Finess_e);
    
    In.Omega_Star    =  sqrt(2*In.ke*In.ko);
  
end