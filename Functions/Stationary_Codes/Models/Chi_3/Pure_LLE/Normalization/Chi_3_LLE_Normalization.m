function L_L = Chi_3_LLE_Normalization(L_L)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Define Space 

        Fundamental_Constants;
        N = L_L.In.N_mode;
        L_L.Space      = Define_Space_Cavity(N,2*pi);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Extract Some Cavity Parameters
        
      L_L.In.omega   =  L_L.In.omega_p;
        
       for i = 1:size(L_L.In.D,2)
            
           L_L.In.omega = L_L.In.omega + L_L.Space.k.^i.*...
            L_L.In.D(i)/factorial(i);
           
       end
       
        L_L.In.omega_int = L_L.In.omega  - L_L.In.omega_p... 
        - L_L.In.D(1)*L_L.Space.k;
    
        L_L.In.Finess          = L_L.In.D(1)/L_L.In.kappa;
        L_L.In.Fin_D           = L_L.In.D(2)/L_L.In.kappa;
        
        L_L.In.H            = sqrt(L_L.In.eta*L_L.In.Finess*L_L.In.P/pi);
        L_L.In.W            = pi/(L_L.In.eta*L_L.In.Finess)*L_L.In.H^2;
        L_L.In.W_Star       = pi/(L_L.In.eta*L_L.In.Finess)*L_L.In.kappa/L_L.In.gamma;
        L_L.In.W_WStar      = L_L.In.W/ L_L.In.W_Star;
        
        if L_L.In.kappa ~= 0
            
            coeff                  = L_L.In.kappa;
            
        else
            
            coeff                  = L_L.In.D(1);
             
        end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% CW Constants

%         L_L.In.eff_index = 1:L_L.CW.Space.N;
%         
%         L_L.CW.Eq.delta        = L_L.In.delta/coeff;
% %        L_L.CW.Eq.kappa        = L_L.In.kappa/coeff;
%         L_L.CW.Eq.kappa_vector = L_L.CW.Eq.kappa*ones(1,L_L.CW.Space.N);
%         L_L.CW.Eq.gamma_3      = L_L.In.gamma/coeff;
%         
%         L_L.CW.Eq.h            = 1/2*L_L.In.kappa*sqrt(L_L.In.Finess*L_L.In.P...
%             /pi*L_L.In.eta)/coeff;
%         
%         L_L.CW.Eq.gamma_Kerr   =  L_L.CW.Eq.gamma_3*ones(1,L_L.Temp.Space.N);
% 
% 
%         L_L.CW.Eq.D            = L_L.In.D/coeff;
%         
%         L_L.CW.Eq.Raman.mu     = 0.18;
%         
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        
%% Temp Constants

        L_L.Eq.delta        = L_L.In.delta/coeff;
        L_L.Eq.kappa        = L_L.In.kappa/coeff;
        L_L.Eq.gamma_3      = L_L.In.gamma/coeff;
        L_L.Eq.D            = L_L.In.D/coeff;
        L_L.Eq.h            = 1/2*L_L.In.kappa*sqrt(L_L.In.Finess*L_L.In.P...
             /pi*L_L.In.eta)/coeff;
         
        L_L.Eq.omega_j      =  (L_L.In.omega - L_L.In.omega_p... 
        - L_L.In.D(1)*L_L.Space.k)/coeff - 1i*L_L.Eq.kappa/2;  
    
        L_L.Eq.gamma_Kerr   =  L_L.Eq.gamma_3*ones(1,L_L.Space.N);
        
        L_L.Eq.mask         =  [ones(1,L_L.In.range),zeros(1,L_L.Space.N-L_L.In.range*2+1),ones(1,L_L.In.range-1)];
        
        L_L.Eq.kappa_vector =  ones(1,L_L.Space.N)*L_L.Eq.kappa;
        L_L.Eq.mode_range   =  [1:L_L.In.range,(L_L.Space.N-L_L.In.range+1):L_L.Space.N];
        L_L.Eq.L            =   L_L.Eq.omega_j  + L_L.Eq.delta;
        L_L.Eq.norm         = coeff;
end
