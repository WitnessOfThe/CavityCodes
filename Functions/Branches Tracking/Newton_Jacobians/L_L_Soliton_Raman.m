    function [f,g] = L_L_Soliton_Raman(Dir,L_L,x)
    
        N = L_L.Space.N;                  

%%        
        L_L.Eq.h = L_L.Eq.h*sqrt(L_L.Eq.gamma_3);
        
        t_0                = sparse(N,N);
        t_1                =  speye(N,N);
        
       Cff                = (L_L.Raman.omega^2+L_L.Raman.gamma^2)/L_L.Raman.alpha^2;
       
       Norm_Matrix_Newton =  [t_1,t_0,            t_0     ,t_0(:,1);
                              t_0            ,t_1,t_0     ,t_0(:,1);
                              t_0            ,t_0            ,t_1./Cff,t_0(:,1);
                              t_0(1,:)       ,t_0(1,:)       ,t_0(1,:),t_1(1,1)];
       N = L_L.Space.N;                  
%%

        [~,Num1,Num2] = Umax_value_pos(x,N);

        f_r = spdiags(x(1:N)',0,N,N);
        f_i = spdiags(x(N+1:2*N)',0,N,N);
        Q_r = spdiags(x(2*N+1:3*N)',0,N,N);
        
        velement     =  [(x(Num1-4)^2+x(Num2-4)^2),(x(Num1-3)^2+x(Num2-3)^2),(x(Num1-2)^2+x(Num2-2)^2),(x(Num1-1)^2+x(Num2-1)^2),(x(Num1)^2+x(Num2)^2),(x(Num1+1)^2+x(Num2+1)^2),(x(Num1+2)^2+x(Num2+2)^2),(x(Num1+3)^2+x(Num2+3)^2),(x(Num1+4)^2+x(Num2+4)^2)];
        velementNum1 = 2*[x(Num1-4),x(Num1-3),x(Num1-2),x(Num1-1),x(Num1),x(Num1+1),x(Num1+2),x(Num1+3),x(Num1+4)];
        velementNum2 = 2*[x(Num2-4),x(Num2-3),x(Num2-2),x(Num2-1),x(Num2),x(Num2+1),x(Num2+2),x(Num2+3),x(Num2+4)];
        
        dir_1 = [1/280,-4/105,1/5,-4/5,0,4/5,-1/5,4/105,-1/280]/(2*pi/N);
        dir_1_diag = spdiags(dir_1',0,9,9);
        
        V = x(3*N+1);
%%        
       f(1:N)       = - 2*pi*V*Dir.d1*x(N+1:2*N)' - L_L.Eq.D2/2*Dir.d2*x(1:N)'     + L_L.Eq.delta*x(1:N)'     + L_L.Eq.kappa/2*x(N+1:2*N)' - ((1-L_L.Eq.mu)*(x(1:N)'.^2+x(N+1:2*N)'.^2) + x(2*N+1:3*N)').*x(1:N)'   - L_L.Eq.h;
       f(N+1:2*N)   =   2*pi*V*Dir.d1*x(1:N)'     - L_L.Eq.D2/2*Dir.d2*x(N+1:2*N)' + L_L.Eq.delta*x(N+1:2*N)' - L_L.Eq.kappa/2*x(1:N)'     - ((1-mu)*(x(1:N)'.^2+x(N+1:2*N)'.^2) + x(2*N+1:3*N)').*x(N+1:2*N)';
       f(2*N+1:3*N) =   4*pi^2*(1+V)^2*Dir.d2*x(2*N+1:3*N)' - 4*pi*(1+V)*L_L.Eq.gamma_r*Dir.d1*x(2*N+1:3*N)' + L_L.Eq.Omega_R^2*(x(2*N+1:3*N)'-L_L.Eq.mu*(x(1:N)'.^2+x(N+1:2*N)'.^2));
       f(3*N+1)     =   dir_1*velement';
       f(2*N+1:3*N) =   f(2*N+1:3*N);
       
       f = Norm_Matrix_Newton*f';
%%        

        g_1_1 = - L_L.Eq.D2/2*Dir.d2   + L_L.Eq.delta*speye(N,N)   - ( 1 - L_L.Eq.mu )*(3*f_r.^2+f_i.^2)   - Q_r;
        g_1_2 = - 2*pi*V*Dir.d1        + speye(N,N)*L_L.Eq.kappa/2 - ( 1 - L_L.Eq.mu )*2*f_r.*f_i;
        g_1_3 = - f_r;
        g_1_4 = - 2*pi*Dir.d1*x(N+1:2*N)';
        
        g_2_1 = 2*pi*V*Dir.d1 - speye(N,N)*L_L.Eq.kappa/2 - 2*f_r.*f_i*(1-L_L.Eq.mu);
        g_2_2 = - L_L.Eq.D2/2*Dir.d2 + speye(N,N)*L_L.Eq.delta - (1-L_L.Eq.mu)*(f_r.^2+3*f_i.^2) - Q_r;
        g_2_3 = - f_i;
        g_2_4 = 2*pi*Dir.d1*x(1:N)';
        
        g_3_1 = -2*speye(N,N)*f_r*L_L.Eq.mu*L_L.Eq.Omega_R^2;
        g_3_2 = -2*speye(N,N)*f_i*L_L.Eq.mu*L_L.Eq.Omega_R^2;
        g_3_3 = 4*pi^2*( 1 + V )^2*Dir.d2 - 4*pi*L_L.Eq.gamma_r*Dir.d1 + speye(N,N)*L_L.Eq.Omega_R^2;
        g_3_4 = 8*pi^2*( 1 + V )*Dir.d2*x(2*N+1:3*N)'-4*pi*L_L.Eq.gamma_r*Dir.d1*x(2*N+1:3*N)';
        
        g_4_1                      = sparse(1,N);
        g_4_1(1,Num1-4:Num1+4)     = dir_1_diag*velemeqntNum1';
        g_4_2                      = sparse(1,N);
        g_4_2(1,Num2-N-4:Num2-N+4) = dir_1_diag*velementNum2';
        g_4_3                      = sparse(1,N);
        g_4_4                      = sparse(1,1);
        
        g = [g_1_1,g_1_2,g_1_3,g_1_4;
            g_2_1,g_2_2,g_2_3,g_2_4;
            g_3_1,g_3_2,g_3_3,g_3_4;
            g_4_1,g_4_2,g_4_3,g_4_4];
        
        g = Norm_Matrix_Newton*g;
        
    end
