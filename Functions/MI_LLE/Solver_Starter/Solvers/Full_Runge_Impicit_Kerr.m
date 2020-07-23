function [F_s,t_s] = Full_Runge_Impicit_Kerr(F_e,gamma_3,Pump,L,dt,nt,NN,Loops,per_loop,N,Runge,Delta,D1,D2,D3,D4,delta,gamma)
           
%%        
    i1      = 1;
    j        = NN;    
    F_s      = zeros(Loops*per_loop,N) + 1i*zeros(Loops*per_loop,N);
    t_s      = zeros(1,Loops*per_loop);
    
%% Define Time Steps inside the runge

    b      = Runge.b;
    c      = Runge.c;
    s      = Runge.s;
    gamma_runge = Runge.gamma;
    a_hat  = (Runge.b - diag(Runge.b));
    
    
    
%%
            Dir     = Finite_Derivatives(N,2*pi/N);
            a1      = - D1*Dir.d1 + 1i*D2*Dir.d2/2 + 1/3/2*D3*Dir.d3 - 1i*D4/4/3/2*Dir.d4 - 1i*delta*speye(N,N) - gamma*speye(N,N); 
%%
    gamma_matrix = b/ (b + gamma_runge*eye(size(b)));
    beta_matrix  = a_hat/(a_hat + gamma_runge*eye(size(a_hat)));
%
d            = c/b;
    A_kron       = kron(b(1:end,1:end),speye(2*N));
%%
    
%tic
h = waitbar(0,'');
    for ni=1:nt  
        
        F_e = Implicit_Runge_Kerr_step(F_e,dt);
        
        if (j == NN)     
        %     toc
             F_s(i1,1:N) = F_e;
             t_s(i1)     = dt*ni;
             i1          = i1+1;
             j           = 0;     
             waitbar(ni/nt,h,strcat(Delta.Initial_Guess,Delta.Physics,Delta.Runge_Type,'|||',sprintf('%.4f',ni/nt*100),'%' ))
        end
         
        j=j+1;     
        
    end
close(h)
    function     B_f    =    Implicit_Runge_Kerr_step(B_E,dt)
        
        z_0       = Runge_Kuarong_Kerr_step(B_E,dt); 
        
        z         = Newton_step(B_E,z_0);
        
        B_f       = y_1(B_E,z);   
   
    end
    
    function     z_0    =    Runge_Kuarong_Kerr_step(B_E,dt)

            k_r      = complex(zeros(s+1,2*N));
            z_exp    = complex(zeros(s+1,2*N));
            z_0      = complex(zeros((s+1)*2*N,1));

            k_r  (1,1:2*N) = dt*Equation_with_Kerr(B_E);
            z_0(1:2*N,1)   = gamma_runge*k_r(1,1:2*N)';
            
%         for i = 2:s+1
% 
%             B_E_temp = [B_E,conj(B_E)];
% 
%             for ii= 1:s
%                 
%                 if b(i,ii) ~=0 
%                     
%                     z_exp(i,1:2*N) = z_exp(i,1:2*N) + b(i,ii).*k_r(ii,:);
%                     
%                 end
%                 
%                    B_E_temp       = B_E_temp + z_exp(i,1:2*N);
%                    
%              end
% 
%             k_r (i,1:2*N)  = dt*Equation_with_Kerr(B_E_temp(1:N));
% 
%         end 
%         
%         for i = 2:(s+1)
%             for i2 = 1:i-1
%                 
%                if beta_matrix(i,i2)  ~= 0
% 
%                     z_0(2*N + 1 + (i-2)*2*N:(4*N+(i-2)*2*N),1) = z_0(1+(i - 2)*2*N:(2*N+( i - 2 )*2*N),1) + beta_matrix(i,i2)*z_exp(i,1:2*N)';
% 
%                end
%                
%             end
%         end
% %             
    end    
    
    function z = Newton_step(Psi,z_0)
        
            err_0   = 10^-13;
 %          z_0 = zeros(2*N*(s+1),1);
            z   = z_0;
            F_z_k   = F_z(Psi,z_0);
            i_err =1 ;
            Err(1)   = norm(F_z_k);
            B_e = Psi;
            
        while err_0 < Err(i_err)
            jac_const = jac_inter(B_e);
            
            i_err = i_err + 1;
            
            tic
            delta_z   = jac_const\F_z_k;
            toc
            
            i_err
            
            z(1:end,1) = z_0(1:end,1) + delta_z;
            
            F_z_k      = F_z(Psi,z);
            Err(i_err) = norm(F_z_k);
            z_0        = z;
            B_e        = y_1(Psi,z);   
            
       end
        
         function F_z_k = F_z(Psi,z_0)

            F_z_k          = complex(zeros((s+1)*2*N,1));

            for i = 1:s+1
                
                tt                                 =   [Psi,conj(Psi)]' + z_0(1+(i-1)*2*N:2*N+(i-1)*2*N,1);
                F_z_k(1+(i-1)*2*N:2*N+(i-1)*2*N,1) =  Equation_with_Kerr( tt');
                
            end
            
             F_z_k =  - z_0(1:end,1)+dt*A_kron*F_z_k;
            
        end
       
        
    end
        

    function k_e_out = Equation_with_Kerr( Psi )

        F_Psi         = fft(Psi(1:N));
        abs_Psi_2     = abs(Psi(1:N)).^2;
        
        k_e           = ifft(-1i*L.*F_Psi) + 1i*( gamma_3*abs_Psi_2.*Psi(1:N) + Pump );
        k_e_out       = [k_e,conj(k_e)];
        
    end

    function B_f = y_1(B_E,z)
        
            B_f = B_E;
            
            for i = 1:s+1

                if d(i)~=0

                    B_f = B_f + d(i)*z(1+(i-1)*2*N:N+(i-1)*2*N,1)';

                end

            end
    end
    function jac_const = jac_inter(B_E)
        
        jac       = J(B_E);
        jac_const = speye(2*N*(s+1),2*N*(s+1)) - dt*kron(b(1:end,1:end),jac); 
        
%         function jac = J_1( Psi )
%         
%             g_1_1   =  a1 + spdiags(1i*2*gamma_3*abs(Psi').^2,0,N,N);
%             g_1_2   =  spdiags(1i*gamma_3*(Psi').^2,0,N,N);
%             
%             g_2_1   =  conj(g_1_2);
%             g_2_2   =  conj(g_1_1);
%             
%             
%             jac = [g_1_1,g_1_2;
%                    g_2_1,g_2_2];
%         end
        function jac = J( Psi )
            
            f_r   = spdiags(real(Psi)',0,N,N);
            f_i   = spdiags(imag(Psi)',0,N,N);
            
            g_1_1   = - D1*Dir.d1    - speye(N,N)*gamma - gamma_3*2*f_r.*f_i;
            g_1_2   = - D2*Dir.d2/2  + delta*speye(N,N) - gamma_3*(f_r.^2+3*f_i.^2);
            
            g_2_1   =   D2*Dir.d2/2  - delta*speye(N,N) + gamma_3*(3*f_r.^2+f_i.^2);
            g_2_2   = - D1*Dir.d1    - speye(N,N)*gamma + gamma_3* 2*f_r.*f_i;
            
            
            jac = [g_1_1,g_1_2;
                   g_2_1,g_2_2];
        end

    end
    
end
    