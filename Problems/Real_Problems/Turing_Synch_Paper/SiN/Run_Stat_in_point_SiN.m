   clear all;
   Save_Br(1) = importdata(strcat('C:\Users\dp710\Documents\Data_Storage\High_Order_Dispersion_Paper\Branch_',num2str(3),'.mat'));
   Save_Br(2) = importdata(strcat('C:\Users\dp710\Documents\Data_Storage\High_Order_Dispersion_Paper\Branch_',num2str(5),'.mat'));
   
%% Define Input Parameters in Physical Units

    i_br_vec  = [2,2];%1,1,1,
    i_del_vec = [220,125];%275,56,30,
    

    SiN       =  Set_Up_Methods_For_Turing_Paper;
    
    N_mode              =  2^8;
    SiN.Stat.In         =  Params_SiN_Modes( N_mode);    
    SiN.Stat.In.N_mode  =  N_mode;
    SiN.Stat.In.mu_bl   =  1;
    SiN.Stat.In.kappa   =  125E6*2*pi;
    
    
    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 1E-3;
    SiN.Temp.Par.s_t           = 0.1;
    SiN.Temp.Par.T             = 100000;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
    SiN.Temp.Par.dd            = SiN.Temp.Par.T/SiN.Temp.Par.s_t;
    SiN.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(SiN.Temp.Par);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN

    i = 5;
    parfor i = 1:2
        i_br              = i_br_vec(i);
        i_del             = i_del_vec(i);

        Res               = SiN;
        Res.Stat          = Save_Br(i_br).Stat(i_del);
        Res.CW.In         = Res.Stat.In;
        Res.Temp.In       = Res.Stat.In;

        Res.Temp          = Chi_3_LLE_Normalization_Without_D_Coeff(Res.Temp);       
        Res               = Res.Temp.Met.Ev_Start_Point(Res);  
        Res.Temp.Met      = [];
        Save(i)  = Res;
        tic
        Save(i).Temp.Sol      = Chi_3_LLE_Runge_Kuarong_mex(Res.Temp,Runge);
        toc
    end

    
%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
i=5;
    ind_t = (size(Save(i).Temp.Sol.Psi,1)/2+1):size(Save(i).Temp.Sol.Psi,1);
            

    [d1,d2,d3] = Plot_Dynamics_Rf_pcolor_Soliton(Save(i).Temp,ind_t,0)   ;
    [d4,d5]    = Plot_Dynamics_Result_pcolors(Save(i).Temp,1,0);
    [d6,d7]    = Plot_Dynamics_Result_LinePlots_Spectrums(Save(i).Temp,0);
    figure;    
    CF = conFigure([d1,d2,d3,d4,d5,d6,d7],2,4, 'UniformPlots', true, 'Height', 15, 'Width', 35,'Labels',false);
