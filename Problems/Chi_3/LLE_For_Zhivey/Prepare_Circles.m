
    clc;clear all;format long;
    Fundamental_Constants;
        
%% Liniar Dispersion Definitions

%    L_L.In.omega_p         = 192E12;            %;1E9;%1.2E9;      % detuning in 2*pi*Hz
%    L_L.In.n               = 1.44;      
%   L_L.Dispersion.N       = 0.5;               % Nonliniar Int Coeff
%   L_L.Dispersion.S       = 1E-12;            % Mode Area

    L_L.In.D               = 2*pi*[15E9,1E3,0,0];
    L_L.In.omega_p         = 2*pi*176E12;
    L_L.In.kappa           = 2*pi*2E3;% 2kHz W 10^11  2*pi*60MHz
    L_L.In.norm_coeff      = L_L.In.kappa;
    L_L.In.Finess          = L_L.In.D(1)/L_L.In.kappa;
    L_L.In.eta             = 0.5;
    L_L.In.gamma           = 2*pi*10E3;
    F_1                    =  L_L.In.D(2)/L_L.In.kappa;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    L_L.In.delta           = 2E6/2*2*pi;   %5e6 at 0.001 
    L_L.In.P               = 0.01;
    
%% Angular space definitions

    L_L.Space.N        = 2^10;
    L_L.Space.lenght   = pi;
    L_L.Space.dphi     = L_L.Space.lenght/L_L.Space.N;
    L_L.Space.phi      = L_L.Space.dphi*( - L_L.Space.N/2:1:L_L.Space.N/2-1);
    L_L.Space.dk       = 2*pi/L_L.Space.lenght;   
    L_L.Space.k        = L_L.Space.dk*[0:L_L.Space.N/2 - 1 -L_L.Space.N/2:-1];
    
%%    
    Normalization          = @Normalization_Normalized_LLE;

    L_L                    = Normalization(L_L,Const);
    L_L_CW                 = CW(L_L);
  %  L_L_CW                 = CW_Stability_Kerr(L_L_CW);
    
%% Define Run 

    Delta_Stationary                        = struct;
    Delta_Stationary.i_max                  = 2000;
    Delta_Stationary.Equation_string        = 'Kerr_Full_Dispersion';
    
    Delta_Stationary.Equation               = @LLE_Full_Dispersion_Equation;%'Kerr_Full_Dispersion'%;'Kerr'
    Delta_Stationary.Liniar_Decomposition   = @LLE_Full_Dispersion_Liniar_Decomposition;
    Delta_Stationary.Preconditioner         = @LLE_Full_Dispersion_Predonditioner;
    Delta_Stationary.Initial_Guess          = @Soliton_At_Point_Full_Disersion_Kerr;
    
    Delta_Stationary.Newton                 = 'Bc_Grad';%'fsolve'
    Delta_Stationary.step_tol               = 0.001;
    Delta_Stationary.Stability              = 'Yes';
    Delta_Stationary.variable               = 'delta';  
    Delta_Stationary.first_step             = 1; %min =1E-4/3 
    Delta_Stationary.Newton_iter            = 50;      
    Delta_Stationary.Newton_tol             = 1E-7;  
    Delta_Stationary.Sol_Flag               = '-';
    
    options                                 = optimoptions(@fsolve,'Display',...
                                                'final','UseParallel',true,'SpecifyObjectiveGradient',true,...
                                                'Algorithm','trust-region-dogleg','FunctionTolerance',Delta_Stationary.Newton_tol,...
                                                'MaxIterations',Delta_Stationary.Newton_iter,'StepTolerance',Delta_Stationary.Newton_tol,'OptimalityTolerance',1E-25);%,
  [~,L_L_CW] = Soliton_At_Point_Full_Disersion_Kerr(L_L_CW,Delta_Stationary,options);
                                            
%%
NN = 32;
Power = linspace(0.001,0.01,NN);
for i =1:NN
    
        L_L_Start(i)                     = L_L;
        L_L_Start(i).In.P               = Power(i);
        L_L_Start(i)                   = Normalization(L_L_Start(i),Const);

end
%%

    sol_flag = ['-','+'];
    Delta_Stationary (2) = Delta_Stationary(1);
    
parfor i =1:NN

        Sol_Branch(i).L_L = Run_Branch_Back(L_L_Start(i),Delta_Stationary(1),options);

end

%%
    delta = zeros(2,max([size(tt(2).L_L,2),size(tt(1).L_L,2)]));
    U_Sol = zeros(2,max([size(tt(2).L_L,2),size(tt(1).L_L,2)]));
    U_CW  = zeros(3,max([size(tt(2).L_L,2),size(tt(1).L_L,2)]));
     V   =  zeros(2,max([size(tt(2).L_L,2),size(tt(1).L_L,2)]));
     
%%

for ii =1:NN
    for i =1:size(Sol_Branch(ii).L_L,2)

        delta(ii,i)       = Sol_Branch(ii).L_L(i).Eq.delta;
        [U_Sol(ii,i),ind] = max(abs(Sol_Branch(ii).L_L(i).Solution.Psi).^2);
        U_Sol(ii,i)       = 2*real(Sol_Branch(ii).L_L(i).Solution.Psi(ind));
        Max_real(ii,i)    = max(real(Sol_Branch(ii).L_L(i).Solution.Linear_Stability.E_values));
%        [~,ind]          =   min(abs(Sol_Branch(ii).L_L(i).Solution.Linear_Stability.E_values));
       % zero_real(ii,i)   = Sol_Branch(ii).L_L(i).Solution.Linear_Stability.E_values(ind);
%     %   U_CW (:,i)  = Sol_Branch(19).L_L(i).Solution.CW.Psi;
   %     V    (ii,i) = tt(ii).L_L(i).Solution.V;
        
    end
end
 U_Sol(U_Sol==0) = NaN;
 Max_real(isnan(U_Sol)) = NaN;
 zero_real(isnan(U_Sol)) = NaN;

%%
figure;
pcolor(delta*L_L.In.norm_coeff/2/pi,Power,real(U_Sol));shading interp





%%

figure;
pcolor(delta,Power,U_Sol);shading none


%%
%U_Sol(U_Sol == 0) = NaN;
figure;
plot(delta(1,:),U_Sol(1,:))
hold on;
plot(delta(2,:),U_Sol(2,:));
plot(delta(1,:),abs(U_CW(:,:)).^2);

%%
figure;
plot(L_L.Dispersion.D(1)/2/pi*delta(1,:), V (1,:))
hold on;
plot(L_L.Dispersion.D(1)/2/pi*delta(2,:), V (2,:))
% %%
%%
    
 figure;plot(2*2*pi*23E-6*linspace(-0.5,0.5,L_L.Space.N)/1E12,abs(tt(ii).L_L(i2).Solution.Psi).^2)
 figure;plot(fftshift(10*log10(abs(fft(tt(ii).L_L(i2).Solution.Psi)).^2)))


%%
ii  = 1;
i = 71;

figure;plot(real(Sol_Branch(ii).L_L(i).Solution.Linear_Stability.E_values),imag(Sol_Branch(ii).L_L(i).Solution.Linear_Stability.E_values),'Marker','.','LineStyle','none')
figure;plot(real(Sol_Branch(ii).L_L(i).Solution.Psi ))