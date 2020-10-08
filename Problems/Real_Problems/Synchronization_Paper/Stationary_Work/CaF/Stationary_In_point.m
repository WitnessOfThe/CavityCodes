    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN


    N_mode              = 2^10;
    SiN.Stat.In.omega_p = 200E12*2*pi;
    SiN.Stat.In         = Params_CaF;
    SiN.Stat.In.kappa   = 2E3*2*pi;                 
    SiN.Stat.In.P       = 0.5;
    SiN.Stat.In.delta   = -0.58E6*2*pi;
    
%%
    SiN.Stat.Par.i_max                = 2000;
    SiN.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';
    
    SiN.Stat.Met.InitialGuess         = @Stat_In_Guess_Chi_3_LLE_From_Dyn;
    
    SiN.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'
    SiN.Stat.Par.step_tol             = 1E-10;
    SiN.Stat.Par.Stability            = 'No';
    SiN.Stat.Par.variable             = 'delta';  
    SiN.Stat.Par.first_step           = 1; %min =1E-4/3
    SiN.Stat.Par.Newton_iter          = 50;      
    SiN.Stat.Par.Newton_tol           = 1E-9;  
    SiN.Stat.Par.Sol_Flag             = '-';
    SiN.Stat.Par.i_max                = 200;
    SiN.Stat.Par.CW_num               =3;
%%

    SiN = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW(SiN,N_mode);
%    SiN.Stat = Run_Branch_Universal(SiN);

    
