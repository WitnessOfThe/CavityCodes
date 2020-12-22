%%%%
    clc;
    clear all;
    
%% Define Input Parameters in Physical Units
    
    CaF       =  Set_Up_Methods_For_Bloch_Matrices;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF


    CaF.Stat.In         = Params_CaF;    
    CaF.Stat.In.range   = 2^7;
    CaF.Stat.In.N_mode  = 2^8;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
   
    CaF.Stat.In.delta   = 70*CaF.Stat.In.kappa;
    
 
%%
    
%    CaF.Stat.In.mu_bl   = 16;
%    W_WStar             = 650;
%    CaF.Stat.In.P       = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma;
%    Delta_Start         = [35.54,35.54]*CaF.Stat.In.kappa;%16   
%    Delta_Start         = [-14,-14,16,16]*CaF.Stat.In.kappa;%8
%    Delta_Start         = [-6.3,-6.3,10,13]*CaF.Stat.In.kappa;%7
%    Delta_Start         = [-6,10.63,12]*CaF.Stat.In.kappa;%6
%    Delta_Start         = [-2,5.5,11.65]*CaF.Stat.In.kappa;%5
%    Delta_Start         = [3]*CaF.Stat.In.kappa;%4

%%
    CaF.CW.In         = CaF.Stat.In;
    CaF.CW.In.N_mode  = 2^8;

%% Stationary Coefficeints

    CaF.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    CaF.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton           = @fsolve;%'fsolve'
         
    CaF.Stat.Par.variable         = 'delta';  %%'Pump Power';
    CaF.Stat.Par.first_step       = 5; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.001;
    CaF.Stat.Par.step_inc         = 0.25;
    CaF.Stat.Par.step_dec         = 0.5;

    CaF.Stat.Par.bot_boundary     = -40; % bottom boundary for delta to search
    CaF.Stat.Par.top_boundary     = 702; % top boundary for delta to search

    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.Newton_iter      = 30;      
    CaF.Stat.Par.Newton_tol       = 1E-10;  
    CaF.Stat.Par.i_max            = 4000;
    CaF.Stat.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);
  
%%
    
    W_WStar             = 500;
    CaF.Stat.In.P       = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma;
    CaF.CW.In.P         = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma;
    
%%

    CaF.Stat.In.mu_bl   = 7;
    Delta_Start         = [10]*CaF.Stat.In.kappa;%8
    Index_Start         = [3];  
    [CaF_Branches_7] = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
%%

    CaF.Stat.In.mu_bl   = 1;
    Index_Start         = 1;%1,
    Delta_Start         = 397*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches_4      = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
%%

    CaF.Stat.In.mu_bl   = 3;
    Index_Start         = [1,2,3];%1,
    Delta_Start         = [0,14,10]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches_4      = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);

    
%%
    CaF.Stat.In.mu_bl   = 16;    
    Delta_Start         = [34.84,34.84]*CaF.Stat.In.kappa;%8
    Index_Start         = [3,4];    
    CaF_Branches_16     = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);

    CaF.Stat.In.mu_bl   = 14;    
    Delta_Start         = [27.743,27.743]*CaF.Stat.In.kappa;%8
    Index_Start         = [3,4];    
    [CaF_Branches_14] = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
    CaF.Stat.In.mu_bl   = 8;
        
    CaF.Stat.Par.first_step       = 0.05; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.01;

    Delta_Start         = [-14.65,-14.4]*CaF.Stat.In.kappa;%8
    Index_Start         = [1,2];    
    [CaF_Branches_8_12] = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
%    CaF.Stat.Par.first_step       = 0.01; % step for delta measured in delta/kappa
%    CaF.Stat.Par.step_tol         = 0.002;
    
    CaF.Stat.Par.first_step       = 0.5; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.01;
    Delta_Start         = [16,16]*CaF.Stat.In.kappa;%8
    Index_Start         = [3,4];
    [CaF_Branches_8_34] = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
    
    CaF.Stat.In.mu_bl   = 6;
    Index_Start         = [1,2,3,4];  
    Delta_Start         = [-6.3,-6.3,10,13]*CaF.Stat.In.kappa;%8
    [CaF_Branches_6] = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
    CaF.Stat.In.mu_bl   = 5;
    Delta_Start         = [-2,5.5,11.65]*CaF.Stat.In.kappa;
    Index_Start         = [2,3,4];    
    [CaF_Branches_5]    = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    Index_Start         = [3,4];    
    
