    function f = Chi23_Bloch_Stability_Matrix(x,Stat)
    
        xo                  = (x(1:Stat.Space.N) +...
                                         1i*x(Stat.Space.N+1:2*Stat.Space.N)).';
        xe                  = (x(2*Stat.Space.N+1:3*Stat.Space.N) +...
                                         1i*x(3*Stat.Space.N+1:4*Stat.Space.N)).';
        
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
        Psio        = ifft(Stat.Sol.Psi_o*Stat.Space.N);
        Psie        = ifft(Stat.Sol.Psi_e*Stat.Space.N);
        
       
        abs_psi2        = abs(Psio).^2;
        [~,max_ind]     = max(abs_psi2);
                
        V               = Stat.Sol.V;
       % mu                 = Stat.Space.k ;
       
         mu              = Stat.Space.k  + Stat.In.n;
%       mu(Stat.Space.k>0) =  mu(Stat.Space.k>0) +Stat.In.n;
%       mu(Stat.Space.k<0) =  mu(Stat.Space.k<0) +Stat.In.n;

        Lo      = Stat.Eq.Lo + Stat.Space.k*Stat.In.n*Stat.Eq.Do(2) +Stat.In.n.^2*Stat.Eq.Do(2)/2 - V*mu;%-Stat.Sol.V.*(Stat.In.n + Stat.Space.k);   %Stat.Eq.mask.*(Stat.Eq.delta_o + mu.^2*1/2*Stat.Eq.Do(2) - 1i*Stat.Eq.ko/2- V*mu);
        Le      = Stat.Eq.Le + Stat.Space.k*Stat.In.n*Stat.Eq.De(2) +Stat.In.n.^2*Stat.Eq.De(2)/2 +...
        + Stat.Eq.d.*Stat.In.n - V*mu;%-Stat.Sol.V.*(Stat.In.n + Stat.Space.k);%Stat.Eq.mask.*(Stat.Eq.delta_e + mu.*Stat.Eq.d + mu.^2*1/2*Stat.Eq.De(2) - 1i*Stat.Eq.ke/2- V*mu);
%         if Stat.In.n > 0
%             mu              = Stat.Space.k  + Stat.In.n;
%             Lo              = Stat.Eq.mask.*(Stat.Eq.delta_o + mu .^2*1/2*Stat.Eq.Do(2)  - V*mu - 1i*Stat.Eq.ko/2);
%             Le              = Stat.Eq.mask.*(Stat.Eq.delta_e + mu *Stat.Eq.d + mu .^2*1/2*Stat.Eq.De(2)   - V*mu- 1i*Stat.Eq.ke/2);
%         else
%             mu              = Stat.Space.k  + Stat.In.n;
%             Lo              = Stat.Eq.mask.*(Stat.Eq.delta_o + mu .^2*1/2*Stat.Eq.Do(2)  - V*mu - 1i*Stat.Eq.ko/2);
%             Le              = Stat.Eq.mask.*(Stat.Eq.delta_e + mu *Stat.Eq.d + mu .^2*1/2*Stat.Eq.De(2)   - V*mu- 1i*Stat.Eq.ke/2);
%         end      
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        L1      = ifft( fft(xo).*(Lo) );
        
        NL1     =  - (Stat.Eq.gam2o.*( Psie.*conj(xo) + conj(Psio).*xe ) +...
                 Stat.Eq.gam3o.*(...
                 2*(abs(Psio).^2 + abs(Psie).^2 ).*xo + Psio.^2.*conj(xo) + ...
                         2*conj(Psie).*Psio.*xo + 2*Psio.*Psie.*conj(xe)));
        
        L2      = ifft( fft(xe).*(Le));
        
        NL2     =  - (Stat.Eq.gam2e.*( 2*Psio.*xo ) +...
                 Stat.Eq.gam3e.*( 2*conj(Psio).*Psie.*xo + 2*Psio.*Psie.*conj(xo)...
                 + 2*( abs(Psio).^2 + abs(Psie).^2 ).*xe + Psie.^2.*conj(xe)) );
        
        Eq1     = -1i*( L1 + NL1 );
            
        Eq2     = -1i*( L2 + NL2 );
                
        Eq1R(1:Stat.Space.N,1) = real(Eq1);
        Eq1I(1:Stat.Space.N,1) = imag(Eq1);
        Eq2R(1:Stat.Space.N,1) = real(Eq2);
        Eq2I(1:Stat.Space.N,1) = imag(Eq2);
        
        f       = [Eq1R;Eq1I;Eq2R;Eq2I];%\;

