% Res.Stat.Logic     = [];
%%
% $x^2+e^{\pi i}$

%%
    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = 100*Res.CW.In.ko;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 2^8;
    Res.CW.In.W       = 1E6*Res.CW.In.W_Star;
    Res.CW.In.mu_bl   = 1;
    Res.CW.In.kMI     = [1:30];
  %%
    
    Res.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    Res.Temp.Par.dt            = 1E-5;
    Res.Temp.Par.s_t           = 0.01;
    Res.Temp.Par.T             = 50;
    
    Res.Temp.Par.dd            = Res.Temp.Par.T/Res.Temp.Par.s_t;
    Res.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(Res.Temp.Par);
    
 %%
 
    NN                = 210;
    delta_vector      = linspace(50,56,NN);
    Power_vector      = ones(1,NN)*Res.CW.In.W /   Res.CW.In.W_Star;
    delta_stary       = 50*ones(1,NN);
    ii                = 0;
    
    parfor i =1:NN
        R = Res;
        W                 = [R.CW.In.W/R.CW.In.W_Star,Power_vector(i)];
        delta             = [delta_stary(i),delta_vector(i)];
        [R.CW,U] = Chi23_CW_TrackToPoint(R.CW,W,delta,1E3);
        US(i) =  U.PsiE(end);
        R.CW.Stab       = Chi23_MI(R.CW);
        RR(i) = R;
    end
    for i=1:NN
       if max(max(real(RR(i).CW.Stab.Value))) > 1E-3
          ii = ii+1;
          ResSave(ii) = RR(i);
       end
    end    
%%    
  PP = strcat('/home/dp710/DataGit/Chi23/Dynamics/CWScans/eps=',num2str( Res.CW.In.eps/ Res.CW.In.ko),'_Power=1E6/CHI3/');
  if ~exist(PP,'dir')
      mkdir(PP);
  end
  parfor i =1:size(ResSave,2)
       RunDynamicsInParFor(ResSave(i),PP,i,Runge)
       i
  end
%%
%  PP = '/home/dp710/DataGit/Chi23/Dynamics/CWScans/eps=50_Delta=25/CHI3/';

for i =1:1785
    load(strcat(PP,num2str(i)));
    dd(i)   = ResSave.CW.Eq.delta_o;
    Psie(i,:)    = abs(ResSave.CW.Sol.Psi_e);
    PsieT(i,:) = ResSave.Temp.Sol.Psio(end-1,:);
    PsioT(i,:) = ResSave.Temp.Sol.Psie(end-1,:);
    i
end
%%
for i =1:801
    
%    load(strcat(PP,num2str(i)));
    dd(i)   = RR(i).CW.Eq.delta_o;
    Psie(i,:)    = abs(RR(i).CW.Sol.Psi_e);
%    PsieT(i,:) = ResSave.Temp.Sol.Psio(end-1,:);
 %   PsioT(i,:) = ResSave.Temp.Sol.Psie(end-1,:);
  %  i
end
     
%%
   Res.Stat.In           = Res.CW.In;
    Res.Stat.Par          = Res.CW.Par;
    
    Res.Stat.In.N         = 2^9;
    Res.Stat.Met.Newton   = @Newton_Manual_bicgstab;%'fsolve'
    
    Res.Stat              = Res.Stat.Met.Norm(Res.Stat);
    
    Res.Stat.Sol.Psi_o    = 1E-10*ones(1,Res.Stat.Space.N);
    Res.Stat.Sol.Psi_e    = 1E-10*ones(1,Res.Stat.Space.N);
    
