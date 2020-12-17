function  Stat =  Chi3_LLE_Stat_Turing_Starting_Points_CaF_2E3(Res,Index_Start)

    switch Res.Stat.In.mu_bl
%             Power_Start       =      [,, , ];
%             Delta_Start       =      [,,,]*Res.Stat.In.kappa;
%             CW_Num            =      [,,,];
%             Sol_Index         =      [,,,];
        case 1
            
            Power_Start       =      [4.188790204786390e-07,4.188790204786390e-07,2.261946710584651e-07,1.189616418159335e-07,1.440943830446518e-07,4.188790204786390e-07,4.188790204786390e-07,...
                4.188790204786390e-07,2.563539605329271e-07,8.360825248753635e-05];
            Delta_Start       =      [1.97,1.5,1.3,0.81,0.941,1.38,1.96...
                        ,0.941,1.51,1.93,397]*Res.Stat.In.kappa;
            Function_start    =      {@fsolve,@fsolve,@fsolve,@fsolve,@fsolve,@fsolve,@fsolve};
            Pert_Amplitude    =      [0.12,0.12,0.12,0.1,0.2,0.3,0.2,...
                                    0.14,0.14,0.8];
            
            CW_Num            =      [1,2,1,1,1,1,1,...
                                                    1,1];
            Sol_Index         =      [2,1,1,1,2,3,3,...
                                                   1,2];
            
        case 2
            
            Power_Start       =      [4.188790204786390e-07,4.188790204786390e-07];
            Delta_Start       =      [0,1.6]*Res.Stat.In.kappa;
            Function_start    =      {@fsolve,@fsolve};
            Pert_Amplitude    =      [0.1,0.1];
            
            CW_Num            =      [3,2];
            Sol_Index         =      [1,1];
            
        case 3
            
            Power_Start       =      [4.188790204786390e-07,4.188790204786390e-07];%[8.377580409572782e-05,8.377580409572782e-05,2.345722514680379e-06];
            Delta_Start       =      [0.18,1.85]*Res.Stat.In.kappa;%[9.7,17,3]*Res.Stat.In.kappa;
            Function_start    =      {@Newton_Manual_bicgstab,@fsolve};%{@Newton_Manual_bicgstab,@fsolve,@fsolve};
            Pert_Amplitude    =      [0.1,0.1];
            
            CW_Num            =      [1,2];%[2,1,1];
            Sol_Index         =      [1,1];%[1,1,1];
            
        case 4
            
            Power_Start       =      [4.188790204786390e-07,4.188790204786390e-07];%[8.377580409572782e-05,8.377580409572782e-05,2.345722514680379e-06];
            Delta_Start       =      [1.63,2.38]*Res.Stat.In.kappa;%[9.7,17,3]*Res.Stat.In.kappa;
            Function_start    =      {@fsolve,@fsolve};%{@Newton_Manual_bicgstab,@fsolve,@fsolve};
            Pert_Amplitude    =      [0.1,0.1];
            
            CW_Num            =      [1,2];%[2,1,1];
            Sol_Index         =      [1,1];%[1,1,1];
            
%            Power_Start       =      [5.8643e-06,3.518583772020568e-07,2.513274122871834e-06,8.377580409572782e-05,8.377580409572782e-05];
%            Delta_Start       =      [-3.1,2,3.68,9.792,2.5]*Res.Stat.In.kappa;
%            CW_Num            =      [3,1,2,2,1];
%            Sol_Index         =      [1,3,1,4,2];
            
        case 5

            Power_Start       =      [1.5080e-05, 1.1058e-05,  4.1888e-05, 8.3776e-05 ];
            Delta_Start       =      [-5,-5.093,5.5,11.65]*Res.Stat.In.kappa;
            CW_Num            =      [3,3,1,2];
            Sol_Index         =      [3,3,1,2];

        
        case 6

            Power_Start       =      [2.5133e-05,2.5133e-05,1.1729e-06 ,8.3776e-05 ];
            Delta_Start       =      [-7.635,-7.635,6.2,11.2]*Res.Stat.In.kappa;
            CW_Num            =      [3,3,1,2];
            Sol_Index         =      [1,3,1,4];
            Function_start    =      {@Newton_Manual_bicgstab,@Newton_Manual_bicgstab,...
                                    @Newton_Manual_bicgstab,@Newton_Manual_bicgstab};

        case 7

            Power_Start       =      [4.6914e-05,4.6914e-05, 8.3776e-05,  8.3776e-05];
            Delta_Start       =      [-11,-11,1,12.2]*Res.Stat.In.kappa;
            CW_Num            =      [3,3,1,2];
            Sol_Index         =      [1,2,1,1];
            Function_start    =      {@Newton_Manual_bicgstab,@Newton_Manual_bicgstab,@Newton_Manual_bicgstab,@Newton_Manual_bicgstab};
            Pert_Amplitude    =      [0.8,0.8,0.8,0.8];

        case 8

            Power_Start       =      [8.2100e-05,8.9975e-05,2.5133e-06,2.5133e-06];
            Delta_Start       =      [-14.65,-14.4,10,10]*Res.Stat.In.kappa;
            CW_Num            =      [3,3,1,2];
            Sol_Index         =      [1,1,1,1];

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

        case 14
            
            Power_Start       =   [ 0.,0.000,8.3776e-05,8.3776e-05];
            Delta_Start       =   [0,0,27.7401,27.743]*Res.Stat.In.kappa;
            CW_Num            =   [0,0,1,2];
            Sol_Index         =   [0,0,2,3];
            
        case 16

            Power_Start       =      [0,0,8.3776e-05,8.3776e-05];
            Delta_Start       =      [0,0,34.84,34.83]*Res.Stat.In.kappa;
            CW_Num            =      [0,0,2,2];
            Sol_Index         =      [0,0,2,1];
            
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
        Res_t.Stat.Par.In.Rel_ampl = Pert_Amplitude(i);
        Res_t                    = Res_t.Stat.Met.Sol_In_point(Res_t);  
        Stat(ii)                 = Res_t.Stat(Sol_Index(i));
        Stat(ii).Met.Newton = Function_start{i};
    end
    
end
