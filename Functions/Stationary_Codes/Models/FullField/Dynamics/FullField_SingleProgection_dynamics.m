function Sol = FullField_SingleProgection_dynamics(Temp,Runge)   
    
    d            =  complex(zeros(Runge.s,Temp.Space.N));
    [nt,dt]      =                        ParSim(Temp.Par);
    N            = Temp.Space.N; 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    G_theta                             = cos(Temp.Space.phi*Temp.Eq.g);
    Temp.Eq.L                           = complex(zeros(1,Temp.Space.N/2));
    Temp.Eq.L(Temp.Eq.mode_range)       = Temp.Eq.omega - 1i*1/2.*Temp.Eq.kappa;
    exp_minus_omega                     = complex(zeros(size(Runge.a,2),size(Temp.Eq.L,2)));
    exp_plus_omega                      = complex(zeros(size(Runge.a,2),size(Temp.Eq.L,2)));
    k_zero                              = complex(zeros(2,Temp.Space.N));

    m                                                = 0:Temp.In.N-1;
    ind_pump = find(m == Temp.In.Pump.m_p);

    for i = 1:size(Runge.a,2)

        exp_minus_omega(i,:) = exp(-1i*Temp.Eq.L*Runge.a(i)*dt);
        exp_plus_omega (i,:) = exp( 1i*Temp.Eq.L*Runge.a(i)*dt);

    end

    shift_back = exp(-1i*Temp.Eq.L*dt); 
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    F_e        = complex(Temp.In.Psi_Start);
    t          = Temp.In.t_start;
    

    Sol.Psi = complex(zeros(Temp.Par.dd,Temp.Space.N/2));
%    Sol.Psie = complex(zeros(Temp.Par.dd,Temp.Space.N));
    
    Sol.t    = complex(zeros(1,Temp.Par.dd));
    
    for ni = 1:nt 
        
        F_e           = Runge_Kuarong_step(F_e,dt,t + ni*dt,d,k_zero);%,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back
        
        if ( mod(ni,Temp.Par.s_t/Temp.Par.dt ) == 0) && (ni ~= 0)
        
            ind_s                = round(ni*Temp.Par.dt/Temp.Par.s_t);
            
            Sol.Psi(ind_s ,:) = F_e(1:Temp.Space.N/2);
%            Sol.Psie(ind_s ,:) = F_e(Temp.Space.N+1:2*Temp.Space.N)/Temp.Space.N;
            
            Sol.t(  ind_s )   = Temp.Par.dt*ni;

%            if 10*log10(sum(abs(Sol.Psio(ind_s,2:end)).^2)) <= -100 && (mod(ind_s,2) == 0)

 %                   Sol.Psio(ind_s+1:end,:) = [];
  %                  Sol.Psie(ind_s+1:end,:) = [];
   %                 Sol.t(ind_s+1:end)     = [];                
    %                break;

     %       end
        
       end
       
    end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
     function     E_f    =    Runge_Kuarong_step(B_E,dt,t,d,k_zero)
         
        E_f    =   B_E;    
        E_temp =   B_E;
        
        d(1,:) =   Chi_3_LLE_Kuar_ins(E_temp,exp_plus_omega(1,:),exp_minus_omega(1,:),t+Runge.a(1)*dt,Temp.Eq,k_zero);
        
        for i2 = 2:Runge.s

            for ii = 1:(Runge.s-1)

                if Runge.b(i2,ii) ~= 0

                    E_temp(Temp.Eq.mode_range)      = E_temp(Temp.Eq.mode_range) + dt*Runge.b(i2,ii).*d(ii,Temp.Eq.mode_range);

                end

            end
            
            d(i2,:) =   Chi_3_LLE_Kuar_ins(E_temp,exp_plus_omega(i2,:),exp_minus_omega(i2,:),t+Runge.a(i2)*dt,Temp.Eq,k_zero);            
            
            E_temp = B_E;
            
         end 

        for i3 = 1:Runge.s

            if  Runge.c(i3)  ~= 0 

                E_f(Temp.Eq.mode_range)    = E_f(Temp.Eq.mode_range) + dt*Runge.c(i3).*d(i3,Temp.Eq.mode_range);

            end

        end    
        
           E_f(Temp.Eq.mode_range) = E_f(Temp.Eq.mode_range).*shift_back(Temp.Eq.mode_range);
    end    
 function k_e = Chi_3_LLE_Kuar_ins(B_Psi,Fac_plus,Fac_minus,t,Eq,k_zero)     
     
    k_e                 = complex(zeros(1,N));    
    B_Psi(Eq.mode_range)= Fac_minus(Eq.mode_range).*B_Psi(Eq.mode_range);
 %   k_e(Eq.mode_range)  = -Fac_plus(Eq.mode_range).*1/2.*Temp.Eq.kappa.*B_Psi(Eq.mode_range);
    Field         = Get_Field(N/2,B_Psi);
    k_zero(1,:)   = fft(G_theta.*Field.^2)/N;
    k_zero(2,:)   = fft(Field.^3)/N;
    
    k_e(Eq.mode_range)   = Fac_plus(Eq.mode_range).*(1i*Eq.gamma2.*k_zero(1,Eq.mode_range)+ 1i*Eq.gamma3.*k_zero(2,Eq.mode_range));
%    k_e                = k_e - 1/2*Eq.kappa.*B_Psi;
% Fac_plus(Eq.Pump.ind_pump).*
%-Fac_minus(Eq.Pump.ind_pump).*1/2*Eq.kappa(Eq.Pump.ind_pump).*B_Psi(Eq.Pump.ind_pump)
    k_e(ind_pump)    = k_e(ind_pump)+ Fac_plus(ind_pump).*(1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1).*exp(-1i*Temp.Eq.Pump.omega_p*t));%.*exp(-1i*Temp.Eq.Pump.omega_p*t));%
%Fac_plus(Eq.Pump.ind_pump).*Fac_plus(Eq.Pump.ind_pump).* Fac_minus(Eq.Pump.ind_pump).*
    
end  
            
    end
function Field = Get_Field(N,F_e)

   F_e_shifted         =   zeros(1,N);
%   F_e_shifted(2:N)    =   conj(F_e(N:-1:2));
   F_e_shifted(2:N)    =   flip(conj(F_e(2:N)));

   Field               =   ifft([F_e,F_e_shifted]*2*N,'symmetric');

end

function     [nt,dt,dd] = ParSim(Par)

    dt = Par.dt;
    nt = Par.T/Par.dt;
    dd = int32(floor(Par.T/Par.s_t));  
    
end
