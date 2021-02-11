%%
    figure('Position',[0,0,1000,800],'Color',[1,1,1]);
    Panel = tiledlayout(2,2,'TileSpacing','none','Padding','none');   
    ax(1) = nexttile(Panel,1,[1,2]);  
    hold(ax(1),'on');
    ax(2) = nexttile(Panel,3,[1,1]);  
    ax(3) = nexttile(Panel,4,[1,1]);  

%%
    load('Omega_-10_center_.mat')
    for i_p = 1:720
        for i_d = 1:720

            if ~isnan(Save.k_vec(i_p,i_d).k)
                [~,ind]    = max(Save.k_vec(i_p,i_d).k);

                Conv_eff(i_p,i_d) = abs(Save.Vector_vec(i_p,i_d).Vector(2,ind) +Save.Vector_vec(i_p,i_d).Vector(4,ind)).^2/abs(Save.Vector_vec(i_p,i_d).Vector(1,ind)+Save.Vector_vec(i_p,i_d).Vector(3,ind)).^2;

            else
                Conv_eff(i_p,i_d) = NaN;
            end
        end         
    end

    pcolor(Save.delta_vector/Res.CW.In.ko,Save.W_Vector/sqrt(2*Res.CW.In.ko*Res.CW.In.ke),10*log10(abs(Conv_eff)),'Parent',ax(1));shading(ax(1),'interp');
    load('Omega_-10_lines.mat');
    
    for mu = 1:40
        dmup=dp+0.5*mu^2*d2p;
        dmus=2*dp-ep+mu*(d1s-d1p)+0.5*mu^2*d2s;
        dmup2=dp+0.5*mu^2*d2p;
        dmus2=2*dp-ep-mu*(d1s-d1p)+0.5*mu^2*d2s;
        om2=4*(dmup+dmup2).*(dmup+dmus2).*(dmus+dmus2).*(dmus+dmup2)...
            ./(dmup+dmup2+dmus+dmus2).^2;
        plot(dp,real(sqrt(om2)*kp/omst),'-','Parent',ax(1)); hold on;
    end

    
%%
    load('Lower_branch_-10.mat')
    for i_p = 1:720
        for i_d = 1:720

            if ~isnan(Save.k2_vec(i_p,i_d).k)
                [~,ind]    = max(Save.k2_vec(i_p,i_d).k);

                Conv_eff(i_p,i_d) = abs(Save.Vector2(i_p,i_d).Vector(2,ind) + Save.Vector2(i_p,i_d).Vector(4,ind)).^2/abs(Save.Vector2(i_p,i_d).Vector(1,ind)+Save.Vector2(i_p,i_d).Vector(3,ind)).^2;

            else
                Conv_eff(i_p,i_d) = NaN;
            end
        end         
    end

   mesh(Save.delta_vector/Res.CW.In.ko,Save.W_Vector,10*log10(abs(Conv_eff)),'Parent',ax(3));shading(gca,'interp');
   
%%
    clear Conv_eff;
    load('Upper_branch_-10.mat');
    
    for i_p = 1:360
        for i_d = 1:360

            if ~isnan(Save.k2_vec(i_p,i_d).k)
                [~,ind]    = max(Save.k2_vec(i_p,i_d).k);

                Conv_eff(i_p,i_d) = abs(Save.Vector2(i_p,i_d).Vector(2,ind) + Save.Vector2(i_p,i_d).Vector(4,ind)).^2/abs(Save.Vector2(i_p,i_d).Vector(1,ind)+Save.Vector2(i_p,i_d).Vector(3,ind)).^2;

            else
                Conv_eff(i_p,i_d) = NaN;
            end
        end         
    end

   mesh(Save.delta_vector/Res.CW.In.ko,Save.W_Vector,10*log10(abs(Conv_eff)),'Parent',ax(2));shading(gca,'interp');

%%
    ax(1).XLabel.String = '$\delta_0/\kappa_o$';
    ax(1).YLabel.String = '$\Omega/\Omega_*$';
    
    ax(2).XLabel.String = '$\delta_0/\kappa_o$';
    ax(2).YLabel.String = '$\mathcal{W}/\mathcal{W}^*$';
    
    ax(3).XLabel.String = '$\delta_0/\kappa_o$';
    
    for i = 1:size(ax,2)
       axes_Style(ax(i));
    end
    
function axes_Style(ax)

     ax.Box      = 'on';
     ax.FontSize = 15;
     ax.TickLabelInterpreter = 'latex';
     ax.XLabel.Interpreter   = 'latex';
     ax.YLabel.Interpreter   = 'latex';
     
end
