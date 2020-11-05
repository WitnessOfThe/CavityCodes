function Chi_3_LLE_Runge_Save_Long_Run_from_Stat(Path,CaF,Ind,CaF_1D_Upper,CaF_1D_Lower,mu)

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
    Save.Temp.Sol.Psi_end = CaF.Temp.Sol.Psi(end,:);
    Save.Temp.Sol.t       = CaF.Temp.Sol.t(:);
    Save.Temp.Sol.Power    = Power_mu;
    Save.Temp.Sol.freq    = freq_mu;
    
    [tt_1,tt_2] = Plot_Dynamics_Result_pcolors(CaF.Temp,1,0);
    [tt_3,tt_4] = Plot_Dynamics_Result_LinePlots_Spectrums(CaF.Temp,0);
    [tt_5,tt_6] = Plot_Dynamics_Rf_pcolor(CaF.CW,CaF.Temp,[min(CaF.Temp.Space.k(CaF.Temp.Eq.mode_range)):max(CaF.Temp.Space.k(CaF.Temp.Eq.mode_range))],ind_t,0);
    [p_wh_1,p_wh_2,p_wh_3]    = Plot_LLE_Static_Branch(CaF.CW,CaF_1D_Upper.Stat,CaF_1D_Lower.Stat,0,1,mu,CaF_1D_Upper(1).Stat(Ind));
    [p_dot_1,p_dot_2]         = Plot_Static_Field_Spectrums(CaF_1D_Upper(1).Stat(Ind),0);
    [p_dot_3,p_dot_4,p_dot_5] = Plot_Static_Field_Stability(CaF_1D_Upper(1).Stat(Ind),0,mu);
    figure;
    CF = conFigure([tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,p_wh_1,p_wh_2,p_wh_3,p_dot_1,p_dot_2,p_dot_3,p_dot_4,p_dot_5],4,4, 'UniformPlots', true, 'Height', 25, 'Width', 35,'Labels',false);
    h = gcf;
    Alph_Ind =    (letters(Ind+26*27))  ;
    if ~exist(strcat(Path,'/jpg'),'dir')
        
        mkdir(strcat(Path,'/jpg'))
        
    end
    
    if ~exist(strcat(Path,'/Data'),'dir')
        
        mkdir(strcat(Path,'/Data'))
        
    end
    
    print(h,strcat(Path,'/jpg/',Alph_Ind{1},'_Power=',num2str(CaF.Temp.In.P),'Delta=',num2str(CaF.Temp.In.delta/CaF.Temp.In.kappa),'.jpg'),'-djpeg','-r300');
    close(h);
    save(strcat(Path,'/Data/',num2str(Ind)),'Save');
    clear variables;
  
    
end
function lets = letters(nums)
lets = arrayfun(@(n)num2char(n),nums,'UniformOutput',0);
function s = num2char(d)
  b = 26;
  n = max(1,round(log2(d+1)/log2(b)));
  while (b^n <= d)
    n = n + 1;
  end
  s(n) = rem(d,b);
  while n > 1
    n = n - 1;
    d = floor(d/b);
    s(n) = rem(d,b);
  end
  n = length(s);
  while (n > 1)
    if (s(n) <= 0)
      s(n) = b + s(n);
      s(n-1) = s(n-1) - 1;
    end
    n = n - 1;
  end
  s(s<=0) = [];
  symbols = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  s = reshape(symbols(s),size(s));
end
end
