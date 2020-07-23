function L_L = CW_another_normalization(L_L)

    gamma   = L_L.In.gamma2_o*L_L.In.gamma2_e;
    delta_o = L_L.In.delta_o;
    delta_e = 2*L_L.In.delta_o - L_L.In.epsilon;
    
    a     = -abs(L_L.In.h)^2*(L_L.In.kappa_e^2+delta_e^2);
    b     = delta_o*delta_e        - L_L.In.kappa_o*L_L.In.kappa_e;
    c     = delta_o*L_L.In.kappa_e + delta_e*L_L.In.kappa_o;    
    x     = [gamma^2, -2*gamma*b,b^2+c^2,a];
    
%%
    x_roots    = roots(x);
    ind        = imag(x_roots) == 0;
        
%%
    L_L.Solution.CW.Psi_p = -L_L.In.h./(  delta_o - 1i*L_L.In.kappa_o - gamma.*x_roots./(delta_e - 1i*L_L.In.kappa_e) ).*ind; 
    L_L.Solution.CW.Psi_s = L_L.In.gamma2_e*L_L.Solution.CW.Psi_p.^2./(delta_e - 1i*L_L.In.kappa_e).*ind;

end
