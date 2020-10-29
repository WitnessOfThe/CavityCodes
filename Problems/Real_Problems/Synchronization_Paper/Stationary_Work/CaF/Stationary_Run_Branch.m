    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Input Parameters for CaF


    N_mode              = 2^8;
    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.P       = 0.0005779;
    CaF.Stat.In.delta   = -0.03668E6*2*pi;
    CaF.Temp.In         = CaF.Stat.In;
    
%% Stationary Coefficeints

    CaF.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    
    CaF.Stat.Met.InitialGuess         = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'
    
    CaF.Stat.Par.step_tol             = 0.00001;
    CaF.Stat.Par.Stability            = 'No';
    CaF.Stat.Par.variable             = 'Pump Power';  %%'Pump Power';
    CaF.Stat.Par.first_step           = 0.001; %min =1E-4/3
    CaF.Stat.Par.Newton_iter          = 30;      
    CaF.Stat.Par.Newton_tol           = 1E-10;  
    CaF.Stat.Par.i_max                = 500;
    CaF.Stat.Par.CW_num               = 3;
    
%% Temporal Coefficients
    
    CaF_Start = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW_Defined(CaF,N_mode,[10,-10]);   
    
