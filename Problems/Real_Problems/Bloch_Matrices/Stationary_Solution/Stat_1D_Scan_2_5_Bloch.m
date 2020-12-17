%%%%
    clc;
    clear all;
    
%% Define Input Parameters in Physical Units
    
    CaF       =  Set_Up_Methods_For_Bloch_Matrices;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF


    CaF.Stat.In         = Params_CaF;    
    CaF.Stat.In.range   = 2^7;
    CaF.Stat.In.N_mode  = 2^9;
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
    CaF.Stat.Par.first_step       = 0.01; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.001;
    CaF.Stat.Par.step_inc         = 0.00;
    CaF.Stat.Par.step_dec         = 0.5;

    CaF.Stat.Par.bot_boundary     = -40; % bottom boundary for delta to search
    CaF.Stat.Par.top_boundary     =  602; % top boundary for delta to search

    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.Newton_iter          = 30;      
    CaF.Stat.Par.Newton_tol           = 1E-10;  
    CaF.Stat.Par.i_max                = 500;
    CaF.Stat.Par.fsolveoptions        = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);
%  
%%
    
%    W_WStar             = 2.25;
    W_WStar             = 2.5;
    CaF.Stat.In.P       = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma;
    CaF.CW.In.P         = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma; 
    CaF.Stat.In.mu_bl   = 4;    
    Index_Start         = [1,2];%1,
    Delta_Start         = [1.63,2.38]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
%%    
    CaF.Stat.In.mu_bl   = 3;    
    Index_Start         = [1,2];%1,
    Delta_Start         = [0.18,1.85]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);

%%    
    CaF.Stat.Par.first_step       = 0.01; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.001;

    CaF.Stat.In.mu_bl   = 2;    
    Index_Start         = [1,2];%1,
    Delta_Start         = [0,1.7]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    

%%    
    CaF.Stat.In.mu_bl   = 1;    
    Index_Start         = [1];%1,
    Delta_Start         = [1.9]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
%%
    CaF.Stat.In.mu_bl   = 1;    
    Index_Start         = [1,2,3,4,5,6,7];%1,
    Delta_Start         = [1.9,1.5,1.4,2.1,1.81,1.38,1.9]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);

%%    
    CaF.Stat.In.mu_bl   = 1;    
    Index_Start         = 7;%1,
    Delta_Start         = [ 1.9]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
%%

    CaF.Stat.In.mu_bl   = 3;
    Index_Start         = [1,2,3];%1,
    Delta_Start         = [0,14,10]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches      = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);

    
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
    CaF.Stat.Par.step_tol         = 0.001;
    Delta_Start         = [16,16]*CaF.Stat.In.kappa;%8
    Index_Start         = [3,4];
    [CaF_Branches_8_34] = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
    CaF.Stat.In.mu_bl   = 7;
    Delta_Start         = [-6.3,-6.3,10,13]*CaF.Stat.In.kappa;%8
    Index_Start         = [1,2,3,4];  
    [CaF_Branches_7] = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
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
%    CaF.Stat.In.mu_bl   = 4;
%    Index_Start         = [4,5];    
%    Delta_Start         = [9.792,2.5]*CaF.Stat.In.kappa;
%    [CaF_Branches_4]    = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);

%%

   [pb_1,pb_2] = Plot_LLE_Bloch_Static_Multiple_Branches(CaF.CW,CaF_Branches(1).Stat(1),CaF_Branches,0);
    Plot_LLE_Bloch_Static_Branch_Stability(CaF.CW,CaF_Branches(3).Stat(1),CaF_Branches(4),1);
   [pf_1,pf_2] =  Plot_Static_Field_Spectrums(CaF_Branches(1).Stat(1),0);
   [pf_3,pf_4] =  Plot_Static_Field_Spectrums(CaF_Branches(2).Stat(1),0);
   [pf_5,pf_6] =  Plot_Static_Field_Spectrums(CaF_Branches(3).Stat(1),0);
   [pf_7,pf_8] =  Plot_Static_Field_Spectrums(CaF_Branches(4).Stat(1),0);
   
   figure('Name','Fields_Spectrums');
   CF = conFigure([pb_1,pb_2,pf_1,pf_2,pf_3,pf_4,pf_5,pf_6,pf_7,pf_8],5,3, 'UniformPlots', true, 'Height', 25, 'Width',20,'Labels',false);
   
%%
    Plot_LLE_Bloch_Static_Field_Stability(CaF_Branches(1).Stat(end-5),1);
    
%%
    ind1 = 5;
    [p_wh_1,p_wh_2,p_wh_3]           = Plot_LLE_Bloch_Static_Branch(CaF.CW,CaF_1D_Upper.Stat,CaF_1D_Lower.Stat,0,1,CaF.Stat.In.mu_bl,CaF_1D_Upper(1).Stat(ind1));
    [p_dot_1,p_dot_2]                = Plot_Static_Field_Spectrums(CaF_1D_Lower(1).Stat(1),0);
    [tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,tt_7,tt_8,tt_9,tt_10,tt_12,tt_13,tt_14,tt_15] = Plot_LLE_Bloch_Static_Field_Stability(CaF_1D_Upper(1).Stat(ind1),0);
    
    figure('Name','Fields_Spectrums');
    CF = conFigure([p_wh_1,p_wh_2,p_wh_3,p_dot_1,p_dot_2,tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,tt_7,tt_8,tt_9,tt_10,tt_12,tt_13,tt_14,tt_15],5,4, 'UniformPlots', true, 'Height', 20, 'Width',40,'Labels',false);
    
    
         
