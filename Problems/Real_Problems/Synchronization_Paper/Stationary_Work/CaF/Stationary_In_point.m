    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF


    N_mode              = 2^10;
    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.P       = 0.4;
    CaF.Stat.In.delta   = -0.595E6*2*pi;
    
    CaF.Temp.In         = CaF.Stat.In;
%% Stationary Coefficeints

    CaF.Stat.Par.i_max                = 2000;
    CaF.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    
    CaF.Stat.Met.InitialGuess         = @Stat_In_Guess_Chi_3_LLE_From_Dyn;    
    CaF.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'
    
    CaF.Stat.Par.step_tol             = 1E-10;
    CaF.Stat.Par.Stability            = 'No';
    CaF.Stat.Par.variable             = 'delta';  
    CaF.Stat.Par.first_step           = 1; %min =1E-4/3
    CaF.Stat.Par.Newton_iter          = 50;      
    CaF.Stat.Par.Newton_tol           = 1E-9;  
    CaF.Stat.Par.i_max                = 200;
    CaF.Stat.Par.CW_num               = 3;
%% Temporal Coefficients

    CaF.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    CaF.Temp.Par.dt            = (1E-10)*CaF.Temp.Eq.norm;
    CaF.Temp.Par.s_t           = (1E-8)*CaF.Temp.Eq.norm; % time normalized by norm ceoff
    CaF.Temp.Par.T             = (1E-3)*CaF.Temp.Eq.norm; %% time normalized by norm ceoff
    CaF.Temp.Par.CW_num        = 3;
    CaF.Temp.Par.dd            = CaF.Temp.Par.T/CaF.Temp.Par.s_t;
    
%%
    Runge                      = Define_Runge_Coeff(CaF.Temp.Par);
    
    CaF.Temp        =          Chi_3_LLE_Normalization(CaF.Temp,N_mode);        
    CaF             =                     Chi_3_LLE_Start_Point_CW(CaF);    
    CaF(1).Temp.Sol =    Chi_3_LLE_Runge_Kuarong(CaF.Temp,N_mode,Runge);
    
    CaF = Stat_In_Guess_Chi_3_LLE_From_Dyn(CaF,N_mode);

 %% Plot Results Of Dynamics
    Plot_Dynamics_Result_LinePlots_Spectrums(CaF.Temp,1)
    CaF.Temp.Met.Plot.Carpets(CaF.Temp,1,1);
    %
    Plot_Dynamics_Rf_pcolor(CaF.CW,CaF.Temp,[-50,50],301:1000,1)
%% Plot Results of Stationary
    Plot_Static_Field_Spectrums(CaF.Stat,1)
