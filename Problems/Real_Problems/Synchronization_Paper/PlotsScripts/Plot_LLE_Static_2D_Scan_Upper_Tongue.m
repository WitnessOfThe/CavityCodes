function Plot_LLE_Static_2D_Scan_Upper_Tongue(Res,Upper,mu,Flag)
%%
    
    Mode_U_mu = NaN(size(Upper,2),2*Upper(1).Stat(1).Par.i_max)+1i*NaN(size(Upper,2),2*Upper(1).Stat(1).Par.i_max);    
    Num_unstable_U = NaN(size(Upper,2),2*Upper(1).Stat(1).Par.i_max); 
    delta_U   =  NaN(size(Upper,2),2*Upper(1).Stat(1).Par.i_max);    
    Power_U   =  NaN(size(Upper,2),2*Upper(1).Stat(1).Par.i_max); 
    G_U   =  NaN(size(Upper,2),2*Upper(1).Stat(1).Par.i_max); 
    Crossing_trag = zeros(size(Upper,2),2*Upper(1).Stat(1).Par.i_max); 
    thresholds_power= zeros(size(Upper,2),2*Upper(1).Stat(1).Par.i_max); 
       
%%    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    
    
  for i_p = 1:size(Upper,2)
      
      for i_d = 1:size(Upper(i_p).Stat,2)
          
          Mode_U_mu(i_p,i_d) = Upper(i_p).Stat(i_d).Sol.Psi_k(mu+1);
          delta_U(i_p,i_d)   = Upper(i_p).Stat(i_d).In.delta/Upper(i_p).Stat(i_d).In.kappa;
          Power_U(i_p,i_d)   = Upper(i_p).Stat(i_d).In.P;
          Num_unstable_U(i_p,i_d)   = sum(real(Upper(i_p).Stat(i_d).Stab.E_values) > 0);
          
          Res.CW.In.delta    = Upper(i_p).Stat(i_d).In.delta;
          Res.CW.In.P        = Upper(i_p).Stat(i_d).In.P;
          
          Res.CW       = Res.CW.Met.Solve(Res.CW,Upper(i_p).Stat(i_d).Space.N);          
          [~,ind]       = max(abs(Res.CW.Sol.Psi));
          G_U(i_p,i_d)  = Res.CW.Sol.g(ind)*Res.CW.Eq.norm/Upper(i_p).Stat(i_d).In.kappa;
          
      end
      
  end
  
  Nd = 1000;
  delta_G = linspace(min(min(delta_U)),max(max(delta_U)),Nd);
  
  for i_d = 1:Nd
      
          Res.CW.In.delta    =  delta_G(i_d)*Res.Stat.In.kappa;
          Res.CW.In.P        = 0.1;
          
          Res.CW       = Chi_3_LLE_MI_Boundary(Res.CW,Upper(1).Stat(1).Space.N);
        
          G_MI_Up_1(i_d,:)        = Res.CW.In.g_MI(1,mu-2:mu+2)/Res.Stat.In.kappa;
          G_MI_Up_2(i_d,:)        = Res.CW.In.g_MI(2,mu-2:mu+2)/Res.Stat.In.kappa;
          
          W_MI_Up_1(i_d,:)        = Res.CW.In.W_MI_Tongue(1,mu-2:mu+2);
          W_MI_Up_2(i_d,:)        = Res.CW.In.W_MI_Tongue(2,mu-2:mu+2);
