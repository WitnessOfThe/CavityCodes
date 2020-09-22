function CF_1 = Plot_Dynamics_Rf_Spectrums_mu_pcolor(CW,Temp,ind_t,k,k_ins)

        Dressed_State   = CW.An.Omega_mu;
        Dressed_State_1 = Dressed_State(1,:);%max(Dressed_State,[],2);
        Dressed_State_2 = Dressed_State(2,:);%min(Dressed_State,[],2);

        Grid_Color  = [0.8,0.8,0.8];
        Base_value  = -50;
        Freq_scale  = 1E3*2*pi;
%%
        N_t = size(ind_t,2);
        dt =  (Temp.Sol.t(ind_t(2)) - Temp.Sol.t(ind_t(1)))/Temp.Eq.norm;
        tau = ( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) )/Temp.Eq.norm;
        f = [0:N_t/2-1,-N_t/2:-1]/tau/Freq_scale*2*pi;
    
        i=1;
            ind = find(Temp.Space.k((Temp.Eq.mode_range)) == k(i));
            k_vector(i) =  Temp.Space.k(Temp.Eq.mode_range(Temp.Space.k((Temp.Eq.mode_range)) == k(i)));
            Temp_Psi = fftshift(ifft(Temp.Sol.Psi(ind_t,ind))*N_t)*dt/tau;
            Psi_mu   = 10*log10(abs(Temp.Sol.Psi(ind_t(end),:)).^2*2*pi);
            
            t_pl = proPlot(k_vector(i)*ones(1,N_t),fftshift(f),10*log10(abs(Temp_Psi).^2*2*pi).','PlotType','plot3','Color',[0,0,0]);
            t_pl = t_pl.addData(k_vector(i)*ones(1,N_t),fftshift(f),Base_value*ones(1,N_t),'PlotType','plot3','Marker','none','Color',Grid_Color,'LineStyle',':');
        
        for i = 1:size(k,2)
            
            ind = find(Temp.Space.k((Temp.Eq.mode_range)) == k(i));
            k_vector(i) =  Temp.Space.k(Temp.Eq.mode_range(Temp.Space.k((Temp.Eq.mode_range)) == k(i)));
            
            Temp_Psi = fftshift(ifft(Temp.Sol.Psi(ind_t,ind))*N_t)*dt/tau;
            
            t_pl = t_pl.addData(max(k)*ones(1,N_t),fftshift(f),10*log10(abs(Temp_Psi).^2*2*pi).','PlotType','plot3','Color',[0 0.450980392156863 0.741176470588235],'LineWidth',2);
            t_pl = t_pl.addData(k_vector(i)*ones(1,100),max(f)*ones(1,100),linspace(Base_value,Psi_mu(ind),100),'PlotType','plot3','Color',[0.470588235294118 0.670588235294118 0.188235294117647],'LineWidth',2);
            
            t_pl = t_pl.addData(k_vector(i)*ones(1,N_t),fftshift(f),10*log10(abs(Temp_Psi).^2*2*pi).','PlotType','plot3','Color',[0,0,0]);
            t_pl = t_pl.addData(k_vector(i)*ones(1,N_t),fftshift(f),Base_value*ones(1,N_t),'PlotType','plot3','Marker','none','Color',Grid_Color,'LineStyle',':');
            
        end
        
        t_pl = t_pl.addData(max(k)*ones(1,size(CW.Space.k,2)),linspace(min(f),max(f),size(CW.Space.k,2)),Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','none','Color',[0,0,0],'LineStyle','-','LineWidth',1);        
        t_pl = t_pl.addData(fftshift(CW.Space.k),max(f)*ones(1,size(CW.Space.k,2)),Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','none','Color',[0,0,0],'LineStyle','-','LineWidth',1);
        
        t_pl = t_pl.addData(fftshift(CW.Space.k),zeros(1,size(CW.Space.k,2)),Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','none','Color',Grid_Color,'LineStyle','--','LineWidth',2);
        
%        t_pl = t_pl.addData(fftshift(CW.Space.k),fftshift(Dressed_State_1(Temp.Space.k ==  2))/2/pi/1E6*ones(1,size(CW.Space.k,2)),Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','o','Marker','none','Color',Grid_Color,'LineStyle','--','LineWidth',2);
 %       t_pl = t_pl.addData(fftshift(CW.Space.k),fftshift(Dressed_State_2(Temp.Space.k == -2))/2/pi/1E6*ones(1,size(CW.Space.k,2)),Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','o','Marker','none','Color',Grid_Color,'LineStyle','--','LineWidth',2);
        
        t_pl = t_pl.addData(fftshift(CW.Space.k),fftshift(Dressed_State_1)/Freq_scale,Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','.','MarkerSize',16,'Color',[1,0,0],'LineStyle','none');
        t_pl = t_pl.addData(fftshift(CW.Space.k),fftshift(Dressed_State_2)/Freq_scale,Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','.','MarkerSize',16,'Color',[0,0,1],'LineStyle','none');
        t_pl = t_pl.addData(fftshift(CW.Space.k(Dressed_State_2 ==0)),fftshift(Dressed_State_2(Dressed_State_2 ==0))/Freq_scale,Base_value*ones(1,size(CW.Space.k(Dressed_State_2 ==0),2)),'PlotType','plot3','Marker','.','MarkerSize',16,'Color',[0,1,0],'LineStyle','none');
        
        t_pl = t_pl.changeAxisOptions('XLabelText','$\mu$',...
                             'YLabelText','$\omega_\mu-D_1\mu$ (kHz)', 'ZLabelText','Power (dB)',...  
                             'FontSize',13,'XLim',[min(k_vector),max(k_vector)],'YLim',[min(f),max(f)],'ZLim',[Base_value,15]);
        t_pl = t_pl.changeFigOptions('Height',12,...
                     'Width',16);
        
%%
        t_pl_ins =  proPlot(1,1);
        
        for i = 1:size(k,2)
            
            ind = find(Temp.Space.k((Temp.Eq.mode_range)) == k(i));
            k_vector(i) =  Temp.Space.k(Temp.Eq.mode_range(Temp.Space.k((Temp.Eq.mode_range)) == k(i)));
            
            Temp_Psi = fftshift(ifft(Temp.Sol.Psi(ind_t,ind))*N_t)*dt/tau;
            if max(10*log10(abs(Temp_Psi).^2*2*pi)) > Base_value
                if k(i) > 0 
                    t_pl_ins = t_pl_ins.addData(fftshift(f),10*log10(abs(Temp_Psi).^2*2*pi).','Color',[1,0,0]);
                end
                if k(i) < 0 
                    t_pl_ins = t_pl_ins.addData(fftshift(f),10*log10(abs(Temp_Psi).^2*2*pi).','Color',[0,0,1]);
                end
                if k(i) == 0 
                    t_pl_ins = t_pl_ins.addData(fftshift(f),10*log10(abs(Temp_Psi).^2*2*pi).','Color',[0,0,0]);
                end
            end
        end
        t_pl_ins = t_pl_ins.changeAxisOptions('XLabelText','$\omega_\mu-D_1\mu$ (kHz)',...
                             'YLabelText','Power (dB)','FontSize',13,'XLim',[-100,100],'YLim',[Base_value,15]);
%%        
      ind = find(Temp.Space.k((Temp.Eq.mode_range)) == k_ins(1));
      Temp_Psi = ifft(Temp.Sol.Psi(ind_t,ind))*N_t*dt/tau;
      d_t_phi_1    = trapz(f.'.*abs(Temp_Psi).^2)./trapz(abs(Temp_Psi).^2)*1e6;
      ind = find(Temp.Space.k((Temp.Eq.mode_range)) == k_ins(2));
      Temp_Psi = ifft(Temp.Sol.Psi(ind_t,ind))*N_t*dt/tau;
      d_t_phi_2    = trapz(f.'.*abs(Temp_Psi).^2)./trapz(abs(Temp_Psi).^2)*1e6;
      d_t_phi      = (d_t_phi_2 - d_t_phi_1)/ ( k_ins(2)- k_ins(1));
      
         [tt_1,tt_2] =  Plot_Dynamics_Result_pcolors(Temp,1,0);       
        figure('Name','Temporal_Rf_Spectrums');
        CF_1 = conFigure([t_pl,t_pl_ins,tt_1,tt_2],2,2, 'Height', 11*2, 'Width', 18*2,'Labels',false);
            %   h = gcf;
        annotation(gcf,'textbox',...
    [0.566642361111111 0.752859848484849 0.0813148148148147 0.161155303030303],...
    'String',{strcat('$d_{',num2str(k_ins(1)),',',num2str(k_ins(2)),'}=$',num2str(d_t_phi),'Hz')},...
    'Interpreter','latex',...
    'FontSize',16,...
    'FitBoxToText','off',...
    'EdgeColor','none');
%        figure('Name','Fields_Spectrums_Carpets');
%        CF_2 = conFigure([tt_1,tt_2],1,2, 'Height', 11, 'Width', 18*2,'Labels',false);
end