%    Res.Stat.Sol.Psi_o(1) = Res.Temp.Sol.Psio(end-1,1)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_o(2) = Res.Temp.Sol.Psio(end-1,1+13)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_o(3) = Res.Temp.Sol.Psio(end-1,1+13*2)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_o(4) = Res.Temp.Sol.Psio(end-1,1+13*3)*Res.Stat.Space.N;
%     
%     Res.Stat.Sol.Psi_e(1) = Res.Temp.Sol.Psie(end-1,1)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_e(2) = Res.Temp.Sol.Psie(end-1,1+13)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_e(3) = Res.Temp.Sol.Psie(end-1,1+13*2)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_e(4) = Res.Temp.Sol.Psie(end-1,1+13*3)*Res.Stat.Space.N;
%         
%     Res.Stat.Sol.Psi_o(end) = Res.Temp.Sol.Psio(end-1,end-13+1)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_o(end-1) = Res.Temp.Sol.Psio(end-1,end-13*2+1)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_o(end-2) = Res.Temp.Sol.Psio(end-1,end-13*3+1)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_o(end-3) = Res.Temp.Sol.Psio(end-1,end-13*4+1)*Res.Stat.Space.N;
%     
%     Res.Stat.Sol.Psi_e(end) = Res.Temp.Sol.Psie(end-1,end-13+1)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_e(end-1) = Res.Temp.Sol.Psie(end-1,end-13*2+1)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_e(end-2) = Res.Temp.Sol.Psie(end-1,end-13*3+1)*Res.Stat.Space.N;
%     Res.Stat.Sol.Psi_e(end-3) = Res.Temp.Sol.Psie(end-1,end-13*4+1)*Res.Stat.Space.N;

    Res.Stat.Sol.Psi_o = Res.Temp.Sol.Psio(end-1,:)*Res.Stat.Space.N;
    Res.Stat.Sol.Psi_e = Res.Temp.Sol.Psie(end-1,:)*Res.Stat.Space.N;

    Slv_Start             = [real(Res.Stat.Sol.Psi_o),imag(Res.Stat.Sol.Psi_o)...
                    ,real(Res.Stat.Sol.Psi_e),imag(Res.Stat.Sol.Psi_e),0.];
                
    [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Res.Stat);
    
    Res.Stat.Sol.Psi_o   = (Slv(1:Res.Stat.Space.N) + 1i*Slv(Res.Stat.Space.N+1:2*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.Psi_e   = (Slv(2*Res.Stat.Space.N+1:3*Res.Stat.Space.N) + 1i*Slv(3*Res.Stat.Space.N+1:4*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.V       =  Slv(end);
    
%   Res.Stat.Stab          = Stability_Switcher(Res.Stat);
%%
    for i =1:1
        Plot_Res_temp(ResSave(4));   
    end
%% гауссов импульс умножить на кусок пси потом фурье (фу) (функция вигнера xfrog) 

%%

    for i = 3:9

        Plot_Res_temp(Res(i));
        h = gcf; 
        print(strcat(num2str(i)),'-dpng','-r450');

    end
    %%
    for i = 1:8
      delta_150(i) = Res(i).Temp.In.delta_o/Res(i).Temp.In.ko;
      conv_eff_eps_150(i) = sum(abs(Res(i).Temp.Sol.Psie(end-1,:)).^2)/sum(abs(Res(i).Temp.Sol.Psio(end-1,:)).^2);
      
      delta_100(i) = ReSS(i).Temp.In.delta_o/ReSS(i).Temp.In.ko;
      conv_eff_eps_100(i) = sum(abs(ReSS(i).Temp.Sol.Psie(end-1,:)).^2)/sum(abs(ReSS(i).Temp.Sol.Psio(end-1,:)).^2);
    end
%%
function Plot_Frog(ResSave,wd)
    
    
    a = max(abs(ResSave.Temp.Psi_o(end,:),2));
    U_Frog = zeros(ResSave.Temp.Space.N,ResSave.Temp.Space.N);
    for i = 1:ResSave.Temp.Space.N
        U_Frog(i,:) = fft(ResSave.Temp.Psi_o(end,:).*a.*exp(-(ResSave.Temp.Space.phi-ResSave.Temp.Space.phi(i)).^2/2/wd^2 ));
    end

end
function RunDynamicsInParFor(ResSave,PP,isim,Runge)
        i = 1;
        ResSave(i).Temp.In        = ResSave(i).CW.In;
        ResSave(i).Temp.In.N     = 2^8;
        ResSave(i).Temp          = ResSave(i).Temp.Met.Norm(ResSave(i).Temp);   
        ResSave(i).Temp          = Chi23_Temp_Start_CW(ResSave(i).Temp,ResSave(i).CW);
        
        ResSave(i).Temp.Met      = [];

        tic
        ResSave(i).Temp.Sol      = Chi23_Runge_Kuarong_mex(ResSave(i).Temp,Runge);
        toc
        save(strcat(PP,num2str(isim)),'ResSave');
end
function Plot_Res_temp(ResSave)

    indmu = 2^8-6+1;
    indt  = 1;
    ind_t = [1:1:2500];
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
    plot(ResSave(indt).Temp.Sol.t(1:end-1),  sum(abs(ResSave(indt).Temp.Sol.Psio(1:end-1,indmu)).^2,2),'Parent',ax(1),'Color',[1,0,0]);
    plot(ResSave(indt).Temp.Sol.t(1:end-1),  sum(abs(ResSave(indt).Temp.Sol.Psie(1:end-1,indmu)).^2,2),'Parent',ax(1),'Color',[1,0,0]);

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
   figure;pcolor(ResSave(indt).Temp.Space.phi,ResSave(indt).Temp.Sol.t(ind_t),abs(PsiO(ind_t,:)).^2);shading interp;
   for i = 1:size(ax,2)
      axes_Style(ax(i));
      shading(ax(i),'flat');
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
