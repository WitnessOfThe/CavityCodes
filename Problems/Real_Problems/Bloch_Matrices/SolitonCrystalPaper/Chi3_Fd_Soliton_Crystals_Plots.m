    clc;
    clear all;
    warning('off')
%% Define Input Parameters in Physical Units

    R       =  Set_Up_Methods_For_Bloch_Matrices;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    R.Stat.In              = Params_SiN_For_Crytal_Paper;%Params_SiN_For_Crytal_Paper;    
    R.Stat.In.mu_bl        = 20;   
    R.Stat.Par.CW_num      = 3;
    
    W_WStar             = 2;   
    
    R.Stat.In.P       = W_WStar*pi/(R.Stat.In.eta*R.Stat.In.D(1)/R.Stat.In.kappa)*R.Stat.In.kappa/R.Stat.In.gamma;    
    R.CW.In           = R.Stat.In;
    
    R.Stat.In.N_mode  = 2^7;
    R.CW.In.N_mode    = 2^7;
    
%% Stationary Coefficeints

    R.Stat.Par.i_max                = 2000;
    R.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    R.Stat.Met.Newton               = @Newton_Manual_bicgstab;

    R.Stat(1).Par.Newton_tol       = 3E-11;  
    R.Stat(1).Par.Turning          =    0;
    R.Stat(1).Par.variable         = 'Fin_D';  %%'Pump Power';
    R.Stat(1).Par.bot_boundary     = 1E-5; % bottom boundary for delta to search in normalized units
    R.Stat(1).Par.top_boundary     =  1E8; % top boundary for delta to search in normalized units
    
    R.Stat(1).Par.Stability        = 0;
    
    R.Stat(1).Par.Newton_iter      = 200;
    R.Stat(1).Par.first_step       = 1E-4;
    R.Stat(1).Par.max_step         = 0.01;
    R.Stat(1).Par.step_dec         = 0.2;
    R.Stat(1).Par.step_tol         = 1E-9;
    R.Stat(1).Par.step_inc         = 1.01;  
    R.Stat.Par.i_max               = 500;

%%    
    R.CW.In.delta    = R.CW.In.kappa*W_WStar;

    R = Chi3_Stat_StartFromCW(R);
    R.Stat.Stab                 = Stability_Switcher(R.Stat);
    
    R.Stat  = R.Stat.Met.Norm(R.Stat);
    x_0     = R.Stat.In.Fin_D;
    
    Stat_1  =   BranchTurning([real(R.Stat.Sol.Psi_k),imag(R.Stat.Sol.Psi_k)]*R.Stat.Space.N,x_0,R.Stat,1);

%     R.CW.In.delta    = R.CW.In.kappa*W_WStar;
% 
%     R = Chi3_Stat_StartFromCW(R);
%     R.Stat.Stab                 = Stability_Switcher(R.Stat);
%     
%     R.Stat  = R.Stat.Met.Norm(R.Stat);
%     x_0     = R.Stat.Eq.(R.Stat.Par.variable);
%     
%     Fd_vector = linspace(1E-3,0.45,1000);
%     
%     for i = 2:size(Fd_vector,2)
%         
%          R.Stat(i)  = R.Stat(i-1);
%          R.Stat(i)  = ChangeFD(R.Stat(i),W_WStar,Fd_vector(i));
%          
%     end
%%
    Stat = R.Stat;
    parfor i = 1:size( Stat_1 ,2)
          Stat_1 (i).Stab                 = Stability_Switcher( Stat_1 (i));
         i             
    end
    R.Stat = Stat;
    clear Stat
%%
    f1 = figure('Position',[0,0,700,300],'Color',[1,1,1]);
    
    Panel1 = tiledlayout(1,3,'TileSpacing','none','Padding','none');
    
    axb(1) =  nexttile(Panel1,1,[1,1]);  
    axb(2) =  nexttile(Panel1,2,[1,1]);  
    axb(3) =  nexttile(Panel1,3,[1,1]);  
    hold(axb(1),'on');
    hold(axb(2),'on');
    hold(axb(3),'on');

    
  %  Plot_Static_Branch(Stat_1,axb);
  %  Plot_Static_Branch(Stat_2,axb);
   Plot_Static_Branch_Stable( Stat_1 ,axb);
%   axb(3).YLim  = [-0.05,0.05];
   clear f1
   clear axb
   clear Panel1
   %%
   f1 = figure('Position',[0,0,1400,900]/2,'Color',[1,1,1]);
    Panel = tiledlayout(2,2,'TileSpacing','none','Padding','none');
    
    ax(1) = nexttile(Panel,1,[1,1]);  
    ax(2) = nexttile(Panel,2,[1,1]);
    ax(3) = nexttile(Panel,3,[1,1]);  
    ax(4) = nexttile(Panel,4,[1,1]);
    %
    hold(ax(1),'on')
    hold(ax(2),'on')
    hold(ax(3),'on')
    hold(ax(4),'on')

    Plot_Static_StabilityK(Stat_1,3,ax(1:2))
    Plot_Static_StabilityK(Stat_1,-3,ax(3:4))
    ax(2).YLim = [-3.5,3.5]/10;
    ax(4).YLim = [-3.5,3.5]/10;
    ax(1).YLim = [0,0.5];
    ax(3).YLim = [0,0.5];
    
    
    clear f1
    clear ax
    clear Panel   
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
    
