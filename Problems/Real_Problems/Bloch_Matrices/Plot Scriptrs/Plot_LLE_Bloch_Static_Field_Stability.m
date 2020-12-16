function [tt_1,tt_2] = Plot_LLE_Bloch_Static_Field_Stability(Stat,ax)
    
    tt_1 = proPlot([],[],[]);
    tt_2 = proPlot([],[],[]);
    tt_3 = proPlot([],[],[]);
   
    
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
    
     [lambda,ind_un_lambda]       = unique(lambda_nu_mu);
     ind_un_lambda(isnan(lambda)) = [];
     lambda(isnan(lambda))        = [];
     nu_array                     = nu_matrix(ind_un_lambda);
     
    [Re_max,ind_max] = max((real(lambda)));
    Im_max           = abs(imag(lambda(ind_max)));
    if Re_max <= 0
        Re_max = 3;
    end
    Im_max = 50;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        
 %%   
     [max_re,ind_max] = maxk(real(lambda),2);

    for i = 1:size(Stat.Stab,2)
        
%        tt_1 = tt_1.addData(real(lambda),...
 %           imag(lambda),'LineStyle','none',...
  %          'Marker','.','MarkerSize',15,'Color',[0,0,0]);
            plot(real(lambda),imag(lambda),'LineStyle','none',...
            'Marker','.','MarkerSize',15,'Color',[0,0,0],'Parent',ax(1));
        
        if sum(real(lambda)>0) > 0
