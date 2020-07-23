function [F_s,Q_s,t_s] = Runge_Kuarong_Raman(F_e,Q,Z,gamma_3,Pump,L,dt,nt,NN,Loops,per_loop,N,Runge,Delta,mu_r,omega_0_2,gamma_ramman)
%% Runge-Kutta Coefficicents
           
%%        
    i1      = 1;
    j        = NN;    
    F_s      = zeros(Loops*per_loop,N) + 1i*zeros(Loops*per_loop,N);
    Q_s      = zeros(Loops*per_loop,N) + 1i*zeros(Loops*per_loop,N);
    t_s      = zeros(1,Loops*per_loop);
    F_e      = [F_e,Z,Q];
%% Define Time Steps inside the runge
for i = 1:size(Runge.a,2)
    time_shift_minus(i,:) = exp(-1i*L*Runge.a(i)*dt);  
    time_shift_plus(i,:)  = exp( 1i*L*Runge.a(i)*dt);
end
shift_back = exp(-1i*L*dt); 

    b  = Runge.b;
    c  = Runge.c;
    iter_l = size(b,1);
    iter_2 = size(b,2);
 k_r = zeros(iter_l,3*N);

%%
h = waitbar(0,' Runge 5,%');

    for ni=1:nt  
        
        B  = Runge_Kuarong_Kerr_step(F_e,dt);
        F_e  = B;
        F_e(1:N)  = B(1:N).*shift_back;
        
        if (j == NN)     
            
             F_s(i1,1:N) = F_e(1:N);
             Q_s(i1,1:N) = B(2*N+1:3*N);
             t_s(i1)     = dt*ni;
             i1          = i1+1;
             j           = 0;     
             waitbar(ni/nt,h,strcat(Delta.Physics,Delta.Runge_Type,'|||',sprintf('%.4f',ni/nt*100),'%' ))
             
        end
         
        j=j+1;     
        
    end
close(h)
    function     B_f    =    Runge_Kuarong_Kerr_step(B_E,dt)
        
        B_f      = B_E;    
        
        k_r(1,:)    = dt*Equation_with_Kerr(B_E,time_shift_plus(1,:));

    for i = 2:iter_l
        
        B_E_temp = B_E;
        
        for ii= 1:iter_2
            if b(i,ii) ~=0 
                B_E_temp = B_E_temp + b(i,ii).*k_r(ii,:);
            end
        end
        
        F_temp        = B_E_temp;
        F_temp(1:N)   = B_E_temp(1:N).*time_shift_minus(i,:);        
        k_r(i,:)      = dt*Equation_with_Kerr(F_temp,time_shift_plus(i,:));
        
    end 
    
    for i = 1:iter_l
        if c(i)  ~=0 
            B_f    = B_f + c(i).*k_r(i,:);
        end
    end    
            
    end    
        
    function k = Equation_with_Kerr(F,Fac_plus)
            
            F_Psi = F(1:N);
            R     = F(N+1:2*N);
            Q     = F(2*N+1:3*N);
            Psi         = ifft(F_Psi);
            abs_Psi_2   = abs(Psi).^2;
            
            k_B         = 1i*Fac_plus.*fft( ( 1 - mu_r )*gamma_3*abs_Psi_2.*Psi+Q.*Psi+Pump );
            k_R         = (-gamma_ramman.*R - omega_0_2.*(Q - mu_r*gamma_3*abs_Psi_2 ));
            k_Q         = R;
            k           = [k_B,k_R,k_Q];

    end
    
    end
