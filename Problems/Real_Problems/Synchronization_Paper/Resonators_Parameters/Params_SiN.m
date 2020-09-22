function In = Params_SiN

    In.eta             = 0.5;                 % Coupling Regime
    In.omega_p         = 220E12*2*pi;         % Frequency of The Pump     
    In.D               = 2*pi*[1E12,50E6,0,0];% Dispersion Coefficients
    In.gamma           = 23E6*2*pi;          % Nonlinear Coefficent
    In.range           =  50;
end
