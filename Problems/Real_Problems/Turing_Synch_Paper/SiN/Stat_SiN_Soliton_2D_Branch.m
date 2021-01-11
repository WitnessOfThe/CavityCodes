    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Turing_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN  

    N_mode              =  2^8;
    SiN.Stat.In         =  Params_SiN_Modes(N_mode);    
    SiN.Stat.In.N_mode  =  N_mode;
    SiN.Stat.In.mu_bl   =  1;
    SiN.Stat.In.kappa   =  125E6*2*pi;
%   SiN.Stat.In.kappa   =  125E6*2*pi;
    SiN.Stat.In.delta   =  3.5*SiN.Stat.In.kappa;
    SiN.Stat.In.P       =  0.0325;       
    
    SiN.CW.In           =  SiN.Stat.In; 
    
%%
    NN = 36;
    
    Power_Start_Vector = linspace(0.03,0.05,NN);     
    Delta_Start_Vector = linspace(8,8,NN)*SiN.Stat.In.kappa;
    
%% Stationary Coefficeints

    SiN.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    SiN.Stat.Met.Stab_Method      =  @LLE_Full_Stability;
    SiN.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    SiN.Stat.Met.Newton           = @fsolve;%'fsolve'
         
    SiN.Stat.Par.variable         = 'delta';  %%'Pump Power';
    SiN.Stat.Par.first_step       = 0.05; % step for delta measured in delta/kappa
    SiN.Stat.Par.step_tol         = 0.01;
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

parfor i =1:NN
    
    Res = SiN;
    
    Res.Stat.In.delta = Delta_Start_Vector(i);
    Res.Stat.In.P     = Power_Start_Vector(i);
    
    Res.Stat         = Chi3_Stat_LLE_Stat_From_Cons_Soliton(Res.Stat);
    SiN_Soliton(i)         = Res;
    SiN_Soliton(i).Stat    = Run_Branch_Universal(Res.Stat);
    
end
%%
full_pic = Plot_LLE_Static_Branch_Soliton_2D(SiN_Soliton);
figure;
full_pic.plotData

  