end 
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%  
%     k_max_acc = [];
%     max_e_v   = 1;
%     for i_p = 1:size(Upper,2)
% 
%         for i_d = 1:size(Upper(i_p).Stat,2)
%             
%            if Num_unstable_U(i_p,i_d) > 0
%                
%                 Vectors_Set = Upper(i_p).Stat(i_d).Stab.E_vectors(1:Upper(i_p).Stat(i_d).Space.N,1:1).'...
%                 + conj(Upper(i_p).Stat(i_d).Stab.E_vectors(Upper(i_p).Stat(i_d).Space.N...
%                           + 1:2*Upper(i_p).Stat(i_d).Space.N,1:1)).';
%                 [~,ind_max] = maxk(Vectors_Set,max_e_v,2,'ComparisonMethod','abs');
% 
%                 for i = 1:size(ind_max,1)
% 
%                     k_max(i_p,i_d).k(i,1:max_e_v) =  Upper(i_p).Stat(i_d).Space.k(ind_max(i,:));
%                      
%                 end
%                 
%                 k_max_acc(end+1:end+size(ind_max,1),1:max_e_v) = k_max(i_p,i_d).k;
%                 
%            end
%            
%         end
% 
%     end
%     k_max_unique = sort(unique(k_max_acc,'rows'),'descend');
%%
    for i_p = 1:size(Num_unstable_U,1)

        for i_d = 1:size(Num_unstable_U,2)-1
            if abs(Num_unstable_U(i_p,i_d) - Num_unstable_U(i_p,i_d+1)) ~= 0
                thresholds_power(i_p,i_d) = 1; 
            end

        end
        
    end
    for i_d = 1:size(Num_unstable_U,2)

        for i_p = 1:size(Num_unstable_U,1)-1
            if abs(Num_unstable_U(i_p,i_d) - Num_unstable_U(i_p+1,i_d)) ~= 0
                thresholds_power(i_p,i_d) = 1; 
            end

        end
        
    end
    
%    k_max_pcolor(k_max_pcolor == 0) = NaN;    
    
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Mode_L_mu(isnan( Mode_L_mu)) = 0;
% Mode_U_mu(isnan( Mode_U_mu)) = 0;

  
    tt_2 = proPlot(delta_U,Power_U,Num_unstable_U,'PlotType','pcolor');
    
    tt_3 = proPlot(delta_U,Power_U,abs(thresholds_power),'PlotType','pcolor');
     for i = 1:size(G_MI_Up_1,2)
        
        tt_3         = tt_3.addData(delta_G,W_MI_Up_1(:,i),'Color',[0,0,0]);
        tt_3         = tt_3.addData(delta_G,W_MI_Up_2(:,i),'Color',[0,0,0]);
        
    end
    tt_4 = proPlot(delta_U,G_U,abs(thresholds_power),'PlotType','pcolor');
     for i = 1:size(G_MI_Up_1,2)
        
        tt_4         = tt_4.addData(delta_G,G_MI_Up_1(:,i),'Color',[0,0,0]);
        tt_4         = tt_4.addData(delta_G,G_MI_Up_2(:,i),'Color',[0,0,0]);
        
    end
   
%%
    tt_2 = tt_2.changeAxisOptions('XLabelText','$\delta/\kappa$',...
                    'YLabelText','$\mathcal{W}$ [W]',...  
                    'FontSize',13,'XLim',[min(delta_G),max(delta_G)]);
    tt_3 = tt_3.changeAxisOptions('ColorMap',[1,1,1;1,0,0],'XLabelText','$\delta/\kappa$',...
                    'YLabelText','$\mathcal{W}$ [W]',...  
                    'FontSize',13,'XLim',[min(delta_G),max(delta_G)]);
    tt_4 = tt_4.changeAxisOptions('ColorMap',[1,1,1;1,0,0],'XLabelText','$\delta/\kappa$',...
                    'YLabelText','$g/\kappa$',...  
                    'FontSize',13,'XLim',[min(delta_G),max(delta_G)]);
                
%%                
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                
    if Flag
        
        figure('Name','Fields_Spectrums');
        CF = conFigure([tt_2,tt_3,tt_4],1,3, 'UniformPlots', true, 'Height', 20, 'Width', 20,'Labels',false);
        
    end

end

function search_for_boundary(x,Delta,Power, k_max)
    
    Pol = zeros(size(k_max,1),size(k_max,2));
    
    for i_p = 1:size(k_max,1)
        
        for i_d = 1:size(k_max,2)
            
            if sum(x == abs(k_max(i_p,i_d).k)) > 0
                
                Pol(i_p,i_d) = 1;
                
            end
            
        end
        
    end
    
end