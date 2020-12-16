function Plot_Bloch_Static_Branch_Save_Points(Branch,N_p,Path,ind_branch)

    N_B = size(Branch(ind_branch).Stat,2);
    index_step = floor(N_B/N_p);
    
    if ~exist(strcat(Path),'dir')
        
        mkdir(strcat(Path))
        
    end
    indexes =    1:index_step:N_B;
%    indexes(size(Branch(ind_branch).Stat,2)) = size(Branch(ind_branch).Stat,2);
    for i_for = 53:size(indexes,2)
        
        h =  Create_fig_mu_23(Branch,ind_branch,indexes(i_for));        
        nn =letters(i_for+26*27);
        
        savefig(h,strcat(Path,nn{1}));
        print(h,strcat(Path,nn{1},'.png'),'-dpng','-r300');
        close(h)
    end
    
    
end
function h = Create_fig_mu_1(CaF_Branches,ind_branch,ind_stat)
        h=    figure('Position',[0,0,1400,900],'Color',[1,1,1]);

        Panel = tiledlayout(h,3,8,'TileSpacing','none','Padding','none');
        ax(1) = nexttile(Panel,1,[1,2]);  
        ax(2) = nexttile(Panel,3,[1,2]); 

        ax(3) = nexttile(Panel,9,[1,1]);  
        ax(4) = nexttile(Panel,10,[1,1]);  

        ax(5) = nexttile(Panel,11,[1,2]);  
        ax(6) = nexttile(Panel,17,[1,2]);  
        ax(7) = nexttile(Panel,19,[1,2]);  

        ax(8) = nexttile(Panel,13,[1,2]);  
        ax(9) = nexttile(Panel,15,[1,2]);  
        ax(10) = nexttile(Panel,21,[1,2]);  
        ax(11) = nexttile(Panel,23,[1,2]);  

        ax(12) = nexttile(Panel,5,[1,2]);  
        ax(13) = nexttile(Panel,7,[1,2]);  
        for i =1:size(ax,2)
            hold(ax(i),'on');
        end
        ind_br   = ind_branch;

        Plot_LLE_Bloch_Static_Multiple_Branches(CaF_Branches(ind_br).CW(1),CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(1:end),ax(1:2));
        Plot_Static_Field_Spectrums(CaF_Branches(ind_br).Stat(ind_stat),ax(3:4));   
        Plot_LLE_Bloch_Static_Field_Stability(CaF_Branches(ind_br).Stat(ind_stat),[ax(5:11)]);
        Plot_LLE_Bloch_Static_Branch_Stability(CaF_Branches(ind_br).CW,CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(ind_br),ax(12:13));

end
function h = Create_fig_mu_23(CaF_Branches,ind_branch,ind_stat)
        h= figure('Position',[0,0,1400,700],'Color',[1,1,1]);

       Panel = tiledlayout(h,3,16,'TileSpacing','none','Padding','none');
    ax(1) = nexttile(Panel,1,[1,4]);  
    ax(2) = nexttile(Panel,5,[1,4]); 
    
    ax(3) = nexttile(Panel,17,[1,2]);  
    ax(4) = nexttile(Panel,19,[1,2]);  
   
    ax(5) = nexttile(Panel,21,[1,4]);  
    ax(6) = nexttile(Panel,33,[1,4]);  
    ax(7) = nexttile(Panel,37,[1,4]);  
    
    ax(8) = nexttile(Panel,25,[1,2]);  
    ax(9) = nexttile(Panel,27,[1,2]);  
    ax(10) = nexttile(Panel,29,[1,2]);  
    ax(11) = nexttile(Panel,31,[1,2]); 
    
    ax(12) = nexttile(Panel,41,[1,2]);  
    ax(13) = nexttile(Panel,43,[1,2]);  
    ax(14) = nexttile(Panel,45,[1,2]);  
    ax(15) = nexttile(Panel,47,[1,2]);  

    ax(16) = nexttile(Panel,9,[1,2]);  
    ax(17) = nexttile(Panel,11,[1,2]);  
    ax(18) = nexttile(Panel,13,[1,2]);  
    ax(19) = nexttile(Panel,15,[1,2]);  
    
    for i =1:size(ax,2)
        hold(ax(i),'on');
    end
        ind_br   = ind_branch;

    Plot_LLE_Bloch_Static_Multiple_Branches(CaF_Branches(ind_br).CW(1),CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(1:end),ax(1:2));
    Plot_Static_Field_Spectrums(CaF_Branches(ind_br).Stat(ind_stat),ax(3:4));   
    Plot_LLE_Bloch_Static_Field_Stability(CaF_Branches(ind_br).Stat(ind_stat),[ax(5:15)]);
    Plot_LLE_Bloch_Static_Branch_Stability(CaF_Branches(ind_br).CW,CaF_Branches(ind_br).Stat(ind_stat),CaF_Branches(ind_br),ax(16:19));

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
