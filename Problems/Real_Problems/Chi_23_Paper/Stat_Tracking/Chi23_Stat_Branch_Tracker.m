 clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
 
    Res.Stat.In         = Params_LiNbd;
    Res.Stat.In.eps     = 2*pi*10E9;
    Res.Stat.In.delta_o = -12*Res.Stat.In.ko;
    Res.Stat.In.W       = 1e+05*Res.Stat.In.W_Star;
    Res.Stat.In.mu_bl   = 1;
    Res.Stat.In.N       = 2^7;
    ResStart            = Chi23_SolitonStartingSingleSolPoints(10, 1);%Res.Stat.In.mu_bl
    ResStart            = TransFormToBloch(ResStart,Res.Stat.In.mu_bl,Res.Stat.In.N);

    Res                 = Chi23TrackSoliton(ResStart,Res,15);

    %%
%     Res.Stat.Par.first_step       = 1; % step for delta measured in delta/kappa
%     Res.Stat.Par.step_tol         = 0.01;
%     Res.Stat.Par.variable         = 'eps';
%     Res.Stat.Par.step_inc         = 1.1;
%     Res.Stat.Par.step_dec         = 0.1;
%     Res.Stat.Par.Stability        = 1;
%     Res.Stat.Par.Newton_tol       = 2E-12;
%     Res.Stat.Par.top_boundary     =  1E5;
%     Res.Stat.Par.bop_boundary     = -1E5;
%     Res.Stat                      = Run_Branch_Universal(Res.Stat);
%%
    Res1 = Res2;
    Res1.Stat = Res2.Stat(1);
    Res1.Stat.Par.first_step       = 0.01; % step for delta measured in delta/kappa
    Res1.Stat.Par.step_tol         = 0.001;
    Res1.Stat.Par.variable         = 'delta_o';
    Res1.Stat.Par.step_inc         = 1.1;
    Res1.Stat.Par.step_dec         = 0.1;
    Res1.Stat.Par.Stability        = 1;
    Res1.Stat.Par.Newton_tol       = 2E-12;
    Res1.Stat.Par.top_boundary     =  1E5;
    Res1.Stat.Par.bop_boundary     = -1E5;
    Res1.Stat                      = Run_Branch_Universal(Res1.Stat);
%%
    Res2                           = Res1;
    Res2.Stat                      = Res1.Stat(84);
    Res2.Stat.Par.first_step       = 1E-13; % step for delta measured in delta/kappa
    Res2.Stat.Par.step_tol         = 1E-14;
    Res2.Stat.Par.variable         = 'W';
    Res2.Stat.Par.step_inc         = 1.1;
    Res2.Stat.Par.step_dec         = 0.1;
    Res2.Stat.Par.Stability        = 1;
    Res2.Stat.Par.Newton_tol       = 2E-12;
    Res2.Stat.Par.top_boundary     =  1E5;
    Res2.Stat.Par.bop_boundary     = -1E5;
    Res2.Stat                      = Run_Branch_Universal(Res2.Stat);


%%
function Res = Chi23_SolitonStartingSingleSolPoints(epsil,CR)

    switch epsil
        case 25
            
            Res = importdata('Data_eps25_Crystal2.mat');
            
        case 8
            switch CR
                case 1
                    Res = importdata('Data_eps8.mat');
                case 4
                    Res = importdata('Data_eps8_Crystal4.mat');
            end            
        case 9
          
            Res = importdata('Data_eps9.mat');
            
        case 10
          
            Res = importdata('Data_eps10.mat');
            
        case 13
            
            Res = importdata('Data_eps13.mat');
            
        case 15
            
            Res = importdata('Data_eps15.mat');
            
        case 18
            
            Res = importdata('Data_eps18.mat');
            
        case 26
            
            Res = importdata('Data_eps26.mat');
            
            
        case 24
            
            Res = importdata('Data_eps24.mat');     
            
    end
    
    
