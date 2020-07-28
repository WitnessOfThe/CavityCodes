function Temp = Runge_Kuarong(Temp)    

    Runge        =               Define_Runge_Coeff(Temp.Par);
    d            =  zeros(Runge.s,size( Temp.In.Psi_Start,2));
    [nt,dt]      =                           ParSim(Temp.Par);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    exp_minus_omega = complex(zeros(size(Runge.a,2),size(Temp.Eq.L,2)));
    exp_plus_omega  = complex(zeros(size(Runge.a,2),size(Temp.Eq.L,2)));
    
    for i = 1:size(Runge.a,2)

        exp_minus_omega(i,:) = exp(-1i*Temp.Eq.L*Runge.a(i)*dt);
        exp_plus_omega (i,:) = exp( 1i*Temp.Eq.L*Runge.a(i)*dt);

    end

    shift_back = exp(-1i*Temp.Eq.L*dt); 
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    Temp       = Temp.Met.Ev_Save(0,Temp,0); 
    
    F_e        = Temp.In.Psi_Start;
    t          = Temp.In.t_start;

    
    for ni = 1:nt 
        
        F_e       = Runge_Kuarong_step(F_e,dt,t + ni*dt);
        Temp      =   Temp.Met.Ev_Save(F_e,Temp,ni);                       
        
    end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    function     E_f    =    Runge_Kuarong_step(B_E,dt,t)
         
        E_f    =   B_E;    
        E_temp =   B_E;
        
        d(1,:) =   Temp.Met.Ev_Core(E_temp,exp_plus_omega(1,:),exp_minus_omega(1,:),t,Temp.Eq);
        
        for i2 = 2:Runge.s

            for ii = 1:(Runge.s-1)

                if Runge.b(i2,ii) ~= 0

                    E_temp(Temp.Eq.mode_range) = E_temp(Temp.Eq.mode_range) + dt*Runge.b(i2,ii).*d(ii,Temp.Eq.mode_range);

                end

            end
            
            d(i2,:) =   Temp.Met.Ev_Core(E_temp,exp_plus_omega(i2,:),exp_minus_omega(i2,:),t,Temp.Eq);            
            
            E_temp = B_E;
            
         end 

        for i3 = 1:Runge.s

            if  Runge.c(i3)  ~= 0 

                E_f(Temp.Eq.mode_range)    = E_f(Temp.Eq.mode_range) + dt*Runge.c(i3).*d(i3,Temp.Eq.mode_range);

            end

        end    
        
           E_f(Temp.Eq.mode_range) = shift_back(Temp.Eq.mode_range).*E_f(Temp.Eq.mode_range); 
    end    
            
end
function     [nt,dt] = ParSim(Par)
    dt = Par.dt;
    nt = Par.T/Par.dt;
end