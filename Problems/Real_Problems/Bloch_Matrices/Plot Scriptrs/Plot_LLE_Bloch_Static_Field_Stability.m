function  Plot_LLE_Bloch_Static_Field_Stability(Stat,Flag)
    
    tt_1 = proPlot([],[],[]);
    tt_2 = proPlot([],[],[]);
    tt_3 = proPlot([],[],[]);
    tt_4 = proPlot([],[],[]);
    tt_5 = proPlot([],[],[]);
    tt_6 = proPlot([],[],[]);
    
 %%   
    for i = 1:size(Stat.Stab,2)
        
        tt_1 = tt_1.addData(real(Stat.Stab(i).E_values)/Stat.In.kappa,...
            imag(Stat.Stab(i).E_values)/Stat.In.kappa,'LineStyle','none',...
            'Marker','.','MarkerSize',15,'Color',[0,0,0]);
        
    end
%%    
    t_Max_y = max(real(Stat(1).Stab(1).E_values)/Stat(1).In.kappa);
    for i = 1:size(Stat.Stab,2)
        
        [Max_y,ind_m] = max(real(Stat(1).Stab(i).E_values)/Stat(1).In.kappa);
        if Max_y > t_Max_y 
            ind_re_max_nu = i;
            ind_re_max_mi = ind_m;
            t_Max_y = Max_y;
        end
    end
    if t_Max_y <= 0
        t_Max_y = 1;
    end
    
%%    
    i=1;
    t_Max_y_2 = max(imag(Stat(1).Stab(i).E_values(real(Stat(1).Stab(i).E_values)>0))/Stat(1).In.kappa);
    for i=1:size(Stat(1).Stab,2)
        
        Max_y = max(imag(Stat(1).Stab(i).E_values(real(Stat(1).Stab(i).E_values)>0))/Stat(1).In.kappa);
        
        if isempty( t_Max_y_2)
            t_Max_y_2 = Max_y;
        end
        if Max_y > t_Max_y_2 
            t_Max_y_2 = Max_y;
        end
        
    end
    
    if t_Max_y_2 <= 0
        t_Max_y_2 = 100;
    end
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%
    Eigen_Vector_1 = (Stat.Stab(ind_re_max_nu).E_vectors(1:Stat.Space.N,ind_re_max_mi));
    Eigen_Vector_2 = (Stat.Stab(ind_re_max_nu).E_vectors(Stat.Space.N+1:Stat.Space.N*2,ind_re_max_mi));
    tt_2 = proPlot(fftshift(Stat.Space.k)+Stat.Stab(ind_re_max_nu).In.n,...
        10*log10(fftshift(abs(Eigen_Vector_1).^2)),'PlotType','stem','BaseValue',-80,'Marker','none');
    tt_3 = proPlot(fftshift(Stat.Space.k)+Stat.Stab(ind_re_max_nu).In.n,...
        10*log10(fftshift(abs(Eigen_Vector_2).^2)),'PlotType','stem','BaseValue',-80,'Marker','none');
    tt_7 = proPlot(fftshift(Stat.Space.k)+Stat.Stab(ind_re_max_nu).In.n,...
        (fftshift(real(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
    tt_7 = tt_7.addData(fftshift(Stat.Space.k)+Stat.Stab(ind_re_max_nu).In.n,...
        (fftshift(real(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
    tt_8 = proPlot(fftshift(Stat.Space.k)+Stat.Stab(ind_re_max_nu).In.n,...
        (fftshift(real(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
    tt_8 = tt_8.addData(fftshift(Stat.Space.k)+Stat.Stab(ind_re_max_nu).In.n,...
        (fftshift(real(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
    
%%
    lambda_nu_mu = zeros(size(Stat(1).Stab,2),Stat.Space.N*2);
    m_matrix     = zeros(size(Stat(1).Stab,2),Stat.Space.N*2);
    nu_matrix    = zeros(size(Stat(1).Stab,2),Stat.Space.N*2);
    
    for i = 1:size(Stat(1).Stab,2)
        
        lambda_nu_mu(i,:) = Stat(1).Stab(i).E_values/Stat(1).In.kappa;
        m_matrix(i,:)    = Stat(1).Stab(i).mum(1,:)/Stat.In.mu_bl;
        nu_matrix(i,:)    = Stat(1).Stab(i).In.n;
        
    end
    
    for i =round(size(nu_matrix,2)/4):round(3*size(nu_matrix,2)/4)
        
        tt_5 = tt_5.addData(nu_matrix(:,i),real(lambda_nu_mu(:,i)),'Color',[0,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
        
    end
    for i =round(size(nu_matrix,2)/4):round(3*size(nu_matrix,2)/4)
        
        tt_6 = tt_6.addData(nu_matrix(:,i),imag(lambda_nu_mu(:,i)),'Color',[0,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
        
    end
    for i = round(size(nu_matrix,2)/4):round(3*size(nu_matrix,2)/4)
        re_ind = real(lambda_nu_mu(:,i)) > 0;
        tt_5 = tt_5.addData(nu_matrix(re_ind,i),real(lambda_nu_mu(re_ind,i)),'Color',[1,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
        
    end
    for i =round(size(nu_matrix,2)/4):round(3*size(nu_matrix,2)/4)
        
        re_ind = real(lambda_nu_mu(:,i)) > 0;
        tt_6 = tt_6.addData(nu_matrix(re_ind,i),imag(lambda_nu_mu(re_ind,i)),'Color',[1,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
        
    end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%
    tt_1         = tt_1.changeAxisOptions('XLabelText','$Re[\lambda_{m\mu}^{(k)}]/\kappa$',...
                        'YLabelText','$Im[\lambda_{m\mu}^{(k)}]/\kappa$',...  
                        'FontSize',13,'YLim',[-t_Max_y_2,t_Max_y_2]*1.1,...
                        'XLim',[-t_Max_y,t_Max_y]*1.1);


    tt_2         = tt_2.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$10log_{10}$(Eignvec amplt${}^2$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
    tt_3         = tt_3.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$10log_{10}$(Eignvec amplt${}^2$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
    tt_7         = tt_7.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$10log_{10}$(Eignvec amplt${}^2$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
    tt_8         = tt_8.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$10log_{10}$(Eignvec amplt${}^2$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);

    tt_5         = tt_5.changeAxisOptions('XLabelText','k','YLabelText','$Re[\lambda_{m\mu}^{(k)}]/\kappa$',...  
                        'FontSize',13,'XLim',[min(nu_matrix(:,1)),max(nu_matrix(:,1))],'YLim',[-t_Max_y,t_Max_y]*1.5);
    tt_6         = tt_6.changeAxisOptions('XLabelText','k','YLabelText','$Im[\lambda_{m\mu}^{(k)}]/\kappa$',...  
                        'FontSize',13,'XLim',[min(nu_matrix(:,1)),max(nu_matrix(:,1))],'YLim',[-t_Max_y_2,t_Max_y_2]*1.5);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
    if Flag
        
        CF = conFigure([tt_1,tt_5,tt_6,tt_2,tt_3,tt_7,tt_8],2,4, 'UniformPlots', true,...
                                'Height', 14, 'Width', 20,'Labels',false);
                
    end
    
end