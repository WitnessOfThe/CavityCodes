function F_e = Chi23_Runge_IntegrationSteps(nt,dt,d,F_e,exp_plus_omega,exp_minus_omega,Runge,shift_back,gam2o,gam2e,gam3o,gam3e,H_f,mode_range)

    coder.gpu.kernelfun;
    coder.gpu.kernel;
    for ni = 1:nt 
        
        F_e           = Runge_Kuarong_step(F_e,dt,d,exp_plus_omega,exp_minus_omega,Runge,shift_back,gam2o,gam2e,gam3o,gam3e,H_f,mode_range);%,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back
              
    end
end 
function     E_f    =    Runge_Kuarong_step(B_E,dt,d,exp_plus_omega,exp_minus_omega,Runge,shift_back,gam2o,gam2e,gam3o,gam3e,H_f,mode_range)

    coder.gpu.kernelfun;
    coder.gpu.kernel;

     
    E_f    =   B_E;    
    E_temp =   B_E;
    
    coder.extrinsic('Chi_3_LLE_Kuar_ins_mex');
    d(1,:) =   Chi_3_LLE_Kuar_ins_mex(E_temp,(exp_plus_omega(1,:)),(exp_minus_omega(1,:)),gam2o,gam2e,gam3o,gam3e,H_f);
    
    for i2 = 2:Runge.s

        for ii = 1:(Runge.s-1)

            if Runge.b(i2,ii) ~= 0

                E_temp(mode_range)      = E_temp(mode_range) + dt*Runge.b(i2,ii).*d(ii,mode_range);

            end

        end
        
        d(i2,:) =   Chi_3_LLE_Kuar_ins_mex(E_temp,exp_plus_omega(i2,:),exp_minus_omega(i2,:),gam2o,gam2e,gam3o,gam3e,H_f);            
        
        E_temp = B_E;
        
     end 

    for i3 = 1:Runge.s

        if  Runge.c(i3)  ~= 0 

            E_f(mode_range)    = E_f(mode_range) + dt*Runge.c(i3).*d(i3,mode_range);

        end

    end    
    
       E_f(mode_range) = shift_back(mode_range).*E_f(mode_range); 
end    
%function k_e = Chi_3_LLE_Kuar_ins(F_Psi,Fac_plus,Fac_minus,gam2o,gam2e,gam3o,gam3e,H_f)     
 
%     N       = size(F_Psi,2)/2;
% 
%     Psio    = ifft(F_Psi(1:N).*Fac_minus(1:N));
%     Psie    = ifft(F_Psi(N+1:2*N).*Fac_minus(N+1:2*N));
% 
%     k_e         = Fac_plus(1).*H_f;
%     k_e(1:N)    = 1i*Fac_plus(1:N).*(gam2o.*fft(conj(Psio).*Psie)+  gam3o.*fft((abs(Psio).^2 + 2*abs(Psie).^2).*Psio )   );%
%     k_e(N+1:2*N)= 1i*Fac_plus(N+1:2*N).*(gam2e.*fft(Psio.^2) +gam3e.*fft((2*abs(Psio).^2 + abs(Psie).^2).*Psie) );% 
% 
% %    k_e(1)      = k_e(1) + ;
% 
% 
% end