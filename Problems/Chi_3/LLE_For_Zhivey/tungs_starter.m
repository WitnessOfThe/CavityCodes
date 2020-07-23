
    clc;clear all;format long;
    Fundamental_Constants;

    Delta(1).Loops         = 1000;                                %   Number of Looops that you disire
    Delta(1).dt            = 2E-4;                                   %   Time ste[ in loops
    Delta(1).per_loop      = 50;                                 %   How ma1000ny times per loop we will save the data
    Delta(1).Runge_Type    = 'Runge 4';                    %  'ARK-6-3-4';% Type of Runge Kutta Sceme
    Delta(1).Initial_Guess = 'CW_Phase';                                  %  'Kerr_Soliton';'Runge SSPRK3'
    Delta(1).Physics       = 'Kuarong Kerr';                    %   Euqation that we Reduce
    Delta(1).Save_iter     = 1;                                     %   How many per loo
   

%% Nonlinear Definitions

Power(1)      =       0.45;%  0.450; % 0.494;
detunning(1)  = -5.911728395061728e+05*2*pi;



%% Input parameters

         %;1E9;%1.2E9;      % detuning in 2*pi*Hz
%    L_L.In.Q               = 5*10^5;   % loaded Q-factor
     % phisical power in Watts
    L_L.In.eta             = 0.5;      % coupling regime
    L_L.In.omega_p         = 176E12*2*pi;
    
%% Angular space definitions

    L_L.Space.N        = 2^11;
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
    for i = 1:1  
        L_L.In.delta           = detunning(i); 
        L_L.In.P               = Power(i);     
        L_L                    = Normalization(L_L,Const); % dispersion of the 
        L_L                    = CW(L_L);
        L_L                    = CW_Stability_Kerr(L_L);
        L_L_Start(i)           = L_L;
    end
    L_L_Start(2)= L_L_Start(1)';%%  Call Solver
%parpool(32);
phase_shift(1).a = [1E-1,1E-3];
phase_shift(2).a = [1E-3,1E-1];
parfor i=1:2
    tic
        L_L_Split(i) = Temporal_evolution_solver(L_L_Start(i),Delta(1),3,phase_shift(i).a) ;
        i
    toc    
end      

%%
U_sol_max = zeros(1,size(L_L_Split(1).Solution.Temporal.E_s,1));

for i = 1:size(L_L_Split(1).Solution.Temporal.E_s,1)
    
    U_sol_max(i)      = max((abs(ifft(L_L_Split(1).Solution.Temporal.E_s(i,:)))));
    
end
    F_Field = ifft(L_L_Split(1).Solution.Temporal.E_s,[],2);

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
%ii = 33;
figure;
hold on;
%[1,2,3,5,11,15,20,25,32,33,40,48];
%[4,6,8,7,9,12,16,10,13,17,21,26,18,22,19,41];
%[47,27,34,23,28,35,42,49,24,29,36,43,50,30,37,44,51,31,38,45,52,39,46,53];
%[47,27,34,23,28,35,42,49,24,29,36,43,50,30,37,44,51,31,38,45,52,39,46,53]  ;
%    [1,2,3,5,11,15,20,25,32,33,40,48];
for ii = 2
    
    Field       = abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(:,:),[],2));
    tong(3).U_max(ii,:) = max(Field,[],2);
    tong(3).t_max(ii,:) = L_L_Split(ii).Solution.Temporal.t;
    plot(tong(3).t_max(ii,:),tong(3).U_max(ii,:))
    
end
%%
ii = 2;
figure;
subplot(2,2,3);plot(L_L_Split(ii).Space.phi,abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(end,:),[],2)));
xlim([-pi,pi]);
subplot(2,2,4);plot(fftshift(L_L_Split(ii).Space.k),fftshift(14*log10(abs(L_L_Split(ii).Solution.Temporal.E_s(end,:)/L_L_Split(ii).Space.N).^2*2*pi),2 ));
xlim([-250,250]*3);
%%
%i = 36;33
    ii = 1;
    fig   = figure('Position',[0,0,1100,600]);
ax(1) = axes('Parent',fig,'Position',[0.08,0.1,0.4,0.85]);
pcolor(L_L_Split(ii).Space.phi,L_L_Split(ii).Solution.Temporal.t(1:1:end)/L_L_Split(ii).In.norm_coeff*L_L_Split(ii).Dispersion.D(1)/2/pi,abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(1:1:end,:),[],2)),'Parent',ax(1));shading interp
%caxis([10,25]);%[0.56,1.8]%[1.2,1.9]
ax(1).Box = 'on';
%ax(1).YLim = [0,10^8*5/3];
ax(1).XLabel.Interpreter = 'latex';
ax(1).XLabel.String = '$\theta$';
ax(1).YLabel.Interpreter = 'latex';
ax(1).YLabel.String = '$roundtrips$';
ax(1).TickLabelInterpreter = 'latex';
ax(1).FontSize             = 15;
ax(1).FontWeight           = 'bold';

Spectrum_matrix = 10*log10(abs(L_L_Split(ii).Solution.Temporal.E_s(1:1:end,:)));
ax(2) = axes('Parent',fig,'Position',[0.08*2+0.4,0.1,0.4,0.85]);
%pcolor(fftshift(L_L_Split(ii).Space.k),L_L_Split(ii).Solution.Temporal.t/L_L_Split(ii).In.norm_coeff*L_L_Split(ii).Dispersion.D(1)/2/pi,fftshift(Spectrum_matrix,2 ),'Parent',ax(2));shading interp
caxis([-50,10]);

ax(2).Box = 'on';
ax(2).XLim = [-1000,1000];
%ax(2).YLim = [0,10^8*5/3];
ax(2).XLabel.Interpreter = 'latex';
ax(2).XLabel.String = '$\mu$';
ax(2).YLabel.Interpreter = 'latex';
ax(2).TickLabelInterpreter = 'latex';
ax(2).FontSize             = 15;
ax(2).FontWeight           = 'bold';

%%
Spectrum_matrix =10*log10(abs(L_L_Split(ii).Solution.Temporal.E_s/L_L_Split(ii).Space.N).^2*2*pi*1000);
subplot(1,2,2);
set(gca,'Interpreter','latex');
caxis([-50,max(max(Spectrum_matrix))/10]);
xlim([-100,100])
box on;
xlabel('\mu','Interpreter','latex')
ylabel('roundtrips','Interpreter','latex')
%%
ii =1;
figure;
mesh(abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(12000-50:100:24000,:),[],2)));%shading interp
