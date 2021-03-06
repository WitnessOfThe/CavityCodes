    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    L_L.CW.In         = Params_CaF;
    L_L.CW.In.kappa   =  2E3*2*pi;%2*1E3*2*pi;%
    L_L.CW.In.P       = 0.00000000001; 
    L_L.Temp          = L_L.CW;
    
%%

    N      = 200;   
    N_Mode = 2^10;
    NN     = N*600;

    delta_vector  = -0.4:1.5E-4:0;
    P_vector      = 0:0.0005:0.07;
  
    N_delta = size(delta_vector,2);
    N_Power = size(P_vector,2);
  
%%
    L_L.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    L_L.Temp.Par.dt            = 5E-5;
    L_L.Temp.Par.s_t           = 0.01;
    L_L.Temp.Par.T             = 200;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    L_L.Temp.Par.CW_num        = 3;
    L_L.Temp.Par.dd            = L_L.Temp.Par.T/L_L.Temp.Par.s_t;
    Runge                      = Define_Runge_Coeff(L_L.Temp.Par);
    load('/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Real_Problems/Synchronization_Paper/Dynamics_work/Tongues_Scan/Starter_CaF_Big_Scan.mat')

%%
  Path = '/home/dp710/Data_Storage/CaF_Scan_from_0.4_to_0_2_synch_zone_fixed';
%  Path = 'C:\Users\dp710\Documents\Check_fig\Intersting';
%h = waitbar(0, 'Waiting...');
  ii = 0;
  for i_2 = 1:N_delta
      for i_1 = 1:N_Power
          
          ii = ii+1;
          Sim_number(i_1,i_2) = ii;
          
      end
  end
ii =0;
 for ii_1 = 1:(round(N_delta*N_Power/70)+1)
      
      Count = 0;
      
      while Count < 70
          
          ii = ii+1;
          
          if Sim_zone(ii) == 1 && ~isfile(strcat(Path,'/Data/',num2str(ii),'.mat'))   
              
              Count = Count +1;
              ii_bathc(Count) = Sim_number(ii);
              
          end
          
      end
      
   %   delete(gcp('nocreate')); 
     myCluster = parcluster('local');
      delete(myCluster.Jobs);
    
      p = parpool(70);
      
      tic
      
      parfor i = 1:70
          
          Chi_3_LLE_Assynch_Paralell_exec(L_L,delta_matrix(ii_bathc(i)),power_matrix(ii_bathc(i)),ii_bathc(i),Path,Sim_zone(ii_bathc(i)),N_Mode,Runge)
          
      end
      
      delete(gcp('nocreate'));
      toc
      ii_1
  end
%updateWaitbarFuture = afterEach(f, @(~) waitbar(sum(strcmp('finished', {f.State}))/numel(f), h), 1); 
%%
% pp4 = proPlot(delta_vector,P_vector, Mumber_Of_Modes, 'PlotType','pcolor');
% %pp4 = pp4.addData([delta_vector,fliplr(delta_vector)],[Power_up,fliplr(Power_down)],[], 'PlotType','Fill','Color',[0.4,0.4,0.4],'FaceAlpha', 0.2);
% %Power_down(Power_down==0)=NaN;
% %Power_up(Power_up==0)=NaN;
% %Power_up(Power_up == max(P_vector)) = NaN;
% 
% %   for i=36:36
%  %      pp4 = pp4.addData(delta_vector_2,W_MI_vector_1(:,i),'Color',[1,0,0],'LineWidth',2.5);
%  %      pp4 = pp4.addData(delta_vector_2,W_MI_vector_2(:,i),'Color',[1,0,0],'LineWidth',2.5);
%  %  end
%  %   pp4 = pp4.addData(delta_vector,Power_up,'Color',[0,0,0],'LineWidth',2.5,'LineStyle','--');
%   %  pp4 = pp4.addData(delta_vector,Power_down,'Color',[0,1,0],'LineWidth',2.5,'LineStyle','--');
%     pp4 = pp4.changeAxisOptions('ColorMap', 'parula',...
%                           'CAxis', [0,max(max(Mumber_Of_Modes))],'YLabelText',...
%         'Power [W]','FontSize',15,'XLabelText','$\delta_0$ (GHz)','XLim',[min(delta_vector),max(delta_vector)]...
%        ,'YLim',[min(P_vector)-0.1, max(P_vector)],'Shading','flat');
%     pp4 = pp4.changeFigOptions('Height',8,...
%                      'Width',18);
%                  
% %    pp4 = pp4.addData([-2.4,2.8,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=14$','FontSize',14,'Color',[1,1,1]);
% %    pp4 = pp4.addData([-2.4,2,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=13$','FontSize',14,'Color',[1,1,1]);
% %    pp4 = pp4.addData([-2.4,1.4,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=12$','FontSize',14,'Color',[1,1,1]);
% %    pp4 = pp4.addData([-2.4,0.9,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', '$|\mu|=11$','FontSize',14,'Color',[1,1,1]);
% %    pp4 = pp4.addData([0.5,2,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', 'Monostable','FontSize',20,'Color',[1,1,1]);
% %    pp4 = pp4.addData([3.3,1.2,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox', 'String', 'Bistable','FontSize',20,'Color',[1,1,1]);
% 
% figure;
% pp4.plotData
% %%
% 
% %%
% %save('H:\Documents\MATLAB\Matlab_Repo\Problems\Cavity_Codes\Problems\Real_Problems\Synchronization_Paper\Scripts_To_Draw_Tongues\delta_power_plate_3E8.mat','pp4')
  for i_1 = 1:N_Power      
    tic
    for i_2 = 1:N_delta
        
        ii = Sim_number(i_1,i_2);
        Left_sim(i_1,i_2) =  Sim_zone(ii) == 1 && ~isfile(strcat(Path,'/Data/',num2str(ii),'.mat')) ; 
    end
    toc
    i_1
  end
