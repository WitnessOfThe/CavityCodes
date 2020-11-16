function [CaF_1D_Upper,CaF_1D_Lower] =  Chi3_Stat_Get_Branch_Turing_2D(CaF,mu,N_mode,Power_Lim,Delta_Lim,N_Power_Res,N_Delta_Res)

    CaF.Stat.Par.bot_boundary     = -300; % bottom boundary for delta to search
    CaF.Stat.Par.top_boundary     = -260; % top boundary for delta to search
    CaF.Stat.Par.i_max            = 200;

%%
    delta_s_vec = linspace(min(Delta_Lim),max(Delta_Lim),N_Power_Res);
    
    for i = 1:N_Power_Res
        
          Res = CaF;          
          Res.CW.In.delta = delta_s_vec(i)*Res.CW.In.kappa;          
          Res.CW          = Res.Met.T_MI (Res.CW,N_mode);
          power_s_vec(i)  = Res.CW.In.W_MI_Tongue(2,mu+1)*0.98;
    end
    

    parfor  i = 1:N_Power_Res
        
        Res = CaF; 
        Res.Stat.In.delta = delta_s_vec(i)*Res.CW.In.kappa;
        Res.Stat.In.P     = power_s_vec(i);
        [Upper,Lower] = Chi3_Stat_Get_Branch_Turing(Res,mu,N_mode);
        CaF_1D_Upper(i) = Upper;
        CaF_1D_Lower(i) = Lower;
        
    end
    
end