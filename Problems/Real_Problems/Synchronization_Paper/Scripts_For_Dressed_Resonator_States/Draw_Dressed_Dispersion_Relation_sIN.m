    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    N_Mode    = 2^5;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF
    L_L.CW.In         = Params_SiN;
    L_L.CW.In.kappa   =  1E8*2*pi;                 
    L_L.CW.In.delta   = 1e+09*2*pi;    
    L_L.CW.In.P       = 0.0005;           
    L_L.CW.In.g  = 0;%L_L.CW.Sol.g(ind)*L_L.CW.Eq.norm;
    L_L.CW       = L_L.CW.Met.Mi_Formula(L_L.CW,N_Mode);          
    t_1_1         = Plot_LLE_Dressed_State(L_L.CW,3);
    
%%
    L_L.CW.In.kappa   =  1E8*2*pi;                 
    L_L.CW.In.delta   = -1e+09*2*pi;    

    L_L.CW       = L_L.CW.Met.Solve(L_L.CW,N_Mode);          
    [~,ind]      = max(abs(L_L.CW.Sol.Psi));
    L_L.CW.In.g  = 0;%L_L.CW.Sol.g(ind)*L_L.CW.Eq.norm;
    L_L.CW       = L_L.CW.Met.Mi_Formula(L_L.CW,N_Mode);          
    t_1_2         = Plot_LLE_Dressed_State(L_L.CW,3);
%%
    L_L.CW.In.kappa   =  1E8*2*pi;                 
    L_L.CW.In.delta   = - 0.5e+09*2*pi;    
    %   L_L.CW       = L_L.CW.Met.Solve(L_L.CW,N_Mode);          
     [~,ind]      = max(abs(L_L.CW.Sol.Psi));
    L_L.CW.In.g  = 2*pi*0.2E9;
    L_L.CW       = L_L.CW.Met.Mi_Formula(L_L.CW,N_Mode);          
    t_2_1         = Plot_LLE_Dressed_State(L_L.CW,3);
    
    
%%
    L_L.CW.In.kappa   =  1E8*2*pi;                 
    L_L.CW.In.delta   = -1.5e+09*2*pi;    
    L_L.CW       = L_L.CW.Met.Solve(L_L.CW,N_Mode);          
     [~,ind]      = max(abs(L_L.CW.Sol.Psi));
    L_L.CW.In.g  = L_L.CW.Sol.g(ind)*L_L.CW.Eq.norm;
    L_L.CW       = L_L.CW.Met.Mi_Formula(L_L.CW,N_Mode);          
    t_2_2         = Plot_LLE_Dressed_State(L_L.CW,3);
  %%  
    L_L.CW.In.kappa   =  1E8*2*pi;                 
    L_L.CW.In.delta   = - 1.5e+09*2*pi;    
    %   L_L.CW       = L_L.CW.Met.Solve(L_L.CW,N_Mode);          
     [~,ind]      = max(abs(L_L.CW.Sol.Psi));
    L_L.CW.In.g  = 2*pi*1E9;
    L_L.CW       = L_L.CW.Met.Mi_Formula(L_L.CW,N_Mode);          
    t_3_1         = Plot_LLE_Dressed_State(L_L.CW,3);
    
    
%%
    L_L.CW.In.kappa   =  1E8*2*pi;                 
    L_L.CW.In.delta   = -1.5e+09*2*pi;    
    L_L.CW.In.g  =  2*pi*1E9;
    L_L.CW       = L_L.CW.Met.Mi_Formula(L_L.CW,N_Mode);          
    t_3_2         = Plot_LLE_Dressed_State(L_L.CW,3);


    