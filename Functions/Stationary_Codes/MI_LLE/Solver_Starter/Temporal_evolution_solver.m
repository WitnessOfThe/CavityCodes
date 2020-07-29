function L_L = Temporal_evolution_solver(L_L,Delta,i,shift)
%% Extract Space
    
    k           = L_L.Space.k;
    L_L.Space.N = Delta.N;
    N =  Delta.N;   
    
%% Extract Time and 

%    Err_0    = Delta.Err;

    dt       = Delta.dt;
    nt       = Delta.Loops/Delta.dt;
    per_loop = Delta.per_loop;
    Loops    = Delta.Loops;
    NN       = round(nt/Loops/per_loop);    
    NNN      = Delta.Save_iter;
    
%%
    File_name = 0;
    if NNN ~= 1
        
        File_name = Create_Folders(Delta,L_L,NNN);
    end
%%  Initial Guess 

    fftw('dwisdom',[]);    
    fftw('planner','measure');
t=0;
switch Delta.Initial_Guess
   case '0'
        
        E   = zeros(1,N);
        F_e_cubic = zeros(1,N);
        F_e_cubic(1:N) =  1E-9.*[ones(1,N) + 1i*ones(1,N)];
        F_e_cubic(L_L.Dispersion.l_0) = 0;%L_L.Solution.CW.Psi(i);
%        F_e(L_L.In.pump_index) = E(1);    
        F_e = fft(E);
        F_e(1:N) = F_e(1:N) + 1E-6*[rand(1,N) + 1i*rand(1,N)];    
        E = ifft(F_e);    
        Q  = zeros(1,N)*L_L.Solution.CW.Q(i);
        Z  = zeros(1,N);

    case 'CW'
        
        phi_big = 2*pi/2/N*[-N:N-1];
        E_0_an                 = exp(1i*phi_big*(L_L.In.pump_index-1))*L_L.Solution.CW.Psi(i); 
        E_0_an                 = E_0_an + conj(E_0_an);
        F_e                    = 1E-7*ones(1,N);
        F_e(1)                 = L_L.Solution.CW.Psi(i)*N;
        
        F_e_cubic = zeros(1,N);
        F_e_cubic(1:200) = 1E-1*[rand(1,200) + 1i*rand(1,200)];
        F_e_cubic(L_L.In.pump_index) = L_L.Solution.CW.Psi(i);
%        F_e(L_L.In.pump_index) = E(1);    
%        F_e(2:N) = F_e(2:N) + 1E-8*[ones(1,N-1) + 1i*ones(1,N-1)];    
        Q  = ones(1,N)*L_L.Solution.CW.Q(i);
        Z  = zeros(1,N);    
    case 'CW_Phase'
        
        phi_big = 2*pi/2/N*[-N:N-1];
        E_0_an                 = exp(1i*phi_big*(L_L.In.pump_index-1))*L_L.Solution.CW.Psi(i); 
        E_0_an                 = E_0_an + conj(E_0_an);
        F_e                    = zeros(1,N);
        F_e(1:36)     = shift(1).*exp(1i*0);
        F_e(L_L.Space.N - 35 +1:L_L.Space.N)    = shift(2).*exp(1i*0);
        F_e(1)                 = L_L.Solution.CW.Psi(i)*N;
        
        F_e_cubic = zeros(1,N);
        F_e_cubic(1:N) = 1E-3*[rand(1,N) + 1i*rand(1,N)];
        F_e_cubic(L_L.In.pump_index) = L_L.Solution.CW.Psi(i);
