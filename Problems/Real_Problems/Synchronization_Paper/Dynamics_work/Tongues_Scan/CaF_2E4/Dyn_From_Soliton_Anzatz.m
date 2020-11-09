    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   =  2E3*2*pi;%2*1E3*2*pi;%
    CaF.Stat.In.P       = 0.35;
    CaF.Stat.In.delta   = -895*CaF.Stat.In.kappa;
    CaF.Stat.In.range   =  300;
    CaF.Temp            = CaF.Stat;
    CaF.Temp.Met.Ev_Start_Point  = @Chi_3_LLE_Start_Point_Stat;
    
%%

    N_Mode = 2^10;
  
%%
    CaF.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    CaF.Temp.Par.dt            = 0.25E-4;
    CaF.Temp.Par.s_t           = 0.01;
    CaF.Temp.Par.T             = 200;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    CaF.Temp.Par.dd            = CaF.Temp.Par.T/CaF.Temp.Par.s_t;
    CaF.Temp.Par.CW_num        = 3;
    Runge                      = Define_Runge_Coeff(CaF.Temp.Par);
    
%% Specify the tongue number
    mu                  = 60; 
       
%%
     CaF.CW.In         = CaF.Temp.In;
     CaF.CW            = CaF.CW.Met.Solve(CaF.CW,CaF.Temp.Space.N);
     CaF.CW.In.g       = CaF.CW.Sol.g(CaF.Temp.Par.CW_num)*CaF.CW.Eq.norm;   
     CaF.CW            = CaF.CW.Met.Mi_Formula(CaF.CW,CaF.Temp.Space.N);   
                    
     CaF             =   CaF.Temp.Met.Ev_Start_Point(Res);  
     CaF(1).Temp.Sol =   Chi_3_LLE_Runge_Kuarong_mex(CaF.Temp,N_Mode,Runge);
          
  
%%
    [tt_1,tt_2] = Plot_Dynamics_Result_pcolors(CaF.Temp,1,0);
    [tt_3,tt_4] = Plot_Dynamics_Result_LinePlots_Spectrums(CaF.Temp,0);
    [tt_5,tt_6] = Plot_Dynamics_Rf_pcolor(CaF.CW,CaF.Stat,CaF.Temp,[min(CaF.Temp.Space.k(CaF.Temp.Eq.mode_range)):max(CaF.Temp.Space.k(CaF.Temp.Eq.mode_range))],ind_t,0);
    [p_wh_1,p_wh_2,p_wh_3]    = Plot_LLE_Static_Branch(CaF.CW,CaF_1D_Upper.Stat,CaF_1D_Lower.Stat,0,1,mu,CaF_1D_Upper(1).Stat(Ind));
    [p_dot_1,p_dot_2]         = Plot_Static_Field_Spectrums(CaF_1D_Upper(1).Stat(Ind),0);
    [p_dot_3,p_dot_4,p_dot_5] = Plot_Static_Field_Stability(CaF_1D_Upper(1).Stat(Ind),0,mu);
    figure;
    CF = conFigure([tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,p_wh_1,p_wh_2,p_wh_3,p_dot_1,p_dot_2,p_dot_3,p_dot_4,p_dot_5],4,4, 'UniformPlots', true, 'Height', 20, 'Width', 35,'Labels',false);

