    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    CaF.CW.In         = Params_CaF;
    CaF.CW.In.kappa   = 2*1E3*2*pi;
    CaF.CW.In.P       = 0.00000000001; 

%% Input Parameters for SiN

    SiN.CW.In         = Params_SiN;
    SiN.CW.In.kappa   = 1E8*2*pi;
    SiN.CW.In.P       = 0.00000000001;
    N_mode            = 2^2;
    
%%

  N         =                      1000;
  delta_CaF = linspace(-1E4,1E4,N)*2*pi;
  Psi_CaF   =                zeros(N,3);
  
for i =1:N
    
   CaF.CW.In.delta = delta_CaF(i);
   CaF.CW          = CaF.CW.Met.Solve(CaF.CW,N_mode); % dispersion of the
   Psi_CaF(i,:)    = CaF.CW.Sol.Psi;
   
end
%%
  N = 1000;
  delta_SiN = linspace(-1E9,1E9,N)*2*pi;
  Psi_SiN   =     zeros(N,3);
  
for i =1:N
    
   SiN.CW.In.delta = delta_SiN(i);
   SiN.CW          = SiN.CW.Met.Solve(SiN.CW,N_mode); % dispersion of the
   Psi_SiN(i,:)    = SiN.CW.Sol.Psi;
   
end

%%
    Psi_CaF = abs(Psi_CaF)./max(max(abs(Psi_CaF)));
    
    Psi_SiN= abs(Psi_SiN)./max(max(abs(Psi_SiN)));
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
    
%     Numbers = -3:2;
% 
%     shift = CaF.CW.In.D(1)*i+1/2*CaF.CW.In.D(2)*Numbers(1)^2;    
%     
%     tt_1 = proPlot((delta_CaF+shift)/2/pi/1E9,abs(Psi_CaF(:,3)).^2,[],'Color',[1,0,0]);
% 
%     
% for i = Numbers(2:end)
%     
%     shift = CaF.CW.In.D(1)*i+1/2*CaF.CW.In.D(2)*i^2;    
%     tt_1 = tt_1.addData((delta_CaF+shift)/2/pi/1E9,abs(Psi_CaF(:,3)).^2,[],'Color',[1,0,0]);
%     
% end
% 
%     tt_1 = tt_1.changeAxisOptions('XTick',[],'XLabelText','$\omega_\mu-\omega_0$ (GHz)',...
%                          'YLabelText','','YTickLabel','',...  
%                          'FontSize',12,...
%                          'XLim',[-35,35]);
% 
%     tt_1 = tt_1.changeFigOptions('Height',7.5/2,...
%                      'Width',18/2);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%

    Numbers = -3:2;
    shift = SiN.CW.In.D(1)*Numbers(1)-1/2*SiN.CW.In.D(2)*Numbers(1)^2;    
    
    tt_2 = proPlot((delta_SiN+shift)/2/pi/1E12,abs(Psi_SiN(:,3)).^2,[],'Color',[1,0,0]);
    
for i = Numbers(2:end)
    
    shift = SiN.CW.In.D(1)*i-1/2*SiN.CW.In.D(2)*i^2;    
    tt_2 = tt_2.addData((delta_SiN+shift)/2/pi/1E12,abs(Psi_SiN(:,3)).^2,[],'Color',[1,0,0]);
    
