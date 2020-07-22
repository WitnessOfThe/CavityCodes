function [F_e_cubic,E_0] = Restore_Field_From_Carrier(Psi,m_p_index,N)

 %        F_e(1:size(Psi,2))              = fft(Psi)/size(Psi,2);
%         F_e                              = circshift(fftshift(F_e), m_p_index - size(Psi,2)/2-1);
         F_e                              = fft(Psi.*exp(1i*(m_p_index-1).*2*pi/N.*[0:N-1]))/size(Psi,2);
         F_e(1)                           = 0;
         F_e                              = [F_e,zeros(1,N-size(Psi,2))];
         F_e(N/2+1:end)                   = 0;
         F_e_shifted                      = zeros(1,N);
         F_e_shifted(2:N)                 = flip( conj( F_e(2:N)) );
         Comp_Spectr                      = [F_e,F_e_shifted];
         E_0                              = ifft(Comp_Spectr,'symmetric')*2*N;%
         F_E_0                            = fft(E_0)/N/2;%
         F_e_cubic                        = F_E_0(1:N);

end

