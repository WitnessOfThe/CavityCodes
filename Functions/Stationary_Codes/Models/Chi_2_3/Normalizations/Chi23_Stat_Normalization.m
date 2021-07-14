function Stat = Chi23_Stat_Normalization(Stat)
%% Define Space 

    Fundamental_Constants;
    N         = Stat.In.N;
    if Stat.In.mu_bl ==0 
        Stat.Space  = Define_Space_Cavity(N,2*pi);
    else
        Stat.Space  = Define_Space_Cavity(N,2*pi/Stat.In.mu_bl);
    end
        
%%

    Stat.In.delta_e = 2*Stat.In.delta_o - Stat.In.eps;
    norm            = Stat.In.ko;%Stat.In.ko;

    Stat.In.Omega_f       =     Stat.In.delta_o - 1i*Stat.In.ko/2;
    Stat.In.Omega_s       =  8*(Stat.In.delta_e - 1i*Stat.In.ke/2);
    Stat.In.Omega_Star    =  sqrt(2*Stat.In.ke*Stat.In.ko);
    
    Stat.In.Finess_e = Stat.In.De(1)/Stat.In.ke;
     
    Stat.In.H_f    = sqrt(Stat.In.eta*Stat.In.Finess*Stat.In.W/pi);    
    Stat.In.H_s    = sqrt(Stat.In.eta*Stat.In.Finess_e*Stat.In.W/pi);   
   
%%
    Stat.Eq.delta_o         = Stat.In.delta_o/norm;
    Stat.Eq.delta_e         = Stat.In.delta_e/norm;
    Stat.Eq.eps             = Stat.In.eps/norm;
    Stat.Eq.W               = Stat.In.W/norm;
    Stat.Eq.ko             = Stat.In.ko/norm;                                
    Stat.Eq.ke             = Stat.In.ke/norm;       
    
    Stat.Eq.gam2o          = Stat.In.gam2o/norm;
    Stat.Eq.gam2e          = Stat.In.gam2e/norm;
    
    Stat.Eq.gam3o          = Stat.In.gam3o/norm;
    Stat.Eq.gam3e          = Stat.In.gam3e/norm;
    
    Stat.Eq.Do              = Stat.In.Do/norm;
    Stat.Eq.De              = Stat.In.De/norm;
    Stat.Eq.d               = (Stat.In.De(1)-Stat.In.Do(1))/norm;
    
    Stat.Eq.norm            = norm;
    
%%

%    Stat.Eq.Lo              = Stat.Eq.mask.*(Stat.Eq.delta_o - Stat.Space.k.*Stat.Eq.d/2 + Stat.Space.k.^2*1/2*Stat.Eq.Do(2) - 1i*Stat.Eq.ko/2);
 %   Stat.Eq.Le              = Stat.Eq.mask.*(Stat.Eq.delta_e + Stat.Space.k.*Stat.Eq.d/2 + Stat.Space.k.^2*1/2*Stat.Eq.De(2) - 1i*Stat.Eq.ke/2);
    
%%    
    Stat.Eq.mask            =ones(1,Stat.In.N);%[ones(1,100),zeros(1,Stat.In.N-200),ones(1,100)];%ones(1,Stat.In.N);%[ones(1,200),zeros(1,Stat.In.N-400),ones(1,200)];%[ones(1,Stat.In.N/2-Stat.Space.N/4),zeros(1,Stat.Space.N/4),zeros(1,Stat.Space.N/4),ones(1,Stat.In.N/2-Stat.Space.N/4)];

    Stat.Eq.Lo              = Stat.Eq.mask.*(Stat.Eq.delta_o + Stat.Space.k.^2*1/2*Stat.Eq.Do(2) - 1i*Stat.Eq.ko/2);
    Stat.Eq.Le              = Stat.Eq.mask.*(Stat.Eq.delta_e + Stat.Space.k.*Stat.Eq.d + Stat.Space.k.^2*1/2*Stat.Eq.De(2) - 1i*Stat.Eq.ke/2);
    
end
