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
%%
    N        = 30;       
    power_in =     linspace(0.005,0.07,N);
    delta_in = linspace(-.2548,-0.2423,N)*2*pi*1E6;
    
    parfor i = 1:N
        
        Res = CaF;
        Res.Stat.In.P     = power_in(i);
        Res.Stat.In.delta = delta_in(i);

        Res     = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW(Res,N_mode);
        CaF_B(i).Stat = Run_Branch_Universal(Res,N_mode);
        
    end
    %%
    
for i_p = 1:size(CaF_B,2)
    for i_d = 1:size(CaF_B(i_p).Stat,2)
        
        Mode_Power(i_p,i_d)      = abs(CaF_B(i_p).Stat(i_d).Sol.Psi_k([24])).^2;
        delta_vector(i_p,i_d)    = CaF_B(i_p).Stat(i_d).In.delta;
        Power_vector(i_p,i_d)    = CaF_B(i_p).Stat(i_d).In.P;
        
    end
end

%%

figure;mesh(delta_vector,Power_vector,Mode_Power)
