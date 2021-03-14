    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = 2*pi*5E9;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 2^7;
    Res.CW.In.W       = 100000*Res.CW.In.W_Star;
    
%%
    Res.CW.Par.Equation_string  = 'Chi23_CW';
    Res.CW.Met.Equation         = @Chi23_CW;
    Res.CW.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    Res.CW.Met.Newton           = @fsolve;%'fsolve'
    Res.CW.Par.Change_Space     = 0;
    
    Res.CW.Par.variable         = 'delta_o';  %%'Pump Power';
    Res.CW.Par.first_step       = 0.02; % step for delta measured in delta/kappa
    Res.CW.Par.step_tol         = 0.001;
    Res.CW.Par.step_inc         = 1.01;
    Res.CW.Par.step_dec         = 0.1;

    Res.CW.Par.bot_boundary     = -120; % bottom boundary for delta to search
    Res.CW.Par.top_boundary     =  200; % top boundary for delta to search
    Res.CW.Par.Sol_Re_Sign      = '-';
    Res.CW.Par.Stability        = true;
    Res.CW.Par.Newton_iter      = 25;      
    Res.CW.Par.Newton_tol       = 1E-10;
    Res.CW.Par.i_max            = 1000;
    Res.CW.Par.Turning = 0;

    Res.CW.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',false,'SpecifyObjectiveGradient',false,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-25,'OptimalityTolerance',1E-25,'FunctionTolerance',10^(-10));

%%
    W_Finish     = 10000;
    delta_Finish = 3;
   
    %    W                 = [1.3E5,6000000];
    %    delta             = [-100,-15];
    
    W                = [1.3E3,30E6];
    delta            = [100,93];
   
    Res = Get_to_point(Res,W,delta);
   
%%
    Res.Stat.In           = Res.CW.In;
    Res.Stat.Par          = Res.CW.Par;    
    Res.Stat.In.mu_bl     = 43;    
    Res.Stat.In.N         = 2^6;
    Res.Stat.Met.Newton   = @Newton_Manual_bicgstab;%'fsolve'
    
    Res.Stat              = Res.Stat.Met.Norm(Res.Stat);
        
    Res.CW.Met.MI_Matrix   = @Chi23_MI_Matrix;
    Res.CW.Stab            =  Chi23_MI(Res.CW);
    Res.Stat.Sol.Psi_o     =  1E-10*ones(1,Res.Stat.Space.N);
    Res.Stat.Sol.Psi_e     =  1E-10*ones(1,Res.Stat.Space.N);
    
    
    [i_k,i_c] = find(real(Res.CW.Stab.Value) == max(max(real(Res.CW.Stab.Value))));
    i_k = Res.Stat.In.mu_bl+1;
    i_k = find(abs(Res.Stat.Space.k) == abs(Res.Stat.Space.k(i_k)));
    
    i_c = zeros(1,2);
    
    [~,i_c(1)]  = max(real(Res.CW.Stab.Value(i_k(1),:)) );
    [~,i_c(2)]  = max(real(Res.CW.Stab.Value(i_k(2),:)) );
    
    Res.Stat.Sol.Psi_o(1)  = Res.CW.Sol.Psi_o*Res.Stat.Space.N;       
    Res.Stat.Sol.Psi_e(1)  = Res.CW.Sol.Psi_e*Res.Stat.Space.N;      
    
    coeff = 1.51;
    
    Res.Stat.Sol.Psi_o(2)  = (Res.CW.Stab.Vector(i_k(1)).V(1,i_c(1)) )*coeff*Res.Stat.Space.N;       %+ Res.CW.Stab.Vector(i_k(2)).V(1,i_c(2) )
    Res.Stat.Sol.Psi_e(2)  = (Res.CW.Stab.Vector(i_k(1)).V(2,i_c(1)) )*coeff*Res.Stat.Space.N;     %+ Res.CW.Stab.Vector(i_k(2)).V(2,i_c(2) )
    
    Res.Stat.Sol.Psi_o(end)  = (Res.CW.Stab.Vector(i_k(1)).V(3,i_c(1)) )*coeff*Res.Stat.Space.N;       %+ Res.CW.Stab.Vector(i_k(2)).V(3,i_c(2))
    Res.Stat.Sol.Psi_e(end)  = (Res.CW.Stab.Vector(i_k(1)).V(4,i_c(1)) )*coeff*Res.Stat.Space.N;    %+ Res.CW.Stab.Vector(i_k(2)).V(4,i_c(2))  
    
    Res.Stat.Sol.Psi_o           = ifft(Res.Stat.Sol.Psi_o);
    Res.Stat.Sol.Psi_e           = ifft(Res.Stat.Sol.Psi_e);
    
    Slv_Start               = [real(Res.Stat.Sol.Psi_o),imag(Res.Stat.Sol.Psi_o)...
                    ,real(Res.Stat.Sol.Psi_e),imag(Res.Stat.Sol.Psi_e),(imag(Res.CW.Stab.Value(i_k(1),i_c(1))))/Res.Stat.In.mu_bl];
    
    [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Res.Stat);
    
    Res.Stat.Sol.Psi_o   = fft(Slv(1:Res.Stat.Space.N) + 1i*Slv(Res.Stat.Space.N+1:2*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.Psi_e   = fft(Slv(2*Res.Stat.Space.N+1:3*Res.Stat.Space.N) + 1i*Slv(3*Res.Stat.Space.N+1:4*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.V       = Slv(end);
    
%    Res.Stat.Stab        = Stability_Switcher(Res.Stat);

%%    
   Res.Stat              = Run_Branch_Universal(Res.Stat);
    
%%

%%
%%
function Res = Get_to_point(Res,W,delta)    
    
    NN = 1000;
    delta_vector          = linspace(delta(1),delta(2),NN);
    W_vector              = linspace(W(1),W(2),NN);
    
    Res.CW.In.W           = W(1)*Res.CW.In.W_Star;        
    Res.CW.In.delta       = delta(1)*Res.CW.In.ko;        
    
    Res.CW                = Res.CW.Met.Solve_Chi2(Res.CW ); 

    [~,ind]               = min(abs(Res.CW.Sol.Omega));

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