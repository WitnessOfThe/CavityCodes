function [tt_1,tt_2] = Plot_LLE_Bloch_Static_Multiple_Branches(CW,Stat,Bran,ax)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%  
    hold(ax(1),'on');
    hold(ax(2),'on');

    for i = 1:size(Bran,2)
        
        ind_max(i) = size(Bran(i).Stat,2);
        
    end
    
%    P_Mode_P_U    = zeros( size(Bran,2), max(ind_max) );
    G_Mode_P_U    = NaN( size(Bran,2), max(ind_max) );
    G_Mode_P_2U = NaN( size(Bran,2), max(ind_max) );
 %   P_Mode_P_0    = zeros( size(Bran,2), max(ind_max) );
    G_Mode_P_0    = NaN( size(Bran,2), max(ind_max) );
    Power_Sol= NaN( size(Bran,2), max(ind_max) );
    delta_v_U     = NaN( size(Bran,2), max(ind_max) );
           
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    for i_b = 1:size(Bran,2)
        
        for i_d = 1: size(Bran(i_b).Stat,2)
        
            G_Mode_P_0(i_b,i_d) = abs(Bran(i_b).Stat(i_d).Sol.Psi_k(1)).^2*Bran(i_b).Stat(i_d).In.gamma/CW.In.kappa;
             G_Mode_P_U(i_b,i_d) = abs(Bran(i_b).Stat(i_d).Sol.Psi_k(2)).^2*Bran(i_b).Stat(i_d).In.gamma/CW.In.kappa;
%             G_Mode_P_2U(i_b,i_d) = abs(Bran(i_b).Stat(i_d).Sol.Psi_k(3)).^2*Bran(i_b).Stat(i_d).In.gamma/CW.In.kappa;
            Power_Sol(i_b,i_d)  = sum(abs(Bran(i_b).Stat(i_d).Sol.Psi_k(:)).^2)*Bran(i_b).Stat(i_d).In.gamma/Bran(i_b).Stat(i_d).In.kappa ; 
            delta_v_U (i_b,i_d) = Bran(i_b).Stat(i_d).Eq.delta;  
            
        
        end
        
    end
    
    delta_CW_vector = linspace(min(min(delta_v_U)),max(max(delta_v_U)),size(delta_v_U,2)*3 ); 
    WW_Statr    = ones(1,size(delta_v_U,2)*3)*Stat.In.P/Stat.In.W_Star;
    Psi_0_2      =   NaN(3,size(delta_v_U,2));
    
    G_MI_1         = NaN(3,size(delta_v_U,2));
    W_MI_1         = NaN(3,size(delta_v_U,2));
    G_MI_2         = NaN(3,size(delta_v_U,2));
    W_MI_2         = NaN(3,size(delta_v_U,2));
    
    for i_d = 1:size(delta_CW_vector,2)
        
          CW.In.delta    = delta_CW_vector(i_d)*CW.In.kappa;
         
          CW             = CW.Met.Solve(CW);          
          Psi_0_2(:,i_d) = abs(CW.Sol.Psi).^2*CW.In.gamma/CW.In.kappa;
          CW             =  Chi_3_LLE_MI_Boundary(CW);
          
          G_MI_1(:,i_d)    = CW.In.g_MI(1,[1,Stat.In.mu_bl+1,2*Stat.In.mu_bl+1])/CW.In.kappa;
          G_MI_2(:,i_d)    = CW.In.g_MI(2,[1,Stat.In.mu_bl+1,2*Stat.In.mu_bl+1])/CW.In.kappa;
          
          W_MI_1(:,i_d)    = CW.In.W_MI_Tongue(1,[1,Stat.In.mu_bl+1,2*Stat.In.mu_bl+1])/Stat.In.W_Star;
          W_MI_2(:,i_d)    = CW.In.W_MI_Tongue(2,[1,Stat.In.mu_bl+1,2*Stat.In.mu_bl+1])/Stat.In.W_Star;
          
    end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    switch Stat.Par.variable

        case   'Pump Power'

%            X_U = Power_v_U*1E3;
                        
 %           X_Text = 'Pump Power (mW)';

        case   'delta'

            X_U = delta_v_U;
            X_Text = '$\delta/\kappa$';

    end    
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%

 %   tt_1         = proPlot([],[],[]);
 %   tt_2         = proPlot([],[],[]);
  %  tt_3         = proPlot([],[],[]);
    i=1;
%        tt_1         = tt_1.addData(delta_CW_vector,G_MI_1(i,:),'Color',[0,0,0],'LineWidth',3);
%        tt_1         = tt_1.addData(delta_CW_vector,G_MI_2(i,:),'Color',[0,0,0],'LineWidth',3);
    plot(delta_CW_vector,G_MI_1(i,:),'Color',[0,0,0],'LineWidth',3,'Parent',ax(1))
    plot(delta_CW_vector,G_MI_2(i,:),'Color',[0,0,0],'LineWidth',3,'Parent',ax(1))
