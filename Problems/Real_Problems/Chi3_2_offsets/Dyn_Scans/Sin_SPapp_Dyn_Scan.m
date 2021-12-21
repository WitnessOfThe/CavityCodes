    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Turing_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN

    N_Mode              = 2^8;
    SiN.Stat.In         =  Params_SiN_Modes(-1,N_Mode);    
    SiN.Stat.In.kappa   =  100E6*2*pi;
    SiN.Stat.In.delta   =  3.5*SiN.Stat.In.kappa;
    SiN.Stat.In.P       = 0.02;          
    SiN.CW.In           = SiN.Stat.In;
    SiN.Temp.In         = SiN.Stat.In;
    
%%   
   
    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 2E-4;
    SiN.Temp.Par.s_t           = 0.01;
    SiN.Temp.Par.T             = 1;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
    SiN.Temp.Par.dd            = SiN.Temp.Par.T/SiN.Temp.Par.s_t;
    SiN.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(SiN.Temp.Par);


    
%%
  Path = strcat('C:/Users/dp710/Documents/Data_Storage/SiN_Soliton','_',num2str(SiN.Stat(1).In.D(2)/SiN.Stat(1).In.kappa),'_Upper_Branch_Scan_',SiN.Stat.Par.variable ,'_Start_delta=',num2str(SiN.Stat(1).In.delta/SiN.Stat(1).In.kappa),'_Power=',num2str(SiN.Stat(1).In.P));
  %delete(gcp('nocreate'));
  %parpool(12);
  
  for i = 1:size(SiN_Soliton_Branch_Up.Stat,2)
      
      Res = SiN;
      Res.Stat = SiN_Soliton_Branch_Up.Stat(i);
      Chi_3_LLE_Assynch_Paralell_exec_Sol(Res,Res.Stat.In.delta,Res.Stat.In.P,i,Path,1,N_Mode,Runge,SiN_Soliton_Branch_Up,SiN_Soliton_Branch_Down,50)
          
  end
  
%%
