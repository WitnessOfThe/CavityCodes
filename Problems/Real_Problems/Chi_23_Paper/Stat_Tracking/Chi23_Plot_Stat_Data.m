    E_Values = zeros(size(Res.Stat,2),10);
    clear delta_vector
    for i = 1:size(Res.Stat,2)
        
        Psi_hat_o(i,:)    = Res.Stat(i).Sol.Psi_o;
        Psi_hat_e(i,:)    = Res.Stat(i).Sol.Psi_e;
  %      delta_vector(i)   = Res.Stat(i).In.eps/2/pi/1E9;
       delta_vector(i)   = Res.Stat(i).Eq.delta_o;
        V_vector(i)       = Res.Stat(i).Sol.V;
        
        for j = 1:size(Res.Stat(i).Stab,2)
            
           E_Values(i,:) =  maxk([E_Values(i,:).';real(Res.Stat(i).Stab(j).E_values)],10);
           
        end
        
        if max(E_Values(i,:)) > 1E2
            
            Stable(i) = false;
            if max(E_Values(i,:)) == real(min(Res.Stat(i).Stab(1).E_values))
                 Stable(i) = true;
            end
        else
            
            Stable(i) = true;
            
        end        
    end
    Str_x = '$\delta_0/\kappa_o$';
    Str_x = '$\varepsilon$';
    Psi_thetao = ifft(Psi_hat_o,[],2)*Res.Stat(1).Space.N;
    Psi_thetae = ifft(Psi_hat_e,[],2)*Res.Stat(1).Space.N;
    
    U_maxo     = max(abs(Psi_thetao).^2,[],2);
    U_maxe     = max(abs(Psi_thetae).^2,[],2);

    figure('Position',[0,0,1600,900],'Color',[1,1,1]);
    Panel = tiledlayout(3,5,'TileSpacing','none','Padding','none');  
    
    for i = 1:15
        
        ax(i) = nexttile(Panel,i,[1,1]);  
        hold(ax(i),'on');
        
    end
    
    ind_show = [2,Res.Stat(1).Space.N - 1 ];
    
    plot(delta_vector,abs(Psi_hat_o(:,1)).^2,'Parent',ax(1));
    plot(delta_vector,abs(Psi_hat_e(:,1)).^2,'Parent',ax(1));     
    plot(delta_vector,sum(abs(Psi_hat_o(:,:)).^2,2),'Parent',ax(1));
    plot(delta_vector,sum(abs(Psi_hat_e(:,:)).^2,2),'Parent',ax(1));

    plot(delta_vector(Stable),abs(Psi_hat_o(Stable,1)).^2,'Parent',ax(1),'LineStyle','none','MarkerSize',20,'Marker','.');
    plot(delta_vector(Stable),abs(Psi_hat_e(Stable,1)).^2,'Parent',ax(1),'LineStyle','none','MarkerSize',20,'Marker','.');
    
    plot(delta_vector(Stable),sum(abs(Psi_hat_o(Stable,:)).^2,2),'Parent',ax(1),'LineStyle','none','MarkerSize',20,'Marker','.');
    plot(delta_vector(Stable),sum(abs(Psi_hat_e(Stable,:)).^2,2),'Parent',ax(1),'LineStyle','none','MarkerSize',20,'Marker','.');
    
    legend(ax(1),'$|\psi^o_{\mu=0}|^2$','$|\psi^e_{\mu=0}|^2$','$\sum|\psi^o_{\mu=0}|^2$','$\sum|\psi^e_{\mu=0}|^2$','Interpreter','latex');
    
    plot(delta_vector,abs(Psi_hat_e(:,1)).^2./abs(Psi_hat_o(:,1)).^2,'Parent',ax(2));
    plot(delta_vector,sum(abs(Psi_hat_e(:,:)).^2,2)./sum(abs(Psi_hat_o(:,:)).^2,2),'Parent',ax(2));
    
    plot(delta_vector(Stable),abs(Psi_hat_e(Stable,1)).^2./abs(Psi_hat_o(Stable,1)).^2,'Parent',ax(2),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
    plot(delta_vector(Stable),sum(abs(Psi_hat_e(Stable,:)).^2,2)./sum(abs(Psi_hat_o(Stable,:)).^2,2),'Parent',ax(2),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
    
    legend(ax(2),'$|\psi^e_{\mu=0}|^2/|\psi^o_{\mu=0}|^2$','$\sum|\psi^e_{\mu=0}|^2/\sum|\psi^o_{\mu=0}|^2$','Interpreter','latex');
    
    for i = 0
        ind_k =  Res.Stat(1).Space.N - 1 -i+1;    
        plot(delta_vector,abs(Psi_hat_o(:,ind_k)).^2,'Parent',ax(6));
        plot(delta_vector,abs(Psi_hat_e(:,ind_k)).^2,'Parent',ax(6));    
        plot(delta_vector(Stable),abs(Psi_hat_o(Stable,ind_k)).^2,'Parent',ax(6),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
        plot(delta_vector(Stable),abs(Psi_hat_e(Stable,ind_k)).^2,'Parent',ax(6),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
    legend(ax(6),strcat('$|\psi^o_{\mu=',num2str(Res.Stat(1).Space.k(ind_k)),'}|^2$'),strcat('$|\psi^e_{\mu=',num2str(Res.Stat(1).Space.k(ind_k)),'}|^2$')...
        ,'Interpreter','latex');
    
    plot(delta_vector,abs(Psi_hat_e(:,ind_k)).^2./abs(Psi_hat_o(:,ind_k)).^2,'Parent',ax(7));
    
    plot(delta_vector(Stable),abs(Psi_hat_e(Stable,ind_k)).^2./abs(Psi_hat_o(Stable,ind_k)).^2,'Parent',ax(7),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
    
    legend(ax(7),strcat('$|\psi^e_{\mu=',num2str(Res.Stat(1).Space.k(ind_k)),'}|^2/|\psi^o_{\mu=',num2str(Res.Stat(1).Space.k(ind_k)),'}|^2$')...
        ,'Interpreter','latex');
        
    end
    
    for i = 3
        ind_k = Res.Stat(1).Space.N - 1 -i+1;
        plot(delta_vector,abs(Psi_hat_o(:,ind_k)).^2,'Parent',ax(11));
        plot(delta_vector,abs(Psi_hat_e(:,ind_k)).^2,'Parent',ax(11));
    
        plot(delta_vector(Stable),abs(Psi_hat_o(Stable,ind_k)).^2,'Parent',ax(11),'LineStyle','none','MarkerSize',20,'Marker','.');
        plot(delta_vector(Stable),abs(Psi_hat_e(Stable,ind_k)).^2,'Parent',ax(11),'LineStyle','none','MarkerSize',20,'Marker','.');
    legend(ax(11),strcat('$|\psi^o_{\mu=',num2str(Res.Stat(1).Space.k(ind_k)),'}|^2$'),strcat('$|\psi^e_{\mu=',num2str(Res.Stat(1).Space.k(ind_k)),'}|^2$')...
        ,'Interpreter','latex');
    
    plot(delta_vector,abs(Psi_hat_e(:,ind_k)).^2./abs(Psi_hat_o(:,ind_k)).^2,'Parent',ax(12));
    plot(delta_vector(Stable),abs(Psi_hat_e(Stable,ind_k)).^2./abs(Psi_hat_o(Stable,ind_k)).^2,'Parent',ax(12),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
    
    legend(ax(12),strcat('$|\psi^e_{\mu=',num2str(Res.Stat(1).Space.k(ind_k)),'}|^2/|\psi^o_{\mu=',num2str(Res.Stat(1).Space.k(ind_k)),'}|^2$')...
        ,'Interpreter','latex');
    
    end
    ind_show = 5;
    
    plot(Res.Stat(1).Space.phi,abs(Psi_thetae(ind_show,:)),'Parent',ax(3));
    plot(Res.Stat(1).Space.phi,real(Psi_thetae(ind_show,:)),'Parent',ax(3));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetae(ind_show,:)),'Parent',ax(3));
    plot(Res.Stat(1).Space.phi,abs(Psi_thetao(ind_show,:)),'Parent',ax(4));
    plot(Res.Stat(1).Space.phi,real(Psi_thetao(ind_show,:)),'Parent',ax(4));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetao(ind_show,:)),'Parent',ax(4));
    
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_o(ind_show,:)).^2),'Parent',ax(5),'BaseValue',-70,'Marker','none','Color',[1,0,0]);
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_e(ind_show,:)).^2),'Parent',ax(5),'BaseValue',-70,'Marker','none','Color',[0,1,0]);
    ax(5).YLabel.String = strcat('Power (db)',Str_x,'=',num2str(delta_vector(ind_show)));
   
    
    delta_avg    = (max(delta_vector()) - min(delta_vector))/2+min(delta_vector);
    
    [~,ind_show] = mink(abs(delta_vector - delta_avg),2 );
    ind_show     = ind_show(2);
    
    plot(Res.Stat(1).Space.phi,abs(Psi_thetae(ind_show,:)),'Parent',ax(8));
    plot(Res.Stat(1).Space.phi,real(Psi_thetae(ind_show,:)),'Parent',ax(8));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetae(ind_show,:)),'Parent',ax(8));
    
    plot(Res.Stat(1).Space.phi,abs(Psi_thetao(ind_show,:)),'Parent',ax(9));
    plot(Res.Stat(1).Space.phi,real(Psi_thetao(ind_show,:)),'Parent',ax(9));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetao(ind_show,:)),'Parent',ax(9));
    
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_o(ind_show,:)).^2),'Parent',ax(10),'BaseValue',-70,'Marker','none','Color',[1,0,0]);
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_e(ind_show,:)).^2),'Parent',ax(10),'BaseValue',-70,'Marker','none','Color',[0,1,0]);
    ax(10).YLabel.String = strcat('Power (db)',Str_x,'=',num2str(delta_vector(ind_show)));

    ind_show = size(Res.Stat,2)-5;
    
    plot(Res.Stat(1).Space.phi,abs(Psi_thetae(ind_show,:)),'Parent',ax(13));
    plot(Res.Stat(1).Space.phi,real(Psi_thetae(ind_show,:)),'Parent',ax(13));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetae(ind_show,:)),'Parent',ax(13));
    
    plot(Res.Stat(1).Space.phi,abs(Psi_thetao(ind_show,:)),'Parent',ax(14));
    plot(Res.Stat(1).Space.phi,real(Psi_thetao(ind_show,:)),'Parent',ax(14));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetao(ind_show,:)),'Parent',ax(14));
    
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_o(ind_show,:)).^2),'Parent',ax(15),'BaseValue',-70,'Marker','none','Color',[1,0,0]);
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_e(ind_show,:)).^2),'Parent',ax(15),'BaseValue',-70,'Marker','none','Color',[0,1,0]);
    ax(15).YLabel.String = strcat('Power (db)',Str_x,'=',num2str(delta_vector(ind_show)));
            
    ylim(ax(15),[-70,15]);
    ylim(ax(10),[-70,15]);
    ylim(ax(5), [-70,15]);
    
    xlim(ax(5),  80*[-Res.Stat(1).Space.k(2),Res.Stat(1).Space.k(2)] );
    xlim(ax(15),80*[-Res.Stat(1).Space.k(2),Res.Stat(1).Space.k(2)] );    
    xlim(ax(10),80*[-Res.Stat(1).Space.k(2),Res.Stat(1).Space.k(2)] );
 
    legend(ax(3),'$abs[\psi(\theta)]$','$Re[\psi(\theta)]$','$Im[\psi(\theta)]$','Interpreter','latex')
     
     
    ax(1).XLabel.String = Str_x;
    ax(2).XLabel.String = Str_x;
    ax(6).XLabel.String = Str_x;
    ax(7).XLabel.String = Str_x;
    ax(11).XLabel.String = Str_x;
    ax(12).XLabel.String = Str_x;

    ax(3).XLabel.String = '$\theta$';
    ax(4).XLabel.String = '$\theta$';
    ax(8).XLabel.String = '$\theta$';
    ax(9).XLabel.String = '$\theta$';
    ax(13).XLabel.String = '$\theta$';
    ax(14).XLabel.String = '$\theta$';

    ax(5).XLabel.String  = '$\mu$';
    ax(10).XLabel.String = '$\mu$';
    ax(15).XLabel.String = '$\mu$';
    
%%    
    figure;
    plot(delta_vector,V_vector,'Color',[0,0,0],'LineWidth',1);hold on; h = gca;
    plot(delta_vector(Stable),V_vector(Stable),'Color',[0,0,0],'LineWidth',4,'LineStyle','none','Marker','.','MarkerSize',12)
    h.XLabel.String  = Str_x;
    h.YLabel.String  = '$V/\kappa_o$';
    axes_Style(h);
%%

  %%  
    for i = 1:size(ax,2)
        
       axes_Style(ax(i));
       
    end
    
    function axes_Style(ax)

         ax.Box                  = 'on';
         ax.FontSize             = 15;
         ax.TickLabelInterpreter = 'latex';
         ax.XLabel.Interpreter   = 'latex';
         ax.YLabel.Interpreter   = 'latex';

    end
    