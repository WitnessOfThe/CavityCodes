function [tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,tt_7,tt_8,tt_9,tt_10,tt_12,tt_13,tt_14,tt_15] = Plot_LLE_Bloch_Static_Field_Stability(Stat,Flag)
    
    tt_1 = proPlot([],[],[]);
    tt_2 = proPlot([],[],[]);
    tt_3 = proPlot([],[],[]);
    
    tt_4 = proPlot([],[],[]);
    tt_5 = proPlot([],[],[]);
    tt_6 = proPlot([],[],[]);
    
    
    tt_7 = proPlot([],[],[]);
    tt_8 = proPlot([],[],[]);
    tt_9 = proPlot([],[],[]);
    
    tt_10 = proPlot([],[],[]);
    tt_11 = proPlot([],[],[]);
    tt_12 = proPlot([],[],[]);
    
    tt_13 = proPlot([],[],[]);
    tt_14 = proPlot([],[],[]);
    tt_15 = proPlot([],[],[]);
%%    
    lambda_nu_mu = zeros(size(Stat(1).Stab,2),Stat.Space.N*2);
    m_matrix     = zeros(size(Stat(1).Stab,2),Stat.Space.N*2);
    nu_matrix    = zeros(size(Stat(1).Stab,2),Stat.Space.N*2);
    
    for i = 1:size(Stat(1).Stab,2)
        
        lambda_nu_mu(i,:) = Stat(1).Stab(i).E_values/Stat(1).In.kappa;
        m_matrix(i,:)     = Stat(1).Stab(i).mum(1,:)/Stat.In.mu_bl;
        nu_matrix(i,:)    = Stat(1).Stab(i).In.n;
        
        [Max_y,ind_m]        = maxk(real(Stat(1).Stab(i).E_values)/Stat(1).In.kappa,2);
        Re_Max_nu_m(i,:)     = Max_y;
        ind_Re_max_nu_m(i,:) = ind_m;
        
        [Max_y,ind_m]        = maxk(imag(Stat(1).Stab(i).E_values)/Stat(1).In.kappa,2);
        Im_Max_nu_m(i,:)     = Max_y;
        ind_Im_max_nu_m(i,:) = ind_m;
        
    end
    
    Re_max = max(max( Re_Max_nu_m ));
    Im_max = max(max( Im_Max_nu_m ));
    
    if Re_max <= 0
        Re_max = 3;
    end
    if Im_max <= 0
        Im_max = 5;
    end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        
 %%   
 
    for i = 1:size(Stat.Stab,2)
        
        tt_1 = tt_1.addData(real(Stat.Stab(i).E_values)/Stat.In.kappa,...
            imag(Stat.Stab(i).E_values)/Stat.In.kappa,'LineStyle','none',...
            'Marker','.','MarkerSize',15,'Color',[0,0,0]);
        
    end
    
