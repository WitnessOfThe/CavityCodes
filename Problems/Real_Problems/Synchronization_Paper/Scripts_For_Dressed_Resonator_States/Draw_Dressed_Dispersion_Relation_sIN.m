    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    L_L.CW.In         = Params_SiN;
    L_L.CW.In.kappa   =  1E8*2*pi;                 
    L_L.CW.In.delta   = 3e+09*2*pi;    
    L_L.CW.In.P       = 0.05;                 

%%

    N_mode          = 32;
    L_L.CW          = MI(L_L.CW,N_mode);
    Pure_State      = 0;
    Dressed_State   = imag(L_L.CW.Stab(1).Value)*L_L.CW.Eq.norm;
    Dressed_State_1 = Dressed_State(:,1);%max(Dressed_State,[],2);
    Dressed_State_2 = Dressed_State(:,2);%min(Dressed_State,[],2);
    
%%

%     t_pl = proPlot(fftshift(L_L.CW.Space.k),fftshift(Pure_State)/2/pi/1E6,[],'Marker','o','FaceAlpha',0.5);
%     t_pl = t_pl.addData(fftshift(L_L.CW.Space.k),fftshift(Pure_State)/2/pi/1E6, ones(1,N_mode)*L_L.CW.In.kappa/2/2/pi/1E6,...
%                     'PlotType', 'errorbar', ...
%                     'Color', [238, 102, 119]/255,...
%                     'LineStyle', 'none',...
%                     'UIStack','bottom');
    t_pl = proPlot(fftshift(L_L.CW.Space.k),fftshift(Dressed_State_1)/2/pi/1E6,[],'Marker','o');
    t_pl = t_pl.addData(fftshift(L_L.CW.Space.k),fftshift(Dressed_State_1)/2/pi/1E6, ones(1,N_mode)*L_L.CW.In.kappa/2/2/pi/1E6,...
                    'PlotType', 'errorbar', ...
                    'Color', [238, 102, 119]/255,...
                    'LineStyle', 'none',...
                    'UIStack','bottom');
    t_pl = t_pl.addData(fftshift(L_L.CW.Space.k),fftshift(Dressed_State_2)/2/pi/1E6,[],'Marker','o');
    t_pl = t_pl.addData(fftshift(L_L.CW.Space.k),fftshift(Dressed_State_2)/2/pi/1E6, ones(1,N_mode)*L_L.CW.In.kappa/2/2/pi/1E6,...
                    'PlotType', 'errorbar', ...
                    'Color', [238, 102, 119]/255,...
                    'LineStyle', 'none',...
                    'UIStack','bottom');

    figure;
    t_pl.plotData
    
%%
