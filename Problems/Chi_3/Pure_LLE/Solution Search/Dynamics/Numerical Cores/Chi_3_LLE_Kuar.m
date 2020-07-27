function k_e = Chi_3_LLE_Kuar(F_Psi,Fac_plus,Fac_minus,t,Eq)

    Psi         =                        ifft(F_Psi.*Fac_minus);

    abs_Psi_2   =                                   abs(Psi).^2;

    k_e         = 1i*Fac_plus.*( Eq.gamma_Kerr.*fft(abs_Psi_2.*Psi )); 

    k_e(1)      = k_e(1) + 1i*Fac_plus(1).*(size(Psi,2)*Eq.h);

    
end
