function In = Chi23_g_to_gamma(In)
    
    Fundamental_Constants;
    
    In.q_o = 2*pi/(In.Do(1)*(Const.h_bar*In.Omega_o));
    In.q_e = 2*pi/(In.De(1)*(Const.h_bar*In.Omega_e));
    
    
    In.gam2o          = sqrt(In.q_e)*In.g2o;
    In.gam2e          = In.g2e*In.q_o/sqrt(In.q_e);
    
    In.gam3o          = In.g3o*In.q_o;
    In.gam3e          = In.g3e*In.q_e;

    
%    In.gam3oe          = In.g3oe*In.q_e;
%    In.gam3eo          = In.g3eo*In.q_o;
    
end