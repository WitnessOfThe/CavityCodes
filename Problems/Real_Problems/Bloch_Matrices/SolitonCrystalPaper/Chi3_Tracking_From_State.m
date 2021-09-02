    clc;
    clear all;
    warning('off');
    
%% Define Input Parameters in Physical Units

    R       =  Set_Up_Methods_For_Bloch_Matrices;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    R.Stat.In              = Params_SiN_For_Crytal_Paper;%Params_SiN_For_Crytal_Paper;    
    R.Stat.Par.CW_num      = 3;
    R.Stat.In.kappa        = R.Stat.In.D(2)/0.05;   %%/0.017
    
    W_WStar           = 2;   
    
    R.Stat.In.P       = W_WStar*pi/(R.Stat.In.eta*R.Stat.In.D(1)/R.Stat.In.kappa)*R.Stat.In.kappa/R.Stat.In.gamma;    
    R.CW.In           = R.Stat.In;
    
    R.Stat.In.N_mode  = 2^10;
    R.CW.In.N_mode    = 2^7;
    
%% Stationary Coefficeints

    R.Stat.Par.i_max                = 2000;
    R.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    R.Stat.Met.Newton               = @Newton_Manual_bicgstab;

    R.Stat(1).Par.Newton_tol       = 1E-13;  
    R.Stat(1).Par.Turning          =    0;
    R.Stat(1).Par.variable         = 'delta';  %%'Pump Power';
    R.Stat(1).Par.bot_boundary     = -1E8; % bottom boundary for delta to search in normalized units
    R.Stat(1).Par.top_boundary     =  1E8; % top boundary for delta to search in normalized units
    
    R.Stat(1).Par.Stability        = 0;
    
    R.Stat(1).Par.Newton_iter      = 100;
    R.Stat(1).Par.first_step       = 0.9E-2;
    R.Stat(1).Par.max_step         = 1E-2;
    R.Stat(1).Par.step_dec         = 0.2; 
    R.Stat(1).Par.step_tol         = 1E-17;
    R.Stat(1).Par.step_inc         = 1.1;  
    R.Stat.Par.i_max               = 16000;
    
%%
    R.CW.In.delta    = R.CW.In.kappa*2;
 
%%  StraitForward  
% 
%     R.CW.In.mu_bl  = 4;   
%     R = Chi3_Stat_StartFromCW(R);
%     R.Stat.Stab                 = Stability_Switcher(R.Stat);
%     
%     R.Stat  = R.Stat.Met.Norm(R.Stat);
%     x_0     = R.Stat.Eq.(R.Stat.Par.variable);
%     
%     Stat_1  =   BranchTurning3Step([real(R.Stat.Sol.Psi_k),imag(R.Stat.Sol.Psi_k)]*R.Stat.Space.N,x_0,R.Stat,1);
%     Stat_2  =   BranchTurning3Step([real(R.Stat.Sol.Psi_k),imag(R.Stat.Sol.Psi_k)]*R.Stat.Space.N,x_0,R.Stat,-1);
%%
%     for imu = 1
%         R.CW.In.mu_bl  = imu;   
%         R = Chi3_Stat_StartFromCW(R);
%         R.Stat.Stab                 = Stability_Switcher(R.Stat);
% 
%         R.Stat  = R.Stat.Met.Norm(R.Stat);
%         x_0     = R.Stat.Eq.(R.Stat.Par.variable);
% % % 
%        Stat_1  =   BranchTurning3Step([real(R.Stat.Sol.Psi_k),imag(R.Stat.Sol.Psi_k)]*R.Stat.Space.N,x_0,R.Stat,1);
%        Stat_2  =   BranchTurning3Step([real(R.Stat.Sol.Psi_k),imag(R.Stat.Sol.Psi_k)]*R.Stat.Space.N,x_0,R.Stat,-1);
%        
%         Stat = [fliplr(Stat_1),Stat_2];%fliplr(Stat_1),fliplr(Stat_1),
% %        
%        parfor i =1:size(Stat,2)
%             Stat(i).Stab                 = Stability_Switcher(Stat(i));
%        end
%        RR(imu).Stat = Stat;
%     end
% %%
%        ii      = 31;
%        x_0     = Stat_x(ii).Eq.(R.Stat.Par.variable);
%        Stat_x  = BranchTurning3Step([real(Stat_x(ii).Sol.Psi_k),imag(Stat_x(ii).Sol.Psi_k)]*Stat_x(ii).Space.N,x_0,Stat_x(ii),-1);