end
% function Stat =  ChangeToBloch(Stat,mu,N)
%     Stat.In.mu_bl = mu;
%     PsiO = zeros(1,N);
%     PsiE = zeros(1,N);
%     PsiO(1) = Stat.Sol.Psi_o(1);
%     PsiE(1) = Stat.Sol.Psi_e(1);
%     Stat.In.N = N;
%     Stat = Stat.Met.Norm(Stat);
%     for i = 2:round(N/Stat.In.mu_bl/2)
%         PsiO(i) = Stat.Sol.Psi_o(1+Stat.In.mu_bl*(i-1));
%         PsiE(i) = Stat.Sol.Psi_e(1+Stat.In.mu_bl*(i-1));
%         PsiO(end-(i-1)) = Stat.Sol.Psi_o(end-Stat.In.mu_bl*(i-1) + 1);
%         PsiE(end-(i-1)) = Stat.Sol.Psi_e(end-Stat.In.mu_bl*(i-1) + 1);
%     end
%     Stat.Sol.Psi_o = PsiO;
%     Stat.Sol.Psi_e = PsiE;
%     
% end
function Res = Chi23TrackSoliton(ReS,ReF,NN)

    
    delta_vector = linspace(ReS.Stat.In.delta_o,ReF.Stat.In.delta_o,NN);%W(2)delta(2)
    Power_vector = linspace(ReS.Stat.In.W,ReF.Stat.In.W,NN);
    eps_vector   = linspace(ReS.Stat.In.eps,ReF.Stat.In.eps,NN);
    
    Psi_o           = ifft(ReS.Stat.Sol.Psi_o*length(ReS.Stat.Sol.Psi_o));
    Psi_e           = ifft(ReS.Stat.Sol.Psi_e*length(ReS.Stat.Sol.Psi_o));
%      Psi_o           = (ReS.Stat.Sol.Psi_o)*ReS.Stat.Space.N;
%     Psi_e           = (ReS.Stat.Sol.Psi_e)*ReS.Stat.Space.N;
 
    Slv              = [real(Psi_o),imag(Psi_o)...
                    ,real(Psi_e),imag(Psi_e), -0.177418332087347];%
         
    Res = ReF;
    Res.Stat.Par.Newton_tol = 2E-13;
    Res.Stat.Par.Newton_iter  = 50;

    Res.Stat.In.delta_o  = delta_vector(1);
    Res.Stat.In.W        = Power_vector(1);
    Res.Stat.In.eps      = eps_vector(1);
    
    for i = 1:NN
        
        Res.Stat.In.delta_o  = delta_vector(i);
        Res.Stat.In.W        = Power_vector(i);
        Res.Stat.In.eps      = eps_vector(i);
        Res.Stat             = Res.Stat.Met.Norm(Res.Stat);
        
        [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,Res.Stat);
        [i,eps_f]
        
    end
        
    Res.Stat.Sol.Psi_o   = fft(Slv(1:Res.Stat.Space.N) + 1i*Slv(Res.Stat.Space.N+1:2*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.Psi_e   = fft(Slv(2*Res.Stat.Space.N+1:3*Res.Stat.Space.N) + 1i*Slv(3*Res.Stat.Space.N+1:4*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.V       = Slv(end);
    Res.Stat.Sol.eps_f   = eps_f;
    Res.Stat.Sol.Exitflag= Exitflag;
  
end
function ReB = TransFormToBloch(Res,mu,N)
    Res.Stat.In.N     = length(Res.Stat.Sol.Psi_o);
    Res.Stat.In.mu_bl = 1;
    Res.Stat          = Res.Stat.Met.Norm(Res.Stat);
    ReB               = Res; 
    ReB.Stat.In.mu_bl = mu;
    ReB.Stat.In.N     = N;
    
    ReB.Stat          = Res.Stat.Met.Norm(ReB.Stat);
    for i = 1:N
         ii = find(Res.Stat.Space.k == ReB.Stat.Space.k(i));
         if ~isempty(ii)
            ind_vec(i) = ii;
         end
    end
   
    ReB.Stat.Sol.Psi_o = zeros(1,N); 
    ReB.Stat.Sol.Psi_e = zeros(1,N);
    ReB.Stat.Sol.Psi_o = Res.Stat.Sol.Psi_o(ind_vec);
    ReB.Stat.Sol.Psi_e = Res.Stat.Sol.Psi_e(ind_vec); 
 %   ReB.Stat.Sol.Psi_o = Res.Stat.Sol.Psi_o(Res.Stat.Space.k == ReB.Stat.Space.k); 
end