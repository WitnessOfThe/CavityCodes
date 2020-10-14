    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF


    N_mode              = 2^10;
    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.P       = 0.2;
    CaF.Stat.In.delta   = -0.6E6*2*pi;
    
    CaF.Temp.In         = CaF.Stat.In;
%% Stationary Coefficeints

    CaF.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    
    CaF.Stat.Met.InitialGuess         = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'
    
    CaF.Stat.Par.step_tol             = 1*2*pi/CaF.Stat.In.kappa;
    CaF.Stat.Par.Stability            = 'No';
    CaF.Stat.Par.variable             = 'delta';  %%'Pump Power'
    CaF.Stat.Par.first_step           = 1e3*2*pi/CaF.Stat.In.kappa; %min =1E-4/3
    CaF.Stat.Par.Newton_iter          = 300;      
    CaF.Stat.Par.Newton_tol           = 5E-10;  
    CaF.Stat.Par.i_max                = 40;
    CaF.Stat.Par.CW_num               = 3;
    
%% Temporal Coefficients
    
    CaF = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW(CaF,N_mode);
    CaF.Stat = Run_Branch_Universal(CaF,N_mode);
    
    %%
for i=1:size(CaF.Stat,2)
    
    Mode_Power(i,:) = CaF.Stat(i).Sol.Psi_k([36]);
    delta_vector(i)    = CaF.Stat(i).In.delta;
    Power_vector(i)    = CaF.Stat(i).In.P;
   % Eig_value_vector(i,1:12)    = real(CaF.Stat(i).Stab.E_values(1:12));
end
figure;
plot(delta_vector/2/pi/1E6,(abs(Mode_Power)))
%
figure;
plot((abs(Mode_Power)))
%plot(delta_vector/2/pi/1E6,Eig_value_vector)

%%

%%
    CaF.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    CaF.Temp.Par.dt            = 1E-5;
    CaF.Temp.Par.s_t           = 0.01;
    CaF.Temp.Par.T             = 50;
    CaF.Temp.Par.CW_num        = 3;
    CaF.Temp.Par.dd            = CaF.Temp.Par.T/CaF.Temp.Par.s_t;
%%
    CaF.Temp.Met.Ev_Core    = @Chi_3_LLE_Kuar_mex;
    tic
    Runge                      = Define_Runge_Coeff(CaF.Temp.Par);
                CaF.Temp.Met    =                                          [];
      %          tic  
                CaF             =               Chi_3_LLE_Start_Point_Stat(CaF,22);    
                CaF(1).Temp.Sol =    Chi_3_LLE_Runge_Kuarong(CaF.Temp,N_mode,Runge);
    toc
%%
Plot_Dynamics_Result_LinePlots_Spectrums(CaF.Temp,1)
%%
%    SiN.Temp.Met.Plot.Integrative_Dynamics(SiN.Temp)
%%
    CaF.Temp.Met.Plot.Carpets(CaF.Temp,100,1)
%%
   Plot_Dynamics_Rf_Spectrums_mu(CaF.Temp,20001:25000)
%%
    Plot_Dynamics_Rf_Spectrums(CaF.Temp,[-15,15],10001:500000)
%% 
i=1;
   Plot_Dynamics_Rf_Spectrums_mu(CaF(i).CW,CaF(i).Temp,10001:500000)
%%
Plot_Dynamics_Repetution_Rate_From_Array(CaF,[6,-6],1001:50000)

