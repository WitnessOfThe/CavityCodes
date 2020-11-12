    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Turing_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN

    N_Mode              = 2^8;
    SiN.Stat.In         =  Params_SiN_Modes(-1,N_Mode);    
    SiN.Stat.In.kappa   =  100E6*2*pi;
    SiN.Stat.In.delta   =  3.5*SiN.Stat.In.kappa;
    SiN.Stat.In.P       = 0.02;          
    SiN.CW.In           = SiN.Stat.In;
    SiN.Temp.In         = SiN.Stat.In;
    
%%   
%     SiN.Stat.Par.step_tol         = 0.000001;
%    SiN.Stat.Par.variable         = 'Pump Power';  %%'Pump Power';
%     SiN.Stat.Par.first_step       = 0.01; %min =1E-4/3
%     SiN.Stat.Par.bot_boundary     = 0;
%     SiN.Stat.Par.top_boundary     = 1;
   
    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 2E-4;
    SiN.Temp.Par.s_t           = 0.01;
    SiN.Temp.Par.T             = 1;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
    SiN.Temp.Par.dd            = SiN.Temp.Par.T/SiN.Temp.Par.s_t;
    SiN.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(SiN.Temp.Par);

 %%
    SiN.Stat.Par.variable         = 'delta';  %%'Pump Power';
    SiN.Stat.Par.first_step       = 0.02; % step for delta measured in delta/kappa
    SiN.Stat.Par.step_tol         = 0.001;

    SiN.Stat.Par.bot_boundary     = 0;
    SiN.Stat.Par.top_boundary     = 15;
    
    SiN.Stat.Par.Sol_Re_Sign      = '-';
    SiN.Stat.Par.Stability        = 'Yes';
    SiN.Stat.Par.Newton_iter      = 30;      
    SiN.Stat.Par.Newton_tol       = 1E-10;  
    SiN.Stat.Par.i_max            = 500;
    SiN.Stat.Par.CW_num           = 3;
    SiN.Stat.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg'...
 ,'FunctionTolerance',SiN.Stat.Par.Newton_tol,...
     'MaxIterations',SiN.Stat.Par.Newton_iter,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);
%%

    SiN.Stat         = Chi3_Stat_LLE_Stat_From_Cons_Soliton(SiN.Stat,N_Mode);
    SiN.Stat         = Chi3_Stat_LLE_Stat_From_Cons_Soliton(SiN.Stat,N_Mode);
    SiN.Stat.Stab =                       Stability_Switcher(SiN.Stat(1));
    
%    Plot_Static_Field_Spectrums(SiN.Stat,1);
 %   Plot_Static_Field_Stability(SiN.Stat,1);
    
%%    -4.8268

    SiN_Soliton_Branch_Up.Stat  = Run_Branch_Universal(SiN.Stat,N_Mode);
    SiN.Stat.Par.Sol_Re_Sign      = '+';
    SiN.Stat         = Chi3_Stat_LLE_Stat_From_Cons_Soliton(SiN.Stat,N_Mode);
    SiN_Soliton_Branch_Down.Stat = Run_Branch_Universal(SiN.Stat,N_Mode);  
    
%%

    
%%
  Path = strcat('C:/Users/dp710/Documents/Data_Storage/SiN_Soliton','_',num2str(SiN.Stat(1).In.D(2)/SiN.Stat(1).In.kappa),'_Upper_Branch_Scan_',SiN.Stat.Par.variable ,'_Start_delta=',num2str(SiN.Stat(1).In.delta/SiN.Stat(1).In.kappa),'_Power=',num2str(SiN.Stat(1).In.P));
  %delete(gcp('nocreate'));
  %parpool(12);
  
  for i = 1:size(SiN_Soliton_Branch_Up.Stat,2)
      
      Res = SiN;
      Res.Stat = SiN_Soliton_Branch_Up.Stat(i);
      Chi_3_LLE_Assynch_Paralell_exec_Sol(Res,Res.Stat.In.delta,Res.Stat.In.P,i,Path,1,N_Mode,Runge,SiN_Soliton_Branch_Up,SiN_Soliton_Branch_Down,50)
          
  end
  
%%
