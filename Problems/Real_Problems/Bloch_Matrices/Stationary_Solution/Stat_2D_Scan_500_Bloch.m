%%%%
    clc;
    clear all;
    
%% Define Input Parameters in Physical Units
    
    CaF       =  Set_Up_Methods_For_Bloch_Matrices;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF


    CaF.Stat.In         = Params_CaF;    
    CaF.Stat.In.range   = 2^6;
    CaF.Stat.In.N_mode  = 2^7;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
   
    CaF.Stat.In.delta   = 70*CaF.Stat.In.kappa;
    
    
    N_Power_Res         = 36*4;
    W_WStar             = 500;
    Power_Lim           = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma;     
    Delta_Lim           = [-7.5,-7.5,12.81,12.81];
    N_Delta_Res         = 150;
    
%%
    
     CaF.Stat.In.mu_bl   = 7;
    
%% Stationary Coefficeints

    CaF.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    CaF.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton           = @Newton_Manual_bicgstab;%'fsolve'
         
    CaF.Stat.Par.variable         = 'delta';  %%'Pump Power';
    CaF.Stat.Par.first_step       = 0.1; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.025;
    CaF.Stat.Par.step_inc         = 1;
    CaF.Stat.Par.step_dec         = 0.5;
    
%%%%%%%%%%%%%%%%%%%%%%

    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.Newton_iter      = 30;      
    CaF.Stat.Par.Newton_tol       = 1E-12;  
    CaF.Stat.Par.CW_num           = 3;
    
%%

    
    CaF_2D_Upper        = Chi3_Stat_Get_Upper_Branch_Turing_2D(CaF,CaF.Stat.In.mu_bl,N_mode,Power_Lim,Delta_Lim,N_Power_Res,N_Delta_Res,Index);
    
%%
    ind1 = 5;
    ind2 = 21;
    
    [p_wh_1,p_wh_2,p_wh_3]            = Plot_LLE_Static_Branch(CaF.CW,CaF_1D_Upper(ind1).Stat,CaF_1D_Lower(ind1).Stat,0,1,mu,CaF_1D_Upper(ind1).Stat(ind2));
    [p_dot_1,p_dot_2]                 = Plot_Static_Field_Spectrums(CaF_1D_Upper(ind1).Stat(ind2),0);
    [p_dot_3,p_dot_4,p_dot_5,p_dot_6] = Plot_Static_Field_Stability(CaF_1D_Upper(ind1).Stat(ind2),0,mu);
    
    figure('Name','Fields_Spectrums');
    CF = conFigure([p_wh_1,p_wh_2,p_wh_3,p_dot_1,p_dot_2,p_dot_3,p_dot_4,p_dot_5,p_dot_6],3,4, 'UniformPlots', true, 'Height', 15, 'Width',40,'Labels',false);
    
%%
    Plot_LLE_Bloch_Static_2D_Scan_Upper_Tongue(CaF,CaF_1D_Upper,CaF.Stat.In.mu_bl,1)
