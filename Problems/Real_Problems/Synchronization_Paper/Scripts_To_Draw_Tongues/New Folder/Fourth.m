    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    L_L.In         = Params_CaF;
    L_L.In.kappa   =  2*1E5*2*pi;%2*1E3*2*pi;%
    L_L.In.P       = 0.00000000001; 

%%
    N = 10000;   
    N_Mode = 90;
    delta_vector  = linspace(-1,0,N);
    
    ind_Mode = [1:45];

    W_MI_vector_1 = zeros(N,size(ind_Mode,2));
    W_MI_vector_2 = zeros(N,size(ind_Mode,2));
    W_Synch_vector_1 = zeros(N,size(ind_Mode,2));
    W_Synch_vector_2 = zeros(N,size(ind_Mode,2));
    
    for i = 1:N
        
        L_L.In.delta = delta_vector(i)*2*pi*1E6;
        L_L          = L_L.Met.T_MI(L_L,N_Mode);
        L_L          = L_L.Met.T_Syn(L_L,N_Mode);
        
        
        W_MI_vector_1(i,:)        = L_L.In.W_MI_Tongue(1,ind_Mode);
        W_MI_vector_2(i,:)        = L_L.In.W_MI_Tongue(2,ind_Mode);
        
        W_Synch_vector_1(i,:)     = L_L.In.W_Synch(1,ind_Mode);
        W_Synch_vector_2(i,:)     = L_L.In.W_Synch(2,ind_Mode);
        
    end
    
%%
W_Synch_vector_1(isnan(W_Synch_vector_1)) = 0;
W_Synch_vector_2(isnan(W_Synch_vector_2)) = 0;
%    plot(delta_vector,W_Synch_vector_1(:,i),'Color',[1,0,0])
 
%    plot(delta_vector,W_Synch_vector_2(:,i),'Color',[1,0,0])
i= 1;
pp4 = proPlot([delta_vector,fliplr(delta_vector)], [W_Synch_vector_1(:,i);flipud(W_Synch_vector_2(:,i))], [], 'PlotType','Fill','Color',[0.4,0.4,0.4], 'FaceAlpha', 0.8);
pp4 = pp4.changeAxisOptions('XLabelText', '',...
                            'YLabelText', '','YLim',[-0.01,0.05],'FontSize',14,'XLim',[-0.62,0]);
pp4 = pp4.changeFigOptions('Height',3,...
                             'Width',9);
    
for i = 2:43
    
  pp4 = pp4.addData([delta_vector,fliplr(delta_vector)], [W_Synch_vector_1(:,i);flipud(W_Synch_vector_2(:,i))], [], 'PlotType','Fill', 'FaceAlpha', 0.8,'Color',[0.4,0.4,0.4]);
    
end


 pp4 = pp4.addData(delta_vector,min(W_MI_vector_2(:,:),[],2),[],'Color',[1,0,0]);
%for i = 10:40
% pp4 = pp4.addData(delta_vector,W_MI_vector_2(:,i),[],'Color',[1,0,0]);
%end

figure('Name','SiNTongues')
pp4.plotData();
%%
save('X:\Documents\MATLAB\Matlab_Repo\Problems\Cavity_Codes\Problems\Real_Problems\Synchronization_Paper\Scripts_To_Draw_Tongues\New Folder\Fourth.mat','pp4');
