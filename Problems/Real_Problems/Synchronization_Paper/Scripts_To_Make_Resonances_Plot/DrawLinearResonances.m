
    clc;
    clear all;
    format long;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Define Spatial and Spectral Grid Of the Cavity

%    L_L  = Define_Space_Cavity(L_L,2^10,2*pi);
      
%% Define Methods
    L_L_CaF.Met.Norm           = @Chi_3_LLE_Normalization; % Method which Apply
    % input parameters to equation
    
    L_L_CaF.CW.Met.MI_Matrix   = @Chi_3_LLE_MI_Matrix;     % Method which define
    % MI matrix to solve
    
    L_L_CaF.CW.Met.Solve       = @Chi_3_LLE_CW;            % Method which define
    % CW equation to solve
    
%% Define Input Parameters in Physical Units
    L_L_SiN                 = L_L_CaF;
    
    L_L.In.N               = 2^5;
    L_L.In.eta             = 0.5;                 % Coupling Regime
    L_L.In.omega_p         = 200E12*2*pi;         % Frequency of The Pump     
    L_L.In.D               = 2*pi*[15E9,1000,0,0];% Dispersion Coefficients
    L_L.In.gamma           = 2*pi*10*1000;        % Nonlinear Coefficent
    L_L.In.kappa           = 2*pi*2*10^3;         % LineWidth 
    L_L.In.norm_coeff      = L_L.In.kappa;        % Normalization Coeff
    L_L.In.delta           = -5.9167e+05*2*pi;            % Detunning
    L_L.In.P               = 0.00000001;                 % Power in Watts            
    
%% Now we need to apply input parameters into  a class

    L_L         = L_L.Met.Norm(L_L); % dispersion of the 
    L_L         = Chi_3_LLE_Finess_Dispersion(L_L);

%%
N =2^10;
 delta_vector = linspace(-1E6,1E6,N)*2*pi;

for i =1:N
    
   L_L.In.delta= delta_vector(i);
   L_L                    = L_L.Met.Norm(L_L); % dispersion of the    
   L_L.CW      = L_L.CW.Met.Solve(L_L.CW);
   Psi(i,:)    = L_L.CW.Sol.Psi;
   
end
%%
Psi = abs(Psi)./max(max(abs(Psi)));
%%
figure;
hold on;
plot(fliplr(delta_vector)/2/pi,abs(Psi(:,1)).^2,'Color',[1,0,0])
plot(fliplr(delta_vector)/2/pi,abs(Psi(:,2)).^2,'Color',[1,0,0])
plot(fliplr(delta_vector)/2/pi,abs(Psi(:,3)).^2,'Color',[1,0,0])
% 
% for i = 2:35
%     shift = 1/2* L_L.In.D(2)/2/pi *i^2;
%     hold on;
%     plot(delta_vector/2/pi+shift,abs(Psi(:,1)).^2,'Color',[1,0,0])
%     plot(delta_vector/2/pi+shift,abs(Psi(:,2)).^2,'Color',[1,0,0])
%     plot(delta_vector/2/pi+shift,abs(Psi(:,3)).^2,'Color',[1,0,0])
% end
