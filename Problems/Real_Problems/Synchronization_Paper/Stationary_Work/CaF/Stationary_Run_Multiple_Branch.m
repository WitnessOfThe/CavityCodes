    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF_P       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Input Parameters for CaF


    N_mode              = 2^8;
    
    CaF_P.Stat.In         = Params_CaF;
    CaF_P.Stat.In.kappa   = 2E3*2*pi;                 
    CaF_P.Stat.In.P       = 0.2;
    CaF_P.Stat.In.delta   = -0.6E6*2*pi;
    CaF_P.Temp.In         = CaF_P.Stat.In;
    
%% Stationary Coefficeints

    CaF_P.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';        
    CaF_P.Stat.Met.InitialGuess         = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF_P.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'    
    CaF_P.Stat.Par.step_tol             = 0.000001;
    CaF_P.Stat.Par.Stability            = 'No';
    CaF_P.Stat.Par.variable             = 'Pump Power';  %%'Pump Power'
    CaF_P.Stat.Par.first_step           = 0.001; %min =1E-4/3
    CaF_P.Stat.Par.Newton_iter          = 30;      
    CaF_P.Stat.Par.Newton_tol           = 1E-10;  
    CaF_P.Stat.Par.i_max                = 500;
    CaF_P.Stat.Par.CW_num               = 3;
%%
    CaF_D =  CaF_P;
    CaF_D.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';        
    CaF_D.Stat.Met.InitialGuess         = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF_D.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'    
    CaF_D.Stat.Par.step_tol             = 0.0001;
    CaF_D.Stat.Par.Stability            = 'No';
    CaF_D.Stat.Par.variable             = 'delta';  %%'Pump Power'
    CaF_D.Stat.Par.first_step           = 0.01; %min =1E-4/3
    CaF_D.Stat.Par.Newton_iter          = 30;      
    CaF_D.Stat.Par.Newton_tol           = 1E-9;  
    CaF_D.Stat.Par.i_max                = 20;
    CaF_D.Stat.Par.CW_num               = 3;

%%
    N        = 30;       
    power_in = linspace(0.000240066,0.000240066,N); %   
    delta_in = linspace(-24.13,-24,N)*CaF_P.Stat.In.kappa;%   
    
    parfor i = 1:N
        
        Res = CaF_P;
        Res.Stat.In.P     = power_in(i);
        Res.Stat.In.delta = delta_in(i);

        Res     = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW_Defined(Res,N_mode,[10,-10]);
        CaF_B(i).Stat = Run_Branch_Universal(Res,N_mode);
        
    end
%%

        Res.Stat                 = CaF_B(30).Stat(28);           
        Res.Stat.Par             = CaF_D.Stat.Par;
        
        CaF_S(1).Stat            = Run_Branch_Universal(Res,N_mode);
        
%%        
        Res.Stat                 = CaF_B(30).Stat(190);           
        Res.Stat.Par             = CaF_D.Stat.Par;
        CaF_S(2).Stat = Run_Branch_Universal(Res,N_mode);

%%
   NN        = 30;       
    
    parfor i = 1:size(CaF_S(1).Stat,2)
        Res      = CaF_P;
        Res.Stat = CaF_S(1).Stat(i);
        Res.Stat.Par             = CaF_P.Stat.Par;
        CaF_U(i).Stat = Run_Branch_Universal(Res,N_mode);
        
    end
    parfor i = 1:size(CaF_S(2).Stat,2)
        Res      = CaF_P;
        Res.Stat = CaF_S(2).Stat(i);
        Res.Stat.Par             = CaF_P.Stat.Par;
        CaF_L(i).Stat = Run_Branch_Universal(Res,N_mode);
        
    end

    %%
