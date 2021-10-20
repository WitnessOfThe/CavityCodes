    function g = LLE_Bloch_Full_Stability_MatrixEig(Stat)
    
        mask           = 1;% L_L.Eq.mask;
       
        
        FF = dftmtx(Stat.Space.N);
        FI = conj(FF)/Stat.Space.N;
        
        psi_hat        = Stat.Sol.Psi_k.'*Stat.Space.N;
        
        f_psi          = ifft(psi_hat).';    
        
        
%        x_psi_1          = ifft(x(1:Stat.Space.N));
 %       x_psi_2          = ifft(x(Stat.Space.N+1:2*Stat.Space.N));
        
       L_pl  = Stat.Eq.delta;
       L_mn  = Stat.Eq.delta;
       
    for    i = 2:3
        
           L_pl = L_pl + ( Stat.Space.k+Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i) ;
           L_mn = L_mn + (-Stat.Space.k-Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i);
           
    end
  %     i=3;
   %        L_pl = L_pl + 1i*(1i)^i*( Stat.Space.k+Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i) ;
     %      L_mn = L_mn + 1i*(1i)^i*(Stat.Space.k+Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i);
       
          L_pl = L_pl - ( Stat.Space.k+Stat.In.k)*Stat.Sol.V;
          L_mn = L_mn - (-Stat.Space.k-Stat.In.k)*Stat.Sol.V;
           
         %  L_pl  =   L_pl.'.*x(1:Stat.Space.N)                ;
        %   L_mn =    L_mn.'.*x(Stat.Space.N+1:2*Stat.Space.N) ;
    
           
%        L_pl                   = L_L.Eq.L + 1/2*L_L.In.k^2*L_L.In.Fin_D+L_L.In.k*L_L.In.Fin_D*L_L.Space.k+(L_L.In.k+L_L.Space.k)*L_L.Sol.V;
 %       L_mn                   = L_L.Eq.L + 1/2*L_L.In.k^2*L_L.In.Fin_D-L_L.In.k*L_L.In.Fin_D*L_L.Space.k+(-L_L.In.k+L_L.Space.k)*L_L.Sol.V;
        
 
        Linear_part    = [diag(L_pl- 1i*Stat.Eq.kappa/2),zeros(Stat.Space.N,Stat.Space.N);
                         zeros(Stat.Space.N,Stat.Space.N),diag(-L_mn - 1i*Stat.Eq.kappa/2)];
                     
        Nonlinear_part = [-FF*diag( (Stat.Eq.gamma_Kerr.*(2*abs(f_psi).^2) ))*FI,-FF*diag( (Stat.Eq.gamma_Kerr.*(      f_psi.^2) ))*FI;
                           FF*diag( Stat.Eq.gamma_Kerr.*(  conj(f_psi).^2 ) )*FI, FF*diag(  Stat.Eq.gamma_Kerr.*(2*abs(f_psi).^2) )*FI];
                   
        
        g     = -1i.*(Linear_part+Nonlinear_part);
        
    end
