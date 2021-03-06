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

  delta_vector  = -0.56:1.5E-4:-0.555;
  P_vector      = 0:0.01:0.65;
  
  N_delta = size(delta_vector,2);
  N_Power = size(P_vector,2);
  
%%
    L_L.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    L_L.Temp.Par.dt            = 5E-5;
    L_L.Temp.Par.s_t           = 0.01;
    L_L.Temp.Par.T             = 300;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    L_L.Temp.Par.CW_num        = 3;
    L_L.Temp.Par.dd            = L_L.Temp.Par.T/L_L.Temp.Par.s_t;
    Runge                      = Define_Runge_Coeff(L_L.Temp.Par);
 %   tt                         = CaF.Temp.Met;
%   %%  
%   Mumber_Of_Modes  = zeros(N_Power,N_delta);
%   Bistability_zone = ones(N_Power,N_delta);
%   Sim_zone= zeros(N_Power,N_delta);
%   Bistability_zone = ones(N_Power,N_delta);
%     delta_matrix = ones(N_Power,N_delta);
%     power_matrix = ones(N_Power,N_delta);
% 
%   tic
%   parfor i = 1:N_delta
%       
%       SiN = L_L;        
%       SiN.CW.In.delta =  delta_vector(i)*2*pi*1E6;
%       
%       for ii = 1:N_Power
%           
%           SiN.CW.In.P  = P_vector(ii);          
%           delta_matrix(ii,i) = delta_vector(i)*2*pi*1E6;
%           power_matrix(ii,i) = P_vector(ii);
%           SiN.CW       = SiN.CW.Met.Solve(SiN.CW,N_Mode);          
%           [~,ind]   = max(abs(SiN.CW.Sol.Psi));
%           SiN.CW.In.g  = SiN.CW.Sol.g(ind)*SiN.CW.Eq.norm;
%           SiN.CW      = SiN.CW.Met.Mi_Formula(SiN.CW,N_Mode);          
%           
%           Mumber_Of_Modes(ii,i) = sum( (SiN.CW.An.Omega_mu(1,1:(end/2-1)) == 0 ));
%           
%           if max(max(real(SiN.CW.An.lambda_mu))) >0 
%               Sim_zone(ii,i) = 1;
%           end
%               
%           if isnan(SiN.CW.Sol.Psi(2))
%               Bistability_zone(ii,i) = 0;
%           end
%       end
%       i
%       SiN = [];
%   end
%   toc
  load('/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Real_Problems/Synchronization_Paper/Dynamics_work/Tongues_Scan/Starter_CaF_Right_Segment.mat')

%%
  Path = '/home/dp710/Data_Storage/CaF_35_Segment_2E3_kappa_0.56_0.555';
%  Path = 'C:\Users\dp710\Documents\Check_fig\Intersting';
%h = waitbar(0, 'Waiting...');
  ii = 0;
  for i_2 = 1:N_delta
      for i_1 = 1:N_Power
          ii = ii+1;
          Sim_number(i_1,i_2) = ii;
      end
  end
  for i_1 = 1:N_Power      
    delete(gcp('nocreate'))
    p = parpool(70);
    tic
    parfor i_2 = 1:N_delta
        
        ii = Sim_number(i_1,i_2)
        Chi_3_LLE_Assynch_Paralell_exec(L_L,delta_matrix(ii),power_matrix(ii),ii,Path,Sim_zone(ii),N_Mode,Runge)
        
    end
    toc
    i_1
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
        
        ii = Sim_number(i_1,i_2)
        Left_sim(i_1,i_2) =  Sim_zone(ii) == 1 && ~isfile(strcat(Path,'/Data/',num2str(ii),'.mat')) ; 
    end
    toc
    i_1
  end
