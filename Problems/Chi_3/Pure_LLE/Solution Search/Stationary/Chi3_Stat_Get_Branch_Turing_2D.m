function [CaF_1D_Upper,CaF_1D_Lower] =  Chi3_Stat_Get_Branch_Turing_2D(ReS,mu,N_mode,Power_Lim,Delta_Lim,N_Power_Res,N_Delta_Res)

    ReS.Stat.Par.bot_boundary     = min(Delta_Lim); % bottom boundary for delta to search
    ReS.Stat.Par.top_boundary     = max(Delta_Lim); % top boundary for delta to search
    ReS.Stat.Par.i_max            = (ReS.Stat.Par.top_boundary- ReS.Stat.Par.bot_boundary)/ReS.Stat.Par.first_step;

%%
    delta_s_vec = linspace(min(Delta_Lim),max(Delta_Lim),N_Power_Res);
    
    for i = 1:N_Power_Res
        
          Res = ReS;          
          Res.CW.In.delta = delta_s_vec(i)*Res.CW.In.kappa;          
          Res.CW          = Res.Met.T_MI (Res.CW,N_mode);
          power_s_vec(i)  = Res.CW.In.W_MI_Tongue(2,mu+1)*0.99;
    end
    

    parfor  i = 1:N_Power_Res
        
        Res = ReS; 
        Res.Stat.In.delta = delta_s_vec(i)*Res.CW.In.kappa;
        Res.Stat.In.P     = power_s_vec(i);
        [Upper,Lower] = Chi3_Stat_Get_Branch_Turing(Res,mu,N_mode);
        CaF_1D_Upper(i) = Upper;
        CaF_1D_Lower(i) = Lower;
        
    end
    
end