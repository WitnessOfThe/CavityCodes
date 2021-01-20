function tt_1 = Plot_LLE_Static_Branch_Soliton_2D(Branch_2D)

    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   
    i_s_m = 1;
    for i = 1:size(Branch_2D,2)
        
        i_s_m = max([ i_s_m ,size( Branch_2D(i).Stat,2)]);
        
    end
%%  
    
    Delta_v_U     = NaN(size(Branch_2D,2),i_s_m);
    Power_v_U     = NaN(size(Branch_2D,2),i_s_m);
    Lambda_v_U    = NaN(size(Branch_2D,2),i_s_m);
    Velocity_v_U  = NaN(size(Branch_2D,2),i_s_m);    
    Power_Max     = NaN(size(Branch_2D,2),i_s_m);   
    Lambda_v_U_IM= NaN(size(Branch_2D,2),i_s_m);   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    for i_p = 1:size(Branch_2D,2)
        for i_d = 1:size(Branch_2D(i_p).Stat,2)
            
           Delta_v_U(i_p,i_d)     = Branch_2D(i_p).Stat(i_d).In.delta/Branch_2D(i_p).Stat(i_d).In.kappa;
           Power_v_U(i_p,i_d)     = Branch_2D(i_p).Stat(i_d).In.P;
           [Lambda_v_U(i_p,i_d),ind]    = max(real(Branch_2D(i_p).Stat(i_d).Stab.E_values));
           Lambda_v_U_IM(i_p,i_d)       = abs(imag(Branch_2D(i_p).Stat(i_d).Stab.E_values(ind)));
           Velocity_v_U(i_p,i_d)  = Branch_2D(i_p).Stat(i_d).Sol.V;
           Power_Max(i_p,i_d)     = max(abs(ifft(Branch_2D(i_p).Stat(i_d).Sol.Psi_k)*Branch_2D(i_p).Stat(i_d).Space.N).^2);
           
        end
    end
    
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%%

%figure;
    tt_1 = proPlot(Delta_v_U,Power_v_U,Lambda_v_U,'PlotType','pcolor');shading flat;

%%
    tt_1 = tt_1.changeAxisOptions('XLabelText','delta',...
                         'YLabelText','Laser Power',...  
                         'FontSize',13);

end
