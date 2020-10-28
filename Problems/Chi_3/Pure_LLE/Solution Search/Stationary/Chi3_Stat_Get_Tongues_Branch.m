function [Res_2D_Upper,Res_2D_Lower] = Chi3_Stat_Get_Tongues_Branch(Res,mu,N_mode,N_res)
%  Stat is current resonator
%  mu is the Tongue number
%  N_mode is the number of modes
%  N_Res resolution of finall matrix

    Res.Stat.Met.Newton               = @Newton_Manual_bicgstab;
    Res.Stat.Par.step_tol             = 0.00001;
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

        
    end
    
    
    Delta_origin        = sqrt(3)/2*Res.Stat.In.kappa -1/2*mu^2*Res.Stat.In.D(2); 
    g_kappa             = 1/sqrt(3);
    gammaH2kappa        = g_kappa+4*g_kappa*(Delta_origin/Res.Stat.In.kappa - g_kappa).^2;
    PowerOrigin         = gammaH2kappa*pi*Res.Stat.In.kappa^2/( Res.Stat.In.eta*Res.Stat.In.D(1)*Res.Stat.In.gamma );

    Delta_min           = 1*Res.Stat.In.kappa -1/2*mu^2*Res.Stat.In.D(2); 
    g_kappa             = 1/2;
    gammaH2kappa        = g_kappa+4*g_kappa*(Delta_min/Res.Stat.In.kappa - g_kappa).^2;
    PowerMin            = gammaH2kappa*pi*Res.Stat.In.kappa^2/( Res.Stat.In.eta*Res.Stat.In.D(1)*Res.Stat.In.gamma );
    
    F_d                 = Res.Stat.In.D(2)/Res.Stat.In.kappa;
    
    mu                  = mu-1;
    alpha_mu            = F_d*(mu+1/2);    
    Delta_Casp          = Res.Stat.In.kappa*( sqrt(1+alpha_mu^2) - alpha_mu/2 - 1/2*mu^2*F_d ); 
    mu                  = mu+1;
    Delta_mu_kap        = (Delta_Casp + 1/2*mu^2*Res.Stat.In.D(2))/Res.Stat.In.kappa;
    g_kappa             = 2/3*Delta_mu_kap - 1/3*sqrt(Delta_mu_kap^2- 3/4  );
    gammaH2kappa        = g_kappa+4*g_kappa*(Delta_Casp/Res.Stat.In.kappa - g_kappa).^2;
    PowerCasp            = gammaH2kappa*pi*Res.Stat.In.kappa^2/( Res.Stat.In.eta*Res.Stat.In.D(1)*Res.Stat.In.gamma );

    
%%

    Res.Stat.In.delta = Delta_Start;
    Res.Stat.In.P     = Power_Start;    
    Res_Start         = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW_Defined(...
                                                      Res,N_mode,[mu,-mu]);   
    
%%
    NN = 15;
    
%    delta_vector = linspace(Delta_Start,Delta_Casp,NN); 
 %   power_vector = linspace(Power_Start,PowerOrigin,NN);  
     delta_vector = linspace(Delta_Start,Delta_Casp,NN); 
    power_vector = linspace(Power_Start,PowerCasp-0.000001,NN); 
   
    Res_Upper                      = Res;
    Res_Upper.Stat                 = Res_Start.Stat(1);    
    Res_Upper.Stat.In.Psi_Start    = Res_Start.Stat(1).Sol.Psi_k;    
    Res_Upper.Stat                 =  Chi_3_Stat_Wierd_Pattern_Tracking(...
                                 Res_Upper.Stat,delta_vector,power_vector);
        
%    delta_vector = linspace(Delta_Casp,Delta_origin,N_res); 
%    power_vector = linspace(PowerOrigin,PowerOrigin,N_res);  
     delta_vector = linspace(Delta_Casp,Delta_Casp,N_res); 
    power_vector = linspace(PowerCasp-0.000001,PowerMin,N_res);  
   
    Res_Upper.Stat(1)              = Res_Upper.Stat(end);    
    Res_Upper.Stat(1).In.Psi_Start = Res_Upper.Stat(end).Sol.Psi_k;    
    Res_Upper.Stat                 =  Chi_3_Stat_Wierd_Pattern_Tracking(...
                                 Res_Upper(1).Stat,delta_vector,power_vector);
                             
    delta_vector = linspace(Delta_Start,Delta_Casp,NN); 
    power_vector = linspace(Power_Start,PowerCasp-0.000001,NN); 
    
    Res_Lower                           = Res;
    
    Res_Lower.Stat                 = Res_Start.Stat(2);    
    Res_Lower.Stat.In.Psi_Start    = Res_Start.Stat(2).Sol.Psi_k;    
    Res_Lower.Stat                 =  Chi_3_Stat_Wierd_Pattern_Tracking(...
                                 Res_Lower.Stat,delta_vector,power_vector);
                             
    delta_vector = linspace(Delta_Casp,Delta_origin-(Delta_origin-Delta_Casp)/4,N_res); 
    power_vector = linspace(PowerCasp-0.000001,PowerMin,N_res);  
                             
    Res_Lower.Stat(1)              = Res_Lower.Stat(end);    
    Res_Lower.Stat(1).In.Psi_Start = Res_Lower.Stat(end).Sol.Psi_k;    
    Res_Lower.Stat                 =  Chi_3_Stat_Wierd_Pattern_Tracking(...
                                 Res_Lower(1).Stat,delta_vector,power_vector);
                             
%%    
    parfor i = 1:N_res
        
        Res_2D_Upper(i).Stat = Run_Branch_Universal(Res_Upper.Stat(i),N_mode);  
        
    end

%%   
% for i=1:size(Res_Lower.Stat,2)
%     
%    Mode_Power_L(i,:)    = Res_Lower.Stat(i).Sol.Psi_k([11]);
%    delta_vector_L(i)    = Res_Lower.Stat(i).Eq.delta;
%    Power_vector_L(i)    = Res_Lower.Stat(i).In.P;
%     
% end
% 
% figure;
% %    plot(delta_vector_L,abs(Mode_Power_L).^2);hold on
% %    plot(delta_vector_U,abs(Mode_Power_U).^2)
%     plot(Power_vector_L,abs(Mode_Power_L).^2);hold on
% %    plot(Power_vector_U,abs(Mode_Power_U).^2)

%%
    parfor i = 1:N_res
        
        Res_2D_Lower(i).Stat = Run_Branch_Universal(Res_Lower.Stat(i),N_mode);  
        
    end
end

