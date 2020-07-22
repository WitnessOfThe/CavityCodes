function [B_s,F_s,t_s] = Full_Runge_Cubic_Reduced_Adaptive(F_e,dt,nt,NN,Loops,per_loop,N,Runge,Delta,gamma_cubic,phi,kappa,delta,Pump,omega_j,m,Omega_laser)
%% Define Time Steps inside the runge

    b       = Runge.b;
    c       = Runge.c;
    c_lower = Runge.c_l;  
    a       = Runge.a;
    s       = size(b,1); 
    d       = zeros(s,N);
    
%%
    mask                =  abs(omega_j./omega_j);
    mask(isnan(mask))   = 0;
     
    g = 1;
    
    N_min = find(omega_j,1,'first');
    N_max = find(omega_j,1,'last');
    
    [~,max_ind]        = max(Pump);
    
    N_min =  N - abs(N_min-max_ind+1);
    N_max = N_max-max_ind+1;
    mode_range = [1:N_max,N_min:N];
    N_prop   = size(mode_range,2);
    
%%    
    omega_j = ifftshift(circshift( omega_j,(N/2-max_ind+1)));
    kappa = ifftshift(circshift( kappa,(N/2-max_ind+1)));
    mask    = ifftshift(circshift( mask,(N/2-max_ind+1)));
    Pump    = ifftshift(circshift( Pump,(N/2-max_ind+1)));
    F_e     = ifftshift(circshift( F_e,(N/2-max_ind+1)));
    
    
    dt_array    = zeros(1,nt+1);
    i_try_array = zeros(1,nt+1);
    d           = zeros(s,N);
    
%%

    k_z             = zeros(1,N);
    Pump_term       = zeros(1,N);
    exp_plus_omega  = zeros(s,N);
    exp_minus_omega = zeros(s,N);
    shift_back      = zeros(1,N);
    g_delta         = zeros(1,s);
    
    j        = NN;    
    F_s      = zeros(Loops*per_loop,N) + 1i*zeros(Loops*per_loop,N);
    B_s      = zeros(Loops*per_loop,N) + 1i*zeros(Loops*per_loop,N);
    t_s      = zeros(1,Loops*per_loop);
    
    [exp_plus_omega,exp_minus_omega,shift_back,g_delta] = Define_Shifts(exp_plus_omega,exp_minus_omega,shift_back,g_delta,mask,omega_j,a,dt,Omega_laser,s,N,mode_range);
    
%%  
    h = waitbar(0,'');
    i1=1;
    
    dt_array(1) = dt;
    for ni=1:nt  
        
        [F_e,dt_array(ni+1),i_try_array(ni+1)] = Runge_Kuarong_Kerr_step(F_e,g,dt_array(ni));
        g   = g.*exp(1i*Omega_laser*dt_array(ni+1));
        
        
         if (j == NN)
             
             t_s(i1)     = sum(dt_array(1:ni+1));
             F_s(i1,1:N) =  circshift(ifftshift(F_e),max_ind-N/2-1);
             B_s(i1,1:N) =  F_s(i1c,1:N).*exp(1i*omega_j*t_s(i1));
             
             i1          = i1+1;
             j           = 0;
             
             waitbar(ni/nt,h,strcat(Delta.Initial_Guess,Delta.Physics,Delta.Runge_Type,'|||',sprintf('%.4f',ni/nt*100),'%' ));
             
        end
      
        j=j+1;     
        
    end
    
close(h);

function     [E_f,dt,i_try]    =    Runge_Kuarong_Kerr_step(B_E,g,dt)
    
    
            i_try    = 0; 
            Err_abs   = max(eps(B_E))*10^7;
            Err_0     = 0;  
            
      while  Err_0 == 0      
          
            E_temp    = B_E;
            E_f       = B_E;    
            E_f_lower = B_E;

            i_try    = i_try+1;
            
            d(1,:) =   Equation_with_Cubic(E_temp,g,exp_plus_omega(1,:),g_delta(1,1),exp_minus_omega(1,:));
