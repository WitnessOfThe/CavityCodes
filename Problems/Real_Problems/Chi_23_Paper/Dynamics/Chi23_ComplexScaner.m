%%
    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = Res.CW.In.ko;%-Res.CW.In.ko*10;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 2^7;
    Res.CW.In.kMI     = [0:30];
    
%%    
    Res.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    Res.Temp.Par.dt            = 2E-5;
    Res.Temp.Par.s_t           = 0.05;
    Res.Temp.Par.T             = 200;    
    Res.Temp.Par.dd            = Res.Temp.Par.T/Res.Temp.Par.s_t;
    Res.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(Res.Temp.Par);
    
%%
    Res.Stat(1).Par.Newton_tol       = 1.5E-10;  
    Res.Stat(1).Par.Turning          =    0;
    Res.Stat(1).Par.variable         = 'delta_o';  %%'Pump Power';
    Res.Stat(1).Par.bot_boundary     = -1E8; % bottom boundary for delta to search in normalized units
    Res.Stat(1).Par.top_boundary     =  1E8; % top boundary for delta to search in normalized units
    
    Res.Stat(1).Par.Stability        = 0;
    
    Res.Stat(1).Par.Newton_iter      = 200;
    Res.Stat(1).Par.first_step       = 1E-2;
    Res.Stat(1).Par.max_step         = 1;
    Res.Stat(1).Par.step_dec         = 0.1;
    Res.Stat(1).Par.step_tol         = 1E-9;
    Res.Stat(1).Par.step_inc         = 1.1;  
    Res.Stat.Par.i_max               = 400;
 %%
     eps_vector = [-20]*Res.CW.In.ko;
%     W_vector   = [2E-6,2E-5,2E-4,2E-3]/Res.CW.In.Ws_Star;%
      W_vector   = [2E-3,2E-2,2E-1]/Res.CW.In.Ws_Star;%
     dd         = [-50:0.3:70];%[-13:0.1:32]; 

     SPRoot = strcat('/home/dp710/DataGit/Chi23/Dynamics/CWScans/OPOCasesChi3/');
     mu_vec = [0,1,20];%0,1,5
     
     for ieps = 1:size(eps_vector,2)

        Res.CW.In.eps = eps_vector(ieps);

        SPEPS = strcat(SPRoot,num2str(eps_vector(ieps)/Res.CW.In.ko),'/');

        for ip = 1:size(W_vector,2)

            NN = size(dd,2);

            Res.CW.In.W = Res.CW.In.Ws_Star*W_vector(ip);
            SPPower = strcat(SPEPS,'Power',num2str(round(Res.CW.In.W*1E6)),'/');

            for imu = 1:size(mu_vec,2)

                Res.CW.In.mu_bl = mu_vec(imu);
                SPMu = strcat(SPPower,'Mu=',num2str(round(Res.CW.In.mu_bl)),'/');
                
                parfor id = 1:NN
                    warning('off')
                    tic
                    R                     = Res;
                    R.CW.In.delta_o        = (R.CW.In.ko*dd(id)+R.CW.In.eps)/2;            
                    [Run(id),ResTest(id)]  = CreateStartingPoints(R,id,SPMu);
                    toc
                end

                Rn(ieps).R(ip).R(imu).RunD = Run;
                
            end
        end
     end
