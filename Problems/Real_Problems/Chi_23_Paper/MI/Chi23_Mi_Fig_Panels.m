    figure('Position',[0,0,1000,800/2],'Color',[1,1,1]);
    Panel = tiledlayout(2,2,'TileSpacing','none','Padding','none');   
    
    ax(1) = nexttile(Panel,1,[1,2]);  
    hold(ax(1),'on');
    ax(2) = nexttile(Panel,3,[1,1]);  
    hold(ax(2),'on');
    ax(3) = nexttile(Panel,4,[1,1]);  
    hold(ax(3),'on');
  %%  
    load('Omega_eps=50GHz_up_to_1E5.mat');
    pcolor(Save.delta_vector/1E6/2/pi,Save.Omega_Vector/2/pi/1E6,Save.Mumber_of_modes,'Parent',ax(1));shading(ax(1),'interp');
   
%%
    load('Power_eps=50GHz_up_to_1E5.mat');
    pcolor(Save.delta_vector/1E6/2/pi,Save.W_Vector,Save.Mumber_of_modes_1,'Parent',ax(2));shading(ax(2),'interp');
    pcolor(Save.delta_vector/1E6/2/pi,Save.W_Vector,Save.Mumber_of_modes_2,'Parent',ax(3));shading(ax(3),'interp');
    ax(1).XLabel.String = '$\delta/\kappa_o$';
    ax(2).XLabel.String = '$\delta/\kappa_o$';
    ax(3).XLabel.String = '$\delta/\kappa_o$';
    ax(1).YLabel.String = '$\Omega$ (MHz)';
    ax(2).YLabel.String = '$\mathcal{W}/\mathcal{W}_*$';
%%
    for i = 1:size(ax,2)
       axes_Style(ax(i))
    end
    
function axes_Style(ax)

     ax.Box      = 'on';
     ax.FontSize = 15;
     ax.TickLabelInterpreter = 'latex';
     ax.XLabel.Interpreter   = 'latex';
     ax.YLabel.Interpreter   = 'latex';
     
end
