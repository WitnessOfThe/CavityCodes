    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    L_L.CW.In         = Params_SiN;
    L_L.CW.In.kappa   =  1E8*2*pi;%2*1E3*2*pi;%
    L_L.CW.In.P       = 0.2; 

%%
  N = 1000;   
  N_Mode = 30;
  
  delta_vector  = linspace(-0.9,-0.65,N);
  
  Re_lambda = zeros(2,N);
  Im_lambda = zeros(2,N);
  tic
  for i = 1:N
      CW = L_L.CW;        
      CW.In.delta =  delta_vector(i)*2*pi*1E9;
      
      CW      = MI(CW,N_Mode);
      Re_lambda(1,i) = max(real(CW.Stab(3).Value(7,:)))*CW.Eq.norm/1E6/2/pi;
      Re_lambda(2,i) = min(real(CW.Stab(3).Value(7,:)))*CW.Eq.norm/1E6/2/pi;
      Im_lambda(:,i) = imag(CW.Stab(3).Value(7,:))*CW.Eq.norm/1E6/2/pi;
       
  end
   toc
%%
fill_delta_vecotor = linspace(-0.8774,-0.8242,100);
pp4 = proPlot([fill_delta_vecotor,fliplr(fill_delta_vecotor)],[ones(1,100)*450,-ones(1,100)*450],[],'PlotType', 'fill','Color',[0.5,0.5,0.5]);
pp4 = pp4.addData(delta_vector,Re_lambda(1,:),[],'Color',[0,0,0],'LineStyle','--','LineWidth',2);
%pp4 = pp4.addData(delta_vector,Re_lambda(2,:),[],'Color',[0,0,0],'LineStyle','--');
pp4 = pp4.addData(delta_vector,Im_lambda(1,:),[],'Color',[0,0,1],'LineWidth',2);
pp4 = pp4.addData(delta_vector,Im_lambda(2,:),[],'Color',[0,0,1],'LineStyle','--','LineWidth',2);
pp4 = pp4.changeFigOptions('Height',4,...
                     'Width',4);
pp4 = pp4.changeAxisOptions('YLabelText','$\lambda_\mu$ (MHz)','XLabelText','','FontSize',14,'YLim',[-300,300],'XLim',[min(delta_vector),max(delta_vector)]);
pp4 = pp4.addData([-1.9,-100,0.1,0.1], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', 'Im[$\lambda_\mu$]','FontSize',14,'Color',[0,0,0]);

%%
%figure;
%pp4.plotData

%%
  L_L.CW.In.P       = 0.5; 
  Re_lambda = zeros(2,N);
  Im_lambda = zeros(2,N);
  tic
  for i = 1:N
      CW = L_L.CW;        
      CW.In.delta =  delta_vector(i)*2*pi*1E9;
      
      CW      = MI(CW,N_Mode);
      Re_lambda(1,i) = max(real(CW.Stab(3).Value(7,:)))*CW.Eq.norm/1E6/2/pi;
      Re_lambda(2,i) = min(imag(CW.Stab(3).Value(7,:)))*CW.Eq.norm/1E6/2/pi;
      Im_lambda(:,i) = imag(CW.Stab(3).Value(7,:))*CW.Eq.norm/1E6/2/pi;

  end
   toc
%%
    fill_delta_vecotor = linspace(-0.849,-0.6852,100);
    pp5 = proPlot([fill_delta_vecotor,fliplr(fill_delta_vecotor)],[ones(1,100)*450,-ones(1,100)*450],[],'PlotType', 'fill','Color',[0.5,0.5,0.5]);
    pp5 = pp5.addData(delta_vector,Re_lambda(1,:),[],'Color',[0,0,0],'LineStyle','--','LineWidth',2);
    pp5 = pp5.addData(delta_vector,Im_lambda(1,:),[],'Color',[0,0,1],'LineWidth',2);
    pp5 = pp5.addData(delta_vector,Im_lambda(2,:),[],'Color',[0,0,1],'LineStyle','--','LineWidth',2);
    pp5 = pp5.changeAxisOptions('YLabelText','...','XLabelText','$\delta_0$ (GHz)','FontSize',15,'YLim',[-200,200],'XLim',[min(delta_vector),max(delta_vector)]);

%%
pp5 = pp5.changeFigOptions('Height',4,...
                     'Width',4);
%pp4 = pp4.changeAxisOptions();
CF = conFigure([pp4,pp5],2,1, 'Height', 8, 'Width', 8,'Labels',false);
