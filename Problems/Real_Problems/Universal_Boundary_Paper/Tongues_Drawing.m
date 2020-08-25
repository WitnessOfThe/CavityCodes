    clc;
    clear all;
    format long;
    L_L = struct;    
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Define Spatial and Spectral Grid Of the Cavity

%    L_L  = Define_Space_Cavity(L_L,2^10,2*pi);
      
%% Define Methods

    L_L.Met.Norm           = @Chi_3_LLE_Normalization; % Method which Apply
    % input parameters to equation
    
    L_L.CW.Met.MI_Matrix   = @Chi_3_LLE_MI_Matrix;     % Method which define
    % MI matrix to solve
    
    L_L.CW.Met.Solve       = @Chi_3_LLE_CW;            % Method which define
    L_L.Met.T_MI           = @Chi_3_LLE_MI_Boundary;
    L_L.Met.T_Syn          = @Chi_3_LLE_Synch_Boundary;
    % CW equation to solve
    
%% Define Input Parameters in Physical Units

    L_L.In.N               = 2^7;
    L_L.In.eta             = 0.5;                 % Coupling Regime
    L_L.In.omega_p         = 200E12*2*pi;         % Frequency of The Pump     
    L_L.In.D               = 2*pi*[15E9,1000,0,0];% Dispersion Coefficients
    L_L.In.gamma           = 2*pi*10*1000;        % Nonlinear Coefficent
    L_L.In.kappa           = 2*pi*2E3;         % LineWidth 
    L_L.In.norm_coeff      = L_L.In.kappa;        % Normalization Coeff
    L_L.In.delta           = -5.9167e+05*2*pi;    % Detunning
    L_L.In.P               = 0.4833;              % Power in Watts            
%%

%     L_L.In.N               = 2^5;
%     L_L.In.eta             = 0.5;                 % Coupling Regime
%     L_L.In.omega_p         = 200E12*2*pi;         % Frequency of The Pump     
%     L_L.In.D               = 2*pi*[1E12,20E6,0,0];% Dispersion Coefficients
%     L_L.In.gamma           = 449459777.3584841;        % Nonlinear Coefficent
%     L_L.In.kappa           = 2*pi*10E6;         % LineWidth 
%     L_L.In.norm_coeff      = L_L.In.kappa;        % Normalization Coeff
%     L_L.In.delta           = -5.9167e+05*2*pi;    % Detunning
%     L_L.In.P               = 0.4833;              % Power in Watts            

%% Now we need to apply input parameters into  a class

    L_L                    = L_L.Met.Norm(L_L); % dispersion of the 
    L_L.CW                 = L_L.CW.Met.Solve(L_L.CW);
    L_L.CW                 =               MI(L_L.CW);

%%
    N = 10000;   
    delta_vector  = linspace(-0.6148,-0.5736,N);
    
%    Mode     = [1:10];
    ind_Mode = 35:37;

    W_MI_vector_1 = zeros(N,size(ind_Mode,2));
    W_MI_vector_2 = zeros(N,size(ind_Mode,2));
    W_Synch_vector_1 = zeros(N,size(ind_Mode,2));
    W_Synch_vector_2 = zeros(N,size(ind_Mode,2));
    
    for i = 1:N
        
        L_L.In.delta = delta_vector(i)*2*pi*1E6;
        L_L          = L_L.Met.Norm(L_L);
        L_L          = L_L.Met.T_MI(L_L);
        L_L          = L_L.Met.T_Syn(L_L);
        
        
        W_MI_vector_1(i,:)        = L_L.In.W_MI_Tongue(1,ind_Mode);
        W_MI_vector_2(i,:)        = L_L.In.W_MI_Tongue(2,ind_Mode);
        
        W_Synch_vector_1(i,:)     = L_L.In.W_Synch(1,ind_Mode);
        W_Synch_vector_2(i,:)     = L_L.In.W_Synch(2,ind_Mode);
        
    end
    
%    W_MI_vector_1(1,:)    = W_MI_vector_2(1,:);
 %   W_Synch_vector_1(1,:) = W_Synch_vector_2(1,:);
    
%% 

figure;
hold on;
for i =1:size(ind_Mode,2)
    plot(delta_vector,W_MI_vector_1(:,i),'Color',[0,0,1])

    plot(delta_vector,W_MI_vector_2(:,i),'Color',[0,0,1])

 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    plot(delta_vector,W_Synch_vector_1(:,i),'Color',[1,0,0])
 
    plot(delta_vector,W_Synch_vector_2(:,i),'Color',[1,0,0])
end
xlabel('Detuning Ghz')
ylabel('Laser Power [W]')
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    L_L.In.P               = 0.025;
    N = 1000;   
    delta_vector  = linspace(-0.55,0.611,N)*2*pi*1E6;
    
    Mode     = 35;
    ind_Mode = find(L_L.Space.k == Mode);

    Real_1          = zeros(N,1);
    Real_2          = zeros(N,1);
    
    Imag_1          = zeros(N,1);
    Imag_2          = zeros(N,1);
    
    
    
    for i = 1:N
        
        L_L.In.delta = delta_vector(i);
        L_L          = L_L.Met.Norm(L_L);
        L_L.CW       = L_L.CW.Met.Solve(L_L.CW);
        L_L.CW       = MI(L_L.CW);
        
        Real_1(i)       = max(real(L_L.CW.Stab(3).Value(ind_Mode,:)));
%        Real_2(i)       = ;
        
        Imag_1(i)       = imag(L_L.CW.Stab(3).Value(ind_Mode,1));
        Imag_2(i)       = imag(L_L.CW.Stab(3).Value(ind_Mode,2));
        
    end
    
    
%%
    figure;
    
