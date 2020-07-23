
    clc;clear all;format long;
    Fundamental_Constants;
    
    Delta(1).Loops         = 500;                          %   Number of Looops that you disire
    Delta(1).dt            = 1E-4;                         %   Time ste[ in loops
    Delta(1).per_loop      = 50;                           %   How ma1000ny times per loop we will save the data
    Delta(1).Runge_Type    = 'Runge 4';                    %  'ARK-6-3-4';% Type of Runge Kutta Sceme
    Delta(1).Initial_Guess = 'CW';                         %  'Kerr_Soliton';'Runge SSPRK3'
    Delta(1).Physics       = 'Kuarong Kerr';               %   Euqation that we Reduce
    Delta(1).Save_iter     = 1;                            %   How many per loo
   

%% Nonlinear Definitions

%linspace(-0.595E6,-0.585E6,10);
   % [,Power]  = meshgrid([-5.9997E5:246:-5.6E5]*2*pi,linspace(0.4,0.55,4));
    %detunning   = ;
    detunning          = [-5.9997E5:150:-5.7E5,-5.981E5:150:-5.7E5,-5.966E5:150:-5.7E5,-5.95E5:150:-5.7E5]*2*pi;
    Power              = [ones(1,200)*0.4,ones(1,188)*0.45,ones(1,178)*0.5,ones(1,167)*0.55];
    NN = size(Power,2);    
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
i=0;
    for i1 = 1:NN
%        for i2 = 1:sqrt(NN)
            i = i+1;
            L_L.In.delta           = detunning(i1); 
            L_L.In.P               = Power(i1);     
            L_L                    = Normalization(L_L,Const); % dispersion of the 
            L_L                    = CW(L_L);
            L_L                    = CW_Stability_Kerr(L_L);
            L_L_Start(i)           = L_L;
 %       end
    end
    
%%  Call Solver
%parpool(32);
    parfor i = 1:size(L_L_Start,2)
        
        save_path = strcat('/home/dp710/Data_Storage/LLE/Delta_Power_Scan/',num2str(i),'.mat');
        check(i) = (isfile(save_path) == 0);
        
        if check(i)

           tic
           L_L_Split = Temporal_evolution_solver(L_L_Start(i),Delta(1),3);
           i
           toc

           Save_Parfor(L_L_Split,Delta,save_path)
           L_L_Split = [];
            
        end    
        
    end


% parfor i=1:NN
%     tic
%         L_L_Split(i) = Temporal_evolution_solver(L_L_Start(i),Delta(1),3) ;
%         i
%     toc    
% end      

%%
U_sol_max = zeros(1,size(L_L_Split(1).Solution.Temporal.E_s,1));

for i = 1:size(L_L_Split(1).Solution.Temporal.E_s,1)
    
    U_sol_max(i)      = max((abs(ifft(L_L_Split(1).Solution.Temporal.E_s(i,:)))));
    
end
    F_Field = ifft(L_L_Split(1).Solution.Temporal.E_s,[],2);

%%
ii =1;
figure;pcolor(fftshift(L_L_Split(ii).Space.k),L_L_Split(ii).Solution.Temporal.t/L_L_Split(ii).In.norm_coeff*L_L_Split(ii).Dispersion.D(1)/2/pi,10*log10(abs(fftshift(L_L_Split(1).Solution.Temporal.E_s,2)).^2));shading interp
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
figure;
hold on;
%[1,2,3,5,11,15,20,25,32,33,40,48];
%[4,6,8,7,9,12,16,10,13,17,21,26,18,22,19,41];
%[47,27,34,23,28,35,42,49,24,29,36,43,50,30,37,44,51,31,38,45,52,39,46,53];
%[47,27,34,23,28,35,42,49,24,29,36,43,50,30,37,44,51,31,38,45,52,39,46,53]  ;
%    [1,2,3,5,11,15,20,25,32,33,40,48];
ii = 1;

%for ii = 6:6
%    [4:5,14:15,24:26,34:36,44:47,54:58,64:68,74:79,84:90,94:100]

    Field       = abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(:,:),[],2));
