    function [f,g] = L_L_Soliton_Full_Dispersion(Dir,L_L,x)
    
        N        = L_L.Space.N;        
        Num      = 9;
        N2       = (Num -1)/2;
        dir_1    = [1/280,-4/105,1/5,-4/5,0,4/5,-1/5,4/105,-1/280]/L_L.Space.dphi;
%        dir_1    = [-1/2,0,1/2]/L_L.Space.dphi;
        dir_1_diag = spdiags(dir_1',0,Num,Num);

        [~,Num1,Num2] = Umax_value_pos(x,N);
        
        x_re = x(1:N)';
        x_im = x(N+1:2*N)';
        
        f_r = spdiags(x_re,0,N,N);
        f_i = spdiags(x_im,0,N,N);
        
        der_x_re = Dir.d1*x_re;
        der_x_im = Dir.d1*x_im;
        
        
        V_eq_jac     = sparse(1,2*N);
        V_eq_jac(Num1-N2:Num1+N2) = 2*(dir_1_diag*x(Num1-N2:Num1+N2)');%                
        V_eq_jac(Num2-N2:Num2+N2) = 2*(dir_1_diag*x(Num2-N2:Num2+N2)');%  ;                
        V = x(2*N+1);
        
%%        
       f(1:N)       = V*Dir.d1*x_re  - L_L.Eq.D(2)/2*Dir.d2*x_im + L_L.Eq.D(3)/6*Dir.d3*x_re + L_L.Eq.D(4)/24*Dir.d4*x_im  + L_L.Eq.delta*x_im - L_L.Eq.kappa/2*x_re - L_L.Eq.gamma_3*x_im.*(x_re.^2 + x_im.^2);
       f(N+1:2*N)   = V*Dir.d1*x_im  + L_L.Eq.D(2)/2*Dir.d2*x_re + L_L.Eq.D(3)/6*Dir.d3*x_im - L_L.Eq.D(4)/24*Dir.d4*x_re  - L_L.Eq.delta*x_re - L_L.Eq.kappa/2*x_im + L_L.Eq.gamma_3*x_re.*(x_re.^2 + x_im.^2) + L_L.Eq.h;      
       f(2*N+1)     = dir_1*[(x(Num1-N2:Num1+N2).^2 + x(Num2-N2:Num2+N2).^2)]';
       
       f            = f';
%%        

        g_1_1 =               V*Dir.d1 +  L_L.Eq.D(3)/6*Dir.d3  - L_L.Eq.kappa/2*speye(N,N) - L_L.Eq.gamma_3*2*f_r.*f_i;
        g_1_2 =   - L_L.Eq.D(2)/2*Dir.d2 + L_L.Eq.D(4)/24*Dir.d4 +   L_L.Eq.delta*speye(N,N) - L_L.Eq.gamma_3*(f_r.^2+3*f_i.^2);
        g_1_3 =     der_x_re;
        
        g_2_1 =     L_L.Eq.D(2)/2*Dir.d2 - L_L.Eq.D(4)/24*Dir.d4 -  L_L.Eq.delta*speye(N,N)  +  L_L.Eq.gamma_3*(3*f_r.^2+f_i.^2);
        g_2_2 =                 V*Dir.d1 + L_L.Eq.D(3)/6*Dir.d3  - L_L.Eq.kappa/2*speye(N,N) +  L_L.Eq.gamma_3*2*f_r.*f_i;
        g_2_3 =      der_x_im;
        
        g_3_1_2(1,:)                 =  V_eq_jac;        
     
               
        g_3_3                      = sparse(1,1);
        
        g = [g_1_1,g_1_2,g_1_3;
             g_2_1,g_2_2,g_2_3;
                 g_3_1_2,g_3_3];
   %      g = [g_1_1,g_1_2;
    %        g_2_1,g_2_2];
        function [Umax,Num1,Num2] = Umax_value_pos(Slv,N)

            MM = abs(Slv(7:N-7)+1i*Slv(N+1+6:2*N-7));
            [Umax,Num1] = max(MM);
            Num1     =  Num1 + 6;
            Num2     = Num1 +  N;

        end
        
    end
