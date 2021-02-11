    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = -10E9*2*pi;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 2^6;
    Res.CW.In.W       = 100000*Res.CW.In.W_Star;
    
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
    NN                  = 72*10;
    
%%
    epsilon_vector = 2*pi*[-10E9,-20E9,0,0,-10E6];
    delta_start    = [-40,-40,-50,50,-50]*Res.CW.In.ko;
    delta_finsih   = [4,40,50,-50,1]*Res.CW.In.ko;
    
    for iii = 1:1
            
    Res.CW.In.eps       = epsilon_vector(iii);
    delta_vector        = linspace(delta_start(iii),delta_finsih(iii),NN);
    W_Vector            = linspace(1,150E6,NN);
    
    tic
    
    parfor i_p = 1:NN
        
        Res_S                   = Res;
        Res_S.CW.In.W           = W_Vector(i_p)*Res_S.CW.In.W_Star;        
        Res_S.CW                = Res_S.CW.Met.Solve_Chi2(Res_S.CW ); 
        
        [~,ind]                 = min(abs(Res_S.CW.Sol.Omega));
        
        Res_S.CW.Sol.Omega      =  Res_S.CW.Sol.Omega(ind);    
        Res_S.CW.Sol.Psi_o      =  Res_S.CW.Sol.Psi_o(ind);    
        Res_S.CW.Sol.Psi_e      =  Res_S.CW.Sol.Psi_e(ind);
        
        for i_d = 1:NN
            
            Res_S.CW.In.delta_o    = delta_vector(i_d);            
            Res_S.CW               = Res.CW.Met.Norm(Res_S.CW);  
            [Slv,eps_f,Exitflag]   = Newton_Switcher([real(Res_S.CW.Sol.Psi_o(1)),imag(Res_S.CW.Sol.Psi_o(1)),real(Res_S.CW.Sol.Psi_e(1)),imag(Res_S.CW.Sol.Psi_e(1))],Res_S.CW);
            Res_S.CW               = Res_S.CW.Met.Prop_Gen(Slv,Res_S.CW);      
            
            if eps_f > 1E-5
                
                break;
                
            end        
            [Mumber1(i_p,i_d),k1_vec(i_p,i_d).k,lambda1_vec(i_p,i_d).lambda,Vector1_vec(i_p,i_d).Vector...
                ,Mumber2(i_p,i_d),k2_vec(i_p,i_d).k,lambda2_vec(i_p,i_d).lambda,Vector2_vec(i_p,i_d).Vector] =  Evaluate_MI(Res_S);
        end
        i_p
    end
    
    Save(iii).Res                  = Res;
    Save(iii).delta_vector         = delta_vector; 
    Save(iii).W_Vector             = W_Vector;
    Save(iii).Mumber1              = Mumber1;
    Save(iii).Mumber2              = Mumber2;
    Save(iii).k1_vec               = k1_vec;
    Save(iii).k2_vec               = k2_vec;
    Save(iii).Vector1              = Vector1_vec;
    Save(iii).Vector2              = Vector2_vec;
    toc 
    
    end

%%    
% delta_vector/Res.CW.In.ko,Save.W_Vector,Save.Mumber_of_modes_2,'Parent',ax(2));shading(ax(2),'interp');
        for i_p = 1:NN
            for i_d = 1:NN
                
                if ~isnan(Save.k2_vec(i_p,i_d).k)
                    [~,ind]    = max(Save.k2_vec(i_p,i_d).k);
                    
                    Conv_eff(i_p,i_d) = abs(Vector2_vec(i_p,i_d).Vector(2,ind) + Vector2_vec(i_p,i_d).Vector(4,ind)).^2/abs(Vector2_vec(i_p,i_d).Vector(1,ind)+Vector2_vec(i_p,i_d).Vector(3,ind)).^2;
                    
                else
                    Conv_eff(i_p,i_d) = NaN;
                end
            end         
        end
   figure;
    mesh(Save.delta_vector/Res.CW.In.ko,Save.W_Vector,abs(Conv_eff));shading(gca,'interp');
     
%%

    for i = 1
        
    figure;
    mesh(Save(i).delta_vector/Res.CW.In.ko,Save(i).W_Vector,abs(Save(i).Mumber1));shading(gca,'interp');
    
    end
%%
    for i = 1:size(ax,2)
       axes_Style(ax(i))
    end
    
function axes_Style(ax)

     ax.Box      = 'on';
     ax.FontSize = 15;
     ax.TickLabelInterpreter = 'latex';
     ax.XLabel.Interpreter   = 'latex';
     ax.YLabel.Interpreter   = 'latex';
     
end

%%

function [Mumber1,k1,lambda1,Vector1,Mumber2,k2,lambda2,Vector2] =  Evaluate_MI(Res)

    Res.CW2           = Res.CW.Met.Norm(Res.CW);  
    Res.CW23          = Res.CW2;
    
    Res.CW2.Met.MI_Matrix   = @Chi2_MI_Matrix;
    Res.CW23.Met.MI_Matrix  = @Chi23_MI_Matrix;
    
    Res.CW2           = Res.CW.Met.Solve_Chi2(Res.CW2);    
    Res.CW2.Stab      = Chi23_MI(Res.CW2);    
    Res.CW23.Stab     = Chi23_MI(Res.CW23);
    
    [~,ind]           = min(abs(Res.CW2.Sol.Omega));
    
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

