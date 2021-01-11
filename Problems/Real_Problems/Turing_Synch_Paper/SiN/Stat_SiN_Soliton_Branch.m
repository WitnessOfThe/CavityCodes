    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Turing_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN  

    N_mode              =  2^8;
    SiN.Stat.In         =  Params_SiN_Modes(0, N_mode);    
    SiN.Stat.In.N_mode  =  N_mode;
    SiN.Stat.In.mu_bl   =  1;
    SiN.Stat.In.kappa   =  125E6*2*pi;
    SiN.Stat.In.delta   =  3.5*SiN.Stat.In.kappa;
    SiN.Stat.In.P       =  0.0325;       
    
    SiN.CW.In           =  SiN.Stat.In;

%% Stationary Coefficeints

    SiN.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    SiN.Stat.Met.Stab_Method      =  @LLE_Full_Stability;
    SiN.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    SiN.Stat.Met.Newton           = @fsolve;%'fsolve'
         
    SiN.Stat.Par.variable         = 'delta';  %%'Pump Power';
    SiN.Stat.Par.first_step       = 0.05; % step for delta measured in delta/kappa
    SiN.Stat.Par.step_tol         = 0.001;
    SiN.Stat.Par.step_inc         = 0.00;
    SiN.Stat.Par.step_dec         = 0.5;

    SiN.Stat.Par.bot_boundary     = -40; % bottom boundary for delta to search
    SiN.Stat.Par.top_boundary     =  602; % top boundary for delta to search
    SiN.Stat.Par.Sol_Re_Sign      = '-';
    SiN.Stat.Par.Stability        = 'Yes';
    SiN.Stat.Par.Newton_iter          = 30;      
    SiN.Stat.Par.Newton_tol           = 1E-10;  
    SiN.Stat.Par.i_max                = 1000;
    
    SiN.Stat.Par.fsolveoptions       = optimoptions('fsolve','CheckGradients',...
    false,'Display','iter','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);
 
%%

    SiN.Stat         = Chi3_Stat_LLE_Stat_From_Cons_Soliton(SiN.Stat);
    SiN.Stat.Stab    = Stability_Switcher(SiN.Stat(1));
    SiN_Soliton_Branch_Up.Stat    = Run_Branch_Universal(SiN.Stat);
        
%%    -4.8268

    SiN.Stat.Par.Sol_Re_Sign      = '+';
    SiN.Stat                      = Chi3_Stat_LLE_Stat_From_Cons_Soliton(SiN.Stat);
    SiN_Soliton_Branch_Down       = SiN_Soliton_Branch_Up;  
    
%%
    ind1 = 3;
    [p_wh_1,p_wh_2,p_wh_3,p_wh_4]      = Plot_LLE_Static_Branch_Soliton(SiN.CW,SiN_Soliton_Branch_Up.Stat,SiN_Soliton_Branch_Down.Stat,0,1,0,SiN_Soliton_Branch_Up(1).Stat(ind1));
    [p_1,p_2,p_3]                      = Plot_Static_Field_Spectrums_Soliton(SiN_Soliton_Branch_Up.Stat(ind1),0);
    [p_dot_3,p_dot_4,p_dot_5,p_dot_6]  = Plot_Static_Field_Stability_Soliton(SiN_Soliton_Branch_Up.Stat(ind1),0);
    
    figure('Name','Fields_Spectrums')   ;    
    CF = conFigure([p_wh_1,p_wh_2,p_wh_3,p_wh_4,p_1,p_2,p_3,p_dot_3,p_dot_4,p_dot_5,p_dot_6],2,6, 'UniformPlots', true, 'Height', 15, 'Width',40,'Labels',false);

%%    
    ind1 = 1;
    [p_wh_1,p_wh_2,p_wh_3]    = Plot_LLE_Static_Branch_Soliton(SiN.CW,SiN_Soliton_Branch.Stat,SiN_Soliton_Branch.Stat,0,1,0,SiN_Soliton_Branch(1).Stat(ind1));
    [p_dot_1,p_dot_2]         = Plot_Static_Field_Spectrums(SiN_Soliton_Branch(1).Stat(ind1),0);
    [p_dot_3,p_dot_4,p_dot_5] = Plot_Static_Field_Stability(SiN_Soliton_Branch(1).Stat(ind1),0,1);
    
    figure('Name','Fields_Spectrums');
    
    CF = conFigure([p_wh_1,p_wh_2,p_wh_3,p_dot_1,p_dot_2,p_dot_3,p_dot_4,p_dot_5],2,4, 'UniformPlots', true, 'Height', 15, 'Width',40,'Labels',false);

% 
%%
    Plot_Static_Field_Spectrums(SiN_Soliton_Branch.Stat(101),1);
%%
    Plot_Static_Field_Stability(SiN_Soliton_Branch.Stat(101),1);
