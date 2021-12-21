    function g = LLE_Bloch_Full_Stability_MatrixEigConjFAST(Stat,FF,FI)
                    
        psi_hat        = Stat.Sol.Psi_k.'*Stat.Space.N;
        
        f_psi          = ifft(psi_hat).';    
        
        L_pl           = complex(zeros(1,Stat.Space.N));
        L_mn           = complex(zeros(1,Stat.Space.N));
                
       L_pl(1:Stat.Space.N)  = Stat.Eq.delta*ones(1,Stat.Space.N);
       L_mn(1:Stat.Space.N)  = Stat.Eq.delta*ones(1,Stat.Space.N);
       
        for    i = 2:3

               L_pl(1:Stat.Space.N) = L_pl(1:Stat.Space.N) + ( Stat.Space.k+Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i) ;
               L_mn (1:Stat.Space.N)= L_mn(1:Stat.Space.N) + (-Stat.Space.k-Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i);

        end
       
        L_pl(1:Stat.Space.N) = L_pl(1:Stat.Space.N) - ( Stat.Space.k+Stat.In.k)*Stat.Sol.V;
        L_mn(1:Stat.Space.N) = L_mn(1:Stat.Space.N) - (-Stat.Space.k-Stat.In.k)*Stat.Sol.V;
                   
 
        Linear_part    = [diag(L_pl- 1i*Stat.Eq.kappa/2),zeros(Stat.Space.N,Stat.Space.N);
                         zeros(Stat.Space.N,Stat.Space.N),diag(-L_mn - 1i*Stat.Eq.kappa/2)];
                     
        Nonlinear_part = [-FF*diag( (Stat.Eq.gamma_Kerr.*(2*abs(f_psi).^2) ))*FI,-FF*diag( (Stat.Eq.gamma_Kerr.*(      f_psi.^2) ))*FI;
                           FF*diag( Stat.Eq.gamma_Kerr.*(  conj(f_psi).^2 ) )*FI, FF*diag(  Stat.Eq.gamma_Kerr.*(2*abs(f_psi).^2) )*FI];
                   
        
        g     = conj(-1i.*(Linear_part+Nonlinear_part));
        
    end
