    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN

    SiN.CW.In         = Params_SiN;
    SiN.CW.In.kappa   = 1E8*2*pi;
    SiN.CW.In.P       = 0.00000000001;
    N_mode            = 2^2;
    
%%
  N = 1000;
  delta_SiN = linspace(-1E9,1E9,N)*2*pi;
  Psi_SiN   =     zeros(N,3);
  
for i =1:N
    
   SiN.CW.In.delta = delta_SiN(i);
   SiN.CW          = SiN.CW.Met.Solve(SiN.CW,N_mode); % dispersion of the
   Psi_SiN(i,:)    = SiN.CW.Sol.Psi;
   
end

    
    Psi_SiN= abs(Psi_SiN)./max(max(abs(Psi_SiN)));
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
 Numbers = [0:20]
    shift = -1/2*SiN.CW.In.D(2)*Numbers(1)^2;    
    
    tt_1  = proPlot((delta_SiN+shift)/2/pi/1E9,abs(Psi_SiN(:,3)).^2,[],'Color',[1,0,0]);

    
for i = Numbers(2:end)
    
    shift = -1/2*SiN.CW.In.D(2)*i^2;    
    tt_1 = tt_1.addData((delta_SiN+shift)/2/pi/1E9,abs(Psi_SiN(:,3)).^2,[],'Color',[1,0,0]);
    
end

    tt_1 = tt_1.changeAxisOptions('XLabelText','Im$\lambda_{\mu}^++\delta_0$ (GHz)',...
                         'YLabelText','','YTickLabel','',...  
                         'FontSize',12,...
                         'XLim',[-0.5,0.5],'YLim',[0,1.4]);

    tt_1 = tt_1.changeFigOptions('Height',7.5/2,...
                     'Width',18/2);
                 
%%
figure1=figure;
cf = conFigure([tt_1,tt_1,tt_1,tt_1], 4,1,'Labels',false, 'UniformPlots', true,'Units','centimeters', 'Height', 15, 'Width', 25,'separation', 3);


