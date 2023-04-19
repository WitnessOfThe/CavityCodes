function Temp = Chi23FFMimik_Stat_Normalization(Temp)
%% Define Space 

    Fundamental_Constants;
    N         = Temp.In.N;  
    Temp.Space  = Define_Space_Cavity(N,2*pi);
        
%%

    Temp.In.delta_e = 2*Temp.In.delta_o - Temp.In.eps;
    
    Temp.In.Finess_e = Temp.In.De(1)/Temp.In.ke;
    Temp.In.H_f    = sqrt(Temp.In.eta*Temp.In.Finess*Temp.In.W/pi/2);    
    Temp.In.H_s    = sqrt(Temp.In.eta*Temp.In.Finess_e*Temp.In.W/pi/2);  

    Temp.Eq.H_f    = sqrt(Temp.In.eta*Temp.In.Finess*Temp.In.W/pi/2);    
    Temp.Eq.H_s    = sqrt(Temp.In.eta*Temp.In.Finess_e*Temp.In.W/pi/2);  
    
    norm          = Temp.In.ko;

    Temp.In.Omega_f    =  Temp.In.delta_o - 1i*Temp.In.ko/2;
    Temp.In.Omega_s    =  8*(Temp.In.delta_e - 1i*Temp.In.ke/2);
    Temp.In.Omega_Star    =  sqrt(2*Temp.In.ke*Temp.In.ko);
    
%%
    Temp.Eq.delta_o         = Temp.In.delta_o/norm;
    Temp.Eq.delta_e         = Temp.In.delta_e/norm;
%    Temp.Eq.delta_e2        =  Temp.In.delta_e2/norm;
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
    tt                      = [Temp.Space.k,Temp.Space.k];
    Temp.Eq.mode_range      =     find( tt < 256*2 & tt > -256*2);
    
    ind_m1 = find(Temp.In.D.m == Temp.In.D.In.m_p);
    ind_m2 = find(Temp.In.D.m == 2*Temp.In.D.In.m_p-Temp.In.D.In.g);
    ind_m3 = find(Temp.In.D.m == 2*Temp.In.D.In.m_p);

%%    
     ii = 0;
    for ik = 1:Temp.Space.N
        Statement = Temp.In.D.m ==  Temp.In.D.In.m_p + Temp.Space.k(ik);
        if sum(Statement) ~= 0
            ii = ii + 1;
            mode_range_a(ii)    = find(Temp.In.D.m ==  Temp.In.D.In.m_p + Temp.Space.k(ik));
            ind_range_k_a(ii)     = find(Temp.Space.k== Temp.Space.k(ik));
        end
    end
    ii = 0;
    for ik = 1:Temp.Space.N
        Statement = Temp.In.D.m ==  2*Temp.In.D.In.m_p + Temp.Space.k(ik)-Temp.In.D.In.g;
        if sum(Statement) ~= 0
            ii = ii + 1;
            mode_range_b(ii)    = find(Temp.In.D.m ==  2*Temp.In.D.In.m_p + Temp.Space.k(ik)-Temp.In.D.In.g);
            ind_range_k_b(ii)     = find(Temp.Space.k== Temp.Space.k(ik));
        end
    end
    ii = 0;
    for ik = 1:Temp.Space.N
        Statement = Temp.In.D.m ==  2*Temp.In.D.In.m_p + Temp.Space.k(ik);
        if sum(Statement) ~= 0
            ii = ii + 1;
            mode_range_c(ii)    = find(Temp.In.D.m ==  2*Temp.In.D.In.m_p + Temp.Space.k(ik));
            ind_range_k_c(ii)     = find(Temp.Space.k== Temp.Space.k(ik));
        end
    end

    omega_a = zeros(1,Temp.Space.N);
    omega_a(ind_range_k_a) = (Temp.In.D.omega(mode_range_a) - Temp.In.D.omega(ind_m1) - Temp.Space.k(ind_range_k_a).*Temp.In.D.D1(ind_m1));

    omega_b = zeros(1,Temp.Space.N);
    omega_b(ind_range_k_b) = (Temp.In.D.omega(mode_range_b) - Temp.In.D.omega(ind_m2) - Temp.Space.k(ind_range_k_b).*Temp.In.D.D1(ind_m1));
    
    Temp.Eq.gam2o = zeros(1,Temp.Space.N);
    Temp.Eq.gam2e = zeros(1,Temp.Space.N);
    Temp.Eq.gam3o = zeros(1,Temp.Space.N);
    Temp.Eq.gam3e = zeros(1,Temp.Space.N);

    Temp.Eq.gam2o(ind_range_k_a)          =   Temp.In.D.gamma2(mode_range_a)/norm;
    Temp.Eq.gam2e(ind_range_k_b)          =   Temp.In.D.gamma2(mode_range_b)/norm/2;

    Temp.Eq.gam3o(ind_range_k_a)          = 3*Temp.In.D.gamma3(mode_range_a)/norm;
    Temp.Eq.gam3e(ind_range_k_c)          = 3*Temp.In.D.gamma3(mode_range_c)/norm;


