    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF


    N_Mode              = 2^11;
    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.P       = 0.3;
    CaF.Stat.In.delta   = -0.6005E6*2*pi;
    
    CaF.Temp.In         = CaF.Stat.In;
    
%% Stationary Coefficeints

    CaF.Stat.Par.i_max                = 2000;
    CaF.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    
    CaF.Stat.Met.InitialGuess         = @Stat_In_Guess_Chi_3_LLE_From_Dyn;    
    CaF.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'
    
    CaF.Stat.Par.step_tol             = 1E-10;
    CaF.Stat.Par.Stability            = 'Yes';
    CaF.Stat.Par.variable             = 'delta';  
    CaF.Stat.Par.first_step           = 1; %min =1E-4/3
    CaF.Stat.Par.Newton_iter          = 50;      
    CaF.Stat.Par.Newton_tol           = 1E-10;  
    CaF.Stat.Par.i_max                = 200;
    CaF.Stat.Par.CW_num               = 3;
    
%%

    CaF.CW.In    = CaF.Stat.In;
    CaF.CW       = CaF.CW.Met.Norm(CaF.CW,N_Mode);
    CaF.Stat     = CaF.Stat.Met.Norm(CaF.Stat,N_Mode);
    CaF.CW       = MI(CaF.CW,N_Mode);

%% Temporal Coefficients

    CaF           =     Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW(CaF,N_Mode);

    CaF.Stat.In.Psi_Start    = CaF.Stat.Sol.Psi_k;
%    CaF.Stat.In.Psi_Start(1) = CaF.CW.Sol.Psi(CaF.Stat.Par.CW_num)*CaF.Stat.Space.N;

    CaF           =     Chi_3_Stat_In_Guess_LLE_From_EigenVectors(CaF);
%    CaF.Stat.Stab =                          Stability_Switcher(CaF.Stat);
    
 %%
 
    Plot_Static_Field_Spectrums(CaF.Stat,1);
    
%%
    Plot_Static_Field_Stability(CaF.Stat,1)
