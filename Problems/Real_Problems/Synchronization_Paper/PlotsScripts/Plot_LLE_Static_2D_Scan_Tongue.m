function Plot_LLE_Static_2D_Scan_Tongue(Upper,Lower,mu,Flag)
%%
    
    Mode_U_mu = NaN(size(Upper,2),2*Upper(1).Stat(1).Par.i_max)+1i*NaN(size(Upper,2),2*Upper(1).Stat(1).Par.i_max);    
    Num_unstable_U = NaN(size(Upper,2),2*Upper(1).Stat(1).Par.i_max); 
    delta_U   =  zeros(size(Upper,2),2*Upper(1).Stat(1).Par.i_max);    
    Power_U   =  zeros(size(Upper,2),2*Upper(1).Stat(1).Par.i_max); 
    k_max_pcolor = zeros(size(Upper,2),2*Upper(1).Stat(1).Par.i_max); 
    
    Mode_L_mu = NaN(size(Lower,2),2*Lower(1).Stat(1).Par.i_max)+1i*NaN(size(Lower,2),2*Lower(1).Stat(1).Par.i_max);
    delta_L   = zeros(size(Lower,2),2*Lower(1).Stat(1).Par.i_max);    
    Power_L   = zeros(size(Lower,2),2*Lower(1).Stat(1).Par.i_max);    
    
%%    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    
    
  for i_p = 1:size(Upper,2)
      
      for i_d = 1:size(Upper(i_p).Stat,2)
          
          Mode_U_mu(i_p,i_d) = Upper(i_p).Stat(i_d).Sol.Psi_k(mu+1);
          delta_U(i_p,i_d)   = Upper(i_p).Stat(i_d).In.delta/Upper(i_p).Stat(i_d).In.kappa;
          Power_U(i_p,i_d)   = Upper(i_p).Stat(i_d).In.P;
          Num_unstable_U(i_p,i_d)   = sum(real(Upper(i_p).Stat(i_d).Stab.E_values > 0));
          
      end
      
  end
    
  for i_p = 1:size(Lower,2)
      
      for i_d = 1:size(Lower(i_p).Stat,2)
          
          Mode_L_mu(i_p,i_d) = Lower(i_p).Stat(i_d).Sol.Psi_k(mu+1);
          delta_L(i_p,i_d)   = Lower(i_p).Stat(i_d).In.delta/Lower(i_p).Stat(i_d).In.kappa;
          Power_L(i_p,i_d)   = Lower(i_p).Stat(i_d).In.P;
          
      end
      
  end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%  
    k_max_acc = [];
    max_e_v = 1;
    for i_p = 1:size(Upper,2)

        for i_d = 1:size(Upper(i_p).Stat,2)
            
           if Num_unstable_U(i_p,i_d) > 0
               
                Vectors_Set = Upper(i_p).Stat(i_d).Stab.E_vectors(1:Upper(i_p).Stat(i_d).Space.N,1:end).'...
                + conj(Upper(i_p).Stat(i_d).Stab.E_vectors(Upper(i_p).Stat(i_d).Space.N...
                          + 1:2*Upper(i_p).Stat(i_d).Space.N,1:end)).';
                [~,ind_max] = maxk(Vectors_Set,max_e_v,2,'ComparisonMethod','abs');

                for i = 1:size(ind_max,1)

                    k_max(i_p,i_d).k(i,1:max_e_v) =  Upper(i_p).Stat(i_d).Space.k(ind_max(i,:));
                     
                end
                
                k_max_acc(end+1:end+size(ind_max,1),1:max_e_v) = k_max(i_p,i_d).k;
                
           end
           
        end

    end
   k_max_unique = unique((k_max_acc),'rows');
%%
    for i_p = 1:size(Upper,2)

        for i_d = 1:size(Upper(i_p).Stat,2)
            
           if Num_unstable_U(i_p,i_d) > 0
    
                k_max_pcolor(i_p,i_d) =  k_max(i_p,i_d).k(1,1);
                
           end
           
        end
        
    end
    
    k_max_pcolor(k_max_pcolor == 0) = NaN;    
    
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Mode_L_mu(isnan( Mode_L_mu)) = 0;
% Mode_U_mu(isnan( Mode_U_mu)) = 0;

    tt_1 = proPlot(delta_L,Power_L,abs(Mode_L_mu).^2,'PlotType','surf');
    tt_1 = tt_1.addData(delta_U,Power_U,abs(Mode_U_mu).^2,'PlotType','surf');

    tt_2 = proPlot(delta_U,Power_U,Num_unstable_U,'PlotType','surf');
    
    tt_3 = proPlot(delta_U,Power_U,abs(k_max_pcolor),'PlotType','surf');
    
%%
    tt_1 = tt_1.changeAxisOptions('XLabelText','$\delta/\kappa$',...
                    'YLabelText','$\mathcal{W}$ [W]',...  
                    'FontSize',13);
    tt_2 = tt_2.changeAxisOptions('XLabelText','$\delta/\kappa$',...
                    'YLabelText','$\mathcal{W}$ [W]',...  
                    'FontSize',13);
    tt_3 = tt_3.changeAxisOptions('XLabelText','$\delta/\kappa$',...
                    'YLabelText','$\mathcal{W}$ [W]',...  
                    'FontSize',13);
%%                
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                
    if Flag
        
        figure('Name','Fields_Spectrums');
        CF = conFigure([tt_1,tt_2,tt_3],1,3, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);
        
    end

end