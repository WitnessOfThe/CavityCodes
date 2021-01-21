function [Res_1D_Upper,Res_1D_Lower] = Chi3_Stat_Get_Branch_Turing_SiN_FD_02(Res,mu,N_mode)
%  Stat is current resonator
%  mu is the Tongue number
%  N_mode is the number of modes
%  N_Res resolution of finall matrix

    Res.Stat.Met.Newton               = @Newton_Manual_bicgstab;
 %   Res.Stat.Par.step_tol             = 0.00001;
    Res.Stat.Par.Newton_iter          = 30;      
    Res.Stat.Par.Newton_tol           = 1E-10;  
   Res.Stat.Par.CW_num               = 3;
    
%%
    
    switch mu
            
        case 9

            Power_Start       =     0.4;
            Delta_Start       = -5.3*Res.Stat.In.kappa;
            ind_d             = 2;
            ind_u             = 3;
            
        case 43

            Power_Start       =     0.356;
            Delta_Start       = -6*Res.Stat.In.kappa;
            ind_d             = 3;
            ind_u             = 4;
            
        case 44

            Power_Start       =     0.022;
            Delta_Start       =  2.345*Res.Stat.In.kappa;
            ind_d             = 3;
            ind_u             = 4;
    end
    
    Delta_In =  Res.Stat.In.delta; 
    Power_In =  Res.Stat.In.P;     
        

    Res.Stat.In.delta = Delta_Start;
    Res.Stat.In.P     = Power_Start;    
    Res_Start         = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW_Defined(...
                                                      Res,N_mode,[mu,-mu]);   
    
%%
    NN = 30;
    
    delta_vector = linspace(Delta_Start,Delta_In,NN); 
    power_vector = linspace(Power_Start,Power_In,NN); 
   
    Res_Upper                      = Res;
    Res_Upper.Stat                 = Res_Start.Stat(ind_u);    
    Res_Upper.Stat.In.Psi_Start    = Res_Start.Stat(ind_u).Sol.Psi_k;    
    Res_Upper.Stat                 =  Chi_3_Stat_Wierd_Pattern_Tracking(...
                                 Res_Upper.Stat,delta_vector,power_vector);
        
    
    Res_Lower                           = Res;
    
    Res_Lower.Stat                 = Res_Start.Stat(ind_d);    
    Res_Lower.Stat.In.Psi_Start    = Res_Start.Stat(ind_d).Sol.Psi_k;    
    Res_Lower.Stat                 =  Chi_3_Stat_Wierd_Pattern_Tracking(...
                                 Res_Lower.Stat,delta_vector,power_vector);
                             
                            
    Res_1D_Upper(1).Stat = Run_Branch_Universal(Res_Upper.Stat(end),N_mode);  
    Res_1D_Lower(1).Stat = Run_Branch_Universal(Res_Lower.Stat(end),N_mode);  
          

end

