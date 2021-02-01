    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = -20E9*2*pi;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 2^8;
    Res.CW.In.W       = 70000*Res.CW.In.W_Star;
    
%%
    Res.CW.Par.Equation_string  = 'Chi23_CW';
    Res.CW.Met.Equation         = @Chi23_CW;
    Res.CW.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    Res.CW.Met.Newton           = @fsolve;%'fsolve'
    Res.CW.Par.Change_Space     = 0;
    
    Res.CW.Par.variable         = 'delta_o';  %%'Pump Power';
    Res.CW.Par.first_step       = 0.05; % step for delta measured in delta/kappa
    Res.CW.Par.step_tol         = 0.001;
    Res.CW.Par.step_inc         = 0.00;
    Res.CW.Par.step_dec         = 0.5;

    Res.CW.Par.bot_boundary     = -40; % bottom boundary for delta to search
    Res.CW.Par.top_boundary     =  40; % top boundary for delta to search
    Res.CW.Par.Sol_Re_Sign      = '-';
    Res.CW.Par.Stability        = false;
    Res.CW.Par.Newton_iter      = 30;      
    Res.CW.Par.Newton_tol       = 1E-10;  
    Res.CW.Par.i_max            = 1000;
    
    Res.CW.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',false,'SpecifyObjectiveGradient',false,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-25,'OptimalityTolerance',1E-25,'FunctionTolerance',10^(-10));

%%
    NN                  = 500;
    delta_vector        = 10*linspace(-2,2,NN)*Res.CW(1).In.ko;
    Omega_Vector         = 2*pi*linspace(1,6E8,NN);
    
%%
    Mumber_of_modes = NaN(NN);
    for i_p = 1:NN
        parfor i_d = 1:NN
            
            Res_S                   = Res;
            Res_S.CW.In.delta_o     = delta_vector(i_d);
            Res_S.CW.Sol.Omega      = Omega_Vector(i_p);         
            [Mumber_of_modes(i_p,i_d)] =  Evaluate_MI(Res_S);
        end
        i_p
    end
    
    Save.delta_vector       = delta_vector; 
    Save.Omega_Vector       = Omega_Vector;
    Save.Mumber_of_modes    = Mumber_of_modes;
    
%%
figure;pcolor(Save.delta_vector/Res.CW.In.ko,Save.Omega_Vector/sqrt(2*Res.CW.In.ko*Res.CW.In.ke),Save.Mumber_of_modes);shading interp;
%%

function [Mumber] =  Evaluate_MI(Res)

    Res.CW            = Res.CW.Met.Norm(Res.CW);
    Res.CW.Stab       = Chi23_MI(Res.CW);
    [~,ind]           = max(abs(Res.CW.Sol.Omega));
    Mumber            = sum(sum(real(Res.CW.Stab(ind).Value)>1E-6));
    
end
    