%    tong(3).U_max(ii,:) = max(Field,[],2);
 %   tong(3).t_max(ii,:) = L_L_Split(ii).Solution.Temporal.t;
  %  plot(tong(3).t_max(ii,:),tong(3).U_max(ii,:))
 %   plot(L_L_Resumed(ii).Solution.Temporal.t/L_L_Resumed(ii).In.norm_coeff,2*real(L_L_Resumed(ii).Solution.Temporal.E_s(:,36)))   
    plot(L_L_Split(ii).Solution.Temporal.t/L_L_Split(ii).In.norm_coeff,2*real(L_L_Split(ii).Solution.Temporal.E_s(:,36)))   
    plot(L_L_Split(ii).Solution.Temporal.t/L_L_Split(ii).In.norm_coeff,2*real(L_L_Split(ii).Solution.Temporal.E_s(:,1)))   
    plot(L_L_Split(ii).Solution.Temporal.t/L_L_Split(ii).In.norm_coeff,2*real(L_L_Split(ii).Solution.Temporal.E_s(:,end-35+1)))
    plot(L_L_Split(ii).Solution.Temporal.t/L_L_Split(ii).In.norm_coeff,2*real(L_L_Split(ii).Solution.Temporal.E_s(:,14)))
    plot(L_L_Split(ii).Solution.Temporal.t/L_L_Split(ii).In.norm_coeff,2*real(L_L_Split(ii).Solution.Temporal.E_s(:,30)))
    plot(L_L_Split(ii).Solution.Temporal.t/L_L_Split(ii).In.norm_coeff,2*real(L_L_Split(ii).Solution.Temporal.E_s(:,42)))
    plot(L_L_Split(ii).Solution.Temporal.t/L_L_Split(ii).In.norm_coeff,2*real(L_L_Split(ii).Solution.Temporal.E_s(:,49)))
%end
%%
mode_range = 45001:50000;

f = [0:(size(L_L_Split(ii).Solution.Temporal.E_s(mode_range,36),1)/2-1),-size(L_L_Split(ii).Solution.Temporal.E_s(mode_range,36),1)/2:-1]*1/(L_L_Split(ii).Solution.Temporal.t(mode_range(1))-L_L_Split(ii).Solution.Temporal.t(mode_range(end)));

for i =1:size(L_L_Split(ii).Solution.Temporal.E_s(mode_range,:),2)
    
    [ff,index(i)] = max(abs(L_L_Split(ii).Solution.Temporal.E_s(mode_range,i)));
    f_save(i) = f(index(i)); 
end
%%
figure;plot(L_L.Space.k(L_L.Eq.Shifted.mode_range),f_save)
%%
figure;%plot(fftshift(f)*L_L_Split(ii).In.norm_coeff,fftshift(10*log10(abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,36))).^2)));
%hold on;plot(fftshift(f)*L_L_Split(ii).In.norm_coeff,fftshift(10*log10(abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,end-34))).^2)));
hold on;plot(fftshift(f)*L_L_Split(ii).In.norm_coeff,fftshift(10*log10(abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,2))).^2)));
hold on;plot(fftshift(f)*L_L_Split(ii).In.norm_coeff,fftshift(10*log10(abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,3))).^2)));
hold on;plot(fftshift(f)*L_L_Split(ii).In.norm_coeff,fftshift(10*log10(abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,4))).^2)));
%hold on;plot(fftshift(f)*L_L_Split(ii).In.norm_coeff,fftshift(10*log10(abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,30))).^2)));
%hold on;plot(fftshift(f)*L_L_Split(ii).In.norm_coeff,fftshift(10*log10(abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,42))).^2)));
%hold on;plot(fftshift(f)*L_L_Split(ii).In.norm_coeff,fftshift(10*log10(abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,49))).^2)));
%%
%ii = 5;\\\\\\\\\\\\
figure;
subplot(2,2,3);plot(L_L_Split(ii).Space.phi,real(ifft(L_L_Split(ii).Solution.Temporal.E_s(end,:),[],2)));
xlim([-pi,pi]);%(L_L_Split(ii).Eq.Shifted.mode_range)
figure;plot(10*log10(abs(L_L_Split(ii).Solution.Temporal.E_s(end,:)).^2*2*pi));
xlim([-250,250]*3);
%%
figure;
subplot(2,2,3);plot(L_L_Split(ii).Space.phi,real(ifft(L_L_Split(ii).Solution.Temporal.E_s(end,:),[],2)));

