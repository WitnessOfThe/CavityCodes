function In = Params_SiN

    In.eta             = 0.5;                                % Coupling Regime
    In.omega_p         = 190E12*2*pi;                        % Frequency of The Pump     
    In.D               = 2*pi*[1E12,20E6,1.5E6,-52E3,-4E3,-2];% Dispersion Coefficients,-4E3
    In.gamma           = 20E6*2*pi;                          % Nonlinear Coefficent
    In.range           =  200;
    
end