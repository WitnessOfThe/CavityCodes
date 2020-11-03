    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    SiN.Stat.In         = Params_SiN;
    SiN.Stat.In.kappa   =  150E6*2*pi;%2*1E3*2*pi;%
    SiN.Stat.In.P       = 0.0004;
    SiN.Stat.In.delta   = -SiN.Stat.In.kappa*24;
    SiN.Temp.In       = SiN.Stat.In;
    SiN.CW.In       = SiN.Stat.In;
    
%%

  N      = 200;   
  N_Mode = 2^8;
  
  
%%
    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 5E-4;
    SiN.Temp.Par.s_t           = 0.01;
    SiN.Temp.Par.T             = 1000;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
    SiN.Temp.Par.dd            = SiN.Temp.Par.T/SiN.Temp.Par.s_t;
    SiN.Temp.Par.CW_num        = 1;
    SiN.Temp.Met.Ev_Start_Point = @Chi_3_LLE_Start_Point_Stat;
    Runge                      = Define_Runge_Coeff(SiN.Temp.Par);
%%
    SiN.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    SiN.Stat.Met.Newton           = @Newton_Manual_bicgstab;%'fsolve'
    
%     SiN.Stat.Par.step_tol         = 0.000001;
%    SiN.Stat.Par.variable         = 'Pump Power';  %%'Pump Power';
%     SiN.Stat.Par.first_step       = 0.01; %min =1E-4/3
%     SiN.Stat.Par.bot_boundary     = 0;
%     SiN.Stat.Par.top_boundary     = 1;
    
 
    SiN.Stat.Par.variable         = 'delta';  %%'Pump Power';
    SiN.Stat.Par.first_step       = 0.01; % step for delta measured in delta/kappa
    SiN.Stat.Par.step_tol         = 0.00001;

    SiN.Stat.Par.bot_boundary     = 0;
    SiN.Stat.Par.top_boundary     = 20;
    
    SiN.Stat.Par.Sol_Re_Sign      = '-';
    SiN.Stat.Par.Stability        = 'Yes';
    SiN.Stat.Par.Newton_iter      = 30;      
    SiN.Stat.Par.Newton_tol       = 1E-10;  
    SiN.Stat.Par.i_max            = 500;
    SiN.Stat.Par.CW_num           = 3;
    SiN.Stat.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg'...
 ,'FunctionTolerance',SiN.Stat.Par.Newton_tol,...
     'MaxIterations',SiN.Stat.Par.Newton_iter,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);

%%
    NN = 72;
    Power_Vector = linspace(0.01,0.4,NN);
    Delta_Vector = linspace(1,10,NN);
    Sim_number   = NaN(NN,NN);
for i_p = 1:size(Power_Vector,2)
    for i_d = 1:size(Delta_Vector,2)
        SiN_Start(i_p,i_d)                 = SiN;
        SiN_Start(i_p,i_d).Stat.In.P       = Power_Vector(i_p);
        SiN_Start(i_p,i_d).Stat.In.delta   = SiN_Start(i_p,i_d).Stat.In.kappa*Delta_Vector(i_d);
                                           
        SiN_Start(i_p,i_d).CW.In           = SiN_Start(i_p,i_d).Stat.In;
        SiN_Start(i_p,i_d).Stat.In.D(3:end)     = []; 
        
        SiN_Start(i_p,i_d).CW              = SiN_Start(i_p,i_d).CW.Met.Solve(SiN_Start(i_p,i_d).CW,N_Mode);

        Power_Matrix(i_p,i_d)              = Power_Vector(i_p);
        Delta_Matrix(i_p,i_d)              = Delta_Vector(i_d);
        Sim_number(i_p,i_d)                = sub2ind([NN,NN],i_p,i_d);
        
        if sum(isnan(SiN_Start(i_p,i_d).CW.Sol.Psi)) > 0 
            
            Sol_Plane(i_p,i_d) = 0;
            
        else
            
            
            SiN_Start(i_p,i_d).Stat            =  Chi3_Stat_LLE_Stat_From_Cons_Soliton(SiN_Start(i_p,i_d).Stat,N_Mode);
             Sol_Plane(i_p,i_d) = SiN_Start(i_p,i_d).Stat.Sol.Flag;
             SiN_Start(i_p,i_d).Stat.In.D =  SiN.Stat.In.D;
        end        
    end
end
%%
  Path = strcat('/home/dp710/Data_Storage/For_SPapp_Meting_From_Sol/SiN_Fd',num2str(SiN.Stat(1).In.D(2)/SiN.Stat(1).In.kappa),'_Stat_Branch_Scan_evenD_only');
ii =0;
  for i = 1:size(Power_Vector,2)*size(Delta_Vector,2)/70
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
            SiN_Temp.Stat.In.P       = Power_Matrix(ii_bathc(i_s));
            SiN_Temp.Stat.In.delta   = SiN_Temp.Stat.In.kappa*Delta_Matrix(ii_bathc(i_s));
  %          SiN_Temp.Temp.Eq.mode_range  = [1:100,SiN_Temp.Stat.Space.N:(SiN_Temp.Stat.Space.N-100+1)];
            
            Chi_3_LLE_Assynch_Paralell_exec(SiN_Temp,SiN_Temp.Stat.In.delta,SiN_Temp.Stat.In.P,ii_bathc(i_s),Path,1,N_Mode,Runge)
            
        end
      toc
      end
      
 %
 