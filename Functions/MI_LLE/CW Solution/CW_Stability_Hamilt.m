function L_L = CW_Stability_Hamilt(L_L)   
    Value = zeros(1,2*L_L.Space.N);
    
    for j = 1:3
        if isnan(L_L.Solution.CW.Psi(j)) ~= 1
            
            for i=1:L_L.Space.N
                tt = eig(Stability_Matrix(L_L.Space.k(i),L_L.Solution.CW.Psi(j)));
                Value(i)              = tt(1);
                Value(L_L.Space.N+i)  = tt(2);
            end
            
                L_L.Solution.CW.Stability(j).Value          = Value;
                L_L.Solution.CW.Stability(j).Max_Groth_Rate = max(real(Value)); 
       else
           L_L.Solution.CW.Stability(j).Value          = NaN(1,2*L_L.Space.N);
           L_L.Solution.CW.Stability(j).Max_Groth_Rate = NaN;
        end
       
    end


    function  M = Stability_Matrix(m,psi)
        
            g_1_1   = -1i*m.^2.*pi*L_L.Eq.d - 1i*L_L.Eq.delta + 2*1i.*abs(psi).^2*L_L.Eq.gamma_3;
            g_1_2   = 1i.*psi.^2*L_L.Eq.gamma_3;
            
            g_2_1   = conj(g_1_2);
            g_2_2   = conj(g_1_1);
            
            
            M = [g_1_1,g_1_2;
                g_2_1,g_2_2];
 
    end
        
end