%    mode_range_a = ind_m1-Temp.In.D.In.Nenv/2:ind_m1+Temp.In.D.In.Nenv/2-1;
 %   mode_range_b = ind_m2-Temp.In.D.In.Nenv/2:ind_m2+Temp.In.D.In.Nenv/2-1;
  %  mode_range_c = ind_m3-Temp.In.D.In.Nenv/2:ind_m3+Temp.In.D.In.Nenv/2-1;
%%
 %   tt                      = [Temp.Space.k,Temp.Space.k];
 %   Temp.Eq.mode_range      =     find( tt < 2*256 & tt > -2*256);

 %   ind_off                 =  sum(mode_range_a<1);
%    Temp.Eq.mode_range(Temp.Space.N/2:Temp.Space.N/2+ind_off) = [];

 %   mode_range_a = mode_range_a(mode_range_a>0);
 %   omega_a = zeros(1,Temp.Space.N);
  %  omega_a(1+ind_off:Temp.Space.N) = (Temp.In.D.omega(mode_range_a) - Temp.In.D.omega(ind_m1) - [-(Temp.Space.N/2-ind_off):Temp.Space.N/2-1].*Temp.In.D.D1(ind_m1));
   % omega_a = ifftshift(omega_a);

%     Temp.Eq.gam2o          = zeros(1,Temp.Space.N);
%     Temp.Eq.gam3o          = zeros(1,Temp.Space.N);
% 
%     Temp.Eq.gam2o(1+ind_off:Temp.Space.N)      = (Temp.In.D.gamma2(mode_range_a))/norm;  % /norm;
%     Temp.Eq.gam3o(1+ind_off:Temp.Space.N)      = (3*Temp.In.D.gamma3(mode_range_a))/norm;
% 
%     Temp.Eq.gam2o          = ifftshift(Temp.Eq.gam2o );
%     Temp.Eq.gam3o          = ifftshift(Temp.Eq.gam3o );
% 
%     ind_off                 =  sum(mode_range_b<1);
%     
%     Temp.Eq.mode_range([mode_range_a < 1, mode_range_b < 1]) = [];
% 
%     mode_range_b = mode_range_b(mode_range_b>0);
%     omega_b = zeros(1,Temp.Space.N);
%     omega_b(1+ind_off:Temp.Space.N) = (Temp.In.D.omega(mode_range_b) - Temp.In.D.omega(ind_m2) - [-(Temp.Space.N/2-ind_off):Temp.Space.N/2-1].*Temp.In.D.D1(ind_m1));
%     omega_b = ifftshift(omega_b);
% %    mode_range_c = mode_range_b;
% 
%     Temp.Eq.gam2e          = zeros(1,Temp.Space.N);
%     Temp.Eq.gam3e          = zeros(1,Temp.Space.N);
% 
%     Temp.Eq.gam2e(1+ind_off:Temp.Space.N)      = (Temp.In.D.gamma2(mode_range_b))/norm;  % /norm;
%     Temp.Eq.gam3e(1+ind_off:Temp.Space.N)      = (3*Temp.In.D.gamma3(mode_range_c))/norm;
% 
%     Temp.Eq.gam2e          = ifftshift(Temp.Eq.gam2e );
%     Temp.Eq.gam3e          = ifftshift(Temp.Eq.gam3e );


%%
    Temp.Eq.Lo          = zeros(1,Temp.Space.N);
    Temp.Eq.Le          = zeros(1,Temp.Space.N);

    Temp.Eq.Lo              = Temp.Eq.delta_o + omega_a/norm - 1i*Temp.Eq.ko/2;
    Temp.Eq.Le              = (-2*(Temp.In.D.omega(ind_m1)-Temp.In.D.In.delta) +Temp.In.D.omega(ind_m2))/norm ...
    + omega_b/norm - 1i*Temp.Eq.ke/2;
%Temp.Eq.Le              = Temp.Eq.delta_e + omega_b/norm - 1i*Temp.Eq.ke/2;
    Temp.Eq.L               = [Temp.Eq.Lo,Temp.Eq.Le];
end
