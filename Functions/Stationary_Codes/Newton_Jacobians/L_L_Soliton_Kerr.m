        function [f,g] = L_L_Soliton_Kerr(Dir,L_L,x)
        

        N   = size(x,2)/2;
        L_L.Eq.D(4) = 0;
        f_r = spdiags(x(1:N)',0,N,N);
        f_i = spdiags(x(N+1:2*N)',0,N,N);
        
        f(1:N)       =  L_L.Eq.D(4)/24*Dir.d4*x(1:N)' - L_L.Eq.D(2)/2*Dir.d2*x(1:N)'     + L_L.Eq.delta*x(1:N)'     + L_L.Eq.kappa/2*x(N+1:2*N)' - (x(1:N)'.^2 + x(N+1:2*N)'.^2).*x(1:N)'*L_L.Eq.gamma_3 - L_L.Eq.h;
        f(N+1:2*N)   =  L_L.Eq.D(4)/24*Dir.d4*x(N+1:2*N)' - L_L.Eq.D(2)/2*Dir.d2*x(N+1:2*N)' + L_L.Eq.delta*x(N+1:2*N)' - L_L.Eq.kappa/2*x(1:N)'     - (x(1:N)'.^2 + x(N+1:2*N)'.^2).*x(N+1:2*N)'*L_L.Eq.gamma_3;
        
        f = f';
        
        g_1_1 = L_L.Eq.D(4)/24*Dir.d4 - L_L.Eq.D(2)/2*Dir.d2  + L_L.Eq.delta*speye(N,N) - (3*f_r.^2+f_i.^2)*L_L.Eq.gamma_3;
        g_1_2 =   speye(N,N)*L_L.Eq.kappa/2 - 2*f_r.*f_i*L_L.Eq.gamma_3;
        
        g_2_1 = - speye(N,N)*L_L.Eq.kappa/2 - 2*f_r.*f_i*L_L.Eq.gamma_3;
        g_2_2 = L_L.Eq.D(4)/24*Dir.d4 - L_L.Eq.D(2)/2*Dir.d2 + speye(N,N)*L_L.Eq.delta - (f_r.^2+3*f_i.^2)*L_L.Eq.gamma_3;
        
        g = [g_1_1,g_1_2;
             g_2_1,g_2_2];
        
    end
