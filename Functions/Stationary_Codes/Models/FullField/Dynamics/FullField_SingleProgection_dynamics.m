function Sol = FullField_SingleProgection_dynamics(Temp,Runge)   
    
    d            =  complex(zeros(Runge.s,Temp.Space.N));
    [nt,dt]      =                        ParSim(Temp.Par);
    N            = Temp.Space.N; 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    G_theta                             = cos(Temp.Space.phi*Temp.Eq.g);%+exp(-1i*Temp.Space.phi*Temp.Eq.g);
    NN = Temp.Space.N;
    g = abs(Temp.Eq.g);
    phi = 2*pi/NN*[0:NN-1];
    beta = 4;
    alpha = pi/g/2;
    G   = zeros(1,NN);
    for i = 1:g+1
        mu =  2*pi/g*(i-1);
        G = G + beta/(2*alpha*gamma(1/beta)).*exp(-(abs(phi-mu)/alpha).^beta);
        mu =    pi/g + 2*pi/g*(i-1);
        G = G - beta/(2*alpha*gamma(1/beta)).*exp(-(abs(phi-mu)/alpha).^beta);
    end
    G_theta = G/max(abs(G));
%    G_theta                             = cos(Temp.Space.phi*Temp.Eq.g);%+exp(-1i*Temp.Space.phi*Temp.Eq.g);
    
    GG_theta                             = cos(2*pi/2^11*[0:2^11-1]*Temp.Eq.g);%+exp(-1i*Temp.Space.phi*Temp.Eq.g);
    Eq.L                                = complex(zeros(1,Temp.Space.N/2));
    Eq.L(Temp.Eq.mode_range)            = Temp.Eq.omega;%-1i*1/2*Temp.Eq.kappa;
    
    exp_minus_omega                     = complex(zeros(size(Runge.a,2),size(Eq.L,2)));
    exp_plus_omega                      = complex(zeros(size(Runge.a,2),size(Eq.L,2)));
    pump_phase_substep                  = complex(zeros(size(Runge.a,2),1));
    k_zero                              = complex(zeros(2,Temp.Space.N));

    m                                   = 0:Temp.In.N-1;
    ind_pump = find(m == Temp.In.Pump.m_p);


    shift_back = exp(-1i*Eq.L*dt); 
%    mask  = zeros(1,N);
 %   mask(m == Temp.In.Pump.m_p) = 1;
  %  mask(m == 2*Temp.In.Pump.m_p) = 1;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    F_e        = complex(Temp.In.Psi_Start);
    Field      = zeros(1,Temp.Space.N);
    t_zero          = Temp.In.t_start;
    

    Sol.Psi = complex(zeros(Temp.Par.dd,length(Temp.Eq.mode_range)));
%    Sol.Psie = complex(zeros(Temp.Par.dd,Temp.Space.N));
    
    Sol.t           = complex(zeros(1,Temp.Par.dd));
    Sol.PsiReal     = complex(zeros(1,round(nt)));
%    NRF        = round(1/dt/10);
%    F_Intermid = complex(zeros(NRF,size(Temp.Eq.mode_range,2)));
%    nii = 0;
 %   phase_pump       = complex(0);

    for i = 1:size(Runge.a,2)

        exp_minus_omega(i,:)    = exp(- 1i*Eq.L*(Runge.a(i)*dt));
        exp_plus_omega (i,:)    = exp(  1i*Eq.L*(Runge.a(i)*dt));
        pump_phase_substep(i)   = exp( -1i*Temp.Eq.Pump.omega_p*(t_zero +Runge.a(i)*dt));
   %     pump_phase_substep (i)    = exp(  1i*Eq.L(ind_pump)*(t_zero +Runge.a(i)*dt)).*exp( -1i*Temp.Eq.Pump.omega_p*(t_zero +Runge.a(i)*dt));
  %      pump_phase_substep(i)   = exp( 1i*Temp.Eq.Pump.delta*(t_zero +Runge.a(i)*dt));
        
    end
