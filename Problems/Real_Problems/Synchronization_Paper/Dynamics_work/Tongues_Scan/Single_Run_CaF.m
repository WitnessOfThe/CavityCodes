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
    SiN.Temp.In.P       = 0.07;      
    SiN.Temp.In.delta   = -0.243E6*2*pi;%-0.379E6*2*pi;
    
%%
    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 5E-5;
    SiN.Temp.Par.s_t           = 0.001;
    SiN.Temp.Par.T             = 150;
    SiN.Temp.Par.CW_num        = 3;
    SiN.Temp.Par.dd            = SiN.Temp.Par.T/SiN.Temp.Par.s_t;
    
%%
    SiN.Temp.Met.Ev_Core    = @Chi_3_LLE_Kuar_mex;
    tic
    Runge                      = Define_Runge_Coeff(SiN.Temp.Par);
                SiN.Temp.Met    =                                        [];
      %          tic  
                SiN.Temp        =    Chi_3_LLE_Normalization(SiN.Temp,N_mode);        
                SiN             =               Chi_3_LLE_Start_Point_CW(SiN);    
                SiN(1).Temp.Sol =    Chi_3_LLE_Runge_Kuarong_mex(SiN.Temp,N_mode,Runge);
    toc
%%
Plot_Dynamics_Result_pcolors(SiN.Temp,1,1)
Plot_Dynamics_Result_LinePlots_Spectrums(SiN.Temp,1)




