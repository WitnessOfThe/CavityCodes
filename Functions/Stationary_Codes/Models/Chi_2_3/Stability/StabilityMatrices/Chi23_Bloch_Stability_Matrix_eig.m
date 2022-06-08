    function f = Chi23_Bloch_Stability_Matrix_eig(x,Stat)
    
%        xo                  = (x(1:Stat.Space.N) +...
 %                                        1i*x(Stat.Space.N+1:2*Stat.Space.N)).';
  %      xe                  = (x(2*Stat.Space.N+1:3*Stat.Space.N) +...
   %                                      1i*x(3*Stat.Space.N+1:4*Stat.Space.N)).';
        
        xo1                  = (x(1:Stat.Space.N)).';
        xo2                  = (x(Stat.Space.N+1:2*Stat.Space.N)).';
        
        xe1                  = (x(2*Stat.Space.N+1:3*Stat.Space.N) ).';
        xe2                  = (x(3*Stat.Space.N+1:4*Stat.Space.N)).';
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        
        Psio        = ifft(Stat.Sol.Psi_o*Stat.Space.N);
        Psie        = ifft(Stat.Sol.Psi_e*Stat.Space.N);
        
       
        V               = -Stat.Sol.V;
       % mu                 = Stat.Space.k ;
       
        mu              = Stat.Space.k  + Stat.In.n;

%       mu(Stat.Space.k>0) =  mu(Stat.Space.k>0) +Stat.In.n;
%       mu(Stat.Space.k<0) =  mu(Stat.Space.k<0) +Stat.In.n;

%        Lo      = Stat.Eq.Lo + Stat.Space.k*Stat.In.n*Stat.Eq.Do(2) +Stat.In.n.^2*Stat.Eq.Do(2)/2 - V*mu;%-Stat.Sol.V.*(Stat.In.n + Stat.Space.k);   %Stat.Eq.mask.*(Stat.Eq.delta_o + mu.^2*1/2*Stat.Eq.Do(2) - 1i*Stat.Eq.ko/2- V*mu);
 %       Le      = Stat.Eq.Le + Stat.Space.k*Stat.In.n*Stat.Eq.De(2) +Stat.In.n.^2*Stat.Eq.De(2)/2 + Stat.Eq.d.*Stat.In.n - V*mu;%-Stat.Sol.V.*(Stat.In.n + Stat.Space.k);%Stat.Eq.mask.*(Stat.Eq.delta_e + mu.*Stat.Eq.d + mu.^2*1/2*Stat.Eq.De(2) - 1i*Stat.Eq.ke/2- V*mu);

        Lop  = Stat.Eq.delta_o                 + V*mu;
        Lep  = Stat.Eq.delta_e + mu.*Stat.Eq.d  + V*mu;

        Lom  = Stat.Eq.delta_o                 - V*mu;
        Lem  = Stat.Eq.delta_e - mu.*Stat.Eq.d  - V*mu;

        for i = [2,3,4]
            Lop = Lop + mu.^i*Stat.Eq.Do(i)/factorial(i);
            Lep = Lep + mu.^i*Stat.Eq.De(i)/factorial(i);
        end
        for i = [2,3,4]
            Lom = Lom + (-mu).^i*Stat.Eq.Do(i)/factorial(i);
            Lem = Lem + (-mu).^i*Stat.Eq.De(i)/factorial(i);
        end
        


        L1p      = ifft( fft(xo1).*(Lop - 1i*Stat.Eq.ko/2) );
        L1m      = ifft( fft(xo2).*(Lom + 1i*Stat.Eq.ko/2) );
        
        NL1p     =  - (Stat.Eq.gam2o.*( Psie.*xo2 + conj(Psio).*xe1 ) +...
                  Stat.Eq.gam3o.*(...
                  2*(abs(Psio).^2 + abs(Psie).^2 ).*xo1 + Psio.^2.*xo2 + ...
                          2*conj(Psie).*Psio.*xe1 + 2*Psio.*Psie.*xe2));
        
        NL1m     =  - (Stat.Eq.gam2o.*( conj(Psie).*xo1 + Psio.*xe2 ) +...
                  Stat.Eq.gam3o.*(...
                  2*(abs(Psio).^2 + abs(Psie).^2 ).*xo2 + conj(Psio).^2.*xo1 + ...
                          2*conj(Psio).*Psie.*xe2 + 2*conj(Psio.*Psie).*xe1));

        L2p      = ifft( fft(xe1).*(Lep - 1i*Stat.Eq.ke/2));
        L2m      = ifft( fft(xe2).*(Lem + 1i*Stat.Eq.ke/2));
        
        NL2p     =  - (Stat.Eq.gam2e.*( 2*Psio.*xo1 ) +...
                 Stat.Eq.gam3e.*( 2*conj(Psio).*Psie.*xo1 + 2*Psio.*Psie.*xo2...
                 + 2*( abs(Psio).^2 + abs(Psie).^2 ).*xe1 + Psie.^2.*xe2) );

        NL2m     =  - (Stat.Eq.gam2e.*( 2*conj(Psio).*xo2 ) +...
                 Stat.Eq.gam3e.*( 2*Psio.*conj(Psie).*xo2 + 2*conj(Psio.*Psie).*xo1...
                 + 2*( abs(Psio).^2 + abs(Psie).^2 ).*xe2 + conj(Psie).^2.*xe1) );

        f  = [fop,fom;
              fep,fem];
    end
