function Chi_3_LLE_Assynch_Paralell_exec_Sol(Res_Branch,Path,ii,Res,Runge,full_pic)

    Alph_Ind =    (letters(ii+26*27));

    if~isfile(strcat(Path,'/Data/',Alph_Ind{1},'.mat'))

        Res.Temp.In       = Res.Stat.In;
        Res.Temp          = Chi_3_LLE_Normalization_Without_D_Coeff(Res.Temp);       


%         Res.CW.In         = Res.Temp.In;
%         Res.CW            = Res.CW.Met.Solve(Res.CW);
%         Res.CW.In.g       = Res.CW.Sol.g(Res.Temp.Par.CW_num)*Res.CW.Eq.norm;   
%         Res.CW            = Res.CW.Met.Mi_Formula(Res.CW);   
% 
        Res             =   Res.Temp.Met.Ev_Start_Point(Res);  

        Res.Temp.Met    =                                       [];
tic
        Res(1).Temp.Sol =    Chi_3_LLE_Runge_Kuarong_mex(Res.Temp,Runge);
toc
    %    Chi_3_LLE_Runge_Save_Long_Run_from_Soliton(Path,Res,ii,Res_Branch,full_pic)

    end
      clearvars;
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

