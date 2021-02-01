    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 2^4;
    
%%
    Res.CW.Par.Equation_string  = 'Chi23_CW';
    Res.CW.Met.Equation         = @Chi23_CW;
    Res.CW.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    Res.CW.Met.Newton           = @fsolve;%'fsolve'
    Res.CW.Par.Change_Space     = 0;
    
    Res.CW.Par.variable         = 'delta_o';  %%'Pump Power';
    Res.CW.Par.first_step       = 1E-5; % step for delta measured in delta/kappa
    Res.CW.Par.step_tol         = 1E-6;
    Res.CW.Par.step_inc         = 1.01;
    Res.CW.Par.step_dec         = 0.1;

    Res.CW.Par.bot_boundary     = -0; % bottom boundary for delta to search
    Res.CW.Par.top_boundary     =  1000; % top boundary for delta to search
    Res.CW.Par.Sol_Re_Sign      = '-';
    Res.CW.Par.Stability        = false;
    Res.CW.Par.Newton_iter      = 30;      
    Res.CW.Par.Newton_tol       = 1E-11;  
    Res.CW.Par.i_max            = 12000;
    
    Res.CW.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',false,'SpecifyObjectiveGradient',f alse,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'FunctionTolerance',10^(-10));


%%

    NN = 500;
    w_wec = linspace(100,1E6^2,NN);
    
    vec_eps = 2*pi*[0,-10,-100]*1E6;
    tic
    
    for i_c = 1:1
        
        parfor i_w = 1:500

            Res_S               = Res;
            Res_S.CW.In.eps      = vec_eps(i_c);
            Res_S.CW.In.W       = w_wec(i_w)*Res_S.CW.In.W_Star;
            [Omega2_max(i_w),delta2_max(i_w),Omega23_max(i_w),delta23_max(i_w),omega_delta(i_w)] = max_val_pos(Res_S);        
        
        end
        
        Save(i_c).Omega2_max  = Omega2_max;
        Save(i_c).delta2_max  = delta2_max;
        Save(i_c).delta23_max = delta23_max;
        Save(i_c).Omega23_max = Omega23_max;
        Save(i_c).w_wec       = w_wec;
    
    end
    toc
%%

    figure;
    for i_c =2:3
        hold on;
       plot(sqrt( Save(i_c).w_wec), Save(i_c).delta23_max/Res.CW.In.k_o);hold on;
       plot(sqrt( Save(i_c).w_wec), Save(i_c).delta2_max/Res.CW.In.k_o);hold on;
     %   plot(abs(Save(i_c).Omega23_max)-abs(Save(i_c).Omega2_max))
%        plot(Save(i_c).delta23_max,Save(i_c).Omega23_max);hold on;  
 %       plot(Save(i_c).delta23_max,Save(i_c).Omega23_max);hold on;  
    end
 %   plot(sqrt(w_wec),delta2_max/Res.CW.In.k_o);
%%
figure;
    plot(delta23_max,Omega23_max);hold on;  
    plot(delta2_max,Omega2_max);

%%
function [Omega2_max,delta2_max,Omega23_max,delta23_max,omega_delta] = max_val(Res)

    Res.CW = Res.CW.Met.Norm(Res.CW);
    
    inck  = Res.CW.In.k_o*Res.CW.Par.step_tol*101;
    
    Omega2_max = 0;
    Flag = 0;
    delta =0;
    ii = 0;
    
    while Flag == 0 
        
        ii = ii+1;
        inck              = inck*1.1;
        delta             = delta+inck;
        Res.CW.In.delta_o = delta;
        Res.CW            = Res.CW.Met.Solve_Chi2(Res.CW);
        Omega             = max(abs(Res.CW.Sol.Omega));
        
        if Omega2_max > Omega
            
              delta             = delta-inck;
               inck              = 0.1*inck;
            
            if Res.CW.Par.step_tol*Res.CW.In.k_o > inck
                
                Flag = 1;
                
            end
        else            
            
            Omega2_max         = Omega;
            delta2_max         = Res.CW.In.delta_o;
            
        end
        Omega_Vec(ii) =Omega2_max;
        delta_Vec(ii) =delta2_max;
    end
%%
    
    
    Res.CW.Par.bot_boundary     = 0;
    Res.CW.Par.top_boundary     = delta2_max/Res.CW.In.k_o*10;
    
    Res.CW.Par.first_step       = Res.CW.Par.step_tol*101;    
    
    Res.CW.In.delta_o = 0.*Res.CW.In.k_o;     
    Res.CW            = Res.CW.Met.Solve_Chi2(Res.CW);
    
            
            Res.CW23            = Res.CW;
            
            [~,IND]             =  max(Res.CW.Sol.Omega);
            Res.CW23.Sol.Psi_o  =  Res.CW.Sol.Psi_o(IND);
            Res.CW23.Sol.Psi_e  =  Res.CW.Sol.Psi_e(IND);
            
            Res.CW23            = Res.CW.Met.Norm(Res.CW23);
            Res.CW23            = Run_Branch_Universal(Res.CW23);

            delta_vector        = zeros(1,size(Res.CW23,2));
            Omega23             = zeros(1,size(Res.CW23,2));
            
            for j = 1:size(Res.CW23,2)

                delta_vector(j)   = Res.CW23(j).In.delta_o;
                Omega23(j)        = Res.CW23(j).Sol.Omega;

            end
            
            
    [Omega23_max,i]   = max(Omega23);
    delta23_max       = delta_vector(i);
