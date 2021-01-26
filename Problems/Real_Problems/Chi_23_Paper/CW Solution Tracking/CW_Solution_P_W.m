    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = -20*1E9*2*pi;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 2^4;
    
%%
    Res.CW.Par.Equation_string  = 'Chi23_CW';
    Res.CW.Met.Equation         = @Chi23_CW;
    Res.CW.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    Res.CW.Met.Newton           = @fsolve;%'fsolve'
    Res.CW.Par.Change_Space     = 0;
    
    Res.CW.Par.variable         = 'delta_o';  %%'Pump Power';
    Res.CW.Par.first_step       = 0.01; % step for delta measured in delta/kappa
    Res.CW.Par.step_tol         = 0.001;
    Res.CW.Par.step_inc         = 0.00;
    Res.CW.Par.step_dec         = 0.5;

    Res.CW.Par.bot_boundary     = -0; % bottom boundary for delta to search
    Res.CW.Par.top_boundary     =  1000; % top boundary for delta to search
    Res.CW.Par.Sol_Re_Sign      = '-';
    Res.CW.Par.Stability        = false;
    Res.CW.Par.Newton_iter      = 30;      
    Res.CW.Par.Newton_tol       = 1E-10;  
    Res.CW.Par.i_max            = 10000;
    
    Res.CW.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',false,'SpecifyObjectiveGradient',false,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-25,'OptimalityTolerance',1E-25,'FunctionTolerance',10^(-10));


%%

    NN = 24;
    w_wec = linspace(1000,1000^2,NN);
    
   parfor i_w = 1:NN
       
        Res_S               = Res;
        Res_S.CW.In.W       = w_wec(i_w)*Res_S.CW.In.W_Star;
        [Omega2_max(i_w),delta2_max(i_w),Omega23_max(i_w),delta23_max(i_w)]...
            = max_val(Res_S);
        
    end
%%
figure;
    plot(sqrt(w_wec),delta23_max);hold on;
    plot(sqrt(w_wec),delta2_max);

figure;
    plot(delta23_max,Omega23_max);hold on;  
    plot(delta2_max,Omega2_max);

%%
function [Omega2_max,delta2_max,Omega23_max,delta23_max] = max_val(Res)

    NN     = 1E5;
    Res.CW = Res.CW.Met.Norm(Res.CW);
    
    delta_vector = linspace( Res.CW.Par.bot_boundary,Res.CW.In.H^2*4,NN)*Res.CW.In.k_o;
    Res.CW2      = Res.CW;
    Res.CW.Par.top_boundary = Res.CW.In.H^2*20;
    Omega2  = zeros(1,NN); 
    
    for i = 1:NN
        
        Res.CW2.In.delta_o = delta_vector(i);
        Res.CW2            = Res.CW2.Met.Solve_Chi2(Res.CW2);
        Omega2(i)          = max(abs(Res.CW2.Sol.Omega));
        
    end

    
    [Omega2_max,ind]  = max(Omega2);    
    delta2_max        = delta_vector(ind);
    
    Res.CW.Par.bot_boundary     = delta2_max/Res.CW.In.k_o/2; % bottom boundary for delta to search   
    Res.CW.Par.first_step       = (Res.CW.Par.top_boundary-Res.CW.Par.bot_boundary)/1000;    
    Res.CW.In.delta_o = delta2_max;     
    Res.CW            = Res.CW.Met.Solve_Chi2(Res.CW);
    [~,ind]           = max(abs(Res.CW.Sol.Omega));    
    
    Res.CW.Sol.Psi_o  = Res.CW.Sol.Psi_o(ind);
    Res.CW.Sol.Psi_e  = Res.CW.Sol.Psi_e(ind);
    
    Res.CW            = Res.CW.Met.Norm(Res.CW);
    
    Res.CW            = Run_Branch_Universal(Res.CW);
    
    delta_vector      = zeros(1,size(Res.CW,2));
    Omega23           = zeros(1,size(Res.CW,2));
    
    for i = 1:size(Res.CW,2)
        
        delta_vector(i)   = Res.CW(i).In.delta_o;
        Omega23(i)        = Res.CW(i).Sol.Omega;
        
    end
    
    [Omega23_max,ind] = max(Omega23);
     delta23_max      = delta_vector(ind);
     
    if size(Omega23_max,2) ==0
        Omega23_max = NaN;
    end
    if size(Omega2_max,2) ==0
        Omega2_max = NaN;
    end        
    if size(delta23_max,2) ==0
        delta23_max = NaN;
    end        
    if size(delta2_max,2) ==0
        delta2_max = NaN;
    end        
            
end