%        F_e(L_L.In.pump_index) = E(1);    
%        F_e(2:N) = F_e(2:N) + 1E-8*[ones(1,N-1) + 1i*ones(1,N-1)];    
        Q  = ones(1,N)*L_L.Solution.CW.Q(i);
        Z  = zeros(1,N);    
        
    case 'Hamilt'
        
        c     = sqrt(L_L.Eq.delta);
        psi_s = c*sech(L_L.Space.phi.*c/sqrt(L_L.Eq.D2/2))/sqrt(L_L.Eq.gamma_3);
        hi    = acos( - L_L.Eq.h/2*sqrt(27*L_L.Eq.gamma_3/L_L.Eq.delta^3) );
        g     = 2*sqrt(L_L.Eq.delta/L_L.Eq.gamma_3)*cos( (hi-2*pi)/3 );
        E     =  g + psi_s;
        F_e   = fft(E);
        Q     = ones(1,N)*L_L.Solution.CW.Q(3);
        Z     = zeros(1,N);
        
   case 'Kerr_Soliton'
       
         F_e(1:size(L_L.Solution.Psi,2))                 = (L_L.Solution.E_j);
         F_e                 = circshift(fftshift(F_e), L_L.In.pump_index-1-size(L_L.Solution.Psi,2)/2);
         F_e(1)              = 0;
         F_e                 = [F_e,zeros(1,N-size(L_L.Solution.Psi,2))];
         F_e(N/2+1:end)      = 0;
         F_e_shifted         =                                zeros(1,N);
         F_e_shifted(2:N)    =                      flip( conj( F_e(2:N)) );
         Comp_Spectr         = [F_e,F_e_shifted];
         E_0                 =               ifft(Comp_Spectr)*2*N;%
         F_E_0               =                           fft(E_0)/N/2;%
         F_e_cubic          = F_E_0(1:N);   
         
   case 'Resume_Solution'
       
         F_e          = zeros(1,N);       
         if length( Delta.Physics) == length('Kuarong Kerr')
             F_e(L_L.Eq.Shifted.mode_range)                 = L_L.Solution.Temporal.E_s(i,:);
         end
         F_e_cubic          = zeros(1,N);
         F_e_cubic(L_L.Dispersion.eff_index)          = L_L.Solution.Temporal.E_s(i,:);
         t                  = L_L.Solution.Temporal.t(i);
end

    fftinfo = fftw('dwisdom');
    fftw('dwisdom',fftinfo);
%%
%% Extract linear operator and nonlienar operator parameters

%   

%    Pump           =   L_L.Eq.h*ones(1,N);
 %   gamma_3        =   L_L.Eq.gamma_3;
  %  mu_r           =   L_L.Raman.mu;
   % omega_0_2      =   L_L.Eq.Omega^2;
    %gamma_ramman   = 2*L_L.Eq.gamma_r;
   % omega_R        =   L_L.Eq.omega;
    
%% Define Runge Coeff

    Runge = Define_Runge_Coeff(Delta);

    %% Evalutate Time Evoulution
