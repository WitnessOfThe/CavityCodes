    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    Res       = Set_Up_Methods_For_Bloch_Matrices;
%%    
    CW        = Res.CW;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    CW.In         = Params_SiN_For_Crytal_Paper;
    CW.In.range   = 2^6;
          
%%

    NN                  = 1000;
    delta_vector        = CW.In.kappa*linspace(-6,2.2,NN);
    W_WStar             = 2;
    CW.In.P             = W_WStar*pi/(CW.In.eta*CW.In.D(1)/CW.In.kappa)*CW.In.kappa/CW.In.gamma;  
    CW.In.N_mode         = 2^8;
    
    R   = Get_CW_Tongues(CW,delta_vector,NN);
    Lambda = Get_MI_Scan(CW,delta_vector,6,NN);
    
%%
    f  = figure('Color',[1,1,1]);hold on;
    
    ax = gca;
    hold(ax,'on');
    
    plot(R.d/CW.In.kappa,R.g/CW.In.kappa,'LineStyle','none','Marker','.','Parent',ax,'Color','m');
% %     
    for ii =1:30
        
        plot(delta_vector/CW.In.kappa,R.Tongue_b1(:,ii)/CW.In.kappa,'Color',[0,0,0],'LineWidth',0.25,'Parent',ax);
        plot(delta_vector/CW.In.kappa,R.Tongue_b2(:,ii)/CW.In.kappa,'Color',[0.00,0.00,1.00],'LineWidth',0.5,'Parent',ax);

        plot(delta_vector/CW.In.kappa,R.Tongue_S1(:,ii)/CW.In.kappa,'Color',[0,0,0],'LineWidth',0.25,'Parent',ax,'LineStyle','--');
        plot(delta_vector/CW.In.kappa,R.Tongue_S2(:,ii)/CW.In.kappa,'Color',[0.00,0.00,1.00],'LineWidth',0.5,'Parent',ax,'LineStyle','--');
        
        [~,idd] = min(abs(R.Tongue_b2(:,ii).'/CW.In.kappa - R.g2/CW.In.kappa));
        plot(delta_vector(idd)/CW.In.kappa,R.Tongue_b2(idd,ii)/CW.In.kappa,'Marker','.','MarkerSize',10,'Parent',ax,'Color',[0,0,1]);        
    end
%     for ii =1:13
% 
%         [~,idd] = min(abs(R.Tongue_b1(:,ii).'/CW.In.kappa - R.g1/CW.In.kappa));
%         plot(delta_vector(idd)/CW.In.kappa,R.Tongue_b1(idd,ii)/CW.In.kappa,'Marker','.','MarkerSize',10,'Parent',ax,'Color',[0,0,0]);        
%     end
%     for ii =14:15
% 
%         [~,idd] = min(abs(R.Tongue_b1(:,ii).'/CW.In.kappa - R.g3/CW.In.kappa));
%         plot(delta_vector(idd)/CW.In.kappa,R.Tongue_b1(idd,ii)/CW.In.kappa,'Marker','.','MarkerSize',10,'Parent',ax,'Color',[0,0,0]);        
%     end
    
%     for ii =1:13
%         [~,idd] = min(abs(R.Tongue_b1(:,ii).'/CW.In.kappa - R.g1/CW.In.kappa));
%         plot(delta_vector(idd)/CW.In.kappa,R.Tongue_b1(idd,ii)/CW.In.kappa,'Marker','.','MarkerSize',10,'Parent',ax,'Color',[0,0,0]);
% %     end
%     for ii = 30:60
%         
%         plot(delta_vector/CW.In.kappa,R.Tongue_b1(:,ii)/CW.In.kappa,'Color',[0,0,0],'LineWidth',0.25,'Parent',ax);
%         plot(delta_vector/CW.In.kappa,R.Tongue_b2(:,ii)/CW.In.kappa,'Color',[0,0,0],'LineWidth',0.25,'Parent',ax);
%         
%     end
%     
    ax.YLim = [0,W_WStar*1.1];
    ax.XLim = [min( delta_vector ),max( delta_vector )]/CW.In.kappa;
    
    ax.XLabel.String = '$\delta/\kappa$';
    ax.YLabel.String = '$g/\kappa$';   
    axes_Style(ax);
%%

%% 
function axes_Style(ax)

     ax.Box                  = 'on';
     ax.Layer               = 'top';
     ax.FontSize             = 13;
     ax.LineWidth            = 1;
     ax.TickLabelInterpreter = 'latex';
     ax.XLabel.Interpreter   = 'latex';
     ax.YLabel.Interpreter   = 'latex';
     ax.XLabel.FontSize   = 15;
     ax.YLabel.FontSize   = 15;

end
function Res = Get_CW_Tongues(CW,delta_vector,NN)

    Res.Tongue_b1 = zeros(NN,CW.In.N_mode/2);
    Res.Tongue_b2 = zeros(NN,CW.In.N_mode/2);
    Res.Tongue_S1 = zeros(NN,CW.In.N_mode/2);
    Res.Tongue_S2 = zeros(NN,CW.In.N_mode/2);
    
    Res.delta_t  = delta_vector;
    Res.g        = NaN(3,NN);

    for i = 1:size(delta_vector,2)
        
        CW.In.delta    = delta_vector(i);
        CW             = CW.Met.Solve(CW);
        CW             = CW.Met.T_MI(CW);
        CW             = CW.Met.T_Syn(CW);
        
        Res.g(:,i)         = CW.Sol.g*CW.Eq.norm;
        Res.Tongue_b1(i,:) = CW.In.g_MI(1,1:CW.In.N_mode/2);
        Res.Tongue_b2(i,:) = CW.In.g_MI(2,1:CW.In.N_mode/2);
        Res.Tongue_S1(i,:) = CW.In.g_Synch(1,1:CW.In.N_mode/2);
        Res.Tongue_S2(i,:) = CW.In.g_Synch(2,1:CW.In.N_mode/2);
        
    end
    
    Res.g2 = Res.g(2,:);
    Res.g2(isnan( Res.g2)) = 0;
    Res.g1 = Res.g(1,:);
    Res.g1(isnan( Res.g1)) = 0;
    Res.g3 = Res.g(3,:);
    Res.g3(isnan( Res.g3)) = 0;
    
    g1 = Res.g(1,:);
    d1 = delta_vector;
    d1(isnan(g1)) = [];
    g1(isnan(g1)) = [];
    
    g2 = fliplr(Res.g(2,:));
    d2 = fliplr(delta_vector);
    d2(isnan(g2)) = [];    
    g2(isnan(g2)) =[];
    
    g3 = Res.g(3,:);
    d3 = delta_vector;
    d3(isnan(g3)) = [];
    g3(isnan(g3)) = [];
    
    Res.g = [g1,g2,g3];
    Res.d = [d1,d2,d3];
end
function Lambda = Get_MI_Scan(CW,delta_vector,mu,NN)

    Lambda = zeros(NN,2);
    
    for i = 1:size(delta_vector,2)
        
        CW.In.delta    = delta_vector(i);
        CW             = MI(CW);        
        Lambda(i,:)    = CW.Stab(3).Value(CW.Space.k == mu,:);
        
    end
    
end
    