%    NFSr = floor(Temp.Eq.omega/Temp.Eq.Pump.D1);
    fftw('dwisdom',[]);
    fftw('planner','measure');
    Runge_Kuarong_step(F_e,dt, exp(-1i*Temp.Eq.Pump.omega_p*(t_zero)),d,k_zero);
    fftinfo = fftw('dwisdom');
    fftw('dwisdom',fftinfo);
%    mode_cut  = zeros(1,1024);
%    mode_cut(185)  =  1;
%  mode_cut(326)  =  1;
%    mode_cut(412)  =  1;

    

    for ni = 0:nt-1
        
        
        phase_pump       = exp(-1i*Temp.Eq.Pump.omega_p*( ni*dt));
 %       phase_pump       = exp(1i*Temp.Eq.Pump.delta*( ni*dt));
        F_e              = Runge_Kuarong_step(F_e,dt,phase_pump,d,k_zero);%,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back
        Field =  Get_Field(N/2,F_e);
        Sol.PsiReal(ni+1)     = Field(1);       
%        nii = nii +1;
        
%        F_Intermid(nii,:) = F_e(Temp.Eq.mode_range);

%        if mod(ni,NRF) == 0

%            nii = 0;

%        end
        
        if ( mod(ni,Temp.Par.s_t/Temp.Par.dt) == 0) 
        
            ind_s                = round(ni*Temp.Par.dt/Temp.Par.s_t)+1;
            
            Sol.Psi(ind_s ,:) = F_e(Temp.Eq.mode_range);
%            Sol.Psie(ind_s ,:) = F_e(Temp.Space.N+1:2*Temp.Space.N)/Temp.Space.N;
            
            Sol.t(  ind_s )   = t_zero+Temp.Par.dt*(ni+1);

%            if 10*log10(sum(abs(Sol.Psio(ind_s,2:end)).^2)) <= -100 && (mod(ind_s,2) == 0)

 %                   Sol.Psio(ind_s+1:end,:) = [];
  %                  Sol.Psie(ind_s+1:end,:) = [];
   %                 Sol.t(ind_s+1:end)     = [];                
    %                break;

     %       end
        
        end
       
    end
            Sol.Psi(end ,:) = F_e(Temp.Eq.mode_range);
            Sol.t(  end )   = t_zero+Temp.Par.dt*(ni+1);
    
    Sol.G   = G_theta;

