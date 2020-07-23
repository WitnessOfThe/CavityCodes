function [F_s,t_s] = Runge_Kuarong_Cubic(F_e,gamma_3,Pump,L,dt,nt,NN,Loops,per_loop,N,Runge,Delta,k)
%% Runge-Kutta Coefficicents
           
%%        
    i1      = 1;
    j        = NN;    
    F_s      = zeros(Loops*per_loop,N) + 1i*zeros(Loops*per_loop,N);
    t_s      = zeros(1,Loops*per_loop);
    
%% Define Time Steps inside the runge
for i = 1:size(Runge.a,2)
    
    time_shift_minus(i,:) = exp(-1i*L*Runge.a(i)*dt);
    time_shift_plus (i,:) = exp( 1i*L*Runge.a(i)*dt);
    
end

    shift_back = exp(-1i*L*dt); 

    b      = Runge.b;
    c      = Runge.c;
    
    iter_l = size(b,1);
    iter_2 = size(b,2);
    k_r    = zeros(iter_l,N);

%%
    
%tic
h = waitbar(0,'Raman Adaptive Runge 5,%');
    for ni=1:nt  
        
        B  = Runge_Kuarong_Kerr_step(F_e,dt);
        F_e  = B.*shift_back;
        
        if (j == NN)
            
             t_s(i1)     = dt*ni;
             F_s(i1,1:N) = F_e.*exp(1i*2*pi*t_s(i1).*k) ;
             i1          = i1+1;
             j           = 0;     
             waitbar(ni/nt,h,strcat(Delta.Initial_Guess,Delta.Physics,Delta.Runge_Type,'|||',sprintf('%.4f',ni/nt*100),'%' ))

        end
         
        j=j+1;     
        
    end
    
    close(h)
    
    function     B_f    =    Runge_Kuarong_Kerr_step(B_E,dt)
        
        B_f      =   B_E;    
        B_E_temp =   B_E;
        
        for i = 1:iter_l

            F_temp   =   B_E_temp.*time_shift_minus(i,:);        
            B_E_temp =   B_E;        
            k_r(i,:) =   dt*Equation_with_Kerr(F_temp,time_shift_plus(i,:));

            for ii = 1:iter_2

                if b(i,ii) ~= 0

                    B_E_temp = B_E_temp + b(i,ii).*k_r(ii,:);

                end

            end

        end 

        for i = 1:iter_l

            if c(i)  ~=0 

                B_f    = B_f + c(i).*k_r(i,:);

            end

        end    
            
    end    
        
    function k_e = Equation_with_Kerr(B_j,exp_delta,exp_omega,exp_theta_omega,exp_theta_omega_conj)
        
        E_0              = B_j*exp_theta_omega +  conj(B_j)*exp_theta_omega_conj;
        Nonlinear_term   = 1i*gamma_cubic.*exp_omega.*ifft(E_0)/2/pi;
        Linear_Pump_term = -0.5*kappa*B_j + 0.5*h.*exp_delta;
        k_e              = Linear_Pump_term + Nonlinear_term; 

    end
    
    end
