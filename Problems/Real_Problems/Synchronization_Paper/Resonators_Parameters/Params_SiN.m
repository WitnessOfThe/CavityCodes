function In = Params_SiN

    In.eta             = 0.5;                 % Coupling Regime
    In.omega_p         = 190E12*2*pi;         % Frequency of The Pump     
 %   In.D               = 2*pi*[1E12,2.9345E6, -4.8711e+05,-6.3548e+04,3.3022e+03,2.9345e+07];% Dispersion Coefficients
    In.D               = 2*pi*[1E12,20E6,0,-117.5E3,-5.3E3,-150];% Dispersion Coefficients,-4E3
%    In.D               = 2*pi*[1E12,20E6,0E6,-120E3,-5.3E3,-150];% Dispersion Coefficients
 %   In.D               = 2*pi*[1E12,20E6];% Dispersion Coefficients
    In.gamma           = 20E6*2*pi;          % Nonlinear Coefficent
    In.range           =  200;
    
end
