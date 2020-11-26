function [CaF_1D_Upper] =  Chi3_Stat_Get_Upper_Branch_Turing_2D(ReS,mu,N_mode,Power_Lim,Delta_Lim,N_Power_Res,N_Delta_Res)

    ReS.Stat.Par.bot_boundary     = min(Delta_Lim); % bottom boundary for delta to search
    ReS.Stat.Par.top_boundary     = max(Delta_Lim); % top boundary for delta to search
    ReS.Stat.Par.i_max            = round((ReS.Stat.Par.top_boundary- ReS.Stat.Par.bot_boundary)/ReS.Stat.Par.first_step);

%%
    delta_s_vec = linspace(min(Delta_Lim),max(Delta_Lim),N_Power_Res);
    
    for i = 1:N_Power_Res
        
          Res = ReS;          
          Res.CW.In.delta = delta_s_vec(i)*Res.CW.In.kappa;          
          Res.CW          = Res.Met.T_MI (Res.CW,2^8);
          power_s_vec(i)  = Res.CW.In.W_MI_Tongue(1,mu+1)*1;
    end
    
    delta_s_vec = delta_s_vec + 0.5;
    
    parfor  i = 1:N_Power_Res
        
        Res = ReS; 
        Res.Stat.In.delta = delta_s_vec(i)*Res.CW.In.kappa;
        Res.Stat.In.P     = power_s_vec(i);
        [Upper,Lower] = Chi3_Stat_Get_Branch_Turing(Res,mu,N_mode);
        CaF_1D_Upper(i) = Upper;
        
    end
    
end