%   CaF_1D_Upper = Chi3_Stat_Get_Single_Branch_Turing(CaF,CaF.Stat.In.mu_bl,N_mode);
%   CaF_1D_Lower = CaF_1D_Upper;
%%
    figure('Position',[0,0,1400,900],'Color',[1,1,1]);

    Panel = tiledlayout(2,3,'TileSpacing','none','Padding','none');
    for i =1:6
        
        ax(i) = nexttile(Panel,i,[1,1]);  
        hold(ax(i),'on');
            
    end
    ind_br   = 1;
    ind_stat = 10;
        
%    Plot_LLE_Bloch_Static_Multiple_Branches(CaF_Branches(ind_br).CW(1),CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(1:end),ax(1:2));
%    Plot_Static_Field_Spectrums(CaF_Branches(ind_br).Stat(ind_stat),ax(3:4));   
        Plot_LLE_Bloch_Static_Branch_Stability(CaF.CW,CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(ind_br),ax(1:8));

%%

    h =  figure('Position',[0,0,1400,700],'Color',[1,1,1]);
    Panel = tiledlayout(h,6,16,'TileSpacing','none','Padding','none');
    
    ax(1) = nexttile(Panel,1,[2,4]);  
    ax(2) = nexttile(Panel,5,[2,4]); 
    
    ax(3) = nexttile(Panel,33,[2,2]);  
    ax(4) = nexttile(Panel,35,[2,2]);  
 %  
    ax(5) = nexttile(Panel,37,[2,4]);  
    ax(6) = nexttile(Panel,65,[2,4]);  
    ax(7) = nexttile(Panel,69,[2,4]);  
    
    ax(8) = nexttile(Panel,41,[1,2]);  
    ax(9) = nexttile(Panel,43,[1,2]);  
    ax(10) = nexttile(Panel,57,[1,2]);  
    ax(11) = nexttile(Panel,59,[1,2]);
    
    ax(12) = nexttile(Panel,45,[1,2]);  
    ax(13) = nexttile(Panel,47,[1,2]);  
    ax(14) = nexttile(Panel,61,[1,2]);  
    ax(15) = nexttile(Panel,63,[1,2]);

    ax(16) = nexttile(Panel,41+32,[1,2]);  
    ax(17) = nexttile(Panel,43+32,[1,2]);  
    ax(18) = nexttile(Panel,57+32,[1,2]);  
    ax(19) = nexttile(Panel,59+32,[1,2]);
    
    ax(20) = nexttile(Panel,45+32,[1,2]);  
    ax(21) = nexttile(Panel,47+32,[1,2]);  
    ax(22) = nexttile(Panel,61+32,[1,2]);  
    ax(23) = nexttile(Panel,63+32,[1,2]);
 %   
    ax(24) = nexttile(Panel,9,[1,2]);  
    ax(25) = nexttile(Panel,11,[1,2]);  
    ax(26) = nexttile(Panel,25,[1,2]);  
    ax(27) = nexttile(Panel,27,[1,2]);
    
    ax(28) = nexttile(Panel,13,[1,2]);  
    ax(29) = nexttile(Panel,15,[1,2]);  
    ax(30) = nexttile(Panel,29,[1,2]);  
    ax(31) = nexttile(Panel,31,[1,2]);
    
    
    for i =1:size(ax,2)
        hold(ax(i),'on');
    end
    ind_br   = 1;
    ind_stat = 76;
        
    Plot_LLE_Bloch_Static_Multiple_Branches(CaF_Branches(ind_br).CW(1),CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(1:end),ax(1:2));
     Plot_Static_Field_Spectrums(CaF_Branches(ind_br).Stat(ind_stat),ax(3:4));   
    Plot_LLE_Bloch_Static_Field_Stability(CaF_Branches(ind_br).Stat(ind_stat),ax(5:23));
    Plot_LLE_Bloch_Static_Branch_Stability(CaF.CW,CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(ind_br),ax(24:end));
    