%%

Plot_LLE_Bloch_Static_Multiple_Branches(CaF_Branches(1).CW,CaF_Branches(1).Stat(1),CaF_Branches(2),1);

%%
ind_br   = 1;
ind_stat = 1;
figure;
Plot_LLE_Bloch_Static_Branch_Stability(CaF.CW,CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(ind_br),1);

%%  
ind_br = 1;
ind_stat = 58;
Plot_Static_Field_Spectrums(CaF_Branches(ind_br).Stat(ind_stat),1);
%Plot_LLE_Bloch_Static_Field_Stability(CaF_Branches_4(ind_br).Stat(ind_stat),1);
%%
    Plot_Bloch_Static_Branch_Save_Points(CaF_Branches_8(1),20);
%%

    Path = 'C:\Users\dp710\Documents\Data_Storage\Static\Scan_from_2.5\mu=2\branch1\';
    tic
    Plot_Bloch_Static_Branch_Save_Points(CaF_Branches,50,Path,1);
    toc
%%
t = tiledlayout(2,2,'TileSpacing','none','Padding','none');
[X,Y,Z] = peaks(20);
surf(X,Y,Z,'Parent',ax(1));
contour(X,Y,Z,'Parent',ax(2));
imagesc(Z,'Parent',ax(3));
plot3(X,Y,Z,'Parent',ax(4));
%% for mu = 1
    figure('Position',[0,0,1400,900],'Color',[1,1,1]);
    Panel = tiledlayout(3,8,'TileSpacing','none','Padding','none');
    ax(1) = nexttile(Panel,1,[1,2]);  
    ax(2) = nexttile(Panel,3,[1,2]); 
    
    ax(3) = nexttile(Panel,9,[1,1]);  
    ax(4) = nexttile(Panel,10,[1,1]);  
    
    ax(5) = nexttile(Panel,11,[1,2]);  
    ax(6) = nexttile(Panel,17,[1,2]);  
    ax(7) = nexttile(Panel,19,[1,2]);  
    
    ax(8) = nexttile(Panel,13,[1,2]);  
    ax(9) = nexttile(Panel,15,[1,2]);  
    ax(10) = nexttile(Panel,21,[1,2]);  
    ax(11) = nexttile(Panel,23,[1,2]);  

    ax(12) = nexttile(Panel,5,[1,2]);  
    ax(13) = nexttile(Panel,7,[1,2]);  
    for i =1:size(ax,2)
        hold(ax(i),'on');
    end
    ind_br   = 1;
    ind_stat = 40;
        
    Plot_LLE_Bloch_Static_Multiple_Branches(CaF_Branches(ind_br).CW(1),CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(1:end),ax(1:2));
    Plot_Static_Field_Spectrums(CaF_Branches(ind_br).Stat(ind_stat),ax(3:4));   
    Plot_LLE_Bloch_Static_Field_Stability(CaF_Branches(ind_br).Stat(ind_stat),[ax(5:11)]);
    Plot_LLE_Bloch_Static_Branch_Stability(CaF.CW,CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(ind_br),ax(12:13));

%% for mu = 2,3
    figure('Position',[0,0,1400,700],'Color',[1,1,1]);
    Panel = tiledlayout(3,16,'TileSpacing','none','Padding','none');
    ax(1) = nexttile(Panel,1,[1,4]);  
    ax(2) = nexttile(Panel,5,[1,4]); 
    
    ax(3) = nexttile(Panel,17,[1,2]);  
    ax(4) = nexttile(Panel,19,[1,2]);  
   
    ax(5) = nexttile(Panel,21,[1,4]);  
    ax(6) = nexttile(Panel,33,[1,4]);  
    ax(7) = nexttile(Panel,37,[1,4]);  
    
    ax(8) = nexttile(Panel,25,[1,2]);  
    ax(9) = nexttile(Panel,27,[1,2]);  
    ax(10) = nexttile(Panel,29,[1,2]);  
    ax(11) = nexttile(Panel,31,[1,2]); 
    
    ax(12) = nexttile(Panel,41,[1,2]);  
    ax(13) = nexttile(Panel,43,[1,2]);  
    ax(14) = nexttile(Panel,45,[1,2]);  
    ax(15) = nexttile(Panel,47,[1,2]);  

    ax(16) = nexttile(Panel,9,[1,2]);  
    ax(17) = nexttile(Panel,11,[1,2]);  
    ax(18) = nexttile(Panel,13,[1,2]);  
    ax(19) = nexttile(Panel,15,[1,2]);  
    
    for i =1:size(ax,2)
        hold(ax(i),'on');
    end
    ind_br   = 1;
    ind_stat = 40;
        
    Plot_LLE_Bloch_Static_Multiple_Branches(CaF_Branches(ind_br).CW(1),CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(1:end),ax(1:2));
    Plot_Static_Field_Spectrums(CaF_Branches(ind_br).Stat(ind_stat),ax(3:4));   
    Plot_LLE_Bloch_Static_Field_Stability(CaF_Branches(ind_br).Stat(ind_stat),[ax(5:15)]);
    Plot_LLE_Bloch_Static_Branch_Stability(CaF.CW,CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(ind_br),ax(16:19));
%%

