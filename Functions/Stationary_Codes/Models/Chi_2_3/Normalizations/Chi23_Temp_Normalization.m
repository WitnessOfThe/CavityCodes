function Temp = Chi23_Temp_Normalization(Temp)
%% Define Space 

    Fundamental_Constants;
    N         = Temp.In.N;  
    Temp.Space  = Define_Space_Cavity(N,2*pi);
        
%%

    Temp.In.delta_e = 2*Temp.In.delta_o - Temp.In.eps;
    
    Temp.In.Finess_e = Temp.In.De(1)/Temp.In.ke;
    Temp.In.H_f    = sqrt(Temp.In.eta*Temp.In.Finess*Temp.In.W/pi);    
    Temp.In.H_s    = sqrt(Temp.In.eta*Temp.In.Finess_e*Temp.In.W/pi);  

    Temp.Eq.H_f    = sqrt(Temp.In.eta*Temp.In.Finess*Temp.In.W/pi);    
    Temp.Eq.H_s    = sqrt(Temp.In.eta*Temp.In.Finess_e*Temp.In.W/pi);  
    
    norm          = Temp.In.ko;

    Temp.In.Omega_f    =  Temp.In.delta_o - 1i*Temp.In.ko/2;
    Temp.In.Omega_s    =  8*(Temp.In.delta_e - 1i*Temp.In.ke/2);
    Temp.In.Omega_Star    =  sqrt(2*Temp.In.ke*Temp.In.ko);
    
%%
    Temp.Eq.delta_o         = Temp.In.delta_o/norm;x
    Temp.Eq.delta_e         = Temp.In.delta_e/norm;
    Temp.Eq.delta_e2        =  Temp.In.delta_e2/norm;
    Temp.Eq.eps             = Temp.In.eps/norm;
    
    Temp.Eq.ko             = Temp.In.ko/norm;                                
    Temp.Eq.ke             = Temp.In.ke/norm;       
    
    Temp.Eq.gam2o          = Temp.In.gam2o/norm;
    Temp.Eq.gam2e          = Temp.In.gam2e/norm;
    
    Temp.Eq.gam3o          = Temp.In.gam3o/norm;
    Temp.Eq.gam3e          = Temp.In.gam3e/norm;
    
    Temp.Eq.Do              = Temp.In.Do/norm;% Dispersion Coefficients,-4E3
    Temp.Eq.De              = Temp.In.De/norm;% Dispersion Coefficients,-4E3
    Temp.Eq.d               = (Temp.In.De(1)-Temp.In.Do(1))/norm;
    
    Temp.Eq.norm            = norm;
    tt = [Temp.Space.k,Temp.Space.k];
    Temp.Eq.mode_range      =     find( tt < 150 & tt > -150);
    
%%
    Temp.Eq.Lo              = Temp.Eq.delta_o + Temp.Space.k.^2*1/2*Temp.Eq.Do(2) - 1i*Temp.Eq.ko/2;
    Temp.Eq.Le              = Temp.Eq.delta_e + Temp.Space.k.*Temp.Eq.d + Temp.Space.k.^2*1/2*Temp.Eq.De(2) - 1i*Temp.Eq.ke/2;
    Temp.Eq.L               = [Temp.Eq.Lo,Temp.Eq.Le];
end
