 function Stat = Chi23_StartTuringFromAnal(CW,Stat)
    
        CW   = Chi23_Stat_OPO_AnalyticsTurings(CW);
        Stat = Stat.Met.Norm(Stat);
        Stat(2) =Stat;
        dphi    = 2*pi/100;
        
        for i = 1:2
            
            ii      = 0;
            Flag    = 0;
            phi     = -pi;
            
            while Flag == 0
                
                ii  = ii + 1;
                phi = phi + dphi;

                Stat(i).Sol.Psi_o      = zeros(1,Stat(i).Space.N);
                Stat(i).Sol.Psi_e      = zeros(1,Stat(i).Space.N);
                
                if isnan(CW.Sol.PsiF(i))
                    
                   break;
                    
                end

                Stat(i).Sol.Psi_o(2)   = CW.Sol.PsiF(i).*exp(1i*phi);
                Stat(i).Sol.Psi_o(end) = conj(Stat(i).Sol.Psi_o(2)).*CW.Sol.expA(i);

                Stat(i).Sol.Psi_e(1)   = CW.Sol.PsiS(i);

                Psi_o           = ifft(Stat(i).Sol.Psi_o*Stat(i).Space.N);
                Psi_e           = ifft(Stat(i).Sol.Psi_e*Stat(i).Space.N);

                Slv_Start               = [real(Psi_o),imag(Psi_o)...
                                         ,real(Psi_e),imag(Psi_e),0];%

                [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Stat(i));

                Stat(i).Sol.Psi_o   = fft(Slv(1:Stat(i).Space.N) + 1i*Slv(Stat(i).Space.N+1:2*Stat(i).Space.N))/Stat(i).Space.N;
                Stat(i).Sol.Psi_e   = fft(Slv(2*Stat(i).Space.N+1:3*Stat(i).Space.N) + 1i*Slv(3*Stat(i).Space.N+1:4*Stat(i).Space.N))/Stat(i).Space.N;

                Stat(i).Sol.V       = Slv(end);

                Stat(i).Sol.eps_f   = eps_f;
                Stat(i).Sol.Exitflag= Exitflag;
                
                
                if abs(Stat(i).Sol.Psi_o(2)) > 1E-4
                    
                   Flag = 1;
                    
                end

            end
        end
        
    end

