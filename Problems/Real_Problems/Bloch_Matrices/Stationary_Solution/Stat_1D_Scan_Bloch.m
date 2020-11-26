%%%%
    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Bloch_Matrices;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Input Parameters for CaF


    N_mode              = 2^5;
    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.P       = 0.0004;
    CaF.Stat.In.delta   = -16.5*CaF.Stat.In.kappa;
    CaF.Stat.In.range   = 2^4;
   
    CaF.CW.In         = CaF.Stat.In;
    

    
%%
    
    CaF.Stat.In.mu_bl   = 10;
    
%% Stationary Coefficeints

    CaF.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    CaF.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton           = @Newton_Manual_bicgstab;%'fsolve'
    
%     CaF.Stat.Par.step_tol         = 0.000001;
%     CaF.Stat.Par.variable         = 'Pump Power';  %%'Pump Power';
%     CaF.Stat.Par.first_step       = 0.01; %min =1E-4/3
%     CaF.Stat.Par.bot_boundary     = 0;
%     CaF.Stat.Par.top_boundary     = 1;
    
 
    CaF.Stat.Par.variable         = 'delta';  %%'Pump Power';
    CaF.Stat.Par.first_step       = 0.5; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.05;
    CaF.Stat.Par.step_inc         = 1;
    CaF.Stat.Par.step_dec         = 0.5;

%%%%%%%%%%%%%%%%%%%%%%

    CaF.Stat.Par.bot_boundary     = -20; % bottom boundary for delta to search
    CaF.Stat.Par.top_boundary     = 150; % top boundary for delta to search

    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.Newton_iter      = 30;      
    CaF.Stat.Par.Newton_tol       = 1E-9;  
    CaF.Stat.Par.i_max            = 2000;
    CaF.Stat.Par.CW_num           = 3;
    
%%

    [CaF_1D_Upper,CaF_1D_Lower] = Chi3_Stat_Get_Branch_Turing(CaF,CaF.Stat.In.mu_bl,N_mode);
    
%%
    ind1 = 94;
    [p_wh_1,p_wh_2,p_wh_3] = Plot_LLE_Bloch_Static_Branch(CaF.CW,CaF_1D_Upper.Stat,CaF_1D_Lower.Stat,0,1,CaF.Stat.In.mu_bl,CaF_1D_Upper(1).Stat(ind1));
    [p_dot_1,p_dot_2]                 = Plot_Static_Field_Spectrums(CaF_1D_Lower(1).Stat(1),0);
     [tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,tt_7,tt_8,tt_9,tt_10,tt_12,tt_13,tt_14,tt_15] = Plot_LLE_Bloch_Static_Field_Stability(CaF_1D_Upper(1).Stat(ind1),0);
    
    figure('Name','Fields_Spectrums');
    
    CF = conFigure([p_wh_1,p_wh_2,p_wh_3,p_dot_1,p_dot_2,tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,tt_7,tt_8,tt_9,tt_10,tt_12,tt_13,tt_14,tt_15],5,4, 'UniformPlots', true, 'Height', 20, 'Width',40,'Labels',false);
    
%%
    