%%
    Nphi = 400;
    phi  = linspace(0,pi-2*pi/Nphi,Nphi);
    R.CW.In.mu_bl  = 1;   
    R = Chi3_Stat_StartFromCW(R);
    Psi_k0 = R.Stat(1).Sol.Psi_k;
    
    for iphi = 1:Nphi   
        
        Psi_k0 = R.Stat(1).Sol.Psi_k;
        Psi_k0(1) =Psi_k0(1)- R.CW.Sol.Psi(3);
        Psi_k = Psi_k0;
    
    for i =1:1
        
        Psi_k = Psi_k + Psi_k0.*exp(1i*R.Stat.Space.k*i*phi(iphi));

    end
    
        Psi_k(1) =Psi_k(1)+ R.CW.Sol.Psi(3);
    
%    Psi = ifft(Psi_k);
 %   Psi = Psi + Psi.*exp(1i*R.Stat.Space.phi*pi/16);
  %  Psi.*exp(1i*R.Stat.Space.phi*pi/8)
%    R.Stat.Stab                 = Stability_Switcher(R.Stat);
    
        R.Stat  = R.Stat.Met.Norm(R.Stat);
        x_0     = R.Stat.Eq.(R.Stat.Par.variable);
        [Slv,eps_f(iphi),Exitflag] = Newton_Switcher([real(Psi_k),imag(Psi_k)]*R.Stat.Space.N,R.Stat);            
        StatShift(iphi)           = R.Stat.Met.Prop_Gen(Slv,R.Stat);  
        StatShift(iphi).Sol.eps_f = eps_f(iphi);
    end
    R.Stat = StatShift(36);
    Stat_1  =   BranchTurning3Step([real(R.Stat.Sol.Psi_k),imag(R.Stat.Sol.Psi_k)]*R.Stat.Space.N,x_0,R.Stat,1);
  %  Stat_2  =   BranchTurning3Step([real(R.Stat.Sol.Psi_k),imag(R.Stat.Sol.Psi_k)]*R.Stat.Space.N,x_0,R.Stat,-1);
%     parfor i =1:1:size(Stat_2,2)
%          Stat_2(i).Stab                 = Stability_Switcher(Stat_2(i));
%          i             
%     end
%%
    parfor i =1:size(Stat_1,2)
         Stat_1(i).Stab                 = Stability_Switcher(Stat_1(i));
         i
    end  
%%

    f1 = figure('Position',[0,0,700,300],'Color',[1,1,1]);
    
    Panel1 = tiledlayout(1,3,'TileSpacing','none','Padding','none');
    
    axb(1) =  nexttile(Panel1,1,[1,1]);  
    axb(2) =  nexttile(Panel1,2,[1,1]);  
    axb(3) =  nexttile(Panel1,3,[1,1]);  
    
    hold(axb(1),'on');
    hold(axb(2),'on');
    hold(axb(3),'on');

    
   Plot_Static_Branch([Stat_1],axb);%,Stat_6 Stat_2,Stat_6,
  %  Plot_Static_Branch(Stat_2,axb);
  % Plot_Static_Branch_Stable([Stat_2],axb);
 %  Plot_Static_Branch_Stable(Stat_2,axb);
%   axb(3).YLim  = [-0.05,0.05];
   clear f1
   clear axb
   clear Panel1
%%   
   
 %  save(strcat('mu=',num2str(R.CW.In.mu_bl),'_Defect,2'),'Stat_2','Stat_1');   
%%
     Stat1 = Chi3_Start_FromBlochVector(R.Stat,3);
%%
     Psi = TransferToResontor(Stat_2(1).Sol.Psi_k,Stat_2(1).In.mu_bl);
    
