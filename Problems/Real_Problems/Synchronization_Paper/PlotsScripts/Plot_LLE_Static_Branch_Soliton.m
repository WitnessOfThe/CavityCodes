function [tt_1,tt_2,tt_3,tt_4] = Plot_LLE_Static_Branch_Soliton(CW,Stat_Up,Stat_Dw,Flag,Flag_Point,mu,Stat)

    Bot_thld = -70;
    Psi_k    = zeros(2,Stat_Up(1).Space.N); 
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    

%%  

    Mode_P_U    = zeros(1,size(Stat_Up,2));
    delta_v_U   = zeros(1,size(Stat_Up,2));
    Power_v_U   = zeros(1,size(Stat_Up,2));
    Veloc_v_U   = zeros(1,size(Stat_Up,2));
    lambda_v_U  = zeros(10,size(Stat_Up,2));
    
    Mode_P_D    = zeros(1,size(Stat_Dw,2));
    delta_v_D   = zeros(1,size(Stat_Dw,2)); 
    Power_v_D   = zeros(1,size(Stat_Dw,2));
    Veloc_v_D   = zeros(1,size(Stat_Dw,2));
    lambda_v_D  = zeros(10,size(Stat_Dw,2));
    
    Mode_P_U_z  = zeros(1,size(Stat_Up,2));
    Mode_P_D_z  = zeros(1,size(Stat_Dw,2));
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    for i_d = 1:size(Stat_Up,2)
        
        Mode_P_U_z(i_d)   = abs(Stat_Up(i_d).Sol.Psi_k( Stat_Up(i_d).Space.k == 0 )).^2*Stat_Up(1).In.gamma;    
        Mode_P_U  (i_d)   = abs(Stat_Up(i_d).Sol.Psi_k( Stat_Up(i_d).Space.k == mu )).^2*Stat_Up(1).In.gamma;
        
        delta_v_U(i_d)    = Stat_Up(i_d).Eq.delta;
        Power_v_U(i_d)    = Stat_Up(i_d).In.P;
        lambda_v_U(:,i_d) = Stat_Up(i_d).Stab.E_values(1:10);
        Veloc_v_U(i_d)    = Stat_Up(i_d).Sol.V*Stat_Up(i_d).Eq.norm;
        
        CW.In.delta       = Stat_Up(i_d).In.delta;
        CW.In.P           = Stat_Up(i_d).In.P; 
        CW                = CW.Met.Solve(CW,Stat_Up(i_d).Space.N);     
        U_CW_1(i_d,:)       = CW.Sol.g*CW.Eq.norm/CW.In.kappa;
       
        CW                = Chi_3_LLE_MI_Boundary(CW,Stat_Up(i_d).Space.N);
        
        G_MI_Up_1(i_d,:)        = CW.In.g_MI(1,40:60);
        G_MI_Up_2(i_d,:)        = CW.In.g_MI(2,40:60);

    end
    
    for i_d = 1:size(Stat_Dw,2)

        Mode_P_D_z(i_d)   = abs(Stat_Dw(i_d).Sol.Psi_k( Stat_Dw(i_d).Space.k == 0 )).^2*Stat_Dw(1).In.gamma;    
        Mode_P_D  (i_d)   = abs(Stat_Dw(i_d).Sol.Psi_k( Stat_Dw(i_d).Space.k == mu )).^2*Stat_Dw(1).In.gamma;
        delta_v_D(i_d)    = Stat_Dw(i_d).Eq.delta;
        Power_v_D(i_d)    = Stat_Dw(i_d).In.P;
        lambda_v_D(:,i_d) = Stat_Dw(i_d).Stab.E_values(1:10);        
        Veloc_v_D(i_d)    = Stat_Dw(i_d).Sol.V*Stat_Dw(i_d).Eq.norm;
        
