    function f_x0  = Trials(L_L,flag)
    
        L_L.Eq.h = L_L.Eq.h*sqrt(L_L.Eq.gamma_3);
        
        N        = L_L.Space.N;
        phi      = acos(-L_L.Eq.h/2.* (27./L_L.Eq.delta^3)^0.5);
        g         = 2*(L_L.Eq.delta/3).^0.5.*cos((phi-2*pi)/3);
        
        switch flag
            
            case '-'
                
                f_x(1,1:N)      = -(2.*L_L.Eq.delta)^(0.5).*sech(L_L.Space.phi.*(L_L.Eq.delta./(L_L.Eq.D(2)/2)).^(0.5));%
                f_x(1,N+1:2*N)  = 0;
                f_x0(1,1:N)     = f_x(1,1:N)+g;
                f_x0(1,N+1:2*N) = f_x(1,N+1:2*N);
                f_x0 = f_x0/sqrt(L_L.Eq.gamma_3);
                
            case '+'
                
                f_x(1,1:N)      = (2.*L_L.Eq.delta)^(0.5).*sech(L_L.Space.phi.*(L_L.Eq.delta./(L_L.Eq.D(2)/2)).^(0.5));%0.75
                f_x(1,N+1:2*N)  = 0;
                f_x0(1,1:N)     = f_x(1,1:N)+g;
                f_x0(1,N+1:2*N) = f_x(1,N+1:2*N);
                f_x0            = f_x0/sqrt(L_L.Eq.gamma_3);
        end
        
    end