%             tt_1 = tt_1.addData(real(lambda(real(lambda)>0)),...
%                 imag(lambda(real(lambda)>0)),'LineStyle','none',...
%                 'Marker','.','MarkerSize',15,'Color',[1,0,0]);
%             tt_1 = tt_1.addData(real(lambda(ind_max)),...
%                 imag(lambda(ind_max)),'LineStyle','none',...
%                 'Marker','.','MarkerSize',15,'Color',[0,1,0]);
            plot(real(lambda(real(lambda)>0)),...
                imag(lambda(real(lambda)>0)),'LineStyle','none',...
                'Marker','.','MarkerSize',15,'Color',[1,0,0],'Parent',ax(1));
            plot(real(lambda(ind_max)),...
                imag(lambda(ind_max)),'LineStyle','none',...
                'Marker','.','MarkerSize',15,'Color',[0,1,0],'Parent',ax(1));
        end
        
    end
    NN =    size(Stat.Stab,2);
    for i = 1:size(Stat.Stab,2)
        Ampl_max= max([10*log10(abs(Stat.Stab(i).E_vectors(1:Stat.Space.N,1)).^2);10*log10(abs(Stat.Stab(i).E_vectors(Stat.Space.N+1:2*Stat.Space.N,1)).^2)]);
        
        stem(Stat.Space.k,10*log10(abs(Stat.Stab(i).E_vectors(1:Stat.Space.N,1)).^2),'Parent',ax(3+i),'BaseValue',Ampl_max-50,'Marker','none');
        stem(Stat.Space.k,10*log10(abs(Stat.Stab(i).E_vectors(Stat.Space.N+1:2*Stat.Space.N,1)).^2),'Parent',ax(3+i+NN),'BaseValue',Ampl_max-50,'Marker','none');
        [~,ind_k_max]= max(abs(Stat.Space.k(10*log10(abs(Stat.Stab(i).E_vectors(1:Stat.Space.N,1)).^2)> Ampl_max-50)));
        if size(ind_k_max,2) == 0
            ind_k_max= 1;
        end
        ax(3+i).YLim = [Ampl_max-50,Ampl_max+1];
        ax(3+i).XLim = [-abs(Stat.Space.k(ind_k_max))-2,abs(Stat.Space.k(ind_k_max))+2];
        
        ax(3+i+NN).YLim = [Ampl_max-50,Ampl_max+1];
        ax(3+i+NN).XLim = [-abs(Stat.Space.k(ind_k_max))-2,abs(Stat.Space.k(ind_k_max))+2];
        
        plot(Stat.Space.phi,abs(ifft(Stat.Stab(i).E_vectors(1:Stat.Space.N,1))),'Parent',ax(3+i+2*NN));
        plot(Stat.Space.phi,real(ifft(Stat.Stab(i).E_vectors(1:Stat.Space.N,1))),'Parent',ax(3+i+2*NN));
        plot(Stat.Space.phi,real(ifft(Stat.Stab(i).E_vectors(Stat.Space.N+1:2*Stat.Space.N,1))),'Parent',ax(3+i+2*NN));       
        
        plot(Stat.Space.phi,abs(ifft(Stat.Stab(i).E_vectors(1:Stat.Space.N,1))),'Parent',ax(3+i+3*NN));
        plot(Stat.Space.phi,imag(ifft(Stat.Stab(i).E_vectors(1:Stat.Space.N,1))),'Parent',ax(3+i+3*NN));
        plot(Stat.Space.phi,imag(ifft(Stat.Stab(i).E_vectors(Stat.Space.N+1:2*Stat.Space.N,1))),'Parent',ax(3+i+3*NN));
         text(0,Ampl_max-25,strcat('X,k=',num2str(Stat.Stab(i).In.n)),'FontSize',13,'Parent',ax(3+i),'Interpreter','latex');
         text(0,Ampl_max-25,strcat('Y,k=',num2str(Stat.Stab(i).In.n)),'FontSize',13,'Parent',ax(3+i+NN),'Interpreter','latex');
         
         text(0,0,strcat('X,k=',num2str(Stat.Stab(i).In.n)),'FontSize',13,'Parent',ax(3+i+2*NN),'Interpreter','latex');
         text(0,0,strcat('Y,k=',num2str(Stat.Stab(i).In.n)),'FontSize',13,'Parent',ax(3+i+3*NN),'Interpreter','latex');
        
         ax(3+i).XLabel.String = 'Mode Number';
         ax(3+i).YLabel.String = 'Rel Power db';
         ax(3+i).YLabel.Interpreter = 'latex';
         ax(3+i).FontSize             = 13;
         ax(3+i).XLabel.Interpreter   = 'latex';
         ax(3+i).TickLabelInterpreter = 'latex';
         ax(3+i).Box =                    'on';
         ax(3+i+NN).XLabel.String = 'Mode Number';
         ax(3+i+NN).YLabel.String = 'Rel Power db';
         ax(3+i+NN).YLabel.Interpreter = 'latex';
         ax(3+i+NN).FontSize             = 13;
         ax(3+i+NN).XLabel.Interpreter   = 'latex';
         ax(3+i+NN).TickLabelInterpreter = 'latex';
         ax(3+i+NN).Box =                    'on';
         
         ax(3+i+2*NN).XLabel.String = '$\theta$';
         ax(3+i+2*NN).YLabel.String = 'Abs,Re,Im[$\psi$]';
         ax(3+i+2*NN).YLabel.Interpreter = 'latex';
         ax(3+i+2*NN).FontSize             = 13;
         ax(3+i+2*NN).XLabel.Interpreter   = 'latex';
         ax(3+i+2*NN).TickLabelInterpreter = 'latex';
         ax(3+i+2*NN).Box =                    'on';
         
         ax(3+i+3*NN).XLabel.String = '$\theta$';
         ax(3+i+3*NN).YLabel.String = 'Abs,Re,Im[$\psi$]';
         ax(3+i+3*NN).YLabel.Interpreter = 'latex';
         ax(3+i+3*NN).FontSize             = 13;
         ax(3+i+3*NN).XLabel.Interpreter   = 'latex';
         ax(3+i+3*NN).TickLabelInterpreter = 'latex';
         ax(3+i+3*NN).Box =                    'on';
    end
    
