    
  %%  
%ylim([-20. 3000])
  
  for ii = 1
    kp = Save_Lower(ii).Res.CW.In.ko;
    ks = Save_Lower(ii).Res.CW.In.ke;
    omst=Save_Lower(ii).Res.CW.In.Omega_Star;
    ep=Save_Lower(ii).Res.CW.In.eps/kp;
    d1p=Save_Lower(ii).Res.CW.In.Do(1)/kp;
    d1s=Save_Lower(ii).Res.CW.In.De(1)/kp;
    d2p=Save_Lower(ii).Res.CW.In.Do(2)/kp;
    d2s=Save_Lower(ii).Res.CW.In.De(2)/kp;
    dp=[min(Save_Omega(ii).delta_vector/Save_Omega(ii).Res.CW.In.ko):0.02:max((Save_Omega(ii).delta_vector/Save_Omega(ii).Res.CW.In.ko))];
      
    figure('Position',[0,0,1000,800],'Color',[1,1,1]);
    Panel = tiledlayout(3,2,'TileSpacing','none','Padding','none');   
    
    ax(1) = nexttile(Panel,1,[1,2]);  
    hold(ax(1),'on');
    ax(2) = nexttile(Panel,3,[1,1]);  
    hold(ax(2),'on');   
    ax(3) = nexttile(Panel,4,[1,1]);  
    hold(ax(3),'on');
    ax(4) = nexttile(Panel,5,[1,1]);
    hold(ax(4),'on');
    ax(5) = nexttile(Panel,6,[1,1]);
    hold(ax(5),'on');

    pcolor(Save_Omega(ii).delta_vector/Save_Omega(ii).Res.CW.In.ko,Save_Omega(ii).W_Vector/Save_Omega(ii).Res.CW.In.Omega_Star,Save_Omega(ii).Mumber,'Parent',ax(1));shading(ax(1),'interp');
    for mu = 1:1
        dmup=dp+0.5*mu^2*d2p;
        dmus=2*dp-ep+mu*(d1s-d1p)+0.5*mu^2*d2s;
        dmup2=dp+0.5*mu^2*d2p;
        dmus2=2*dp-ep-mu*(d1s-d1p)+0.5*mu^2*d2s;
        om2=4*(dmup+dmup2).*(dmup+dmus2).*(dmus+dmus2).*(dmus+dmup2)...
            ./(dmup+dmup2+dmus+dmus2).^2;
        plot(dp,real(sqrt(om2)*kp/omst),'LineWidth',1,'Color',[1,0,0],'Parent',ax(1)); 
    end
%    for mu = 26:50
 %       dmup=dp+0.5*mu^2*d2p;
   %     dmus=2*dp-ep+mu*(d1s-d1p)+0.5*mu^2*d2s;
  %      dmup2=dp+0.5*mu^2*d2p;
    %    dmus2=2*dp-ep-mu*(d1s-d1p)+0.5*mu^2*d2s;
     %   om2=4*(dmup+dmup2).*(dmup+dmus2).*(dmus+dmus2).*(dmus+dmup2)...
      %      ./(dmup+dmup2+dmus+dmus2).^2;
       % plot(dp,real(sqrt(om2)*kp/omst),'LineWidth',1,'Color',[0,0,1],'Parent',ax(1)); 
    %end
    
    pcolor(Save_Upper(ii).delta_vector/Save_Upper(ii).Res.CW.In.ko,Save_Upper(ii).W_Vector,Save_Upper(ii).Mumber1,'Parent',ax(2));shading(ax(2),'interp');
    pcolor(Save_Upper(ii).delta_vector/Save_Upper(ii).Res.CW.In.ko,Save_Upper(ii).W_Vector,Save_Upper(ii).Mumber2,'Parent',ax(3));shading(ax(3),'interp');
   
    pcolor(Save_Lower(ii).delta_vector/Save_Lower(ii).Res.CW.In.ko,Save_Lower(ii).W_Vector,Save_Lower(ii).Mumber1,'Parent',ax(4));shading(ax(4),'interp');
    pcolor(Save_Lower(ii).delta_vector/Save_Lower(ii).Res.CW.In.ko,Save_Lower(ii).W_Vector,Save_Lower(ii).Mumber2,'Parent',ax(5));shading(ax(5),'interp');
    
    ax(1).XLim = [min(Save_Omega(ii).delta_vector/Save_Omega(ii).Res.CW.In.ko),max(Save_Omega(ii).delta_vector/Save_Omega(ii).Res.CW.In.ko)];
    ax(1).YLim = [min(Save_Omega(ii).W_Vector/Save_Omega(ii).Res.CW.In.Omega_Star),max(Save_Omega(ii).W_Vector/Save_Omega(ii).Res.CW.In.Omega_Star)];
    
    ax(2).XLim = [min(Save_Upper(ii).delta_vector/Save_Upper(ii).Res.CW.In.ko),max(Save_Upper(ii).delta_vector/Save_Upper(ii).Res.CW.In.ko)];
    ax(3).XLim = [min(Save_Upper(ii).delta_vector/Save_Upper(ii).Res.CW.In.ko),max(Save_Upper(ii).delta_vector/Save_Upper(ii).Res.CW.In.ko)];
    
    ax(4).XLim = [min(Save_Lower(ii).delta_vector/Save_Lower(ii).Res.CW.In.ko),max(Save_Lower(ii).delta_vector/Save_Lower(ii).Res.CW.In.ko)];
    ax(5).XLim = [min(Save_Lower(ii).delta_vector/Save_Lower(ii).Res.CW.In.ko),max(Save_Lower(ii).delta_vector/Save_Lower(ii).Res.CW.In.ko)];

    ax(2).YLim = [min(Save_Upper(ii).W_Vector),max(Save_Upper(ii).W_Vector)];
    ax(3).YLim = [min(Save_Upper(ii).W_Vector),max(Save_Upper(ii).W_Vector)];
    ax(4).YLim = [min(Save_Upper(ii).W_Vector),max(Save_Upper(ii).W_Vector)];
    
    ax(1).XLabel.String = '$\delta/\kappa_o$';
    ax(2).XLabel.String = '$\delta/\kappa_o$';
    ax(3).XLabel.String = '$\delta/\kappa_o$';
    
    ax(1).YLabel.String = '$\Omega/\Omega^*$ ';
    ax(2).YLabel.String = '$\mathcal{W}/\mathcal{W}_*$';
    
    for i = 1:size(ax,2)
        
        tt = colormap(ax(i));
        tt(1,:) = [0,0,0];
        colormap(ax(i),tt)
        axes_Style(ax(i))
       
    end
    
    figure1 = gcf;
