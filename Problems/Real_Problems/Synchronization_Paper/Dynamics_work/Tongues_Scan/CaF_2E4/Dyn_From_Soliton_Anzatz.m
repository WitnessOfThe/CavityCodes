    clc;clear all;
    
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    CaF.Temp.In         = Params_CaF;
    CaF.Temp.In.kappa   =  2E3*2*pi;%2*1E3*2*pi;%
    CaF.Temp.In.P       =  0.29;
    CaF.Temp.In.delta   = -898*CaF.Temp.In.kappa;
    CaF.Temp.In.range   =  300;
    
    CaF.Temp.Met.Ev_Start_Point  = @Chi_3_LLE_Start_Point_Stat;
    
%%

    N_Mode = 2^10;
  
%%
    CaF.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    CaF.Temp.Par.dt            = 0.25E-4;
    CaF.Temp.Par.s_t           = 0.001;
    CaF.Temp.Par.T             = 50;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    CaF.Temp.Par.dd            = CaF.Temp.Par.T/CaF.Temp.Par.s_t;
    CaF.Temp.Par.CW_num        = 3;
    Runge                      = Define_Runge_Coeff(CaF.Temp.Par);
%%
    CaF.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton           = @Newton_Manual_bicgstab;%'fsolve'
     
    CaF.Stat.Par.variable         = 'delta';  %%'Pump Power';
    CaF.Stat.Par.first_step       = 0.25; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.1;

    CaF.Stat.Par.bot_boundary     = -900;
    CaF.Stat.Par.top_boundary     = -870;

    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.Newton_iter      = 30;      
    CaF.Stat.Par.Newton_tol       = 1E-13;  
    CaF.Stat.Par.i_max            = 100;
    CaF.Stat.Par.CW_num          = 3;

%% Specify the tongue number

    mu                  = 60;
%%
    [CaF_1D_Upper,CaF_1D_Lower] = Chi3_Stat_Get_Branch_Turing(CaF,mu,N_Mode);

%%
     CaF.CW.In         = CaF.Temp.In;
     CaF.Temp          = Chi_3_LLE_Normalization(CaF.Temp,N_Mode);
     
     CaF.CW            = CaF.CW.Met.Solve(CaF.CW,CaF.Temp.Space.N);
     CaF.CW.In.g       = CaF.CW.Sol.g(CaF.Temp.Par.CW_num)*CaF.CW.Eq.norm;   
     CaF.CW            = CaF.CW.Met.Mi_Formula(CaF.CW,CaF.Temp.Space.N);   
                    
     CaF.Temp          = Chi_3_LLE_Start_mu_Envelope_Soliton(CaF.CW,CaF.Temp,mu);  
     CaF.Temp.Met      = [];
     
     CaF.Temp.Sol      = Chi_3_LLE_Runge_Kuarong_mex(CaF.Temp,N_Mode,Runge);
          
  
%%
    ind_t  = round(size(CaF.Temp.Sol.Psi,1)/2+1):size(CaF.Temp.Sol.Psi,1);
    if mod(size(ind_t,2),2) == 1
        
        ind_t  = round(size(CaF.Temp.Sol.Psi,1)/2+2):size(CaF.Temp.Sol.Psi,1);
        
    end

    [tt_1,tt_2] = Plot_Dynamics_Result_pcolors(CaF.Temp,1,0);
    [tt_3,tt_4] = Plot_Dynamics_Result_LinePlots_Spectrums(CaF.Temp,0);
    [tt_5,tt_6] = Plot_Dynamics_Rf_pcolor_without_Stat(CaF.CW,CaF.Temp,[min(CaF.Temp.Space.k(CaF.Temp.Eq.mode_range)):max(CaF.Temp.Space.k(CaF.Temp.Eq.mode_range))],ind_t,0);
 %   [p_wh_1,p_wh_2,p_wh_3]    = Plot_LLE_Static_Branch(CaF.CW,CaF_1D_Upper.Stat,CaF_1D_Lower.Stat,0,1,mu,CaF_1D_Upper(1).Stat(Ind));
  %  [p_dot_1,p_dot_2]         = Plot_Static_Field_Spectrums(CaF_1D_Upper(1).Stat(Ind),0);
   % [p_dot_3,p_dot_4,p_dot_5] = Plot_Static_Field_Stability(CaF_1D_Upper(1).Stat(Ind),0,mu);
%    figure;
 %   CF = conFigure([tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,p_wh_1,p_wh_2,p_wh_3,p_dot_1,p_dot_2,p_dot_3,p_dot_4,p_dot_5],4,4, 'UniformPlots', true, 'Height', 20, 'Width', 35,'Labels',false);
    figure;
    CF = conFigure([tt_1,tt_2,tt_3,tt_4,tt_5,tt_6],2,3, 'UniformPlots', true, 'Height', 20, 'Width', 35,'Labels',false);