%            d(1,:) =   exp_minus_omega(s,:).*d(s,:);

            for i = 2:s

                for ii = 1:s-1

                    if b(i,ii) ~= 0

                        E_temp(mode_range) = E_temp(mode_range) + dt*b(i,ii).*d(ii,mode_range);

                    end

                end

                d(i,:) =   Equation_with_Cubic(E_temp,g,exp_plus_omega(i,:),g_delta(1,i),exp_minus_omega(i,:));            

                E_temp = B_E;

            end 

            for i = 1:s

                if c(i)  ~=0 

                    E_f(mode_range)          = E_f(mode_range) + dt*c(i).*d(i,mode_range);

                end
                if c_lower(i)  ~= 0 

                    E_f_lower(mode_range)    = E_f_lower(mode_range) + dt*c_lower(i).*d(i,mode_range);

                end
            end    

           E_f(mode_range) = shift_back(mode_range).*E_f(mode_range); 
           E_f_lower(mode_range) = shift_back(mode_range).*E_f_lower(mode_range);

           [dt,~,Err_0] = dt_eval(B_E(mode_range),E_f_lower(mode_range),E_f(mode_range),dt,Err_abs,1E-2,N);
           
      end
      function [dt,In_Err,Err_0] = dt_eval(B_E,B_dydx_4,B_dydx_5,dt,Err_abs,Err_rel,N)
          
            q = 4;
            Delta_R_B           = abs( B_dydx_4 - B_dydx_5);
            sc                  = Err_abs + max(abs(B_E),abs(B_dydx_5))*Err_rel;
 
     %       Delta_R_B           = [real( B_dydx_4) - real(B_dydx_5),imag( B_dydx_4) - imag(B_dydx_5)];
      %      sc                  = Err_abs + [max(real(B_E),real(B_dydx_5)),max(imag(B_E),imag(B_dydx_5))]*Err_rel;
            
            err_or              = min(sc./Delta_R_B);%sqrt( 1/N*sum( (Delta_R_B./sc).^2 )  );
            fac                 = 0.25;%0.38^( 1/( q + 1) );
            facmax              = 1.2;
            facmin              = 0.0001;
            dt_new              = dt*min(facmax,max(facmin, fac*err_or) );
            inc                 =  1.1;
            
             if dt_new > inc*dt
                 
                dt = dt_new;
                Err_0 = 1;
                In_Err = 0;
                [exp_plus_omega,exp_minus_omega,shift_back,g_delta] = Define_Shifts(exp_plus_omega,exp_minus_omega,shift_back,g_delta,mask,omega_j,a,dt,Omega_laser,s,N,mode_range);
                
             end 
             
             if  (inc*dt >= dt_new) && (dt_new >= dt)
                 
                Err_0 = 1;
                In_Err = 0;
                dt = dt;
                
             end
             
             if  dt > dt_new
                 
                dt     = dt_new;
                Err_0  = 0;
                In_Err = 1;
                
               [exp_plus_omega,exp_minus_omega,shift_back,g_delta] = Define_Shifts(exp_plus_omega,exp_minus_omega,shift_back,g_delta,mask,omega_j,a,dt,Omega_laser,s,N,mode_range);

             end
          end
       
end    
   
 
    function k_e = Equation_with_Cubic(E_j,g,exp_plus_omega,g_delta,exp_minus_omega)
        
         E_j(mode_range)     =   exp_minus_omega(mode_range).*E_j(mode_range);
         E_0                 =   ifft(E_j)*N; %
         
         F_E_0_3             =   fft(3*abs( E_0 ).^2.*E_0)/N;%
                
         Pump_term(1)        =    Pump(1).*g.*g_delta;        
         
         k_z(mode_range)     =  exp_plus_omega(mode_range).*(- kappa(mode_range)./2.*E_j(mode_range) +  Pump_term(mode_range) + 1i*gamma_cubic.*F_E_0_3(mode_range)); 
         k_e                 =  k_z;
         

    end    
end
function [exp_plus_omega,exp_minus_omega,shift_back,g_delta] = Define_Shifts(exp_plus_omega,exp_minus_omega,shift_back,g_delta,mask,omega_j,a,dt,Omega_laser,s,N,mode_range)

    for i1 = 1:s

        exp_plus_omega(i1,mode_range)  = exp(1i*omega_j(mode_range)*a(i1)*dt);%
        exp_minus_omega(i1,mode_range) = exp(-1i*omega_j(mode_range)*a(i1)*dt);%tt.*
        g_delta(i1,:)                  = exp(1i*Omega_laser*a(i1)*dt);

    end    
    
    shift_back(mode_range) = exp(-1i*omega_j(mode_range)*dt);

end
