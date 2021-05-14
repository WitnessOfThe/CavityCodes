%%
clear all;

%%

  a = 1000;
    f1 = figure('Position',[0,0,a,a*0.618],'Color',[1,1,1]);
    Panel = tiledlayout(1,2,'TileSpacing','none','Padding','none','Parent',f1);  
    
    for i = 1:2
        
        ax(i) = nexttile(Panel,i,[1,1]);  
        hold(ax(i),'on');
        
    end
    f2 = figure('Position',[0,0,a*0.3,a/2],'Color',[1,1,1]);
    Panel2 = tiledlayout(3,1,'TileSpacing','none','Padding','none','Parent',f2);  
    
    for i = 1:3
        
        ax2(i) = nexttile(Panel2,i,[1,1]);  
        hold(ax2(i),'on');
        
    end
    
    load('600mqw25Branch.mat')
    PlotSome(Res1,ax)
    stem(fftshift(Res1.Stat(end).Space.k),fftshift(10*log10(abs(Res1.Stat(end).Sol.Psi_o).^2) ),'Parent',ax2(1),'Marker','none','BaseValue',-75,'Color',[1,0,0]);
    stem(fftshift(Res1.Stat(end).Space.k)+0.3,fftshift(10*log10(abs(Res1.Stat(end).Sol.Psi_e).^2) ),'Parent',ax2(1),'Marker','none','BaseValue',-75,'Color',[0,1,0]);
    load('6mw25Branch.mat')
    PlotSome(Res3,ax)
    stem(fftshift(Res3.Stat(end).Space.k),fftshift(10*log10(abs(Res3.Stat(end).Sol.Psi_o).^2) ),'Parent',ax2(2),'Marker','none','BaseValue',-75,'Color',[1,0,0]);
    stem(fftshift(Res3.Stat(end).Space.k)+0.3,fftshift(10*log10(abs(Res1.Stat(end).Sol.Psi_e).^2) ),'Parent',ax2(2),'Marker','none','BaseValue',-75,'Color',[0,1,0]);
    load('60mw25Branch.mat')
    PlotSome(Res3,ax)
    stem(fftshift(Res3.Stat(end).Space.k),fftshift(10*log10(abs(Res3.Stat(end).Sol.Psi_o).^2) ),'Parent',ax2(3),'Marker','none','BaseValue',-75,'Color',[1,0,0]);
    stem(fftshift(Res3.Stat(end).Space.k),fftshift(10*log10(abs(Res3.Stat(end).Sol.Psi_e).^2) ),'Parent',ax2(3),'Marker','none','BaseValue',-75,'Color',[0,1,0]);

    
    for i =1:3
        ax2(i).YLim = [-75,0];
        ax2(i).XLim = [-100,100];
    end
    for i = 1:size(ax,2)
        
       axes_Style(ax(i));
       
    end

 function PlotSome(Res,ax)
%%
    E_Values = zeros(size(Res.Stat,2),10);
    
    for i = 1:size(Res.Stat,2)
        
        Psi_hat_o(i,:)    = Res.Stat(i).Sol.Psi_o;
        Psi_hat_e(i,:)    = Res.Stat(i).Sol.Psi_e;
        delta_vector(i)   = Res.Stat(i).Eq.delta_o;%/2/pi/1E9;%delta_o;%.eps/2/pi/1E9
        V_vector(i)       = Res.Stat(i).Sol.V; %Res.Stat(i).Sol.V;
  %      [~,]              = max(abs(Res.Stat(i).Stab(1).E_values));
        [V_zero_value(i),ind]   = min(abs(Res.Stat(i).Stab(1).E_values));
%        V_zero_value(i)         = 
        Res.Stat(i).Stab(1).E_values(ind) = [];
        max_psi(i) = max(abs(ifft( Psi_hat_o(i,:))*Res.Stat(i).Space.N).^2);
        Sum_power(i) = sum(abs(Res.Stat(i).Sol.Psi_e(1:end)).^2);
        
        for j = 1:size(Res.Stat(i).Stab,2)
            
           E_Values(i,:) =  maxk([E_Values(i,:).';real(Res.Stat(i).Stab(j).E_values)],10);
           
        end
        
        if max(E_Values(i,:)) > 0
            
            Stable(i) = false;
            
        else
            
            Stable(i) = true;
            
        end        
    end
%%    
    dd            = delta_vector;
    dd(Stable==0) = NaN;
    mp            = max_psi;
    mp(Stable==0) = NaN;
    
    plot(delta_vector,max_psi,'Parent',ax(1),'Color',[0,0,0])
    plot(dd,mp,'Parent',ax(1),'Color',[0,0,0],'LineWidth',2)
%%
    mpow            = Sum_power;
    mpow(Stable==0) = NaN;
    
    plot(delta_vector,Sum_power,'Parent',ax(2),'Color',[0,0,0])
    plot(dd,mpow,'Parent',ax(2),'Color',[0,0,0],'LineWidth',2)

  end