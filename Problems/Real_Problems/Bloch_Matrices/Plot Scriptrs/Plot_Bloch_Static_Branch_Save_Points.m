function Plot_Bloch_Static_Branch_Save_Points(Branch,N_p,Path)

    N_B = size(Branch.Stat,2);
    index_step = floor(N_B/N_p);
    
    if ~exist(strcat(Path),'dir')
        
        mkdir(strcat(Path))
        
    end
    indexes =    1:index_step:N_B;
    parfor i = 1:N_p
         i_j  = indexes(i);         
    	[pb_1,pb_2]      = Plot_LLE_Bloch_Static_Multiple_Branches(Branch.CW,Branch(1).Stat(i_j),Branch,0);
        [ps_1,ps_2,ps_3] = Plot_LLE_Bloch_Static_Branch_Stability(Branch.CW,Branch.Stat(i_j),Branch,0);
        [point_1,point_2] = Plot_Static_Field_Spectrums(Branch.Stat(i_j),0);
        [stp1,stp2,stp3] = Plot_LLE_Bloch_Static_Field_Stability(Branch.Stat(i_j),0);
        
        h = figure;        
        CF = conFigure([pb_1,pb_2,ps_1,ps_2,ps_3,point_1,point_2,stp1,stp2,stp3],2,5, 'UniformPlots', true, 'Height',15, 'Width', 30,'Labels',false);
        nn =letters(i+26*27);
        print(gcf,strcat(Path,nn{1},'.png'),'-dpng','-r300');
        close(h)
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