%%


    for i =round(size(nu_matrix,2)/4):round(3*size(nu_matrix,2)/4)
        
        tt_2 = tt_2.addData(nu_matrix(:,i),real(lambda_nu_mu(:,i)),'Color',[0,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
        
    end
    for i =round(size(nu_matrix,2)/4):round(3*size(nu_matrix,2)/4)
        
        tt_3 = tt_3.addData(nu_matrix(:,i),imag(lambda_nu_mu(:,i)),'Color',[0,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
        
    end
    for i = round(size(nu_matrix,2)/4):round(3*size(nu_matrix,2)/4)
        re_ind = real(lambda_nu_mu(:,i)) > 0;
        tt_2 = tt_2.addData(nu_matrix(re_ind,i),real(lambda_nu_mu(re_ind,i)),'Color',[1,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
        
    end
    for i =round(size(nu_matrix,2)/4):round(3*size(nu_matrix,2)/4)
        
        re_ind = real(lambda_nu_mu(:,i)) > 0;
        tt_3 = tt_3.addData(nu_matrix(re_ind,i),imag(lambda_nu_mu(re_ind,i)),'Color',[1,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
        
    end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%
    if Re_max > 0 
        [~,ind_re_nu] = maxk(Re_Max_nu_m(:,1),2); 
        
        Eigen_Vector_1 = Stat.Stab( ind_re_nu(1) ).E_vectors(1:Stat.Space.N,ind_Re_max_nu_m(ind_re_nu(1),1));
        Eigen_Vector_2 = Stat.Stab( ind_re_nu(1)).E_vectors(Stat.Space.N+1:Stat.Space.N*2,ind_Re_max_nu_m(ind_re_nu(1),1));

        tt_4 = tt_4.addData(fftshift(Stat.Space.k),...
            10*log10(fftshift(abs(Eigen_Vector_1).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
        tt_4 = tt_4.addData(fftshift(Stat.Space.k),...
            10*log10(fftshift(abs(Eigen_Vector_2).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
        tt_5 = tt_5.addData(fftshift(Stat.Space.k),...
            (fftshift(real(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_5 = tt_5.addData(fftshift(Stat.Space.k),...
            (fftshift(real(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_6 = tt_6.addData(fftshift(Stat.Space.k),...
            (fftshift(imag(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_6 = tt_6.addData(fftshift(Stat.Space.k),...
            (fftshift(imag(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');

        Eigen_Vector_1 = Stat.Stab( ind_re_nu(2) ).E_vectors(1:Stat.Space.N,ind_Re_max_nu_m(ind_re_nu(2),1));
        Eigen_Vector_2 = Stat.Stab( ind_re_nu(2)).E_vectors(Stat.Space.N+1:Stat.Space.N*2,ind_Re_max_nu_m(ind_re_nu(2),1));

        tt_7 = tt_7.addData(fftshift(Stat.Space.k),...
            10*log10(fftshift(abs(Eigen_Vector_1).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
        tt_7 = tt_7.addData(fftshift(Stat.Space.k),...
            10*log10(fftshift(abs(Eigen_Vector_2).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
        tt_8 = tt_8.addData(fftshift(Stat.Space.k),...
            (fftshift(real(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_8 = tt_8.addData(fftshift(Stat.Space.k),...
            (fftshift(real(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_9 = tt_9.addData(fftshift(Stat.Space.k),...
            (fftshift(imag(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_9 = tt_9.addData(fftshift(Stat.Space.k),...
            (fftshift(imag(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none'); 
        
        Eigen_Vector_1 = Stat.Stab( ind_re_nu(1) ).E_vectors(1:Stat.Space.N,ind_Re_max_nu_m(ind_re_nu(1),2));
        Eigen_Vector_2 = Stat.Stab( ind_re_nu(1)).E_vectors(Stat.Space.N+1:Stat.Space.N*2,ind_Re_max_nu_m(ind_re_nu(1),2));

        tt_10 = tt_10.addData(fftshift(Stat.Space.k),...
            10*log10(fftshift(abs(Eigen_Vector_1).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
        tt_10 = tt_10.addData(fftshift(Stat.Space.k),...
            10*log10(fftshift(abs(Eigen_Vector_2).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
        tt_11 = tt_11.addData(fftshift(Stat.Space.k),...
            (fftshift(real(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_11 = tt_11.addData(fftshift(Stat.Space.k),...
            (fftshift(real(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_12 = tt_12.addData(fftshift(Stat.Space.k),...
            (fftshift(imag(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_12 = tt_12.addData(fftshift(Stat.Space.k),...
            (fftshift(imag(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');

        Eigen_Vector_1 = Stat.Stab( ind_re_nu(2) ).E_vectors(1:Stat.Space.N,ind_Re_max_nu_m(ind_re_nu(2),2));
        Eigen_Vector_2 = Stat.Stab( ind_re_nu(2)).E_vectors(Stat.Space.N+1:Stat.Space.N*2,ind_Re_max_nu_m(ind_re_nu(2),2));

        tt_13 = tt_13.addData(fftshift(Stat.Space.k),...
            10*log10(fftshift(abs(Eigen_Vector_1).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
        tt_13 = tt_13.addData(fftshift(Stat.Space.k),...
            10*log10(fftshift(abs(Eigen_Vector_2).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
        tt_14 = tt_14.addData(fftshift(Stat.Space.k),...
            (fftshift(real(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_14 = tt_14.addData(fftshift(Stat.Space.k),...
            (fftshift(real(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_15 = tt_15.addData(fftshift(Stat.Space.k),...
            (fftshift(imag(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
        tt_15 = tt_15.addData(fftshift(Stat.Space.k),...
            (fftshift(imag(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');   
        
    end
    
%%
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%
    tt_1         = tt_1.changeAxisOptions('XLabelText','$Re[\lambda_{m\mu}^{(k)}]/\kappa$',...
                        'YLabelText','$Im[\lambda_{m\mu}^{(k)}]/\kappa$',...  
                        'FontSize',13,'YLim',[-500,500]*1.1,...
                        'XLim',[-Re_max,Re_max]*1.1);
    tt_3         = tt_3.changeAxisOptions('XLabelText','k','YLabelText','$Im[\lambda_{m\mu}^{(k)}]/\kappa$',...  
                        'FontSize',13,'XLim',[min(nu_matrix(:,1)),max(nu_matrix(:,1))],'YLim',[-500,500]*1.5);
    tt_2         = tt_2.changeAxisOptions('XLabelText','k','YLabelText','$Re[\lambda_{m\mu}^{(k)}]/\kappa$',...  
                        'FontSize',13,'XLim',[min(nu_matrix(:,1)),max(nu_matrix(:,1))],'YLim',[-Re_max,Re_max ]*1.5);


    tt_4         = tt_4.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$10*log10(abs(x^{(k+)}_{\mu_1 m})$',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
    tt_5         = tt_5.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$Re(x^{(k+)}_{\mu_1 m})$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
    tt_6         = tt_6.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$Im(x^{(k+)}_{\mu_1 m})$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
                    
    tt_7         = tt_7.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$10*log10(abs(x^{(k-)}_{\mu m_2})$',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
    tt_8         = tt_8.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$Re(x^{(k-)}_{\mu m_2})$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
    tt_9         = tt_9.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$Im(x^{(k-)}_{\mu m_2})$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);

                    
    tt_10         = tt_10.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$10*log10(abs(x^{(k+)}_{\mu m_1})$',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
    tt_11         = tt_11.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$Re(x^{(k+)}_{\mu m_1})$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
    tt_12         = tt_12.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$Im(x^{(k+)}_{\mu m_1})$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);

                    
    tt_13         = tt_13.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$10*log10(abs(x^{(k-)}_{\mu m_2})$',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
    tt_14         = tt_14.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$Re(x^{(k-)}_{\mu m_2})$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
    tt_15         = tt_15.changeAxisOptions('XLabelText','$m\mu+n$',...
                        'YLabelText','$Im(x^{(k-)}_{\mu m_2})$)',...  
                        'FontSize',13,...
                        'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
    if Flag
        
        CF = conFigure([tt_1,tt_2,tt_3,tt_4,tt_5,tt_6,tt_7,tt_8,tt_9,tt_10,tt_11,tt_12,tt_13,tt_14,tt_15],4,4, 'UniformPlots', true,...
                                'Height', 20, 'Width', 30,'Labels',false);
                
    end
    
end