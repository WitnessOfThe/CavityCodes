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
    CaF.Stat.In.P       = 0.05;
    CaF.Stat.In.delta   = -290.5*CaF.Stat.In.kappa;
    CaF.Stat.In.range   = 2^3;
   
    CaF.CW.In         = CaF.Stat.In;
    

    
%%
    
    CaF.Stat.In.mu_bl   = 35;
    
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
    CaF.Stat.Par.first_step       = 0.2; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.05;
    CaF.Stat.Par.step_inc         = 1;
    CaF.Stat.Par.step_dec         = 0.5;

%%%%%%%%%%%%%%%%%%%%%%

    CaF.Stat.Par.bot_boundary     = -305; % bottom boundary for delta to search
    CaF.Stat.Par.top_boundary     = -285; % top boundary for delta to search

    CaF.Stat.Par.Stability        = 'No';
    CaF.Stat.Par.Newton_iter      = 30;      
    CaF.Stat.Par.Newton_tol       = 1E-12;  
    CaF.Stat.Par.i_max            = 2000;
    CaF.Stat.Par.CW_num           = 3;
    
%%

    [CaF_1D_Upper,CaF_1D_Lower] = Chi3_Bloch_Stat_Get_Branch_Turing(CaF,    CaF.Stat.In.mu_bl,N_mode);
    
%%
    ind1 = 50;
    Plot_LLE_Bloch_Static_Branch(CaF.CW,CaF_1D_Upper.Stat,CaF_1D_Lower.Stat,1,1,CaF.Stat.In.mu_bl,CaF_1D_Upper(1).Stat(ind1));
    [p_dot_1,p_dot_2]                 = Plot_Static_Field_Spectrums(CaF_1D_Upper(1).Stat(ind1),0);
   % [p_dot_3,p_dot_4,p_dot_5,p_dot_6] = Plot_Static_Field_Stability(CaF_1D_Upper(1).Stat(ind1),0,mu);
    
    %figure('Name','Fields_Spectrums');
    
  %  CF = conFigure([p_wh_1,p_wh_2,p_wh_3,p_dot_1,p_dot_2,p_dot_3,p_dot_4,p_dot_5,p_dot_6],3,4, 'UniformPlots', true, 'Height', 25, 'Width',40,'Labels',false);
    
%%
    
