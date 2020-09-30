    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN


    N_mode              = 2^10;
    SiN.Temp.In.omega_p = 200E12*2*pi; 
    SiN.Temp.In         = Params_CaF;
    SiN.Temp.In.kappa   = 2E3*2*pi;                 
    SiN.Temp.In.P       = 0.13;      
    SiN.Temp.In.delta   = -0.6060E6*2*pi;
%%
    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 0.1E-4;
    SiN.Temp.Par.s_t           = 0.01;
    SiN.Temp.Par.T             = 300;
    SiN.Temp.Par.CW_num        = 3;
    SiN.Temp.Par.dd            = SiN.Temp.Par.T/SiN.Temp.Par.s_t;
%%
    SiN.Temp.Met.Ev_Core    = @Chi_3_LLE_Kuar_mex;
    tic
    Runge                      = Define_Runge_Coeff(SiN.Temp.Par);
                SiN.Temp.Met    =                                          [];
      %          tic  
                SiN.Temp        =    Chi_3_LLE_Normalization(SiN.Temp,N_mode);        
                SiN             =               Chi_3_LLE_Start_Point_CW(SiN);    
                SiN(1).Temp.Sol =    Chi_3_LLE_Runge_Kuarong_mex(SiN.Temp,N_mode,Runge);
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
