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
    
 
    CaF.CW.In         = CaF.Stat.In;
    CaF.CW.In.N_mode  = 2^8;

%% Stationary Coefficeints

    CaF.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    CaF.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    CaF.Stat.Met.Newton           = @fsolve;%'fsolve'
         
    CaF.Stat.Par.variable         = 'delta';  %%'Pump Power';
    CaF.Stat.Par.first_step       = 0.2; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.001;
    CaF.Stat.Par.step_inc         = 0.00;
    CaF.Stat.Par.step_dec         = 0.5;

    CaF.Stat.Par.bot_boundary     = -40; % bottom boundary for delta to search
    CaF.Stat.Par.top_boundary     =  602; % top boundary for delta to search

    CaF.Stat.Par.Stability        = 'Yes';
    CaF.Stat.Par.Newton_iter          = 30;      
    CaF.Stat.Par.Newton_tol           = 1E-10;  
    CaF.Stat.Par.i_max                = 1000;
    
    CaF.Stat.Par.fsolveoptions       = optimoptions('fsolve','CheckGradients',...
    false,'Display','iter','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);
%  
%%
    
%    W_WStar             = 2.25;
    W_WStar             = 25;%25;
    CaF.Stat.In.P       = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma;
    CaF.CW.In.P         = W_WStar*pi/(CaF.Stat.In.eta*CaF.Stat.In.D(1)/CaF.Stat.In.kappa)*CaF.Stat.In.kappa/CaF.Stat.In.gamma; 
   CaF.Stat.In.mu_bl   = 4;    
   Index_Start         = [1,3];%1,
   Delta_Start         = [1.63,4.3]*CaF.Stat.In.kappa;%9.7,   
   CaF_Branches_4        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
%%    
    CaF.Stat.In.mu_bl   = 3;    
    Index_Start         = [3,4,5];%1,
    Delta_Start         = [-0.7,4.3,2]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches_3        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);

%%    
%    CaF.Stat.Par.first_step       = 0.01; % step for delta measured in delta/kappa
 %   CaF.Stat.Par.step_tol         = 0.001;

   CaF.Stat.In.mu_bl   = 2;
   Index_Start         = [3,4,6,7];%1,
    Delta_Start         = [3.4,3.4,5,4.4]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches_2        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    
    CaF.Stat.Par.first_step       = 0.1; % step for delta measured in delta/kappa
    CaF.Stat.Par.step_tol         = 0.001;
    Index_Start         = [5];%1,
    Delta_Start         = [4.4]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches_2(end+1)        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);
    

%%
    CaF.Stat.In.mu_bl   = 1;    
    Index_Start         = [1,2,3,4,5,6,7];%1,
    Delta_Start         = [1.9,1.5,1.4,2.1,1.81,1.38,1.9]*CaF.Stat.In.kappa;%9.7,   
    CaF_Branches        = Chi3_Stat_Get_Branch_Turing(CaF,Delta_Start,Index_Start);

%%
    figure('Position',[0,0,1400,900]/2,'Color',[1,1,1]);

    Panel = tiledlayout(2,2,'TileSpacing','none','Padding','none');
    for i = 1:4
        
        ax(i) = nexttile(Panel,i,[1,1]);  
        hold(ax(i),'on');
            
    end
    ind_br   = 3;
    ind_stat = 10;

    Plot_LLE_Bloch_Static_Multiple_Branches(CaF_Branches_2(ind_br).CW(1),CaF_Branches_2(ind_br).Stat(ind_stat),CaF_Branches_2(1:end),ax(1:4));
    Plot_Static_Field_Spectrums(CaF_Branches_2(ind_br).Stat(ind_stat),ax(3:4));   

%%
    figure('Position',[0,0,1400,900],'Color',[1,1,1]);

    Panel = tiledlayout(2,3,'TileSpacing','none','Padding','none');
    
    for i = 1:6
        
        ax(i) = nexttile(Panel,i,[1,1]);  
        hold(ax(i),'on');
            
    end
    ind_br   = 5;
    ind_stat = 5;
        
%    Plot_LLE_Bloch_Static_Multiple_Branches(CaF_Branches(ind_br).CW(1),CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(1:end),ax(1:2));
%    Plot_Static_Field_Spectrums(CaF_Branches(ind_br).Stat(ind_stat),ax(3:4));   
        Plot_LLE_Bloch_Static_Branch_Stability(CaF.CW,CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(ind_br),ax(1:6));
%%
    Path = 'C:\Users\dp710\Documents\Data_Storage\Static\Scan_from_25\mu=2\branch1\';
    tic
    Plot_Bloch_Static_Branch_Save_Points(CaF_Branches_2,24,Path,1);
    toc
    Path = 'C:\Users\dp710\Documents\Data_Storage\Static\Scan_from_25\mu=2\branch2\';
    tic
    Plot_Bloch_Static_Branch_Save_Points(CaF_Branches_2,50,Path,2);
    toc
    Path = 'C:\Users\dp710\Documents\Data_Storage\Static\Scan_from_25\mu=2\branch3\';
    tic
    Plot_Bloch_Static_Branch_Save_Points(CaF_Branches_2,50,Path,3);
    toc
    Path = 'C:\Users\dp710\Documents\Data_Storage\Static\Scan_from_25\mu=2\branch4\';
    tic
    Plot_Bloch_Static_Branch_Save_Points(CaF_Branches_2,50,Path,4);
    toc
    Path = 'C:\Users\dp710\Documents\Data_Storage\Static\Scan_from_25\mu=2\branch5\';
    tic
    Plot_Bloch_Static_Branch_Save_Points(CaF_Branches_2,50,Path,5);
    toc
%%
    Path = 'C:\Users\dp710\Documents\Data_Storage\Static\Scan_from_25\mu=3\branch1\';
    tic
    Plot_Bloch_Static_Branch_Save_Points(CaF_Branches_3,50,Path,1);
    toc
    Path = 'C:\Users\dp710\Documents\Data_Storage\Static\Scan_from_25\mu=3\branch2\';
    tic
    Plot_Bloch_Static_Branch_Save_Points(CaF_Branches_3,50,Path,2);
    toc
    Path = 'C:\Users\dp710\Documents\Data_Storage\Static\Scan_from_25\mu=3\branch3\';
    tic
    Plot_Bloch_Static_Branch_Save_Points(CaF_Branches_3,50,Path,3);
    toc