%%
    fstable = figure('Position',[0,0,1400,900]/2,'Color',[1,1,1]);
    P1      = tiledlayout(1,3,'TileSpacing','none','Padding','none');
    axb(1)  =  nexttile(P1,1,[1,1]);  
    axb(2)  =  nexttile(P1,2,[1,1]);  
    axb(3)  =  nexttile(P1,3,[1,1]);  
    Plot_Stability(Stat(1),axb)
    axb(1).YLim = [-2,2];
    axb(2).YLim = [0,0.001];
    axb(3).YLim = [-2,2];
    clear fstable 
    clear axb
    clear P1 
    
%%

    fstable = figure('Position',[0,0,1300,400],'Color',[1,1,1]);
    P1      = tiledlayout(1,4,'TileSpacing','none','Padding','none','Parent',fstable);
    axb(1)  =  nexttile(P1,1,[1,1]);  
    axb(2)  =  nexttile(P1,2,[1,1]);  
    axb(3)  =  nexttile(P1,3,[1,1]);  
    axb(4)  =  nexttile(P1,4,[1,1]);  
%     axb(5)  =  nexttile(P1,5,[1,1]);  
%     axb(6)  =  nexttile(P1,6,[1,1]);  
%     axb(7)  =  nexttile(P1,7,[1,1]);  
%     axb(8)  =  nexttile(P1,8,[1,1]);  
    Plot_Vector(Stat(1), 0,axb(1:4),4)
%    Plot_Vector(Stat_1(1),-3,axb(5:8))
   clear fstable 
   clear P1
   clear axb 



   
%%
    f1 = figure('Position',[0,0,1400,900]/2,'Color',[1,1,1]);
    Panel = tiledlayout(3,2,'TileSpacing','none','Padding','none');
    
    ax(1) = nexttile(Panel,1,[1,1]);  
    ax(2) = nexttile(Panel,2,[1,1]);    
    ax(3) = nexttile(Panel,3,[1,1]);  
    ax(4) = nexttile(Panel,4,[1,1]);    
    ax(5) = nexttile(Panel,5,[1,1]);  
    ax(6) = nexttile(Panel,6,[1,1]);    
    
    for i =1:size(ax,2)
        
        hold(ax(i),'on');
        
    end
    
       Plot_Static_Field_Spectrums(Stat_1(1),ax(1:2));   
       Plot_Static_Field_Spectrums(Stat_1(end),ax(3:4));   
       Plot_Static_Field_Spectrums(Stat_2(end),ax(5:6));   
   clear f1
   clear ax
   clear Panel
%%
    f1 = figure('Position',[0,0,1400,900]/2,'Color',[1,1,1]);
    Panel = tiledlayout(1,2,'TileSpacing','none','Padding','none');
    
    ax(1) = nexttile(Panel,1,[1,1]);  
    ax(2) = nexttile(Panel,2,[1,1]);
    %
    hold(ax(1),'on')
    hold(ax(2),'on')

%    Plot_Static_StabilityK(Stat_1,0,ax)
    Plot_Static_StabilityK(Stat_2,0,ax)
    ax(2).YLim = [-2,2];
    
    clear f1
    clear ax
    clear Panel

%%
    f1 = figure('Position',[0,0,1400,900]/2,'Color',[1,1,1]);
    Panel = tiledlayout(2,2,'TileSpacing','none','Padding','none');
    
    ax(1) = nexttile(Panel,1,[1,1]);  
    ax(2) = nexttile(Panel,2,[1,1]);
    ax(3) = nexttile(Panel,3,[1,1]);  
    ax(4) = nexttile(Panel,4,[1,1]);
    %
    hold(ax(1),'on')
    hold(ax(2),'on')
    hold(ax(3),'on')
    hold(ax(4),'on')

    Plot_Static_StabilityK(Stat_1,3,ax(1:2))
    Plot_Static_StabilityK(Stat_2,3,ax(1:2))
    Plot_Static_StabilityK(Stat_1,-3,ax(3:4))
    Plot_Static_StabilityK(Stat_2,-3,ax(3:4))
    ax(2).YLim = [-3.5,3.5];
    ax(4).YLim = [-3.5,3.5];
    ax(1).YLim = [0,0.01];
    ax(3).YLim = [0,0.01];
    
    
    clear f1
    clear ax
    clear Panel
