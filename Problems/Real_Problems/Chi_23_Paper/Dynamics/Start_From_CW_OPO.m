%%
    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = Res.CW.In.ko;%-Res.CW.In.ko*10;
    Res.CW.In.delta_o = Res.CW.In.ko;
    Res.CW.In.N       = 2^7;
    Res.CW.In.kMI     = [0:30];
    
%%
    
    Res.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    Res.Temp.Par.dt            = 2E-5;
    Res.Temp.Par.s_t           = 0.01;
    Res.Temp.Par.T             = 20;
    
    Res.Temp.Par.dd            = Res.Temp.Par.T/Res.Temp.Par.s_t;
    Res.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(Res.Temp.Par);
    
 %%
 eps_vector = [10]*Res.CW.In.ko;
 
 for ieps = 1:size(eps_vector,2)
     
    Res.CW.In.eps = eps_vector(ieps);
    
    SPEPS = strcat('/home/dp710/DataGit/Chi23/Dynamics/CWScans/NoOPOStartEps',num2str(eps_vector(ieps)/Res.CW.In.ko),'/');
    
    dd = [-13:0.1:32]; 
    W  = [3.5,5.5,7.5].^2*Res.CW.In.ko.^2/Res.CW.In.gam2o.^2/Res.CW.In.eta/Res.CW.In.Finess_e*pi/Res.CW.In.Ws_Star;
    
    for ip = 1:size(W,2)
        
        NN = size(dd,2);
        SP = strcat(SPEPS,'Power',num2str(round(W(ip))),'/');
        
        for iCW = 1:1

            switch iCW

            case 1

                Res.CW.In.W = Res.CW.In.Ws_Star*W(ip);

            case 2

                Res.CW.In.W = Res.CW.In.Ws_Star*W;

            case 3

                Res.CW.In.W = Res.CW.In.Wf_Star*W*15.5;

            end               
            parfor id = 1:NN

                R                 = Res;
                R.CW.In.delta_o   = (R.CW.In.ko*dd(id)+R.CW.In.eps)/2;            
                Run(id) = CreateStartingPoints(R,id,iCW,SP);


            end
            Rn(ieps).R(ip).RunD = Run;
        end
    end
 end
%%    
    p = gcp;
    for ieps =1:size(eps_vector,2)
        SPEPS = strcat('/home/dp710/DataGit/Chi23/Dynamics/CWScans/NoOPOStartEps',num2str(eps_vector(ieps)/Res.CW.In.ko),'/');
        
        for iCW = 1:1
            
            for ip =1:size(W,2)            
                SP = strcat(SPEPS,'Power',num2str(round(W(ip))),'/');
                
                indRun = find(Rn(ieps).R(ip).RunD==0);
                parfor id = 1:size(indRun,2)
                    
                     RunStartingPoints(indRun(id),iCW,SP);
                    
                end    
                
                indRun = find(Rn(ieps).R(ip).RunD>0);
                parfor id = 1:size(indRun,2)
                    
                     RunStartingPoints(indRun(id),iCW,SP);
                    
                end    
            end
        end
        
    end
     


