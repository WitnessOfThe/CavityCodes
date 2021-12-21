    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    SiN       =  Set_Up_Methods_For_Turing_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for SiN  

    N_mode              =  2^8;
    SiN.Stat.In         =  Params_SiN_Modes( N_mode);    
    SiN.Stat.In.N_mode  =  N_mode;
    SiN.Stat.In.mu_bl   =  1;
    SiN.Stat.In.kappa   =  125E6*2*pi;
    SiN.Stat.In.delta   =  2.6929*SiN.Stat.In.kappa;
    SiN.Stat.In.P       =  0.047429;       
    
    SiN.CW.In           = SiN.Stat.In;
    SiN.Temp.In         = SiN.Stat.In;
    
%%
    NN = 36;
    
    Power_Start_Vector = linspace(0.005,0.05,NN);     
    Delta_Start_Vector = linspace(1.25,4,NN)*SiN.Stat.In.kappa;
    
%% Stationary Coefficeints

    SiN.Stat.Par.Equation_string  = 'Kerr_Full_Dispersion';        
    SiN.Stat.Met.Stab_Method      =  @LLE_Full_Stability;
    SiN.Stat.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    SiN.Stat.Met.Newton           = @fsolve;%'fsolve'
         
    SiN.Stat.Par.variable         = 'delta';  %%'Pump Power';
    SiN.Stat.Par.first_step       = 0.05; % step for delta measured in delta/kappa
    SiN.Stat.Par.step_tol         = 0.01;
    SiN.Stat.Par.step_inc         = 0.00;
    SiN.Stat.Par.step_dec         = 0.5;

    SiN.Stat.Par.bot_boundary     = -40; % bottom boundary for delta to search
    SiN.Stat.Par.top_boundary     =  602; % top boundary for delta to search
    SiN.Stat.Par.Sol_Re_Sign      = '-';
    SiN.Stat.Par.Stability        = 'Yes';
    SiN.Stat.Par.Newton_iter          = 30;      
    SiN.Stat.Par.Newton_tol           = 1E-10;  
    SiN.Stat.Par.i_max                = 1000;
    
    SiN.Stat.Par.fsolveoptions       = optimoptions('fsolve','CheckGradients',...
    false,'Display','iter','UseParallel',true,'SpecifyObjectiveGradient',true,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);
%%

    SiN.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    SiN.Temp.Par.dt            = 1E-4;
    SiN.Temp.Par.s_t           = 0.01;
    SiN.Temp.Par.T             = 2500;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
    SiN.Temp.Par.dd            = SiN.Temp.Par.T/SiN.Temp.Par.s_t;
    SiN.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(SiN.Temp.Par);

%%
    Res = SiN;
   
   
    Res.Stat               = Chi3_Stat_LLE_Stat_From_Cons_Soliton(Res.Stat);

    Res.Temp          = Chi_3_LLE_Normalization_Without_D_Coeff(Res.Temp);       
    Res               = Res.Temp.Met.Ev_Start_Point(Res);  
    Res.Temp.Met      = [];

    tic
    Res.Temp.Sol      = Chi_3_LLE_Runge_Kuarong_mex(Res.Temp,Runge);
    toc

%%
    ind_t = (size(Res.Temp.Sol.Psi,1)/2+1):size(Res.Temp.Sol.Psi,1);
            

    [d1,d2,d3] = Plot_Dynamics_Rf_pcolor_Soliton(Res.Stat,Res.Temp,ind_t,0)   ;
    [d4,d5]    = Plot_Dynamics_Result_pcolors(Res.Temp,1,0);
    [d6,d7]    = Plot_Dynamics_Result_LinePlots_Spectrums(Res.Temp,0);
    figure;    
    CF = conFigure([d1,d2,d3,d4,d5,d6,d7],2,4, 'UniformPlots', true, 'Height', 15, 'Width', 35,'Labels',false);
%%
    tau = (Res.Temp.Sol.t(ind_t(end)) - Res.Temp.Sol.t(ind_t(1)));%/ Res.Temp.Eq.norm
    N_t = size(ind_t,2);
    f = [0:N_t/2-1,-N_t/2:-1]/tau;
    k = fftshift(Res(1).Stat.Space.k(Res(1).Temp.Eq.mode_range));


    for i = 1:size(Res.Temp.Eq.mode_range,2)
        
        Power_mu(i)         = trapz(abs(Res.Temp.Sol.Psi(ind_t,i)).^2*2*pi)/tau*tau/N_t;
        freq_mu_avg(i)      = trapz(f.*abs(ifft(Res.Temp.Sol.Psi(ind_t,i))).^2.')./trapz(abs(ifft(Res.Temp.Sol.Psi(ind_t,i))).^2);
        [~,ind]             = max(abs(ifft(Res.Temp.Sol.Psi(ind_t,i))).^2);
        freq_mu_max(i)      = f(ind);
        
    end
    
    freq_vec = fftshift(freq_mu_max);
    vel_pl  = freq_vec(2:end) - freq_vec(1:end-1);
    vel_pl  = [vel_pl,NaN];
    vel_pl(abs(vel_pl) > 0.05) = NaN;
    freq_vec(abs(vel_pl) > 0.05) =NaN;
    vel_avg(1) = mean(vel_pl,'omitnan');
    f0_pl(1)  = mean(freq_vec - k.*vel_avg(1) ,'omitnan');
    m_t = fftshift(fftshift(ifft(Res.Temp.Sol.Psi(ind_t,:),[],1),1),2);
    for i = 1:size(Res.Stat.Eq.mode_range,2)
        f_matrix(:,i) = fftshift(f) - vel_avg*k(i);
    end
%%
figure;pcolor(k,f_matrix,10*log10(abs(m_t(:,:)).^2*2*pi));
shading flat;caxis([-70,0]);
%%
    figure;plot(f_matrix,10*log10(abs(m_t(:,:)).^2*2*pi),'Color',[0,0,0]);
    ylim([-70,10])
%%
k_vec = [-60:10:60];
figure;
hold on;
for ii = 1:size(k_vec,2)
    k_int = k_vec(ii);
    ind_k = k == k_int;
    plot3(k_vec(ii)*ones(1,N_t),f_matrix(:,ind_k),10*log10(abs(m_t(:,ind_k)).^2*2*pi));
end
zlim([-70,10])
ylim([-15,15])