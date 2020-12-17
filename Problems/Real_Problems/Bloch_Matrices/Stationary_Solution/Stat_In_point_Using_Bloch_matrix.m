    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Bloch_Matrices;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.delta   = 2*CaF.Stat.In.kappa;
    CaF.Stat.In.range   = 2^6;
    CaF.Stat.In.mu_bl   = 7;   
    CaF.Stat.Par.CW_num = 1;
    CaF.Stat.Par.In.Rel_ampl = 0.8;
    
    W_WStar             = 500;
    CaF.Stat.In.P       = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma;
    
    CaF.CW.In           = CaF.Stat.In;
    CaF.Stat.In.N_mode  = 2^7;
    CaF.CW.In.N_mode    = 2^8;
    
%% Stationary Coefficeints

    CaF.Stat.Par.i_max                = 2000;
    CaF.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    
    CaF.Stat.Met.InitialGuess         = @Stat_In_Guess_Chi_3_LLE_From_Dyn;    
    CaF.Stat.Met.Newton               = @fsolve;%'fsolve'
    %Newton_Manual_bicgstab
    CaF.Stat.Par.step_tol             = 1E-10;
    CaF.Stat.Par.Stability            = 'No';
    CaF.Stat.Par.variable             = 'delta';  
    CaF.Stat.Par.first_step           = 1; %min =1E-4/3
    CaF.Stat.Par.Newton_iter          = 30;      
    CaF.Stat.Par.Newton_tol           = 1E-10;  
    CaF.Stat.Par.i_max                = 50;
    CaF.Stat.Par.fsolveoptions        = optimoptions('fsolve','CheckGradients',...
    false,'Display','iter','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);
%    ..
%,'FunctionTolerance', CaF.Stat.Par.Newton_tol,...
 %    'MaxIterations', CaF.Stat.Par.Newton_iter,'StepTolerance',1E-20,'OptimalityTolerance',1E-25
%% Temporal Coefficients
    
    CaF             = Chi3_LLE_Bloch_Stat_In_Guess_From_CW_Defined(CaF);
    
 %%
  figure('Position',[0,0,1400,900],'Color',[1,1,1]);
    Panel = tiledlayout(4,2,'TileSpacing','none','Padding','none');
    
    ax(1) = nexttile(Panel,1,[1,1]);  
    ax(2) = nexttile(Panel,2,[1,1]);    
    ax(3) = nexttile(Panel,3,[1,1]);  
    ax(4) = nexttile(Panel,4,[1,1]);  
    ax(5) = nexttile(Panel,5,[1,1]);  
    ax(6) = nexttile(Panel,6,[1,1]);    
    ax(7) = nexttile(Panel,7,[1,1]);  
    ax(8) = nexttile(Panel,8,[1,1]);  
    
       Plot_Static_Field_Spectrums(CaF(1).Stat(1),ax(1:2));   
       Plot_Static_Field_Spectrums(CaF(1).Stat(2),ax(3:4));   
       Plot_Static_Field_Spectrums(CaF(1).Stat(3),ax(5:6));   
       Plot_Static_Field_Spectrums(CaF(1).Stat(4),ax(7:8));   

%%