%%
function RunStartingPoints(id,iCW,SPS)
    warning('off')
    switch iCW
        
        case 1
            
            SP = strcat(SPS,'SinOPO/Out/');
            SPI = strcat(SPS,'SinOPO/In/');
            if ~exist(SP,'dir')
                mkdir(SP)
            end
            
            
            
        case 2
            
            SP = strcat(SPS,'DbOPO/Out/');
            SPI = strcat(SPS,'DbOPO/In/');
            if ~exist(SP,'dir')
                mkdir(SP)
            end
            
            
        case 3
            
            SP = strcat(SPS,'SH/Out/');
            SPI = strcat(SPS,'SH/In/');
            if ~exist(SP,'dir')
                mkdir(SP)
            end
            
            
    end
    
    ResSave = importdata(strcat(SPI,num2str(id),'.mat'));
    
    Runge                      = Define_Runge_Coeff(ResSave.Temp.Par);

    ResSave.Temp.In       = ResSave.CW.In;

    ResSave.Temp          = ResSave.Temp.Met.Norm(ResSave.Temp);   
    ResSave.Temp          = Chi23_Temp_Start_CW(ResSave.Temp,ResSave.CW);

    ResSave.Temp.Met      = [];
    
    if isnan(ResSave.CW.Sol.Psi_o)
        save(strcat(SP,num2str(id)),'ResSave'); 
    else
        if max(max(real(ResSave.CW.Stab.Value))) > 0
            switch iCW

                case 1

                    tic
                    ResSave.Temp.Sol      = Chi23OPO_Runge_Kuarong_mex(ResSave.Temp,Runge);
                    iCW
                    id
                    toc

                case 2

                    ResSave.Temp.In = rmfield(ResSave.Temp.In,'Deltasmu');
                    ResSave.Temp.In = rmfield(ResSave.Temp.In,'Deltafmu');
                    ResSave.Temp.In = rmfield(ResSave.Temp.In,'g_mu');

                    ResSave.CW.In = rmfield(ResSave.CW.In,'Deltasmu');
                    ResSave.CW.In = rmfield(ResSave.CW.In,'Deltafmu');
                    ResSave.CW.In = rmfield(ResSave.CW.In,'g_mu');

                    ResSave.CW.Sol = rmfield(ResSave.CW.Sol,'PsiF');
                    ResSave.CW.Sol = rmfield(ResSave.CW.Sol,'PsiS');
                    ResSave.CW.Sol = rmfield(ResSave.CW.Sol,'expA');
                    tic
                    ResSave.Temp.Sol      = Chi23OPO_Runge_Kuarong_mex(ResSave.Temp,Runge);
                    iCW
                    id
                    toc

                case 3


                    tic
                    ResSave.Temp.Sol      = Chi23_Runge_Kuarong_mex(ResSave.Temp,Runge);
                    iCW
                    id
                    toc

            end
        end
        save(strcat(SP,num2str(id)),'ResSave'); 
    end
end
function Run =  CreateStartingPoints(R,id,iCW,SP)


    switch iCW
        
        case 1
            
            R.CW.In.mu_bl   = 0;
            R.CW            = Chi2_CW_OPOSingleField(R.CW);
            R.CW.Stab       = Chi23_MI(R.CW);
            SP = strcat(SP,'SinOPO/In/');
            
            if ~exist(SP,'dir')
                mkdir(SP)
            end
            
            save(strcat(SP,num2str(id),'.mat'),'R');
            
        case 2
            
            R.CW.In.mu_bl   = 0;
            R.CW            = Chi23_Stat_OPO_AnalyticsTurings(R.CW);
            
            R.CW.Sol.Psi_o  = R.CW.Sol.PsiF(1);
            R.CW.Sol.Psi_e  = R.CW.Sol.PsiS(1);
            
            R.CW.Stab       = Chi23_MI(R.CW);

            SP = strcat(SP,'DbOPO/In/');
            
            if ~exist(SP,'dir')
                mkdir(SP)
            end
            
            save(strcat(SP,num2str(id)),'R');
            
        case 3
            
            R.CW.In.mu_bl   = 0;
            
            R.CW            = Chi2_CW(R.CW);
                        
            [~,ind] = max(R.CW.Sol.g);

            R.CW.Sol.Omega    = R.CW.Sol.Omega(ind);        
            R.CW.Sol.Psi_o    = R.CW.Sol.Psi_o(ind);
            R.CW.Sol.Psi_e    = R.CW.Sol.Psi_e(ind);
            R.CW.Sol.g        = R.CW.Sol.g(ind);        
              
            R.CW.Stab         = Chi23_MI(R.CW);
            SP = strcat(SP,'SH/In/');
            
            if ~exist(SP,'dir')
                mkdir(SP)
            end
            
            save(strcat(SP,num2str(id)),'R');
    end
    if  max(max(real(R.CW.Stab.Value))) > 0 
        Run = 1;
    else
        Run = 0;
    end

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
function Plot_Frog(ResSave,wd)
    
    
    a = max(abs(ResSave.Temp.Psi_o(end,:),2));
    U_Frog = zeros(ResSave.Temp.Space.N,ResSave.Temp.Space.N);
    for i = 1:ResSave.Temp.Space.N
        U_Frog(i,:) = fft(ResSave.Temp.Psi_o(end,:).*a.*exp(-(ResSave.Temp.Space.phi-ResSave.Temp.Space.phi(i)).^2/2/wd^2 ));
    end

