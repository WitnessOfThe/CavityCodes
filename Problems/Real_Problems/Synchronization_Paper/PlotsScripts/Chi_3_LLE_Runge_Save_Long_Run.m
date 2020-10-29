function Chi_3_LLE_Runge_Save_Long_Run(Path,CaF,Ind)

    ind_t  = (size(CaF.Temp.Sol.Psi,1)/2+1):size(CaF.Temp.Sol.Psi,1);
    tau = CaF.Temp.Sol.t(ind_t(end)) - CaF.Temp.Sol.t(ind_t(1))/ CaF.Temp.Eq.norm;
    N_t = size(ind_t,2);
    f = [0:N_t/2-1,-N_t/2:-1]/tau*2*pi;
    
    for i = 1:size(CaF.Temp.Eq.mode_range,2)
        
        Power_mu(i)         =  trapz(abs(CaF.Temp.Sol.Psi(ind_t,i)).^2*2*pi)/tau*tau/N_t;
        freq_mu(i)          = trapz(f.*abs(ifft(CaF.Temp.Sol.Psi(ind_t,i))).^2.')./trapz(abs(ifft(CaF.Temp.Sol.Psi(ind_t,i))).^2);
    end
    
    Save.Stat             = CaF.Stat;
    Save.Temp.In          = CaF.Temp.In;
    Save.Temp.Eq          = CaF.Temp.Eq;
%    Save.Temp.Sol.Psi_mu  = CaF.Temp.Sol.Psi(:,SaveInd);
    Save.Temp.Sol.Psi_end = CaF.Temp.Sol.Psi(end,:);
    Save.Temp.Sol.t       = CaF.Temp.Sol.t(:);
    Save.Temp.Sol.Power    = Power_mu;
    Save.Temp.Sol.freq    = freq_mu;
    
    [tt_1,tt_2] = Plot_Dynamics_Result_pcolors(CaF.Temp,1,0);
    [tt_3,tt_4] = Plot_Dynamics_Result_LinePlots_Spectrums(CaF.Temp,0);
    [tt_5,tt_6] = Plot_Dynamics_Rf_pcolor(CaF.CW,CaF.Temp,[min(CaF.Temp.Space.k(CaF.Temp.Eq.mode_range)):max(CaF.Temp.Space.k(CaF.Temp.Eq.mode_range))],ind_t,0);
    figure;
    CF = conFigure([tt_1,tt_2,tt_3,tt_4,tt_5,tt_6],2,3, 'UniformPlots', true, 'Height', 18, 'Width', 18,'Labels',false);
    h = gcf;
    
    if ~exist(strcat(Path,'/jpg'),'dir')
        
        mkdir(strcat(Path,'/jpg'))
        
    end
    
    if ~exist(strcat(Path,'/Data'),'dir')
        
        mkdir(strcat(Path,'/Data'))
        
    end
    
    print(h,strcat(Path,'/jpg/','Power=',num2str(CaF.Temp.In.P),'Delta=',num2str(CaF.Temp.In.delta/2/pi),'.jpg'),'-djpeg','-r300');
    close(h);
    save(strcat(Path,'/Data/',num2str(Ind)),'Save');
    clear variables;
  
    
end
