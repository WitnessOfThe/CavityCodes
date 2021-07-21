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
%%
   f1 = figure('Position',[0,0,1400,900]/2,'Color',[1,1,1]);    
   ax(1) = axes('Parent',f1);  
   ax = gca;
%    PlotNewCrystalKmax(ResCrystal,ax)   
   PlotNewCrystal(ResCrystal,ax);
  % PlotNewCrystalMu(Crystals,ax)
%   PlotNewCrystalSideBand(ResCrystal,ax);
%%   
   f1 = figure('Position',[0,0,1400,900]/2,'Color',[1,1,1]);    
   ax(1) = axes('Parent',f1);  
   ax = gca;
%%
    function PlotNewCrystalSideBand(S,ax)
    
        hold(ax,'on');
        NT = 1;
        
        for iT =1:size(S,2)
            
          NT =  max([NT,size(S(iT).Tracks,2)]);
          
        end
        
        FD         = NaN(size(S,2), NT);
        Delta      = NaN(size(S,2), NT);
        FullEnergy = NaN(size(S,2), NT);
        
        for iT = 1:size(S,2)
            
            for iC = 1:size(S(iT).Tracks ,2)
                
                FD(iT,iC)    = S(iT).Tracks(iC).Eq.Fin_Dlog;
                Delta(iT,iC) = S(iT).Tracks(iC).Eq.delta;
                FullEnergy(iT,iC) = S(iT).Tracks(iC).Sol.eps_f;%10*log10(sum(abs(S(iT).Tracks(iC).Sol.Psi_k).^2));               
%                 
%                 if real(S(iT).Tracks(iC).Stab.MaxRe) > 10
%                     
%                     FullEnergy(iT,iC) = 1;
%                     if abs(imag(S(iT).Tracks(iC).Stab.MaxRe)) > 1
%                         FullEnergy(iT,iC) = 2;
%                     end
%                    if real(S(iT).Tracks(iC).Stab.lamk0(1)) >1 && abs(imag(S(iT).Tracks(iC).Stab.lamk0(1))) < 10
%                        FullEnergy(iT,iC) = 5;
%                    end
%                 else
%                     
%                     FullEnergy(iT,iC) = 0;
%                     
%                 end
%                 if 10*log10(sum(abs(S(iT).Tracks(iC).Sol.Psi_k([2,end]).^2))) < -40
%                         FullEnergy(iT,iC) = 4;
%                     if 10*log10(sum(abs(S(iT).Tracks(iC).Sol.Psi_k(2:end)).^2)) < -14
%                           FullEnergy(iT,iC) = 3;
%                     end
%                 end
%                 
% %                 if S(iT).Tracks(iC).Sol.eps_f > 1E-10
% %                         FullEnergy(iT,iC) = NaN;
% %                 end
%                 
            end
      FullEnergy(iT,FullEnergy(iT,:)<1E-10) =1;
     %  pcolor(Delta,FD,10*log10(FullEnergy),'Parent',ax);shading(ax,'interp');
            
%             plot(Delta(iT,FullEnergy(iT,:) == 5),FD(iT,FullEnergy(iT,:) == 5),'Parent',ax,'Marker','.','Color',[0,0,0],'LineStyle','none','MarkerSize',4,'Marker','s')
%             plot(Delta(iT,FullEnergy(iT,:) == 4),FD(iT,FullEnergy(iT,:) == 4),'Parent',ax,'Marker','.','Color',[0,1,0],'LineStyle','none','MarkerSize',15)
%     
%             plot(Delta(iT,FullEnergy(iT,:) == 3),FD(iT,FullEnergy(iT,:) == 3),'Parent',ax,'Marker','.','Color','m','LineStyle','none','MarkerSize',15)
%             plot(Delta(iT,FullEnergy(iT,:) == 2),FD(iT,FullEnergy(iT,:) == 2),'Parent',ax,'Marker','.','Color',[1,0,0],'LineStyle','none','MarkerSize',6)
             plot(Delta(iT,FullEnergy(iT,:) == 1),FD(iT,FullEnergy(iT,:) == 1),'Parent',ax,'Marker','.','Color',[0,0,1],'LineStyle','none','MarkerSize',6)
