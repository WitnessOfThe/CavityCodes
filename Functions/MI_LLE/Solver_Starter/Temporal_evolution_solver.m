function L_L = Temporal_evolution_solver(L_L)

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
    t = 0;
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

function File_name = Create_Folders(Delta,L_L,NNN)
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
