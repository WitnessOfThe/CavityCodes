    clc;
    clear all;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    SiN.CW.In         = Params_SiN;
    SiN.CW.In.kappa   =  150E6*2*pi;%2*1E3*2*pi;%
    SiN.CW.In.P       = 0.1;
    SiN.CW.In.delta   = SiN.CW.In.kappa*2;
    SiN.Temp.In       = SiN.CW.In;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%

    N      = 200;   
    N_Mode = 2^8;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%
    
    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 2E-4;
    SiN.Temp.Par.s_t           = 0.01;
    SiN.Temp.Par.T             = 500;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
    SiN.Temp.Par.dd            = SiN.Temp.Par.T/SiN.Temp.Par.s_t;
    SiN.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(SiN.Temp.Par);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%

    SiN.Temp        =   Chi_3_LLE_Normalization(SiN.Temp,N_Mode);       
    SiN.CW          =   Chi_3_LLE_Normalization(SiN.CW,N_Mode);       
   
    SiN.CW          =   SiN.CW.Met.Solve(SiN.CW,N_Mode);
    SiN             =   SiN.Temp.Met.Ev_Start_Point(SiN);  
    
%%