annotation(figure1,'textbox',[0.0606 0.57425 0.0462 0.054],'Color',[1 1 1],...
    'String','$\chi_{2}$',...
    'Interpreter','latex',...
    'FontSize',20,...
    'FitBoxToText','off');

annotation(figure1,'textbox',[0.5474 0.57675 0.0462 0.054],'Color',[1 1 1],...
    'String','$\chi_{2,3}$',...
    'Interpreter','latex',...
    'FontSize',20,...
    'FitBoxToText','off');
annotation(figure1,'textbox',...
    [0.0606000000000006 0.22725 0.0462 0.0540000000000001],...
    'String','$\chi_{2}$',...
    'Interpreter','latex',...
    'FontSize',20,...
    'FitBoxToText','off',...
    'EdgeColor','none');
annotation(figure1,'textbox',...
    [0.546600000000001 0.22575 0.0462 0.0540000000000001],...
    'String','$\chi_{2,3}$',...
    'Interpreter','latex',...
    'FontSize',20,...
    'FitBoxToText','off',...
    'EdgeColor','none');

    
  end
  %%
  
  Left_Resonance.epsilon        = 2*pi*[-1E9,-3E9,-5E9,-7E9,-9E9,-10E9,-15E9,-20E9,1E9,2E9,3E9,4E9,5E9,10E9,20E9];
  Left_Resonance.Chi2.delta_p   = [-23.61,  -41.72,-53.57,-62.82,-73.15,-85.16,-91.17,-26.5462,-36.6227,-44.4,-50.799,-56.2196,-75.8165,-93.7063];
  Left_Resonance.Chi2.WW        = [960962,8458460,22942900,43843800,69509500,84534500,170170000,260661000,972899,3822100,8478110,14975700,22863100,83947200,258741000];
  Left_Resonance.Chi23.delta_p  = [-23.61,-41.5616,-53.09,-62.10,-71.952,-82.52,-87.5676,-26.54,-36.76,-44.5448,-51.077,-56.7755,-77.2064,-98.1818];
  Left_Resonance.Chi23.WW       = [950952,8318320,22162200,41982000,65905900,79129100,153153000,225526000,1007650,3856850,8929810,15253600,23801300,90479500,307692000];
  
  figure;
    hold on;
    plot(Left_Resonance.epsilon(1:8)/2/pi/1E9,Left_Resonance.Chi2.WW(1:8),'Color',[1,0,0],'Marker','*');
    plot(Left_Resonance.epsilon(1:8)/2/pi/1E9,Left_Resonance.Chi23.WW(1:8),'Color',[0,0,1],'Marker','*');
    plot(Left_Resonance.epsilon(9:end)/2/pi/1E9,Left_Resonance.Chi2.WW(9:end),'Color',[1,0,0],'Marker','*');
    plot(Left_Resonance.epsilon(9:end)/2/pi/1E9,Left_Resonance.Chi23.WW(9:end),'Color',[0,0,1],'Marker','*');
    axes_Style(gca);
%   Left_Resonance.epsilon        = 2*pi*[1E9,2E9,3E9,4E9,5E9,10E9];
%   Left_Resonance.Chi2.delta_p   = [-26.5462,-36.6227,-44.4,-50.799,-56.2196,-75.8165];
%   Left_Resonance.Chi2.WW        = [972899,3822100,8478110,14975700,22863100,83947200];
%   Left_Resonance.Chi23.delta_p  = [-26.54,-36.76,-44.5448,-51.077,-56.7755,-77.2064];
%   Left_Resonance.Chi23.WW       = [1007650,3856850,8929810,15253600,23801300,90479500];
%     plot(Left_Resonance.epsilon/2/pi/1E9,Left_Resonance.Chi2.WW,'Color',[1,0,0]);
 %   plot(Left_Resonance.epsilon/2/pi/1E9,Left_Resonance.Chi23.WW,'Color',[0,0,1]);
    xlabel('$\varepsilon$ (GHz)');
    ylabel( '$\mathcal{W}/\mathcal{W}_*$');
 %   axes_Style(gca);

%%
    function axes_Style(ax)

     ax.Box      = 'on';
     ax.FontSize = 15;
     ax.TickLabelInterpreter = 'latex';
     ax.XLabel.Interpreter   = 'latex';
     ax.YLabel.Interpreter   = 'latex';

    end

    
%%