%     parfor i = 1:N
%         
%         Res = CaF;
%         Res.Stat = CaF_B(i).Stat(end);
%  
%         Res.Stat.In.Psi_Start    = Res.Stat.Sol.Psi_k;
%         CaF_L(i).Stat = Run_Branch_Universal(Res,N_mode);
%         
%     end
%%
for i_p = 1:size(CaF_B,2)
    for i_d = 1:size(CaF_B(i_p).Stat,2)
        
        Mode_Power(i_p,i_d)      = abs(CaF_B(i_p).Stat(i_d).Sol.Psi_k([11]));
        delta_vector(i_p,i_d)    = CaF_B(i_p).Stat(i_d).In.delta/CaF_P.Stat.In.kappa;
        Power_vector(i_p,i_d)    = CaF_B(i_p).Stat(i_d).In.P;
  %      [Re_lambda_Vector(i_p,i_d),ind] =  max(real(CaF_B(i_p).Stat(i_d).Stab.E_values));
   %     Im_lambda_Vector(i_p,i_d) =  (imag(CaF_B(i_p).Stat(i_d).Stab.E_values(ind)));
    end
end

%%
ii = 1;

Mode_Power_S = zeros(1,size(CaF_S(ii).Stat,2));
delta_vector_S = zeros(1,size(CaF_S(ii).Stat,2));
for i=1:size(CaF_S(ii).Stat,2)
        Mode_Power_S(i)      = abs(CaF_S(ii).Stat(i).Sol.Psi_k([11]));
        delta_vector_S(i)    = CaF_S(ii).Stat(i).In.delta/CaF_P.Stat.In.kappa;
        
end
figure;plot(delta_vector_S,Mode_Power_S)
%%
ii = 30;
figure;plot(Mode_Power(ii,:))%Power_vector(ii,:),
%%
Mode_Power(Mode_Power==0) =NaN;
%Mode_Power_l(Mode_Power_l==0) =NaN;
figure;mesh(delta_vector,Power_vector,Mode_Power)
%hold on;mesh(delta_vector_l,Power_vector_l,Mode_Power_l)
%%
Re_lambda_Vector(Re_lambda_Vector==0) =NaN;
figure;mesh(delta_vector,Power_vector,Re_lambda_Vector)
%%
Im_lambda_Vector(Im_lambda_Vector==0) =NaN;
figure;mesh(delta_vector,Power_vector,Im_lambda_Vector)
%%
    Plot_Static_Field_Spectrums(CaF_S(1).Stat(end-6),1);
    Plot_Static_Field_Spectrums(CaF_S(2).Stat(end-6),1);

%%
%%
for i_p = 1:size(CaF_L,2)
    for i_d = 1:size(CaF_L(i_p).Stat,2)
        
        Mode_Power_L(i_p,i_d)      = abs(CaF_L(i_p).Stat(i_d).Sol.Psi_k([11]));
        delta_vector_L(i_p,i_d)    = CaF_L(i_p).Stat(i_d).In.delta/CaF_P.Stat.In.kappa;
        Power_vector_L(i_p,i_d)    = CaF_L(i_p).Stat(i_d).In.P;
%        [Re_lambda_Vector(i_p,i_d),ind] =  max(real(CaF_L(i_p).Stat(i_d).Stab.E_values));
 %       Im_lambda_Vector(i_p,i_d) =  (imag(CaF_L(i_p).Stat(i_d).Stab.E_values(ind)));
    end
end
for i_p = 1:size(CaF_U,2)
    for i_d = 1:size(CaF_U(i_p).Stat,2)
        
        Mode_Power_U(i_p,i_d)      = abs(CaF_U(i_p).Stat(i_d).Sol.Psi_k([11]));
        delta_vector_U(i_p,i_d)    = CaF_U(i_p).Stat(i_d).In.delta/CaF_P.Stat.In.kappa;
        Power_vector_U(i_p,i_d)    = CaF_U(i_p).Stat(i_d).In.P;
%        [Re_lambda_Vector(i_p,i_d),ind] =  max(real(CaF_L(i_p).Stat(i_d).Stab.E_values));
 %       Im_lambda_Vector(i_p,i_d) =  (imag(CaF_L(i_p).Stat(i_d).Stab.E_values(ind)));
    end
end
Mode_Power_L(Mode_Power_L == 0) = NaN;
Mode_Power_U(Mode_Power_U == 0) = NaN;
figure;
mesh(delta_vector_L,Power_vector_L,Mode_Power_L)
hold on;
mesh(delta_vector_U,Power_vector_U,Mode_Power_U)

%%