%         tt_2         = tt_2.addData(delta_CW_vector,W_MI_1(i,:),'Color',[0,0,0],'LineWidth',3);
%         tt_2         = tt_2.addData(delta_CW_vector,W_MI_2(i,:),'Color',[0,0,0],'LineWidth',3);
        
    for i = 2:size(G_MI_1,1)
        
  %      tt_1         = tt_1.addData(delta_CW_vector,G_MI_1(i,:),'Color',[0,0,0]);
  %      tt_1         = tt_1.addData(delta_CW_vector,G_MI_2(i,:),'Color',[0,0,0]);
    plot(delta_CW_vector,G_MI_1(i,:),'Color',[0,0,0],'Parent',ax(1))
    plot(delta_CW_vector,G_MI_2(i,:),'Color',[0,0,0],'Parent',ax(1))
%       tt_2         = tt_2.addData(delta_CW_vector,W_MI_1(i,:),'Color',[0,0,0]);
%       tt_2         = tt_2.addData(delta_CW_vector,W_MI_2(i,:),'Color',[0,0,0]);
        
    end
    
 %       tt_1         = tt_1.addData(delta_CW_vector,abs(Psi_0_2),'Color','m');
%    plot(delta_CW_vector,abs(Psi_0_2),'Color','m','Parent',ax(1))
    for i =1:size(X_U,1)
        
 %       tt_1         = tt_1.addData(X_U(i,:),G_Mode_P_0(i,:),'Color',[1,0,0],'LineStyle','--');
 %       tt_1         = tt_1.addData(X_U(i,:),G_Mode_P_U(i,:),'Color',[1,0,0],'LineStyle','-');
 %       tt_1         = tt_1.addData(X_U(i,:),G_Mode_P_2U(i,:),'Color',[0,0,1],'LineStyle','-');
 %   plot(X_U(i,:),G_Mode_P_0(i,:),'Color',[1,0,0],'LineStyle','--','Parent',ax(1))
    plot(X_U(i,:),G_Mode_P_U(i,:),'Color',[1,0,0],'LineStyle','-','Parent',ax(1))
 %   plot(X_U(i,:),G_Mode_P_2U(i,:),'Color',[0,0,1],'Parent',ax(1))
        
   %     tt_2         = tt_2.addData(X_U(i,:), Power_Sol(i,:),'Color',[0,0,1]);
      plot(X_U(i,:), Power_Sol(i,:),'Color',[0,0,1],'Color',[0,0,1],'Parent',ax(2))
        
    end    
    
                    
    Point_Detla   =   Stat.In.delta*ones(1,10)/Stat.In.kappa; 
    Height_Re     =   linspace(min(min([G_Mode_P_U,G_Mode_P_U])),max(max([G_Mode_P_U,G_Mode_P_U]))*1.1,10); 
    Height_Re_2   =   linspace(min(min(Power_Sol)),max(max(Power_Sol))*1.1,10); 
    
%    tt_1 = tt_1.addData();
%    tt_2 = tt_2.addData();
      plot(Point_Detla,Height_Re,'Marker','.','LineStyle','-','Color','m','Parent',ax(1))
      plot(Stat.In.delta/Stat.In.kappa, abs(Stat(1).Sol.Psi_k(2)).^2*Stat.In.gamma/CW.In.kappa,'Marker','*','LineStyle','none','Color','m','Parent',ax(1),'MarkerSize',6);
      plot(Point_Detla,Height_Re_2,'Marker','.','LineStyle','-','Color','m','Parent',ax(2))
      plot(Stat.In.delta/Stat.In.kappa, sum(abs(Stat.Sol.Psi_k(:)).^2)*Stat.In.gamma/Stat.In.kappa,'Marker','*','LineStyle','none','Color','m','Parent',ax(2),'MarkerSize',6);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

         ax(1).XLabel.String = X_Text;
         ax(1).YLabel.String = 'g$_{\mu}/\kappa$';
         ax(1).YLabel.Interpreter = 'latex';
         ax(1).XLim        = [min(min(delta_v_U)),max(max(delta_v_U))];
         ax(1).YLim        = [min([min([G_Mode_P_U,G_Mode_P_U])]),max([max([G_Mode_P_U,G_Mode_P_U])])*1.1];
         ax(1).FontSize             = 13;
         ax(1).XLabel.Interpreter   = 'latex';
         ax(1).TickLabelInterpreter = 'latex';
         ax(1).Box =                    'on';

         ax(2).XLabel.String = X_Text;
         ax(2).YLabel.String = '$\sum{|\psi_\mu|^2}$';
         ax(2).YLabel.Interpreter = 'latex';
         ax(2).XLim        = [min(min(delta_v_U)),max(max(delta_v_U))];
%         ax(2).YLim        = [min([min([G_Mode_P_U,G_Mode_P_U])]),max([max([G_Mode_P_U,G_Mode_P_U])])*1.1];
         ax(2).FontSize             = 13;
         ax(2).XLabel.Interpreter   = 'latex';
         ax(2).TickLabelInterpreter = 'latex';
         ax(2).Box =                    'on';
                    
%    tt_2         = tt_2.changeAxisOptions('XLabelText',X_Text,...
 %                       'YLabelText','$\mathcal{W}/\mathcal{W^*}$',...  
  %                      'FontSize',13);
   % tt_3         = tt_3.changeAxisOptions('XLabelText',X_Text,...
    %                    'YLabelText','Im[$\lambda/\kappa$]',...  
     %                   'FontSize',13);

%%
%     if Flag
%         
%         CF = conFigure([tt_1,tt_2],1,2, 'UniformPlots', true, 'Height',15, 'Width', 25,'Labels',false);
%        % ,tt_2,tt_3
%     end

end
