    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Input Parameters for CaF


    N_mode              = 2^8;
    
    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.P       = 0.0004;
    CaF.Stat.In.delta   = -CaF.Stat.In.kappa*28;
    
%%
    mu                  = 11; 
    
%% Stationary Coefficeints
    CaF.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    CaF.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton           = @Newton_Manual_bicgstab;%'fsolve'
    
%     CaF.Stat.Par.step_tol         = 0.000001;
%     CaF.Stat.Par.variable         = 'Pump Power';  %%'Pump Power';
%     CaF.Stat.Par.first_step       = 0.01; %min =1E-4/3
%     CaF.Stat.Par.bot_boundary     = 0;
%     CaF.Stat.Par.top_boundary     = 1;
    
 
    CaF.Stat.Par.variable         = 'delta';  %%'Pump Power';
    CaF.Stat.Par.first_step       = 0.1; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.00001;

    CaF.Stat.Par.bot_boundary     = -30;
    CaF.Stat.Par.top_boundary     = -22.5;

    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.Newton_iter      = 30;      
    CaF.Stat.Par.Newton_tol       = 1E-13;  
    CaF.Stat.Par.i_max            = 500;
    CaF.Stat.Par.CW_num          = 3;
    
%%    -4.8268

    [CaF_1D_Upper,CaF_1D_Lower] = Chi3_Stat_Get_Branch_Turing(CaF,mu,N_mode);
    
%%    
i_p =1;
for i_d = 1:size(CaF_1D_Upper.Stat,2)
    
        
        Mode_Power_U  (i_d)    = CaF_1D_Upper(i_p).Stat(i_d).Sol.Psi_k([mu+1]);
        delta_vector_U(i_d)    = CaF_1D_Upper(i_p).Stat(i_d).Eq.delta;
        Power_vector_U(i_d)    = CaF_1D_Upper(i_p).Stat(i_d).In.P;
        [~,ind]    = max(real(CaF_1D_Upper(i_p).Stat(i_d).Stab.E_values));
        lambda_vector_U(i_d)    = CaF_1D_Upper(i_p).Stat(i_d).Stab.E_values(ind);
        
    
end

for i_d = 1:size(CaF_1D_Lower.Stat,2)
    
        
        Mode_Power_L  (i_d)    = CaF_1D_Lower(i_p).Stat(i_d).Sol.Psi_k([mu+1]);
        delta_vector_L(i_d)    = CaF_1D_Lower(i_p).Stat(i_d).Eq.delta;
        Power_vector_L(i_d)    = CaF_1D_Lower(i_p).Stat(i_d).In.P;
        [~,ind]    = max(real(CaF_1D_Lower(i_p).Stat(i_d).Stab.E_values));
        lambda_vector_L(i_d)    = CaF_1D_Lower(i_p).Stat(i_d).Stab.E_values(ind);
        
    
end


figure;
plot(delta_vector_U,abs(Mode_Power_U));hold on;
plot(delta_vector_L,abs(Mode_Power_L))
figure;
plot(delta_vector_U,real(lambda_vector_U));hold on;
plot(delta_vector_L,real(lambda_vector_L));hold on;
figure;
plot(delta_vector_U,imag(lambda_vector_U));hold on;
plot(delta_vector_L,imag(lambda_vector_L));hold on;

% figure;
% plot(Power_vector_U,abs(Mode_Power_U).^2);hold on;
% plot(Power_vector_L,abs(Mode_Power_L).^2)
% figure;
% plot(Power_vector_U,real(lambda_vector_U));hold on;
% plot(Power_vector_L,real(lambda_vector_L));hold on;
% figure;
% plot(Power_vector_U,imag(lambda_vector_U));hold on;
% plot(Power_vector_L,imag(lambda_vector_L));hold on;
% 
%%

    Plot_Static_Field_Spectrums(CaF_1D_Lower(end/2).Stat(1),1);
    Plot_Static_Field_Stability(CaF_1D_Upper(1).Stat(1),1)
