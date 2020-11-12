    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF


    N_mode              = 2^11;
    SiN.Stat.In         = Params_SiN;
    SiN.Stat.In.kappa   = 100E6*2*pi;                 
    SiN.Stat.In.P       = 2;
    SiN.Stat.In.delta   = 16.25*SiN.Stat.In.kappa;
    mu                  = 69;
    SiN.Temp.In         = SiN.Stat.In;
    
%% Stationary Coefficeints

    SiN.Stat.Par.i_max                = 2000;
    SiN.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    
    SiN.Stat.Met.InitialGuess         = @Stat_In_Guess_Chi_3_LLE_From_Dyn;    
    SiN.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'
    
    SiN.Stat.Par.step_tol             = 1E-10;
    SiN.Stat.Par.Stability            = 'No';
    SiN.Stat.Par.variable             = 'delta';  
    SiN.Stat.Par.first_step           = 1; %min =1E-4/3
    SiN.Stat.Par.Newton_iter          = 30;      
    SiN.Stat.Par.Newton_tol           = 1E-10;  
    SiN.Stat.Par.i_max                = 200;
    SiN.Stat.Par.CW_num               = 3;
    
%% Temporal Coefficients
    
 %   CaF = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW(CaF,N_mode);
    SiN = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW_Defined(SiN,N_mode,[ mu ,- mu]);

%    SiN.Stat(1).Stab =    Stability_Switcher(SiN.Stat(1));
 %   SiN.Stat(2).Stab =    Stability_Switcher(SiN.Stat(2));
    
 %%
%    Plot_Static_Field_Spectrums(SiN.Stat(1),2);

    Plot_Static_Field_Spectrums(SiN.Stat(1),2);
    Plot_Static_Field_Spectrums(SiN.Stat(2),2);
    Plot_Static_Field_Spectrums(SiN.Stat(3),2);
    Plot_Static_Field_Spectrums(SiN.Stat(4),2);
    
%%
    Plot_Static_Field_Stability(SiN.Stat(2),1)
