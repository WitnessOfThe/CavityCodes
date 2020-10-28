    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    L_L.CW.In         =  Params_CaF;
    L_L.CW.In.kappa   =  2E3*2*pi;%2*1E3*2*pi;%
    L_L.CW.In.P       =  0.000000001; 

%%
  N      = 200;
  NN     = N*50;
  N_Mode = 200;
  
  
  Mumber_Of_Modes = zeros(N);
  Bistability_zone = ones(N);

  tic
  delta_vector  = linspace(-0.1,0.1,N);
  P_vector      = linspace(0,0.005,N);
    
%W_MI_vector_2
  parfor i = 1:N
      
      SiN = L_L;
      SiN.CW.In.delta =  delta_vector(i)*2*pi*1E6;
      SiN.CW          = SiN.Met.T_MI (SiN.CW,N_Mode);
      SiN.CW          = SiN.Met.T_Syn(SiN.CW,N_Mode);
      
      for ii = 1:N
          
          SiN.CW.In.P  = P_vector(ii);          
          SiN.CW       = SiN.CW.Met.Solve(SiN.CW,N_Mode);          
          [~,ind]   = max(abs(SiN.CW.Sol.Psi));
          SiN.CW.In.g  = SiN.CW.Sol.g(ind)*SiN.CW.Eq.norm;
          SiN.CW      = SiN.CW.Met.Mi_Formula(SiN.CW,N_Mode);          
          Mumber_Of_Modes(ii,i) = sum( (SiN.CW.An.Omega_mu(1,1:(end/2-1)) == 0 ));
          
          if isnan(SiN.CW.Sol.Psi(2))
              
              Bistability_zone(ii,i) = 0;
              
          end
          
      end
      
      W_MI_vector_1(i,:)        = SiN.CW.In.W_MI_Tongue(1,1:N_Mode/2)/(2*pi*1E6);
      W_MI_vector_2(i,:)        = SiN.CW.In.W_MI_Tongue(2,1:N_Mode/2)/(2*pi*1E6);
      
      i
  end
  
%%
  delta_vector_2 = linspace(min(delta_vector),max(delta_vector),NN);
  W_MI_vector_1_1 = zeros(NN,N_Mode/2);
  W_MI_vector_2_1 = zeros(NN,N_Mode/2);
    
     parfor i = 1:NN

          SiN = L_L;
          SiN.CW.In.delta =  delta_vector_2(i)*2*pi*1E6;
          SiN.CW          = SiN.Met.T_MI (SiN.CW,N_Mode);
          SiN.CW          = SiN.Met.T_Syn(SiN.CW,N_Mode);     
          
          W_MI_vector_1_1(i,:)        = SiN.CW.In.W_MI_Tongue(1,1:N_Mode/2);
          W_MI_vector_2_1(i,:)        = SiN.CW.In.W_MI_Tongue(2,1:N_Mode/2);
          
%           if SiN.CW.In.delta >0 
%               
%               W_MI_vector_1_1(i,:) = min([W_MI_vector_1_1(i,:),W_MI_vector_2_1(i,:)]);
%               W_MI_vector_2_1(i,:) = min([W_MI_vector_1_1(i,:),W_MI_vector_2_1(i,:)]);
%               
%           end

          i
      end
%%
    Power_down = zeros(1,N);
    Power_up = zeros(1,N);
    for i =1:N
        if ~isempty(find(Bistability_zone(:,i)==1,1,'first'))
              Power_down(i)   =  P_vector(find(Bistability_zone(:,i)==1,1,'first'));
        end
        if ~isempty(find(Bistability_zone(:,i)==1,1,'last'))
              Power_up(i)   = P_vector(find(Bistability_zone(:,i)==1,1,'last')) ;
        end
    end


%%
    pp4 = proPlot(delta_vector,P_vector, Mumber_Of_Modes, 'PlotType','pcolor');
    
     for i= 1:20
        pp4 = pp4.addData(delta_vector_2,W_MI_vector_1_1(:,i),'Color',[1,0,0],'LineWidth',2.5);
        pp4 = pp4.addData(delta_vector_2,W_MI_vector_2_1(:,i),'Color',[1,0,0],'LineWidth',2.5);
     end
     pp4 = pp4.addData([delta_vector,fliplr(delta_vector)],[Power_up,fliplr(Power_down)],[], 'PlotType','Fill','Color',[0.4,0.4,0.4],'FaceAlpha', 0.2);
Power_down(Power_down==0)=NaN;
Power_up(Power_up==0)=NaN;
Power_up(Power_up == max(P_vector)) = NaN;

     pp4 = pp4.addData(delta_vector_2,min(W_MI_vector_2_1,[],2),'Color',[1,0,0],'LineWidth',2.5);

    pp4 = pp4.addData(delta_vector,Power_up,'Color',[0,0,0],'LineWidth',2.5,'LineStyle','--');
    pp4 = pp4.addData(delta_vector,Power_down,'Color',[0,1,0],'LineWidth',2.5,'LineStyle','--');

    pp4 = pp4.changeAxisOptions('ColorMap', 'parula',...
                          'CAxis', [0,max(max(Mumber_Of_Modes))],'XLabelText','\delta_0 (GHz)','YLabelText',...
        'Power (W)','FontSize',15,'XLabelText','$\delta_0$ (MHz)','XLim',[min(delta_vector),max(delta_vector)]...
       ,'YLim',[min(P_vector),max(P_vector)],'Shading','flat');
    pp4 = pp4.changeFigOptions('Height',8,...
                     'Width',18);
    pp4 = pp4.addData([0.6,0.34,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', 'Bistable','FontSize',16,'Color',[1,1,1]);
    pp4 = pp4.addData([-0.2,0.74,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', 'Monostable','FontSize',16,'Color',[1,1,1]);

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
%save('H:\Documents\MATLAB\Matlab_Repo\Problems\Cavity_Codes\Problems\Real_Problems\Synchronization_Paper\Scripts_To_Draw_Tongues\delta_g_plate_CaF','pp4')

%%
