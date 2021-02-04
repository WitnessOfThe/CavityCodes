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
    NN                  = 72*72;
    
%%
    epsilon_vector = 2*pi*[-10E9,-20E9,0,0,-10E6];
    delta_start    = [-30,-40,-50,50,-50]*Res.CW.In.ko;
    delta_finsih   = [30,40,50,-50,1]*Res.CW.In.ko;
    
    for iii = 1:2
        
    Mumber_of_modes_1 = NaN(NN);
    Mumber_of_modes_2 = NaN(NN);
    k1                = NaN(NN);
    k2                = NaN(NN);
    
    Res.CW.In.eps       = epsilon_vector(iii);
    delta_vector        = linspace(delta_start(iii),delta_finsih(iii),NN);
    W_Vector            = linspace(1,3E5,NN);
    
    tic
    
    parfor i_p = 1:NN
        
        Res_S                   = Res;
        Res_S.CW.In.W           = W_Vector(i_p)*Res_S.CW.In.W_Star;        
        Res_S.CW                = Res_S.CW.Met.Solve_Chi2(Res_S.CW ); 
        
        [~,ind]                 = max(abs(Res_S.CW.Sol.Omega));
        
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
            [Mumber_of_modes_1(i_p,i_d),Mumber_of_modes_2(i_p,i_d),k1(i_p,i_d),k2(i_p,i_d)] =  Evaluate_MI(Res_S);
        end
        i_p
    end
    
    Save(iii).Res                  = Res;
    Save(iii).delta_vector         = delta_vector; 
    Save(iii).W_Vector             = W_Vector;
    Save(iii).Mumber_of_modes_1    = Mumber_of_modes_1;
    Save(iii).Mumber_of_modes_2    = Mumber_of_modes_2;
    Save(iii).k1                   = k1;
    Save(iii).k2                   = k2;
    
    toc
    
    end

%%    
    figure('Position',[0,0,1000,800/2],'Color',[1,1,1]);
    Panel = tiledlayout(1,2,'TileSpacing','none','Padding','none');   
    
    for i = 1:2
        
        ax(i) = nexttile(Panel,i,[1,1]);  
        hold(ax(i),'on');
        
    end
    
    pcolor(Save.delta_vector/Res.CW.In.ko,Save.W_Vector,Save.Mumber_of_modes_1,'Parent',ax(1));shading(ax(1),'interp');
    pcolor(Save.delta_vector/Res.CW.In.ko,Save.W_Vector,Save.Mumber_of_modes_2,'Parent',ax(2));shading(ax(2),'interp');
    
%%

    for i = 1
        
    figure;
    pcolor(Save(i).delta_vector/Res.CW.In.ko,Save(i).W_Vector,abs(Save(i).Mumber_of_modes_1));shading(gca,'interp');
    
    end
%%

function [Mumber1,Mumber2,k1,k2] =  Evaluate_MI(Res)

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
    
    [m_ind1,ind1_t]   = max(real(Res.CW2.Stab(ind).Value),[],1);
    [~,ind1]          = max(m_ind1);
    k1                = Res.CW2.Space.k(ind1_t(ind1));
    
    [m_ind1,ind1_t]   = max(real(Res.CW23.Stab.Value),[],1);
    [~,ind1]          = max(m_ind1);
    k2                = Res.CW23.Space.k(ind1_t(ind1));
    
end

