    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Turing_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN  

    N_mode              =  2^8;
    SiN.Stat.In         =  Params_SiN_Modes( N_mode);    
    SiN.Stat.In.N_mode  =  N_mode;
    SiN.Stat.In.mu_bl   =  1;
    SiN.Stat.In.kappa   =  125E6*2*pi;
    SiN.Stat.In.delta   =  3.5*SiN.Stat.In.kappa;
    SiN.Stat.In.P       =  0.0325;       
    
    SiN.CW.In           = SiN.Stat.In;
    SiN.Temp.In         = SiN.Stat.In;
    
%%
    NN = 36;
    
    Power_Start_Vector = linspace(0.005,0.05,NN);     
    Delta_Start_Vector = linspace(1.25,4,NN)*SiN.Stat.In.kappa;
    
%% Stationary Coefficeints

    SiN.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    SiN.Stat.Met.Stab_Method      =  @LLE_Full_Stability;
    SiN.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    SiN.Stat.Met.Newton           = @fsolve;%'fsolve'
         
    SiN.Stat.Par.variable         = 'delta';  %%'Pump Power';
    SiN.Stat.Par.first_step       = 0.05; % step for delta measured in delta/kappa
    SiN.Stat.Par.step_tol         = 0.01;
    SiN.Stat.Par.step_inc         = 0.00;
    SiN.Stat.Par.step_dec         = 0.5;

    SiN.Stat.Par.bot_boundary     = -40; % bottom boundary for delta to search
    SiN.Stat.Par.top_boundary     =  602; % top boundary for delta to search
    SiN.Stat.Par.Sol_Re_Sign      = '-';
    SiN.Stat.Par.Stability        = 'Yes';
    SiN.Stat.Par.Newton_iter          = 30;      
    SiN.Stat.Par.Newton_tol           = 1E-10;  
    SiN.Stat.Par.i_max                = 1000;
    
    SiN.Stat.Par.fsolveoptions       = optimoptions('fsolve','CheckGradients',...
    false,'Display','iter','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);
%%

    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 2E-4;
    SiN.Temp.Par.s_t           = 0.01;
    SiN.Temp.Par.T             = 2500;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
    SiN.Temp.Par.dd            = SiN.Temp.Par.T/SiN.Temp.Par.s_t;
    SiN.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(SiN.Temp.Par);

%%

parfor i =1:NN
    
    Res = SiN;
    
    Res.Stat.In.delta = Delta_Start_Vector(i);
    Res.Stat.In.P     = Power_Start_Vector(i);
    
    Res.Stat               = Chi3_Stat_LLE_Stat_From_Cons_Soliton(Res.Stat);
    SiN_Soliton(i)         = Res;
    SiN_Soliton(i).Stat    = Run_Branch_Universal(Res.Stat);
    
end

%%
    i_max    = 0;
    i_d_vect = [];
    i_p_vect = [];
    ii = 0;
    for i_p = 1:size(SiN_Soliton,2)
        
        for i_d =1:size(SiN_Soliton(i_p).Stat,2)
            
            ii = ii+1;
            ii_matrix(i_p,i_d) = ii; 
            
        end    
        
    end
%%
full_pic = Plot_LLE_Static_Branch_Soliton_2D(SiN_Soliton);
Cust        = parcluster('local');
 Path          = strcat('/home/dp710/Data_Storage/SiN_Soliton_Paper_Small_Time_step');

%%
 %Cust = parcluster('local');
%delete(Cust.Jobs)
 %
 for i_p = 28:size(SiN_Soliton,2)
     
     delete(gcp('nocreate'));
     Cust       = parcluster('local');
     parpool(30);
     Res_Branch = SiN_Soliton(i_p);
     
     parfor  i_d =1:size(Res_Branch.Stat,2)
        Alph_Ind =    (letters(ii_matrix(i_p,i_d)+26*27));

         if~isfile(strcat(Path,'/Data/',Alph_Ind{1},'.mat'))

             Res               = SiN;
             Res.Stat          = Res_Branch.Stat(i_d);
             Res.Temp.In       = Res.Stat.In;
             Res.Temp          = Chi_3_LLE_Normalization_Without_D_Coeff(Res.Temp);       
             Res               = Res.Temp.Met.Ev_Start_Point(Res);  
             Res.Temp.Met      = [];

             tic
             Res.Temp.Sol               =Chi_3_LLE_Runge_Kuarong_mex(Res.Temp,Runge);
             toc

             Chi_3_LLE_Runge_Save_Long_Run_from_Soliton(Path,Res, ii_matrix(i_p,i_d),Res_Branch,full_pic)
         end
         i_p
     end
     
%     Comp = findJob(Cust,'State','completed');
 %    delete(Comp);
    delete(Cust.Jobs)

 end
 %%
 function lets = letters(nums)
lets = arrayfun(@(n)num2char(n),nums,'UniformOutput',0);
function s = num2char(d)
  b = 26;
  n = max(1,round(log2(d+1)/log2(b)));
  while (b^n <= d)
    n = n + 1;
  end
  s(n) = rem(d,b);
  while n > 1
    n = n - 1;
    d = floor(d/b);
    s(n) = rem(d,b);
  end
  n = length(s);
  while (n > 1)
    if (s(n) <= 0)
      s(n) = b + s(n);
      s(n-1) = s(n-1) - 1;
    end
    n = n - 1;
  end
  s(s<=0) = [];
  symbols = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  s = reshape(symbols(s),size(s));
end
end

