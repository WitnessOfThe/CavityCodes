function L_L = Chi_3_Stat_In_Guess_LLE_From_CW_2_phases(L_L,N_Mode)

    L_L.CW.In    = L_L.Stat.In;
    
    L_L.CW       = L_L.CW.Met.Norm(L_L.CW,N_Mode);    
    L_L.Stat     = L_L.CW.Met.Norm(L_L.Stat,N_Mode);    
    
    L_L.CW      = MI(L_L.CW,N_Mode);
    L_L.CW.In.g = L_L.CW.Sol.g(L_L.Stat.Par.CW_num)*L_L.Stat.Eq.norm;
    
    L_L.CW      = L_L.CW.Met.Mi_Formula(L_L.CW,L_L.Stat.Space.N); 
    
    L_L.Stat.In.Psi_Start   = zeros(1,N_Mode)*1E-5;
    
    ind = find(L_L.CW.An.Omega_mu(1,:) == 0);
    
    if isempty(ind)
        [~,ind] = max(max(real(L_L.CW.An.lambda_mu(:,:)),[],1));
    end
    
    if ind ~= 1
        
        L_L.Stat.In.Psi_Start(ind(1))                = 1;
      %  L_L.Stat.In.Psi_Start(2*(ind(1)-1)+1)        = 1E-3;
        L_L.Stat.In.Psi_Start(end-ind(1)+2)          = 1;
    %    L_L.Stat.In.Psi_Start(end-2*(ind(1)-1)+2)    = -1i*1E-3;
        
    end
    
    L_L.Stat.In.Psi_Start(1) = L_L.CW.Sol.Psi(L_L.Stat.Par.CW_num);    
    x0                       = [real(L_L.Stat.In.Psi_Start),imag(L_L.Stat.In.Psi_Start),0]*L_L.Stat(1).Space.N;   
    [x,eps_f,SolveFlag]      =    L_L.Stat.Met.Newton(L_L.Stat,x0);
    
    L_L.Stat.Sol.Flag        = SolveFlag;
    L_L.Stat.Sol.eps         =     eps_f;
    eps_f
    
    L_L.Stat                 = Chi3_LLE_Stat_Prop_Gen(x,L_L.Stat);    
    
    L_L.Stat(2)             = L_L.Stat(1); 
    
    L_L.Stat(2).In.Psi_Start   = zeros(1,N_Mode)*1E-5;
   if ind ~= 1
        
        L_L.Stat(2).In.Psi_Start(ind(1))             =  1i;
     %   L_L.Stat(2).In.Psi_Start(2*(ind(1)-1)+1)     = 1E-3;
        L_L.Stat(2).In.Psi_Start(end-ind(1)+2)       =  1;
      %  L_L.Stat(2).In.Psi_Start(end-2*(ind(1)-1)+2) = 1E-3;
        
    end
    
    L_L.Stat(2).In.Psi_Start(1) = L_L.CW.Sol.Psi(L_L.Stat(2).Par.CW_num);    
    
    x0                       =   [real(L_L.Stat(2).In.Psi_Start),imag(L_L.Stat(2).In.Psi_Start),0]*L_L.Stat(2).Space.N;   
    [x,eps_f,SolveFlag]      =    L_L.Stat(2).Met.Newton(L_L.Stat(2),x0);
    
    L_L.Stat(2).Sol.Flag        = SolveFlag;
    L_L.Stat(2).Sol.eps         =     eps_f;
    eps_f
                                   
    L_L.Stat(2)                 = Chi3_LLE_Stat_Prop_Gen(x,L_L.Stat(2));    

end
