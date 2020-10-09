function L_L = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW(L_L,N_Mode)

    L_L.CW.In    = L_L.Stat.In;
    
    L_L.CW       = L_L.CW.Met.Norm(L_L.CW,N_Mode);    
    L_L.Stat     = L_L.CW.Met.Norm(L_L.Stat,N_Mode);    
    
    L_L.CW      = MI(L_L.CW,N_Mode);
    L_L.CW.In.g = L_L.CW.Sol.g(L_L.Stat.Par.CW_num)*L_L.Stat.Eq.norm;
    
    L_L.CW      = L_L.CW.Met.Mi_Formula(L_L.CW,L_L.Stat.Space.N); 
    
    L_L.Stat.In.Psi_Start   = ones(1,N_Mode)*1E-5;
    
    ind = find(L_L.CW.An.Omega_mu(1,:) == 0);
    if isempty(ind)
        [~,ind] = max(max(real(L_L.CW.An.lambda_mu(:,:)),[],1));
    end
    if ind ~= 1
        L_L.Stat.In.Psi_Start(ind(1))    = 1;
        L_L.Stat.In.Psi_Start(2*(ind(1)-1)+1)    = 1E-3;
        L_L.Stat.In.Psi_Start(end-ind(1)+2)    = 1;
        L_L.Stat.In.Psi_Start(end-2*(ind(1)-1)+2)    = 1E-3;
    end
    
 %   for i =1:L_L.Stat.Space.N
 %       L_L.Stat.In.Psi_Start(i) = sum(L_L.CW.Stab(3).Vector(i).Vect(3))*1000;
%    end
    L_L.Stat.In.Psi_Start=L_L.Stat.In.Psi_Start*450*(1+1i);
    L_L.Stat.In.Psi_Start(1) = L_L.CW.Sol.Psi(L_L.Stat.Par.CW_num)*L_L.Stat.Space.N;
    
    L_L.Stat.In.t_start      = 0;
    
    x0                       = [real(L_L.Stat.In.Psi_Start),imag(L_L.Stat.In.Psi_Start),0];
    
    [x,eps_f,SolveFlag]      =    L_L.Stat.Met.Newton(L_L.Stat,x0);
    L_L.Stat.Sol.Flag        = SolveFlag;
    L_L.Stat.Sol.eps         =     eps_f
                                   
    L_L.Stat                 = Chi3_LLE_Stat_Prop_Gen(x,L_L.Stat);    
    
end
