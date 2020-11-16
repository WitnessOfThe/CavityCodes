    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN


    N_mode              = 2^8;
    SiN.Stat.In         = Params_SiN;
    SiN.Stat.In.kappa   = 1E8*2*pi;                 
    SiN.Stat.In.P       = 5;
    SiN.Stat.In.delta   = -1.225E9*2*pi;
    
    
%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%