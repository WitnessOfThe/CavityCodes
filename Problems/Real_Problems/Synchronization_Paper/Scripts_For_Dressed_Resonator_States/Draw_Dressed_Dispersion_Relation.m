    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    L_L.CW.In         = Params_CaF;
    L_L.CW.In.kappa   =  2*1E3*2*pi;                 
    L_L.CW.In.delta   = -4.9167e+05*2*pi;    
    L_L.CW.In.P       = 0.5;                 

%%
    N_mode        = 128;
    L_L.CW        = MI(L_L.CW,N_mode);
    Pure_State      = 1/2*L_L.CW.In.D(2)/2.*L_L.CW.Space.k.^2.';
    Dressed_State   = imag(L_L.CW.Stab(3).Value)*L_L.CW.Eq.norm;
    Dressed_State_1 = Pure_State+Dressed_State(:,1);%max(Dressed_State,[],2);
    Dressed_State_2 = Pure_State+Dressed_State(:,2);%min(Dressed_State,[],2);
%%

    t_pl = proPlot(fftshift(L_L.CW.Space.k),fftshift(Pure_State)/2/pi/1E6,[],'Marker','o');
    t_pl = t_pl.addData(fftshift(L_L.CW.Space.k),fftshift(Dressed_State_1)/2/pi/1E6,[],'Marker','o');
    t_pl = t_pl.addData(fftshift(L_L.CW.Space.k),fftshift(Dressed_State_2)/2/pi/1E6,[],'Marker','o');
    
    figure;
    t_pl.plotData
