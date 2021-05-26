function In = Params_SiN_For_Crytal_Paper

    In.eta         = 0.5;                 % Coupling Regime
    In.omega_p     = 200E12*2*pi;         % Frequency of The Pump     
    In.D           = 2*pi*[200E9,2.5E6]; % Dispersion Coefficients,25E3
    In.gamma       = 2*pi*20E6;        % Nonlinear Coefficent
    In.range       = 120;
    In.kappa       = 2500E6*2*pi; 
    
end