end

function Plot_Res_temp(ResSave)

    indmu = 1;
    indt  = 1;
    ind_t = [size(ResSave.Temp.Sol.Psio,1)/2+1:1:size(ResSave.Temp.Sol.Psio,1)];
    Nt    = size(ind_t,2);
    T     = ( ResSave(indt).Temp.Sol.t(ind_t(end)) - ResSave(indt).Temp.Sol.t(ind_t(1)) );
    dt    =   ResSave(indt).Temp.Sol.t(ind_t(end)) - ResSave(indt).Temp.Sol.t(ind_t(end-1));
    
    f = 2*pi*ResSave(indt).Temp.Eq.norm/( ResSave(indt).Temp.Sol.t(ind_t(end)) - ResSave(indt).Temp.Sol.t(ind_t(1)) )/ResSave.Temp.In.ko*[0:Nt/2-1,-Nt/2:-1];
    
    PsiO = ifft(ResSave(indt).Temp.Sol.Psio,[],2);
    PsiE = ifft(ResSave(indt).Temp.Sol.Psie,[],2);
    
    PsiOt = zeros(Nt,ResSave(indt).Temp.Space.N);
    PsiEt = zeros(Nt,ResSave(indt).Temp.Space.N);
    
    for i = 1:ResSave(indt).Temp.Space.N
        
        PsiOt(:,i)    = ifft(ResSave(indt).Temp.Sol.Psio(ind_t,i)*ResSave(indt).Temp.Space.N );        
        PsiEt(:,i)    = ifft(ResSave(indt).Temp.Sol.Psie(ind_t,i)*ResSave(indt).Temp.Space.N );
        PowerOmuavg(i) = dt/T*sum(abs(ResSave(indt).Temp.Sol.Psio(ind_t,i)).^2);
        PowerEmuavg(i) = dt/T*sum(abs(ResSave(indt).Temp.Sol.Psie(ind_t,i)).^2);
        
    end
    
    figure('Position',[0,0,1000,800],'Color',[1,1,1]);
    
    Panel = tiledlayout(4,2,'TileSpacing','none','Padding','none');   
   
    ax(1) = nexttile(Panel,1,[1,2]);hold(ax(1),'on');  
    ax(2) = nexttile(Panel,3,[1,1]);hold(ax(2),'on');  
    ax(3) = nexttile(Panel,4,[1,1]);hold(ax(3),'on');  
    ax(4) = nexttile(Panel,5,[1,1]);hold(ax(4),'on');  
    ax(5) = nexttile(Panel,6,[1,1]);hold(ax(5),'on');  
    ax(6) = nexttile(Panel,7,[1,1]);hold(ax(6),'on');  
    ax(7) = nexttile(Panel,8,[1,1]);hold(ax(7),'on');  
    
  %  plot(ResSave(indt).Temp.Sol.t(1:end-1),  sum(abs(ResSave(indt).Temp.Sol.Psie(1:end-1,:)).^2,2),'Parent',ax(1),'Color',[0,1,0]);
  %  plot(ResSave(indt).Temp.Sol.t(1:end-1),  sum(abs(ResSave(indt).Temp.Sol.Psio(1:end-1,2:end)).^2,2),'Parent',ax(1),'Color',[1,0,0]);
    plot(ResSave(indt).Temp.Sol.t(1:end-1),  sum(abs(ResSave(indt).Temp.Sol.Psie(1:end-1,1)).^2,2),'Parent',ax(1),'Color',[0,1,0]);

   % ylim(ax(1),[0,sum(abs(ResSave(indt).Temp.Sol.Psio(end-1,:)).^2*1.4,2)])
    
    stem(fftshift(ResSave(indt).Temp.Space.k),fftshift(10*log10(abs(ResSave(indt).Temp.Sol.Psio(end-1,:)).^2 )),'Parent',ax(2),'Color',[1,0,0],'BaseValue',-100,'Marker','none'); 
    stem(fftshift(ResSave(indt).Temp.Space.k),fftshift(10*log10(abs(ResSave(indt).Temp.Sol.Psie(end-1,:)).^2 )),'Parent',ax(2),'Color',[0,1,0],'BaseValue',-100,'Marker','none'); 
    
    stem(fftshift(ResSave(indt).Temp.Space.k),fftshift(10*log10( PowerOmuavg)),'Parent',ax(3),'Color',[1,0,0],'BaseValue',-100,'Marker','none'); 
    stem(fftshift(ResSave(indt).Temp.Space.k),fftshift(10*log10( PowerEmuavg)),'Parent',ax(3),'Color',[0,1,0],'BaseValue',-100,'Marker','none'); 

    plot((ResSave(indt).Temp.Space.phi),abs(ifft(ResSave(indt).Temp.Sol.Psio(end-1,:)*ResSave(indt).Temp.Space.N)).^2 ,'Parent',ax(4),'Color',[1,0,0]); 
    plot((ResSave(indt).Temp.Space.phi),abs(ifft(ResSave(indt).Temp.Sol.Psie(end-1,:)*ResSave(indt).Temp.Space.N)).^2 ,'Parent',ax(5),'Color',[0,1,0]); 
    
    pcolor(fftshift(ResSave(indt).Temp.Space.k),fftshift(f),fftshift(fftshift(10*log10(abs(PsiOt).^2),1),2),'Parent',ax(6))
    pcolor(fftshift(ResSave(indt).Temp.Space.k),fftshift(f),fftshift(fftshift(10*log10(abs(PsiEt).^2),1),2),'Parent',ax(7))
    
    ax(1).XLabel.String = '$t,(s \cdot k_o)$';
    ax(1).YLabel.String = '$|\psi_\mu|^2$';
    
    ax(2).XLabel.String = 'Mode Number';
    ax(2).YLabel.String = 'Power (db)';
    
    ax(3).XLabel.String = 'Mode Number';
    ax(3).YLabel.String = 'Power (db)';
