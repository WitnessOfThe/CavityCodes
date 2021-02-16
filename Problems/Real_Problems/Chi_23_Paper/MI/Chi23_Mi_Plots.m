%%
    figure('Position',[0,0,1000,800],'Color',[1,1,1]);
    Panel = tiledlayout(3,2,'TileSpacing','none','Padding','none');   
    ax(1) = nexttile(Panel,1,[1,2]);  
    hold(ax(1),'on');
    ax(2) = nexttile(Panel,3,[1,1]);  
    ax(3) = nexttile(Panel,4,[1,1]);  
    ax(4) = nexttile(Panel,5,[1,1]);  
    ax(5) = nexttile(Panel,6,[1,1]);  

%%
    load('Omega_-10_Resonance_.mat');
    
    for i_p = 1:720
        for i_d = 1:720

            if ~isnan(Save.k_vec(i_p,i_d).k)
                [~,ind]    = max(Save.k_vec(i_p,i_d).k);

                Conv_eff(i_p,i_d) = abs(Save.Vector_vec(i_p,i_d).Vector(2,ind) ).^2/abs(Save.Vector_vec(i_p,i_d).Vector(1,ind)).^2;

            else
                
                Conv_eff(i_p,i_d) = NaN;
                
            end
        end         
    end

    pcolor(Save.delta_vector/Res.CW.In.ko,Save.W_Vector/sqrt(2*Res.CW.In.ko*Res.CW.In.ke),(abs(Conv_eff)),'Parent',ax(1));shading(ax(1),'interp');
    
%     load('Omega_-10_lines.mat');    
%     for mu = 1:40
%         
%         dmup=dp+0.5*mu^2*d2p;
%         dmus=2*dp-ep+mu*(d1s-d1p)+0.5*mu^2*d2s;
%         dmup2=dp+0.5*mu^2*d2p;
%         dmus2=2*dp-ep-mu*(d1s-d1p)+0.5*mu^2*d2s;
%         om2=4*(dmup+dmup2).*(dmup+dmus2).*(dmus+dmus2).*(dmus+dmup2)...
%             ./(dmup+dmup2+dmus+dmus2).^2;
%         plot(dp,real(sqrt(om2)*kp/omst),'-','Parent',ax(1)); hold on;
%     end

    
%%
    clear Conv_eff;
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
    
   pcolor(Save.delta_vector/Res.CW.In.ko,Save.W_Vector,(abs(Conv_eff)),'Parent',ax(2));shading(gca,'interp');
   colorbar;
    for i_p = 1:NN
        for i_d = 1:NN

            if ~isnan(Save.k1_vec(i_p,i_d).k)
                [~,ind]    = max(Save.k1_vec(i_p,i_d).k);

                Conv_eff(i_p,i_d) = abs(Save.Vector1(i_p,i_d).Vector(2,ind)).^2/abs(Save.Vector1(i_p,i_d).Vector(1,ind)).^2;

            else
                Conv_eff(i_p,i_d) = NaN;
            end
        end         
    end

   pcolor(Save.delta_vector/Res.CW.In.ko,Save.W_Vector,(abs(Conv_eff)),'Parent',ax(3));shading(gca,'interp');
   colorbar;
%%
%     clear Conv_eff;
%     load('Upper_branch_-10.mat');
%     
%     for i_p = 1:360
%         for i_d = 1:360
% 
%             if ~isnan(Save.k2_vec(i_p,i_d).k)
%                 [~,ind]    = max(Save.k2_vec(i_p,i_d).k);
% 
%                 Conv_eff(i_p,i_d) = abs(Save.Vector2(i_p,i_d).Vector(2,ind) ).^2/abs(Save.Vector2(i_p,i_d).Vector(1,ind)).^2;
% 
%             else
%                 Conv_eff(i_p,i_d) = NaN;
%             end
%         end         
%     end
% 
%    pcolor(Save.delta_vector/Res.CW.In.ko,Save.W_Vector,(abs(Conv_eff)),'Parent',ax(3));shading(gca,'interp');
% colorbar;
%     for i_p = 1:360
%         for i_d = 1:360
% 
%             if ~isnan(Save.k1_vec(i_p,i_d).k)
%                 [~,ind]    = max(Save.k1_vec(i_p,i_d).k);
% 
%                 Conv_eff(i_p,i_d) = abs(Save.Vector1(i_p,i_d).Vector(2,ind) ).^2/abs(Save.Vector1(i_p,i_d).Vector(1,ind)).^2;
% 
%             else
%                 
%                 Conv_eff(i_p,i_d) = NaN;
%                 
%             end
%         end         
%     end
% 
%    pcolor(Save.delta_vector/Res.CW.In.ko,Save.W_Vector,(abs(Conv_eff)),'Parent',ax(5));shading(gca,'interp');
%    colorbar;
%%
    ax(1).XLabel.String = '$\delta_0/\kappa_o$';
    ax(1).YLabel.String = '$\Omega/\Omega_*$';
    
    ax(2).XLabel.String = '$\delta_0/\kappa_o$';
    ax(2).YLabel.String = '$\mathcal{W}/\mathcal{W}^*$';
    
    ax(3).XLabel.String = '$\delta_0/\kappa_o$';
    
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
