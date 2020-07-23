function Temporal = Runge_Kuarong_chi_2(Psi_o_0,Psi_e_0,gamma_o,gamma_e,Pump,Pump_probe,mu_p,L_o,L_e,dt,nt,NN,Loops,per_loop,N,Runge,Delta,range_o,k,omega_prob,kappa_o,kappa_e)
%% Runge-Kutta Coefficicents
    
    b      = Runge.b;
    c      = Runge.c;
    a      = Runge.a;
    
    s      = size(b,1); 
    d      = zeros(s,2*N);
    
%%
    range_e    = 1:N;
    mode_range = 1:(2*N);
    Psi        = [Psi_o_0,Psi_e_0];

%%        

    i1      = 1;
    i2      = 1;
    j       = NN;    
    
    Psi_o_s      = zeros(Loops*per_loop,size(mode_range,2)/2) + 1i*zeros(Loops*per_loop,size(mode_range,2)/2);
    Psi_e_s      = zeros(Loops*per_loop,size(mode_range,2)/2) + 1i*zeros(Loops*per_loop,size(mode_range,2)/2);
    
    U_m          = zeros(4,nt);
    index_m      = [mu_p+1,N-mu_p+1,mu_p+1+N,N-mu_p+1+N];
    t_s      = zeros(1,Loops*per_loop);
    
    
%% Define Time Steps inside the runge

    k_o        = zeros(1,N); 
    k_e        = zeros(1,N); 
    E_o        = zeros(1,N); 
    E_e        = zeros(1,N); 
    
    Nonlin_o   = zeros(1,N); 
    Nonlin_e   = zeros(1,N); 
    
    omega_o_p  = zeros(size(Runge.a,2),N);
    omega_e_p  = zeros(size(Runge.a,2),N);
    omega_o_m  = zeros(size(Runge.a,2),N);
    omega_e_m  = zeros(size(Runge.a,2),N);
    
    shift_back = zeros(1,2*N);
    
    for i = 1:size(Runge.a,2)
        
        omega_o_p(i,range_o) =  exp(1i*(L_o(range_o))*Runge.a(i)*dt);
        
        omega_e_p(i,range_e) =  exp(1i*(L_e(range_e))*Runge.a(i)*dt);
        
        omega_o_m(i,range_o) =  exp(-1i*(L_o(range_o))*Runge.a(i)*dt);
        
        omega_e_m(i,range_e) =  exp(-1i*(L_e(range_e))*Runge.a(i)*dt);

    end

        shift_back(mode_range) = exp(-1i*([L_o(range_o),L_e(range_e)])*dt); 
        
        h = waitbar(0,'\chi_2,%');
        
%%
    
    for ni = 1:nt  
        
        Psi  = Runge_Kuarong_Kerr_step(Psi,dt,ni*dt);
        
        U_m(:,ni) = Psi(index_m);
        
        if  j == NN
            
            [Psi_o_s,Psi_e_s,t_s] = Save_data(Psi_o_s,Psi_e_s,t_s,Psi,ni,i1,dt,range_o,nt,h,Delta,N);
            i1 = i1 + 1;        
            j = 0;
            
        end
        
        j=j+1;     
        
    end

    Temporal.t           = t_s;
%    Temporal.l_s         = l_s;
    Temporal.U_m         = U_m;
    Temporal.Psi_o       = Psi_o_s;
    Temporal.Psi_e       = Psi_e_s;
    
    close(h)
    
    function     E_f    =    Runge_Kuarong_Kerr_step(B_E,dt,t)
         
        E_f    =   B_E;    
        E_temp =   B_E;
        
        d(1,:) =   Equation_Second_Harmonic(E_f,omega_o_p(1,:),omega_e_p(1,:),omega_o_m(1,:),omega_e_m(1,:),t+a(1)*dt);
        
        for i = 2:s

            for ii = 1:s-1

                if b(i,ii) ~= 0

                    E_temp(mode_range) = E_temp(mode_range) + dt*b(i,ii).*d(ii,mode_range);

                end

            end
            
            d(i,:) =   Equation_Second_Harmonic( E_temp,omega_o_p(i,:),omega_e_p(i,:),omega_o_m(i,:),omega_e_m(i,:),t+a(i)*dt);            
            
            E_temp = B_E;
            
         end 

        for i = 1:s

            if c(i)  ~=0 

                E_f(mode_range)    = E_f(mode_range) + dt*c(i).*d(i,mode_range);

            end

        end    
        
           E_f(mode_range) = shift_back(mode_range).*E_f(mode_range); 
    end    
        
    function k = Equation_Second_Harmonic(B,omega_o_p,omega_e_p,omega_o_m,omega_e_m,t)

        B_o =B(1:N); 
        B_e =B(N+1:2*N); 
        
        E_o(range_o) = B_o(range_o).*omega_o_m(range_o);
        E_e(range_e) = B_e(range_e).*omega_e_m(range_e);
        
        Psi_o         = ifft(E_o);
        Psi_e         = ifft(E_e); 
        
        
        Nonlin_o      = fft( 1i*Psi_e.*conj(Psi_o)  + Pump(1)/gamma_o);
        Nonlin_e      = fft( 1i*Psi_o.^2 );
        %-1i*kappa_o.*E_o(range_o)
        k_o(range_o)         = omega_o_p(range_o).*(gamma_o.*Nonlin_o(range_o)); 
        k_e(range_e)         = omega_e_p(range_e).*(gamma_e.*Nonlin_e(range_e)); 
        
%        k_o(mu_p+1)      =  k_o(mu_p+1) - 1i*omega_o_p(mu_p+1).*(1i*Pump_probe(1)*N.*exp(-1i*omega_prob*t));
        
        k           = [k_o,k_e];
        
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

function [Psi_o_s,Psi_e_s,t_s] = Save_data(Psi_o_s,Psi_e_s,t_s,Psi,ni,i1,dt,range_o,nt,h,Delta,N)

     t_s(i1)     = dt*ni;
     ni/nt
     Psi_o_s(i1,:)   = Psi(range_o);
     Psi_e_s(i1,:)   = Psi(range_o+N);

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


