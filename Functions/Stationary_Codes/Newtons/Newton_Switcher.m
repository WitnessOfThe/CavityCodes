function [x0,eps_f,Output]    = Newton_Switcher(x0,Stat)

    switch func2str(Stat.Met.Newton)
        
        case 'Newton_Manual_bicgstab'
            
            [x0,eps_f,Output]   = Stat.Met.Newton(Stat,x0);
            
        case 'fsolve'
                
%            Stat.Eq.FFT   = dftmtx(Stat.Space.N);
%            Stat.Eq.IFFT  = conj(Stat.Eq.FFT)/Stat.Space.N;
            Psi_theta           = ifft( x0(1:Stat.Space.N) + 1i*x0(Stat.Space.N+1:Stat.Space.N*2));
            Stat.Eq.Dir         = Finite_Derivatives(Stat.Space.N,Stat.Space.dphi);
            [x0,eps_f,Output,~] = Stat.Met.Newton(@(x)Stat.Met.Newton_Matrix(Stat,x),[real(Psi_theta),imag(Psi_theta)],Stat.Par.fsolveoptions);
            eps_f = sum(abs(eps_f));           
            Psi_m               = fft( x0(1:Stat.Space.N) + 1i*x0(Stat.Space.N+1:Stat.Space.N*2));
            x0                  = [real(Psi_m),imag(Psi_m)];
 %           Stat.Eq.FFT   = [];
 %           Stat.Eq.IFFT  = [];
            
    end
    
end


