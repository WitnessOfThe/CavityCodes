    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    CaF       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF


    N_mode              = 2^9;
    CaF.Stat.In         = Params_CaF;
    CaF.Stat.In.kappa   = 2E3*2*pi;                 
    
    CaF.Temp.In         = CaF.Stat.In;
    
%% Stationary Coefficeints

    CaF.Stat.Par.i_max                = 2000;
    CaF.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    
    CaF.Stat.Met.InitialGuess         = @Stat_In_Guess_Chi_3_LLE_From_Dyn;    
    CaF.Stat.Met.Newton               = @Newton_Manual_bicgstab;%'fsolve'
    
    CaF.Stat.Par.step_tol             = 1E-10;
    CaF.Stat.Par.Stability            = 'Yes';
    CaF.Stat.Par.variable             = 'delta';  
    CaF.Stat.Par.first_step           = 1/2; %min =1E-4/3
    CaF.Stat.Par.Newton_iter          = 50;      
    CaF.Stat.Par.Newton_tol           = 1E-9;  
    CaF.Stat.Par.i_max                = 2000;
    CaF.Stat.Par.CW_num               = 3;
    
%%

    NN = 32;
    delta_vector = linspace(-0.1683,-0.178,NN)*1E6*2*pi; 
    power_vector = linspace(0.0265,0.0037,NN);
    
%% Temporal Coefficients

   CaF.Stat.In.P       = power_vector(1);
   CaF.Stat.In.delta   = delta_vector(1);
    
   CaF = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW(CaF,N_mode);
    
   CaF_down.Stat             =  Chi_3_Stat_Wierd_Pattern_Tracking(CaF.Stat,delta_vector,power_vector);
    
    delta_vector_upp          = fliplr(delta_vector);
    power_vector_upp          = fliplr(power_vector);
    
    CaF.Stat.In.P       = power_vector_upp(1);
    CaF.Stat.In.delta   = delta_vector_upp(1);

    
    CaF = Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW(CaF,N_mode);
    CaF.Stat.In.Psi_Start = CaF.Stat.Sol.Psi_k;
    CaF_up.Stat             =  Chi_3_Stat_Wierd_Pattern_Tracking(CaF.Stat,delta_vector_upp,power_vector_upp);
    
%%
parpool(32)
for i=1:NN
    
    CaF(i).Stat               = CaF_up.Stat(i);
    CaF(i).Stat.In.Psi_Start  = CaF_up.Stat(i).Sol.Psi_k;
    
end

parfor i = 1:NN
    
    CaF_Branc_up(i).Stat  = Run_Branch_Universal(CaF(i),N_mode);
    
end
for i=1:NN
    
    CaF(i).Stat               = CaF_down.Stat(i);
    CaF(i).Stat.In.Psi_Start  = CaF_down.Stat(i).Sol.Psi_k;
    
end
parfor i = 1:NN
    
    CaF_Branc_dw(i).Stat  = Run_Branch_Universal(CaF(i),N_mode);
    
end
%%
for i_p = 1:NN
    for i_d = 1:size(CaF_Branc_up(i_p).Stat,2)
        
      delta_u(i_p,i_d) = CaF_Branc_up(i_p).Stat(i_d).In.delta;
      P_u   (i_p,i_d)  = CaF_Branc_up(i_p).Stat(i_d).In.P;        
      U_10_u(i_p,i_d)  = CaF_Branc_up(i_p).Stat(i_d).Sol.Psi_k(20);
        
    end
end
for i_p = 1:NN
    for i_d = 1:size(CaF_Branc_dw(i_p).Stat,2)
        
      delta_d(i_p,i_d) = CaF_Branc_dw(i_p).Stat(i_d).In.delta;
      P_d(i_p,i_d)     = CaF_Branc_dw(i_p).Stat(i_d).In.P;        
      U_10_d(i_p,i_d)  = CaF_Branc_dw(i_p).Stat(i_d).Sol.Psi_k(20);
        
    end
end
%%
delta_d(delta_d == 0) = NaN;
P_d(P_d == 0) = NaN;
U_10_d(U_10_d == 0) = NaN;
delta_u(delta_u == 0) = NaN;
P_u(P_u == 0) = NaN;
U_10_u(U_10_u == 0) = NaN;

figure;
mesh(delta_d/2/pi,P_d,abs(U_10_d));
hold on;
mesh(delta_u/2/pi,P_u,abs(U_10_u));
xlim([-0.18,-0.15]*1E6)
%%
figure;
ii = 15;

plot(delta_d(ii,:)/2/pi,abs(U_10_d(ii,:)),delta_u(P_u(:,1) == P_d(ii,1),:)/2/pi,abs(U_10_u(P_u(:,1) == P_d(ii,1),:)));

%%
    for i = 1:NN

        Power_upp(i) = CaF_up.Stat(i).Sol.Psi_k(20);
        Power_dow(i) = CaF_down.Stat(i).Sol.Psi_k(20);

        U_upp(i,:) = abs(ifft(CaF_up.Stat(i).Sol.Psi_k));
        U_dow(i,:) = abs(ifft(CaF_down.Stat(i).Sol.Psi_k));

    end
    figure;plot(delta_vector,real(Power_dow),delta_vector_upp,abs(Power_upp))
    
%%
    figure;mesh(CaF(1).Stat(1).Space.phi,delta_vector,U_dow)
    hold on;mesh(CaF(1).Stat(1).Space.phi,delta_vector_upp,U_upp)


