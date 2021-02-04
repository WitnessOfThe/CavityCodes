    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = -2*pi*10E9;
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
    W_Finish     = 10000;
    delta_Finish = 3;
    
    W                 = [10,5.6320e+04];
    delta             = [10,9.6489];
    
    Res = Get_to_point(Res,W,delta);
    
%%
    Res.Stat.In           = Res.CW.In;
    Res.Stat.Par          = Res.CW.Par;
    
    Res.Stat.In.N         = 2^8;
    Res.Stat.Met.Newton   = @Newton_Manual_bicgstab;%'fsolve'
    
    Res.Stat              = Res.Stat.Met.Norm(Res.Stat);
    
    Res.Stat.Sol.Psi_o    = zeros(1,Res.Stat.Space.N);
    Res.Stat.Sol.Psi_e    = zeros(1,Res.Stat.Space.N);
    
    Res.Stat.Sol.Psi_o(1) = Res.CW.Sol.Psi_o;
    Res.Stat.Sol.Psi_e(1) = Res.CW.Sol.Psi_e; 
    
    Slv_Start               = [real(Res.Stat.Sol.Psi_o),imag(Res.Stat.Sol.Psi_o)...
                    ,real(Res.Stat.Sol.Psi_e),imag(Res.Stat.Sol.Psi_e),0]*Res.Stat.Space.N;
    
    [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Res.Stat);
    
    Res.Stat.Sol.Psi_o   = (Slv(1:Res.Stat.Space.N) + 1i*Slv(Res.Stat.Space.N+1:2*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.Psi_o   = (Slv(1:Res.Stat.Space.N) + 1i*Slv(Res.Stat.Space.N+1:2*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.V       = Slv(end);
    Res.Stat.Stab        = Stability_Switcher(Res.Stat);

%%    
function Res = Get_to_point(Res,W,delta)    
    
    NN = 1000;
    delta_vector          = linspace(delta(1),delta(2),NN);
    W_vector              = linspace(W(1),W(2),NN);
    
    Res.CW.In.W           = W(1)*Res.CW.In.W_Star;        
    Res.CW.In.delta       = delta(1)*Res.CW.In.ko;        
    
    Res.CW                = Res.CW.Met.Solve_Chi2(Res.CW ); 

    [~,ind]               = max(abs(Res.CW.Sol.Omega));

    Res.CW.Sol.Omega      =  Res.CW.Sol.Omega(ind);    
    Res.CW.Sol.Psi_o      =  Res.CW.Sol.Psi_o(ind);    
    Res.CW.Sol.Psi_e      =  Res.CW.Sol.Psi_e(ind);

        for i_d = 1:NN

            Res.CW.In.delta_o    = delta_vector(i_d)*Res.CW.In.ko;            
            Res.CW.In.W         = W_vector(i_d)*Res.CW.In.W_Star;            
            Res.CW               = Res.CW.Met.Norm(Res.CW);  
            [Slv,eps_f,Exitflag] = Newton_Switcher([real(Res.CW.Sol.Psi_o(1)),imag(Res.CW.Sol.Psi_o(1)),real(Res.CW.Sol.Psi_e(1)),imag(Res.CW.Sol.Psi_e(1))],Res.CW);
            Res.CW               = Res.CW.Met.Prop_Gen(Slv,Res.CW);          
            
            if eps_f > 1E-5
                
                break;
                
            end        
        end
        
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

    
        
%%
function Chi23_Stat_From_CW(Res)
    
end