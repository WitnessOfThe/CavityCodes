function In = Params_LiNbd

    In.eta             = 0.5;                                
    In.k_o             = 2*pi*1E6;                                
    In.k_e             = 2*pi*20E6;       
    
    In.gam2_o          = 2*pi*300E6;
    In.gam2_e          = 2*pi*300E6;
    
    In.gam3_o          = 2*pi*300E3;
    In.gam3_e          = 2*pi*300E3;
    
    In.Do              = 2*pi*[21E9,-100E3];% Dispersion Coefficients,-4E3
    In.De              = 2*pi*[20E9,-200E3];% Dispersion Coefficients,-4E3
    
    In.Finess         = In.Do(1)/In.k_o;
    
    In.H_Star       = sqrt(In.k_o*In.k_e/4/In.gam2_o/In.gam2_e);
    In.W_Star       = (In.H_Star^2*pi/In.eta/In.Finess);
    
end