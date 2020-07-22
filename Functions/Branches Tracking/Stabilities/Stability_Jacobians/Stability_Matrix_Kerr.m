    function g = Stability_Matrix_Kerr(Dir,L_L)
        
        N   = L_L.Space.N;
        
       f_r   = spdiags(real(L_L.Solution.Psi)',0,N,N);
       f_i   = spdiags(imag(L_L.Solution.Psi)',0,N,N);

                        
       g_1_1 = - speye(N,N)*L_L.Eq.kappa/2 - 2*f_r.*f_i*L_L.Eq.gamma_3;
       g_1_2 = - L_L.Eq.D2/2*Dir.d2  + L_L.Eq.delta*speye(N,N) - (f_r.^2+3*f_i.^2)*L_L.Eq.gamma_3;
        
       g_2_1 =   L_L.Eq.D2/2*Dir.d2  - L_L.Eq.delta*speye(N,N) + (3*f_r.^2+f_i.^2)*L_L.Eq.gamma_3;
       g_2_2 =  - speye(N,N)*L_L.Eq.kappa/2 + 2*f_r.*f_i*L_L.Eq.gamma_3;
        
        g = [g_1_1,g_1_2;
             g_2_1,g_2_2];
        
    end
