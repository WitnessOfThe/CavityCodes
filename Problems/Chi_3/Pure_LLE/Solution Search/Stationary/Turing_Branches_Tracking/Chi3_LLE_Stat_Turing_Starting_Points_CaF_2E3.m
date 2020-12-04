function  Stat =  Chi3_LLE_Stat_Turing_Starting_Points_CaF_2E3(Res,Index_Start)

    switch Res.Stat.In.mu_bl
%             Power_Start       =      [,, , ];
%             Delta_Start       =      [,,,]*Res.Stat.In.kappa;
%             CW_Num            =      [,,,];
%             Sol_Index         =      [,,,];
        case 4
            Power_Start       =      [6.7021e-06,3.8872e-06, 8.3776e-05,  8.3776e-05];
            Delta_Start       =      [-3,-2.34,3,10]*Res.Stat.In.kappa;
            CW_Num            =      [3,3,1,2];
            Sol_Index         =      [1,1,2,4];
        case 5

            Power_Start       =      [1.5080e-05, 1.1058e-05,  4.1888e-05, 8.3776e-05 ];
            Delta_Start       =      [-5,-5.093,5.5,11.65]*Res.Stat.In.kappa;
            CW_Num            =      [3,3,1,2];
            Sol_Index         =      [3,3,1,2];

        
        case 6

            Power_Start       =      [2.5133e-05,2.5133e-05,1.1729e-06 ,8.3776e-05 ];
            Delta_Start       =      [-7.635,-7.635,6.2,12]*Res.Stat.In.kappa;
            CW_Num            =      [3,3,1,2];
            Sol_Index         =      [1,3,1,2];

        case 7

            Power_Start       =      [4.6914e-05,4.6914e-05, 8.3776e-05,  8.3776e-05];
            Delta_Start       =      [-11,-11,1,12.2]*Res.Stat.In.kappa;
            CW_Num            =      [3,3,1,2];
            Sol_Index         =      [1,2,1,1];

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

        case 16

            Power_Start       =      [8.3776e-05,8.3776e-05];
            Delta_Start       =      [35.54,35.54]*Res.Stat.In.kappa;
            CW_Num            =      [1,2];
            Sol_Index         =      [1,3];
            
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
    
    
    ii =0;
    for i = Index_Start
        ii = ii+1;
        Res_t                 = Res;
        Res_t.Stat.Par.CW_num = CW_Num(i);
        Res_t.Stat.In.delta   = Delta_Start(i);
        Res_t.Stat.In.P       = Power_Start(i);            
        Res_t                 = Res_t.Stat.Met.Sol_In_point(Res_t);  
        
        Stat(ii)               = Res_t.Stat(Sol_Index(i));
        
    end
    
end