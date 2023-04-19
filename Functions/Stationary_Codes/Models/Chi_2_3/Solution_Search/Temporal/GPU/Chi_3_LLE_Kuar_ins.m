function k_e = Chi_3_LLE_Kuar_ins(F_Psi,Fac_plus,Fac_minus,gam2o,gam2e,gam3o,gam3e,H_f)     
 
    N       = size(F_Psi,2)/2;

    Psio    = ifft(F_Psi(1:N).*Fac_minus(1:N));
    Psie    = ifft(F_Psi(N+1:2*N).*Fac_minus(N+1:2*N));

    k_e         = Fac_plus(1).*H_f;
    k_e(1:N)    = 1i*Fac_plus(1:N).*(gam2o.*fft(conj(Psio).*Psie)+  gam3o.*fft((abs(Psio).^2 + 2*abs(Psie).^2).*Psio )   );%
    k_e(N+1:2*N)= 1i*Fac_plus(N+1:2*N).*(gam2e.*fft(Psio.^2) +gam3e.*fft((2*abs(Psio).^2 + abs(Psie).^2).*Psie) );% 

%    k_e(1)      = k_e(1) + ;


end