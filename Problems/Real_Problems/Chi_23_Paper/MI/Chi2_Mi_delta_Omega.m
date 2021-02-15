    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = -10E9*2*pi;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 90;
    Res.CW.In.W       = 7000*Res.CW.In.W_Star;
    
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
    NN                  = 72*5;
  %  delta_vector        = linspace(-11,-9,NN)*Res.CW(1).In.ko;
    epsilon_vector      = 2*pi*[-10E9,-20E9,0,-10E6];   
    omega_max           = [150,100,10,10];
    delta_max           = [40,100,10,10];
    delta_min           = [150,100,10,10];
    
%%
    tic
    for ii = 1:1
        
        Res.CW.In.eps       = epsilon_vector(ii);
        Omega_Vector        = linspace(30,omega_max(ii),NN)*Res.CW.In.Omega_Star;
        delta_vector        = linspace(delta_min(ii),delta_max(ii),NN)*Res.CW(1).In.ko;

        parfor i_p = 1:NN
            for i_d = 1:NN

                Res_S                   = Res;
                Res_S.CW.In.delta_o     = delta_vector(i_d);
                Res_S.CW.Sol.Omega      = Omega_Vector(i_p);         
                [Mumber(i_p,i_d),lambda_vec(i_p,i_d).lambda...
                    ,k_vec(i_p,i_d).k,Vector_vec(i_p,i_d).Vector] =  Evaluate_MI(Res_S);
            end          
            i_p
        end
        ii
        Res                  = Res;
        
        Save(ii).delta_vector         = delta_vector; 
        Save(ii).W_Vector             = Omega_Vector;
        Save(ii).Mumber               = Mumber;
        Save(ii).lambda_vec           = lambda_vec;
        Save(ii).k_vec                = k_vec;
        Save(ii).Vector_vec           = Vector_vec;
        
    end
    toc
        
%%
        for i_p = 1:NN
            for i_d = 1:NN
                
                if ~isnan(Save.k_vec(i_p,i_d).k)
                    [~,ind]    = min(Save.k_vec(i_p,i_d).k);
                    
                    Conv_eff(i_p,i_d) = abs(Vector_vec(i_p,i_d).Vector(2,ind) ).^2/abs(Vector_vec(i_p,i_d).Vector(1,ind)).^2;
                    
                else
                    Conv_eff(i_p,i_d) = NaN;
                end
            end         
        end

%%

figure;
mesh(Save(ii).delta_vector/Res.CW.In.ko,Save(ii).W_Vector/sqrt(2*Res.CW.In.ko*Res.CW.In.ke),abs(Conv_eff));shading interp;

%%

for ii = 1
    figure;pcolor(Save(ii).delta_vector/Res.CW.In.ko,Save(ii).W_Vector/sqrt(2*Res.CW.In.ko*Res.CW.In.ke),abs(Save(ii).Mumber));shading interp;
end

%%
    figure;mesh(Save(ii).delta_vector/Res.CW.In.ko,Save(ii).W_Vector/sqrt(2*Res.CW.In.ko*Res.CW.In.ke),log10(Conv_eff));shading interp;
%%

function [Mumber,lambda,k,Vector] =  Evaluate_MI(Res)

    k                 = NaN;
    Vector_Save       = NaN;
    Res.CW            = Res.CW.Met.Norm(Res.CW);
    Res.CW.Stab       = Chi23_MI(Res.CW);
    [~,ind]           = max(abs(Res.CW.Sol.Omega));
    Mumber            = sum(sum(uniquetol(real(Res.CW.Stab(ind).Value))>1E-6));
    
    [i_r,i_c]         = find(Res.CW.Stab(ind).Value > 0);
    
    k      = zeros(1,length(i_r));
    lambda = zeros(1,length(i_r));
    Vector = zeros(4,length(i_r));
    
    if ~isempty(i_r) > 0
        for i = 1:length(i_r)
            
           k(i)         = Res.CW.Space.k(i_r(i));
           lambda(i)    = Res.CW.Stab.Value(i_r(i),i_c(i));
           Vector(:,i)  = Res.CW.Stab.Vector(i_r(i)).V(:,i_c(i));
            
        end
    end
end
    