function In = Params_AlN

    In.eta            = 0.5;                                
    In.ko             = 2*pi*100E6;                                
    In.ke             = 2*pi*200E6;       
    
    In.gam2o          = 2*pi*500E6;
    In.gam2e          = 2*pi*500E6;
    
    In.gam3o          = 0;%2*pi*300E3;
    In.gam3e          = 0;%2*pi*300E3;
    
    In.Do              = 2*pi*[363E9,20E6];% Dispersion Coefficients,-4E3
    In.De              = 2*pi*[351E9,34E6];% Dispersion Coefficients,-4E3
    
    In.Finess         = In.Do(1)/In.ko;
    
    In.H_Star       = sqrt(In.ko*In.ke/4/In.gam2o/In.gam2e);
    In.W_Star       = (In.H_Star^2*pi/In.eta/In.Finess);
    In.Omega_Star    =  sqrt(2*In.ke*In.ko);
  
end