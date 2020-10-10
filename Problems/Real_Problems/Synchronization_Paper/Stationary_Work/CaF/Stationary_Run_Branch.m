    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF


    N_mode              = 2^10;
    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.P       = 0.04;
    CaF.Stat.In.delta   = -0.605E6*2*pi;
    
    CaF.Temp.In         = CaF.Stat.In;
%% Stationary Coefficeints

    CaF.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    
    CaF.Stat.Met.InitialGuess         = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'
    
    CaF.Stat.Par.step_tol             = 1*2*pi/CaF.Stat.In.kappa;
    CaF.Stat.Par.Stability            = 'No';
    CaF.Stat.Par.variable             = 'delta';  
    CaF.Stat.Par.first_step           = 1e3*2*pi/CaF.Stat.In.kappa; %min =1E-4/3
    CaF.Stat.Par.Newton_iter          = 100;      
    CaF.Stat.Par.Newton_tol           = 1E-8;  
    CaF.Stat.Par.i_max                = 10;
    CaF.Stat.Par.CW_num               = 3;
    
%% Temporal Coefficients
    
    CaF = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW(CaF,N_mode);
    CaF.Stat = Run_Branch_Universal(CaF,N_mode);
    
    %%
for i=1:size(CaF.Stat,2)
    
    Mode_Power(i,:) = CaF.Stat(i).Sol.Psi_k([1,36,end-35+1]);
    delta_vector(i)    = CaF.Stat(i).Eq.delta*CaF.Stat(i).Eq.norm;
   % Eig_value_vector(i,1:12)    = real(CaF.Stat(i).Stab.E_values(1:12));
end
figure;
plot(delta_vector/2/pi/1E6,(abs(Mode_Power)))
%figure;
%plot(delta_vector/2/pi/1E6,Eig_value_vector)

%%
     Plot_Static_Field_Spectrums(CaF.Stat(1),1);

  
