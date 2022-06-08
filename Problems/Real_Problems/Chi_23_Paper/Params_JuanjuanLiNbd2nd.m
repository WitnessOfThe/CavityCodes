function In = Params_JuanjuanLiNbd2nd
    Fundamental_Constants;
    In.eta             = 0.5;                                
    In.ko             = 2*2*pi*300E6;                                
    In.ke             = 2*2*pi*800E6; %2*pi*4E6     e
    
    In.Omega_o        = Const.c/1550E-9*2*pi;
    In.Omega_e        = Const.c/1550E-9*2*pi*2;
    
%    In.gam2o          = 2*pi*6.4274e+09;
%    In.gam2e          = 2*pi*6.4274e+09;
    
%    In.gam3o          = 2*pi*29E6;
%    In.gam3e          = 2*pi*29E6;
    
    In.Do              = 2*pi*[286.24E9, 14E6,153E3,0];% Dispersion Coefficients,-4E3
    In.De              = 2*pi*[289.24E9,-18E6,-103E3,0];% Dispersion Coefficients,-4E3
%%
    In.Do              = 2*pi*[286.24E9, 14E6,0,0];% Dispersion Coefficients,-4E3
    In.De              = 2*pi*[289.24E9,-18E6,0,0];% Dispersion Coefficients,-4E3

    In.g2o             = 2*pi*1.2E6; 
    In.g2e             = 2*pi*1.2E6;

    In.g3o             = 2*pi*2.2;
    In.g3e             = 2*pi*2.2;

    In                 = Chi23_g_to_gamma(In);
    
 %   In.Do              = 2*pi*[286.24E9,200E6];% Dispersion Coefficients,-4E3
  %  In.De              = 2*pi*[289.24E9,300E9];% Dispersion Coefficients,-4E3
  %   In.Do              = 2*pi*[286.24E9,0.2E9,1.9649E-4*1E9,-3.7692E-6*1E9];% Dispersion Coefficients,-4E3
    
    In.Finess         = In.Do(1)/In.ko;
    In.Finess_e       = In.De(1)/In.ke;
    
    In.H_Star       = sqrt(In.ko*In.ke/4/In.gam2o/In.gam2e);
    In.Wf_Star      = (In.H_Star^2*pi/In.eta/In.Finess);
    In.Ws_Star      = (In.H_Star^2*pi/In.eta/In.Finess_e);
    
    In.Omega_Star    =  sqrt(2*In.ke*In.ko);
  
end