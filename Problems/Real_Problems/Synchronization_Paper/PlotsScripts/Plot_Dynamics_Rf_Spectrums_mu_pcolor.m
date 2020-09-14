function  Plot_Dynamics_Rf_Spectrums_mu_pcolor(CW,Temp,ind_t,k)

    Dressed_State   = CW.An.Omega_mu;
    Dressed_State_1 = Dressed_State(1,:);%max(Dressed_State,[],2);
    Dressed_State_2 = Dressed_State(2,:);%min(Dressed_State,[],2);

    Grid_Color  = [0.8,0.8,0.8];
    Base_value  = -70;
%%
        N_t = size(ind_t,2);
        dt =  (Temp.Sol.t(ind_t(2)) - Temp.Sol.t(ind_t(1)))/Temp.Eq.norm*1E6;
        tau = ( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) )/Temp.Eq.norm;
        f = [0:N_t/2-1,-N_t/2:-1]/tau/1E6;
    
        i=1;
            ind = find(Temp.Space.k == k(i));
            k_vector(i) =  Temp.Space.k(Temp.Space.k == k(i));
            Temp_Psi = fftshift(ifft(Temp.Sol.Psi(ind_t,ind))*N_t)*dt;
            
            t_pl = proPlot(k_vector(i)*ones(1,N_t),fftshift(f),10*log10(abs(Temp_Psi).^2*2*pi).','PlotType','plot3','Color',[0,0,0]);
            t_pl = t_pl.addData(k_vector(i)*ones(1,N_t),fftshift(f),Base_value*ones(1,N_t),'PlotType','plot3','Marker','none','Color',Grid_Color,'LineStyle','--');
        
        for i = 2:size(k,2)
            
            ind = find(Temp.Space.k == k(i));
            k_vector(i) =  Temp.Space.k(Temp.Space.k == k(i));
            Temp_Psi = fftshift(ifft(Temp.Sol.Psi(ind_t,ind))*N_t)*dt;
            
            t_pl = t_pl.addData(k_vector(i)*ones(1,N_t),fftshift(f),10*log10(abs(Temp_Psi).^2*2*pi).','PlotType','plot3','Color',[0,0,0]);
            t_pl = t_pl.addData(k_vector(i)*ones(1,N_t),fftshift(f),Base_value*ones(1,N_t),'PlotType','plot3','Marker','none','Color',Grid_Color,'LineStyle','--');
            
            [~,ind_f]  = min(abs(fftshift(f) - Dressed_State_1(ind)/2/pi/1E6 ));           
            t_pl = t_pl.addData(k_vector(i)*ones(1,N_t),Dressed_State_1(ind)/2/pi/1E6*ones(1,N_t),linspace(10*log10(abs(Temp_Psi(ind_f)).^2*2*pi).',Base_value,N_t),'PlotType','plot3','Marker','none','Color',Grid_Color/2,'LineStyle',':');
            t_pl = t_pl.addData(k_vector(i),Dressed_State_1(ind)/2/pi/1E6,10*log10(abs(Temp_Psi(ind_f)).^2*2*pi).','PlotType','plot3','Marker','o');
                [~,ind_f]  = min(abs(fftshift(f) - Dressed_State_2(ind)/2/pi/1E6 ));           
            t_pl = t_pl.addData(k_vector(i)*ones(1,N_t),Dressed_State_2(ind)/2/pi/1E6*ones(1,N_t),linspace(10*log10(abs(Temp_Psi(ind_f)).^2*2*pi).',Base_value,N_t),'PlotType','plot3','Marker','none','Color',Grid_Color/2,'LineStyle',':');
            t_pl = t_pl.addData(k_vector(i),Dressed_State_2(ind)/2/pi/1E6,10*log10(abs(Temp_Psi(ind_f)).^2*2*pi).','PlotType','plot3','Marker','o');

        end
        
        t_pl = t_pl.addData(fftshift(CW.Space.k),zeros(1,size(CW.Space.k,2)),Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','none','Color',Grid_Color,'LineStyle','--');
        t_pl = t_pl.addData(fftshift(CW.Space.k),fftshift(Dressed_State_1(Temp.Space.k ==  2))/2/pi/1E6*ones(1,size(CW.Space.k,2)),Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','o','Marker','none','Color',Grid_Color,'LineStyle','--');
        t_pl = t_pl.addData(fftshift(CW.Space.k),fftshift(Dressed_State_2(Temp.Space.k == -2))/2/pi/1E6*ones(1,size(CW.Space.k,2)),Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','o','Marker','none','Color',Grid_Color,'LineStyle','--');
        t_pl = t_pl.addData(fftshift(CW.Space.k),fftshift(Dressed_State_1)/2/pi/1E6,Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','o');
        t_pl = t_pl.addData(fftshift(CW.Space.k),fftshift(Dressed_State_2)/2/pi/1E6,Base_value*ones(1,size(CW.Space.k,2)),'PlotType','plot3','Marker','o');
%%


        t_pl = t_pl.changeAxisOptions('XLabelText','$\mu$',...
                             'YLabelText','$<\partial\phi_\mu>$ (GHz)',...  
                             'FontSize',13,'XLim',[min(k_vector),max(k_vector)],'YLim',[-1000,1000],'ZLim',[Base_value,25]);
                         
%%
    figure('Name','Nonlinear Dispersion');
    t_pl.plotData
end
