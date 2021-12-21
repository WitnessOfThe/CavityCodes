function L_L =  Chi3_LLE_Start_Point_Bloch(L_L)
    
    L_L.Temp.In.Psi_Start          = zeros(1,L_L.Temp.Space.N);
    L_L.Temp.In.Psi_Start          = L_L.Stat.Sol.Psi_k;
    
%    for i = 1:floor(L_L.Temp.Space.N/2/L_L.Stat.In.mu_bl)
 %       L_L.Temp.In.Psi_Start(L_L.Temp.Space.k == L_L.Stat.Space.k(i))  = L_L.Stat.Sol.Psi_k(i);
  %      L_L.Temp.In.Psi_Start(L_L.Temp.Space.k == L_L.Stat.Space.k(end-i+1))= L_L.Stat.Sol.Psi_k(end-i+1);        
   % end
    
    L_L.Temp.In.Psi_Start = (L_L.Temp.In.Psi_Start+1E-9*rand(1,L_L.Temp.Space.N))*L_L.Temp.Space.N;
    L_L.Temp.In.t_start   = 0;
    
end
