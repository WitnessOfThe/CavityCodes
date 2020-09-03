    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    L_L.CW.In         =  Params_SiN;
    L_L.CW.In.kappa   =  1E8*2*pi;%2*1E3*2*pi;%
    L_L.CW.In.P       =  0.000000001; 

%%
  N = 1000;
  NN = N*50;
  N_Mode = 56;
  
  
  Mumber_Of_Modes = zeros(N);
  tic
  delta_vector  = linspace(-3.8,3,N);
  g_vector      = linspace(0,1,N);
    

  parfor i = 1:N      
      SiN = L_L;
      SiN.CW.In.delta =  delta_vector(i)*2*pi*1E9;
      SiN.CW          = SiN.Met.T_MI (SiN.CW,N_Mode);
      SiN.CW          = SiN.Met.T_Syn(SiN.CW,N_Mode);
      
      for ii = 1:N
          
          SiN.CW.In.g = g_vector(ii)*2*pi*1E9;
          SiN.CW      = SiN.CW.Met.Mi_Formula(SiN.CW,N_Mode);          
          Mumber_Of_Modes(ii,i) = sum( (SiN.CW.An.Omega_mu(1,1:(end/2-1)) == 0 ));
          
      end
      
      W_MI_vector_1(i,:)        = SiN.CW.In.g_MI(1,1:20)/(2*pi*1E9);
      W_MI_vector_2(i,:)        = SiN.CW.In.g_MI(2,1:20)/(2*pi*1E9);
      
      i
  end
  
%%
  L_L.CW.In.kappa   =  1.5E9*2*pi;%2*1E3*2*pi;%
  delta_vector_2 = linspace(min(delta_vector),max(delta_vector),NN);
  W_MI_vector_1_1 = zeros(NN,size(1:20,2));
  W_MI_vector_2_1 = zeros(NN,size(1:20,2));

 parfor i = 1:NN      
      
      SiN = L_L;
      SiN.CW.In.delta =  delta_vector_2(i)*2*pi*1E9;
      SiN.CW          = SiN.Met.T_MI (SiN.CW,N_Mode);
      SiN.CW          = SiN.Met.T_Syn(SiN.CW,N_Mode);      
      W_MI_vector_1_1(i,:)        = SiN.CW.In.g_MI(1,1:20)/(2*pi*1E9);
      W_MI_vector_2_1(i,:)        = SiN.CW.In.g_MI(2,1:20)/(2*pi*1E9);
      
      i
  end
%%
  L_L.CW.In.kappa   =  3E8*2*pi;%2*1E3*2*pi;%
  delta_vector_2 = linspace(min(delta_vector),max(delta_vector),NN);
  W_MI_vector_1_2 = zeros(NN,size(1:20,2));
  W_MI_vector_2_2 = zeros(NN,size(1:20,2));

  parfor i = 1:NN      
      
      SiN = L_L;
      SiN.CW.In.delta =  delta_vector_2(i)*2*pi*1E9;
      SiN.CW          = SiN.Met.T_MI (SiN.CW,N_Mode);
      SiN.CW          = SiN.Met.T_Syn(SiN.CW,N_Mode);      
      W_MI_vector_1_2(i,:)        = SiN.CW.In.g_MI(1,1:20)/(2*pi*1E9);
      W_MI_vector_2_2(i,:)        = SiN.CW.In.g_MI(2,1:20)/(2*pi*1E9);
      
      i
  end
%%
  L_L.CW.In.kappa   =  1E7*2*pi;%2*1E3*2*pi;%
  delta_vector_2 = linspace(min(delta_vector),max(delta_vector),NN);
  W_MI_vector_1_3 = zeros(NN,size(1:20,2));
  W_MI_vector_2_3 = zeros(NN,size(1:20,2));
  W_Synch_vector_1_3 = zeros(NN,1);
  W_Synch_vector_2_3 = zeros(NN,1);

  parfor i = 1:NN      
      
      SiN = L_L;
      SiN.CW.In.delta =  delta_vector_2(i)*2*pi*1E9;
      SiN.CW                = SiN.Met.T_MI (SiN.CW,N_Mode);
      SiN.CW                = SiN.Met.T_Syn(SiN.CW,2);   
      
      W_MI_vector_1_3(i,:)  = SiN.CW.In.g_MI(1,1:20)/(2*pi*1E9);
      W_MI_vector_2_3(i,:)  = SiN.CW.In.g_MI(2,1:20)/(2*pi*1E9);
      W_Synch_vector_1_3(i,:)  = SiN.CW.In.g_Synch(1,1)/(2*pi*1E9);
      W_Synch_vector_2_3(i,:)  = SiN.CW.In.g_Synch(2,1)/(2*pi*1E9);
      
      i
  end

%%


