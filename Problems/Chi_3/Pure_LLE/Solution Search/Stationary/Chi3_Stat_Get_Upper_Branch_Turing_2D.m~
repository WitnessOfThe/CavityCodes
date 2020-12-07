function CaF_1D_Upper =  Chi3_Stat_Get_Upper_Branch_Turing_2D(ReS,Power_Lim,Delta_Lim,N_Power_Res,N_Delta_Res)

%    ReS.Stat.Par.bot_boundary     = min(Delta_Lim);                         % bottom boundary for delta to search
%    ReS.Stat.Par.top_boundary     = max(Delta_Lim);                         % top boundary for delta to search
%    ReS.Stat.Par.i_max            = round((ReS.Stat.Par.top_boundary - ReS.Stat.Par.bot_boundary)/ReS.Stat.Par.first_step);

%%
    delta_s_vec = linspace(min(Delta_Lim),max(Delta_Lim),N_Delta_Res); 
    power_s_vec = linspace(min(Power_Lim),max(Power_Lim),N_Power_Res); 
    
    Delta_Start         = 10*ReS.Stat.In.kappa;
    Index_Start         = 3;%,2,3,4  
                              % ,-6.3,10,13
    parfor  i = 1:N_Power_Res
        
        Res               = ReS; 
        Res.Stat.In.delta = delta_s_vec(i)*Res.CW.In.kappa;
        Res.Stat.In.P     = power_s_vec(i);
        CaF_1D_Upper(i)   = Chi3_Stat_Get_Branch_Turing(Res,Delta_Start,Index_Start);
        
    end
    
end