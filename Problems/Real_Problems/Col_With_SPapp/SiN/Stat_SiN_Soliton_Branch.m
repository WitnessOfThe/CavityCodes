    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN


    N_mode              = 2^8;
    SiN.Stat.In         = Params_SiN;
%    L_L.CW.In.D        =2*pi*[1E12,20E6,0,-117.5E3,-5.3E3,-150];
    SiN.Stat.In.D(3:end)   = [];                 
    SiN.Stat.In.kappa   = 150E6*2*pi;                
    SiN.Stat.In.P       = 0.15;
    SiN.Stat.In.delta   = 4.4*SiN.Stat.In.kappa;

%% Stationary Coefficeints
    SiN.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    SiN.Stat.Met.Newton           = @Newton_Manual_bicgstab;%'fsolve'
    
%     SiN.Stat.Par.step_tol         = 0.000001;
%    SiN.Stat.Par.variable         = 'Pump Power';  %%'Pump Power';
%     SiN.Stat.Par.first_step       = 0.01; %min =1E-4/3
%     SiN.Stat.Par.bot_boundary     = 0;
%     SiN.Stat.Par.top_boundary     = 1;
    
 
    SiN.Stat.Par.variable         = 'delta';  %%'Pump Power';
    SiN.Stat.Par.first_step       = 0.01; % step for delta measured in delta/kappa
    SiN.Stat.Par.step_tol         = 0.00001;

    SiN.Stat.Par.bot_boundary     = 0;
    SiN.Stat.Par.top_boundary     = 20;
    
    SiN.Stat.Par.Sol_Re_Sign      = '-';
    SiN.Stat.Par.Stability        = 'Yes';
    SiN.Stat.Par.Newton_iter      = 30;      
    SiN.Stat.Par.Newton_tol       = 1E-10;  
    SiN.Stat.Par.i_max            = 500;
    SiN.Stat.Par.CW_num           = 3;
    SiN.Stat.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg'...
 ,'FunctionTolerance',SiN.Stat.Par.Newton_tol,...
     'MaxIterations',SiN.Stat.Par.Newton_iter,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);
%%

    SiN.Stat         = Chi3_Stat_LLE_Stat_From_Cons_Soliton(SiN.Stat,N_mode);
    SiN.Stat.Stab =                       Stability_Switcher(SiN.Stat(1));
    
    Plot_Static_Field_Spectrums(SiN.Stat,1);
    Plot_Static_Field_Stability(SiN.Stat,1);
    
%%    -4.8268

     SiN_Soliton_Branch.Stat = Run_Branch_Universal(SiN.Stat,N_mode);  

%%    
i_p= 1;
Psi_CW = NaN(3,size(SiN_Soliton_Branch.Stat,2));
 SiN.CW.In =  SiN.Stat.In;
for i_d = 1:size(SiN_Soliton_Branch.Stat,2)
    
        
        Mode_Power_U  (i_d)    = max(abs(ifft(SiN.Stat.Space.N*SiN_Soliton_Branch(i_p).Stat(i_d).Sol.Psi_k) ));
        delta_vector_U(i_d)    = SiN_Soliton_Branch(i_p).Stat(i_d).Eq.delta;
        Power_vector_U(i_d)    = SiN_Soliton_Branch(i_p).Stat(i_d).In.P;
        SiN.CW.In.delta        =  delta_vector_U(i_d)*SiN_Soliton_Branch.Stat(i_d).Eq.norm;
        SiN.CW.In.P           =  Power_vector_U(i_d) ;
        
        SiN.CW                 = SiN.CW.Met.Solve(SiN.CW,N_mode);
        Psi_CW(:,i_d)          = SiN.CW.Sol.Psi;
        
        [~,ind]                = max(real(SiN_Soliton_Branch.Stat(i_d).Stab.E_values));
        lambda_vector_U(i_d)   = SiN_Soliton_Branch(i_p).Stat(i_d).Stab.E_values(ind);
        
    
end


figure;
plot(delta_vector_U,abs(Psi_CW).^2,'Color',[0,0,0]);hold on;
plot(delta_vector_U,abs(Mode_Power_U).^2);hold on;
figure;
plot(delta_vector_U,real(lambda_vector_U));hold on;%delta_vector_U,
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
    Plot_Static_Field_Spectrums(SiN_Soliton_Branch.Stat(1),1);
%%
    Plot_Static_Field_Stability(SiN_Soliton_Branch.Stat(10),1);
