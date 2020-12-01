function [f,g] = Chi3_LLE_Bloch_Stat_Newton_Matrix(L_L,x)

%         N         = size(x,2)/2;
%     
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         
%         psi_hat             = L_L.Eq.mask.*x(1:L_L.Space.N) + 1i*x(L_L.Space.N+1:2*L_L.Space.N);
%         
%         f_psi               = ifft(psi_hat);
%         
%         abs_psi_2           = abs(f_psi).^2;
%              
%         
% 
%         Nonliniar_term =    -L_L.Eq.gamma_Kerr.*fft(abs_psi_2.*f_psi);
%         Pump           =    zeros(1,L_L.Space.N);
%         Pump(1)        =     1i*L_L.Eq.h*L_L.Space.N;
%         Liniar_term    =     (L_L.Eq.L ).*psi_hat;
%         Eq             =    -1i*(Liniar_term + Nonliniar_term + Pump);
%         
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %        f_r = spdiags(x(1:N)',0,N,N);
%  %       f_i = spdiags(x(N+1:2*N)',0,N,N);
% 
%         
%     
%         f(1:N)       =         (L_L.Eq.mask.*Eq);
%         f(N+1:2*N)   =     conj(L_L.Eq.mask.*Eq);
%     
%         matr_Psi     = diag( f_psi.',0);
% 
%         g_1_1 =  -1i*diag(real(L_L.Eq.mask.'.*L_L.Eq.L.'),0) +diag(imag(L_L.Eq.mask.'.*L_L.Eq.L.'),0) + 1i*diag(L_L.Eq.mask.'.*L_L.Eq.gamma_Kerr.',0).*2*L_L.Eq.FFT.*abs(matr_Psi).^2*L_L.Eq.IFFT;
%         g_1_2 =   1i*diag(L_L.Eq.mask.'.*L_L.Eq.gamma_Kerr.',0).*L_L.Eq.FFT.*matr_Psi.^2*L_L.Eq.IFFT;
%         
%         g_2_2 =    1i*diag(real(L_L.Eq.mask.'.*L_L.Eq.L.'),0) +diag(imag(L_L.Eq.mask.'.*L_L.Eq.L.'),0) - 1i*diag(L_L.Eq.mask.'.*L_L.Eq.gamma_Kerr.',0).*2*L_L.Eq.IFFT.*abs(matr_Psi).^2*L_L.Eq.FFT;
%         g_2_1 =   -1i*diag(L_L.Eq.mask.'.*L_L.Eq.gamma_Kerr.',0).*L_L.Eq.IFFT.*conj(matr_Psi).^2*L_L.Eq.FFT;
%         
%         %        g_1_1 =  - real(diag(L_L.Eq.mask.'.*L_L.Eq.L.',0));
%  %       g_1_2 =  - imag(diag(L_L.Eq.mask.'.*L_L.Eq.L.',0)) -  diag(L_L.Eq.mask.'.*L_L.Eq.gamma_Kerr.',0).*( L_L.Eq.FFT.*matr_Psi.^2*L_L.Eq.IFFT - 2*L_L.Eq.FFT.*abs(matr_Psi).^2*L_L.Eq.IFFT  );
% 
%         
%   %      g_2_2 =    real(diag(L_L.Eq.mask.'.*L_L.Eq.L.',0));
%    %     g_2_1 =  - imag(diag(L_L.Eq.mask.'.*L_L.Eq.L.',0)) +  diag(L_L.Eq.mask.'.*L_L.Eq.gamma_Kerr.',0).*( L_L.Eq.FFT.*matr_Psi.^2*L_L.Eq.IFFT + 2*L_L.Eq.FFT.*abs(matr_Psi).^2*L_L.Eq.IFFT  );
% 
%         g = [      g_1_1,        g_1_2;
%                    g_2_1,  g_2_2];

        N   = size(x,2)/2;
        f_r = spdiags(x(1:N)',0,N,N);
        f_i = spdiags(x(N+1:2*N)',0,N,N);
        
        
        f(1:N)       =  - L_L.Eq.D(2)/2*L_L.Eq.Dir.d2*x(1:N)'     + L_L.Eq.delta*x(1:N)'     + L_L.Eq.kappa/2*x(N+1:2*N)' - (x(1:N)'.^2 + x(N+1:2*N)'.^2).*x(1:N)'*L_L.Eq.gamma_3 ;
        f(N+1:2*N)   =  - L_L.Eq.D(2)/2*L_L.Eq.Dir.d2*x(N+1:2*N)' + L_L.Eq.delta*x(N+1:2*N)' - L_L.Eq.kappa/2*x(1:N)'     - (x(1:N)'.^2 + x(N+1:2*N)'.^2).*x(N+1:2*N)'*L_L.Eq.gamma_3 + L_L.Eq.h;
        
        f = f';
        
        g_1_1 = L_L.Eq.D(4)/24*L_L.Eq.Dir.d4 - L_L.Eq.D(2)/2*L_L.Eq.Dir.d2  + L_L.Eq.delta*speye(N,N) - (3*f_r.^2+f_i.^2)*L_L.Eq.gamma_3;
        g_1_2 =   speye(N,N)*L_L.Eq.kappa/2 - 2*f_r.*f_i*L_L.Eq.gamma_3;
        
        g_2_1 = - speye(N,N)*L_L.Eq.kappa/2 - 2*f_r.*f_i*L_L.Eq.gamma_3;
        g_2_2 = L_L.Eq.D(4)/24*L_L.Eq.Dir.d4 - L_L.Eq.D(2)/2*L_L.Eq.Dir.d2 + speye(N,N)*L_L.Eq.delta - (f_r.^2+3*f_i.^2)*L_L.Eq.gamma_3;
        
        g = [g_1_1,g_1_2;
             g_2_1,g_2_2];
        

end
