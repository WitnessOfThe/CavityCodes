function [F_s,t_s] = Full_Runge_ESDIRK_Kerr(F_e,gamma_3,Pump,L,dt,nt,NN,Loops,per_loop,N,Runge,Delta,D1,D2,D3,D4,delta,gamma,Runge_expl)
           
%%        
    i1      = 1;
    j        = NN;    
    F_s      = zeros(Loops*per_loop,N) + 1i*zeros(Loops*per_loop,N);
    t_s      = zeros(1,Loops*per_loop);
    loc_err_save  = zeros(1,nt);
    Newton_iter = zeros(1,nt);
    dt_s        = zeros(1,nt);
    
%% Define Time Steps inside the runge

    b      = Runge.b;
    c      = Runge.c;
    c_1    = Runge.c_l;
    s      = Runge.s;
    gamma_runge = Runge.gamma;
    a_hat  = Runge.b;
    a_hat(1,1) =0;
    
    k_max  = 40;
 
%%

            Dir     = Finite_Derivatives(N,2*pi/N);
            a1      = - D1*Dir.d1 + 1i*D2*Dir.d2/2 + 1/3/2*D3*Dir.d3 - 1i*D4/4/3/2*Dir.d4 - 1i*delta*speye(N,N) - gamma*speye(N,N); 
            
%%
    gamma_matrix =      b/ (b + gamma_runge*eye(size(b)));
    beta_matrix  =     a_hat/(a_hat + gamma_runge*eye(size(a_hat)));
    
%%


    d            = c/b;
    A_kron       = kron(b(1:end,1:end),speye(2*N));
    tic
    h = waitbar(0,'');
    z = complex(zeros(s+1,2*N));
    jac_const = speye(2*N) - dt*gamma_runge*J(F_e);
    
    dt_s(1:2)  = dt;
    
       for ni= 2:nt+1  
    tic       
        [F_e,z,loc_err_save(ni),Newton_iter(ni),dt_s(ni+1)] = Implicit_Runge_Kerr_step( F_e,dt_s(ni),nt,z,dt_s(ni-1));
    toc 
        if (j == NN)     
        %     toc
             F_s(i1,1:N) = F_e;
             t_s(i1)     = dt*(ni+1);
             i1          = i1+1;
             j           = 0;     
             waitbar(ni/nt,h,strcat(Delta.Initial_Guess,Delta.Physics,Delta.Runge_Type,'|||',sprintf('%.4f',ni/nt*100),'%' ))
        end
         
        j=j+1;     
        
    end
    
close(h)

    function    [F_e,z,loc_err_max,Newt,dt]   =    Implicit_Runge_Kerr_step(B_E,dt,nt,z_old,dt_old)
        
        fl = 0;
        
        while fl ~= 1
            
            z        = complex(zeros(s+1,2*N));

            if nt == 1

                z(1,1:2*N) = dt*gamma_runge*Equation_with_Kerr(B_E);

            else

                for i = 1:s

                    if gamma_matrix(s+1,i) ~= 0      

                        z(1,1:2*N) = z(1,1:2*N) + gamma_matrix(s+1,i)*z_old(i,1:2*N);

                    end 

                end

                z(1,1:2*N) = dt/dt_old*(z_old(s+1,1:2*N) -  z(1,1:2*N));

            end

            for i = 2:1 + s

                [z(i,1:2*N),Newt(i-1)]    =    Runge_Kerr_step(B_E,dt,z,i);

            end
            Newt = max(Newt);

            [F_e,loc_err,dt,fl]   =        y_1(B_E,z,dt,max(Newt),k_max);
            loc_err_max =  max(abs(loc_err));
            
        end
        
    end

    function     [z_i,Newt]    =    Runge_Kerr_step(B_E,dt,z,i)
        
        z_i(1,1:2*N) = complex(zeros(1,2*N));
        
        for jj = 1:i-1
            
            if beta_matrix(i,jj) ~= 0
                
                z_i(1,1:2*N) = z_i(1,1:2*N) + beta_matrix(i,jj)*z(jj,:);
                
            end 
            
        end
        
        [z_i,Newt] = Newton_step(B_E,z_i,z,i);
                     
        function [z_i,i_err] = Newton_step(B_E,z_0,z,i)
            
            err_0 = 1*10^-30;
            i_err = 1;
            
            sum_gamma_z(1,1:2*N) = complex(zeros(1,2*N)); 
            
            for ii = 1:i-1
                
                sum_gamma_z(1,1:2*N) = sum_gamma_z(1,1:2*N) + gamma_matrix(i,ii)*z(ii,1:2*N);
                
            end
            
            z_i = z_0;
            
            [F_z_k] = F_z(B_E,sum_gamma_z,z_0(1,:));
            Err(1:2) =1;
            
            while err_0 < Err(i_err) && i_err < k_max
                   % [B_f,~,~,~] = y_1(B_E,z,dt,1,1);
                    i_err = i_err + 1;
                    
                    jac_const = speye(2*N) - dt*gamma_runge*J(B_E);
                    