%%    
 for ieps = 1:size(eps_vector,2)

        Res.CW.In.eps = eps_vector(ieps);

        SPEPS = strcat(SPRoot,num2str(eps_vector(ieps)/Res.CW.In.ko),'/');

        for ip = 1:size(W_vector,2)

            NN = size(dd,2);

            Res.CW.In.W = Res.CW.In.Ws_Star*W_vector(ip);
            SPPower = strcat(SPEPS,'Power',num2str(round(Res.CW.In.W*1E6)),'/');

            for imu = 1:size(mu_vec,2)

                Res.CW.In.mu_bl = mu_vec(imu);
                SPMu = strcat(SPPower,'Mu=',num2str(round(Res.CW.In.mu_bl)),'/');
                
                
                indRun = find( Rn(ieps).R(ip).R(imu).RunD==0 | isnan(Rn(ieps).R(ip).R(imu).RunD));
                tic
                parfor in = 1:size(indRun,2)
                    
                     RunStartingPoints(indRun(in),SPMu,Rn(ieps).R(ip).R(imu).RunD(indRun(in)));
                    
                end    
                toc
                indRun = find( Rn(ieps).R(ip).R(imu).RunD==1);
                tic
                parfor in = 1:size(indRun,2)
                    
                     RunStartingPoints(indRun(in),SPMu,Rn(ieps).R(ip).R(imu).RunD(indRun(in)));
                    
                end    
                toc
                
            end
        end
 end
 %%
 for id =1:size(ResTest,2)
     ddelta(id) = ResTest(id).Stat.Eq.delta_e;
     if Run(id) ==1
         Psi_o(id,:) = ResTest(id).Stat.Sol.Psi_o;
     else 
         Psi_o(id,:) = zeros(1,128);
     end
 end
    figure;pcolor(ddelta,fftshift(ResTest(1).Stat.Space.k),10*log10(abs(fftshift(Psi_o,2)).^2).');shading interp     
%%
function [Run,R] =  CreateStartingPoints(R,id,SP)

    R.CW                 = Chi23_Stat_OPO_AnalyticsTurings(R.CW);
    R.Stat.In            = R.CW.In;
    [R.Stat,R.CW,Flag]   = Chi23_OPO_StartTuringFromAnal(R.CW,R.Stat);
    
    if Flag == 1
        
        R.Stat.Stab     = Stability_Switcher(R.Stat);
        
        if  max(max(real(R.Stat.Stab.E_values))) > 1E-4 
            
            Run = 1;

            R.Temp.In       = R.Stat.In;

            R.Temp          = R.Temp.Met.Norm(R.Temp);   
            R.Temp          = Chi23_StartFromBloch(R.Stat,R.Temp);
            
            R.Temp.Met      = [];
    
            R.Temp.In = rmfield(R.Temp.In,'Deltasmu');
            R.Temp.In = rmfield(R.Temp.In,'Deltafmu');

            R.CW.In = rmfield(R.CW.In,'Deltasmu');
            R.CW.In = rmfield(R.CW.In,'Deltafmu');

            R.CW.Sol = rmfield(R.CW.Sol,'PsiF');
            R.CW.Sol = rmfield(R.CW.Sol,'PsiS');
            R.CW.Sol = rmfield(R.CW.Sol,'expA');
            
        else
            
            Run = 0;
            
        end
        
    else
        
        Run             = NaN;
        
    end
    
    SP = strcat(SP,'In/');

    if ~exist(SP,'dir')
        
        mkdir(SP)
        
    end

    save(strcat(SP,num2str(id)),'R');


end

%%
function RunStartingPoints(id,SPS,Run)

    SI = strcat(SPS,'In/');
    SO = strcat(SPS,'Out/');
    
    ResSave = importdata(strcat(SI,num2str(id),'.mat'));
            Runge   = Define_Runge_Coeff(ResSave.Temp.Par);
    
    
    if Run == 1
        
        ResSave.Temp.Sol      = Chi23OPO_Runge_Kuarong_mex(ResSave.Temp,Runge);
        
    end
    if ~exist(SO,'dir')

        mkdir(SO);

    end

    save(strcat(SO,num2str(id)),'ResSave'); 
end

function SaveRes(ResSave)
        save(strcat('/home/dp710/DataGit/Chi23/Dynamics/OPOCWScansNew/eps0_power',num2str(ResSave(1).Temp.In.W/ResSave(1).Temp.In.Ws_Star)),'ResSave')
end
function ResSave = RunDyn(ResSave)

        i=1;
        Runge                      = Define_Runge_Coeff(ResSave(i).Temp.Par);
 
        ResSave(i).Temp.In       = ResSave(i).CW.In;
        
        ResSave(i).Temp          = ResSave(i).Temp.Met.Norm(ResSave(i).Temp);   
        ResSave(i).Temp          = Chi23_Temp_Start_CW(ResSave(i).Temp,ResSave(i).CW);
        
        ResSave(i).Temp.Met      = [];

        tic
        ResSave(i).Temp.Sol      = Chi23OPO_Runge_Kuarong_mex(ResSave(i).Temp,Runge);
        toc


end
%%
    
%%

function Temp = Chi23_Temp_Start_CW(Temp,CW)

    Temp.In.Psi_Start                 = 1E-2*ones(1,Temp.Space.N*2);
    Temp.In.Psi_Start(1)              = (CW.Sol.Psi_o)*Temp.Space.N;
    Temp.In.Psi_Start(Temp.Space.N+1) = (CW.Sol.Psi_e)*Temp.Space.N;
    Temp.In.t_start                   = 0;
    
end