%%
    pp4 = proPlot(delta_vector,g_vector, Mumber_Of_Modes, 'PlotType','pcolor');
    W_Synch_vector_1_3(isnan(W_Synch_vector_1_3)) = 0;
    W_Synch_vector_2_3(isnan(W_Synch_vector_2_3)) = 0;
    for i = 1:1
          pp4 = pp4.addData([delta_vector_2,fliplr(delta_vector_2)],[W_Synch_vector_1_3(:,i);flipud(W_Synch_vector_2_3(:,i))], [], 'PlotType', 'Fill','Color',[0.5,0.5,0.5],'FaceAlpha', 0.5);
    end
          pp4 = pp4.addData(delta_vector_2,min(W_MI_vector_2_1(:,:),[],2),'Color',[1,1,0],'LineWidth',2.5);
    for i=1:15
          pp4 = pp4.addData(delta_vector_2,W_MI_vector_1_2(:,i),'Color',[0,1,1],'LineWidth',2.5);
          pp4 = pp4.addData(delta_vector_2,W_MI_vector_2_2(:,i),'Color',[0,1,1],'LineWidth',2.5);
    end
    for i=1:15
          pp4 = pp4.addData(delta_vector_2,W_MI_vector_1_3(:,i),'Color',[1,0,1],'LineWidth',2.5);
          pp4 = pp4.addData(delta_vector_2,W_MI_vector_2_3(:,i),'Color',[1,0,1],'LineWidth',2.5);
    end
    pp4 = pp4.changeAxisOptions('ColorMap', 'parula',...
                          'CAxis', [0,max(max(Mumber_Of_Modes))],'XLabelText','\delta_0 (GHz)','YLabelText',...
        'g (GHz)','FontSize',15,'XLabelText','$\delta_0$ (GHz)','XLim',[min(delta_vector),3]...
       ,'YLim',[min(g_vector),max(g_vector)],'Shading','flat');
    pp4 = pp4.changeFigOptions('Height',8,...
                     'Width',18);
    pp4 = pp4.addData([-3.6,0.72,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox',...
    'String', '$|\mu|$=14','FontSize',15,'Color',[1,1,1]);
    pp4 = pp4.addData([-3.2,0.58,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox',...
    'String', '$|\mu|$=13','FontSize',15,'Color',[1,1,1]);
    pp4 = pp4.addData([-2.71,0.47,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox',...
    'String', '$|\mu|$=12','FontSize',15,'Color',[1,1,1]);
    pp4 = pp4.addData([-2.07,0.585,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox',...
    'String', '$|\mu|$=11','FontSize',15,'Color',[1,1,1]);
    pp4 = pp4.addData([-1.4,0.7,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox',...
    'String', '$|\mu|$=10','FontSize',15,'Color',[1,1,1]);
    pp4 = pp4.addData([0.75,0.65,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox',...
    'String', '$|\mu|$=0','FontSize',15,'Color',[1,1,1]);

    pp4 = pp4.addData([-2.5,-2.347],[0.8649,0.797], [], 'PlotType', 'Annotation', 'AnnotationType',  'textarrow', 'String', '$Q =1.3\cdot10^5$','FontSize',15,'Color',[1,1,1],'HeadWidth',5,...
    'HeadLength',5);
    pp4 = pp4.addData([-1.145,-1.309],[0.3333,0.26], [], 'PlotType', 'Annotation', 'AnnotationType',  'textarrow', 'String', '$Q =6.6\cdot10^5$','FontSize',15,'Color',[1,1,1],'HeadWidth',5,...
    'HeadLength',5);
    pp4 = pp4.addData([0.4747,-0.03724],[0.086,0.06266], [], 'PlotType', 'Annotation', 'AnnotationType',  'textarrow', 'String', '$Q =2\cdot10^7$','FontSize',15,'Color',[1,1,1],'HeadWidth',5,...
    'HeadLength',5);
    W_Synch_vector_1_3((W_Synch_vector_1_3==0)) = NaN;
    W_Synch_vector_2_3((W_Synch_vector_2_3==0)) = NaN;

     pp4 = pp4.addData(delta_vector_2,W_Synch_vector_1_3,[],'Color',[0,0,0],'LineWidth',2.5,'LineStyle','--');
     pp4 = pp4.addData(delta_vector_2,W_Synch_vector_2_3,[],'Color',[0,1,0],'LineWidth',2.5,'LineStyle','--');

%%
figure;
pp4.plotData
cmap = colormap(gca);
%cmap(1,:) = 1; 
colormap(gca,cmap)
%h = colorbar;
%h = colorbar;
%h = colorbar;
%h.FontSize = 15;
%h.TickLabelInterpreter = 'latex';
%h.Label.String         = 'Number of Synchronized Modes';
%h.Label.Interpreter    = 'latex';
%h.Location             = 'northoutside';
%save('H:\Documents\MATLAB\Matlab_Repo\Problems\Cavity_Codes\Problems\Real_Problems\Synchronization_Paper\Scripts_To_Draw_Tongues\delta_g_plate','pp4')

%%
