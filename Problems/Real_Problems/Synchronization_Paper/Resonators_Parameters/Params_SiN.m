function In = Params_SiN

    In.eta             = 0.5;                                % Coupling Regime
    In.omega_p         = 190E12*2*pi;                        % Frequency of The Pump     
    In.D               = 2*pi*[1E12,20E6,0,-120E3,5.3E3,-150];% Dispersion Coefficients  
    In.D               = 2*pi*[1E12,20E6,0,-120E3,0,-150];% Dispersion Coefficients,-4E3
    In.gamma           = 20E6*2*pi;                          % Nonlinear Coefficent
    In.range           =  200;
    In.kappa        = 125E6*2*pi;    
    
end