%
        
        omega_delta = Omega23_max - Omega2_max;
        if size(Omega23_max,2) == 0
            Omega23_max = NaN;
        end

        if size(Omega2_max,2) == 0
            Omega2_max = NaN;
        end

        if size(delta23_max,2) == 0
            delta23_max = NaN;
        end

        if size(delta2_max,2) == 0
            delta2_max = NaN;
        end        
            
end


function [Omega2_max,delta2_max,Omega23_max,delta23_max,omega_delta] = max_val_pos(Res)

    Res.CW = Res.CW.Met.Norm(Res.CW);
    
    inck  = Res.CW.In.k_o*Res.CW.Par.first_step/100;
    
    Omega2_max = 0;
    Flag = 0;
    delta =0;
    ii = 0;
    
    while Flag == 0 
        
        ii = ii+1;
        inck              = inck*1.1;
        delta             = delta+inck;
        Res.CW.In.delta_o = delta;
        Res.CW            = Res.CW.Met.Solve_Chi2(Res.CW);
        Omega             = max(abs(Res.CW.Sol.Omega));
        
        if Omega2_max > Omega
            
              delta             = delta-inck;
               inck              = 0.1*inck;
            
            if Res.CW.Par.step_tol*Res.CW.In.k_o/100 > inck
                
                Flag = 1;
                
            end
        else            
            
            Omega2_max         = Omega;
            delta2_max         = Res.CW.In.delta_o;
            
        end
        
        Omega_Vec(ii) = Omega2_max;
        delta_Vec(ii) = delta2_max;
        
    end
%%
    d_start_vec = linspace(0,delta2_max/2,1000);
    W_vec = linspace(1,Res.CW.In.W /Res.CW.In.W_Star,1000);
    Res.CW.In.delta_o = 1.*Res.CW.In.k_o;     
    Res.CW.In.W       = W_vec(1)*Res.CW.In.W_Star;    
    Res.CW            = Res.CW.Met.Solve_Chi2(Res.CW);
    
         [Slv,eps_f,Exitflag]  = Newton_Switcher([real(Res.CW.Sol.Psi_o(3)),imag(Res.CW.Sol.Psi_o(3)),real(Res.CW.Sol.Psi_e(3)),imag(Res.CW.Sol.Psi_e(3))],Res.CW);
         Res.CW             = Res.CW.Met.Prop_Gen(Slv,Res.CW);        
         
    for i =1:1000
         Res.CW.In.W       = W_vec(i)*Res.CW.In.W_Star;    
         Res.CW.In.delta_o = d_start_vec(i);     
         Res.CW = Res.CW.Met.Norm(Res.CW);
         [Slv,eps_f,Exitflag]  = Newton_Switcher([real(Res.CW.Sol.Psi_o(1)),imag(Res.CW.Sol.Psi_o(1)),real(Res.CW.Sol.Psi_e(1)),imag(Res.CW.Sol.Psi_e(1))],Res.CW);
         Res.CW             = Res.CW.Met.Prop_Gen(Slv,Res.CW);             
    end

    Res.CW.Par.bot_boundary     = - abs(delta2_max/Res.CW.In.k_o*10);
    Res.CW.Par.top_boundary     =  abs(delta2_max/Res.CW.In.k_o*10);
    
    
 %% 
            
            Res.CW23            = Res.CW;
            
            [~,IND]             =  max(Res.CW.Sol.Omega);
            Res.CW23.Sol.Psi_o  =  Res.CW.Sol.Psi_o(IND);
            Res.CW23.Sol.Psi_e  =  Res.CW.Sol.Psi_e(IND);
            
            Res.CW23            = Res.CW.Met.Norm(Res.CW23);
            Res.CW23            = Run_Branch_Universal(Res.CW23);

            delta_vector        = zeros(1,size(Res.CW23,2));
            Omega23             = zeros(1,size(Res.CW23,2));
            
            for j = 1:size(Res.CW23,2)

                delta_vector(j)   = Res.CW23(j).In.delta_o;
                Omega23(j)        = Res.CW23(j).Sol.Omega;

            end
            
            
    [Omega23_max,i]   = max(Omega23);
    delta23_max       = delta_vector(i);
%
        
        omega_delta = Omega23_max - Omega2_max;
        if size(Omega23_max,2) == 0
            Omega23_max = NaN;
        end

        if size(Omega2_max,2) == 0
            Omega2_max = NaN;
        end

        if size(delta23_max,2) == 0
            delta23_max = NaN;
        end

        if size(delta2_max,2) == 0
            delta2_max = NaN;
        end        
            
end
