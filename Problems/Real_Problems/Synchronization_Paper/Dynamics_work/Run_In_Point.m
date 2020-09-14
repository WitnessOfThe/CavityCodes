    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN

    N_mode              = 2^8;
    SiN.Temp.In.omega_p = 200E12*2*pi; 
    SiN.Temp.In         = Params_SiN;
    SiN.Temp.In.kappa   =  1E7*2*pi;                 
    SiN.Temp.In.P       = 5;      
    SiN.Temp.In.delta   = -2.3636*2*pi*1E9;
%%
    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 0.01E-2;
    SiN.Temp.Par.s_t           = 0.001;
    SiN.Temp.Par.T             = 500;
    SiN.Temp.Par.CW_num        = 3;
%%
    L_L.Temp.Met.Ev_Start_Point = @Chi_3_LLE_Start_Point_CW;
    tic
    SiN          = Runge_Kuarong(SiN,N_mode);
    toc
%%
 i=1;
    SiN.Temp.Met.Plot.Fields_Spectrums(SiN.Temp)
%%
%    SiN.Temp.Met.Plot.Integrative_Dynamics(SiN.Temp)
%%
    SiN.Temp.Met.Plot.Carpets(SiN.Temp,100)
%%
   Plot_Dynamics_Rf_Spectrums_mu(SiN.Temp,20001:25000)
%%
    Plot_Dynamics_Rf_Spectrums(SiN.Temp,[-15,15],10001:500000)
%% 
i=1;
   Plot_Dynamics_Rf_Spectrums_mu(SiN(i).CW,SiN(i).Temp,10001:500000)
%%
Plot_Dynamics_Repetution_Rate_From_Array(SiN,[6,-6],1001:50000)
