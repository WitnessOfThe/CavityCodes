function Save = Runge_Kuarong(L_L,Delta,Eq,Runge,Met)    

    Runge        =         Define_Runge_Coeff(Delta);
    [t,F_e]      = L_L.Met.Ev_Start_Point(L_L,Delta);    
    d            =        zeros(Runge.s,size(F_e,2));
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    exp_minus_omega = complex(zeros(size(Runge.a,2),size(Eq.L,2)));
    exp_plus_omega  = complex(zeros(size(Runge.a,2),size(Eq.L,2)));
    
    for i = 1:size(Runge.a,2)

        exp_minus_omega(i,:) = exp(-1i*Eq.L*Runge.a(i)*Delta.dt);
        exp_plus_omega (i,:) = exp( 1i*Eq.L*Runge.a(i)*Delta.dt);

    end

    shift_back = exp(-1i*Eq.L*dt); 
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    Save       = Met.Ev_Save(1,Delta,Eq,0); 
    
    
    for ni = 1 : nt  
        
        F_e  = Runge_Kuarong_step(F_e,dt,t);
        Save = Met.Ev_Save(Save,Delta,Eq,ni);                       
        
    end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    function     E_f    =    Runge_Kuarong_step(B_E,dt,t)
         
        E_f    =   B_E;    
        E_temp =   B_E;
        
        d(1,:) =   Met.Ev_Core(E_temp,exp_plus_omega(1,:),exp_minus_omega(1,:),t);
        
        for i2 = 2:Runge.s

            for ii = 1:(Runge.s-1)

                if Runge.b(i2,ii) ~= 0

                    E_temp(Eq.mode_range) = E_temp(Eq.mode_range) + dt*Runge.b(i2,ii).*d(ii,Eq.mode_range);

                end

            end
            
            d(i2,:) =   Met.Ev_Core(E_temp,exp_plus_omega(i2,:),exp_minus_omega(i2,:),t);            
            
            E_temp = B_E;
            
         end 

        for i3 = 1:Runge.s

            if  Runge.c(i3)  ~= 0 

                E_f(Eq.mode_range)    = E_f(Eq.mode_range) + dt*Runge.c(i3).*d(i3,Eq.mode_range);

            end

        end    
        
           E_f(Eq.mode_range) = shift_back(Eq.mode_range).*E_f(Eq.mode_range); 
    end    
            
end


