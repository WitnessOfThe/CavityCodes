function  Plot_Dynamics_Rf_Power_and_D1(CW,Temp,ind_t,k)

        Dressed_State   = CW.An.Omega_mu;
        Base_value  = -50;
        k_ins =k;
%%
        N_t = size(ind_t,2);
        
        dt =  (Temp.Sol.t(ind_t(2)) - Temp.Sol.t(ind_t(1)))/Temp.Eq.norm;
        tau = ( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) )/Temp.Eq.norm;
        
        f = [0:N_t/2-1,-N_t/2:-1]/tau/1E6;

        
        t_1 = proPlot([],[],[]);    
        Psi_theta = ifft(Temp.Sol.Psi(ind_t,:),[],2)*Temp.Space.N;
        
        for  i = 1:size(k,2)
        
            ind = find(Temp.Space.k(Temp.Eq.mode_range) == k(i));
            k_mat{i} = strcat('$|\mu|$=',num2str(k(i)));
            t_1 = t_1.addData(Temp.Sol.t(ind_t)/Temp.Eq.norm,10*log10(abs(Temp.Sol.Psi(ind_t,ind)).^2*2*pi).');
        end
        
        Temp_Psi =  ifft( Psi_theta(:,1) )*N_t*dt/tau;
        
        t_1 = t_1.changeAxisOptions('XLabelText','$\omega_\mu-D_1\mu$ (MHz)', 'YLabelText','Power (dB)',...  
                             'FontSize',13,'XLim',[min(Temp.Sol.t(ind_t)/Temp.Eq.norm),max(Temp.Sol.t(ind_t)/Temp.Eq.norm)],'YLim',[Base_value,25]);
                         
        t_1 = t_1.changeFigOptions('Height',12,...
                     'Width',16);
        
        t_2 = proPlot([],[],[]);    
        t_2 = t_2.addData(fftshift(f),10*log10(fftshift(abs(Temp_Psi).^2*2*pi)).','Color',[0,0,0]);
        
%%

        t_2 = t_2.changeAxisOptions('XLabelText','$\omega_\mu-D_1\mu$ (MHz)',...
                             'YLabelText','Power (dB)','FontSize',13,'XLim',[-30,30],'YLim',[Base_value,25]);
%%        
        figure('Name','Temporal_Rf_Spectrums');
        CF_2 = conFigure([t_1,t_2],1,2, 'Height', 11, 'Width', 18*2,'Labels',false);
        legend(CF_2.proPlotArray(1, 1).axis1,k_mat,'Location','northwest','NumColumns',4,'Interpreter','latex')
   %     d_t_phi    = trapz(f.'.*abs(Temp_Psi).^2)./trapz(abs(Temp_Psi).^2)/1e3;
 

end
