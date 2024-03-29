%%%%
    clc;
    clear all;
    
%% Define Input Parameters in Physical Units
    
    CaF       =  Set_Up_Methods_For_Bloch_Matrices;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF


    CaF.Stat.In         = Params_CaF;    
    CaF.Stat.In.range   = 2^6;
    CaF.Stat.In.N_mode  = 2^8;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
   
    CaF.Stat.In.delta   = -14*CaF.Stat.In.kappa;
    
%%
    
%    CaF.Stat.In.mu_bl   = 16;
 %   W_WStar             = 650;
  %  CaF.Stat.In.P       = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma;
  % Delta_Start         = [35.54,35.54]*CaF.Stat.In.kappa;%16   
  % Delta_Start         = [-14,-14,16,16]*CaF.Stat.In.kappa;%8
   % Delta_Start         = [-6.3,-6.3,10,13]*CaF.Stat.In.kappa;%7
  %  Delta_Start             = [-6,10.63,12]*CaF.Stat.In.kappa;%6
%    Delta_Start         = [-2,5.5,11.65]*CaF.Stat.In.kappa;%5
 %  Delta_Start         = [3]*CaF.Stat.In.kappa;%4
%%
    CaF.CW.In         = CaF.Stat.In;
    CaF.CW.In.N_mode  = 2^8;

%% Stationary Coefficeints

    CaF.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    CaF.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton           = @fsolve;%'fsolve'
         
    CaF.Stat.Par.variable         = 'delta';  %%'Pump Power';
    CaF.Stat.Par.first_step       = 1; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.01;
    CaF.Stat.Par.step_inc         = 0.01;
    CaF.Stat.Par.step_dec         = 0.8;

    CaF.Stat.Par.bot_boundary     = -40; % bottom boundary for delta to search
    CaF.Stat.Par.top_boundary     = 3000; % top boundary for delta to search

    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.Newton_iter      = 100;      
    CaF.Stat.Par.Newton_tol       = 1E-9;  
    CaF.Stat.Par.i_max            = 4000;
      CaF.Stat.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','iter','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',CaF.Stat.Par.Newton_iter,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);
  
%%
    
    W_WStar             = 500;
    CaF.Stat.In.P       = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma;
    CaF.CW.In.P       = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma;
   CaF.Stat.In.mu_bl   = 8;
   Delta_Start         = [16,16]*CaF.Stat.In.kappa;%8
   Index_Start         = [3,4];    
   [CaF_Branches_8] = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    CaF.Stat.In.mu_bl   = 7;
    Delta_Start         = [-6.3,-6.3,10,13]*CaF.Stat.In.kappa;%8
    Index_Start         = [1,2,3,4];  
    [CaF_Branches_7] = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    CaF.Stat.In.mu_bl   = 6;
    Delta_Start         = [-6.3,-6.3,10,13]*CaF.Stat.In.kappa;%8
    [CaF_Branches_6] = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    CaF.Stat.In.mu_bl   = 5;
    Delta_Start         = [-2,5.5,11.65]*CaF.Stat.In.kappa;
    Index_Start         = [2,3,4];    
    [CaF_Branches_5]    = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    Index_Start         = [3,4];    
    CaF.Stat.In.mu_bl   = 4;
    Delta_Start         = [3,10]*CaF.Stat.In.kappa;
    [CaF_Branches_4] = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
%    CaF_1D_Upper = Chi3_Stat_Get_Single_Branch_Turing(CaF,CaF.Stat.In.mu_bl,N_mode);
 %   CaF_1D_Lower = CaF_1D_Upper;
%%

   [pb_1,pb_2] = Plot_LLE_Bloch_Static_Multiple_Branches(CaF.CW,CaF_Branches(1).Stat(1),CaF_Branches,0);
    Plot_LLE_Bloch_Static_Branch_Stability(CaF.CW,CaF_Branches(3).Stat(1),CaF_Branches(4),1);
   [pf_1,pf_2] =  Plot_Static_Field_Spectrums(CaF_Branches(1).Stat(1),0);
   [pf_3,pf_4] =  Plot_Static_Field_Spectrums(CaF_Branches(2).Stat(1),0);
   [pf_5,pf_6] =  Plot_Static_Field_Spectrums(CaF_Branches(3).Stat(1),0);
   [pf_7,pf_8] =  Plot_Static_Field_Spectrums(CaF_Branches(4).Stat(1),0);
   
   figure('Name','Fields_Spectrums');    
   CF = conFigure([pb_1,pb_2,pf_1,pf_2,pf_3,pf_4,pf_5,pf_6,pf_7,pf_8],5,3, 'UniformPlots', true, 'Height', 25, 'Width',20,'Labels',false);
   
%%
    Plot_LLE_Bloch_Static_Field_Stability(CaF_Branches(1).Stat(end-5),1);
%%
    ind1 = 4;
    [p_wh_1,p_wh_2,p_wh_3]           = Plot_LLE_Bloch_Static_Branch(CaF.CW,CaF_1D_Upper.Stat,CaF_1D_Lower.Stat,0,1,CaF.Stat.In.mu_bl,CaF_1D_Upper(1).Stat(ind1));
    [p_dot_1,p_dot_2]                = Plot_Static_Field_Spectrums(CaF_1D_Lower(1).Stat(1),0);
    [tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,tt_7,tt_8,tt_9,tt_10,tt_12,tt_13,tt_14,tt_15] = Plot_LLE_Bloch_Static_Field_Stability(CaF_1D_Upper(1).Stat(ind1),0);
    
    figure('Name','Fields_Spectrums');
    CF = conFigure([p_wh_1,p_wh_2,p_wh_3,p_dot_1,p_dot_2,tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,tt_7,tt_8,tt_9,tt_10,tt_12,tt_13,tt_14,tt_15],5,4, 'UniformPlots', true, 'Height', 20, 'Width',40,'Labels',false);
    
%%
ind_br = 1;
ind_stat = 200;
figure;
Plot_LLE_Bloch_Static_Branch_Stability(CaF.CW,CaF_Branches_8(ind_br).Stat(ind_stat),CaF_Branches_8(ind_br),1);
%%
ind_stat = 10;
Plot_Static_Field_Spectrums(CaF_Branches_8(ind_br).Stat(ind_stat),1);
Plot_LLE_Bloch_Static_Field_Stability(CaF_Branches_8(ind_br).Stat(ind_stat),1);
%%
Plot_Bloch_Static_Branch_Save_Points(CaF_Branches_8(1),20);
%%
    Path = 'C:\Users\dp710\Documents\Data_Storage\Static\Scan_from_500\mu=8\point_4\';
    Plot_Bloch_Static_Branch_Save_Points(CaF_Branches_8(4),12*4,Path);
    