end
    tt_2 = tt_2.changeAxisOptions('XLabelText','$\omega_\mu-\omega_0$ (THz)',...
                         'YLabelText','','YTickLabel','',...  
                         'FontSize',12,...
                         'XLim',[-2.5,2.5],'YLim',[0,1.4],'YColor',[1,1,1]);

    tt_2 = tt_2.changeFigOptions('Height',7.5/2,...
                     'Width',18/2);
    tt_2 = tt_2.addData([-0.23,1.4,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$\mu=0$','FontSize',14);
    tt_2 = tt_2.addData([-1.23,1.4,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$\mu=-1$','FontSize',14);
    tt_2 = tt_2.addData([-2.23,1.4,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$\mu=-2$','FontSize',14);
    tt_2 = tt_2.addData([-0.23+1,1.4,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$\mu=1$','FontSize',14);
    tt_2 = tt_2.addData([-0.23+2,1.4,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$\mu=2$','FontSize',14);
    
    tt_2 = tt_2.addData([-2,-1],[0.8,0.8], [], 'PlotType', 'Annotation', 'AnnotationType', 'doublearrow','LineWidth',1,'Head2Width',5,...
    'Head2Length',5,...
    'Head1Width',5,...
    'Head1Length',5);
    tt_2 = tt_2.addData([-1,0],[0.8,0.8], [], 'PlotType', 'Annotation', 'AnnotationType', 'doublearrow','LineWidth',1,'Head2Width',5,...
    'Head2Length',5,...
    'Head1Width',5,...
    'Head1Length',5);
    tt_2 = tt_2.addData([0,1],[0.8,0.8], [], 'PlotType', 'Annotation', 'AnnotationType', 'doublearrow','LineWidth',1,'Head2Width',5,...
    'Head2Length',5,...
    'Head1Width',5,...
    'Head1Length',5);
    tt_2 = tt_2.addData([1,2],[0.8,0.8], [], 'PlotType', 'Annotation', 'AnnotationType', 'doublearrow','LineWidth',1,'Head2Width',5,...
    'Head2Length',5,...
    'Head1Width',5,...
    'Head1Length',5);

    tt_2 = tt_2.addData([-1.9,0.7,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$D_1-\frac{3}{2}D_2$','FontSize',14);
    tt_2 = tt_2.addData([-0.9,0.7,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$D_1-\frac{1}{2}D_2$','FontSize',14);
    tt_2 = tt_2.addData([-0.9+1,0.7,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$D_1+\frac{1}{2}D_2$','FontSize',14);
    tt_2 = tt_2.addData([-0.9+2,0.7,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$D_1+\frac{3}{2}D_2$','FontSize',14);
    
    tt_2 = tt_2.changeFigOptions('Height',7.5/2,...
                     'Width',18);
%    figure;
 %   tt_2.plotData
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
% 
%     Numbers = 0:20;
% 
%     shift = 1/2*CaF.CW.In.D(2)*Numbers(1)^2;    
%     
%     tt_3  = proPlot((delta_CaF+shift)/2/pi/1E3,abs(Psi_CaF(:,3)).^2,[],'Color',[1,0,0]);
% 
%     
% for i = Numbers(2:end)
%     
%     shift = 1/2*CaF.CW.In.D(2)*i^2;    
%     tt_3 = tt_3.addData((delta_CaF+shift)/2/pi/1E3,abs(Psi_CaF(:,3)).^2,[],'Color',[1,0,0]);
%     
% end
% 
%     tt_3 = tt_3.changeAxisOptions('XLabelText','Im$\lambda_{\mu}^--\delta_0$ (GHz)',...
%                          'YLabelText','','YTickLabel','',...  
%                          'FontSize',12,...
%                          'XLim',[-10,10],'YLim',[0,1.4],'YColor',[1,1,1]);
% 
%     tt_3 = tt_3.changeFigOptions('Height',7.5/2,...
%                      'Width',18/2,'YColor',[1,1,1]);
%                  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
    Numbers = -6:2;
    shift = -1/2*SiN.CW.In.D(2)*Numbers(1)^2;    
    
    tt_4  = proPlot((delta_SiN+shift)/2/pi/1E9,abs(Psi_SiN(:,3)).^2,[],'Color',[1,0,0]);

    
for i = Numbers(1:end)
    
    shift = -1/2*SiN.CW.In.D(2)*i^2;    
    tt_4 = tt_4.addData((delta_SiN+shift)/2/pi/1E9,abs(Psi_SiN(:,3)).^2,[],'Color',[1,0,0]);
    
end

    tt_4 = tt_4.changeAxisOptions('XLabelText','Im$\lambda_{\mu}^++\delta_0$ (GHz)',...
                         'YLabelText','','YTickLabel','',...  
                         'FontSize',12,...
                         'XLim',[-0.5,0.2],'YLim',[0,1.45],'YColor',[1,1,1]);

    tt_4 = tt_4.changeFigOptions('Height',7.5/2,...
                     'Width',18/2);
    tt_4 = tt_4.addData([-0.5,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=4$','FontSize',14);
    tt_4 = tt_4.addData([-0.33,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=3$','FontSize',14);
    tt_4 = tt_4.addData([-0.19,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=2$','FontSize',14);
    tt_4 = tt_4.addData([-0.05,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=1$','FontSize',14);
    tt_4 = tt_4.addData([0.05,1,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$\mu=0$','FontSize',14);
    

%%
    Numbers = -6:2;
    shift = -1/2*SiN.CW.In.D(2)*Numbers(1)^2;    
    
    tt_5  = proPlot((delta_SiN+shift)/2/pi/1E9,abs(Psi_SiN(:,3)).^2,[],'Color',[1,0,0]);

    
for i = Numbers(1:end)
    
    shift = 1/2*SiN.CW.In.D(2)*i^2;    
    tt_5 = tt_5.addData((delta_SiN+shift)/2/pi/1E9,abs(Psi_SiN(:,3)).^2,[],'Color',[1,0,0]);
    
end

    tt_5 = tt_5.changeAxisOptions('XLabelText','Im$\lambda_{\mu}^--\delta_0$ (GHz)',...
                         'YLabelText','','YTickLabel','',...  
                         'FontSize',12,...
                         'XLim',[-0.2,0.5],'YLim',[0,1.45],'YColor',[1,1,1]);

    tt_5 = tt_5.changeFigOptions('Height',7.5/2,...
                     'Width',18/2);
    tt_5 = tt_5.addData([-0.5,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=4$','FontSize',14);
    tt_5 = tt_5.addData([-0.33,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=3$','FontSize',14);
    tt_5 = tt_5.addData([-0.19,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=2$','FontSize',14);
    tt_5 = tt_5.addData([-0.05,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=1$','FontSize',14);
    tt_5 = tt_5.addData([0.05,1,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$\mu=0$','FontSize',14);
%figure;
%tt_5.plotData
%%
    CaF.CW.In.kappa   = 2*1E4*2*pi;
    SiN.CW.In.kappa   = 1E9*2*pi;

  N         =                      1000;
  delta_CaF = linspace(-1E5,1E5,N)*2*pi;
  Psi_CaF   =                zeros(N,3);
  
for i =1:N
    
   CaF.CW.In.delta = delta_CaF(i);
   CaF.CW          = CaF.CW.Met.Solve(CaF.CW,N_mode); % dispersion of the
   Psi_CaF(i,:)    = CaF.CW.Sol.Psi;
   
end
%%
  N = 1000;
  delta_SiN = linspace(-4E9,4E9,N)*2*pi;
  Psi_SiN   =     zeros(N,3);
  
for i =1:N
    
   SiN.CW.In.delta = delta_SiN(i);
   SiN.CW          = SiN.CW.Met.Solve(SiN.CW,N_mode); % dispersion of the
   Psi_SiN(i,:)    = SiN.CW.Sol.Psi;
   
end
%%

    Psi_CaF = abs(Psi_CaF)./max(max(abs(Psi_CaF)));    
    Psi_SiN = abs(Psi_SiN)./max(max(abs(Psi_SiN)));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%

% 
%     shift = 1/2*CaF.CW.In.D(2)*Numbers(1)^2;    
%     
%     tt_5  = proPlot((delta_CaF+shift)/2/pi/1E3,abs(Psi_CaF(:,3)).^2,[],'Color',[1,0,0]);
% 
%     
% for i = Numbers(2:end)
%     
%     shift = 1/2*CaF.CW.In.D(2)*i^2;    
%     tt_5 = tt_5.addData((delta_CaF+shift)/2/pi/1E3,abs(Psi_CaF(:,3)).^2,[],'Color',[1,0,0]);
%     
% end
% 
%     tt_5 = tt_5.changeAxisOptions('XLabelText','Im$\lambda_{\mu}^--\delta_0$ (GHz)',...
%                          'YLabelText','','YTickLabel','',...  
%                          'FontSize',12,...
%                          'XLim',[-10,75],'YLim',[0,1.4],'YColor',[1,1,1]);
% 
%     tt_5 = tt_5.changeFigOptions('Height',7.5/2,...
%                      'Width',18/2);
%                  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
    Numbers = 0:20;
    
    
    shift = -1/2*SiN.CW.In.D(2)*Numbers(1)^2;    
    
    tt_6  = proPlot((delta_SiN+shift)/2/pi/1E9,abs(Psi_SiN(:,3)).^2,[],'Color',[1,0,0]);

    
for i = Numbers(2:end)
    
    shift = -1/2*SiN.CW.In.D(2)*i^2;    
    tt_6 = tt_6.addData((delta_SiN+shift)/2/pi/1E9,abs(Psi_SiN(:,3)).^2,[],'Color',[1,0,0]);
    
end

    tt_6 = tt_6.changeAxisOptions('XLabelText','Im$\lambda_{\mu}^--\delta_0$ (GHz)',...
                         'YLabelText','','YTickLabel','',...  
                         'FontSize',12,...
                         'XLim',[-3.8,0.5],'YColor',[1,1,1]);

    tt_6 = tt_6.changeFigOptions('Height',7.5/2,...
                     'Width',18/2);
    tt_6 = tt_6.addData([-0.5,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=4$','FontSize',14);
    tt_6 = tt_6.addData([-0.33,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=3$','FontSize',14);
    tt_6 = tt_6.addData([-0.19,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=2$','FontSize',14);
    tt_6 = tt_6.addData([-0.05,1.45,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=1$','FontSize',14);
    tt_6 = tt_6.addData([0.05,1,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$\mu=0$','FontSize',14);
                 
%%                 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                 
figure;
tt_4.plotData
figure;
cf_1 = conFigure([tt_4,tt_6,tt_5,tt_7], 2,2,'Labels',false, 'UniformPlots', true,'Units','centimeters', 'Height', 7, 'Width', 18,'separation', 3);

%% (a) Annotation
figure1 = gcf;
annotation(figure1,'textbox',[0.389789712260312 0.921513886559672 0 0],...
    'String','$\mu=0$',...
    'LineWidth',1,...
    'Interpreter','latex',...
    'FontSize',14,...
    'FitBoxToText','off',...
    'EdgeColor','none');
annotation(figure1,'textbox',[0.322870147267262 0.92 0.1 0.1],...
    'String','$|\mu|=1$',...
    'LineWidth',1,...
    'Interpreter','latex',...
    'FontSize',14,...
    'FitBoxToText','off',...
    'EdgeColor','none');
annotation(figure1,'textbox',[0.231829815100525 0.92 0.1 0.1],...
    'String','$|\mu|=2$',...
    'LineWidth',1,...
    'Interpreter','latex',...
    'FontSize',14,...
    'FitBoxToText','off',...
    'EdgeColor','none');
annotation(figure1,'textbox',[0.130495365286728 0.92 0.1 0.1],...
    'String','$|\mu|=3$',...
    'LineWidth',1,...
    'Interpreter','latex',...
    'FontSize',14,...
    'FitBoxToText','off',...
    'EdgeColor','none');


annotation(figure1,'textbox',[0.027614457739722 0.92 0.1 0.1],...
    'String','$|\mu|=4$',...
    'LineWidth',1,...
    'Interpreter','latex',...
    'FontSize',14,...
    'FitBoxToText','off',...
    'EdgeColor','none');
%% (b)

annotation(figure1,'textbox',[0.374673281269134 0.4 0.1 0.1],...
    'String','$|\mu|=4$',...
    'LineWidth',1,...
    'Interpreter','latex',...
    'FontSize',14,...
    'FitBoxToText','off',...
    'EdgeColor','none');
annotation(figure1,'textbox',[0.267260071169081 0.4 0.1 0.1],...
    'String','$|\mu|=3$',...
    'LineWidth',1,...
    'Interpreter','latex',...
    'FontSize',14,...
    'FitBoxToText','off',...
    'EdgeColor','none');


annotation(figure1,'textbox',[0.174476873924054 0.4 0.1 0.1],...
    'String','$|\mu|=2$',...
    'LineWidth',1,...
    'Interpreter','latex',...
    'FontSize',14,...
    'FitBoxToText','off',...
    'EdgeColor','none');
annotation(figure1,'textbox',[0.062576029620203 0.4 0.1 0.1],...
    'String','$|\mu|=1$',...
    'LineWidth',1,...
    'Interpreter','latex',...
    'FontSize',14,...
    'FitBoxToText','off',...
    'EdgeColor','none');

annotation(figure1,'textbox',[0.030966182848547 0.389438414861559 0 0],...
    'String','$\mu=0$',...
    'LineWidth',1,...
    'Interpreter','latex',...
    'FontSize',14,...
    'FitBoxToText','off',...
    'EdgeColor','none');



