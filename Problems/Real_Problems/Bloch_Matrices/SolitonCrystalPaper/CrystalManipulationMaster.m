%% Crystal Manipulations

    clc;
    clear all;
    warning('off');
    
%% Define Input Parameters in Physical Units

    R                   = Set_Up_Methods_For_Bloch_Matrices;
    R.Stat.In           = Params_SiN_For_Crytal_Paper;    

    R.Stat.Par.CW_num   = 1;
    R.Stat.In.W_WStar   = 2;   
    
    Fd                  = 10^(-3);
    
    
    R.Stat.In.kappa     = R.Stat.In.D(2)/Fd;
    
    R.Stat.In.delta     = 1.95*R.Stat.In.kappa;   
    
    R.Stat.In.mu_bl     = 13;
    
    R.Stat.In.P       = R.Stat.In.W_WStar*pi/(R.Stat.In.eta*R.Stat.In.D(1)...
                        /R.Stat.In.kappa)*R.Stat.In.kappa/R.Stat.In.gamma;    
                    
    R.CW.In           = R.Stat.In;
    R.Stat.Par.Newton_tol       = 3E-10;         
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    R.Stat.In.N_mode  = 2^6;
    R.CW.In.N_mode    = 2^8;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Path Control

    MP  = '/home/dp710/GitHubData/CHICrystals/';
    SP  = Chi3_CrystalPathGenerator(R.Stat,MP);
%% Create Many Starting Crystals

  %  R.Stat.Par.CW_num   = 1;
    mu_vec              = [13];%46
    
    for imu =1:size(mu_vec,2)
        warning('off')
        RR = R;
        RR.Stat.In.mu_bl     = mu_vec(imu);
        RR.CW.In.mu_bl     = mu_vec(imu);        
        RR.Stat.Par.CW_num   = 3;
        Chi3_CrystalPathGenerator(RR.Stat,MP);
        [Stat(imu),Val(imu)] = Chi3_CrystalCreator(RR,MP,0);
        
    end
%% Create a single Crystal

   Res = Chi3_CrystalCreator(R,MP,0);
 
%% Change Parameter Of The Crystal

    Stat = Chi3_CrystalChangeParameter(R,MP,'FD');
%% Stability of Parameter
    Chi3_CrystalDoStabilityInFolder(strcat(SP,'FDScan/'));
%%  Make a scan From changed Parameter Point  
    
    Chi3_CrystalChangeParameterFromParameter(strcat(SP,'FDScan/'),'delta');
    
%% Make a Stability of ParameterParameter
    Chi3_CrystalDoStabilityInManyFolders(strcat(SP,'FDScan/'),'delta');
%%
   ResCrystal = Chi3_CrystalCollect2DData(strcat(SP,'FDScan/'),'delta');  
  %  ResCrystal = Chi3_CrystalCollect2DData('/home/dp710/DataGit/CHICrystals/CrystalMu=28_Fd=0.001_Delta=1.95_Power=2/FDScan/','delta');  
%%
    MP  = '/home/dp710/GitHubData/CHICrystals/mu=14DecreaseFd_From-2.2/';
    FDVec = 10.^(linspace(-2.1,-3,144));
    mkdir(MP)    
    Stat = Chi3_CrystalCreateStartingPointsNearBoundary(R,FDVec,MP);
%%
    Chi3_CrystalChangeParameterFromParameter(MP,'FD');
    %%
    Chi3_CrystalDoStabilityInManyFolders(MP,'FD');
    %%
    MP  = '/home/dp710/GitHubData/CHICrystals/';
    R.Stat.In.mu_bl     =14*3;       
    SP  = Chi3_CrystalPathGenerator(R.Stat,MP);
    
    ResCrystal = Chi3_CrystalCollect2DData(strcat(SP,'FDScan/'),'delta');
%%  Call For Starters
    mu_vec              = [1:89];
    for imu =1:size(mu_vec,2)
        warning('off')
        R.Stat.In.mu_bl     = mu_vec(imu);
        SP  = Chi3_CrystalPathGenerator(R.Stat,MP);
        
        [Stat(imu)] = importdata(strcat(SP,'Starter.mat'));
    end
%%
   mu_vec              = fliplr([1,7,14,28,14*3]);
   
    for imu =1:size(mu_vec,2)
        tic
        warning('off');
        RR = R;
        RR.Stat.In.mu_bl     = mu_vec(imu);
        SP                   = Chi3_CrystalPathGenerator(RR.Stat,MP);     
%        SS(imu).Stat = Chi3_CrystalChangeParameter(RR,MP,'delta');
%        Chi3_CrystalDoStabilityInFolder(strcat(SP,'FDScan/'));
         Chi3_CrystalDoStabilityInManyFolders(strcat(SP,'FDScan/'),'delta');
