    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Bloch_Matrices;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    N_mode              = 2^5;
    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    CaF.Stat.In.P       =4E-6    ;
    CaF.Stat.In.delta   = 12.4341*CaF.Stat.In.kappa;
    CaF.Stat.In.range   = 2^4;
    CaF.Stat.In.mu_bl   = 10;
    CaF.Stat.Par.CW_num = 1;
    CaF.Temp.In         = CaF.Stat.In;
    
%% Stationary Coefficeints

    CaF.Stat.Par.i_max                = 2000;
    CaF.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    
    CaF.Stat.Met.InitialGuess         = @Stat_In_Guess_Chi_3_LLE_From_Dyn;    
    CaF.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'
    
    CaF.Stat.Par.step_tol             = 1E-10;
    CaF.Stat.Par.Stability            = 'No';
    CaF.Stat.Par.variable             = 'delta';  
    CaF.Stat.Par.first_step           = 1; %min =1E-4/3
    CaF.Stat.Par.Newton_iter          = 50;      
    CaF.Stat.Par.Newton_tol           = 1E-18;  
    CaF.Stat.Par.i_max                = 200;
    
%% Temporal Coefficients
    
    CaF             = Chi3_LLE_Bloch_Stat_In_Guess_From_CW_Defined(CaF,N_mode);
    
 %%
 
  [tt_1_1,tt_1_2] =  Plot_Static_Field_Spectrums(CaF.Stat(1),0);
  [tt_2_1,tt_2_2] =  Plot_Static_Field_Spectrums(CaF.Stat(2),0);
  [tt_3_1,tt_3_2] =  Plot_Static_Field_Spectrums(CaF.Stat(3),0);
  [tt_4_1,tt_4_2] =  Plot_Static_Field_Spectrums(CaF.Stat(4),0);
  
   figure('Name','Fields_Spectrums');
   CF = conFigure([tt_1_1,tt_1_2,tt_2_1,tt_2_2,tt_3_1,tt_3_2,tt_4_1,tt_4_2]...
       ,4,2, 'UniformPlots', true, 'Height', 14, 'Width', 18,'Labels',false);
    
%%
