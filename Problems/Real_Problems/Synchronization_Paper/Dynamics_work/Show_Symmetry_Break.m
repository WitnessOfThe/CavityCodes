    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN

    N_mode              = 2^8;
    SiN.Temp.In.omega_p = 220E12*2*pi; 
    SiN.Temp.In         = Params_SiN;
    SiN.Temp.In.kappa   =  1E7*2*pi;                 
    SiN.Temp.In.P       = 1.3;      
    SiN.Temp.In.delta = -5.9052e+08*2*pi;

%%
    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 0.01E-2;
    SiN.Temp.Par.s_t           = 0.001;
    SiN.Temp.Par.T             = 500;
    SiN.Temp.Par.CW_num        = 3;
%%
    SiN.Temp.Met.Ev_Start_Point = @Chi_3_LLE_Start_Point_CW;
    SiN(2)                      = SiN(1);
    SiN(2).Temp.Met.Ev_Start_Point = @Chi_3_LLE_Start_Point_CW_Reversed_Phase;Plot_Dynamics_Rf_Spectrums_mu_pcolor(SiN(i).CW,SiN(i).Temp,100001:500000,[-15:15])

    NN = 30;
        
        
    tic
    parfor i =1:2
        SiN(i)          = Runge_Kuarong(SiN(i),N_mode);
        i
    endPlot_Dynamics_Rf_Spectrums_mu_pcolor(SiN(i).CW,SiN(i).Temp,100001:500000,[-15:15])
    end
    toc
%%
%%
    %%
    i = 1
    SiN(i).Temp.Met.Plot.Fields_Spectrums(SiN(i).Temp)
   SiN(i).Temp.Met.Plot.Carpets(SiN(i).Temp,10)
   %%
   i=2;
   SiN(i).Temp.Met.Plot.Integrative_Dynamics(SiN(i).Temp,80001:500000)
   %%
   i = 2
      Plot_Dynamics_Rf_Spectrums(SiN(i).Temp,[-5,5],70001:500000)
%%   
   Plot_Dynamics_Rf_Spectrums_mu(SiN(i).CW,SiN(i).Temp,60001:500000)
%%
   Plot_Dynamics_Repetution_Rate_From_Array(SiN,[5,-5],5001:10000)
%%
Plot_Dynamics_Rf_Spectrums_mu_pcolor(SiN(i).CW,SiN(i).Temp,100001:500000,[-15:15])