%%
%i = 36;33
    mode_range = 1:10:5000;
    fig   = figure('Position',[0,0,1100,600]);
    ax(1) = axes('Parent',fig,'Position',[0.08,0.1,0.4,0.85]);
    pcolor(L_L_Split(ii).Space.phi,L_L_Split(ii).Solution.Temporal.t(mode_range)/L_L_Split(ii).In.norm_coeff*L_L_Split(ii).Dispersion.D(1)/2/pi,abs(ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,:),[],2)),'Parent',ax(1));shading flat
%caxis([2,2.2]);%[0.56,1.8]%[1.2,1.9]
ax(1).Box = 'on';
%ax(1).YLim = [0,10^8*5/3];
ax(1).XLabel.Interpreter = 'latex';
ax(1).XLabel.String = '$\theta$';
ax(1).YLabel.Interpreter = 'latex';
ax(1).YLabel.String = '$roundtrips$';
ax(1).TickLabelInterpreter = 'latex';
ax(1).FontSize             = 15;
ax(1).FontWeight           = 'bold';

Spectrum_matrix = 10*log10(abs(L_L_Split(ii).Solution.Temporal.E_s(mode_range,:)));
ax(2) = axes('Parent',fig,'Position',[0.08*2+0.4,0.1,0.4,0.85]);
pcolor(fftshift(L_L_Split(ii).Space.k),L_L_Split(ii).Solution.Temporal.t(mode_range)/L_L_Split(ii).In.norm_coeff*L_L_Split(ii).Dispersion.D(1)/2/pi,fftshift(Spectrum_matrix,2 ),'Parent',ax(2));shading interp
caxis([-50,10]);

%ax(2).Box = 'on';
%ax(2).XLim = [-512,512];
%ax(2).YLim = [0,10^8*5/3];
ax(2).XLabel.Interpreter = 'latex';
ax(2).XLabel.String = '$\mu$';
ax(2).YLabel.Interpreter = 'latex';
ax(2).TickLabelInterpreter = 'latex';
ax(2).FontSize             = 15;
ax(2).FontWeight           = 'bold';
%%
     U = zeros(size(L_L_Split(1).Solution.Temporal.E_s));
 for i =1:size(L_L_Split(1).Solution.Temporal.E_s,1)
     
     U(i,L_L_Split(1).Eq.Shifted.mode_range) = L_L_Split(1).Solution.Temporal.E_s(i,:);
     
 end
 %%
 ii= 2;
field = abs(ifft(U,[],2));
%%
figure;
subplot(1,2,1);plot(real(field(end,:)));
subplot(1,2,2);plot(L_L.Space.k,10*log10(abs(U(end,:))));
%%
 figure;pcolor(L_L_Split(ii).Space.phi,L_L_Split(ii).Solution.Temporal.t(end-1000:end)/L_L_Split(ii).In.norm_coeff,field(end-1000:end,:));shading flat
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
%%
for i = 1:32
    
    U(i,:) = L_L_Split(i).Solution.Temporal.E_s(end,:);
    
end
%%
i = 0;
for i1 = 1:10
    for    i2 = 1:10
        i = i+1;
        U_max(i1,i2) = abs(max(abs(L_L_Split(i).Solution.Temporal.E_s(30:40,36)))-min(abs(L_L_Split(i).Solution.Temporal.E_s(30:40,36))));
    end
end
%%
    Delta(2).Loops         = 50;                          %   Number of Looops that you disire
    Delta(2).dt            = 1E-4;                         %   Time ste[ in loops
    Delta(2).per_loop      = 100;                           %   How ma1000ny times per loop we will save the data
    Delta(2).Runge_Type    = 'Runge 4';                    %  'ARK-6-3-4';% Type of Runge Kutta Sceme
    Delta(2).Initial_Guess = 'Resume_Solution';                         %  'Kerr_Soliton';'Runge SSPRK3'
    Delta(2).Physics       = 'Kuarong Kerr';               %   Euqation that we Reduce
    Delta(2).Save_iter     = 1;                            %   How many per loo
%%
           L_L_Resumed = Temporal_evolution_solver(L_L_new(1),Delta(2),4000);

