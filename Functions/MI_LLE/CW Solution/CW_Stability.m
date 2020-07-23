function L_L = CW_Stability(L_L)   
    Value = zeros(1,6*L_L.Space.N);
    
    for j = 1:3
        if isnan(L_L.Solution.CW.Psi(j)) ~= 1
            
            for i=1:L_L.Space.N
%               tt = eig(Stability_Matrix(L_L.Space.k(i),L_L.Solution.CW.Psi(j),L_L.Solution.CW.Q(j)));%,L_L.Eq.V_cr
                tt = eig(Stability_Matrix_Velocity(L_L.Space.k(i),L_L.Solution.CW.Psi(j),L_L.Solution.CW.Q(j),L_L.Eq.V_cr));%
                Value(i)               = tt(1);
                Value(L_L.Space.N+i)   = tt(2);
                Value(2*L_L.Space.N+i) = tt(3);
                Value(3*L_L.Space.N+i) = tt(4);
                Value(4*L_L.Space.N+i) = tt(5);
                Value(5*L_L.Space.N+i) = tt(6);
            end
            
                L_L.Solution.CW.Stability(j).Value                  = Value;
                [L_L.Solution.CW.Stability(j).Max_Groth_Rate,Index] = max(real(Value));
                tt = [L_L.Space.k,L_L.Space.k,L_L.Space.k,L_L.Space.k,L_L.Space.k,L_L.Space.k];
                L_L.Solution.CW.Stability(j).k                      = tt(Index); 
       else
           L_L.Solution.CW.Stability(j).Value          = zeros(1,6*L_L.Space.N);
           L_L.Solution.CW.Stability(j).Max_Groth_Rate = NaN;
           L_L.Solution.CW.Stability(j).k              = NaN;
        end
       
    end     


%     function  M = Stability_Matrix(m,psi,Q_r)
%          
%             g_1_1   = -1i*2*pi*m - 1i*1/2*m.^2.*L_L.Eq.D(2) - 1i*1/6*m.^3.*L_L.Eq.D(3) - 1i*1/6/4*m.^4.*L_L.Eq.D(4) - 1i*L_L.Eq.delta - L_L.Eq.gamma + 1i*L_L.Eq.gamma_3*( Q_r + 2*(1-L_L.Raman.mu).*abs(psi).^2 );
%             g_1_2   = 1i*L_L.Eq.gamma_3*(1-L_L.Raman.mu).*psi.^2;
%             g_1_3   = 0;
%             g_1_4   = 1i*psi.*L_L.Eq.gamma_3;
%             
%             g_2_1   = -1i*L_L.Eq.gamma_3*(1-L_L.Raman.mu).*conj(psi).^2;
%             g_2_2   = -1i*2*pi*m + 1i*1/2*m.^2.*L_L.Eq.D(2) - 1i*1/6*m.^3.*L_L.Eq.D(3)  + 1i*1/6/4*m.^4.*L_L.Eq.D(4) + 1i*L_L.Eq.delta - L_L.Eq.gamma - 1i*L_L.Eq.gamma_3*( Q_r + 2*(1-L_L.Raman.mu).*abs(psi).^2 );
%             g_2_3   = 0;
%             g_2_4   = -1i*conj(psi).*L_L.Eq.gamma_3;
%             
%             g_3_1   = L_L.Raman.t_r.^2*L_L.Raman.Omega^2*L_L.Raman.mu*conj(psi);
%             g_3_2   = L_L.Raman.t_r.^2*L_L.Raman.Omega^2*L_L.Raman.mu*psi;
%             g_3_3   = - 2*L_L.Raman.gamma *L_L.Raman.t_r;
%             g_3_4   = -   L_L.Raman.t_r.^2*L_L.Raman.Omega^2;
%                         
%             g_4_1 = 0;
%             g_4_2 = 0;
%             g_4_3 = 1;
%             g_4_4 = 0;
% 
% 
%             
%             M = [g_1_1,g_1_2,g_1_3,g_1_4;
%                 g_2_1,g_2_2,g_2_3,g_2_4;
%                 g_3_1,g_3_2,g_3_3,g_3_4;
%                 g_4_1,g_4_2,g_4_3,g_4_4];
%  
%     end
    function  M = Stability_Matrix(m,psi,Q_r)
