    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Input Parameters for CaF


    N_mode              = 2^8;
    
    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.P       = 0.0005779;
    CaF.Stat.In.delta   = -0.03668E6*2*pi;
    
%%
    mu                  = 11; 
    
%% Stationary Coefficeints
    CaF.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    CaF.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton           = @Newton_Manual_bicgstab;%'fsolve'
%        Res_Lower.Stat.Par.step_tol         = 0.0001;
 %   Res_Lower.Stat.Par.variable         = 'delta';  %%'Pump Power';
 %   Res_Lower.Stat.Par.first_step       = 0.01; %min =1E-4/3

    CaF.Stat.Par.step_tol         = 0.00001;
    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.variable         = 'delta';  %%'Pump Power';
    CaF.Stat.Par.first_step       = 0.1; %min =1E-4/3
    CaF.Stat.Par.Newton_iter      = 30;      
    CaF.Stat.Par.Newton_tol       = 1E-8;  
    CaF.Stat.Par.i_max            = 500;
    CaF.Stat.Par.CW_num          = 3;
    
%%    -4.8268
    [CaF_2D_Upper,CaF_2D_Lower] = Chi3_Stat_Get_Tongues_Branch(CaF,mu,N_mode,72);
%%    
Mode_Power_U    = NaN(size(CaF_2D_Upper,2),300);
delta_vector_U  = NaN(size(CaF_2D_Upper,2),300);
Power_vector_U  = NaN(size(CaF_2D_Upper,2),300);
lambda_vector_U = NaN(size(CaF_2D_Upper,2),300);

for i_p = 1:size(CaF_2D_Upper,2)
    
    for i_d = 1:size(CaF_2D_Upper(i_p).Stat,2)
        
        Mode_Power_U  (i_p,i_d)    = CaF_2D_Upper(i_p).Stat(i_d).Sol.Psi_k([mu+1]);
        delta_vector_U(i_p,i_d)    = CaF_2D_Upper(i_p).Stat(i_d).Eq.delta;
        Power_vector_U(i_p,i_d)    = CaF_2D_Upper(i_p).Stat(i_d).In.P;
        [~,ind]    = max(real(CaF_2D_Upper(i_p).Stat(i_d).Stab.E_values));
        lambda_vector_U(i_p,i_d)    = CaF_2D_Upper(i_p).Stat(i_d).Stab.E_values(ind);
        
    end
    
end
Mode_Power_L    = NaN(size(CaF_2D_Upper,2),300);
delta_vector_L  = NaN(size(CaF_2D_Upper,2),300);
Power_vector_L  = NaN(size(CaF_2D_Upper,2),300);
lambda_vector_L = NaN(size(CaF_2D_Upper,2),300);

for i_p = 1:size(CaF_2D_Lower,2)
    
    for i_d = 1:size(CaF_2D_Lower(i_p).Stat,2)
        
        Mode_Power_L  (i_p,i_d)    = CaF_2D_Lower(i_p).Stat(i_d).Sol.Psi_k([mu+1]);
        delta_vector_L(i_p,i_d)    = CaF_2D_Lower(i_p).Stat(i_d).Eq.delta;
        Power_vector_L(i_p,i_d)    = CaF_2D_Lower(i_p).Stat(i_d).In.P;
        [~,ind]    = max(real(CaF_2D_Lower(i_p).Stat(i_d).Stab.E_values));
        lambda_vector_L(i_p,i_d)    = CaF_2D_Lower(i_p).Stat(i_d).Stab.E_values(ind);
        
    end
    
end


figure;
mesh(delta_vector_U,Power_vector_U,abs(Mode_Power_U));hold on;
mesh(delta_vector_L,Power_vector_L,abs(Mode_Power_L))
figure;
mesh(delta_vector_U,Power_vector_U,real(lambda_vector_U));hold on;
figure;
mesh(delta_vector_L,Power_vector_L,real(lambda_vector_L));hold on;
figure;
mesh(delta_vector_U,Power_vector_U,imag(lambda_vector_U));hold on;
figure;
mesh(delta_vector_L,Power_vector_L,imag(lambda_vector_L));hold on;

%%
    Plot_Static_Field_Spectrums(CaF_2D_Upper(30).Stat(1),1);
    Plot_Static_Field_Stability(CaF_2D_Upper(30).Stat(1),1)
