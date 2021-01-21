function [tt_1,tt_2,tt_3] = Plot_Dynamics_Rf_pcolor_Soliton(Temp,ind_t,Flag)
%%
%    Dressed_State   = imag(CW.An.lambda_mu);
%    Dressed_State_1 = Dressed_State(1,:);%max(Dressed_State,[],2);
%    Dressed_State_2 = Dressed_State(2,:);%min(Dressed_State,[],2);

        ind      = 1:size( Temp.Eq.mode_range,2);

 %%  
   N_t = size(ind_t,2);
   
   f   = [0:N_t/2-1,-N_t/2:-1]/( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) )*Temp.Eq.norm;
   dt  =  (Temp.Sol.t(ind_t(2)) - Temp.Sol.t(ind_t(1)))/Temp.Eq.norm;
   tau = ( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) )/Temp.Eq.norm;

    for i = 1:size(Temp.Eq.mode_range,2)
        
        Power_mu(i)   = trapz(abs(Temp.Sol.Psi(ind_t,i)).^2*2*pi)/tau*tau/N_t;
        freq_mu_avg(i)    = trapz(f.*abs(ifft(Temp.Sol.Psi(ind_t,i))).^2.')./trapz(abs(ifft(Temp.Sol.Psi(ind_t,i))).^2);
         [~,ind_m]                 = max(abs(ifft(Temp.Sol.Psi(ind_t,i))).^2);
        freq_mu_max(i)    = f(ind_m);
        
    end
    Vel = (freq_mu_max(2)-freq_mu_max(1));
    i=1; 
   
%   L_Re_pos              = real(Stat.Stab.Dres_Spec.lam);
  % L_Re_pos(L_Re_pos<=0) = NaN;
   %L_Re_pos(L_Re_pos>=0) = 1;
   shift_freq_max = fftshift(freq_mu_max);
   tt_2 = proPlot(fftshift(Temp.Space.k(Temp.Eq.mode_range)),[shift_freq_max(2:end)-shift_freq_max(1:end-1),NaN]/Temp.In.kappa*2*pi );
%     for i = 1:size(Temp.Eq.mode_range,2)
%         tt_2 = tt_2.addData(fftshift(f-Temp.Space.k(Temp.Eq.mode_range(i))*Vel)/Temp.In.kappa, 10*log10(abs( Temp_Psi(:,i).^2*2*pi)),'Color',[0,0,0]);   
%     end

%   tt_2 = proPlot(fftshift(Temp.Space.k(Temp.Eq.mode_range)),fftshift(f)/Temp.In.kappa, 10*log10(abs( Temp_Psi).^2*2*pi),'PlotType','pcolor','DownSample2DPlot',[5000 5000]);
%   tt_3 = proPlot(Temp.Space.k(Temp.Eq.mode_range(ind)),fftshift(f)/Temp.In.kappa, 10*log10(abs( Temp_Psi).^2*2*pi),'PlotType','pcolor','DownSample2DPlot',[5000 5000]);
   tt_3 = proPlot(Temp.Space.k(Temp.Eq.mode_range((10*log10(Power_mu)>-70))),freq_mu_avg(10*log10(Power_mu)>-70)/Temp.In.kappa*2*pi,[],'LineStyle','none','Marker','o','Color',[1,0.5,0.5]);
   tt_3 = tt_3.addData(Temp.Space.k(Temp.Eq.mode_range((10*log10(Power_mu)>-70))),freq_mu_max(10*log10(Power_mu)>-70)/Temp.In.kappa*2*pi,[],'LineStyle','none','Marker','x','Color',[1,0,0.5]);
   

   tt_1 = proPlot(Temp.Space.k(Temp.Eq.mode_range),10*log10(Power_mu),[],'PlotType','stem','BaseValue',-70,'Marker','none');
  % tt_1 = tt_1.addData(Temp.Space.k(Temp.Eq.mode_range((10*log10(Power_mu)>-50))),freq_mu(10*log10(Power_mu)>-50),[], 'Axis', 2,'LineStyle','none','Marker','o','Color',[1,0.5,0.5]);
   
   
   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    Xlim = [min(Temp.Space.k(Temp.Eq.mode_range(10*log10(Power_mu)>-70)))-10,max(Temp.Space.k(Temp.Eq.mode_range(10*log10(Power_mu)>-70)))+10];
    
%    ind_Bound_Real = find(real(Stat.Stab.E_values) > 0);

  %  Im_Bound   = abs(max(imag(Stat.Stab.E_values( ind_Bound_Real)))*1.5)+0;
 %   if Im_Bound < 10*Stat.In.kappa
        
    %    Im_Bound = 10*Stat.In.kappa;
     %   
  %  end
   %     if  isempty(Im_Bound )
        
  %      Im_Bound = 10*Stat.In.kappa;
        
%    end    

    tt_2 = tt_2.changeAxisOptions('XLabelText','Mode Number',...
                         'YLabelText','Velocity',...  
                         'FontSize',13,'XLim',Xlim,'YLim',[-1,1]);%,'CAxis', [-70,max(max(10*log10(abs( Temp_Psi).^2*2*pi)))]
    tt_3 = tt_3.changeAxisOptions('XLabelText','Mode Number',...
                         'YLabelText','RF frequency/$\kappa$',...  
                         'FontSize',13,'YLim',[min(freq_mu_avg),max(freq_mu_avg)]/Temp.In.kappa*2*pi,'XLim',Xlim);%,'CAxis', [-70,max(max(10*log10(abs( Temp_Psi).^2*2*pi)))]
                     
    tt_2 = tt_2.changeFigOptions('Height', 11, 'Width', 11,'Labels',false);

    tt_1 = tt_1.changeAxisOptions('Axis', 1,'XLabelText','Mode Number',...
                         'YLabelText','Power (db)',...  
                         'FontSize',13,'YLim', [-70,max(10*log10(Power_mu))+5],'XLim',Xlim);
%     tt_1 = tt_1.changeAxisOptions('Axis', 2,...
%                                   'YAxisLocation', 'Right',...
%                                   'XAxisLocation', 'Top',...
%                                   'XLabelText', 'Frequency, $f$ (THz)',...
%                                   'YColor',[1,0.5,0.5],'XColor',[1,0.5,0.5],'YLim',[-15,15],'XLim',[-50,50]);
%                               'XTickLabel', x_tick_labels,...
 %                                 'XLim', x_lim,... 
  %                                'XTick', x_ticks_lam,...

    tt_1 = tt_1.changeFigOptions('Height', 11, 'Width', 11,'Labels',false);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    if Flag
        figure('Name','RF_Spectrums');
        CF = conFigure([tt_1,tt_2,tt_3],3,1, 'UniformPlots', true, 'Height', 20, 'Width', 10,'Labels',false);
    end
    

end
