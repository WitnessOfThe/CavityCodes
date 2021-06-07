    clear all;
    Res       = Set_Up_Methods_For_Bloch_Matrices;
    CW        = Res.CW;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    CW.In         = Params_SiN_For_Crytal_Paper;
    CW.In.range   = 2^8;
    CW.In.N_mode  = 2^8;
          
%%
    NN          = 10000;
    FdVector    = linspace(1E-3,2,NN);
    W_WStar     = 5;
    CW.In.delta = -CW.In.kappa*1.5;
    
%%
%     NN = 100;
%     CW.In.delta  = -CW.In.kappa*0.5;
%     CW.In.P      = W_WStar*pi/(CW.In.eta*CW.In.D(1)/CW.In.kappa)*CW.In.kappa/CW.In.gamma;  
%     CW           = CW.Met.Solve(CW);        
% %    D2_Vector    = 2*pi*linspace(1E3,1E5,NN);
%  %   Kappa_Vector = 2*pi*linspace(1E7,1E9,NN);
%     F_Vector  = linspace(100,1E3,NN);
%     Fd_Vector = linspace(1E-3,100,NN);
%     
%     parfor iFd = 1:NN
%         
%         CWW              = CW;
%         for iFF = 1:NN
%             
%             CWW.In.kappa     = CWW.In.D(1)/F_Vector(iFF);
%             CWW.In.D(2)      = CWW.In.kappa*Fd_Vector(iFd);
%         
%             CWW.In.delta     = -CWW.In.kappa*0.5;
%             CWW.In.P         = W_WStar*pi/(CWW.In.eta*CWW.In.D(1)/CWW.In.kappa)*CWW.In.kappa/CWW.In.gamma;  
%             [F_D(iFd,iFF)]   = CWW.In.D(2)/CWW.In.kappa;
%             [F(iFd,iFF)]     = CWW.In.D(1)/CWW.In.kappa;
%             [muMThr(iFd,iFF),deltaThr(iFd,iFF),WThr(iFd,iFF),H2Thr(iFd,iFF)] = Get_MuDeltaTreshold(CWW);
%         end
%         iFd 
%     end

%%
    mu    = zeros(1,NN);
    delta = zeros(1,NN);
    W     = zeros(1,NN);
    
    parfor i = 1:NN
        CWW = CW;
        CWW.In.kappa     = CWW.In.D(2)/FdVector(i);
        CWW.In.delta     = -CWW.In.kappa*1.5;
        CWW.In.P         = W_WStar*pi/(CWW.In.eta*CWW.In.D(1)/CWW.In.kappa)*CWW.In.kappa/CWW.In.gamma;  
        [mu(i),delta(i),W(i)] = Get_MuDeltaTreshold(CWW);
        i
    end
%%
W_WStar =2;
    CW.In.delta = CW.In.kappa*W_WStar;
    CW.In.P     = W_WStar*pi/(CW.In.eta*CW.In.D(1)/CW.In.kappa)*CW.In.kappa/CW.In.gamma;  
    CW          = CW.Met.Solve(CW);
    
    for i =1:NN
        CWW              = CW;
        CWW.In.kappa     = CWW.In.D(2)/FdVector(i);
        CWW.In.delta     = CWW.In.kappa*W_WStar;
        CWW.In.P         = W_WStar*pi/(CWW.In.eta*CWW.In.D(1)/CWW.In.kappa)*CWW.In.kappa/CWW.In.gamma;  
        [muMax(i)]       = Get_PeakMu(CWW);
        i
    end
%%
    NN = 100;
    CW.In.delta  = CW.In.kappa*2;
    CW.In.P      = W_WStar*pi/(CW.In.eta*CW.In.D(1)/CW.In.kappa)*CW.In.kappa/CW.In.gamma;  
    CW           = CW.Met.Solve(CW);        
%    D2_Vector    = 2*pi*linspace(1E3,1E5,NN);
 %   Kappa_Vector = 2*pi*linspace(1E7,1E9,NN);
    F_Vector  = linspace(1,1E4,NN);
    Fd_Vector = linspace(1E-4,0.5,NN);
    
    parfor iFd = 1:NN
        
        CWW              = CW;
        for iFF = 1:NN
            
            CWW.In.kappa     = CWW.In.D(1)/F_Vector(iFF);
            CWW.In.D(2)      = CWW.In.kappa*Fd_Vector(iFd);
        
            CWW.In.delta     = CWW.In.kappa*2;
            CWW.In.P         = W_WStar*pi/(CWW.In.eta*CWW.In.D(1)/CWW.In.kappa)*CWW.In.kappa/CWW.In.gamma;  
            [F_D(iFd,iFF)]   = CWW.In.D(2)/CWW.In.kappa;
            [F(iFd,iFF)]     = CWW.In.D(1)/CWW.In.kappa;
            [muMax(iFd,iFF),W(iFd,iFF),H(iFd,iFF)] = Get_PeakMu(CWW);
           
        end
        iFd 
    end
