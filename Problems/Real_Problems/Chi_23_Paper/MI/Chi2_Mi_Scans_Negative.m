    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 150;
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
    NN                  = 72*8;
%    epsilon_vector      = 2*pi*[-1E9,-3E9,-5E9,-7E9,-9E9,-10E9,-15E9,-20E9];   
 %   omega_max           = [30,100,100,150,150,150,150,150];
  %  delta_min           = [70,80,80,120,120,120,120,120];
   % delta_max           = [-70,-80,-80,-120,-120,-120,-120,-120];
    %Power_max_vect      = [1E7,1E7,3E7,6E7,8E7,15E7,20E7,30E7];
    epsilon_vector      = 2*pi*[-5E9];   
    omega_max           = [40];
    delta_min           = [-1];
    delta_max           = [6];
    Power_max_vect      = [3E4];
%% Omega_Scan
 tic
    for ii = 1:size(epsilon_vector,2)
        
        Res.CW.In.eps       = epsilon_vector(ii);
        Omega_Vector        = linspace(10,omega_max(ii),NN)*Res.CW.In.Omega_Star;
        delta_vector        = linspace(delta_min(ii),delta_max(ii),NN)*Res.CW(1).In.ko;

        parfor i_p = 1:NN
            for i_d = 1:NN

                Res_S                   = Res;
                Res_S.CW.In.delta_o     = delta_vector(i_d);
                Res_S.CW.Sol.Omega      = Omega_Vector(i_p);         
                [Mumber(i_p,i_d),~...
                    ,~,~] =  Evaluate_MI_Omega(Res_S);
            end          
       
        end
%        ii
        
        Save_Omega(ii).Res                  = Res;
        
        Save_Omega(ii).delta_vector         = delta_vector; 
        Save_Omega(ii).W_Vector             = Omega_Vector;
        Save_Omega(ii).Mumber               = Mumber;
%        Save_Omega(ii).lambda_vec           = lambda_vec;
 %       Save_Omega(ii).k_vec                = k_vec;
  %      Save_Omega(ii).Vector_vec           = Vector_vec;
        
    end
  toc  
%%
    clear delta_vector W_Vector
    for iii = 1:size(epsilon_vector,2)
tic
            
    Res.CW.In.eps       = epsilon_vector(iii);
    delta_vector        = linspace(delta_min(iii),delta_max(iii),NN)*Res.CW(1).In.ko;
    W_Vector            = linspace(1,Power_max_vect(iii),NN);
    
    Mumber1 = NaN(NN);
    Mumber2 = NaN(NN);
    Psi_o   =  NaN(NN);
    parfor i_p = 1:NN
        
        Res_S                   = Res;
        Res_S.CW.In.W           = W_Vector(i_p)*Res_S.CW.In.W_Star;        
        Res_S.CW                = Res_S.CW.Met.Solve_Chi2(Res_S.CW ); 
         Ext                    = @max;
        [~,ind]                 = Ext(abs(Res_S.CW.Sol.Omega));
        
        Res_S.CW.Sol.Omega      =  Res_S.CW.Sol.Omega(ind);    
        Res_S.CW.Sol.Psi_o      =  Res_S.CW.Sol.Psi_o(ind);    
        Res_S.CW.Sol.Psi_e      =  Res_S.CW.Sol.Psi_e(ind);
        
        for i_d = 1:NN
            
            Res_S.CW.In.delta_o    = delta_vector(i_d);            
            Res_S.CW               = Res.CW.Met.Norm(Res_S.CW);  
            [Slv,eps_f,Exitflag]   = Newton_Switcher([real(Res_S.CW.Sol.Psi_o(1)),imag(Res_S.CW.Sol.Psi_o(1)),real(Res_S.CW.Sol.Psi_e(1)),imag(Res_S.CW.Sol.Psi_e(1))],Res_S.CW);
            Res_S.CW               = Res_S.CW.Met.Prop_Gen(Slv,Res_S.CW);      
            
            Psi_o(i_p,i_d)         = Res_S.CW.Sol.Psi_o;
            if eps_f > 1E-8
                
                break;
                
            end        
            [Mumber1(i_p,i_d),~,~,~...
                ,Mumber2(i_p,i_d),~,~,~] =  Evaluate_MI_Power(Res_S,Ext );
        end
    end
    
    Save_Upper(iii).Res                  = Res;
    Save_Upper(iii).delta_vector         = delta_vector; 
    Save_Upper(iii).W_Vector             = W_Vector;
    Save_Upper(iii).Mumber1              = Mumber1;
    Save_Upper(iii).Mumber2              = Mumber2;
    Save_Upper(iii).Psio                 = Psi_o;
 %   Save_Upper(iii).k1_vec               = k1_vec;
  %  Save_Upper(iii).k2_vec               = k2_vec;
   % Save_Upper(iii).Vector1              = Vector1_vec;
    %Save_Upper(iii).Vector2              = Vector2_vec;
    
    toc 
    end
  