switch Delta.Physics
     case 'Second Harmonic Split'
         
         
         Psi_o_0 = ones(1,N)*L_L.Solution.CW.Psi_p(3)+1i*ifft(1E-4*[ones(1,N/4),zeros(1,2*N/4),ones(1,N/4)]);
         Psi_e_0 = ones(1,N)*L_L.Solution.CW.Psi_s(3)+1i*ifft(1E-4*[ones(1,N/4),zeros(1,2*N/4),ones(1,N/4)]);
         
         L_L.Solution.Temporal = Split_chi_2(Psi_o_0,Psi_e_0,L_L.Eq.gamma2_o,L_L.Eq.gamma2_e,...
         L_L.Eq.h,L_L.Eq.h_prob,L_L.In.mu_p,L_L.Eq.L_o,L_L.Eq.L_e,dt,nt,NN,Loops,per_loop,N,Runge,...
         Delta,0,L_L.Space.k,L_L.Eq.omega_probe,L_L.Eq.k_o,L_L.Eq.k_e);
     
     case'Second Harmonic'
         
         
         Psi_o_0(1) = L_L.Solution.CW.Psi_p(3)*N;
         Psi_e_0(1) = L_L.Solution.CW.Psi_s(3)*N;
         
         Psi_o_0([1:N/8,(7*N/8+1):N]) = 1E-8*ones(1,N/4);
         Psi_e_0([1:N/8,(7*N/8+1):N]) = 1E-12*ones(1,N/4);

         
         L_L.Solution.Temporal = Runge_Kuarong_chi_2(Psi_o_0,Psi_e_0,L_L.Eq.gamma2_o,L_L.Eq.gamma2_e,...
         L_L.Eq.h,L_L.Eq.h_prob,L_L.In.mu_p,L_L.Eq.L_o,L_L.Eq.L_e,dt,nt,NN,Loops,per_loop,N,Runge,...
         Delta,[1:N],L_L.Space.k,L_L.Eq.omega_probe,L_L.Eq.k_o,L_L.Eq.k_e);
     
     case 'Kuarong Kerr'
         % - L_L.Eq.D(1)*L_L.Space.k
        L              =     L_L.Eq.Shifted.omega_j  + L_L.Eq.delta;    
        l = [1:Delta.N]-1;
        l              =     circshift(l,-L_L.In.pump_index).*L_L.Eq.Shifted.mask;
        D_norm         =     L_L.Eq.D(1);
    
        L_L.Solution.Temporal      =  Runge_Kuarong_Kerr(F_e,L_L.Eq.Shifted.gamma_Kerr,...
                                       L_L.Eq.h,L,dt,nt,NN,Loops,per_loop,N,...
                                       Runge,Delta,L_L.Eq.Shifted.mode_range,l,...
                                       D_norm,L_L.In.pump_index,...
                                        1);
        
     case 'Full-Runge Explicit Kerr'
        L              =  L_L.Eq.Shifted.omega_j  + L_L.Eq.delta;    
        
        [F_s,t_s]      =  Full_Runge_Kerr(F_e,L_L.Eq.gamma_3,L_L.Eq.h,L,dt,nt,NN,Loops,per_loop,N,Runge,Delta,l,L_L.Eq.D);
        
        L_L.Solution.Temporal.E_s = F_s;
        L_L.Solution.Temporal.t   = t_s;
        
     case 'Full-Runge Implicit Kerr'
        
        [F_s,t_s]      =   Full_Runge_Impicit_Kerr(E,gamma_3,Pump,L,dt,nt,NN,Loops,per_loop,N,Runge,Delta,2*pi,L_L.Eq.D2,L_L.Eq.D3,L_L.Eq.D4,L_L.Eq.delta,L_L.Eq.gamma);
        
        L_L.Solution.Temporal.Phi = F_s;
        L_L.Solution.Temporal.t   = t_s;
        
     case 'Full-Runge ESDIRK Kerr'
        
        [F_s,t_s]      =  Full_Runge_ESDIRK_Kerr(E,gamma_3,Pump,L,dt,round(nt),NN,Loops,per_loop,N,Runge,Delta,2*pi,L_L.Eq.D2,L_L.Eq.D3,L_L.Eq.D4,L_L.Eq.delta,L_L.Eq.gamma);
        
        L_L.Solution.Temporal.Phi = F_s;
        L_L.Solution.Temporal.t   = t_s;
        
     case 'Kuarong Raman'
        
        [F_s,Q_s,t_s]      =  Runge_Kuarong_Raman(F_e,Q,Z,gamma_3,Pump,L,dt,nt,NN,Loops,per_loop,N,Runge,Delta,mu_r,omega_0_2,gamma_ramman);
        
        L_L.Solution.Temporal.Phi = F_s;
        L_L.Solution.Temporal.Q   = Q_s;
        L_L.Solution.Temporal.t   = t_s;

    case 'Full-Runge Explicit Cubic'
        

        L_L.Solution.Temporal   =    Full_Runge_Cubic(F_e_cubic,dt,nt,NN,NNN,N,Runge,Delta,L_L.Eq.gamma_cubic_vector,L_L.Eq.kappa_vector,Delta.Detunning_change/L_L.In.norm_coeff,L_L.Eq.Pump,real(L_L.Eq.omega_j),real(L_L.Eq.omega_j(L_L.In.pump_index)) - L_L.Eq.delta,File_name,Delta.h_change,t);

    case 'Full-Runge Explicit Cubic Reduced'
        
        L_L.Solution.Temporal   =    Full_Runge_Cubic_Reduced(F_e_cubic,dt,nt,NN,NNN,N,Runge,Delta,L_L.Eq.gamma_cubic_vector,L_L.Eq.kappa_vector,Delta.Detunning_change/L_L.In.norm_coeff,L_L.Eq.Pump,real(L_L.Eq.omega_j),real(L_L.Eq.omega_j(L_L.In.pump_index)) - L_L.Eq.delta,File_name,Delta.h_change,t);
        
    case 'Full-Runge Explicit Cubic Reduced Adapt'
        
        [B_s,E_s,t_s]      =    Full_Runge_Cubic_Reduced_Adaptive(F_e_cubic,dt,nt,NN,Loops,per_loop,N,Runge,Delta,L_L.Eq.gamma_cubic,L_L.Space.phi,L_L.Eq.kappa_vector,L_L.Eq.delta,L_L.Eq.Pump,L_L.Eq.omega_j,L_L.Eq.m,-(real(L_L.Eq.omega_j(L_L.In.pump_index)) - L_L.Eq.delta));
        
        L_L.Solution.Temporal.B_s = B_s;
        L_L.Solution.Temporal.E_s = E_s;
        L_L.Solution.Temporal.t   = t_s;