function Stat  = ChangeFD(Stat,delta,Fd)    

        Stat.In.kappa     = Stat.In.D(2)/Fd;
        Stat.In.delta     = Stat.In.kappa*delta;
        Stat.In.P         = Stat.In.W_WStar*pi/(Stat.In.eta*Stat.In.D(1)/Stat.In.kappa)*Stat.In.kappa/Stat.In.gamma; 
        
        x0                = [real(Stat.Sol.Psi_k),imag(Stat.Sol.Psi_k)]*Stat.Space.N;
        Stat              = Stat.Met.Norm(Stat);    
            
        [x,eps_f,SolveFlag]  =         Newton_Switcher(x0,Stat);
        eps_f
        Stat.Sol.Exitflag    =                       SolveFlag;
        Stat.Sol.eps         =                           eps_f;
        Stat                 =       Stat.Met.Prop_Gen(x,Stat);   
        
end
    function  Plot_Static_Branch_Stable(Stat_1,ax)

    Peak    =  NaN(1,size(Stat_1,2));
    delta   =  NaN(1,size(Stat_1,2));
    SmParam =  NaN(1,size(Stat_1,2));        
    ReLambda = NaN(size(Stat_1,2),100);
    
    for i = 1:size(Stat_1,2)
        
        Peak(i)       = max(abs(ifft(Stat_1(i).Sol.Psi_k.*Stat_1(i).Space.N)).^2);
        SmParam(i)    = real(Stat_1(i).Sol.V);
        delta(i)      = Stat_1(i).In.D(2)/Stat_1(i).In.kappa;
        kappa_Vect(i)    = Stat_1(i).In.kappa;
        ReLambda  = real(Stat_1(i).Stab.Values(real(Stat_1(i).Stab.Values)>0))/Stat_1(i).In.kappa;
        if ~isempty(ReLambda)
                Stable(i) = 1;
            if max(real(ReLambda)) > 1/Stat_1(i).In.kappa
                Stable(i) = 0;
            end
            plot(delta(i)*size(ReLambda,2),real(ReLambda).','Color',[0,0,0],'LineStyle','none','Marker','.','MarkerSize',15,'Parent',ax(3));
        else
                Stable(i) = 1;
        end
    end
    
    plot(delta,Peak,'Color',[0,0,0],'LineWidth',1,'Parent',ax(1),'LineStyle','--');
    plot(delta,SmParam,'Color',[0,0,0],'LineWidth',1,'Parent',ax(2),'LineStyle','--');
    
    PeakS              =  Peak;
    PeakS(Stable==0)   = NaN;
    SmParamS           = SmParam;
    SmParamS(Stable==0)= NaN;
    deltaS             = delta;
    deltaS(Stable==0)  = NaN;
    
    plot(deltaS,PeakS,'Color',[0,0,0],'LineWidth',2,'Parent',ax(1));
    plot(deltaS,SmParamS,'Color',[0,0,0],'LineWidth',2,'Parent',ax(2));
    
    
    ax(1).XLabel.String = '$\mathcal{F_d}$';
    ax(1).YLabel.String = 'Peak Power';
    ax(2).XLabel.String = '$\mathcal{F_d}$';
    ax(2).YLabel.String = 'V';
    ax(3).XLabel.String = '$\mathcal{F_d}$';
    ax(3).YLabel.String = 'Re[$\lambda^{(k)}_{\hat \mu}$]';
    
    axes_Style(ax(1));
    axes_Style(ax(2));
    axes_Style(ax(3));
 %   axes_Style(ax(4));
    end
function  Plot_Static_StabilityK(Stat_1,k,ax)

    [~,Id] = find(Stat_1(1).Stab.k == k);
    
    for i = 1:size(Stat_1,2)
        
        UnstLambda = unique( Stat_1(i).Stab.Values(Id,Stat_1(i).Stab.Values(Id,:)>1) )/Stat_1(i).In.kappa;
        
        ReLambda = uniquetol(real(Stat_1(i).Stab.Values(Id,:)))/Stat_1(i).In.kappa;
        ImLambda = uniquetol(imag(Stat_1(i).Stab.Values(Id,:)))/Stat_1(i).In.kappa;

        plot(Stat_1(i).In.D(2)/Stat_1(i).In.kappa*ones(size(ReLambda)),ReLambda...
                       ,'Color',[0,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(1),'MarkerSize',15);
                   
        plot(Stat_1(i).In.D(2)/Stat_1(i).In.kappa*ones(size(ImLambda)),ImLambda...
                       ,'Color',[0,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(2),'MarkerSize',15);
                   
        plot(Stat_1(i).In.D(2)/Stat_1(i).In.kappa*ones(size(UnstLambda)),real(UnstLambda)...
                       ,'Color',[1,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(1),'MarkerSize',15);
                   
        plot(Stat_1(i).In.D(2)/Stat_1(i).In.kappa*ones(size(UnstLambda)),imag(UnstLambda)...
                       ,'Color',[1,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(2),'MarkerSize',15);
        
    end
    
    
    ax(1).XLabel.String = '$\delta/\kappa$';
    ax(1).YLabel.String = '$Re[\lambda^{(k)}_{m}]$';
    ax(2).XLabel.String = '$\delta/\kappa$';
    ax(2).YLabel.String = '$Im[\lambda^{(k)}_{m}]$';
    
    axes_Style(ax(1));
    axes_Style(ax(2));
 %   axes_Style(ax(4));
end
    