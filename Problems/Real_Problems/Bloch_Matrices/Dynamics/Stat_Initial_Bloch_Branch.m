    clc;
    clear all;
    
%% Define Input Parameters in Physical Units
    
    CaF       =  Set_Up_Methods_For_Bloch_Matrices;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF


    CaF.Stat.In         = Params_CaF;    
    CaF.Stat.In.range   = 2^8;
    CaF.Stat.In.N_mode  = 2^8;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.delta   = 70*CaF.Stat.In.kappa;
    
 
    CaF.CW.In         = CaF.Stat.In;
    CaF.Temp.In         = CaF.Stat.In;
    CaF.CW.In.N_mode  = 2^8;
    CaF.Temp.In.N_mode  = 2^9;
  
%%
    CaF.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    CaF.Temp.Par.dt            = 0.25E-4;
    CaF.Temp.Par.s_t           = 0.01;
    CaF.Temp.Par.T             = 1000;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    CaF.Temp.Par.dd            = CaF.Temp.Par.T/CaF.Temp.Par.s_t;
    CaF.Temp.Par.CW_num        = 3;
    Runge                      = Define_Runge_Coeff(CaF.Temp.Par);
    
    
%% Stationary Coefficeints

    CaF.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    CaF.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton           = @fsolve;%'fsolve'
         
    CaF.Stat.Par.variable         = 'delta';  %%'Pump Power';
    CaF.Stat.Par.first_step       = 0.2; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.001;
    CaF.Stat.Par.step_inc         = 0.00;
    CaF.Stat.Par.step_dec         = 0.5;

    CaF.Stat.Par.bot_boundary     = -40; % bottom boundary for delta to search
    CaF.Stat.Par.top_boundary     =  602; % top boundary for delta to search

    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.Newton_iter          = 30;      
    CaF.Stat.Par.Newton_tol           = 1E-10;  
    CaF.Stat.Par.i_max                = 1000;
    
    CaF.Stat.Par.fsolveoptions       = optimoptions('fsolve','CheckGradients',...
    false,'Display','iter','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);

%%    -4.8268x
   W_WStar             = 25;%25;
  
   CaF.Stat.In.P       = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma;
   CaF.CW.In.P         = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma; 
   CaF.Temp.In.P       = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma; 
%    CaF.Stat.In.mu_bl   = 4;    
%    Index_Start         = [1,3];%1,
%    Delta_Start         = [1.63,4.3]*CaF.Stat.In.kappa;%9.7,   
%    CaF_Branches_4        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
%%    
    CaF.Stat.In.mu_bl   = 3;    
    Index_Start         = [5];%1,
    Delta_Start         = [2]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches_3        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);

%%    
%    CaF.Stat.Par.first_step       = 0.01; % step for delta measured in delta/kappa
 %   CaF.Stat.Par.step_tol         = 0.001;
% 
%    CaF.Stat.In.mu_bl   = 2;
%    Index_Start         = [3,4,6,7];%1,
%     Delta_Start         = [3.4,3.4,5,4.4]*CaF.Stat.In.kappa;%9.7,   
%     CaF_Branches_2        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
%     
%     CaF.Stat.Par.first_step       = 0.1; % step for delta measured in delta/kappa
%     CaF.Stat.Par.step_tol         = 0.001;
%     Index_Start         = [5];%1,
%     Delta_Start         = [4.4]*CaF.Stat.In.kappa;%9.7,   
%     CaF_Branches_2(end+1)        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
%     
% 
% %%
%     CaF.Stat.In.mu_bl   = 1;    
%     Index_Start         = [1,2,3,4,5,6,7];%1,
%     Delta_Start         = [1.9,1.5,1.4,2.1,1.81,1.38,1.9]*CaF.Stat.In.kappa;%9.7,   
%     CaF_Branches        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
%     
% %%

    
%%
  Path = strcat('C:/Users/dp710/Documents/Data_Storage/From_bloch/CaF_mu=',num2str(CaF.Stat(1).In.mu_bl),'_',num2str(CaF.Stat(1).In.D(2)/CaF.Stat(1).In.kappa),'_Upper_Branch_Scan_',CaF.Stat.Par.variable ,'_Start_delta=',num2str(CaF.Stat(1).In.delta/CaF.Stat(1).In.kappa),'_Power=',num2str(W_WStar));
  delete(gcp('nocreate'));
  parpool();
  Indexes = fliplr(1:3:153);
  parfor Ind = 1:size(Indexes,2)
      
      i = Indexes(Ind);
      Res = CaF;
      Res.Stat = CaF_Branches_3(1).Stat(i);
      Chi_3_LLE_Assynch_Paralell_exec(Res,Res.Stat.In.delta,Res.Stat.In.P,i,Path,1,Res.Temp.In.N_mode,Runge,CaF_Branches_3,CaF_Branches_3,CaF.Stat(1).In.mu_bl)
          
  end
  
%%