%     case 'Runge_5_Stiff_Kerr'
%         
%         [B_e,F_s,t_s]      = Runge_5_stiff_Kuarong_Kerr(F_e,gamma_3,Pump,L,dt,N,NN,Loops,per_loop,nt);
%         
%         L_L.Solution.Temporal.Phi = F_s;
%         L_L.Solution.Temporal.B_e = B_e;
%         L_L.Solution.Temporal.t   = t_s;
%         
%      case 'Runge_5_Adaptive_Kerr_DORPI5'
%          
%         [B_e,F_s,t_s,dt,t] =   Runge_4_5_Adaptive_Kuarong_Kerr_DORPI5(F_e,gamma_3,Pump,L,dt,N,NN,Loops,per_loop,nt,Delta.Err.abs,Delta.Err.rel);
%         
%         L_L.Solution.Temporal.dt    = dt; 
%         L_L.Solution.Temporal.Phi   = F_s;
%         L_L.Solution.Temporal.t_s   = t_s;  
%         L_L.Solution.Temporal.t     = t;
%         
%      case 'Runge_5_Adaptive_Raman'
%         L_q             = ones(1,N)*(-omega_R - 1i*L_L.Eq.gamma_r);
%         [F_s,F_Q_s,t_s,dt,t]      =  Runge_Kuarong_Raman_Adaptive(F_e,Q,Z,gamma_3,Pump,L,L_q,dt,nt,NN,Loops,per_loop,N,Err_0,mu_r,omega_0_2,gamma_ramman,omega_R,Delta.dt_abs);
%         
%         L_L.Solution.Temporal.dt    = dt;
%         L_L.Solution.Temporal.Phi   = F_s;
%         L_L.Solution.Temporal.F_Q   = F_Q_s;
%         L_L.Solution.Temporal.t_s   = t_s;
%         L_L.Solution.Temporal.t     = t;
%         
%      case 'Runge_5_Raman_DOPRI5'
%         L_q             = ones(1,N)*(-omega_R - 1i*L_L.Eq.gamma_r);
%         [F_s,F_Q_s,t_s]      =  Runge_5_Kuarong_Raman_DOPRI5(F_e,Q,Z,gamma_3,Pump,L,L_q,dt,nt,NN,Loops,per_loop,N,mu_r,omega_0_2,gamma_ramman);
%         
%         L_L.Solution.Temporal.dt    = dt;
%         L_L.Solution.Temporal.Phi   = F_s;
%         L_L.Solution.Temporal.F_Q   = F_Q_s;
%         L_L.Solution.Temporal.t_s   = t_s;
%         L_L.Solution.Temporal.t     = t;
% 
%         
% end
end
end
%%
function Runge = Define_Runge_Coeff(Delta)

