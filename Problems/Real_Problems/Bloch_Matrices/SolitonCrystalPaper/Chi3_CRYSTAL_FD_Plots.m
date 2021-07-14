clc;
clear all
%%
    load('CrystalsRes.mat');
%
    f1 = figure('Position',[0,0,1400,900]/2,'Color',[1,1,1]);    
    ax(1) = axes('Parent',f1);  
    hold(ax(1),'on');
    
    for i = [1:88]
        
        plot(i*ones(size(S(i).PeakPower,2)),S(i).FD,'Parent',ax(1),'LineWidth',1,'LineStyle','-','Color',[0,0,1]);
        FD = S(i).FD;
        Peak = S(i).PeakPower;
        FD(~S(i).Stable) = NaN;
        Peak(~S(i).Stable) = NaN;
        plot(i*ones(size(S(i).PeakPower,2)),FD,'Parent',ax(1),'LineWidth',1,'LineStyle','-','Color',[0,0.,0.]);
        FD(~S(i).Stable) = [];
        if ~isempty(FD) 
            plot(i,FD(end),'Parent',ax(1),'Marker','.','MarkerSize',10,'Color',[0.64,0.08,0.18]);
        end
        plot(i,S(i).FD(end),'Parent',ax(1),'Marker','.','MarkerSize',10,'Color','m');
        
    end
%
%%
    ax.XLabel.String = '$\hat \mu$';
    ax.YLabel.String = '$\mathcal{F}_d$';
    ax.YScale  = 'log';
%    ax(1).YTick     = log10([1E-3,1E-2,1E-1,1]);
 %   ax.YTickLabel   = {'$10^{-3}$','$10^{-2}$','$10^{-1}$','1'}; 
    axes_Style(ax)
%%
   load('CrystalsResDeltaRemSS.mat');
%
   f1 = figure('Position',[0,0,1400,900]/2,'Color',[1,1,1]);    
   ax(1) = axes('Parent',f1);  
   hold(ax(1),'on');
    PlotFD(S,ax)
   function PlotFD(S,ax)    
    for i = 1:80
        
        FDM(i,1:size(S(i).FD,2)) = S(i).FD;
        deltaM(i,1:size(S(i).FD,2)) = S(i).delta;
        StabM(i,1:size(S(i).FD,2)) = S(i).Stable;
    end
    x = deltaM;
    y = FDM;
 %   k = boundary(x,y,0.9);
    k_v    =unique(unique(StabM));

        plot(x(StabM==0),y(StabM==0),'Parent',ax(1),'LineStyle','none','Marker','.','Color',[0,0,0],'MarkerSize',5);
        CC = parula(size(k_v,1)-1);
    for i = 2:length(k_v)
        plot(x(StabM==k_v(i)),y(StabM==k_v(i)),'Parent',ax(1),'LineStyle','none','Marker','.','Color',CC(i-1,:),'MarkerSize',5);
    end
    h= colorbar(ax(1));
    colormap(ax(1),CC)
    caxis(ax(1),[min(k_v)+1,max(k_v)])
%    plot(x(k),y(k),'Parent',ax(1),'Marker','.');
  %  pcolor(deltaM,FDM,StabM,'Parent',ax(1))
    ax.XLabel.String = '$\delta/\kappa$';
    ax.YLabel.String = '$\mathcal{F}_d$';
    ax.YScale  = 'log';
    shading(ax(1),'flat')
    annotation(f1,'textbox',...
    [0.167904054825814 0.753996447602131 0.118218161050828 0.123333925399643],...
    'String',{'$\hat \mu =13$','$\mathcal{P}=2$'},...
    'Interpreter','latex',...
    'FontSize',15,...
    'FitBoxToText','off',...
    'EdgeColor','none');

%    ax(1).YTick     = log10([1E-3,1E-2,1E-1,1]);
 %   ax.YTickLabel   = {'$10^{-3}$','$10^{-2}$','$10^{-1}$','1'}; 
    axes_Style(ax)
   end
%%
 function axes_Style(ax)

         ax.Box                  = 'on';
         ax.Layer               = 'top';
         ax.FontSize             = 13;
         ax.LineWidth            = 1;
         ax.TickLabelInterpreter = 'latex';
         ax.XLabel.Interpreter   = 'latex';
         ax.YLabel.Interpreter   = 'latex';
         ax.XLabel.FontSize   = 15;
         ax.YLabel.FontSize   = 15;

    end