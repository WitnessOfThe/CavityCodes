%%%%
    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Turing_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN

    N_mode              = 2^9;
    
    SiN.Stat.In         =  Params_SiN_Modes(-1,N_mode);        
    SiN.Stat.In.kappa   =  100E6*2*pi;
    SiN.Stat.In.delta   =  2.34*SiN.Stat.In.kappa;
    SiN.Stat.In.P       =  0.022;         
    SiN.CW.In           =  SiN.Stat.In;
    SiN.Temp.In         =  SiN.Stat.In;     
    
%%
    
    mu                  = 44; 
    
%% Stationary Coefficeints

    SiN.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    SiN.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    SiN.Stat.Met.Newton           = @Newton_Manual_bicgstab;%'fsolve'
    
%     CaF.Stat.Par.step_tol         = 0.000001;
%     CaF.Stat.Par.variable         = 'Pump Power';  %%'Pump Power';
%     CaF.Stat.Par.first_step       = 0.01; %min =1E-4/3
%     CaF.Stat.Par.bot_boundary     = 0;
%     CaF.Stat.Par.top_boundary     = 1;
    
 
    SiN.Stat.Par.variable         = 'delta';  %%'Pump Power';
    SiN.Stat.Par.first_step       = 0.01; % step for delta measured in delta/kappa
    SiN.Stat.Par.step_tol         = 0.001;
    
%%%%%%%%%%%%%%%%%%%%%%

    SiN.Stat.Par.bot_boundary     = -900; % bottom boundary for delta to search
    SiN.Stat.Par.top_boundary     = 50; % top boundary for delta to search

    SiN.Stat.Par.Stability        = 'Yes';
    SiN.Stat.Par.Newton_iter      = 30;      
    SiN.Stat.Par.Newton_tol       = 1E-12;  
    SiN.Stat.Par.i_max            = 100;
    SiN.Stat.Par.CW_num           = 3;
    
%%

    [CaF_1D_Upper,CaF_1D_Lower]   = Chi3_Stat_Get_Branch_Turing_SiN_FD_02(SiN,mu,N_mode);
    
%%
    ind1 = 1;
    
    [p_wh_1,p_wh_2,p_wh_3]      = Plot_LLE_Static_Branch(SiN.CW,CaF_1D_Upper.Stat,CaF_1D_Lower.Stat,0,1,mu,CaF_1D_Upper(1).Stat(ind1));
    [p_dot_1,p_dot_2]           = Plot_Static_Field_Spectrums(CaF_1D_Upper(1).Stat(ind1),0);
    [p_dot_3,p_dot_4,p_dot_5]   = Plot_Static_Field_Stability(CaF_1D_Upper(1).Stat(ind1),0,mu);
    
    figure('Name','Fields_Spectrums');
    
    CF = conFigure([p_wh_1,p_wh_2,p_wh_3,p_dot_1,p_dot_2,p_dot_3,p_dot_4,p_dot_5],2,4, 'UniformPlots', true, 'Height', 15, 'Width',40,'Labels',false);
    
%%
    