%%    
     clear delta_vector W_Vector
   for iii = 1:size(epsilon_vector,2)
            
    Res.CW.In.eps       = epsilon_vector(iii);
    delta_vector        = linspace(delta_max(iii),1,NN)*Res.CW(1).In.ko;
    W_Vector            = linspace(1,Power_max_vect(iii),NN);
    
    Mumber1 = NaN(NN);
    Mumber2 = NaN(NN);
  Psi_o   =  NaN(NN);    
    tic
    
    parfor i_p = 1:NN
        
        Res_S                   = Res;
        Res_S.CW.In.W           = W_Vector(i_p)*Res_S.CW.In.W_Star;        
        Res_S.CW                = Res_S.CW.Met.Solve_Chi2(Res_S.CW ); 
        Ext                     = @min;
        [~,ind]                 = Ext(abs(Res_S.CW.Sol.Omega));
        
        Res_S.CW.Sol.Omega      =  Res_S.CW.Sol.Omega(ind);    
        Res_S.CW.Sol.Psi_o      =  Res_S.CW.Sol.Psi_o(ind);    
        Res_S.CW.Sol.Psi_e      =  Res_S.CW.Sol.Psi_e(ind);
        
        for i_d = 1:NN
            
            Res_S.CW.In.delta_o    = delta_vector(i_d);            
            Res_S.CW               = Res.CW.Met.Norm(Res_S.CW);  
            [Slv,eps_f,Exitflag]   = Newton_Switcher([real(Res_S.CW.Sol.Psi_o(1)),imag(Res_S.CW.Sol.Psi_o(1)),real(Res_S.CW.Sol.Psi_e(1)),imag(Res_S.CW.Sol.Psi_e(1))],Res_S.CW);
            Res_S.CW               = Res_S.CW.Met.Prop_Gen(Slv,Res_S.CW);      
            Psi_o(i_p,i_d)         = Res_S.CW.Sol.Psi_o;
            
            if eps_f > 1E-8
                
                break;
                
            end        
             [Mumber1(i_p,i_d),~,~,~...
                ,Mumber2(i_p,i_d),~,~,~] =  Evaluate_MI_Power(Res_S,Ext );
        end
    end
    
    Save_Lower(iii).Res                  = Res;
    Save_Lower(iii).delta_vector         = delta_vector; 
    Save_Lower(iii).W_Vector             = W_Vector;
    Save_Lower(iii).Mumber1              = Mumber1;
    Save_Lower(iii).Mumber2              = Mumber2;
    Save_Lower(iii).Psio                 = Psi_o;
    
   % Save_Lower(iii).k1_vec               = k1_vec;
 %   Save_Lower(iii).k2_vec               = k2_vec;
%    Save_Lower(iii).Vector1              = Vector1_vec;
%    Save_Lower(iii).Vector2              = Vector2_vec;
    toc 
    
    end
save(strcat('Mi_Negative_Zoom_NN=',num2str(NN)),'Save_Lower','Save_Upper','Save_Omega');
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Mumber,lambda,k,Vector] =  Evaluate_MI_Omega(Res)

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

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [Mumber1,k1,lambda1,Vector1,Mumber2,k2,lambda2,Vector2] =  Evaluate_MI_Power(Res,Ext)

    Res.CW2           = Res.CW.Met.Norm(Res.CW);  
    Res.CW23          = Res.CW2;
    
    Res.CW2.Met.MI_Matrix   = @Chi2_MI_Matrix;
    Res.CW23.Met.MI_Matrix  = @Chi23_MI_Matrix;
    
    Res.CW2           = Res.CW.Met.Solve_Chi2(Res.CW2);    
    Res.CW2.Stab      = Chi23_MI(Res.CW2);    
    Res.CW23.Stab     = Chi23_MI(Res.CW23);
    
    [~,ind]           = Ext(abs(Res.CW2.Sol.Omega));
    
    Mumber1           = sum(sum(real(Res.CW2.Stab(ind).Value)>1E-6));
    Mumber2           = sum(sum(real(Res.CW23.Stab(1).Value)>1E-6));
    
    
    [i_r,i_c]         = find(Res.CW2.Stab(ind).Value > 0);

    k1      = NaN;
    lambda1 = NaN;
    Vector1 = NaN;

    if ~isempty(i_r) > 0
        k1      = zeros(1,length(i_r));
        lambda1 = zeros(1,length(i_r));
        Vector1 = zeros(4,length(i_r));
        for i = 1:length(i_r)

           k1(i)         = Res.CW2.Space.k(i_r(i));
           lambda1(i)    = Res.CW2.Stab(ind).Value(i_r(i),i_c(i));
           Vector1(:,i)  = Res.CW2.Stab(ind).Vector(i_r(i)).V(:,i_c(i));

        end
    end
    
    [i_r,i_c]         = find(Res.CW23.Stab.Value > 0);

    k2      = NaN;
    lambda2 = NaN;
    Vector2 = NaN;

    if ~isempty(i_r) > 0
        k2      = zeros(1,length(i_r));
        lambda2 = zeros(1,length(i_r));
        Vector2 = zeros(4,length(i_r));
        for i = 1:length(i_r)

           k2(i)         = Res.CW23.Space.k(i_r(i));
           lambda2(i)    = Res.CW23.Stab.Value(i_r(i),i_c(i));
           Vector2(:,i)  = Res.CW23.Stab.Vector(i_r(i)).V(:,i_c(i));

        end
    end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
