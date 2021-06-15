% Res.Stat           = Res.Stat(1);
% Res.Stat.In        = Res.Temp.In;
% Res.Stat.Sol.Psi_o = Res.Temp.Sol.Psio(end-1,:);
% Res.Stat.Sol.Psi_e = Res.Temp.Sol.Psie(end-1,:);
% Res.Stat.Sol.V     = 0;
% Res.Stat.Stab      = [];
% Res.Stat.Logic     = [];
%%
% $x^2+e^{\pi i}$

%%
    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd_FR_OPO;
    Res.CW.In.eps     = Res.CW.In.ko*0;%-Res.CW.In.ko*10;
    Res.CW.In.delta_o = -Res.CW.In.ko*0;
    Res.CW.In.N       = 2^8;
    Res.CW.In.W       = 1E3*Res.CW.In.Ws_Star;
    Res.CW.In.mu_bl   = 1;
    
    
%%
    
    Res.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    Res.Temp.Par.dt            = 5E-5;
    Res.Temp.Par.s_t           = 0.01;
    Res.Temp.Par.T             = 50;
    
    Res.Temp.Par.dd            = Res.Temp.Par.T/Res.Temp.Par.s_t;
    Res.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(Res.Temp.Par);
    
 %%
    NN =1;
    for i = 1:NN
        
        ResSave(i) = Res;
        
        ResSave(i).CW            = Chi2_CW_OPOSingleField(Res.CW);
        
        ResSave(i).Temp.In       = ResSave(i).CW.In;
        
        ResSave(i).Temp          = ResSave(i).Temp.Met.Norm(ResSave(i).Temp);   
        ResSave(i).Temp          = Chi23_Temp_Start_CW(ResSave(i).Temp,ResSave(i).CW);
        
        ResSave(i).Temp.Met      = [];

        tic
        ResSave(i).Temp.Sol      = Chi23OPO_Runge_Kuarong_mex(ResSave(i).Temp,Runge);
        toc
    end
%%
  
    
%   Res.Stat.Stab          = Stability_Switcher(Res.Stat);
%%
        Plot_Res_temp(ResSave(1));   
%
%%
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
