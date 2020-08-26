    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    L_L.In         = Params_SiN;
    L_L.In.kappa   =  2*10E6*2*pi;%2*1E3*2*pi;%
    L_L.In.P       = 0.00000000001; 

%%
  N = 10000;   
  N_Mode = 2^7;
    delta_vector  = linspace(-0.6148,-0.5736,N);
    
%    Mode     = [1:10];
    ind_Mode = 1:37;

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

figure;
hold on;

for i = 1:8
    
    plot(delta_vector,W_MI_vector_1(:,i),'Color',[0,0,1])

    plot(delta_vector,W_MI_vector_2(:,i),'Color',[0,0,1])

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    plot(delta_vector,W_Synch_vector_1(:,i),'Color',[1,0,0])
 
    plot(delta_vector,W_Synch_vector_2(:,i),'Color',[1,0,0])
    
end

    xlabel('Detuning Ghz');
    ylabel('Laser Power [W]');
