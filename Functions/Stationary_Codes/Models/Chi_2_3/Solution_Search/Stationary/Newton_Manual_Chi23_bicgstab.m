    function [x0,eps_f,SolveFlag] = Newton_Manual_Chi23_bicgstab(Stat,x0)
    
      %  [Stat.Eq.abs_psi2,Stat.Eq.ind] = max(abs(x0(1:Stat.Space.N)+1i*x0(Stat.Space.N+1:2*Stat.Space.N)).^2);
        
        fun           =  Equation_RS(x0,Stat);
        eps_f         =  max(abs(fun));
        
        SolveFlag = 1;
        j = 0;
        

        Check = sum(abs(fun) > Stat.Par.Newton_tol );
        while Check > 0
  %      [Stat.Eq.abs_psi2,Stat.Eq.ind] = max(abs(x0(1:Stat.Space.N)+1i*x0(Stat.Space.N+1:2*Stat.Space.N)).^2);
        
  %          [Stat.Eq.abs_psi2,Stat.Eq.ind] = max(abs(x0(1:Stat.Space.N)+1i*x0(Stat.Space.N+1:2*Stat.Space.N)).^2);
     
            [dx,flag,relres,iter,resvec] =  bicgstabl(@(t)Liniar_Decomposition_RS(t,x0,Stat),Equation_RS(x0,Stat),10^-10,300,@(t)Preconditioner_RS(t,Stat,x0));%%,...
 %                %
            %
            x0(1,1:end)     = x0.' - dx;
            fun             = Equation_RS(x0,Stat);
            eps_f           = max(abs(fun));
            
            if j == Stat.Par.Newton_iter || eps_f > 1E6
        
                SolveFlag = -1;
                break;
                
            end
                
        
           Check =  sum(abs(fun) > Stat.Par.Newton_tol );
           j = j+1;
        
         end
        