%         mask                = Stat.Eq.mask;%[ones(1,Stat.In.N/2-Stat.Space.N/4),zeros(1,Stat.Space.N/4),zeros(1,Stat.Space.N/4),ones(1,Stat.In.N/2-Stat.Space.N/4)];
%             
%         xo                  = mask.*(x(1:Stat.Space.N) +...
%                                          1i*x(Stat.Space.N+1:2*Stat.Space.N)).';
%         xe                  = mask.*(x(2*Stat.Space.N+1:3*Stat.Space.N) +...
%                                          1i*x(3*Stat.Space.N+1:4*Stat.Space.N)).';
%         
%      
%         
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
%         xoS             = ifft(xo);        
%         xeS             = ifft(xe);
%         
%         Psio_hat        = mask.*Stat.Space.N.*Stat.Sol.Psi_o;
%         Psie_hat        = mask.*Stat.Space.N.*Stat.Sol.Psi_e;
%         
%         Psio            = ifft(Psio_hat);
%         Psie            = ifft(Psie_hat);
%         Psio2           = Psio.^2;%ifft(mask.*fft());
%         Psie2           = Psie.^2;% ifft(mask.*fft());
%         Psioe           = Psio.*Psie;%ifft(mask.*fft());
%         PsiCoe           =conj(Psio).*Psie;% ifft(mask.*fft());
%         PsioCe           = conj(Psie).*Psio;%ifft(mask.*fft());
%         
%         V               = Stat.Sol.V;
%         
%         mu      = (Stat.Space.k + Stat.In.n);
%         
%         Lo      = Stat.Eq.Lo + Stat.Space.k*Stat.In.n*Stat.Eq.Do(2) +Stat.In.n.^2*Stat.Eq.Do(2)/2 - V*mu;%-Stat.Sol.V.*(Stat.In.n + Stat.Space.k);   %Stat.Eq.mask.*(Stat.Eq.delta_o + mu.^2*1/2*Stat.Eq.Do(2) - 1i*Stat.Eq.ko/2- V*mu);
%         Le      = Stat.Eq.Le + Stat.Space.k*Stat.In.n*Stat.Eq.De(2) +Stat.In.n.^2*Stat.Eq.De(2)/2 + Stat.Eq.d.*Stat.In.n- V*mu;%-Stat.Sol.V.*(Stat.In.n + Stat.Space.k);%Stat.Eq.mask.*(Stat.Eq.delta_e + mu.*Stat.Eq.d + mu.^2*1/2*Stat.Eq.De(2) - 1i*Stat.Eq.ke/2- V*mu);
%         
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
%         
%         L1      = ( xo.*(Lo) );
%         
%         NL1     =  - fft(Stat.Eq.gam2o.*( Psie.*conj(xoS) + conj(Psio).*xeS ) +...
%                 Stat.Eq.gam3o.*(...
%                 2*(abs(Psio2) + abs(Psie2) ).*xoS + Psio2.*conj(xoS) + ...
%                         2*PsioCe.*xoS + 2*Psioe.*conj(xeS)));
%         
%         L2      =  xe.*(Le);
%         
%         NL2     =  - fft(Stat.Eq.gam2e.*( 2*Psio.*xoS ) +...
%                 Stat.Eq.gam3e.*( 2*PsiCoe.*xoS + 2*Psioe.*conj(xoS)...
%                 + 2*( abs(Psio2) + abs(Psie2) ).*xeS + Psie2.*conj(xeS))) ;
%         
%         Eq1     = -1i*mask.*( L1 + NL1 );
%             
%         Eq2     = -1i*mask.*( L2 + NL2 );
%         
%         
%         Eq1R = real(Eq1).';
%         Eq1I = imag(Eq1).';
%         
%         Eq2R = real(Eq2).';
%         Eq2I = imag(Eq2).';
%         
%         f       = [Eq1R;Eq1I;Eq2R;Eq2I];%\;        
    end
