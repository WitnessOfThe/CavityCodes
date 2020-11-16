    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Turing_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN

    N_Mode              = 2^9;
    
    SiN.Stat.In         =  Params_SiN_Modes(-1,N_Mode);        
    SiN.Stat.In.kappa   =  100E6*2*pi;
    SiN.Stat.In.delta   =  2.345*SiN.Stat.In.kappa;
    SiN.Stat.In.P       =  0.022;         
    mu                  =  44;
    SiN.CW.In           =  SiN.Stat.In;
    SiN.Temp.In         =  SiN.Stat.In;      
    
%%
    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 2E-4;
    SiN.Temp.Par.s_t           = 0.01;
    SiN.Temp.Par.T             = 200;
    SiN.Temp.Par.dd            = SiN.Temp.Par.T/SiN.Temp.Par.s_t;
    SiN.Temp.Par.CW_num        = 3;
    Runge                      = Define_Runge_Coeff(SiN.Temp.Par);

%% Stationary Coefficeints
    
    SiN.Stat.Par.i_max                = 2000;
    SiN.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';        
    SiN.Stat.Met.InitialGuess         = @Stat_In_Guess_Chi_3_LLE_From_Dyn;    
    SiN.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'
    SiN.Stat.Par.step_tol             = 1E-10;
    SiN.Stat.Par.Stability            = 'No';
    SiN.Stat.Par.variable             = 'delta';  
    SiN.Stat.Par.first_step           = 1; %min =1E-4/3
    SiN.Stat.Par.Newton_iter          = 60;      
    SiN.Stat.Par.Newton_tol           = 1E-11;  
    SiN.Stat.Par.i_max                = 200;
    SiN.Stat.Par.CW_num               = 3;
    
%% Temporal Coefficients
    
    SiN = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW_Defined(SiN,N_Mode,[ mu ,- mu]);
    
 %%
 
   [tt_1,tt_2]  = Plot_Static_Field_Spectrums(SiN.Stat(1),0);
   [tt_3,tt_4]  = Plot_Static_Field_Spectrums(SiN.Stat(2),0);
   [tt_5,tt_6]  = Plot_Static_Field_Spectrums(SiN.Stat(3),0);
   [tt_7,tt_8]  = Plot_Static_Field_Spectrums(SiN.Stat(4),0);
   
    figure('Name','Fields_Spectrums');    
    CF = conFigure([tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,tt_7,tt_8],4,2, 'UniformPlots', true, 'Height', 20, 'Width',20,'Labels',false);

%%

    SiN.Temp          = Chi_3_LLE_Normalization_Without_D_Coeff(SiN.Temp,N_Mode);                      
    SiN.CW.In         = SiN.Temp.In;
    SiN.CW            = SiN.CW.Met.Solve(SiN.CW,SiN.Temp.Space.N);
    SiN.CW.In.g       = SiN.CW.Sol.g(SiN.Temp.Par.CW_num)*SiN.CW.Eq.norm;   
    SiN.CW            = SiN.CW.Met.Mi_Formula(SiN.CW,SiN.Temp.Space.N);   

    SiN               = Chi_3_LLE_Start_Point_CW(SiN);  

    SiN.Temp.Met      = [];

    SiN.Temp.Sol      = Chi_3_LLE_Runge_Kuarong_mex(SiN.Temp,N_Mode,Runge);
                
%%

    [tt_1,tt_2] = Plot_Dynamics_Result_pcolors(SiN.Temp,1,0);
    [tt_3,tt_4] = Plot_Dynamics_Result_LinePlots_Spectrums(SiN.Temp,0);
    [tt_5,tt_6] = Plot_Dynamics_Rf_pcolor_without_Stat(SiN.CW,SiN.Temp,[-44,44],10001:20000,0);
    figure;
    CF = conFigure([tt_1,tt_2,tt_3,tt_4,tt_5,tt_6],2,3, 'UniformPlots', true, 'Height', 20, 'Width', 35,'Labels',false);
    
%%

    SiN.Stat(2:end) = [];
    SiN = Stat_In_Guess_Chi_3_LLE_From_Dyn(SiN,N_Mode);
    
%%
