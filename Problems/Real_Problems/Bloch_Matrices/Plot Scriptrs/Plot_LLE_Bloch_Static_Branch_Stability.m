function [tt_1,tt_2,tt_3] = Plot_LLE_Bloch_Static_Branch_Stability(CW,Stat,Bran,Flag)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%  
    for i = 1:size(Bran,2)
        
        ind_max(i) = size(Bran(i).Stat,2);
        
    end
    
    G_Mode_P_U    = NaN( size(Bran,2), max(ind_max) );    
    G_Mode_P_0    = NaN( size(Bran,2), max(ind_max) );    
    delta_v_U     = zeros( size(Bran,2), max(ind_max) );
    Re_lambda_v_U     = NaN( 20, max(ind_max) );
    Im_lambda_v_U     = NaN( 80, max(ind_max) );
    Pos_Re_lambda_v_U     = NaN( 40, max(ind_max) );
    Pos_Im_lambda_v_U     = NaN(40, max(ind_max) );
    Re_lambda_nu          = NaN(11, max(ind_max) );
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        i_b = 1;
        index_m = 1:Stat(1).Space.N*2;
        
        for i_d = 1: size(Bran(i_b).Stat,2)
        
            delta_v_U (i_b,i_d) = Bran(i_b).Stat(i_d).Eq.delta;  
            
             for i = 1:size(Stat(1).Stab,2)

                lambda_nu_mu(i,:) = Bran(i_b).Stat(i_d).Stab(i).E_values(index_m)/Stat(1).In.kappa;
                m_matrix(i,:)     = Bran(i_b).Stat(i_d).Stab(i).mum(1,index_m)/Stat.In.mu_bl;
                nu_matrix(i,:)    = Bran(i_b).Stat(i_d).Stab(i).In.n;

                [Max_y,ind_m]        = maxk(real(Stat(1).Stab(i).E_values(index_m))/Stat(1).In.kappa,2);
                Re_Max_nu_m(i,:)     = Max_y;
                ind_Re_max_nu_m(i,:) = ind_m;

                [Max_y,ind_m]        = max(imag(Stat(1).Stab(i).E_values(index_m))/Stat(1).In.kappa);
                Im_Max_nu_m(i,:)     = Max_y;
                ind_Im_max_nu_m(i,:) = ind_m;

             end
             tem_lam = unique(lambda_nu_mu);
             tem_lam(isnan(tem_lam)) = [];
             tt_pos_lam = tem_lam;
             tt_pos_lam(real(tem_lam)<=0) =[];
             
             tt_imag = unique(imag(tem_lam));
             tt_rel  = unique(real(tem_lam));
             
             [~,Ind_real]    =  sort(real(tt_rel),'descend');
             [~,Ind_imag]    =  sort(abs(tt_imag),'ascend');
             Re_lambda_v_U(1:20,i_d)   = tt_rel(Ind_real(1:20)); 
             Im_lambda_v_U(1:80,i_d)   = tt_imag(Ind_imag(1:80)); 
             
             Pos_Re_lambda_v_U(1:size(unique(real(tt_pos_lam)),1),i_d)   = unique(real(tt_pos_lam)); 
             Pos_Im_lambda_v_U(1:size(unique(imag(tt_pos_lam)),1),i_d)   = unique(imag(tt_pos_lam)); 
%             Re_lambda_nu(:,i_d)  = max(real(lambda_nu_mu),[],2);   
%             [Re_lambda_m(:,i_d),ind_m]   = max(real(lambda_nu_mu),[],1);   
 %            [m_Re(:,i_d),ind_sort]      = sort(m_matrix(ind_m),'descend');
  %           Re_lambda_m(:,i_d)         = Re_lambda_m(ind_sort,i_d);
        end
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    
    
    switch Stat.Par.variable

        case   'Pump Power'

%            X_U = Power_v_U*1E3;
                        
 %           X_Text = 'Pump Power (mW)';

        case   'delta'

            X_U = delta_v_U;
            X_Text = '$\delta/\kappa$';

    end    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%

    tt_1         = proPlot([],[],[]);
    tt_2         = proPlot([],[],[]);
    tt_3         = proPlot([],[],[]);
    
    
    for i = 1:size(Re_lambda_v_U,1)
        tt_1 = tt_1.addData(delta_v_U,Re_lambda_v_U(i,:),'Marker','.','LineStyle','none','Color',[0,0,1]);
    end
    for i = 1:size(Im_lambda_v_U,1)
        tt_2 = tt_2.addData(delta_v_U,Im_lambda_v_U(i,:),'Marker','.','LineStyle','none','Color',[0,0,1]);
    end
    for i = 1:size(Pos_Re_lambda_v_U,1)
        tt_1 = tt_1.addData(delta_v_U,Pos_Re_lambda_v_U(i,:),'Marker','.','LineStyle','none','Color',[1,0,0]);
        tt_2 = tt_2.addData(delta_v_U,Pos_Im_lambda_v_U(i,:),'Marker','.','LineStyle','none','Color',[1,0,0]);
    end
    Point_Detla =    Stat.In.delta*ones(1,10)/Stat.In.kappa; 
    Height_Re   =   linspace(min(min(Re_lambda_v_U)),max(max(Re_lambda_v_U)),10); 
    Height_Im   =   linspace(min(min(Im_lambda_v_U)),max(max(Im_lambda_v_U)),10); 
    
        tt_1 = tt_1.addData(Point_Detla,Height_Re,'Marker','.','LineStyle','-','Color','m');
        tt_2 = tt_2.addData(Point_Detla,Height_Im,'Marker','.','LineStyle','-','Color','m');
        tt_3 = tt_3.addData(delta_v_U,nu_matrix(:,1),real(Re_lambda_nu),'PlotType','surf');
%        tt_4 = tt_4.addData(delta_v_U,mu_matrix_pcolor(:,1),real(Re_lambda_nu),'PlotType','pcolor');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    tt_1         = tt_1.changeAxisOptions('XLabelText',X_Text,...
                        'YLabelText','Re[$\lambda^(k)_{m\mu}$]',...  
                        'FontSize',13);
                    
    tt_2         = tt_2.changeAxisOptions('XLabelText',X_Text,...
                        'YLabelText','Im[$\lambda^(k)_{m\mu}$]',...  
                        'FontSize',13);
   tt_3         = tt_3.changeAxisOptions('XLabelText',X_Text,...
                       'YLabelText','$\nu$',...  
                       'FontSize',13);

%%
    if Flag
        
        CF = conFigure([tt_1,tt_2,tt_3],1,3, 'UniformPlots', true, 'Height',15, 'Width', 25,'Labels',false);
       % ,tt_2,tt_3
    end

end
