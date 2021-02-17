    
  %%  
  for ii = 1:size(Save_Omega,2)
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
    
    pcolor(Save_Upper(ii).delta_vector/Save_Upper(ii).Res.CW.In.ko,Save_Upper(ii).W_Vector,Save_Upper(ii).Mumber1,'Parent',ax(2));shading(ax(2),'interp');
    pcolor(Save_Upper(ii).delta_vector/Save_Upper(ii).Res.CW.In.ko,Save_Upper(ii).W_Vector,Save_Upper(ii).Mumber2,'Parent',ax(3));shading(ax(3),'interp');
   
    pcolor(Save_Lower(ii).delta_vector/Save_Lower(ii).Res.CW.In.ko,Save_Lower(ii).W_Vector,Save_Lower(ii).Mumber1,'Parent',ax(4));shading(ax(4),'interp');
    pcolor(Save_Lower(ii).delta_vector/Save_Lower(ii).Res.CW.In.ko,Save_Lower(ii).W_Vector,Save_Lower(ii).Mumber2,'Parent',ax(5));shading(ax(5),'interp');
    
    ax(1).XLabel.String = '$\delta/\kappa_o$';
    ax(2).XLabel.String = '$\delta/\kappa_o$';
    ax(3).XLabel.String = '$\delta/\kappa_o$';
    ax(1).YLabel.String = '$\Omega$ (MHz)';
    ax(2).YLabel.String = '$\mathcal{W}/\mathcal{W}_*$';

    for i = 1:size(ax,2)
       axes_Style(ax(i))
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