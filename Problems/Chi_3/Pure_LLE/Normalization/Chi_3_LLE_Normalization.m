function L_L = Chi_3_LLE_Normalization(L_L)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Define Space 

        Fundamental_Constants;
        L_L.CW.Space   = Define_Space_Cavity(L_L.In.N,2*pi);
        L_L.Temp.Space = Define_Space_Cavity(L_L.In.N,2*pi);
        L_L.Stat.Space = Define_Space_Cavity(L_L.In.N,2*pi);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Extract Some Cavity Parameters
        
      L_L.In.omega   =  L_L.In.omega_p;
        
       for i = 1:size(L_L.In.D,2)
            
           L_L.In.omega = L_L.In.omega + L_L.Temp.Space.k.^i.*...
            L_L.In.D(i)/factorial(i);
           
       end
        

        L_L.In.Finess          = L_L.In.D(1)/L_L.In.kappa;
        coeff                  = L_L.In.norm_coeff;
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% CW Constants

        L_L.In.eff_index = 1:L_L.CW.Space.N;
        
        L_L.CW.Eq.delta        = L_L.In.delta/coeff;
        L_L.CW.Eq.kappa        = L_L.In.kappa/coeff;
        L_L.CW.Eq.kappa_vector = L_L.CW.Eq.kappa*ones(1,L_L.CW.Space.N);
        L_L.CW.Eq.gamma_3      = L_L.In.gamma/coeff;
        
        L_L.CW.Eq.h            = 1/2*L_L.In.kappa*sqrt(L_L.In.Finess*L_L.In.P...
            /pi*L_L.In.eta)/coeff;
        
        L_L.CW.Eq.gamma_Kerr   =  L_L.CW.Eq.gamma_3*ones(1,L_L.Temp.Space.N);


        L_L.CW.Eq.D            = L_L.In.D/coeff;
        
        L_L.CW.Eq.Raman.mu     = 0.18;
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        
%% Temp Constants

        L_L.Temp.Eq                = L_L.CW.Eq;
        
        L_L.Temp.Eq.omega_j      =  (L_L.In.omega - L_L.In.omega_p... 
        - L_L.In.D(1)*L_L.Temp.Space.k)/coeff - 1i*L_L.CW.Eq.kappa/2;  
        L_L.Temp.Eq.gamma_Kerr   =  L_L.CW.Eq.gamma_3*ones(1,L_L.Temp.Space.N);
        L_L.Temp.Eq.mask         =  ones(1,L_L.Temp.Space.N);
        L_L.Temp.Eq.kappa_vector =  ones(1,L_L.Temp.Space.N)*L_L.CW.Eq.kappa;
        L_L.Temp.Eq.mode_range   =  [1:350,(L_L.Temp.Space.N-350):L_L.Temp.Space.N];
        L_L.Temp.Eq.L                    =   L_L.Temp.Eq.omega_j  + L_L.CW.Eq.delta;
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        
%% Stat Constants

        L_L.Stat.Eq                = L_L.Temp.Eq;
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        
end
