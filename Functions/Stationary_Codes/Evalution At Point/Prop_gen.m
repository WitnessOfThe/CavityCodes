    function L_L = Prop_gen(L_L,Slv,Delta)
    
        N = L_L.Space.N;
        
        switch Delta.Equation_string
            
            case 'Raman'
                
                L_L.Solution.Psi              =  (Slv(1:N) + 1i*Slv(N+1:2*N));                
                L_L.Solution.Q                = Slv(2*N+1:3*N);
                [L_L.Solution.Amplitude,~,~]  = Umax_value_pos(Slv,N);
                L_L.Solution.V                = Slv(3*N+1);
                L_L.Solution.Momentum         = Momentun(L_L.Solution.Psi,L_L.Space.phi,L_L.Space.k);
                
            case 'Hamilton'
                
                [L_L.Solution.Amplitude,~,~]  = Umax_value_pos(Slv,N);
                L_L.Solution.Momentum         = Momentun(L_L.Solution.Psi,L_L.Space.phi,L_L.Space.k);
                
            case 'Kerr'
                
                L_L.Solution.Psi              = (Slv(1:N) + 1i*Slv(N+1:2*N));
                [L_L.Solution.Amplitude,~,~]  = Umax_value_pos(Slv,N);
                L_L.Solution.Momentum         = Momentun(L_L.Solution.Psi,L_L.Space.phi,L_L.Space.k);
              %  L_L.Solution.V                = Slv(2*N+1);
                
            case 'Kerr_Full_Dispersion'
                
                    switch Delta.Newton 
                        
                        case 'Bc_Grad'
                            
                            L_L.Solution.E_j          = (Slv(1:N) + 1i*Slv(N+1:2*N))/L_L.Space.N;
                            L_L.Solution.Psi          = ifft(L_L.Solution.E_j);                            
                            [L_L.Solution.Amplitude]  = max(abs(L_L.Solution.Psi));
                            L_L.Solution.V            = Slv(2*N+1);
                     
                            
                        otherwise
                            
                            L_L.Solution.Psi              = (Slv(1:N) + 1i*Slv(N+1:2*N));
                            [L_L.Solution.Amplitude]  = Umax_value_pos(Slv,N);
                            
                    
                    end
   
        end
        
        function PS1 = Momentun(Sol1,phi,k)
            
            Der_1_Sol1       =  ifft(1i*k.*fft(Sol1));
            Ps               =  Sol1.*conj(Der_1_Sol1)-conj(Sol1).*Der_1_Sol1;
            PS1              =  real(1i/2*trapz(phi,Ps));
            
        end
    
        function [Umax,Num1,Num2] = Umax_value_pos(Slv,N)

            MM = abs(Slv(7:N-7)+1i*Slv(N+1+6:2*N-7));
            [Umax,Num1] = max(MM);
            Num1     =  Num1+6;
            Num2     = Num1 +  N;

        end
        
    end