%%
     %   tt_2 = tt_2.addData(nu_array,real(lambda),'Color',[0,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
     plot(nu_array,real(lambda),'Color',[0,0,0],'LineStyle','none','Marker','.','MarkerSize',15,'Parent',ax(2));
     plot(nu_array,imag(lambda),'Color',[0,0,0],'LineStyle','none','Marker','.','MarkerSize',15,'Parent',ax(3));
       
%        tt_3 = tt_3.addData(nu_array,imag(lambda),'Color',[0,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
        
        if sum(real(lambda)>0) > 0

   %         tt_2 = tt_2.addData(nu_array(real(lambda)>0),real(lambda(real(lambda)>0)),'Color',[1,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
   %         tt_2 = tt_2.addData(nu_array(ind_max),real(lambda(ind_max)),'Color',[0,1,0],'LineStyle','none','Marker','.','MarkerSize',15);
   %         tt_3 = tt_3.addData(nu_array(real(lambda)>0),imag(lambda(real(lambda)>0)),'Color',[1,0,0],'LineStyle','none','Marker','.','MarkerSize',15);
   %         tt_3 = tt_3.addData(nu_array(ind_max),imag(lambda(ind_max)),'Color',[0,1,0],'LineStyle','none','Marker','.','MarkerSize',15);
            
            plot(nu_array(real(lambda)>0),real(lambda(real(lambda)>0)),'Color',[1,0,0],'LineStyle','none','Marker','.','MarkerSize',15,'Parent',ax(2));
            plot(nu_array(ind_max),real(lambda(ind_max)),'Color',[0,1,0],'LineStyle','none','Marker','.','MarkerSize',15,'Parent',ax(2));
            plot(nu_array(real(lambda)>0),imag(lambda(real(lambda)>0)),'Color',[1,0,0],'LineStyle','none','Marker','.','MarkerSize',15,'Parent',ax(3));
            plot(nu_array(ind_max),imag(lambda(ind_max)),'Color',[0,1,0],'LineStyle','none','Marker','.','MarkerSize',15,'Parent',ax(3));

            
        end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
% %%
%     if Re_max > 0 
%         [~,ind_re_nu] = maxk(Re_Max_nu_m(:,1),2); 
%         
%         Eigen_Vector_1 = Stat.Stab( ind_re_nu(1) ).E_vectors(1:Stat.Space.N,ind_Re_max_nu_m(ind_re_nu(1),1));
%         Eigen_Vector_2 = Stat.Stab( ind_re_nu(1)).E_vectors(Stat.Space.N+1:Stat.Space.N*2,ind_Re_max_nu_m(ind_re_nu(1),1));
% 
%         tt_4 = tt_4.addData(fftshift(Stat.Space.k),...
%             10*log10(fftshift(abs(Eigen_Vector_1).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
%         tt_4 = tt_4.addData(fftshift(Stat.Space.k),...
%             10*log10(fftshift(abs(Eigen_Vector_2).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
%         tt_5 = tt_5.addData(fftshift(Stat.Space.k),...
%             (fftshift(real(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_5 = tt_5.addData(fftshift(Stat.Space.k),...
%             (fftshift(real(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_6 = tt_6.addData(fftshift(Stat.Space.k),...
%             (fftshift(imag(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_6 = tt_6.addData(fftshift(Stat.Space.k),...
%             (fftshift(imag(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
% 
%         Eigen_Vector_1 = Stat.Stab( ind_re_nu(2) ).E_vectors(1:Stat.Space.N,ind_Re_max_nu_m(ind_re_nu(2),1));
%         Eigen_Vector_2 = Stat.Stab( ind_re_nu(2)).E_vectors(Stat.Space.N+1:Stat.Space.N*2,ind_Re_max_nu_m(ind_re_nu(2),1));
% 
%         tt_7 = tt_7.addData(fftshift(Stat.Space.k),...
%             10*log10(fftshift(abs(Eigen_Vector_1).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
%         tt_7 = tt_7.addData(fftshift(Stat.Space.k),...
%             10*log10(fftshift(abs(Eigen_Vector_2).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
%         tt_8 = tt_8.addData(fftshift(Stat.Space.k),...
%             (fftshift(real(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_8 = tt_8.addData(fftshift(Stat.Space.k),...
%             (fftshift(real(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_9 = tt_9.addData(fftshift(Stat.Space.k),...
%             (fftshift(imag(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_9 = tt_9.addData(fftshift(Stat.Space.k),...
%             (fftshift(imag(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none'); 
%         
%         Eigen_Vector_1 = Stat.Stab( ind_re_nu(1) ).E_vectors(1:Stat.Space.N,ind_Re_max_nu_m(ind_re_nu(1),2));
%         Eigen_Vector_2 = Stat.Stab( ind_re_nu(1)).E_vectors(Stat.Space.N+1:Stat.Space.N*2,ind_Re_max_nu_m(ind_re_nu(1),2));
% 
%         tt_10 = tt_10.addData(fftshift(Stat.Space.k),...
%             10*log10(fftshift(abs(Eigen_Vector_1).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
%         tt_10 = tt_10.addData(fftshift(Stat.Space.k),...
%             10*log10(fftshift(abs(Eigen_Vector_2).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
%         tt_11 = tt_11.addData(fftshift(Stat.Space.k),...
%             (fftshift(real(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_11 = tt_11.addData(fftshift(Stat.Space.k),...
%             (fftshift(real(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_12 = tt_12.addData(fftshift(Stat.Space.k),...
%             (fftshift(imag(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_12 = tt_12.addData(fftshift(Stat.Space.k),...
%             (fftshift(imag(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
% 
%         Eigen_Vector_1 = Stat.Stab( ind_re_nu(2) ).E_vectors(1:Stat.Space.N,ind_Re_max_nu_m(ind_re_nu(2),2));
%         Eigen_Vector_2 = Stat.Stab( ind_re_nu(2)).E_vectors(Stat.Space.N+1:Stat.Space.N*2,ind_Re_max_nu_m(ind_re_nu(2),2));
% 
%         tt_13 = tt_13.addData(fftshift(Stat.Space.k),...
%             10*log10(fftshift(abs(Eigen_Vector_1).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
%         tt_13 = tt_13.addData(fftshift(Stat.Space.k),...
%             10*log10(fftshift(abs(Eigen_Vector_2).^2)),'PlotType','stem','BaseValue',-200,'Marker','none');
%         tt_14 = tt_14.addData(fftshift(Stat.Space.k),...
%             (fftshift(real(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_14 = tt_14.addData(fftshift(Stat.Space.k),...
%             (fftshift(real(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_15 = tt_15.addData(fftshift(Stat.Space.k),...
%             (fftshift(imag(Eigen_Vector_1))),'PlotType','stem','BaseValue',0,'Marker','none');
%         tt_15 = tt_15.addData(fftshift(Stat.Space.k),...
%             (fftshift(imag(Eigen_Vector_2))),'PlotType','stem','BaseValue',0,'Marker','none');   
%         
%     end
    
%%
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%
    tt_1         = tt_1.changeAxisOptions('XLabelText','$Re[\lambda_{m\mu}^{(k)}]/\kappa$',...
                        'YLabelText','$Im[\lambda_{m\mu}^{(k)}]/\kappa$',...  
                        'FontSize',13,'YLim',[-Im_max,Im_max]*1.1,...
                        'XLim',[-Re_max,Re_max]*1.1);
    tt_2         = tt_2.changeAxisOptions('XLabelText','k','YLabelText','$Re[\lambda_{m\mu}^{(k)}]/\kappa$',...  
                        'FontSize',13,'XLim',[min(nu_matrix(:,1)),max(nu_matrix(:,1))],'YLim',[-Re_max,Re_max ]*1.5);
    tt_3         = tt_3.changeAxisOptions('XLabelText','k','YLabelText','$Im[\lambda_{m\mu}^{(k)}]/\kappa$',...  
                        'FontSize',13,'XLim',[min(nu_matrix(:,1)),max(nu_matrix(:,1))],'YLim',[-Im_max,Im_max]*1.5);
        k_lim =[min(nu_matrix(:,1)),max(nu_matrix(:,1))];
         if max(nu_matrix(:,1)) == 0
             k_lim = [-1,1];
         end
         ax(1).XLabel.String = '$Re[\lambda_{m\mu}^{(k)}]/\kappa$';
         ax(1).YLabel.String = '$Im[\lambda_{m\mu}^{(k)}]/\kappa$';
         ax(1).YLabel.Interpreter = 'latex';
         ax(1).XLim        = [-Re_max,Re_max]*1.1;
         ax(1).YLim        = [-Im_max,Im_max]*1.1;
         ax(1).FontSize             = 13;
         ax(1).XLabel.Interpreter   = 'latex';
         ax(1).TickLabelInterpreter = 'latex';
         ax(1).Box =                    'on';

         ax(2).XLabel.String = 'k';
         ax(2).YLabel.String = '$Re[\lambda_{m\mu}^{(k)}]/\kappa$';
         ax(2).YLabel.Interpreter = 'latex';
         ax(2).XLim        = k_lim;
         ax(2).YLim        = [-Re_max,Re_max ]*1.5;
         ax(2).FontSize             = 13;
         ax(2).XLabel.Interpreter   = 'latex';
         ax(2).TickLabelInterpreter = 'latex';
         ax(2).Box =                    'on';

         ax(3).XLabel.String = 'k';
         ax(3).YLabel.String = '$Im[\lambda_{m\mu}^{(k)}]/\kappa$';
         ax(3).YLabel.Interpreter = 'latex';
         ax(3).XLim        = k_lim;
         ax(3).YLim        = [-Im_max,Im_max]*1.5;
         ax(3).FontSize             = 13;
         ax(3).XLabel.Interpreter   = 'latex';
         ax(3).TickLabelInterpreter = 'latex';
         ax(3).Box =                    'on';
         
%     tt_4         = tt_4.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$10*log10(abs(x^{(k+)}_{\mu_1 m})$',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
%     tt_5         = tt_5.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$Re(x^{(k+)}_{\mu_1 m})$)',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
%     tt_6         = tt_6.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$Im(x^{(k+)}_{\mu_1 m})$)',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
%                     
%     tt_7         = tt_7.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$10*log10(abs(x^{(k-)}_{\mu m_2})$',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
%     tt_8         = tt_8.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$Re(x^{(k-)}_{\mu m_2})$)',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
%     tt_9         = tt_9.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$Im(x^{(k-)}_{\mu m_2})$)',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
% 
%                     
%     tt_10         = tt_10.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$10*log10(abs(x^{(k+)}_{\mu m_1})$',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
%     tt_11         = tt_11.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$Re(x^{(k+)}_{\mu m_1})$)',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
%     tt_12         = tt_12.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$Im(x^{(k+)}_{\mu m_1})$)',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
% 
%                     
%     tt_13         = tt_13.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$10*log10(abs(x^{(k-)}_{\mu m_2})$',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
%     tt_14         = tt_14.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$Re(x^{(k-)}_{\mu m_2})$)',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
%     tt_15         = tt_15.changeAxisOptions('XLabelText','$m\mu+n$',...
%                         'YLabelText','$Im(x^{(k-)}_{\mu m_2})$)',...  
%                         'FontSize',13,...
%                         'XLim',[-4*Stat.In.mu_bl,4*Stat.In.mu_bl]*1.1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %%
%     if Flag
%         figure;
%         CF = conFigure([tt_1,tt_2,tt_3],1,3, 'UniformPlots', true,...
%                                 'Height', 10, 'Width', 30,'Labels',false);
%        %         ,tt_4,tt_5,tt_6,tt_7,tt_8,tt_9,tt_10,tt_11,tt_12,tt_13,tt_14,tt_15
%     end
%     
end