%             plot(Delta(iT,FullEnergy(iT,:) == 0),FD(iT,FullEnergy(iT,:) == 0),'Parent',ax,'Marker','.','Color',[0,0,0],'LineStyle','none','MarkerSize',6)
%   
        end
     % FullEnergy(FullEnergy>0) =1;
      % pcolor(Delta,FD,10*log10(FullEnergy),'Parent',ax);shading(ax,'interp');
     %  caxis([0,1])
    end

    function PlotNewCrystal(S,ax)
    
        hold(ax,'on');
        NT = 1;
        
        for iT =1:size(S,2)
            
          NT =  max([NT,size(S(iT).Tracks,2)]);
          
        end
        
        FD         = NaN(size(S,2), NT);
        Delta      = NaN(size(S,2), NT);
        FullEnergy = NaN(size(S,2), NT);
        
        for iT = 1:size(S,2)
            
            for iC = 1:size(S(iT).Tracks ,2)
                
                FD(iT,iC)    = S(iT).Tracks(iC).Eq.Fin_Dlog;
                Delta(iT,iC) = S(iT).Tracks(iC).Eq.delta;
                FullEnergy(iT,iC) = 10*log10(sum(abs(S(iT).Tracks(iC).Sol.Psi_k).^2));               
                
                if real(S(iT).Tracks(iC).Stab.MaxRe) > 10
                    
                    FullEnergy(iT,iC) = 1;
                    if abs(imag(S(iT).Tracks(iC).Stab.MaxRe)) > 1
                        FullEnergy(iT,iC) = 2;
                    end
                   if real(S(iT).Tracks(iC).Stab.lamk0(1)) >10 && abs(imag(S(iT).Tracks(iC).Stab.lamk0(1))) < 10
                       FullEnergy(iT,iC) = 5;
                   end
                else
                    
                    FullEnergy(iT,iC) = 0;
                    
                end
                if 10*log10(sum(abs(S(iT).Tracks(iC).Sol.Psi_k([2,end]).^2))) < -40
                        FullEnergy(iT,iC) = 4;
                    if 10*log10(sum(abs(S(iT).Tracks(iC).Sol.Psi_k(2:end)).^2)) < -14
                          FullEnergy(iT,iC) = 3;
                    end
                end
                
%                 if S(iT).Tracks(iC).Sol.eps_f > 1E-10
%                         FullEnergy(iT,iC) = NaN;
%                 end
                
            end
            
            plot(Delta(iT,FullEnergy(iT,:) == 5),FD(iT,FullEnergy(iT,:) == 5),'Parent',ax,'Marker','.','Color',[0,0,0],'LineStyle','none','MarkerSize',4,'Marker','s')
            plot(Delta(iT,FullEnergy(iT,:) == 4),FD(iT,FullEnergy(iT,:) == 4),'Parent',ax,'Marker','.','Color',[0,1,0],'LineStyle','none','MarkerSize',15)
    
            plot(Delta(iT,FullEnergy(iT,:) == 3),FD(iT,FullEnergy(iT,:) == 3),'Parent',ax,'Marker','.','Color','m','LineStyle','none','MarkerSize',15)
            plot(Delta(iT,FullEnergy(iT,:) == 2),FD(iT,FullEnergy(iT,:) == 2),'Parent',ax,'Marker','.','Color',[1,0,0],'LineStyle','none','MarkerSize',6)
            plot(Delta(iT,FullEnergy(iT,:) == 1),FD(iT,FullEnergy(iT,:) == 1),'Parent',ax,'Marker','.','Color',[0,0,1],'LineStyle','none','MarkerSize',6)
            plot(Delta(iT,FullEnergy(iT,:) == 0),FD(iT,FullEnergy(iT,:) == 0),'Parent',ax,'Marker','.','Color',[0,0,0],'LineStyle','none','MarkerSize',6)
            
        end
  %      FullEnergy(FullEnergy>0) =1;
 %       pcolor(Delta,FD,FullEnergy,'Parent',ax);shading(ax,'interp');
   %     caxis([0,1])
    end
  function PlotNewCrystalMu(S,ax)
    
        hold(ax,'on');
        NT = 1;
        
        for iT =1:size(S,2)
            
          NT =  max([NT,size(S(iT).Tracks,2)]);
          
        end
        
        FD         = NaN(size(S,2), NT);
        Delta      = NaN(size(S,2), NT);
        FullEnergy = NaN(size(S,2), NT);
        
        for iT = 1:size(S,2)
            clear FullEnergy FD Delta
            for iC = 1:size(S(iT).Tracks ,2)
                
                FD(iC)    = S(iT).Tracks(iC).Eq.Fin_Dlog;
                FD(iC)    = S(iT).Tracks(iC).Eq.delta;
