function k_e = Chi_3_LLE_Kuar(F_Psi,Fac_plus,Fac_minus,Eq,t)

    Psi         =                        ifft(F_Psi.*Fac_minus);

    abs_Psi_2   =                                   abs(Psi).^2;

    k_e         = 1i*Fac_plus.*( gamma_3.*fft(abs_Psi_2.*Psi )); 

    k_e(1)      = k_e(1) + 1i*Fac_plus(1).*(size(Psi,2)*Pump(1));

end
