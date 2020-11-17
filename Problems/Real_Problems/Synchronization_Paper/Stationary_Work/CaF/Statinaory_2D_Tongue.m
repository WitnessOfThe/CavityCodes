%%%%
    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Input Parameters for CaF


    N_mode              = 2^9;
    
    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.P       = 0.5;
    CaF.Stat.In.delta   = -270*CaF.Stat.In.kappa;   
    CaF.CW.In           = CaF.Stat.In;
    
    N_Power_Res         = 36;

    Power_Lim           = [0.22,0.5];     
    Delta_Lim           = [-288,-263];
    N_Delta_Res         = 150;
%%
    
    mu                  = 34; 
    
%% Stationary Coefficeints

    CaF.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    CaF.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton           = @Newton_Manual_bicgstab;%'fsolve'
         
    CaF.Stat.Par.variable         = 'delta';  %%'Pump Power';
    CaF.Stat.Par.first_step       = 0.1; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.01;
    CaF.Stat.Par.step_inc         = 1;
    CaF.Stat.Par.step_dec         = 0.5;
    
%%%%%%%%%%%%%%%%%%%%%%

    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.Newton_iter      = 30;      
    CaF.Stat.Par.Newton_tol       = 1E-12;  
    CaF.Stat.Par.CW_num           = 3;
    
%%
    [CaF_1D_Upper,CaF_1D_Lower] = Chi3_Stat_Get_Branch_Turing_2D(CaF,mu,N_mode,Power_Lim,Delta_Lim,N_Power_Res,N_Delta_Res);
    
%%
    ind1 = 5;
    ind2 = 141;
    
    [p_wh_1,p_wh_2,p_wh_3]    = Plot_LLE_Static_Branch(CaF.CW,CaF_1D_Upper(ind1).Stat,CaF_1D_Lower(ind1).Stat,0,1,mu,CaF_1D_Upper(ind1).Stat(ind2));
    [p_dot_1,p_dot_2]         = Plot_Static_Field_Spectrums(CaF_1D_Upper(ind1).Stat(ind2),0);
    [p_dot_3,p_dot_4,p_dot_5,p_dot_6] = Plot_Static_Field_Stability(CaF_1D_Upper(ind1).Stat(ind2),0,mu);
    
    figure('Name','Fields_Spectrums');
    
    CF = conFigure([p_wh_1,p_wh_2,p_wh_3,p_dot_1,p_dot_2,p_dot_3,p_dot_4,p_dot_5,p_dot_6],3,4, 'UniformPlots', true, 'Height', 15, 'Width',40,'Labels',false);
    
%%
    Plot_LLE_Static_2D_Scan_Tongue(CaF_1D_Upper,CaF_1D_Lower,mu,1)
