    clc;
    clear all;
    warning('off');
    
%% Define Input Parameters in Physical Units

    R                   = Set_Up_Methods_For_Bloch_Matrices;
    R.Stat.In           = Params_SiN_For_Crytal_Paper;    

    R.Stat.Par.CW_num   = 3;
    R.Stat.In.W_WStar   = 2;   
    
    Fd                  = 1E-3;
    
    
    R.Stat.In.kappa     = R.Stat.In.D(2)/Fd;
    
    R.Stat.In.delta     = 1.95*R.Stat.In.kappa;   
    
    R.Stat.In.mu_bl     = 14*2;
    
    R.Stat.In.P       = R.Stat.In.W_WStar*pi/(R.Stat.In.eta*R.Stat.In.D(1)...
                        /R.Stat.In.kappa)*R.Stat.In.kappa/R.Stat.In.gamma;    
                    
    R.CW.In           = R.Stat.In;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    R.Stat.In.N_mode  = 2^5;
    R.CW.In.N_mode    = 2^8;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Path Control

    MP  = '/home/dp710/DataGit/CHICrystals/';
    SP  = Chi3_CrystalPathGenerator(R.Stat,MP);
    
%% Create A Crystal

    Res = Chi3_CrystalCreator(R,MP);
 
%% ChangeFdOfTheCrystal

    Stat = Chi3_CrystalChangeParameter(R,MP,'FD');
    
%%    
    Chi3_CrystalChangeParameterFromParameter(strcat(SP,'FDScan/'),'delta');
    
%%

    Chi3_CrystalDoStabilityInManyFolders(strcat(SP,'FDScan/'),'delta');
%%
   ResCrystal = Chi3_CrystalCollect2DData(strcat(SP,'FDScan/'),'delta');  
%%
    clear dd Peak
    for iSt =1:size(Stat,2)
        dd(iSt) = Stat(iSt).Eq.Fin_Dlog;
        Peak(iSt) = abs(Stat(iSt).Sol.Psi_k(1)).^2;
    end
%
figure;plot(dd,Peak,'Marker','.')