%        mu_D(i_d,:)       = Stat_Dw.Stab.Dres_Spec.lam;
    end
    
    lambda_v_U(lambda_v_U == 0 ) = NaN + 1i*NaN;
    lambda_v_D(lambda_v_D == 0 ) = NaN + 1i*NaN;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    switch Stat_Up(1).Par.variable

        case   'Pump Power'

            X_U = Power_v_U*1E3;
            X_D = Power_v_D*1E3;
                        
            X_Text = 'Pump Power (mW)';

        case   'delta'

            X_U = delta_v_U;
            X_D = delta_v_D;
            X_Text = '$\delta/\kappa$';

    end    
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%

    tt_1         = proPlot([],[],[]);
    
    tt_1         = tt_1.addData(X_U,Mode_P_U_z/Stat.In.kappa,'Color',[1,0,0],'LineStyle','--');
    tt_1         = tt_1.addData(X_D,Mode_P_D_z/Stat.In.kappa,'Color',[0,0,1],'LineStyle','--');
    
    tt_1         = tt_1.addData(X_U,U_CW_1,'Color',[0,1,1],'LineStyle','-');
    
    for i = 1:size(G_MI_Up_1,2)
        
        tt_1         = tt_1.addData(X_U,G_MI_Up_1(:,i)/Stat.In.kappa,'Color',[0,0,0]);
        tt_1         = tt_1.addData(X_U,G_MI_Up_2(:,i)/Stat.In.kappa,'Color',[0,0,0]);
        
    end
    
    tt_1         = tt_1.addData(X_U,Mode_P_U/Stat.In.kappa,'Color',[1,0,0]);
    tt_1         = tt_1.addData(X_D,Mode_P_D/Stat.In.kappa,'Color',[0,0,1]);
    tt_1         = tt_1.addData(Stat.In.delta/Stat.In.kappa*ones(1,2),[min(min([Mode_P_U,Mode_P_D])),max(max([Mode_P_U,Mode_P_D]))]*1.1/Stat.In.kappa,'LineStyle',':','Color','m');
    
                    
    tt_2         = proPlot(     X_D,real(lambda_v_D)/Stat.In.kappa,'Color',[0,0,1],'Marker','.','LineStyle','none');
    tt_2         = tt_2.addData(X_U,real(lambda_v_U)/Stat.In.kappa,'Color',[1,0,0],'Marker','.','LineStyle','none');
    tt_2         = tt_2.addData(Stat.In.delta/Stat.In.kappa*ones(1,2),[min(min([real(lambda_v_D),real(lambda_v_U)])),max(max([real(lambda_v_D),real(lambda_v_U)]))]*1.1/Stat.In.kappa,'LineStyle',':','Color','m');
    
                    
    tt_3         = proPlot(     X_D,imag(lambda_v_D)/Stat.In.kappa,'Color',[0,0,1],'Marker','.','LineStyle','none');
    tt_3         = tt_3.addData(X_U,imag(lambda_v_U)/Stat.In.kappa,'Color',[1,0,0],'Marker','.','LineStyle','none');
    tt_3         = tt_3.addData(Stat.In.delta/Stat.In.kappa*ones(1,2),[min(min([imag(lambda_v_D),imag(lambda_v_U)])),max(max([imag(lambda_v_D),imag(lambda_v_U)]))]*1.1/Stat.In.kappa,'LineStyle',':','Color','m');
    

    tt_4         = proPlot(     X_D,Veloc_v_D/Stat.In.kappa,'Color',[0,0,1]);
    tt_4         = tt_4.addData(X_U,Veloc_v_U/Stat.In.kappa,'Color',[1,0,0]);
    tt_4         = tt_4.addData(Stat.In.delta/Stat.In.kappa*ones(1,2),[min(min([Veloc_v_U/Stat.In.kappa,Veloc_v_D/Stat.In.kappa])),max(max([Veloc_v_U/Stat.In.kappa,Veloc_v_D/Stat.In.kappa]))]*1.1,'LineStyle',':','Color','m');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    tt_1         = tt_1.changeAxisOptions('XLabelText',X_Text,...
                        'YLabelText','g$_{\mu}/\kappa$',...  
                        'FontSize',13,'YLim',[min(min([Mode_P_U,Mode_P_D])),max(max([Mode_P_U,Mode_P_D]))*1.1]/Stat.In.kappa);
                    
    tt_2         = tt_2.changeAxisOptions('XLabelText',X_Text,...
                        'YLabelText','Re[$\lambda/\kappa$]',...  
                        'FontSize',13);
    tt_3         = tt_3.changeAxisOptions('XLabelText',X_Text,...
                        'YLabelText','Im[$\lambda/\kappa$]',...  
                        'FontSize',13);
    tt_4         = tt_4.changeAxisOptions('XLabelText',X_Text,...
                        'YLabelText','Velocity/$\kappa$',...  
                        'FontSize',13);

%%
    if Flag
        
        CF = conFigure([tt_1,tt_2,tt_3,tt_4],1,4, 'UniformPlots', true, 'Height', 7, 'Width', 25,'Labels',false);
        
    end

end
