    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   =  2E3*2*pi;%2*1E3*2*pi;%
    CaF.Stat.In.P       = 0.00024;
    CaF.Stat.In.delta   = -CaF.Stat.In.kappa*23;
    
    CaF.Temp          = CaF.Stat;
    CaF.Temp.Met.Ev_Start_Point  = @Chi_3_LLE_Start_Point_Stat;
    
%%

  N      = 200;   
  N_Mode = 2^8;
  
  
%%
    CaF.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    CaF.Temp.Par.dt            = 5E-4;
    CaF.Temp.Par.s_t           = 0.01;
    CaF.Temp.Par.T             = 500;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    CaF.Temp.Par.dd            = CaF.Temp.Par.T/CaF.Temp.Par.s_t;
    CaF.Temp.Par.CW_num        = 3;
    Runge                      = Define_Runge_Coeff(CaF.Temp.Par);
    
%% Specify the tongue number
    mu                  = 10; 
    
%% Stationary Coefficeints

F.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton           = @Newton_Manual_bicgstab;%'fsolve'
    
%     CaF.Stat.Par.step_tol         = 0.000001;
%     CaF.Stat.Par.variable         = 'Pump Power';  %%'Pump Power';
%     CaF.Stat.Par.first_step       = 0.01; %min =1E-4/3
%     CaF.Stat.Par.bot_boundary     = 0;
%     CaF.Stat.Par.top_boundary     = 1;
    
 
    CaF.Stat.Par.variable         = 'delta';  %%'Pump Power';
    CaF.Stat.Par.first_step       = 0.05; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.01;

    CaF.Stat.Par.bot_boundary     = -30;
    CaF.Stat.Par.top_boundary     = 0;

    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.Newton_iter      = 30;      
    CaF.Stat.Par.Newton_tol       = 1E-13;  
    CaF.Stat.Par.i_max            = 500;
    CaF.Stat.Par.CW_num          = 3;
    
%%    -4.8268x

    [CaF_1D_Upper,CaF_1D_Lower] = Chi3_Stat_Get_Branch_Turing(CaF,mu,N_Mode);
    
%%

    
%%
  Path = strcat('/home/dp710/Data_Storage/From_Stationary/CaF_mu=',num2str(mu),'_',num2str(CaF.Stat(1).In.D(2)/CaF.Stat(1).In.kappa),'_Upper_Branch_Scan_',CaF.Stat.Par.variable ,'_Start_delta=',num2str(CaF.Stat(1).In.delta/CaF.Stat(1).In.kappa),'_Power=',num2str(CaF.Stat(1).In.P));
  delete(gcp('nocreate'))
  parpool(50);
  parfor i = 1:size(CaF_1D_Upper.Stat,2)
      
      Res = CaF;
      Res.Stat = CaF_1D_Upper.Stat(i);
      Chi_3_LLE_Assynch_Paralell_exec(Res,Res.Stat.In.delta,Res.Stat.In.P,i,Path,1,N_Mode,Runge,CaF_1D_Upper,CaF_1D_Lower,mu)
          
  end
%%
%   Path = strcat('/home/dp710/Data_Storage/From_Stationary/CaF_',num2str(CaF.Stat(1).In.D(2)/CaF.Stat(1).In.kappa),'_Lower_Branch_Scan_',CaF.Stat.Par.variable ,'_Start_delta=',num2str(CaF.Stat(1).In.delta/CaF.Stat(1).In.kappa),'_Power=',num2str(CaF.Stat(1).In.P));
 
%   parfor i = 1:size(CaF_1D_Lower.Stat,2)
%       
%       Res = CaF;
%       Res.Stat = CaF_1D_Lower.Stat(i);
%       Chi_3_LLE_Assynch_Paralell_exec(Res,Res.Stat.In.delta,Res.Stat.In.P,i,Path,1,N_Mode,Runge,CaF_1D_Upper,CaF_1D_Lower,mu)
%           
%   end
