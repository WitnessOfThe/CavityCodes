function L_L = CW_Stability_Kerr(L_L)   
    Value = zeros(1,2*L_L.Space.N);
    
    for j = 1:3
        if isnan(L_L.Solution.CW.Psi(j)) ~= 1
            
            for i=1:L_L.Space.N
                tt = eig(Stability_Matrix(L_L.Space.k(i),L_L.Solution.CW.Psi(j),0,i));
                Value(i)              = tt(1);
                Value(L_L.Space.N+i)  = tt(2);
            end
            
                L_L.Solution.CW.Stability(j).Value          = Value;
                [L_L.Solution.CW.Stability(j).Max_Groth_Rate,Index] = max(real(Value));
                tt = [L_L.Space.k,L_L.Space.k];
                L_L.Solution.CW.Stability(j).k                      = tt(Index); 
       else
           L_L.Solution.CW.Stability(j).Value          = NaN(1,2*L_L.Space.N);
           L_L.Solution.CW.Stability(j).Max_Groth_Rate = NaN;
           L_L.Solution.CW.Stability(j).k              = NaN;
        end
       
    end


    function  M = Stability_Matrix(m,psi,V,i)
        
            g_1_1   = 1i*V*m-1i*m.^2.*L_L.Eq.D(2)/2  - 1i*1/6*m.^3.*L_L.Eq.D(3) - 1i*1/6/4*m.^4.*L_L.Eq.D(4) - 1i*L_L.Eq.delta - L_L.Eq.Shifted.kappa_vector(i)/2  + 2*1i.*abs(psi).^2*L_L.Eq.Shifted.gamma_Kerr(i);
            g_1_2   = 1i.*psi.^2*L_L.Eq.Shifted.gamma_Kerr(i);
            
            g_2_1   = conj(g_1_2);
            g_2_2   = 1i*V*m +1i*m.^2.*L_L.Eq.D(2)/2  - 1i*1/6*m.^3.*L_L.Eq.D(3) + 1i*1/6/4*m.^4.*L_L.Eq.D(4) + 1i*L_L.Eq.delta -L_L.Eq.Shifted.kappa_vector(i)/2 - 2*1i.*abs(psi).^2*L_L.Eq.Shifted.gamma_Kerr(i);
            
            
            M = [g_1_1,g_1_2;
                g_2_1,g_2_2];
 
    end
        
end