%   colorbar(ax(i));
    ax(3).YLim  = [-100,4];
    ax(2).YLim  = [-100,4];
    
    ax(3).XLim  = [-80,80];
    ax(2).XLim  = [-80,80];
    ax(5).XLim  = [-pi,pi];
    ax(4).XLim  = [-pi,pi];
    
    ax(6).XLim  = [-80,80];
    ax(7).XLim  = [-80,80];
    ax(6).YLim  = [-100,100];
    ax(7).YLim  = [-100,100];
    
    caxis(ax(6),[-100,4]);
    caxis(ax(7),[-100,4]);
    
   ff= figure('Position',[0,0,1000,800]/2,'Color',[1,1,1]);
    
   Panel1 = tiledlayout(1,2,'TileSpacing','none','Padding','none','Parent',ff);   
   axx(1) = nexttile(Panel1,1,[1,1]);hold(axx(1),'on');  
   axx(2) = nexttile(Panel1,2,[1,1]);hold(axx(2),'on');  
   
   pcolor(ResSave(indt).Temp.Space.phi,ResSave(indt).Temp.Sol.t(ind_t),abs(PsiO(ind_t,:)).^2,'Parent',axx(1));
   pcolor(ResSave(indt).Temp.Space.phi,ResSave(indt).Temp.Sol.t(ind_t),abs(PsiE(ind_t,:)).^2,'Parent',axx(2));
   
   for i = 1:size(ax,2)
      axes_Style(ax(i));
      shading(ax(i),'flat');
   end
   for i = 1:size(axx,2)
      axes_Style(axx(i));
      shading(axx(i),'interp');
   end

end    

function axes_Style(ax)

     ax.Box      = 'on';
     ax.FontSize = 15;
     ax.TickLabelInterpreter = 'latex';
     ax.XLabel.Interpreter   = 'latex';
     ax.YLabel.Interpreter   = 'latex';
     
end
%%
    
%%

function Temp = Chi23_Temp_Start_CW(Temp,CW)

    Temp.In.Psi_Start                 = 1E-2*ones(1,Temp.Space.N*2);
    Temp.In.Psi_Start(1)              = (CW.Sol.Psi_o)*Temp.Space.N;
    Temp.In.Psi_Start(Temp.Space.N+1) = (CW.Sol.Psi_e)*Temp.Space.N;
    Temp.In.t_start                   = 0;
    
end