%                   tic
                    delta_z   = jac_const\F_z_k';
%                   toc
                    if i_err > 2
                        theta_k    = norm(delta_z)./norm(delta_z_old);
                        Err(i_err) = theta_k/(1-theta_k)*norm(delta_z);
                    end
%                   i_err
                    delta_z_old = delta_z;
                    z_i      = z_i + delta_z';
                    
                    F_z_k  = F_z(B_E,sum_gamma_z,z_i);
                    
                    
            end

                     function F_z_k = F_z(Psi,sum_gamma_z,z_k)

                            F_z_k          = sum_gamma_z - z_k + dt*gamma_runge*Equation_with_Kerr(Psi+z_k(1:N));
                            
                     end
                     
%         function jac = J( Psi )
%             
%             f_r   = spdiags(real(Psi)',0,N,N);
%             f_i   = spdiags(imag(Psi)',0,N,N);
%             
%             g_1_1   = - D1*Dir.d1    - speye(N,N)*gamma - gamma_3*2*f_r.*f_i;
%             g_1_2   = - D2*Dir.d2/2  + delta*speye(N,N) - gamma_3*(f_r.^2+3*f_i.^2);
%             
%             g_2_1   =   D2*Dir.d2/2  - delta*speye(N,N) + gamma_3*(3*f_r.^2+f_i.^2);
%             g_2_2   = - D1*Dir.d1    - speye(N,N)*gamma + gamma_3* 2*f_r.*f_i;
%             
%             
%             jac = [g_1_1,g_1_2;
%                    g_2_1,g_2_2];
%         end

        end
    end

    function k_e_out = Equation_with_Kerr( Psi )

        F_Psi         = fft(Psi(1:N));
        abs_Psi_2     = abs(Psi(1:N)).^2;
        
        k_e           = ifft(-1i*L.*F_Psi) + 1i*( gamma_3*abs_Psi_2.*Psi(1:N) + Pump );
        k_e_out       = [k_e,conj(k_e)];
        
    end

    function [B_f,loc_err,dt_new,fl] = y_1(B_E,z,dt,Newt,k_max)
        
            B_f  = B_E;
            B_ff = B_E;
            
            Atol = 10^-20;
            Rtol = 10^-15;
            
            for i = 1:s+1
                
                    
                    k (1,1:2*N) = dt*Equation_with_Kerr(B_E + z(i,1:N));
                    B_f         = B_f  + c(i)*k(1,1:N);
                    B_ff        = B_ff + c_1(i)*k(1,1:N);


            end
            
            tt       = B_f - B_ff;
            loc_err  = abs(([tt,conj(tt)])/jac_const);
            
            fac      = 0.9*(2*k_max+1)./(2*k_max+Newt);
            sc       = Atol + abs([B_f])*Rtol;
            err_norm = norm(tt./sc)/sqrt(N);
            
            dt_new  = fac*dt*err_norm.^(-1/4);
            
            if (dt_new >= dt) && (dt_new <= 1.2*dt )
                
                fl = 1;
                dt_new = dt;
                
            elseif dt_new < dt 
                
                fl     = 0;
                
            elseif dt_new > 1.2*dt 
            
                fl     = 1;
            
            end
            
    end


 function jac = J( Psi )

         g_1_1   =  a1 + spdiags(1i*2*gamma_3*abs(Psi').^2,0,N,N);
         g_1_2   = spdiags(     1i*gamma_3*(Psi').^2,0,N,N);

         g_2_1   =  conj(g_1_2);
         g_2_2   =  conj(g_1_1);


     jac = [g_1_1,g_1_2;
            g_2_1,g_2_2];

 end

end
    