function [tt_1,tt_2,tt_3] = Plot_LLE_Bloch_Static_Branch_Stability(CW,Stat,Bran,ax_1)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%  
    for i = 1:size(Bran,2)
        
        ind_max(i) = size(Bran(i).Stat,2);
        
    end
    
    G_Mode_P_U            = NaN( size(Bran,2), max(ind_max) );    
    G_Mode_P_0            = NaN( size(Bran,2), max(ind_max) );    
    delta_v_U             = zeros( size(Bran,2), max(ind_max) );
    Re_lambda_v_U         = NaN(100, max(ind_max) );
    Im_lambda_v_U         = NaN(100, max(ind_max) );
    Pos_Re_lambda_v_U     = NaN(100, max(ind_max) );
    Pos_Im_lambda_v_U     = NaN(100, max(ind_max) );
    Re_lambda_nu          = NaN(1, max(ind_max) );
    nu_re_max             = NaN(1, max(ind_max) );
    Im_max_lambda_v_U     = NaN(1, max(ind_max) );
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        i_b = 1;
        index_m = 1:Stat(1).Space.N*2;
            Max_Re = -1;
        
        for i_d = 1: size(Bran(i_b).Stat,2)
        
            delta_v_U (i_b,i_d) = Bran(i_b).Stat(i_d).Eq.delta;  
             for i = 1:size(Stat(1).Stab,2)

                lambda_nu_mu(i,:) = Bran(i_b).Stat(i_d).Stab(i).E_values(index_m)/Stat(1).In.kappa;
                m_matrix    (i,:) = Bran(i_b).Stat(i_d).Stab(i).mum(1,index_m)/Stat.In.mu_bl;
                
                temp_lambda                   = lambda_nu_mu(i,~isnan(lambda_nu_mu(i,:))); 
                [lambda_nu(i,i_d).Re,i1,i2]   = uniquetol(real(temp_lambda ));
                
                lambda_nu(i,i_d).m_Re         = m_matrix(i,i1);
                
                lambda_nu(i,i_d).Im         = NaN(length(lambda_nu(i,i_d).Re),10);
                Un_Re_lam                   = unique(i2);
                
                lambda_nu(i,i_d).Im_pos_Re   = NaN(1);
                lambda_nu(i,i_d).Im_pos_max  = NaN(1);
                
                Un_Re_lam_pos               = real(temp_lambda) > 0;
                Max_Im_pos_Re               = 5;
                
                if sum(real(temp_lambda) > 0) > 0
                                        
                        lambda_nu(i,i_d).Im_pos_Re  = uniquetol(imag(temp_lambda(Un_Re_lam_pos)));                          
                        [~,ind_max]                 = max(lambda_nu(i,i_d).Re(Un_Re_lam ));                
                        lambda_nu(i,i_d).Im_pos_max = uniquetol(imag(temp_lambda(1,i2 == Un_Re_lam(ind_max))));
                        Max_Im_pos_Re = max(max(Max_Im_pos_Re,lambda_nu(i,i_d).Im_pos_Re));
    
                end
                
                for i_im = 1:length(lambda_nu(i,i_d).Re)                        
                    
                    Im_temp              = uniquetol(imag(temp_lambda(1,i2 == Un_Re_lam(i_im))));
                    [~,Ind_temp]         = sort(abs(Im_temp),'ascend');
                    SRE                  = length(Im_temp);
                    
                    if  SRE > 10
                        
                        SRE = 10;
                        
                    end
                    
                    lambda_nu(i,i_d).Im(i_im,1:SRE)  = Im_temp(Ind_temp(1:SRE));
                    
                end

%               lambda_nu(i,i_d).Im         = imag(lambda_nu_mu(i,i2));
                lambda_nu(i,i_d).k          = Stat(1).Stab(i).In.n;
                
             end
                Max_Re = min(Max_Re,min(min(real(lambda_nu_mu(:,:)) )));
                          
        end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    

            X_U = delta_v_U;
            X_Text = '$\delta/\kappa$';

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%
    
    
    for i_k = 1:size(lambda_nu,1)

        ax = ax_1(i_k);
        hold(ax,'on');
        for i_d = 1:size(Bran(i_b).Stat,2)

%            tt_1(i_k) = tt_1(i_k).addData(delta_v_U(i_d),lambda_nu(i_k,i_d).Re,'Marker','.','LineStyle','none','Color',[0,0,1]);
            plot(delta_v_U(i_d),lambda_nu(i_k,i_d).Re,'Marker','.','LineStyle','none','Color',[0,0,1],'Parent',ax);
            if max(lambda_nu(i_k,i_d).Re) > 0
                plot(delta_v_U(i_d),max(lambda_nu(i_k,i_d).Re),'Marker','.','LineStyle','none','Color',[0,1,0],'Parent',ax);
            end        
        end

        Write_1 = strcat('k=',num2str(lambda_nu(i_k,i_d).k));
 %       tt_1(i_k) =  tt_1(i_k).addData([min(delta_v_U),0,0,0], [], []...
  %      , 'PlotType', 'Annotation', 'AnnotationType', 'textbox',...
    %    'String', Write_1,'FontSize',18);
         text(min(delta_v_U),0, Write_1,'FontSize',18,'Parent',ax,'Interpreter','latex');
