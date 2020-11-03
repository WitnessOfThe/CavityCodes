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
    L_L.Stat.Par.i_max                = 2000;
    L_L.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';
    
    L_L.Stat.Met.InitialGuess         = @Stat_In_Guess_Chi_3_LLE_From_Dyn;
    
    L_L.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'
    L_L.Stat.Par.step_tol             = 1E-10;
    L_L.Stat.Par.Stability            = 'No';
    L_L.Stat.Par.variable             = 'delta';  
    L_L.Stat.Par.first_step           = 1; %min =1E-4/3
    L_L.Stat.Par.Newton_iter          = 50;      
    L_L.Stat.Par.Newton_tol           = 1E-9;  
    L_L.Stat.Par.Sol_Flag             = '-';
    L_L.Stat.Par.i_max                = 200;
