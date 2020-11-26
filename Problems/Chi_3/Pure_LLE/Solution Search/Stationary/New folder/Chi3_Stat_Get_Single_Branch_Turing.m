function [Res_1D_Upper] = Chi3_Stat_Get_Single_Branch_Turing(Res,mu,N_mode)
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
        case 6
            
            Power_Start       =                0.00003;
            Delta_Start       =  -6.601*Res.Stat.In.kappa;
        
        case 7
            
            Power_Start       =                0.00008054;
            Delta_Start       =  -7.407*Res.Stat.In.kappa;
            
        case 8
            
            Power_Start       =      0.0002;
            Delta_Start       =  -8.28*Res.Stat.In.kappa;
        
        case 9
            
            Power_Start       =      0.00033;
            Delta_Start       =  -14.32*Res.Stat.In.kappa;
            
        case 10
            
            Power_Start       =       0.0005779;
            Delta_Start       = -0.03668E6*2*pi;
            
        case 11
            
            Power_Start       =      0.001;
            Delta_Start       =  -23.11*Res.Stat.In.kappa;

        case 34
            
            Power_Start       =     0.15;
            Delta_Start       =  -280*Res.Stat.In.kappa;
            
        case 35
            
            Power_Start       =     0.15;
            Delta_Start       =  -298.5*Res.Stat.In.kappa;
            
        case 60

            Power_Start       =     1.007;
            Delta_Start       =  -892.25*Res.Stat.In.kappa;
        
    end
    
    Delta_In =  Res.Stat.In.delta; 
    Power_In =  Res.Stat.In.P;     
        

    Res.Stat.In.delta = Delta_Start;
    Res.Stat.In.P     = Power_Start;    
    Res_Start         = Res.Stat.Met.Sol_In_point(...
                                                      Res,N_mode,[Res.Stat.In.mu_bl,-Res.Stat.In.mu_bl]);   
    
%%
    NN = 30;
    
    delta_vector = linspace(Delta_Start,Delta_In,NN); 
    power_vector = linspace(Power_Start,Power_In,NN); 
   
    Res_Upper                      = Res;
    Res_Upper.Stat                 = Res_Start.Stat(1);    
    Res_Upper.Stat.In.Psi_Start    = Res_Start.Stat(1).Sol.Psi_k;    
    Res_Upper.Stat                 =  Chi_3_Stat_Wierd_Pattern_Tracking(...
                                 Res_Upper.Stat,delta_vector,power_vector);
        
    
                             
                            
    Res_1D_Upper(1).Stat = Run_Branch_Universal(Res_Upper.Stat(end),N_mode);  
          

end