%         ax('XLabelText',X_Text,...
%                             'YLabelText','Re[$\lambda^(k)_{m\mu}$]',...  
%                             'FontSize',13,'XLim',[min(delta_v_U),max(delta_v_U)]);
         ax.XLabel.String = X_Text;
         ax.YLabel.String = 'Re[$\lambda_{m\mu}^{(k)}$]';
         ax.YLabel.Interpreter = 'latex';
         ax.XLim        = [min(delta_v_U),max(delta_v_U)];
         ax.YLim        = [-abs( Max_Re)*1.1,abs( Max_Re)*1.1];
         ax.FontSize             = 13;
         ax.XLabel.Interpreter   = 'latex';
         ax.TickLabelInterpreter = 'latex';
%         ax.YLabel.FontSize        = 13;
        ax.Box =                    'on';
        plot(Stat.Eq.delta*ones(1,2),linspace(-abs( Max_Re)*1.1,abs( Max_Re)*1.1,2),'LineStyle','-','Marker','.','Color','m','Parent',ax);

    end
    for i_k = 1:size(lambda_nu,1)
        ax = ax_1(i_k+size(lambda_nu,1));
        hold(ax,'on');

        for i_d = 1:size(Bran(i_b).Stat,2)
            
            Im = reshape(lambda_nu(i_k,i_d).Im,1,[]);
            Im(isnan(Im)) = [];
            Max_Im        = reshape(lambda_nu(i_k,i_d).Im_pos_max,1,[]);
%            plot(delta_v_U(i_d),Im,'Marker','.','LineStyle','none','Color',[0,0,1],'Parent',ax);
 %           plot(delta_v_U(i_d),lambda_nu(i_k,i_d).Im_pos_Re,'Marker','.','LineStyle','none','Color',[1,0,0],'Parent',ax);
  %          plot(delta_v_U(i_d),Max_Im,'Marker','.','LineStyle','none','Color',[0,1,0],'Parent',ax);
            
%            tt_2(i_k) = tt_2(i_k).addData(delta_v_U(i_d),Im,'Marker','.','LineStyle','none','Color',[0,0,1]);
%            tt_2(i_k) = tt_2(i_k).addData(delta_v_U(i_d),lambda_nu(i_k,i_d).Im_pos_Re,'Marker','.','LineStyle','none','Color',[1,0,0]);
%            tt_2(i_k) = tt_2(i_k).addData(delta_v_U(i_d),Max_Im,'Marker','.','LineStyle','none','Color',[0,1,0]);
            
        end 
        
        Write_1 = strcat('k=',num2str(lambda_nu(i_k,i_d).k));
        text(min(delta_v_U),0, Write_1,'FontSize',18,'Parent',ax,'Interpreter','latex');
         ax.XLabel.String = X_Text;
         ax.YLabel.String = 'Im[$\lambda_{m\mu}^{(k)}$]';
         ax.YLabel.Interpreter = 'latex';
         ax.XLim        = [min(delta_v_U),max(delta_v_U)];
         ax.YLim        = [-abs(Max_Im_pos_Re),abs(Max_Im_pos_Re)]*1.1;
         ax.FontSize             = 13;
         ax.XLabel.Interpreter   = 'latex';
         ax.TickLabelInterpreter = 'latex';
        ax.Box =                    'on';
        plot(Stat.Eq.delta*ones(1,2),linspace(-abs(Max_Im_pos_Re)*1.1,abs(Max_Im_pos_Re)*1.1,2),'LineStyle','-','Marker','.','Color','m','Parent',ax);

%        ax.('XLabelText',X_Text,...
 %                           'YLabelText','Im[$\lambda^(k)_{m\mu}$]',...  
 %                           'FontSize',13,'XLim',[min(delta_v_U),max(delta_v_U)]);
%        tt_2(i_k) =  tt_2(i_k).addData([min(delta_v_U),0,0,0], [], []...
%           , 'PlotType', 'Annotation', 'AnnotationType',...
%           'textbox','String', Write_1,'FontSize',18);
        
    end
    
  
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
%     for i_k = 1:size(lambda_nu,1)
%         
%         tt_1(i_k)         = tt_1(i_k).changeAxisOptions('XLabelText',X_Text,...
%                             'YLabelText','Re[$\lambda^(k)_{m\mu}$]',...  
%                             'FontSize',13,'XLim',[min(delta_v_U),max(delta_v_U)]);
% 
%         tt_2(i_k)         = tt_2(i_k).changeAxisOptions('XLabelText',X_Text,...
%                             'YLabelText','Im[$\lambda^(k)_{m\mu}$]',...  
%                             'FontSize',13,'XLim',[min(delta_v_U),max(delta_v_U)]);%'YLim',1.3*[-max(max(abs(Im_max_lambda_v_U)))-1,max(max(abs(Im_max_lambda_v_U)))+1]
%     end         
%    tt_3         = tt_3.changeAxisOptions('XLabelText',X_Text,...
%                       'YLabelText','$\nu$',...  
%                      'FontSize',13);

%%


end
