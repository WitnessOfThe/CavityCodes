function  Stat =  Chi3_LLE_Stat_Turing_Starting_Points_CaF_2E3(Res)

    switch Res.Stat.In.mu_bl
        
        case 6

            Power_Start       =                0.00003;
            Delta_Start       =  -6.601*Res.Stat.In.kappa;

        case 7

            Power_Start       =                0.00008054;
            Delta_Start       =  -7.407*Res.Stat.In.kappa;

        case 8

            Power_Start       =      [8.2100e-05,8.2100e-05,2.5133e-06,2.5133e-06];
            Delta_Start       =      [-14.65,-14.65,10,10]*Res.Stat.In.kappa;
            CW_Num            =      [3,3,1,2];
            Sol_Index         =      [1,2,1,1];

        case 9

            Power_Start       =      0.00033;
            Delta_Start       =  -14.32*Res.Stat.In.kappa;
            
        case 10
            
            Power_Start       =   [ 0.000211,0.000211,3.25E-6,1E-5];
            Delta_Start       =   [-23.7,-23.7, 13.5,16]*Res.Stat.In.kappa;
            CW_Num            =   [3,3,2,2];
            Sol_Index         =   [3,4,1,3];
            
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
    
    
    
    for i = 1:size(Delta_Start,2)
        Res_t                 = Res;
        Res_t.Stat.Par.CW_num = CW_Num(i);
        Res_t.Stat.In.delta   = Delta_Start(i);
        Res_t.Stat.In.P       = Power_Start(i);            
        Res_t                 = Res_t.Stat.Met.Sol_In_point(Res_t);  
        
        Stat(i)               = Res_t.Stat(Sol_Index(i));
        
    end
    
end