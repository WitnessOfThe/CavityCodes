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
    
    R.Stat.In.mu_bl     = 14;
    
    R.Stat.In.P       = R.Stat.In.W_WStar*pi/(R.Stat.In.eta*R.Stat.In.D(1)...
                        /R.Stat.In.kappa)*R.Stat.In.kappa/R.Stat.In.gamma;    
                    
    R.CW.In           = R.Stat.In;
    R.Stat.Par.Newton_tol       = 3E-11;         
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    R.Stat.In.N_mode  = 2^4;
    R.CW.In.N_mode    = 2^8;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Path Control

    MP  = '/home/dp710/GitHubData/CHICrystals/';
%    SP  = Chi3_CrystalPathGenerator(R.Stat,MP);
%% Create Many Crystals

    R.Stat.Par.CW_num   = 1;
    mu_vec              = [89];%46
    
    for imu =1:size(mu_vec,2)
        warning('off')
        RR = R;
        RR.Stat.In.mu_bl     = mu_vec(imu);
        RR.CW.In.mu_bl     = mu_vec(imu);        
        RR.Stat.Par.CW_num   = 1;
        Chi3_CrystalPathGenerator(RR.Stat,MP);
        [Stat(imu),Val(imu)] = Chi3_CrystalCreator(RR,MP,0);
        
    end
%% Create A Crystal

   Res = Chi3_CrystalCreator(R,MP,0);
 
%% ChangeFdOfTheCrystal

    Stat = Chi3_CrystalChangeParameter(R,MP,'FD');
    
%%    
    Chi3_CrystalChangeParameterFromParameter(strcat(SP,'FDScan/'),'delta');
    
%

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
    ResCrystal = Chi3_CrystalCollect2DData(MP,'FD');
%%  Call For Starters
    mu_vec              = [1:89];
    for imu =1:size(mu_vec,2)
        warning('off')
        R.Stat.In.mu_bl     = mu_vec(imu);
        SP  = Chi3_CrystalPathGenerator(R.Stat,MP);
        
        [Stat(imu)] = importdata(strcat(SP,'Starter.mat'));
    end
%%
   mu_vec              = [2:6,8:13,15:27,29:41,43:89];
    for imu =1:size(mu_vec,2)
        
        warning('off');
        RR = R;
        RR.Stat.In.mu_bl     = mu_vec(imu);
        SP  = Chi3_CrystalPathGenerator(RR.Stat,MP);     
        SS(imu).Stat = Chi3_CrystalChangeParameter(RR,MP,'FD');
%        Chi3_CrystalChangeParameterFromParameter(strcat(SP,'FDScan/'),'delta');

    end
%%
    mu_vec              = [1,7,14,28,14*3];
    for imu =1:size(mu_vec,2)
        
        warning('off');
        RR = R;
        RR.Stat.In.mu_bl     = mu_vec(imu);
        SP  = Chi3_CrystalPathGenerator(RR.Stat,MP);     
%        SS(imu).Stat = Chi3_CrystalChangeParameter(RR,MP,'FD');
        Chi3_CrystalChangeParameterFromParameter(strcat(SP,'FDScan/'),'delta');

    end

%%
    clear dd Peak
    for iSt =1:size(Stat,2)
        dd(iSt) = Stat(iSt).Eq.Fin_Dlog;
        Peak(iSt) = log10(Stat(iSt).Sol.eps_f);%log10(abs(Stat(iSt).Sol.Psi_k(2)).^2);
        Peak(iSt) = log10(abs(Stat(iSt).Sol.Psi_k(2)).^2);
    end
%
figure;plot(dd, Peak,'Marker','.')