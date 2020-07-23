function Temporal = Runge_Kuarong_Kerr(F_e,gamma_3,Pump,L,dt,nt,NN,Loops,per_loop,N,Runge,Delta,mode_range,l,D1_norm,ind_pump,omega_j)    
%% Runge-Kutta Coefficicents

    b      = Runge.b;
    c      = Runge.c;
    a      = Runge.a;
    s      = size(b,1); 
    d      = zeros(s,N);

%%        

    i1      = 1;
    i2      = 1;
    j       = NN;    
    
    F_s      = zeros(Loops*per_loop,size(mode_range,2)) + 1i*zeros(Loops*per_loop,size(mode_range,2));
    t_s      = zeros(1,Loops*per_loop);
    
%% Define Time Steps inside the runge

    for i = 1:size(Runge.a,2)

        exp_minus_omega(i,:) = exp(-1i*L*Runge.a(i)*dt);
        exp_plus_omega (i,:) = exp( 1i*L*Runge.a(i)*dt);

    end

    shift_back = exp(-1i*L*dt); 
        
    h = waitbar(0,'Raman Adaptive Runge 5,%');
    
%%
    N_t                 = 2^15;
    
%    U_max               = zeros(1,round(nt));
    
%    omega_max_vector    = zeros(round(nt/N_t),size(mode_range,2)); 
 %   Amplitude           = zeros(round(nt/N_t),size(mode_range,2)); 
  %  t_t                 = zeros(1,round(nt/N_t));
   % F_e_t               = zeros(N_t,size(mode_range,2));
    
%    omega_t  = -[0:N_t/2-1,-N_t/2:-1]*2*pi/(N_t*dt);
    
    k = [0:N/2 - 1, -N/2:-1];
    
%    for i = 1:size(mode_range,2)
 %       
  %      omega_t_j_matrix(1:N_t,i)         =   omega_t + l(mode_range(i))*D1_norm;%;% ; % 
   %     
    %end
    
    phi = ([0:N-1] - N/2)*2*pi/N;
    
%%
%    l_m                 = [50,100,150,200,250,300,350,400,341];
    
%     for i = 1:size(l_m,2)
% 
%         indexes(i) =  mode_range( l(mode_range) == l_m(i));
%         
%     end

    
%    U_m                 = zeros(round(nt),size(l_m,2));

%%

    for ni=1:nt  
        
        F_e  = Runge_Kuarong_Kerr_step(F_e,dt);
        
        
        if  j == NN
            
            [F_s,t_s] = Save_data(F_s,t_s,F_e,ni,i1,dt,mode_range,nt,h,Delta);
            i1 = i1 + 1;        
            j = 0;
            
        end
        
%        F_e_t(mod((ni-1),N_t) + 1,:) = F_e(mode_range);%
        
%        if mod(ni,N_t) == 0                

 %           [Amplitude(i2,:),omega_max_vector(i2,:)] =  Get_Real_Spectrum(F_e_t,omega_t_j_matrix,k,D1_norm,omega_j,mode_range);
  %          t_t(i2)                                  =   ni*dt;
   %         i2                                       =  i2 + 1;

    %    end
        
        E_0         = Get_Electric_Field(F_e,ind_pump,ni*dt,omega_j,phi,mode_range,D1_norm,k,L);
%        U_max(ni)   = max(E_0);
%        U_m(ni,:)   =  F_e(indexes);
        
%        U_m(ni)     = F_s(ind_m);
%        U_2m(ni)    = F_s(ind_2m);
         
        j=j+1;     
        
    end

  %  Temporal.t_abs       = [1:nt]*dt;
  %  Temporal.t_t         = t_t;
    Temporal.t           = t_s;
 %   Temporal.U_max       = U_max;
%    Temporal.U_m         = U_m;
 %   Temporal.l_s         = l_m;
    Temporal.E_s         = F_s;
  %  Temporal.omega_max   = omega_max_vector;
 %   Temporal.E_t         = Amplitude;
    
    close(h)
    
    function     E_f    =    Runge_Kuarong_Kerr_step(B_E,dt)
         
        E_f    =   B_E;    
        E_temp =   B_E;
        
        d(1,:) =   Equation_with_Kerr(E_temp,exp_plus_omega(1,:),exp_minus_omega(1,:));
        
        for i = 2:s

            for ii = 1:s-1

                if b(i,ii) ~= 0

                    E_temp(mode_range) = E_temp(mode_range) + dt*b(i,ii).*d(ii,mode_range);

                end

            end
            
            d(i,:) =   Equation_with_Kerr(E_temp,exp_plus_omega(i,:),exp_minus_omega(i,:));            
            
            E_temp = B_E;
            
         end 

        for i = 1:s

            if c(i)  ~=0 

                E_f(mode_range)    = E_f(mode_range) + dt*c(i).*d(i,mode_range);

            end

        end    
        
           E_f(mode_range) = shift_back(mode_range).*E_f(mode_range); 
    end    
        
    function k_e = Equation_with_Kerr(F_Psi,Fac_plus,Fac_minus)

        Psi         =                                   ifft(F_Psi.*Fac_minus);
        
        abs_Psi_2   =                                   abs(Psi).^2;
        k_e         = 1i*Fac_plus.*( gamma_3.*fft(abs_Psi_2.*Psi )); 
        k_e(1)         =  k_e(1) + 1i*Fac_plus(1).*(N*Pump(1));
        
    end
    
end
function [Amplitude,omega_max_vector] = Get_Real_Spectrum(F_e_t,omega_t_j_matrix,k,D1_norm,omega_j,mode_range)
    
        omega_f_e_t               = fft(F_e_t,[],1)*size(F_e_t,1);    
        [Amplitude,ind_vector]    = max(omega_f_e_t,[],1);
        omega_max_vector          = zeros(1,size(omega_f_e_t,2));
     
    for i = 1:size(omega_f_e_t,2)
        
        omega_max_vector(i)          = omega_t_j_matrix(ind_vector(i),i) + ...
            k(mode_range(i))*D1_norm + omega_j(1);
        
    end
    
end

function [F_s,t_s] = Save_data(F_s,t_s,F_e,ni,i1,dt,mode_range,nt,h,Delta)

     t_s(i1)     = dt*ni;
     ni/nt
     F_s(i1,:)   = F_e(mode_range);

     waitbar(ni/nt,h,strcat(Delta.Initial_Guess,Delta.Physics,Delta.Runge_Type,'|||',sprintf('%.4f',ni/nt*100),'%' ))

end

function E_0 = Get_Electric_Field(F_e,ind_m_p,t,omega_j,phi,mode_range,D1_norm,k,L)
    
    m_p        = ind_m_p  - 1; 
    omega_j(mode_range) = omega_j(1)  + k(mode_range)*D1_norm ;
    psi_full    = F_e;
    psi_full(mode_range)    = F_e(mode_range).*exp(-1i*t*omega_j(mode_range));
    
    B                      = exp(1i*m_p*phi).*ifft(psi_full);
    
    E_0        = B + conj(B);
    
end


