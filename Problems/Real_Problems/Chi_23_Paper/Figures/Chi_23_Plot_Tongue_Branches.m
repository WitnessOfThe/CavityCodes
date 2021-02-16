clear all
figure('Position',[0,0,1000,800/2],'Color',[1,1,1]);
    Panel = tiledlayout(1,2,'TileSpacing','none','Padding','none');   
    ax(1) = nexttile(Panel,1,[1,1]);  
    hold(ax(1),'on');
    ax(2) = nexttile(Panel,2,[1,1]);  
%%

    load('Upper_-10_Resonance_.mat')
    
  NN = 360;
    for i_p = 1:NN
        for i_d = 1:NN

            if ~isnan(Save.k2_vec(i_p,i_d).k)
                [~,ind]    = max(Save.k2_vec(i_p,i_d).k);

                Conv_eff(i_p,i_d) = abs(Save.Vector2(i_p,i_d).Vector(2,ind)).^2/abs(Save.Vector2(i_p,i_d).Vector(1,ind)).^2;

            else
                Conv_eff(i_p,i_d) = NaN;
            end
        end         
    end
    
   pcolor(Save.delta_vector/Res.CW.In.ko,Save.W_Vector,(abs(Conv_eff)),'Parent',ax(1));shading(gca,'interp');
   load('Tongue_10_Conv_Distrubution')
   pcolor(delta_matrix,W_matrix,Conv_eff,'Parent',ax(2));shading(gca,'interp');
   colorbar;
%%
%%
     ax(1).XLabel.String = '$\delta_0/\kappa_o$';
    ax(1).YLabel.String = '$\mathcal{W}/\mathcal{W}^*$';
    
    ax(2).XLabel.String = '$\delta_0/\kappa_o$';
    ax(2).YLabel.String = '$\mathcal{W}/\mathcal{W}^*$';
    
    
    for i = 1:size(ax,2)
       axes_Style(ax(i));
       shading(ax(i),'interp');
       colorbar(ax(i));
    end
    
function axes_Style(ax)

     ax.Box      = 'on';
     ax.FontSize = 15;
     ax.TickLabelInterpreter = 'latex';
     ax.XLabel.Interpreter   = 'latex';
     ax.YLabel.Interpreter   = 'latex';
     
end
