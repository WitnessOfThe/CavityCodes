    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = 50E9*2*pi;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 2^4;
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
    NN                  = 1E4;
    delta_vector        = linspace(-20,20,NN)*Res.CW(1).In.k_o;
    
%%
    U_f_2    =   zeros(NN,3);
    U_s_2    =   zeros(NN,3);
    U_f_23   =   zeros(NN,3);
    U_s_23   =   zeros(NN,3);
    
    for i =1:NN
        
        Res.CW.In.delta_o = delta_vector(i);
        Res.CW            = Res.CW.Met.Solve_Chi2(Res.CW);
        Res.CW_23         = Res.CW;
        
        for i_s = 1:3
            
            if ~isnan(Res.CW_23.Sol.Psi_o(i_s))
                
                [Slv,eps_f,Exitflag]  = Newton_Switcher([real(Res.CW.Sol.Psi_o(i_s)),imag(Res.CW.Sol.Psi_o(i_s)),real(Res.CW.Sol.Psi_e(i_s)),imag(Res.CW.Sol.Psi_e(i_s))],Res.CW_23);
                
                if eps_f > 1E-5
                    
                    U_f_23(i,i_s)         = NaN;
                    U_s_23(i,i_s)         = NaN; 
                    
                else
                    
                    U_f_23(i,i_s)         = Slv(1) + 1i*Slv(2);
                    U_s_23(i,i_s)         = Slv(3) + 1i*Slv(4); 
                    
                end
                
            else
                
                U_f_23(i,i_s)         = NaN;
                U_s_23(i,i_s)         = NaN; 
                
            end
            
        end 
        
        U_f_2(i,:)        = Res.CW.Sol.Psi_o;
        U_s_2(i,:)        = Res.CW.Sol.Psi_e;  
        
    end
%%
    figure;plot(delta_vector/Res.CW(1).In.k_o,abs(U_s_2).^2,'LineStyle','none','Marker','.');
    hold on;plot(delta_vector/Res.CW(1).In.k_o,abs(U_s_23).^2,'LineStyle','none','Marker','.','Color',[0,0,0]);
    