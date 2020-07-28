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
    % CW equation to solve
    
%% Define Input Parameters in Physical Units
    L_L.In.eta             = 0.5;                 % Coupling Regime
    L_L.In.omega_p         = 176E12*2*pi;         % Frequency of The Pump     
    L_L.In.D               = 2*pi*[15E9,1000,0,0];% Dispersion Coefficients
    L_L.In.gamma           = 2*pi*10*1000;        % Nonlinear Coefficent
    L_L.In.kappa           = 2*pi*2*10^3;         % LineWidth 
    L_L.In.norm_coeff      = L_L.In.kappa;        % Normalization Coeff
    L_L.In.delta           = -5.911728395061728e+05*2*pi;            % Detunning
    L_L.In.P               = 0.45;                 % Power in Watts            
    
%% Now we need to apply input parameters into  a class

    L_L                    = L_L.Met.Norm(L_L); % dispersion of the 
        
%% Solve for CW and Calculate MI
    L_L.CW                 = L_L.CW.Met.Solve(L_L.CW);
    L_L.CW                 =               MI(L_L.CW);

%% Some Methods To Run Dynamics
 
    % equation to solve in Dynamical Simulation    
    % starting point of simulation
    
%%
    L_L.Temp.Met.Ev_Core        = @Chi_3_LLE_Kuar;          % Method which define
    L_L.Temp.Met.Ev_Start_Point = @Chi_3_LLE_Start_Point_CW;% Method which define
    L_L.Temp.Met.Ev_Save        = @Chi_3_LLE_Dyn_Saving;
    
    L_L.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    L_L.Temp.Par.CW_num        = 3;
    L_L.Temp.Par.dt            = 2E-4;
    L_L.Temp.Par.s_t           = 10;
    L_L.Temp.Par.T             = 100;
    
%% Temporal Evolution

    L_L.Temp.In  =   L_L.Temp.Met.Ev_Start_Point(L_L);    
    L_L.Temp     =         Runge_Kuarong(L_L.Temp);



