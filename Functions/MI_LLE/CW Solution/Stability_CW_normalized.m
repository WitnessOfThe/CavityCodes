function L_L = Stability_CW_normalized(L_L)
   delta_o = L_L.Eq.delta_o;
   delta_e = 2*L_L.Eq.delta_o - L_L.Eq.epsilon;
   
    Value = zeros(L_L.Space.N,4);

    for j = 1:3
        if L_L.Solution.CW.Psi_s(j) ~= 0 + 1i*0
            for i=1:L_L.Space.N
                %SHG_MI_X_CORE_MF(m,L_L.Eq.delta_o,L_L.Eq.delta_e,L_L.Eq.Omega_R,L_L.Eq.D1_o,L_L.Eq.D1_e,L_L.Eq.D2_o,L_L.Eq.D2_e,L_L.Eq.k_o,L_L.Eq.k_e,L_L.Eq.gamma2_o,L_L.Eq.gamma2_e)
%
 %               Value(i,:) = eig(SHG_MI_X_CORE_MF(L_L.Space.k(i),L_L.Eq.delta_o,L_L.Eq.delta_e,L_L.Eq.Omega_R.^2,L_L.Eq.D1_o,L_L.Eq.D1_e,L_L.Eq.D2_o,L_L.Eq.D2_e,L_L.Eq.k_o,L_L.Eq.k_e,L_L.Eq.gamma2_o,L_L.Eq.gamma2_e));
                Value(i,:) = eig(Stability_Matrix(L_L.Space.k(i),L_L.Solution.CW.Psi_p(j),L_L.Solution.CW.Psi_s(j)));
                [L_L.Solution.CW.Stability(j).Groth_rate(i),~] = max(real(Value(i,:)));
                L_L.Solution.CW.Stability(j).Groth_rate_ind(i) = L_L.Space.k(i);
                
            end
                 L_L.Solution.CW.Stability(j).Value = Value;
                [L_L.Solution.CW.Max_Groth_rate(j),tt] = max(real(L_L.Solution.CW.Stability(j).Groth_rate));
                L_L.Solution.CW.Max_Groth_rate_ind(j) = L_L.Space.k(tt);
        else
            L_L.Solution.CW.Stability(j).Value          = NaN(L_L.Space.N,4);
            L_L.Solution.CW.Stability(j).Groth_rate     = NaN;
            L_L.Solution.CW.Stability(j).Groth_rate_ind = NaN;
        end
    end


%     function M = Stability_Matrix(m,psi_p,psi_s)
%         
%         M = -1i*[delta_o + 1/2*L_L.Eq.D2_o.*m.^2 - 1i*L_L.Eq.k_o ,- L_L.Eq.gamma2_o*psi_s, - L_L.Eq.gamma2_o*conj(psi_p), 0;
%                                   L_L.Eq.gamma2_o*conj(psi_s), - ( delta_o + 1/2*L_L.Eq.D2_o.*m.^2 + 1i*L_L.Eq.k_o ), 0                            , L_L.Eq.gamma2_o*psi_p;
%              - 2*L_L.Eq.gamma2_e*psi_p,                              0,delta_e + 1/2*L_L.Eq.D2_e.*m.^2 + m*L_L.Eq.d - 1i*L_L.Eq.k_e,0;
%                                      0,  2*L_L.Eq.gamma2_e*conj(psi_p), 0                                                           , -(delta_e + 1/2*L_L.Eq.D2_e.*m.^2 - m*L_L.Eq.d + 1i*L_L.Eq.k_e)];  
%     end
function MI_matrix = SHG_MI_X_CORE_MF(mode,delta_o,delta_e,x,D1_o,D1_e,D2_o,D2_e,kappa_o,kappa_e,gamma2_o,gamma2_e)
%    MI_matrix        = struct;
 %   MI_matrix.lambda = NaN(1,4);
  %  MI_matrix.vector = NaN(4,4);
   % MI_matrix.matrix = NaN(4,4);

    omega_o_pos = delta_o + 0.5 * D2_o * (mode^2);
    omega_o_neg = delta_o + 0.5 * D2_o * (mode^2); 
    omega_e_pos = delta_e + (D1_e - D1_o) * mode + 0.5 * D2_e * (mode^2);
    omega_e_neg = delta_e - (D1_e - D1_o) * mode + 0.5 * D2_e * (mode^2);

    psi_o = sqrt(x / (gamma2_o * gamma2_e));
    psi_e = x / (gamma2_o * sqrt(delta_e^2+kappa_e^2));

    MI_matrix = -1i* [ omega_o_pos-1i*kappa_o,           -gamma2_o*psi_e,          -gamma2_o*psi_o,                        0; 
                                 gamma2_o*psi_e,   -omega_o_neg-1i*kappa_o,                        0,           gamma2_o*psi_o; 
                              -2*gamma2_e*psi_o,                         0,   omega_e_pos-1i*kappa_e,                        0; 
                                              0,          2*gamma2_e*psi_o,                        0,  -omega_e_neg-1i*kappa_e];
  %  [MI_matrix.vector, MI_matrix.lambda] = eig(MI_matrix.matrix);
   %  MI_matrix.lambda                    = diag(MI_matrix.lambda)/1i;
end
    function M = Stability_Matrix(m,psi_p,psi_s)
        phi =0;% 2*angle(psi_p)-angle(psi_s); 
    M = -1i*[delta_o + 1/2*L_L.Eq.D2_o.*m.^2 - 1i*L_L.Eq.k_o ,                                      - L_L.Eq.Omega_R, - L_L.Eq.Omega_R.^2/L_L.Eq.Omega_R_e.*exp(-1i*phi),                                                     0;
                                             - L_L.Eq.Omega_R,   delta_e + 1/2*L_L.Eq.D2_e.*m.^2 +  m*L_L.Eq.d - 1i*L_L.Eq.k_e ,                                  0,                                                     0;
                           L_L.Eq.Omega_R.^2/L_L.Eq.Omega_R_e.*exp(1i*phi),                                                     0,-(delta_o + 1/2*L_L.Eq.D2_o.*m.^2  )-1i*L_L.Eq.k_o,L_L.Eq.Omega_R;
                                                            0,                                                     0, L_L.Eq.Omega_R , -(delta_e + 1/2*L_L.Eq.D2_e.*m.^2 - m*L_L.Eq.d )- 1i*L_L.Eq.k_e];  
    end
%     function M = Stability_Matrix(m,psi_p,psi_s)
%         
%         M = -1i*[L_L.Eq.L_o(i) ,- L_L.Eq.gamma2_o*psi_s, - L_L.Eq.gamma2_o*conj(psi_p), 0;
%                                   L_L.Eq.gamma2_o*conj(psi_s), - conj(L_L.Eq.L_o(i) ), 0                            , L_L.Eq.gamma2_o*psi_p;
%              - 2*L_L.Eq.gamma2_e*psi_p,                              0,L_L.Eq.Lj_e(i),0;
%                                      0,  2*L_L.Eq.gamma2_e*conj(psi_p), 0                                                           , -conj(L_L.Eq.L_e(i))];  
%     end
end

