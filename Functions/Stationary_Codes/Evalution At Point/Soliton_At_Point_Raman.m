   function [Slv_1,L_L] = Soliton_At_Point_Raman(L_L,options)
        
        N                  = L_L.Space.N;
        
        NN                 = 50;
        L_L_start.Eq.h     = 0.0;
        L_L_start.Eq.gamma = 0.0;
        L_L_start.Eq.delta = L_L.Eq.delta;
        L_L_start.Eq.d     = L_L.Eq.d;
        
        gamma_vector       = linspace(L_L_start.Eq.gamma,L_L.Eq.gamma,NN);
        h_vector           = linspace(L_L_start.Eq.h    ,L_L.Eq.h,NN);
        
        Slv   = Trials(Space,L_L_start,Sol_Flag);
        
        for ii=1:NN
            
            L_L_start.Eq.h = h_vector(ii);
            Slv   = fsolve(@(x)L_L_Soliton_Kerr(Dir,L_L_start,x),Slv,options);
            
        end
                
        for ii=1:NN
            
            L_L_start.Eq.gamma = gamma_vector(ii);
            Slv   = fsolve(@(x)L_L_Soliton_Kerr(Dir,L_L_start,x),Slv,options);
            
        end
                
        Slv_1(1:N)               = Slv(1:N);
        Slv_1(N+1:2*N)     = Slv(N+1:2*N);
        Slv_1(2*N+1:3*N+1) = zeros(1,N+1);
        
        mu_vector    = linspace(0,L_L.Raman.mu,NN);
        L_L.Eq.mu = mu_vector(1);
        
        
        for ii = 1:NN
            
            L_L.Eq.mu     = mu_vector(ii);
            [Slv_1,~,~,~] = fsolve(@(x)L_L_Soliton_Raman(Dir,L_L_start,x),Slv_1,options);
            
        end
        
        L_L      = Prop_gen(L_L,Slv_1,Delta);  
        
        figure;
        plot(Slv_1);
        
    end
