function [tt_1,tt_2,tt_3] = Plot_LLE_Bloch_Static_Branch(CW,Stat_Up,Stat_Dw,Flag,Flag_Point,mu,Stat)

    Bot_thld = -70;
    Psi_k    = zeros(2,Stat_Up(1).Space.N); 
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    

%%  

    Mode_P_U    = zeros(1,size(Stat_Up,2));
    delta_v_U   = zeros(1,size(Stat_Up,2));
    Power_v_U   = zeros(1,size(Stat_Up,2));
    lambda_v_U  = zeros(10,size(Stat_Up,2));
    
    Mode_P_D    = zeros(1,size(Stat_Dw,2));
    delta_v_D   = zeros(1,size(Stat_Dw,2)); 
    Power_v_D   = zeros(1,size(Stat_Dw,2));
    lambda_v_D  = zeros(10,size(Stat_Dw,2));
    
    Mode_P_U_z  = zeros(1,size(Stat_Up,2));
    Mode_P_D_z  = zeros(1,size(Stat_Dw,2));
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    for i_d = 1:size(Stat_Up,2)
        
        Mode_P_U_z(i_d)   = abs(Stat_Up(i_d).Sol.Psi_k( Stat_Up(i_d).Space.k == 0 )).^2*Stat_Up(1).In.gamma;    
        Mode_P_U  (i_d)   = abs(Stat_Up(i_d).Sol.Psi_k( Stat_Up(i_d).Space.k == mu )).^2*Stat_Up(1).In.gamma;
        
        delta_v_U(i_d)    = Stat_Up(i_d).Eq.delta;
        Power_v_U(i_d)    = Stat_Up(i_d).In.P;
        
        CW.In.delta       = Stat_Up(i_d).In.delta;
        CW.In.P           = Stat_Up(i_d).In.P; 
        CW                = CW.Met.Solve(CW,2^8);     
        U_CW_1(i_d,:)       = CW.Sol.g*CW.Eq.norm/CW.In.kappa;
       
        CW                = Chi_3_LLE_MI_Boundary(CW,2^8);
        
        G_MI_Up_1(i_d,:)        = CW.In.g_MI(1,mu+1);
        G_MI_Up_2(i_d,:)        = CW.In.g_MI(2,mu+1);

        W_MI_Up_1(i_d,:)        = CW.In.W_MI_Tongue(1,mu+1);
        W_MI_Up_2(i_d,:)        = CW.In.W_MI_Tongue(2,mu+1);
        
        for i = 1:size(Stat.Stab,2)
            
            Lambda_vec(1+(i-1)*Stat.Space.N*2:(i)*Stat.Space.N*2) = Stat_Up(i_d).Stab(i).E_values;
            
        end
         [~,re_max_ind]  = maxk(real(Lambda_vec),10);
         lambda_v_U(:,i_d) = Lambda_vec(re_max_ind);
    end
    
    for i_d = 1:size(Stat_Dw,2)

        Mode_P_D_z(i_d)   = abs(Stat_Dw(i_d).Sol.Psi_k( Stat_Dw(i_d).Space.k == 0 )).^2*Stat_Dw(1).In.gamma;    
        Mode_P_D  (i_d)   = abs(Stat_Dw(i_d).Sol.Psi_k( Stat_Dw(i_d).Space.k == mu )).^2*Stat_Dw(1).In.gamma;
        delta_v_D(i_d)    = Stat_Dw(i_d).Eq.delta;
        Power_v_D(i_d)    = Stat_Dw(i_d).In.P;
        for i = 1:size(Stat.Stab,2)
            
            Lambda_vec(1+(i-1)*Stat.Space.N*2:(i)*Stat.Space.N*2) = Stat_Dw(i_d).Stab(i).E_values;
            
        end
         [~,re_max_ind]  = maxk(real(Lambda_vec),10);
         lambda_v_D(:,i_d) = Lambda_vec(re_max_ind);        
    end
    
    
   lambda_v_U(lambda_v_U == 0 ) = NaN + 1i*NaN;
   lambda_v_D(lambda_v_D == 0 ) = NaN + 1i*NaN;
   lambda_v_U(real(lambda_v_U)<=0)= real(lambda_v_U(real(lambda_v_U)<=0));
   lambda_v_D(real(lambda_v_D)<=0)= real(lambda_v_D(real(lambda_v_D)<=0));
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

%%
    if Flag
        
        CF = conFigure([tt_1,tt_2,tt_3],1,3, 'UniformPlots', true, 'Height', 7, 'Width', 15,'Labels',false);
       % ,tt_2,tt_3
    end

end
