function Sol = FullField_SingleProgection_dynamics(Temp,Runge)   

    d            =  complex(zeros(Runge.s,2*Temp.Space.N));
    [nt,dt]      =                        ParSim(Temp.Par);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    exp_minus_omega = complex(zeros(size(Runge.a,2),size(Temp.Eq.L,2)));
    exp_plus_omega  = complex(zeros(size(Runge.a,2),size(Temp.Eq.L,2)));
    
    for i = 1:size(Runge.a,2)

        exp_minus_omega(i,:) = exp(-1i*Temp.Eq.L*Runge.a(i)*dt);
        exp_plus_omega (i,:) = exp( 1i*Temp.Eq.L*Runge.a(i)*dt);

    end

    shift_back = exp(-1i*Temp.Eq.L*dt); 
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    F_e        = complex(Temp.In.Psi_Start);
    t          = Temp.In.t_start;
    
    Sol.Psio = complex(zeros(Temp.Par.dd,Temp.Space.N));
    Sol.Psie = complex(zeros(Temp.Par.dd,Temp.Space.N));
    
    Sol.t    = complex(zeros(1,Temp.Par.dd));

    
    for ni = 1:nt 
        
        F_e           = Runge_Kuarong_step(F_e,dt,t + ni*dt,d);%,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back
        
        if ( mod(ni,Temp.Par.s_t/Temp.Par.dt ) == 0) && (ni ~= 0)
        
            ind_s                = round(ni*Temp.Par.dt/Temp.Par.s_t);
            
            Sol.Psio(ind_s ,:) = F_e(1:Temp.Space.N)/Temp.Space.N;
            Sol.Psie(ind_s ,:) = F_e(Temp.Space.N+1:2*Temp.Space.N)/Temp.Space.N;
            
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
     function     E_f    =    Runge_Kuarong_step(B_E,dt,t,d)
         
        E_f    =   B_E;    
        E_temp =   B_E;
        
        d(1,:) =   Chi_3_LLE_Kuar_ins(E_temp,exp_plus_omega(1,:),exp_minus_omega(1,:),t,Temp.Eq);
        
        for i2 = 2:Runge.s

            for ii = 1:(Runge.s-1)

                if Runge.b(i2,ii) ~= 0

                    E_temp(Temp.Eq.mode_range)      = E_temp(Temp.Eq.mode_range) + dt*Runge.b(i2,ii).*d(ii,Temp.Eq.mode_range);

                end

            end
            
            d(i2,:) =   Chi_3_LLE_Kuar_ins(E_temp,exp_plus_omega(i2,:),exp_minus_omega(i2,:),t,Temp.Eq);            
            
            E_temp = B_E;
            
         end 

        for i3 = 1:Runge.s

            if  Runge.c(i3)  ~= 0 

                E_f(Temp.Eq.mode_range)    = E_f(Temp.Eq.mode_range) + dt*Runge.c(i3).*d(i3,Temp.Eq.mode_range);

            end

        end    
        
           E_f(Temp.Eq.mode_range) = shift_back(Temp.Eq.mode_range).*E_f(Temp.Eq.mode_range); 
    end    
 function k_e = Chi_3_LLE_Kuar_ins(B_Psi,Fac_plus,Fac_minus,t,Eq)     
     
    N       = size(B_Psi,2)/2;
    Field   = Get_Field(N,B_Psi);
    
    k_e         = complex(zeros(1,2*N));    
    k_e                = Fac_plus.*(Eq.gamma2.*fft(G_theta.*Field.^2) + Eq.gamma3.*fft(Field.^3));
    k_e                = k_e - 1/2*Eq.kappa.*B_Psi;

    k_e(Eq.indPump)    = k_e(Eq.indPump) + N*Fac_plus(Eq.indPump).*1/2*Eq.kappa(Eq.indPump)*Eq.H(1);

    
end  
            
    end
function Field = Get_Field(N,F_e)

   F_e_shifted         =   zeros(1,N);
   F_e_shifted(2:N)    =   conj(F_e(N:-1:2));
   Field               =   ifft([F_e,F_e_shifted],'symmetric')*2*N;

end

function     [nt,dt,dd] = ParSim(Par)

    dt = Par.dt;
    nt = Par.T/Par.dt;
    dd = int32(floor(Par.T/Par.s_t));  
    
end