%         j = 0;
%         
%         while Check > 1
%             
%             [dx,flag,relres,iter,resvec] =  bicgstabl(@(t)Stat.Met.Liniar_Decomposition(t,x0,Stat),Stat.Met.Equation(x0,Stat),10^-3,100,@(t)Stat.Met.Preconditioner(t,Stat,x0) );
%             
%             x0(1,1:end)     = x0' - dx;
%             fun             = Stat.Met.Equation(x0,Stat);
%             eps_f           = sum(abs(fun));
%             
%             if j == 30
%         
%                 SolveFlag = -1;
%                 break;
%             
%             end
%         
%            Check =  sum(abs(fun) > Stat.Par.Newton_tol );
%            j = j+1;
%         
%         end
%         

    end
    function f = Liniar_Decomposition_RS(x,Psi,Stat)
         mask                = Stat.Eq.mask;               
        xo                  = (x(1:Stat.Space.N) +...
                                         1i*x(Stat.Space.N+1:2*Stat.Space.N)).';
        xe                  = (x(2*Stat.Space.N+1:3*Stat.Space.N) +...
                                         1i*x(3*Stat.Space.N+1:4*Stat.Space.N)).';
        
        xV                   = x(end);   %    
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
        Psio        = Psi(1:Stat.Space.N) + ...
                                1i*Psi(Stat.Space.N+1:2*Stat.Space.N);
        Psie        = Psi(2*Stat.Space.N+1:3*Stat.Space.N) + ...
                                        1i*Psi(3*Stat.Space.N+1:4*Stat.Space.N);
        
        
        V               = Psi(end);
        [~,ind]         = max(abs(Psio).^2);
                
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
        L1      = ifft(mask.* fft(xo).*(Stat.Eq.Lo - V*Stat.Space.k) - Stat.Space.k.*xV.*fft(Psio));
        
        NL1     =  - (Stat.Eq.gam2o.*( Psie.*conj(xo) + conj(Psio).*xe ) +...
                  Stat.Eq.gam3o.*(...
                 2*(abs(Psio).^2 + abs(Psie).^2 ).*xo + Psio.^2.*conj(xo) + ...
                         2*conj(Psie).*Psio.*xo + 2*Psio.*Psie.*conj(xe)));
        
        L2      = ifft(mask.* fft(xe).*(Stat.Eq.Le - V*Stat.Space.k) - Stat.Space.k.*xV.*fft(Psie) );
        
        NL2     =  - (Stat.Eq.gam2e.*( 2*Psio.*xo ) +...
                 Stat.Eq.gam3e.*( 2*conj(Psio).*Psie.*xo + 2*Psio.*Psie.*conj(xo)...
                  + 2*( abs(Psio).^2 + abs(Psie).^2 ).*xe + Psie.^2.*conj(xe)) );
        
        Eq1     = ( L1 + NL1 );
            
        Eq2     = ( L2 + NL2 );
        
      Eq3     = abs(ifft(mask.*1i.*Stat.Space.k.*fft( conj(Psio).*xo + Psio.*conj(xo))));
   %   Eq3     =- 2*real(ifft(1i.*Stat.Space.k.*fft(xo),'symmetric').*conj(Psio) + ifft(1i.*Stat.Space.k.*fft(Psio),'symmetric').*xo );
        
        Eq1R = real(Eq1).';
        Eq1I = imag(Eq1).';
        
        Eq2R = real(Eq2).';
        Eq2I = imag(Eq2).';

        f       = [Eq1R;Eq1I;Eq2R;Eq2I;Eq3(ind)];%\;
        
    end
    function f = Equation_RS(x,Stat)
    
        mask                = Stat.Eq.mask;
            
        xo               = x(1:Stat.Space.N) +...
                                 1i*x(Stat.Space.N+1:2*Stat.Space.N);
                             
        xe               = x(2*Stat.Space.N+1:3*Stat.Space.N) +...
                               1i*x(3*Stat.Space.N+1:4*Stat.Space.N);
        
        V                   = x(end);   %    
                 [~,ind]         = max(abs(xo).^2);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        L1     = ifft(mask.*(Stat.Eq.Lo - V*Stat.Space.k).*fft(xo));
        NL1    =  - (Stat.Eq.gam2o.*xe.*conj(xo) + ...
                            Stat.Eq.gam3o.*(abs(xo).^2 + 2*abs(xe).^2).*xo);
        
        L2     = ifft(mask.*(Stat.Eq.Le - V*Stat.Space.k).*fft(xe));
        NL2    =  - (Stat.Eq.gam2e.*xo.^2  +...
                        Stat.Eq.gam3e.*(2*abs(xo).^2 + abs(xe).^2).*xe);
        Pump   = 1i/2*Stat.Eq.ko*Stat.In.H;

        f_1    = ( L1 + NL1 + Pump);        
        f_2    = ( L2 + NL2 );
        
       f_3    = abs(ifft(mask.*1i.*Stat.Space.k.*fft(abs(xo).^2)));
        
  %    f_3    = -2*real(conj(xo).*ifft(1i.*Stat.Space.k.*fft(xo))); %1*ifft(mask.*1i.*Stat.Space.k.*fft(abs_psi2),'symmetric');
        
        f     = [real(f_1).';imag(f_1).';real(f_2).';imag(f_2).';f_3(ind).'];%\;
        
    end
    function M = Preconditioner_RS(t,Stat,x0)
    
        ddt = 10^4;        
        
        Lo   =  Stat.Eq.mask.*(real( Stat.Eq.Lo - Stat.Space.k.*x0(end) ));%
        Le   =  Stat.Eq.mask.*(real( Stat.Eq.Le - Stat.Space.k.*x0(end) ));%
%        Lo   =Stat.Eq.mask.*(abs(-Stat.Space.k.*x0(end)- Stat.Space.k.*Stat.Eq.d/2 + Stat.Space.k.^2*1/2*Stat.Eq.Do(2)));
%        Le   =Stat.Eq.mask.*(abs(-Stat.Space.k.*x0(end)+ Stat.Space.k.*Stat.Eq.d/2 + Stat.Space.k.^2*1/2*Stat.Eq.De(2)));
  %%      
  
        m_psio = fft(t(1:Stat.Space.N)                  + 1i.*t(Stat.Space.N+1:2*Stat.Space.N));  
        m_psie = fft(t(2*Stat.Space.N+1:3*Stat.Space.N) + 1i.*t(3*Stat.Space.N+1:4*Stat.Space.N));  
        
        M_psio = ifft(Stat.Eq.mask.'.*ddt.*m_psio./(eps +  1. + ddt.*abs(Lo).' ));
        M_psie = ifft(Stat.Eq.mask.'.*ddt.*m_psie./(eps +  1. + ddt.*abs(Le).' ));
        
        M     = [real(M_psio);imag(M_psio);real(M_psie);imag(M_psie);t(4*Stat.Space.N+1)];%;%;t(2*L_L.Space.N+1)
        
    end
