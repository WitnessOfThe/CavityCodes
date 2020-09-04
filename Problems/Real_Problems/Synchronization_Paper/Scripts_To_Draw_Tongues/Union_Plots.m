
%% Delta_Power
load('H:\Documents\MATLAB\Matlab_Repo\Problems\Cavity_Codes\Problems\Real_Problems\Synchronization_Paper\Scripts_To_Draw_Tongues\delta_power_plate.mat')
figure;
    pp4.plotData
    h = colormap;
    cmap = colormap(h);
    cmap(1,:) = 0; 
    colormap(gca,cmap)
%%
load('H:\Documents\MATLAB\Matlab_Repo\Problems\Cavity_Codes\Problems\Real_Problems\Synchronization_Paper\Scripts_To_Draw_Tongues\delta_g_plate.mat')
%    pp4 = pp4.changeAxisOptions('ColorMap', 'parula',...
 %                         'CAxis', [0,max(max(Mumber_Of_Modes))],'YLabelText',...
  %      'Power [W]','FontSize',15,'XLabelText','','Shading','flat');
figure;
pp4.plotData
h = colorbar;
cmap = colormap(h);
cmap(1,:) = 0; 
colormap(gca,cmap)
h = colorbar;
h.FontSize = 15;
h.TickLabelInterpreter = 'latex';
h.Label.String         = 'Number of Synchronized Modes';
h.Label.Interpreter    = 'latex';
h.Location             = 'northoutside';
%%
tt_1 =load('H:\Documents\MATLAB\Matlab_Repo\Problems\Cavity_Codes\Problems\Real_Problems\Synchronization_Paper\Scripts_To_Draw_Tongues\delta_power_plate_2E7.mat');
tt_2 =load('H:\Documents\MATLAB\Matlab_Repo\Problems\Cavity_Codes\Problems\Real_Problems\Synchronization_Paper\Scripts_To_Draw_Tongues\delta_power_plate_3E8.mat');
tt_3 =load('H:\Documents\MATLAB\Matlab_Repo\Problems\Cavity_Codes\Problems\Real_Problems\Synchronization_Paper\Scripts_To_Draw_Tongues\delta_power_plate_1.5E9.mat');

CF = conFigure([tt_1.pp4,tt_2.pp4,tt_3.pp4],3,1,'Height',18,'Width',18, 'UniformPlots', true)