switch Delta.Runge_Type 
    
    case 'ARK-6-3-4'
        
        Runge.b      = [        0,                            0,                            0,                          0,            0,        0;
                              1/2,                            0,                            0,                          0,            0,        0;
                      13861/62500,                   6889/62500,                            0,                          0,            0,        0;
      -116923316275/2393684061468,-2731218467317/15368042101831, 9408046702089/11113171139209,                          0,            0,        0;
      -451086348788/2902428689909,- 2682348792572/7519795681897,12662868775082/11960479115383,3355817975965/11060851509271,           0,        0;
                             12/5,    73281519250/8382639484533,   552539513391/3454668386233, 3354512671639/8306763924573,  4040/17871,        0];
                    
        Runge.a     = [   0,1/2,     83/250,  31/50,     17/20,   1];           
        Runge.c     = [ 82889/524892,0,15625/83664,69875/102672,-2260/8211,1/4];
        Runge.c_l   = [ 4586570599/29645900160,0,178811875/945068544,814220225/1159782912,-3700637/11593932,61727/225920];
        
    case 'Verner-8-5-6'
        
        Runge.b      = [        0,        0,           0,        0,          0,        0,          0,      0;
                              1/6,        0,           0,        0,          0,        0,          0,      0;
                             4/75,    16/75,           0,        0,          0,        0,          0,      0;
                              5/6,     -8/3,         5/2,        0,          0,        0,          0,      0;
                          -165/64,     55/6,     -425/64,    85/96,          0,        0,          0,      0;
                             12/5,       -8,    4015/612,   -11/36,     88/255,        0,          0,      0;
                      -8263/15000,   124/75,    -643/680,  -81/250, 2484/10625,        0,          0,      0;
                        3501/1720,  -300/43,297275/52632,-319/2322,24068/84065,        0, 3850/26703,      0];
                    
        Runge.a     = [   0,1/6,      4/15,  2/3,     5/6,   1,     1/15,1];           
        Runge.c     = [  3/40,0, 875/2244,23/72,264/1955,   0,125/11592,43/616];
        Runge.c_l   = [13/160,0,2375/5984, 5/16,   12/85,3/44,        0,     0];   
        
    case 'Runge Ralston'
        
        Runge.b      = [  0,0,0;
                        1/2,0,0;            
                        0,3/4,0]; 
        Runge.a     = [ 0,1/2,3/4];   
        Runge.c     = [2/9,1/3,4/9];   
        
    case 'Runge SSPRK3'
        
        Runge.b      = [ 0,0,0;
                        1,0,0;            
                        1/4,1/4,0]; 
        Runge.a     = [ 0,1,1/2];   
        Runge.c     = [1/6,1/6,2/3];   
        
    case 'Runge 4'
        
        Runge.b      = [  0,0,0;
                        1/2,0,0;
                        0,1/2,0;            
                        0,  0,1];
        Runge.a     = [0,1/2,1/2,1];
        Runge.c     = [1/6,1/3,1/3,1/6];
        
    case 'Runge 4-5 DOPRI5'
        
        Runge.b      = [          0,            0,         0,0,0;
                                1/5,            0,         0,0,0;
                               3/40,         9/40,         0,0,0;            
                              44/45,       -56/15,      32/9,0                  ,0;
                         19372/6561, - 25360/2187,64448/6561,-212/729           ,0;
                          9017/3168,     - 355/33,46732/5247,  49/176,-5103/18656]; 
        Runge.a     = [0,1/5,3/10,4/5,8/9,1];  
        Runge.c     = [35/384    ,0,  500/1113  ,125/192,   -2187/6784,    11/84];
        Runge.c_l   = [5179/57600,0,  7571/16695,393/640,-92097/339200,187/2100,1/40];
        
    case 'Runge 7-8 FEHLBERG'
        
        Runge.b      = [          0,            0,         0,      0,          0,      0,         0,      0,       0,      0,0,0;
                               2/27,            0,         0,      0,          0,      0,         0,      0,       0,      0,0,0;
                               1/36,         1/12,         0,      0,          0,      0,         0,      0,       0,      0,0,0;
                               1/24,           0,        1/8,      0,          0,      0,         0,      0,       0,      0,0,0;            
                               5/12,           0,     -25/16,  25/16,          0,      0,         0,      0,       0,      0,0,0;
                               1/20,           0,         0,     1/4,        1/5,      0,         0,      0,       0,      0,0,0;
                            -25/108,           0,         0, 125/108,     -65/27, 125/54,         0,      0,       0,      0,0,0;
                             31/300,           0,         0,       0,     61/225,   -2/9,    13/900,      0,       0,      0,0,0;
                                  2,           0,         0,   -53/6,     704/45, -107/9,     67/90,      3,       0,      0,0,0;
                            -91/108,           0,         0,  23/108,   -976/135, 311/54,    -19/60,   17/6,   -1/12,      0,0,0;
                          2383/4100,           0,         0,-341/164,  4496/1025,-301/82, 2133/4100,  45/82,  45/164,  18/41,0,0
                              3/205,           0,         0,       0,          0,  -6/41,    -3/205,  -3/41,    3/41,   6/41,0,0
                         -1777/4100,           0,         0,-341/164,  4496/1025,-289/82, 2193/4100,  51/82,  33/164,  19/41,0,1]; 
        Runge.a     = [0,2/27,1/9,1/6,5/12,1/2,5/6,1/6,2/3,1/3,1,0,1];  
        Runge.c     = [41/840,0,0,0,0,34/105,9/35,9/35,9/280,9/280,41/840,0,0];
        Runge.c_l   = [0,0,0,0,0,34/105,9/35,9/35,9/280,9/280,0,41/840,41/840];
        
    case 'Runge 5-3-4 ESDIRK'
        
        Runge.b      = [          0,            0,         0,       0,        0,       0;
                                1/4,          1/4,         0,       0,        0,       0;
                               1/16,        -1/16,       1/4,       0,        0,       0;            
                               1/16,        -1/16,       1/2,     1/4,        0,       0;
                              -9/62,      -77/124,   143/124,  45/124,      1/4,       0;
                               7/90,         2/15,     16/45,   16/45,  -31/180,    1/4]; 
        Runge.a     = [ 0, 1/2, 1/4, 3/4,1,1];  
        Runge.gamma = 1/4;
        Runge.s     = 5;
        Runge.c     = [ 7/90,         2/15,     16/45,   16/45,  -31/180,    1/4];
        Runge.c_l   = [    0,         -1/3,       2/3,     2/3,        0,      0];
        
    case 'Runge 4-3-4 ESDIRKb'
        
        Runge.b      = [                      0,                         0,                      0,                    0,                     0;
                               0.43586652150846,          0.43586652150846,                      0,                    0,                     0;
                               0.14073777472471,        - 0.10836555138132,       0.43586652150846,                    0,                     0;            
                               0.10239940061991,        - 0.37687845225556,       0.83861253012719,     0.43586652150846,                     0;
                               0.15702489786032,          0.11733044137044,       0.61667803039212,    -0.32689989113134,      0.43586652150846];
        Runge.a     = [0,0.87173304301692,0.46823874485185,1,1];  
        Runge.gamma = 0.43586652150846;
        Runge.s     = 4;
        Runge.c     = [0.10239940061991, - 0.37687845225556,    0.83861253012719,   0.43586652150846,  0];
        Runge.c_l   = [0.15702489786032,   0.11733044137044,    0.61667803039212, - 0.32689989113134,  0.43586652150846];
        
    case 'Runge 5-3-4 SDIRKb'
        
        Runge.b      = [                     1/4,                         0,                      0,                    0,                     0;
                                             1/2,                       1/4,                      0,                    0,                     0;
                                           17/50,                     -1/25,                    1/4,                    0,                     0;            
                                        371/1360,                 -137/2720,                 15/544,                  1/4,                     0;
                                           25/24,                    -49/48,                 125/16,               -85/12,                  1/4];
        Runge.a     = [1/4,3/4,11/20,1/2,1];  
        Runge.gamma = 1/4;
        Runge.s     = 4;
        Runge.c     = [ 25/24,                    -49/48,                 125/16,               -85/12,                  1/4];
        
    %    Runge.c_l   = [0.15702489786032,   0.11733044137044,    0.61667803039212, - 0.32689989113134,  0.43586652150846];
    
    case 'Runge 8-4-5 ESDIRK'   
        Runge.b      = [                         0,                           0,                             0,                               0,                           0,                             0,                            0,       0; 
                                            41/200,                      41/200,                             0,                               0,                           0,                             0,                            0,       0;         
                                            41/400,-567603406766/11931857230679,                        41/200,                               0,                           0,                             0,                            0,       0;
                        683785636431/9252920307686,                           0,   -110385047103/1367015193373,                          41/200,                           0,                             0,                            0,       0;
                      3016520224154/10081342136671,                           0, 30586259806659/12414158314087, - 22760509404356/11113319521817,                      41/200,                             0,                            0,       0;
                        218866479029/1489978393911,                           0,    638256894668/5436446318841, -   1179710474555/5321154724896,  -60928119172/8023461067671,                        41/200,                            0,       0;
                       1020004230633/5715676835656,                           0, 25762820946817/25263940353407, -   2161375909145/9755907335909, -211217309593/5846859502534,-  4269925059573/7827059040749,                       41/200,       0;
                    -   872700587467/9133579230613,                           0,                             0,    22348218063261/9555858737531,-1143369518992/8141816002931,-39379526789629/19018526304540, 32727382324388/42900044865799, 41/200];      
        Runge.a     = [41/100,2935347310677/11292855782101,1426016391358/7196633302097,92/100,24/100,3/5,1];  
        Runge.gamma = 0.26;
        Runge.s     = 7;
        Runge.c     = [                    -   872700587467/9133579230613,                           0,                             0,    22348218063261/9555858737531,-1143369518992/8141816002931,-39379526789629/19018526304540, 32727382324388/42900044865799, 41/200];
       Runge.c_l   = [-975461918565/9796059967033,0,0,78070527104295/32432590147079,-548382580838/3424219808633,-33438840321285/15594753105479,3629800801594/4656183773603,4035322873751/18575991585200];

end

end
function File_name =Create_Folders(Delta,L_L,NNN)
  File_name = strcat(Delta.File_name,'/Power=',num2str(L_L.In.P),'/');
    
     if NNN ~= 1

        [status,msg] = mkdir(File_name);

    end

    File_name = strcat(File_name,'/Delta=',num2str(L_L.Eq.de5lta*L_L.Dispersion.D(1)/2/pi,'%10.3e'));
    
     if NNN ~= 1

        [status,msg] = mkdir(File_name);

     end
     
     File_name = strcat(File_name,'/Model=',Delta.Physics,'_||_Algorythm=',Delta.Runge_Type);    
    
     if NNN ~= 1

        [status,msg] = mkdir(File_name);
        
     end
    
     File_name = strcat(File_name,'/InitialGuess=',Delta.Initial_Guess,'_||_dt=',num2str(Delta.dt));    

     if NNN ~= 1

        [status,msg] = mkdir(File_name);
        save(strcat(File_name,'/L_L','.mat'),'L_L');
        
     end
end
