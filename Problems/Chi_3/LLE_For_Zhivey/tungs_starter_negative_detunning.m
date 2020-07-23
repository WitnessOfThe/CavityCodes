
    clc;clear all;format long;
    Fundamental_Constants;

    Delta(1).Loops         = 25;                                %   Number of Looops that you disire
    Delta(1).dt            = 1E-5/2;                                   %   Time ste[ in loops
    Delta(1).per_loop      = 1000;                                 %   How ma1000ny times per loop we will save the data
    Delta(1).Runge_Type    = 'Runge 4';                    %  'ARK-6-3-4';% Type of Runge Kutta Sceme
    Delta(1).Initial_Guess = 'CW';                                  %  'Kerr_Soliton';'Runge SSPRK3'
    Delta(1).Physics       = 'Kuarong Kerr';                    %   Euqation that we Reduce
    Delta(1).Save_iter     = 1;                                     %   How many per loo
   

%% Nonlinear Definitions

Power(1)   = 0.05;
Power(2)   = 0.1;
Power(3:4) = 0.15;
Power(5:7) = 0.2;
Power(8:10) = 0.25;
Power(11:14) = 0.3;
Power(15:19) = 0.35;
Power(20:24) = 0.4;
Power(25:31) = 0.45;
Power(32:39) = 0.5;
Power(40:46) = 0.55;
Power(47:53) = 0.6;

detunning                            = zeros(1,50);
detunning(1)                         = -0.61E6*2*pi;
detunning([2:3,5])                   = -0.605E6*2*pi;
detunning([4,6,8,11,15])             = -0.6E6*2*pi;
detunning([7,9,12,16,20,25,32])      = -0.595E6*2*pi;
detunning([10,13,17,21,26,33,40,47]) = -0.59E6*2*pi;
detunning([14,18,22,27,34,41,48])    = -0.585E6*2*pi;
detunning([19,23,28,35,42,49])       = -0.58E6*2*pi;
detunning([24,29,36,43,50])          = -0.575E6*2*pi;
detunning([30,37,44,51])             = -0.57E6*2*pi;
detunning([31,38,45,52])            = -0.565E6*2*pi;
detunning([39,46,53])               = -0.56E6*2*pi;



%% Input parameters

         %;1E9;%1.2E9;      % detuning in 2*pi*Hz
%    L_L.In.Q               = 5*10^5;   % loaded Q-factor
     % phisical power in Watts
    L_L.In.eta             = 0.5;      % coupling regime
    L_L.In.omega_p         = 176E12*2*pi;
    
%% Angular space definitions

    L_L.Space.N        = 2^12;
    L_L.Space.lenght   = 2*pi;
    L_L.Space.dphi     = L_L.Space.lenght/L_L.Space.N;
    L_L.Space.phi      = L_L.Space.dphi*( - L_L.Space.N/2:1:L_L.Space.N/2-1);
    L_L.Space.dk       = 2*pi/L_L.Space.lenght;   
    L_L.Space.k        = L_L.Space.dk*[0:L_L.Space.N/2-1, -L_L.Space.N/2:-1];
     Delta(1).N             = L_L.Space.N;
     
%% Liniar Dispersion Definitions

    L_L.In.D               = 2*pi*[15E9,1000,0,0];
    L_L.In.gamma           = 2*pi*10*1000;
    L_L.In.kappa           = 2*pi*2*10^3;    
    L_L.In.norm_coeff      = L_L.In.kappa;

    Normalization      = @Normalization_Normalized_LLE;
%%
    for i = 1:53    
        L_L.In.delta           = detunning(i); 
        L_L.In.P               = Power(i);     
        L_L                    = Normalization(L_L,Const); % dispersion of the 
        L_L                    = CW(L_L);
        L_L                    = CW_Stability_Kerr(L_L);
        L_L_Start(i)           = L_L;
    end
%%  Call Solver
%parpool(32);
%%
    tic
        L_L_Split(i) = Temporal_evolution_solver(L_L_Start(i),Delta(1),3) ;
        i
    toc    

%%
ii = 1;
U_sol_max = zeros(1,size(L_L_Split(ii).Solution.Temporal.E_s,1));

for i = 1:size(L_L_Split(1).Solution.Temporal.E_s,1)    
    
    U_sol_max(i)      = max((abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(i,:)))));
    
end
%    F_Field = ifft(L_L_Split(1).Solution.Temporal.E_s,[],2);

%%
figure;pcolor(fftshift(L_L.Space.k),L_L_Split.Solution.Temporal.t/L_L.In.norm_coeff*L_L.Dispersion.D(1)/2/pi,10*log10(abs(fftshift(L_L_Split(1).Solution.Temporal.E_s,2)).^2));shading interp
%%
figure;
mesh(L_L.Space.phi,L_L_Split.Solution.Temporal.t/L_L.In.norm_coeff*L_L.Dispersion.D(1)/2/pi,abs(F_Field).^2);shading interp;
xlabel('Angle')
ylabel('Time in 1/kappa')
%%
figure;plot(L_L_Split.Solution.Temporal.t/L_L.In.norm_coeff*L_L.Dispersion.D(1)/2/pi,U_sol_max);
xlabel('Time in Loops') 
ylabel('Integral ower abs field^2')
%%

%%
 figure;
 plot(L_L.Space.k,10*log10(abs(L_L_Split(1).Solution.Temporal.E_s(end,:)).^2)) % spectrum  at the end of simulation
 xlabel('Relative Mode Number');
 ylabel('Power db')
 figure;
    hold on;
    plot(L_L.Space.phi,abs( ifft(L_L_Split(1).Solution.Temporal.E_s(end,:))).^2)
 xlabel('Angle');
 ylabel('Power W')

%% Check Nonliniar Oscillation Frequency

%figure;
%plot(abs(L_L_Save(i).   ))
%%
figure;
pcolor(fftshift( 10*log10(abs(fft(L_L_Split.Solution.Temporal.E_s,[],1)).^2 ), 1) );shading interp
%%
for i =1:50
    L_L_Save(i) = L_L_Start(i);
    L_L_Save(i).Solution.Temporal.t =  L_L_Split(i).Solution.Temporal.t(1:10:end);
    L_L_Save(i).Solution.Temporal.E_s =  L_L_Split(i).Solution.Temporal.E_s(1:10:end,:);
end
%%
ii = 1;
Field = abs(ifft(L_L_Split(ii).Solution.Temporal.E_s,[],2));
%%
figure;
pcolor(L_L_Split.Space.phi,L_L_Split.Solution.Temporal.t,Field(:,:));shading interp
%%
    Delta(2)               = Delta(1);
    Delta(2).Loops         = 0.02;                                %   Number of Looops that you disire
    Delta(2).dt            = 1E-6;                                   %   Time ste[ in loops
    Delta(2).per_loop      = 10^4/2;                                 %   How ma1000ny times per loop we will save the data
    Delta(2).Runge_Type    = 'Runge 4';                    %  'ARK-6-3-4';% Type of Runge Kutta Sceme
    Delta(2).Initial_Guess = 'Resume_Solution';                                  %  'Kerr_Soliton';'Runge SSPRK3'
    Delta(2).Physics       = 'Kuarong Kerr';                    %   Euqation that we Reduce
    Delta(2).Save_iter     = 1;                                     %   How many per loo
    tic
        L_L_Split(1) = Temporal_evolution_solver(L_L_Save(1),Delta(2),718) ;
    toc    
