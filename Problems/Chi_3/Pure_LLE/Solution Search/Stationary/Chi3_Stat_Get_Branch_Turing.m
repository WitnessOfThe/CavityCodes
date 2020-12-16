function Res_Branches = Chi3_Stat_Get_Branch_Turing(Res,Delta_Start,Index_Start)
%  Stat is current resonator
%  mu is the Tongue number
%  N_mode is the number of modes
%  N_Res resolution of finall matrix

    
%%
    Stat_Start    = Res.Stat.Met.Branch_Starting_points(Res,Index_Start);
    
%%
    NN = 100;
    
    for i_c =1:size(Delta_Start,2)
        
        delta_s_vec(i_c,:) = linspace(Stat_Start(i_c).In.delta,Delta_Start(i_c),NN);    
        power_s_vec(i_c,:) = linspace(Stat_Start(i_c).In.P,Res.Stat.In.P,NN);    
        
    end
        
    for i = 1:size(Stat_Start,2)
        
        Res_Adj(i)                     = Res;
        Res_Adj(i).Stat                = Stat_Start(i);
        Res_Adj(i).Stat.In.Psi_Start   = Stat_Start(i).Sol.Psi_k;    
        Res_Adj(i).Stat                = Chi_3_Stat_Wierd_Pattern_Tracking(...
        Res_Adj(i).Stat,delta_s_vec(i,:),power_s_vec(i,:));
    
    end
   
    parfor i = 1:size( Stat_Start,2)
        
        Res_Branches(i) = Res;       
        Res_Branches(i).Stat = Run_Branch_Universal( Res_Adj(i).Stat(end));          
        
    end

end