%%

    %%
    h = 700;
     f1 = figure('Position',[0,0,700,400],'Color',[1,1,1]);
    
    Panel1 = tiledlayout(1,4,'TileSpacing','none','Padding','none');
    
    axb(1) =  nexttile(Panel1,1,[1,1]);  
    axb(2) =  nexttile(Panel1,2,[1,1]);  
    axb(3) =  nexttile(Panel1,3,[1,1]);  
    axb(4) =  nexttile(Panel1,4,[1,1]);  
    
    pcolor(F,F_D,abs(muMThr),'Parent',axb(1));
    pcolor(F,F_D,deltaThr,'Parent',axb(2));
    pcolor(F,F_D,10*log10(abs(WThr)),'Parent',axb(3));
    pcolor(F,F_D,10*log10(abs(H2Thr)),'Parent',axb(4));

    for i = 1:size(axb,2)
        shading(axb(i),'flat');
        axb(i).XLabel.String = '$\mathcal{F}$';
        axb(i).YLabel.String = '$\mathcal{F}_d$';
        axes_Style(axb(i))
    end
%%
h = 700;
 f1 = figure('Position',[325.8,440.6,1050,300],'Color',[1,1,1]);
    
    Panel1 = tiledlayout(1,3,'TileSpacing','none','Padding','none');
    
    axb(1) =  nexttile(Panel1,1,[1,1]);  
    axb(2) =  nexttile(Panel1,2,[1,1]);  
    axb(3) =  nexttile(Panel1,3,[1,1]);  
%    axb(4) =  nexttile(Panel1,4,[1,1]);  
    
    semilogy(delta,FdVector,'Parent',axb(1),'Color',[0,0,0]);
    loglog(abs(mu),FdVector,'Parent',axb(2),'Color',[0,0,0]);
    loglog(abs(muMax),FdVector,'Parent',axb(3),'Color',[0,0,0]);
    
    axb(1).XLabel.String = '$\delta_{Thr}/\kappa$';

%     axb(2).YLabel.String = 'Corresponding $\mathcal{W}$ scaling';
%     axb(2).XLim          = [-1E-2,1];
%     axb(2).YLim          = [-60,30];
%     axb(2).YTick         = [-60:30:30];
%     axb(2).YTickLabel    = {'1$\mu$W','1$mW$','1W','1kW'};
%     axb(2).YTickLabelRotation = 90;

    axb(2).XLabel.String = '$\mu_{Thr}$';
 %   axb(2).YTickLabelRotation = 90;
    
    axb(3).XLabel.String = '$\mu_{max}$';
%    axb(3).YTickLabelRotation = 90;

    for i = 1:size(axb,2)
        axb(i).YLabel.String = '$\mathcal{F}_d$';
        axes_Style(axb(i))
    end
%%
axb(3).XTick = [1,10,100]
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
function [mu,delta,W,H2] = Get_MuDeltaTreshold(CW)   
    flag = 0;
    h    = 1E-1;
    coeff = 1;
    while flag == 0
        
        CW.In.delta                 = ((CW.In.delta/CW.In.kappa) + coeff*h)*CW.In.kappa;    
        CW                          = CW.Met.Norm(CW);        
        CW                          = CW.Met.Solve(CW);        
        CW                          = MI(CW);
        ind                         =  find(~isnan(CW.Sol.g)==1);
        if length(ind) > 1
            ind = 1;
        end
        [lambda,~]                  = max(real(CW.Stab(ind).Value),[],2);
        if max(lambda) >= 0
            if coeff*h <= 1E-6
                flag   = 1;
                ReLam = lambda(lambda>0);
                [MReLam]   = min(ReLam);
                mu    = CW.Space.k(find(lambda == MReLam));
                delta = CW.In.delta/CW.In.kappa;
                mu    = mu(1);
                delta = delta(1);
                W = CW.In.P;
                H2 = CW.In.H.^2;
                break;
            else
                CW.In.delta                 = ((CW.In.delta/CW.In.kappa) - coeff*h)*CW.In.kappa;    
                coeff                       = coeff/2;                          
            end
        else
            flag   = 0;
        end
        if CW.In.delta/CW.In.kappa > CW.In.W_WStar 
                mu    = NaN;
                delta = NaN;
                W     = NaN;
                H2     = NaN;
                break;
        end
    end
end
function [mu,W,H] = Get_PeakMu(CW)   
        CW                  = MI(CW);
        [~,ind]             = max(max(real(CW.Stab(1).Value),[],2));
        mu                  = CW.Space.k(ind);
        W                   = CW.In.W;
        H                   = CW.In.H;
end