%    Sol.Pric = F_Intermid; 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
     function     E_f    =    Runge_Kuarong_step(B_E,dt,pump_phase,d,k_zero)
         
        E_f    =   B_E;    
        E_temp =   B_E;
        
        d(1,:) =   Chi_3_LLE_Kuar_ins(E_temp,exp_plus_omega(1,:),exp_minus_omega(1,:),pump_phase_substep(1,:),Temp.Eq,k_zero,pump_phase);
        
        for i2 = 2:Runge.s

            for ii = 1:(Runge.s-1)

                if Runge.b(i2,ii) ~= 0

                    E_temp(Temp.Eq.mode_range)      = E_temp(Temp.Eq.mode_range) + dt*Runge.b(i2,ii).*d(ii,Temp.Eq.mode_range);

                end

            end
            
            d(i2,:) =   Chi_3_LLE_Kuar_ins(E_temp,exp_plus_omega(i2,:),exp_minus_omega(i2,:),pump_phase_substep(i2,:),Temp.Eq,k_zero,pump_phase);            
            
            E_temp = B_E;
            
         end 

        for i3 = 1:Runge.s

            if  Runge.c(i3)  ~= 0 

                E_f(Temp.Eq.mode_range)    = E_f(Temp.Eq.mode_range) + dt*Runge.c(i3).*d(i3,Temp.Eq.mode_range);

            end

        end    
        
           E_f(Temp.Eq.mode_range) = E_f(Temp.Eq.mode_range).*shift_back(Temp.Eq.mode_range);
    end    
    function k_e = Chi_3_LLE_Kuar_ins(B_Psi,Fac_plus,Fac_minus,pump_phase_substep,Eq,k_zero,pump_phase)     
         
         
        k_e                 = complex(zeros(1,N));    
        k_e(Eq.mode_range)  = -1/2.*Temp.Eq.kappa.*B_Psi(Eq.mode_range);
        B_Psi(Eq.mode_range)= Fac_minus(Eq.mode_range).*B_Psi(Eq.mode_range);
    
        Field         = Get_Field(N/2,B_Psi);
    %    GField        = ifft(B_Psi)*N/2;
    %    B_Psi    
    %    E_1  = B_Psi(185).*exp(1i*Temp.Space.phi*m(185));
    %    E_2  = B_Psi(185).*exp(1i*Temp.Space.phi*m(185));
        k_zero(1,:)   = fft(G_theta.*Field.^2)/N;
    %    exp(1i*Temp.Space.phi*411)*B_Psi(412) + exp(1i*Temp.Space.phi*411)*B_Psi(412)
    %    k_zero(1,:)   = fft(G_theta.*(E_1.^2+E_2.*E_1)/N;%Field.^2
     %   k_zero(1,1:2048)   = fft(GG_theta.*( GField.^2 + GField.*conj(GField)))/N*2;
    %    k_zero(1,185) = 1/2*B_Psi(412).*conj(B_Psi(185))+1/2*B_Psi(326).*conj(B_Psi(185));
     %   k_zero(1,326) = 1/2*B_Psi(185).^2;
      %  k_zero(1,412) = 1/2*B_Psi(185).^2;
     %  mode_cut(Eq.mode_range).*  
        k_zero(2,:)   = fft(Field.^3)/N;
        %mode_cut(Eq.mode_range).*
        %mode_cut(Eq.mode_range).*
        k_e(Eq.mode_range)   = k_e(Eq.mode_range)+Fac_plus(Eq.mode_range).*...
            (1i*Eq.gamma2.*k_zero(1,Eq.mode_range)+ 1i*Eq.gamma3.*k_zero(2,Eq.mode_range));
    %    k_e                = k_e - 1/2*Eq.kappa.*B_Psi;
    % Fac_plus(Eq.Pump.ind_pump).*
    %-Fac_minus(Eq.Pump.ind_pump).*1/2*Eq.kappa(Eq.Pump.ind_pump).*B_Psi(Eq.Pump.ind_pump)
    
        k_e(ind_pump)    = k_e(ind_pump)+ Fac_plus(ind_pump).*1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1).*pump_phase_substep*pump_phase;
    %    k_e(ind_pump)    = k_e(ind_pump) + 1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1).*pump_phase_substep*pump_phase;
    %    k_e(ind_pump)    = k_e(ind_pump) + Fac_plus(ind_pump).*1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1).*pump_phase_substep*pump_phase;
    %    k_e(ind_pump)    = k_e(ind_pump)+ 1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1).*exp(1i*Temp.Eq.Pump.delta*t);
    %    k_e(ind_pump)    = k_e(ind_pump)+ 1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1)*pump_phase_substep*pump_phase;
    
    %Fac_plus(Eq.Pump.ind_pump).*Fac_plus(Eq.Pump.ind_pump).* Fac_minus(Eq.Pump.ind_pump).*
        
    end  
function Field = Get_Field(N,F_e)

   F_e_shifted         =   complex(zeros(1,N));
%   F_e_shifted(2:N)    =   conj(F_e(N:-1:2));
   F_e_shifted(2:N)    =   flip(conj(F_e(2:N)));

   Field               =   ifft([F_e,F_e_shifted]*2*N);

end
            
    end

function     [nt,dt,dd] = ParSim(Par)

    dt = Par.dt;
    nt = Par.T/Par.dt;
    dd = int32(floor(Par.T/Par.s_t));  
    
end
