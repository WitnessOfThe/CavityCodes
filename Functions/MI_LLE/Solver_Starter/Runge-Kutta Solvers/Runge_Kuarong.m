    function Res = Runge_Kuarong(Res,N_modes)   

    Res.Temp     =    Res.Temp.Met.Norm(Res.Temp,N_modes);        
    Res          =    Res.Temp.Met.Ev_Start_Point(Res);
    Runge        =               Define_Runge_Coeff(Res.Temp.Par);
    d            =  zeros(Runge.s,size( Res.Temp.In.Psi_Start,2));
    [nt,dt]      =                           ParSim(Res.Temp.Par);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    exp_minus_omega = complex(zeros(size(Runge.a,2),size(Res.Temp.Eq.L,2)));
    exp_plus_omega  = complex(zeros(size(Runge.a,2),size(Res.Temp.Eq.L,2)));
    
    for i = 1:size(Runge.a,2)

        exp_minus_omega(i,:) = exp(-1i*Res.Temp.Eq.L*Runge.a(i)*dt);
        exp_plus_omega (i,:) = exp( 1i*Res.Temp.Eq.L*Runge.a(i)*dt);

    end

    shift_back = exp(-1i*Res.Temp.Eq.L*dt); 
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    Res.Temp       = Res.Temp.Met.Ev_Save(0,Res.Temp,0); 
    
    F_e        = Res.Temp.In.Psi_Start;
    t          = Res.Temp.In.t_start;
    
    Res.Temp.Sol.Psi = zeros(Res.Temp.Par.T/Res.Temp.Par.s_t,size(Res.Temp.In.Psi_Start(Res.Temp.Eq.mode_range),2));
    Res.Temp.Sol.t   = zeros(1,Res.Temp.Par.T/Res.Temp.Par.s_t);

    
    for ni = 1:nt 
        
        F_e           = Runge_Kuarong_step(F_e,dt,t + ni*dt,d);
        
     if ( mod(ni,Res.Temp.Par.s_t/Res.Temp.Par.dt ) == 0) && (ni ~= 0)
         
        ind_s                = round(ni*Res.Temp.Par.dt/Res.Temp.Par.s_t);
        Res.Temp.Sol.Psi(ind_s,:) = F_e(Res.Temp.Eq.mode_range)/Res.Temp.Space.N;
        Res.Temp.Sol.t(  ind_s)   = Res.Temp.Par.dt*ni;
        
        if sum(10*log10(abs(Psi(ind_s,2:end)).^2)) <= -70
            
            Res.Temp.Sol.Psi(ind_s+1:end,:) = [];
            Res.Temp.Sol.t(ind_s+1:end)     = [];
            break;
            
        end
        
     end
       
    end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    function     E_f    =    Runge_Kuarong_step(B_E,dt,t,d)
         
        E_f    =   B_E;    
        E_temp =   B_E;
        
        d(1,:) =   Res.Temp.Met.Ev_Core(E_temp,exp_plus_omega(1,:),exp_minus_omega(1,:),t,Res.Temp.Eq);
        
        for i2 = 2:Runge.s

            for ii = 1:(Runge.s-1)

                if Runge.b(i2,ii) ~= 0

                    E_temp(Res.Temp.Eq.mode_range) = E_temp(Res.Temp.Eq.mode_range) + dt*Runge.b(i2,ii).*d(ii,Res.Temp.Eq.mode_range);

                end

            end
            
            d(i2,:) =   Res.Temp.Met.Ev_Core(E_temp,exp_plus_omega(i2,:),exp_minus_omega(i2,:),t,Res.Temp.Eq);            
            
            E_temp = B_E;
            
         end 

        for i3 = 1:Runge.s

            if  Runge.c(i3)  ~= 0 

                E_f(Res.Temp.Eq.mode_range)    = E_f(Res.Temp.Eq.mode_range) + dt*Runge.c(i3).*d(i3,Res.Temp.Eq.mode_range);

            end

        end    
        
           E_f(Res.Temp.Eq.mode_range) = shift_back(Res.Temp.Eq.mode_range).*E_f(Res.Temp.Eq.mode_range); 
    end    
            
end
function     [nt,dt] = ParSim(Par)
    dt = Par.dt;
    nt = Par.T/Par.dt;
end
