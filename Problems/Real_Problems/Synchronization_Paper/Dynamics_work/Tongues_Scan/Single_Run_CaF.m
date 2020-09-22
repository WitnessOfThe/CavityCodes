    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN

    N_mode              = 2^10;
    
    CaF.Temp.In         = Params_CaF;
    CaF.Temp.In.kappa   =   1E3*2*pi;                 
    CaF.Temp.In.P       =           0.09;      
    CaF.Temp.In.delta   = -0.6086*2*pi*1E6;
    
%%
    CaF.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    CaF.Temp.Par.dt            = 1E-4;
    CaF.Temp.Par.s_t           = 0.01;
    CaF.Temp.Par.T             = 1000;
    CaF.Temp.Par.CW_num        = 3;
    CaF.Temp.Par.dd            = CaF.Temp.Par.T/CaF.Temp.Par.s_t;
    Runge                      = Define_Runge_Coeff(CaF.Temp.Par);
    tt                         = CaF.Temp.Met; 
%%
    tic
    CaF.Temp     =    Chi_3_LLE_Normalization(CaF.Temp,N_mode);        
    CaF          =    Chi_3_LLE_Start_Point_CW(CaF);    
    CaF.Temp.Met = [];
    CaF(1).Temp.Sol     =    Chi_3_LLE_Runge_Kuarong(CaF.Temp,N_mode,Runge);
    toc
    CaF.Temp.Met = tt;
%%
    i = 1
    
    
   CaF(i).Temp.Met.Plot.Fields_Spectrums(CaF(i).Temp,1)
   CaF(i).Temp.Met.Plot.Carpets(CaF(i).Temp,1,1)
   Plot_Dynamics_Rf_Spectrums(CaF(i).Temp,[5,-5],25001:40000)
   %%
   i = 1
%%   
   Plot_Dynamics_Rf_Spectrums_mu_pcolor(CaF(i).CW,CaF(i).Temp,5001:50000,[-50:50],[-35,35])
%%
   Plot_Dynamics_Rf_Spectrums_mu(CaF.Temp,20001:25000)
%%
    Plot_Dynamics_Rf_Spectrums(CaF.Temp,[-15,15],10001:500000)
%% 
i=1;
   Plot_Dynamics_Rf_Spectrums_mu(CaF(i).CW,CaF(i).Temp,10001:500000)
%%
Plot_Dynamics_Repetution_Rate_From_Array(CaF,[6,-6],1001:50000)