%         Chi3_CrystalDoStabilityInManyFolders(strcat(SP,'FDScan/','FD');

%        Crystals(imu).Tracks = Chi3_CrystalCollect1DData(strcat(SP,'FDScan/'));

%        Chi3_CrystalChangeParameterFromParameter(strcat(SP,'FDScan/'),'delta');
        imu
        toc
    end
    %%
      mu_vec              = 1;%;[7,13,27,29,43,59,60,78,73,83];
   
    for imu =1:size(mu_vec,2)
        tic
        warning('off');
        RR = R;
        RR.Stat.In.mu_bl     = mu_vec(imu);
        SP                   = Chi3_CrystalPathGenerator(RR.Stat,MP);     
 %       SS(imu).Stat = Chi3_CrystalChangeParameter(RR,MP,'delta');
    %   Chi3_CrystalDoStabilityInFolder(strcat(SP,'FDScan/'));
  %     Chi3_CrystalDoStabilityInFolder(strcat(SP,'deltaScan/'));
 %        Chi3_CrystalDoStabilityInManyFolders(strcat(SP,'FDScan/'),'delta');
%         Chi3_CrystalDoStabilityInManyFolders(strcat(SP,'FDScan/','FD');

%        Crystals(imu).Tracks = Chi3_CrystalCollect1DData(strcat(SP,'FDScan/'));
        Crystals = Chi3_CrystalCollect2DData(strcat(SP),'FDScan/','delta',25);

%        Chi3_CrystalChangeParameterFromParameter(strcat(SP,'FDScan/'),'delta');
        imu
        toc
    end
%%
 mu_vec              = [1:89];
   
    for imu =1:size(mu_vec,2)
        tic
        warning('off');
        RR = R;
        RR.Stat.In.mu_bl     = mu_vec(imu);
        SP                   = Chi3_CrystalPathGenerator(RR.Stat,MP);     
%        SS(imu).Stat = Chi3_CrystalChangeParameter(RR,MP,'delta');
%        Chi3_CrystalDoStabilityInFolder(strcat(SP,'FDScan/'));
%         Chi3_CrystalDoStabilityInManyFolders(strcat(SP,'FDScan/'),'delta');
%         Chi3_CrystalDoStabilityInManyFolders(strcat(SP,'FDScan/','FD');

%        Crystals(imu).Tracks = Chi3_CrystalCollect1DData(strcat(SP,'FDScan/'));
        Crystals(imu).Tracks = Chi3_CrystalCollect1DData(strcat(SP,'FDScan/'));

%        Chi3_CrystalChangeParameterFromParameter(strcat(SP,'FDScan/'),'delta');
        imu
        toc
    end
%%
 mu_vec              = fliplr([1,7,14,28,14*3]);
   
    for imu =1:size(mu_vec,2)

        R.Stat.In.mu_bl     = mu_vec(imu);%[1,7,14,28,14*3]
        SP                   = Chi3_CrystalPathGenerator(R.Stat,MP);    
        Chi3_CrystalCollect2DData(strcat(SP),'FDScan/','delta');
        
    end
%% StartDynamicsFromFolder
    Par.N  = 2^9;
    Par.NN = 200;
    Par.T  = 5E3;
    mu_vec              = [14,7,1];
    
    for i = 1:3
        
        R.Stat.In.mu_bl     = mu_vec(i);%[1,7,14,28,14*3]
        SP                  = Chi3_CrystalPathGenerator(R.Stat,MP);    
        Chi3_CrystalStartDynamicsFromMultiFolder(strcat(SP,'FDScan/'),'delta',Par);
        
    end
%% ReadDynamicsFolder

    Par.N  = 2^9;
    Par.NN = 200;
    Par.T  = 1;
    mu_vec              = [14,7,1];
%%    
    for i = 1:1
        
        R.Stat.In.mu_bl     = mu_vec(i);%[1,7,14,28,14*3]
        SP                  = Chi3_CrystalPathGenerator(R.Stat,MP);    
        Crystals = Chi3_CrystalReadDynamicsFromMultiFolder(strcat(SP,'FDScan/'),'delta');
        
    end
%%
    clear dd Peak;
    for iSt =1:size(Stat,2)
        dd(iSt) = Stat(iSt).Eq.Fin_Dlog;
        Peak(iSt) = log10(Stat(iSt).Sol.eps_f);%log10(abs(Stat(iSt).Sol.Psi_k(2)).^2);
        Peak(iSt) = log10(abs(Stat(iSt).Sol.Psi_k(2)).^2);
    end
%
figure;plot(dd, Peak,'Marker','.')