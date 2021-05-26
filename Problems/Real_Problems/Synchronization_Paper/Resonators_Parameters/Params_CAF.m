function In = Params_CaF

    In.eta         = 0.5;                 % Coupling Regime
    In.omega_p     = 200E12*2*pi;         % Frequency of The Pump     
    In.D           = 2*pi*[15E9,1000,0,0,0,0];% Dispersion Coefficients
    In.gamma       = 2*pi*10*1e3;        % Nonlinear Coefficent
    In.range       = 100;
    In.kappa       = 2*pi*1E4;
end
