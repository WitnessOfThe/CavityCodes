clear all
%%
    k_o = 2*pi*1E6;
    figure('Position',[0,0,1000,800],'Color',[1,1,1]);
    Panel = tiledlayout(4,3,'TileSpacing','none','Padding','none');   
    for i = 1:6
        ax(i) = nexttile(Panel,i,[1,1]);  
        hold(ax(i),'on');
    end
 %%
 
    load('eps_0_70000.mat');
    
        plot(Sa2.delta_vector/k_o ,1e3*abs(Sa2.U_f_2).^2,'Parent',ax(1),'Color',[1,0,0],'LineWidth',1)
        plot(Sa2.delta_vector/k_o ,1e3*abs(Sa2.U_s_2).^2,'Parent',ax(4),'Color',[0,1,0],'LineWidth',1)
    for i = 1:size(Sa23,2)
        plot(Sa23(i).delta,1e3*abs(Sa23(i).Psi_o).^2,'Parent',ax(1),'Color',[1,0,0],'LineWidth',1,'LineStyle','--')
        plot(Sa23(i).delta,1e3*abs(Sa23(i).Psi_e).^2,'Parent',ax(4),'Color',[0,1,0],'LineWidth',1,'LineStyle','--')
    end
    
%%
    load('eps_plus_20_Ghz_70000.mat');
    
        plot(Sa2.delta_vector/k_o ,1e3*abs(Sa2.U_f_2).^2,'Parent',ax(2),'Color',[1,0,0],'LineWidth',1)
        plot(Sa2.delta_vector/k_o ,1e3*abs(Sa2.U_s_2).^2,'Parent',ax(5),'Color',[0,1,0],'LineWidth',1)
    for i = 1:size(Sa23,2)
        plot(Sa23(i).delta,1e3*abs(Sa23(i).Psi_o).^2,'Parent',ax(2),'Color',[1,0,0],'LineWidth',1,'LineStyle','--')
        plot(Sa23(i).delta,1e3*abs(Sa23(i).Psi_e).^2,'Parent',ax(5),'Color',[0,1,0],'LineWidth',1,'LineStyle','--')
    end
    load('eps_plus_50_Ghz_70000.mat');
    
        plot(Sa2.delta_vector/k_o ,1e3*abs(Sa2.U_f_2).^2,'Parent',ax(2),'Color',[1,0,0],'LineWidth',1)
        plot(Sa2.delta_vector/k_o ,1e3*abs(Sa2.U_s_2).^2,'Parent',ax(5),'Color',[0,1,0],'LineWidth',1)
    for i = 1:size(Sa23,2)
        plot(Sa23(i).delta,1e3*abs(Sa23(i).Psi_o).^2,'Parent',ax(2),'Color',[1,0,0],'LineWidth',1,'LineStyle','--')
        plot(Sa23(i).delta,1e3*abs(Sa23(i).Psi_e).^2,'Parent',ax(5),'Color',[0,1,0],'LineWidth',1,'LineStyle','--')
    end
    
    
%%
    load('eps_minus_20_Ghz_70000.mat');
    
        plot(Sa2.delta_vector/k_o ,1e3*abs(Sa2.U_f_2).^2,'Parent',ax(3),'Color',[1,0,0],'LineWidth',1)
        plot(Sa2.delta_vector/k_o ,1e3*abs(Sa2.U_s_2).^2,'Parent',ax(6),'Color',[0,1,0],'LineWidth',1)
    for i = 1:size(Sa23,2)
        plot(Sa23(i).delta,1e3*abs(Sa23(i).Psi_o).^2,'Parent',ax(3),'Color',[1,0,0],'LineWidth',1,'LineStyle','--')
        plot(Sa23(i).delta,1e3*abs(Sa23(i).Psi_e).^2,'Parent',ax(6),'Color',[0,1,0],'LineWidth',1,'LineStyle','--')
    end
    load('eps_minus_50_Ghz_70000.mat');
    
        plot(Sa2.delta_vector/k_o ,1e3*abs(Sa2.U_f_2).^2,'Parent',ax(3),'Color',[1,0,0],'LineWidth',1)
        plot(Sa2.delta_vector/k_o ,1e3*abs(Sa2.U_s_2).^2,'Parent',ax(6),'Color',[0,1,0],'LineWidth',1)
    for i = 1:size(Sa23,2)
        plot(Sa23(i).delta,1e3*abs(Sa23(i).Psi_o).^2,'Parent',ax(3),'Color',[1,0,0],'LineWidth',1,'LineStyle','--')
        plot(Sa23(i).delta,1e3*abs(Sa23(i).Psi_e).^2,'Parent',ax(6),'Color',[0,1,0],'LineWidth',1,'LineStyle','--')
    end
    
%%
    ax(1).YLabel.String = 'Power (mW)';
    ax(4).YLabel.String = 'Power (mW)';
    
    ax(2).XLim          = [-20,5];
    ax(5).XLim          = [-20,5];
    
    ax(3).XLim          = [-5,20];
    ax(6).XLim          = [-5,20];
    
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
