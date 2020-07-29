function Temporal = Split_chi_2(Psi_o_0,Psi_e_0,gamma_o,gamma_e,Pump,Pump_probe,mu_p,L_o,L_e,dt,nt,NN,Loops,per_loop,N,Runge,Delta,range_0,k,omega_prob,kappa_o,kappa_e)
%% Runge-Kutta Coefficicents
    
    b      = Runge.b;
    c      = Runge.c;
    a      = Runge.a;
    
    s      = size(b,1); 
    d      = zeros(s,2*N);
    
%%
    Psi        = [Psi_o_0,Psi_e_0];

%%        
    phi = linspace(-pi,pi,N);
    exp_probe = exp(1i*phi*mu_p);
    i1      = 1;
    i2      = 1;
    j       = NN;    
    
    Psi_o_s      = zeros(Loops*per_loop,size(1:2*N,2)/2) + 1i*zeros(Loops*per_loop,size(1:2*N,2)/2);
    Psi_e_s      = zeros(Loops*per_loop,size(1:2*N,2)/2) + 1i*zeros(Loops*per_loop,size(1:2*N,2)/2);
    
  %  U_m          = zeros(4,nt);
 %   index_m      = [abs(mu_p)+1,N-abs(mu_p)+1,abs(mu_p)+1+N,N-abs(mu_p)+1+N];
    t_s      = zeros(1,Loops*per_loop);
    
    
%% Define Time Steps inside the runge

    k_o        = zeros(1,N); 
    k_e        = zeros(1,N); 
    
    Nonlin_o   = zeros(1,N); 
    Nonlin_e   = zeros(1,N); 
    
        
        h = waitbar(0,'\chi_2,%');
        
%%
    
    for ni = 1:nt  

        Psi(1:N)    = ifft(exp( -1i*dt/2.*(L_o(1:N) ) ) .*fft(Psi(1:N))) ;
        Psi(N+1:2*N)  = ifft(exp( -1i*dt/2.*(L_e(1:N) ) ) .*fft(Psi(N+1:2*N))) ;

        Psi  = Runge_Kuarong_Kerr_step(Psi,dt,ni*dt);
        
        Psi(1:N)    = ifft(exp( -1i*dt/2.*(L_o(1:N) ) ) .*fft(Psi(1:N))) ;
        Psi(N+1:2*N)  = ifft(exp( -1i*dt/2.*(L_e(1:N) ) ) .*fft(Psi(N+1:2*N))) ;
        
%        U_m(:,ni) = Psi(index_m);
        
        if  j == NN
            
            [Psi_o_s,Psi_e_s,t_s] = Save_data(Psi_o_s,Psi_e_s,t_s,Psi,ni,i1,dt,1:N,nt,h,Delta,N);
            i1 = i1 + 1;        
            j = 0;
            
        end
        
        j=j+1;     
        
    end

    Temporal.t           = t_s;
%    Temporal.l_s         = l_s;
%    Temporal.U_m         = U_m;
    Temporal.Psi_o       = Psi_o_s;
    Temporal.Psi_e       = Psi_e_s;
    
    close(h)
    
    function     E_f    =    Runge_Kuarong_Kerr_step(B_E,dt,t)
         
        E_f    =   B_E;    
        E_temp =   B_E;
        
        d(1,:) =   Equation_Second_Harmonic(E_f,t+a(1)*dt);
        
        for i = 2:s

            for ii = 1:s-1

                if b(i,ii) ~= 0

                    E_temp(1:2*N) = E_temp(1:2*N) + dt*b(i,ii).*d(ii,1:2*N);

                end

            end
            
            d(i,:) =   Equation_Second_Harmonic( E_temp,t+a(i)*dt);            
            
            E_temp = B_E;
            
         end 

        for i = 1:s

            if c(i)  ~=0 

                E_f(1:2*N)    = E_f(1:2*N) + dt*c(i).*d(i,1:2*N);

            end

        end    
        
%           E_f(1:2*N) = shift_back(1:2*N).*E_f(1:2*N); 
    end    
        
    function k = Equation_Second_Harmonic(B,t)

        B_o =B(1:N); 
        B_e =B(N+1:2*N); 
        
        
        
        Nonlin_o      = (B_e.*conj(B_o));                                                                                                                                             
        Nonlin_e      =  B_o.^2 ;
        
        k_o(1:N)         = -1i.*(- gamma_o.*Nonlin_o(1:N) + Pump(1) + Pump_probe.*exp_probe.*exp(-1i*omega_prob*t)); 
        k_e(1:N)         = -1i.*(- gamma_e.*Nonlin_e(1:N)); 
        
%        k_o(mu_p+1)      =  k_o(mu_p+1) - 1i*omega_o_p(mu_p+1).*(1i*Pump_probe(1)*N.*exp(-1i*omega_prob*t));
        
        k           = [k_o,k_e];
        
    end
    
end

function [Psi_o_s,Psi_e_s,t_s] = Save_data(Psi_o_s,Psi_e_s,t_s,Psi,ni,i1,dt,range_o,nt,h,Delta,N)

     t_s(i1)     = dt*ni;
     ni/nt
     Psi_o_s(i1,:)   = Psi(1:N);
     Psi_e_s(i1,:)   = Psi(N+1:2*N);

     waitbar(ni/nt,h,strcat(Delta.Initial_Guess,Delta.Physics,Delta.Runge_Type,'|||',sprintf('%.4f',ni/nt*100),'%' ))

end

