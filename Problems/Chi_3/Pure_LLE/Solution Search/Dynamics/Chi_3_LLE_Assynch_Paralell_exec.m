function Chi_3_LLE_Assynch_Paralell_exec(Res,delta_matrix,power_matrix,ii,Path,Sim_zone,N_Mode,Runge,CaF_1D_Upper,CaF_1D_Lower,mu)

    Alph_Ind =    (letters(ii+26*27))  ;

      if~isfile(strcat(Path,'/Data/',Alph_Ind{1},'.mat'))
          
                Res.Temp.In.delta = delta_matrix;
                Res.Temp.In.P     = power_matrix;
                Res.Temp          = Chi_3_LLE_Normalization(Res.Temp,N_Mode);       
                

                Res.CW.In         = Res.Temp.In;
                Res.CW            = Res.CW.Met.Solve(Res.CW,Res.Temp.Space.N);
                Res.CW.In.g       = Res.CW.Sol.g(Res.Temp.Par.CW_num)*Res.CW.Eq.norm;   
                Res.CW            = Res.CW.Met.Mi_Formula(Res.CW,Res.Temp.Space.N);   
                
                Res             =          Res.Temp.Met.Ev_Start_Point(Res);  
                
                Res.Temp.Met    =                                       [];
                
                Res(1).Temp.Sol =    Chi_3_LLE_Runge_Kuarong_mex(Res.Temp,N_Mode,Runge);
                
                Chi_3_LLE_Runge_Save_Long_Run_from_Stat(Path,Res,ii,CaF_1D_Upper,CaF_1D_Lower,mu)

      end
      
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