%                Delta(iC) = S(iT).Tracks(iC).Eq.delta;
                FullEnergy(iC) = 10*log10(sum(abs(S(iT).Tracks(iC).Sol.Psi_k).^2));               
                
                if real(S(iT).Tracks(iC).Stab.MaxRe) > 10
                    
                    FullEnergy(iC) = 1;
                    if abs(imag(S(iT).Tracks(iC).Stab.MaxRe)) > 1
                        FullEnergy(iC) = 2;
                    end
                   if real(S(iT).Tracks(iC).Stab.lamk0(1)) >1E3 && abs(imag(S(iT).Tracks(iC).Stab.lamk0(1))) < 10
                       FullEnergy(iC) = 5;
                   end
                else
                    
                    FullEnergy(iC) = 0;
                    
                end
                if 10*log10(sum(abs(S(iT).Tracks(iC).Sol.Psi_k([2,end]).^2))) < -40
                        FullEnergy(iC) = 4;
                    if 10*log10(sum(abs(S(iT).Tracks(iC).Sol.Psi_k(2:end)).^2)) < -14
                          FullEnergy(iC) = 3;
                    end
                end
                
%                 if S(iT).Tracks(iC).Sol.eps_f > 1E-10
%                         FullEnergy(iT,iC) = NaN;
%                 end
                
            end
            if sum(FD(FullEnergy == 5)) ~=0
                plot(S(iT).Tracks(iC).In.mu_bl*ones(size(FD(FullEnergy == 5))),FD(FullEnergy == 5),'Parent',ax,'Marker','.','Color',[0,0,0],'LineStyle','none','MarkerSize',4,'Marker','s')
            end
            if sum(FD(FullEnergy == 4)) ~=0
            plot(S(iT).Tracks(iC).In.mu_bl*ones(size(FD(FullEnergy == 4))),FD(FullEnergy == 4),'Parent',ax,'Marker','.','Color',[0,1,0],'LineStyle','none','MarkerSize',15)    
            end
            if sum(FD(FullEnergy == 3)) ~=0
            plot(S(iT).Tracks(iC).In.mu_bl*ones(size(FD(FullEnergy == 3))),FD(FullEnergy == 3),'Parent',ax,'Marker','.','Color','m','LineStyle','none','MarkerSize',15)
            end
            if sum(FD(FullEnergy == 2)) ~=0
            plot(S(iT).Tracks(iC).In.mu_bl*ones(size(FD(FullEnergy == 2))),FD(FullEnergy == 2),'Parent',ax,'Marker','.','Color',[1,0,0],'LineStyle','none','MarkerSize',6)
            end
            if sum(FD(FullEnergy == 1)) ~=0
            plot(S(iT).Tracks(iC).In.mu_bl*ones(size(FD(FullEnergy == 1))),FD(FullEnergy == 1),'Parent',ax,'Marker','.','Color',[0,0,1],'LineStyle','none','MarkerSize',6)
            end
            if sum(FD(FullEnergy == 0)) ~=0
            plot(S(iT).Tracks(iC).In.mu_bl*ones(size(FD(FullEnergy == 0))),FD(FullEnergy == 0),'Parent',ax,'Marker','.','Color',[0,0,0],'LineStyle','none','MarkerSize',6)
            end           
        end
  %      FullEnergy(FullEnergy>0) =1;
 %       pcolor(Delta,FD,FullEnergy,'Parent',ax);shading(ax,'interp');
   %     caxis([0,1])
  end  
     function PlotNewCrystalKmax(S,ax)
    
        hold(ax,'on');
        NT = 1;
        
        for iT =1:size(S,2)
            
          NT =  max([NT,size(S(iT).Tracks,2)]);
          
        end
        
        FD         = NaN(size(S,2), NT);
        Delta      = NaN(size(S,2), NT);
        FullEnergy = NaN(size(S,2), NT);
        CC = parula(2+round(S(1).Tracks(1).In.mu_bl/2));
        CC(1,:) = [0,0,0];
        
        for iT = 1:size(S,2)
            
            clear FullEnergy FD Delta;
            
            for iC = 1:size(S(iT).Tracks ,2)
                
                FinD(iC)    = S(iT).Tracks(iC).Eq.Fin_Dlog;
                FD(iC)    = S(iT).Tracks(iC).Eq.delta;
                                                
           
                if real(S(iT).Tracks(iC).Stab.MaxRe) > 10
                    
                    FullEnergy(iC) = S(iT).Tracks(iC).Stab.kmax;               
                else
                    
                    FullEnergy(iC) = -1;
                    
                end
            end
            for ik = -1:round(S(iT).Tracks(iC).In.mu_bl/2)
                
                plot(FD( FullEnergy == ik),FinD(FullEnergy == ik),'Color',CC(ik+2,:),'Parent',ax,'LineStyle','none','Marker','.');
                
            end
            
        end
        caxis([-1,round(S(iT).Tracks(iC).In.mu_bl/2)])
        h = colorbar;
        
        colormap(h,CC);
    end 
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