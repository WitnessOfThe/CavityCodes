    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    L_L.In         = Params_SiN;
    L_L.In.kappa   =  1E9*2*pi;%2*1E3*2*pi;%
    L_L.In.P       = 0.00000000001; 

%%
    N             = 10000;   
    N_Mode        = 2^7;
    delta_vector  = linspace(-0.9,-0.65,N);
    
    ind_Mode = [7:7];

    W_MI_vector_1 = zeros(N,size(ind_Mode,2));
    W_MI_vector_2 = zeros(N,size(ind_Mode,2));
    
    W_Synch_vector_1 = zeros(N,size(ind_Mode,2));
    W_Synch_vector_2 = zeros(N,size(ind_Mode,2));
    
    G_Synch_vector_1          = zeros(N,size(ind_Mode,2));
    G_Synch_vector_2          = zeros(N,size(ind_Mode,2));
    
for i = 1:N
        
        L_L.In.delta = delta_vector(i)*2*pi*1E9;
        L_L          = L_L.Met.T_MI(L_L,N_Mode);
        L_L          = L_L.Met.T_Syn(L_L,N_Mode);
        
        L_L          = L_L.Met.T_Syn(L_L,N_Mode);
        
        W_MI_vector_1(i,:)        = L_L.In.W_MI_Tongue(1,ind_Mode);
        W_MI_vector_2(i,:)        = L_L.In.W_MI_Tongue(2,ind_Mode);
        
        W_Synch_vector_1(i,:)     = L_L.In.W_Synch(1,ind_Mode);
        W_Synch_vector_2(i,:)     = L_L.In.W_Synch(2,ind_Mode);
        
        G_Synch_vector_1(i,:)         = L_L.In.g_Synch(1,ind_Mode);
        G_Synch_vector_2(i,:)         = L_L.In.g_Synch(2,ind_Mode);
        
    end
    
%%
    W_Synch_vector_1(isnan(W_Synch_vector_1)) = 0;
    W_Synch_vector_2(isnan(W_Synch_vector_2)) = 0;

    i= 1;
pp4 = proPlot([delta_vector+(ind_Mode(i)-1)^2/2*L_L.In.D(2)/2/pi/1E9,fliplr(delta_vector)+(ind_Mode(i)-1)^2/2*L_L.In.D(2)/2/pi/1E9], [W_Synch_vector_1(:,i);flipud(W_Synch_vector_2(:,i))], [], 'PlotType','Fill','Color',[0.4,0.4,0.4], 'FaceAlpha', 0.5);
pp4 = pp4.changeAxisOptions('XLabelText', '',...
                            'YLabelText', '',...
                            'FontSize',14);
pp4 = pp4.changeFigOptions('Height',8,...
                             'Width',10);
    
for i = 1:1
    
   pp4 = pp4.addData([delta_vector+(ind_Mode(i)-1)^2/2*L_L.In.D(2)/2/pi/1E9,fliplr(delta_vector)+(ind_Mode(i)-1)^2/2*L_L.In.D(2)/2/pi/1E9], [W_Synch_vector_1(:,i);flipud(W_Synch_vector_2(:,i))], [], 'PlotType','Fill', 'FaceAlpha', 0.5,'Color',[0.6,0.6,0.6],'EdgeColor','none');
    
end
for i = 1:1
  pp4 = pp4.addData(delta_vector+(ind_Mode(i)-1)^2/2*L_L.In.D(2)/2/pi/1E9,W_MI_vector_1(:,i),[],'Color',[1,0,0]);
  pp4 = pp4.addData(delta_vector+(ind_Mode(i)-1)^2/2*L_L.In.D(2)/2/pi/1E9,W_MI_vector_2(:,i),[],'Color',[1,0,0]);
%  pp4 = pp4.addData(delta_vector,W_Synch_vector_1(:,i),[],'Color',[1,0,0]);
 % pp4 = pp4.addData(delta_vector,W_Synch_vector_2(:,i),[],'Color',[1,0,0]);
end

%%
%save('H:\Documents\MATLAB\Matlab_Repo\Problems\Cavity_Codes\Problems\Real_Problems\Synchronization_Paper\Scripts_To_Draw_Tongues\Single_Tongue_Plate','pp4')
%%
figure;pp4.plotData
