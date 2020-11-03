    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    SiN.CW.In         = Params_SiN;
    SiN.CW.In.kappa   =  200E6*2*pi;%2*1E3*2*pi;%
    SiN.CW.In.P       = 0.0004;
    SiN.CW.In.delta   = -SiN.CW.In.kappa*24;
    SiN.Temp.In       = SiN.CW.In;
    
%%

  N      = 200;   
  N_Mode = 2^9;
  
  
%%
    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 2E-4;
    SiN.Temp.Par.s_t           = 0.01;
    SiN.Temp.Par.T             = 500;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
    SiN.Temp.Par.dd            = SiN.Temp.Par.T/SiN.Temp.Par.s_t;
    SiN.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(SiN.Temp.Par);
    
%%
    NN = 72;
    Power_Vector = linspace(0.00,0.2,NN);
    Delta_Vector = linspace(0,10,NN);
ii =0;
for i_p = 1:size(Power_Vector,2)
    for i_d = 1:size(Delta_Vector,2)
        ii=ii+1;
        SiN_Start(i_p,i_d)               = SiN;
        SiN_Start(i_p,i_d).CW.In.P       = Power_Vector(i_p);
        SiN_Start(i_p,i_d).CW.In.delta   = SiN.CW.In.kappa*Delta_Vector(i_d);
        SiN_Start(i_p,i_d).CW            = SiN_Start(i_p,i_d).CW.Met.Solve(SiN_Start(i_p,i_d).CW,N_Mode);
        
        Power_Matrix(i_p,i_d)            = Power_Vector(i_p);
        Delta_Matrix(i_p,i_d)            = Delta_Vector(i_d);
        Sim_number(i_p,i_d)              = ii;
        if sum(isnan(SiN_Start(i_p,i_d).CW.Sol.Psi)) > 0 
            
            Sol_Plane(i_p,i_d) = 0;
            
        else
            
            Sol_Plane(i_p,i_d) = 1;
            
        end        
    end
end
%%
  Path = strcat('/home/dp710/Data_Storage/For_SPapp_Meting_new/SiN_Fd',num2str(SiN.CW(1).In.D(2)/SiN.CW(1).In.kappa),'_CW_Branch_Scan_');
ii =0;
  for i = 1:size(Power_Vector,2)*size(Delta_Vector,2)
      Count = 0;
      
      while Count < 70
          
          ii = ii+1;
          
          if Sol_Plane(ii) == 1 && ~isfile(strcat(Path,'/Data/',num2str(ii),'.mat'))   
              
              Count = Count +1;
              ii_bathc(Count) = Sim_number(ii);
              
          end
          
      end
      delete(gcp('nocreate')); 
      parpool(70);
        tic
        parfor i_s =1:70 
            
            SiN_Temp               = SiN_Start(ii_bathc(i_s));
            SiN_Temp.CW.In.P       = Power_Matrix(ii_bathc(i_s));
            SiN_Temp.CW.In.delta   = SiN_Temp.CW.In.kappa*Delta_Matrix(ii_bathc(i_s));
            Chi_3_LLE_Assynch_Paralell_exec(SiN_Temp,SiN_Temp.CW.In.delta,SiN_Temp.CW.In.P,ii_bathc(i_s),Path,1,N_Mode,Runge)
            
        end
        toc
      end
      
 %
 