%    axb(1).YLim = [-2,2];
    
%%
function  Plot_Static_Branch(Stat_1,ax)

    Peak  = NaN(1,size(Stat_1,2));
    delta =  NaN(1,size(Stat_1,2));
    SmParam =  NaN(1,size(Stat_1,2));    
    for i = 1:size(Stat_1,2)
        Peak(i)    =  sum(abs(Stat_1(i).Sol.Psi_k(1:end)).^2);%Stat_1(i).Sol.Dir.d1;
        SmParam(i) = real(Stat_1(i).Sol.Psi_k(1));
        delta(i) = Stat_1(i).Eq.delta;
    end
    
    plot(delta,Peak,'Color',[0,0,0],'LineWidth',1,'Parent',ax(1));
    plot(delta,'Color',[0,0,0],'LineWidth',1,'Parent',ax(2));
    
    ax(1).XLabel.String = '$\delta/\kappa$';
    ax(1).YLabel.String = 'Peak Power';
    ax(2).XLabel.String = '$\delta/\kappa$';
    ax(2).YLabel.String = 'Re[$\psi_0$]';
    axes_Style(ax(1))
    axes_Style(ax(2))
end
function  Plot_Static_Branch_Stable(Stat_1,ax)

    Peak    =  NaN(1,size(Stat_1,2));
    delta   =  NaN(1,size(Stat_1,2));
    SmParam =  NaN(1,size(Stat_1,2));    
    
    ReLambda = NaN(size(Stat_1,2),100);
    for i = 1:size(Stat_1,2)
        
        Peak(i)       = sum(abs(ifft(Stat_1(i).Sol.Psi_k(2:end).*Stat_1(i).Space.N)).^2);
        SmParam(i)    = real(Stat_1(i).Sol.V);
        delta(i)      = Stat_1(i).Eq.delta;
        ReLambda(i,:) = maxk(real(reshape(Stat_1(i).Stab.Values.', 1, [])),100);
        Stable(i) = 1;
        if max(ReLambda(i,:)) > 1
            Stable(i) = 0;
        end
    end
    
    plot(delta,Peak*Stat_1(1).In.gamma/Stat_1(1).In.kappa,'Color',[0,0,0],'LineWidth',1,'Parent',ax(1),'LineStyle','--');
    plot(delta,SmParam,'Color',[0,0,0],'LineWidth',1,'Parent',ax(2),'LineStyle','--');
    plot(delta,ReLambda.'/Stat_1(i).In.kappa,'Color',[0,0,0],'LineStyle','none','Marker','.','MarkerSize',15,'Parent',ax(3));
    
    PeakS              =  Peak;
    PeakS(Stable==0)   = NaN;
    SmParamS           = SmParam;
    SmParamS(Stable==0)= NaN;
    deltaS             = delta;
    deltaS(Stable==0)  = NaN;
    
    plot(deltaS,PeakS*Stat_1(1).In.gamma/Stat_1(1).In.kappa,'Color',[0,0,0],'LineWidth',2,'Parent',ax(1));
    plot(deltaS,SmParamS,'Color',[0,0,0],'LineWidth',2,'Parent',ax(2));
    
    
    ax(1).XLabel.String = '$\delta/\kappa$';
    ax(1).YLabel.String = 'Peak Power';
    ax(2).XLabel.String = '$\delta/\kappa$';
    ax(2).YLabel.String = 'V';
    ax(3).XLabel.String = '$\delta/\kappa$';
    ax(3).YLabel.String = 'Re[$\lambda^{(k)}_{\hat \mu}$]';
    
    axes_Style(ax(1));
    axes_Style(ax(2));
    axes_Style(ax(3));
 %   axes_Style(ax(4));
end
function  Plot_Stability(S,ax)

    hold(ax(1),'on');
    hold(ax(2),'on');
    hold(ax(3),'on');
    
    for i = 1:size(S.Stab.Values,1)        
        
        plot(real(S.Stab.Values)/S.In.kappa,...
            imag(S.Stab.Values)/S.In.kappa...
                       ,'Color',[0,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(1),'MarkerSize',15);                  
                   
        ReUnique = uniquetol(real(S.Stab.Values(i,:)));
        ImUnique = uniquetol(imag(S.Stab.Values(i,:)));
        
        UnstEig  = S.Stab.Values(i,real(S.Stab.Values(i,:)) > 1);  
        
        plot(S.Stab.k(i)*ones(size(ReUnique)),ReUnique/S.In.kappa...
                       ,'Color',[0,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(2),'MarkerSize',15);
                   
        plot(S.Stab.k(i)*ones(size(ImUnique)),ImUnique/S.In.kappa...
                       ,'Color',[0,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(3),'MarkerSize',15);                  

        plot(S.Stab.k(i)*ones(size(UnstEig )),real(UnstEig)/S.In.kappa...
                       ,'Color',[1,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(2),'MarkerSize',15);
                   
        plot(S.Stab.k(i)*ones(size(UnstEig )),imag(UnstEig)/S.In.kappa...
                       ,'Color',[1,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(3),'MarkerSize',15);          
                                      
    end
    
    
    ax(1).XLabel.String = 'Re[$\lambda$]';
    ax(1).YLabel.String = 'Im[$\lambda$]';

    ax(2).XLabel.String = 'k';
    ax(2).YLabel.String = 'Re[$\lambda^{(k)}$]';
    
    ax(3).XLabel.String = 'k';
    ax(3).YLabel.String = 'Im[$\lambda^{(k)}$]';
    
    axes_Style(ax(1))
    axes_Style(ax(2))
    axes_Style(ax(3))
end
function  Plot_Vector(S,k,ax,ivec)
%     =3;
    for i = 1:size(ax,2)        
        hold(ax(i),'on');
    end
    
    Space = Define_Space_Cavity(2^12,2*pi);
    Ish  = find(S.Stab.k == k);
    SolitonBl = abs(ifft(S.Sol.Psi_k)).^2/max(abs(ifft(S.Sol.Psi_k)).^2);
    Soliton   = TransferToResontor(S.Sol.Psi_k,S.In.mu_bl);
    Soliton   = ifft(Soliton);
    Soliton   = abs(Soliton).^2/max( abs(Soliton).^2);
    
%    stem(fftshift(S.Space.k)/S.In.mu_bl,fftshift( 10*log10(abs(S.Sol.Psi_k).^2/max(abs(S.Sol.Psi_k).^2)) ),'Parent',ax(3),'Color',[0,0,0],'BaseValue',-100,'Marker','none','LineWidth',1);
    stem(fftshift(Space.k),fftshift( 10*log10(abs( TransferToResontor(S.Sol.Psi_k,S.In.mu_bl)).^2/max(abs( TransferToResontor(S.Sol.Psi_k,S.In.mu_bl)).^2) )),'Parent',ax(4),'Color',[0,0,0],'BaseValue',-100,'Marker','none','LineWidth',1);
    
    plot(S.Space.phi,circshift(SolitonBl ,S.Space.N/2),'Parent',ax(1),'Color',[0,0,0],'LineWidth',1);
    plot(Space.phi,circshift(Soliton ,S.Space.N/2),'Parent',ax(2),'Color',[0,0,0],'LineWidth',1);
    
    Vect = ifft(S.Stab.Vk(Ish).Vectors(1:S.Space.N,ivec));
    plot(S.Space.phi,circshift(abs(Vect).^2/max(abs(Vect).^2),S.Space.N/2),'Parent',ax(1),'Color',[1,0,0],'LineWidth',1);    
    stem(fftshift(S.Space.k)/S.In.mu_bl,fftshift(10*log10(abs(fft(Vect)).^2/max(abs(fft(Vect)).^2) )),'Parent',ax(3),'Color',[1,0,0],'BaseValue',-100,'Marker','none','LineWidth',1);
    
    
    Vect = TransferToResontor(S.Stab.Vk(Ish).Vectors(1:S.Space.N,ivec),S.In.mu_bl);
    Vect = ifft(Vect).*exp(1i*Space.phi*k);   
    plot(Space.phi,circshift(abs(Vect).^2/max(abs(Vect).^2),S.Space.N/2),'Parent',ax(2),'Color',[1,0,0],'LineWidth',1);
    stem(fftshift(Space.k),fftshift(10*log10(abs(fft(Vect)).^2/max(abs(fft(Vect)).^2) )),'Parent',ax(4),'Color',[1,0,0],'BaseValue',-100,'Marker','none');

    
        
    Vect = ifft(S.Stab.Vk(Ish).Vectors(S.Space.N+1:2*S.Space.N,ivec));    
    plot(S.Space.phi,circshift(abs(Vect).^2/max(abs(Vect).^2),S.Space.N/2),'Parent',ax(1),'Color',[0,0,1],'LineWidth',1);
    stem(fftshift(S.Space.k)/S.In.mu_bl,fftshift(10*log10(abs(fft(Vect)).^2/max(abs(fft(Vect)).^2) )),'Parent',ax(3),'Color',[0,0,1],'BaseValue',-100,'Marker','none','LineWidth',1);
    
    Vect = TransferToResontor(S.Stab.Vk(Ish).Vectors(S.Space.N+1:2*S.Space.N,ivec),S.In.mu_bl);
    
    Vect = ifft(Vect).*exp(1i*Space.phi*k);
    plot(Space.phi,circshift(abs(Vect).^2/max(abs(Vect).^2),S.Space.N/2),'Parent',ax(2),'Color',[0,0,1],'LineWidth',1);
    stem(fftshift(Space.k),fftshift(10*log10(abs(fft(Vect)).^2/max(abs(fft(Vect)).^2) )),'Parent',ax(4),'Color',[0,0,1],'BaseValue',-100,'Marker','none','LineWidth',1);
        
%     legend(ax(1),{'Soliton','$|X_{\hat \mu}^{(k)}(\theta_{\hat \mu})|^2$','$|Y_{\hat \mu}^{(k)}(\theta_{\hat \mu})|^2$'},...
%         'Interpreter','latex');
%     legend(ax(2),{'Soliton','$|X_{\hat \mu}^{(k)}(\theta_{\hat \mu})e^{i\theta k}|^2$','$|Y_{\hat \mu}^{(k)}(\theta_{\hat \mu})e^{i\theta k|^2}$'},...
%         'Interpreter','latex');
%     legend(ax(3),{'$|X_{\hat \mu}^{(k)}(m)|^2$','$|Y_{\hat \mu}^{(k)}(m)|^2$'},...
%         'Interpreter','latex');
%     legend(ax(4),{'Soliton','$|X_{\hat \mu}^{(k)}(\mu)e^{i\theta k}|^2$','$|Y_{\hat \mu}^{(k)}(\mu))e^{i\theta k|^2}$'},...
%         'Interpreter','latex');

    
%     Vect = ifft(S.Stab.Vk.Vectors(1:S.Space.N,2));
%     plot(S.Space.phi,abs(Vect).^2/max(abs(Vect).^2),'Position',ax(1),'Color',[0,0,1]);
%     
%     Vect = ifft(S.Stab.Vk.Vectors(S.Space.N+1:2*S.Space.N,1));    
%     plot(S.Space.phi,abs(Vect).^2/max(abs(Vect).^2),'Position',ax(2),'Color',[1,0,0]);
%     Vect = ifft(S.Stab.Vk.Vectors(S.Space.N+1:2*S.Space.N,2));
%     plot(S.Space.phi,abs(Vect).^2/max(abs(Vect).^2),'Position',ax(2),'Color',[0,0,1]);
% 
%     Vect = ifft(S.Stab.Vk.Vectors(S.Space.N+1:2*S.Space.N,1));        
%     plot(S.Space.phi,abs(Vect).^2/max(abs(Vect).^2),'Position',ax(2));
%     
%     ax(1).XLabel.String = 'Re[$\lambda$]';
%     ax(1).YLabel.String = 'Im[$\lambda$]';
% 
%     ax(2).XLabel.String = 'k';
%     ax(2).YLabel.String = 'Re[$\lambda^{(k)}$]';
%     
%     ax(3).XLabel.String = 'k';
%     ax(3).YLabel.String = 'Re[$\lambda^{(k)}$]';
    
    ax(1).XLabel.String = '$\theta_{\hat\mu}/\hat\mu$';
    ax(2).XLabel.String = '$\theta$';
    ax(3).XLabel.String = '$m$';
    ax(4).XLabel.String = '$\mu = \hat\mu m + k$';
    
    axes_Style(ax(1));
    axes_Style(ax(2));
    axes_Style(ax(3));
    axes_Style(ax(4));

    ax(1).XLim = [-pi,pi]/S.In.mu_bl;
    ax(2).XLim = [-pi,0];
    ax(1).YLim = [0,1.1];
    ax(2).YLim = [0,1.1];
    
    ax(3).XLim = [-10,10];
    ax(4).XLim = [-10,10]*S.In.mu_bl;

    ax(3).YLim = [-50,5];
    ax(4).YLim = [-50,5];
end
function Psi = TransferToResontor(Psimu,mubl)

    
    Psi     = 1E-12*ones(1,2^12);
    Psi(1)  = Psimu(1);
    for i = 1:floor(2^6/mubl)
        Psi(1+mubl*i)     =   Psimu(i+1);
        Psi(end-mubl*i+1) =   Psimu(end+1-i);
    end

end
function  Plot_Static_StabilityK(Stat_1,k,ax)

    [~,Id] = find(Stat_1(1).Stab.k == k);
    
    for i = 1:size(Stat_1,2)
        
        UnstLambda = unique( Stat_1(i).Stab.Values(Id,Stat_1(i).Stab.Values(Id,:)>1) )/Stat_1(i).In.kappa;
        
        ReLambda = uniquetol(real(Stat_1(i).Stab.Values(Id,:)))/Stat_1(i).In.kappa;
        ImLambda = uniquetol(imag(Stat_1(i).Stab.Values(Id,:)))/Stat_1(i).In.kappa;
%Stat_1(i).Eq.delta*ones(size(ReLambda))
        plot(i*ones(size(ReLambda)),ReLambda...
                       ,'Color',[0,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(1),'MarkerSize',15);
%Stat_1(i).Eq.delta*ones(size(ImLambda)),                   
        plot(i*ones(size(ImLambda)),ImLambda...
                       ,'Color',[0,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(2),'MarkerSize',15);
%Stat_1(i).Eq.delta*                 ones(size(UnstLambda)),  
        plot(i*ones(size(UnstLambda)),real(UnstLambda)...
                       ,'Color',[1,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(1),'MarkerSize',15);
%Stat_1(i).Eq.delta*ones(size(UnstLambda)),                   
        plot(i*ones(size(UnstLambda)),imag(UnstLambda)...
                       ,'Color',[1,0,0],'LineStyle','none',...
                       'Marker','.','Parent',ax(2),'MarkerSize',15);
        
    end
    
    
    ax(1).XLabel.String = '$\delta/\kappa$';
    ax(1).YLabel.String = '$Re[\lambda^{(k)}_{m}]$';
    ax(2).XLabel.String = '$\delta/\kappa$';
    ax(2).YLabel.String = '$Im[\lambda^{(k)}_{m}]$';
    
    axes_Style(ax(1));
    axes_Style(ax(2));
 %   axes_Style(ax(4));
end
    function axes_Style(ax)

         ax.Box                  = 'on';
         ax.Layer               = 'top';
         ax.FontSize             = 13;
         ax.LineWidth            = 1;
         ax.TickLabelInterpreter = 'latex';
         ax.XLabel.Interpreter   = 'latex';
         ax.YLabel.Interpreter   = 'latex';
         ax.XLabel.FontSize   = 15;
         ax.YLabel.FontSize   = 15;

    end