function Chi_3_LLE_Runge_Save_Long_Run_from_Soliton(Path,Res,Ind,Res_Branch,full_pic)

    ind_t  = round(1*size(Res.Temp.Sol.Psi,1)/4+1):size(Res.Temp.Sol.Psi,1);
    
    if mod(size(ind_t,2),2) == 1
        
        ind_t  = round(1*size(Res.Temp.Sol.Psi,1)/4+2):size(Res.Temp.Sol.Psi,1);
            
   end
        
    tau = Res.Temp.Sol.t(ind_t(end)) - Res.Temp.Sol.t(ind_t(1))/ Res.Temp.Eq.norm;
    N_t = size(ind_t,2);
    f = [0:N_t/2-1,-N_t/2:-1]/tau*2*pi;
    
    for i = 1:size(Res.Temp.Eq.mode_range,2)
        
        Power_mu(i)         = trapz(abs(Res.Temp.Sol.Psi(ind_t,i)).^2*2*pi)/tau*tau/N_t;
        freq_mu_avg(i)      = trapz(f.*abs(ifft(Res.Temp.Sol.Psi(ind_t,i))).^2.')./trapz(abs(ifft(Res.Temp.Sol.Psi(ind_t,i))).^2);
        [~,ind]             = max(abs(ifft(Res.Temp.Sol.Psi(ind_t,i))).^2);
        freq_mu_max(i)      = f(ind);
        
    end
    
    Save.CW                 = Res.CW;
    Save.Stat               = Res.Stat;
    Save.Temp.In            = Res.Temp.In;
    Save.Temp.Eq            = Res.Temp.Eq;
    Save.Temp.Sol.Psi_end   = Res.Temp.Sol.Psi(end,:);
    Save.Temp.Sol.dt        = Res.Temp.Sol.t(end);
    Save.Temp.Sol.N_t       = N_t;
    
    Save.Temp.Sol.Power     = Power_mu;
    Save.Temp.Sol.freq_avg  = freq_mu_avg;
    Save.Temp.Sol.freq_max  = freq_mu_max;
    
    [p_wh_1,p_wh_2,~,p_wh_4]         = Plot_LLE_Static_Branch_Soliton(Res.CW,Res_Branch.Stat,Res_Branch.Stat,0,1,Res.Stat);
    [p_1,p_2,~]                      = Plot_Static_Field_Spectrums_Soliton(Res.Stat,0);
    [p_dot_3,~,~,p_dot_6,p_dot_7]    = Plot_Static_Field_Stability_Soliton(Res.Stat,0);

    [d1,d2,d3] = Plot_Dynamics_Rf_pcolor_Soliton(Res.Stat,Res.Temp,ind_t,0)   ;
    [d4,d5]    = Plot_Dynamics_Result_pcolors(Res.Temp,1,0);
    [d6,d7]    = Plot_Dynamics_Result_LinePlots_Spectrums(Res.Temp,0);
    full_pic   = full_pic.addData(Res.Stat.Eq.delta,Res.Stat.In.P,[],'Marker','x','Color',[1,0,0],'MarkerSize',6);
%%      
    figure;
    
    CF = conFigure([p_wh_1,p_wh_2,p_wh_4,p_1,p_2,p_dot_3,p_dot_6,p_dot_7,d1,d2,d3,d4,d5,d6,d7,full_pic],2,8, 'UniformPlots', true, 'Height', 20, 'Width', 45,'Labels',false);
    h = gcf;
    Alph_Ind =    (letters(Ind+26*27))  ;
    if ~exist(strcat(Path,'/jpg'),'dir')
        
        mkdir(strcat(Path,'/jpg'))
        
    end
    
    if ~exist(strcat(Path,'/Data'),'dir')
        
        mkdir(strcat(Path,'/Data'))
        
    end
    
    print(h,strcat(Path,'/jpg/',Alph_Ind{1},'_Power=',num2str(Res.Temp.In.P),'Delta=',num2str(Res.Temp.In.delta/Res.Temp.In.kappa),'.jpg'),'-djpeg','-r300');
    close(h);
    save(strcat(Path,'/Data/',Alph_Ind{1}),'Save');
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