%            Q_r = Q_r*L_L.Eq.gamma_3;
            
            a1 =    -1i*m*L_L.Eq.D1 - 1i/2*m^2*L_L.Eq.D(2) - 1i/2/3*m^3*L_L.Eq.D(3) - 1i/2/3/4*m^4*L_L.Eq.D(4) - 1i*L_L.Eq.delta - L_L.Eq.gamma + 1i*L_L.Eq.gamma_3*(1-L_L.Raman.mu)*2*abs(psi).^2 + 1i*Q_r;  
            a2 =    -1i*m*L_L.Eq.D1 + 1i/2*m^2*L_L.Eq.D(2) - 1i/2/3*m^3*L_L.Eq.D(3) + 1i/2/3/4*m^4*L_L.Eq.D(4) + 1i*L_L.Eq.delta - L_L.Eq.gamma - 1i*L_L.Eq.gamma_3*(1-L_L.Raman.mu)*2*abs(psi).^2 - 1i*Q_r;  
            
            g_1_1   = a1;
            g_1_2   = 1i*psi;
            g_1_3   = 1i*L_L.Eq.gamma_3*(1-L_L.Raman.mu).*psi.^2;
            g_1_4   = 0;
            g_1_5   = 0;
            g_1_6   = 0;
            
            g_2_1   = 0;
            g_2_2   = 0;
            g_2_3   = 0;
            g_2_4   = 0;
            g_2_5   = 1;
            g_2_6   = 0;
            
            g_3_1   = conj(g_1_3);
            g_3_2   = 0;
            g_3_3   = a2;
            g_3_4   = conj(g_1_2);
            g_3_5   = 0;
            g_3_6   = 0;

            g_4_1   = 0;
            g_4_2   = 0;
            g_4_3   = 0;
            g_4_4   = 0;
            g_4_5   = 0;
            g_4_6   = 1;
            
            
            g_5_1   = L_L.Eq.Omega^2*L_L.Raman.mu*L_L.Eq.gamma_3;
            g_5_2   = - L_L.Eq.Omega^2;
            g_5_3   = L_L.Eq.Omega^2*L_L.Raman.mu*L_L.Eq.gamma_3;
            g_5_4   = 0;
            g_5_5   = - 2*L_L.Eq.gamma_r;
            g_5_6   = 0;

            g_6_1   = L_L.Eq.Omega^2*L_L.Raman.mu*L_L.Eq.gamma_3;
            g_6_2   = 0;
            g_6_3   = L_L.Eq.Omega^2*L_L.Raman.mu*L_L.Eq.gamma_3;
            g_6_4   = - L_L.Eq.Omega^2;
            g_6_5   = 0;
            g_6_6   = - 2*L_L.Eq.gamma_r;
            
            M = [g_1_1,g_1_2,g_1_3,g_1_4,g_1_5,g_1_6;
                 g_2_1,g_2_2,g_2_3,g_2_4,g_2_5,g_2_6;
                 g_3_1,g_3_2,g_3_3,g_3_4,g_3_5,g_3_6;
                 g_4_1,g_4_2,g_4_3,g_4_4,g_4_5,g_4_6;
                 g_5_1,g_5_2,g_5_3,g_5_4,g_5_5,g_5_6;
                 g_6_1,g_6_2,g_6_3,g_6_4,g_6_5,g_6_6];
    end
    function  M = Stability_Matrix_Velocity(m,psi,Q_r,V)
            
            a1 =    1i*m*V - 1i/2*m^2*L_L.Eq.D(2) - 1i/2/3*m^3*L_L.Eq.D(3) - 1i/2/3/4*m^4*L_L.Eq.D(4) - 1i*L_L.Eq.delta - L_L.Eq.kappa/2 + 1i*L_L.Eq.gamma_3*(1-L_L.Raman.mu)*2*abs(psi).^2 + 1i*Q_r;  
            a2 =    1i*m*V + 1i/2*m^2*L_L.Eq.D(2) - 1i/2/3*m^3*L_L.Eq.D(3) + 1i/2/3/4*m^4*L_L.Eq.D(4) + 1i*L_L.Eq.delta -L_L.Eq.kappa/2 - 1i*L_L.Eq.gamma_3*(1-L_L.Raman.mu)*2*abs(psi).^2 - 1i*Q_r;  
            
            g_1_1   = a1;
            g_1_2   = 1i*psi;
            g_1_3   = 1i*L_L.Eq.gamma_3*(1-L_L.Raman.mu).*psi.^2;
            g_1_4   = 0;
            g_1_5   = 0;
            g_1_6   = 0;
            
            g_2_1   = 0;
            g_2_2   = 1i*m*(2*pi+V);
            g_2_3   = 0;
            g_2_4   = 0;
            g_2_5   = 1;
            g_2_6   = 0;
            
            g_3_1   = conj(g_1_3);
            g_3_2   = 0;
            g_3_3   = a2;
            g_3_4   = conj(g_1_2);
            g_3_5   = 0;
            g_3_6   = 0;

            g_4_1   = 0;
            g_4_2   = 0;
            g_4_3   = 0;
            g_4_4   = 1i*m*(2*pi+V);
            g_4_5   = 0;
            g_4_6   = 1;
            
            
            g_5_1   = L_L.Eq.Omega^2*L_L.Raman.mu*L_L.Eq.gamma_3;
            g_5_2   = - L_L.Eq.Omega^2;
            g_5_3   = L_L.Eq.Omega^2*L_L.Raman.mu*L_L.Eq.gamma_3;
            g_5_4   = 0;
            g_5_5   = 1i*m*(2*pi+V) - 2*L_L.Eq.gamma_r;
            g_5_6   = 0;

            g_6_1   = L_L.Eq.Omega^2*L_L.Raman.mu*L_L.Eq.gamma_3;
            g_6_2   = 0;
            g_6_3   = L_L.Eq.Omega^2*L_L.Raman.mu*L_L.Eq.gamma_3;
            g_6_4   = - L_L.Eq.Omega^2;
            g_6_5   = 0;
            g_6_6   = 1i*m*(2*pi+V) - 2*L_L.Eq.gamma_r;
            
            M = [g_1_1,g_1_2,g_1_3,g_1_4,g_1_5,g_1_6;
                 g_2_1,g_2_2,g_2_3,g_2_4,g_2_5,g_2_6;
                 g_3_1,g_3_2,g_3_3,g_3_4,g_3_5,g_3_6;
                 g_4_1,g_4_2,g_4_3,g_4_4,g_4_5,g_4_6;
                 g_5_1,g_5_2,g_5_3,g_5_4,g_5_5,g_5_6;
                 g_6_1,g_6_2,g_6_3,g_6_4,g_6_5,g_6_6];
    end
        
end
