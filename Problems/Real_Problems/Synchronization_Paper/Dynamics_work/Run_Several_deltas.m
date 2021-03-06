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
%    SiN.Temp.In.P       = 1.2;      
     SiN.Temp.In.P       = 1.0;      
    
%%

    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';
    SiN.Temp.Par.dt            = 0.005E-2;
    SiN.Temp.Par.s_t           = 0.01;
    SiN.Temp.Par.T             = 400;
    SiN.Temp.Par.CW_num        = 3;
    
%%
    SiN.Temp.Met.Ev_Start_Point = @Chi_3_LLE_Start_Point_CW;
    NN = 30;
    delta_vector = linspace(-0.595,-0.588,NN)*1e+09*2*pi;
% delta_vector = linspace(-0.040,-0.0,NN)*1e+09*2*pi;

    for i=1:NN
        
        SiN(i) =SiN(1);
        
    end
        
        
    tic
    parfor i =1:NN
        
        SiN(i).Temp.In.delta = delta_vector(i);
        SiN(i)          = Runge_Kuarong(SiN(i),N_mode);
        i
        
    end
    toc
%%
%%
    %%
    i = 1
    
    
   SiN(i).Temp.Met.Plot.Fields_Spectrums(SiN(i).Temp)
   SiN(i).Temp.Met.Plot.Carpets(SiN(i).Temp,100)
   Plot_Dynamics_Rf_Spectrums(SiN(i).Temp,[5,-5],25001:40000)
   %%
   i = 1
%%   
   Plot_Dynamics_Rf_Spectrums_mu_pcolor(SiN(i).CW,SiN(i).Temp,5001:500000,[-10:10],[-5,5])
%%
   Plot_Dynamics_Repetution_Rate_From_Array(SiN,[5,-5],101:10000)
