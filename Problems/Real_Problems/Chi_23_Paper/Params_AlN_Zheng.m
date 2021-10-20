function In = Params_AlN_Zheng

    In.eta             = 0.3453;                                
    
    In.ko             = 2*pi*333E6;                                
    In.ke             = 2*pi*1.549E9; %2*pi*4E6      
    
    In.gam2o          = 2*pi*3.2E9;
    In.gam2e          = 2*pi*3.2E9;
    
    In.gam3o          = 2*pi*6E8;
    In.gam3e          = 2*pi*3.6E9;
    
    In.Do              = 2*pi*[722E9,100E6];% Dispersion Coefficients,-4E3
    In.De              = 2*pi*[700E9,138E6];% Dispersion Coefficients,-4E3
    
    In.Finess         = In.Do(1)/In.ko;
    In.Finess_e       = In.De(1)/In.ke;
    
    In.H_Star       = sqrt(In.ko*In.ke/4/In.gam2o/In.gam2e);
    In.Wf_Star      = (In.H_Star^2*pi/In.eta/In.Finess);
    In.Ws_Star      = (In.H_Star^2*pi/In.eta/In.Finess_e);
    
    In.Omega_Star    =  sqrt(2*In.ke*In.ko);
  
end