function L_L = Set_Up_Methods_For_Bloch_Matrices

    L_L.Met.Norm           = @Chi_3_LLE_Normalization_Bloch; % Method which Apply
    L_L.CW.Met.Norm        = @Chi_3_LLE_Normalization; % Method which Apply
    L_L.Temp.Met.Norm      = @Chi_3_LLE_Normalization_Bloch; % Method which Apply
    L_L.Stat.Met.Norm      = @Chi_3_LLE_Normalization_Bloch; % Method which Apply
    
    L_L.CW.Met.MI_Matrix   = @Chi_3_LLE_MI_Matrix;     % Method which define
    % MI matrix to solve
    
    L_L.CW.Met.Solve              = @Chi_3_LLE_CW;            % Method which define
    L_L.Met.T_MI                  = @Chi_3_LLE_MI_Boundary;
    L_L.Met.T_Syn                 = @Chi_3_LLE_Synch_Boundary;
    L_L.CW.Met.Mi_Formula         = @Chi_3_LLE_MI_Formula;
    L_L.CW.Met.Plot.Dressed_State = @Plot_LLE_Dressed_State;
    
    L_L.Stat.Met.Equation              = @LLE_Full_Dispersion_Equation;
    L_L.Stat.Met.Liniar_Decomposition  = @LLE_Full_Dispersion_Liniar_Decomposition;
    L_L.Stat.Met.Preconditioner        = @LLE_Full_Dispersion_Predonditioner;
%     L_L.Stat.Met.Equation              = @LLE_Zero_Velocity_Equation;
%     L_L.Stat.Met.Liniar_Decomposition  = @LLE_Zero_Vel_Liniar_Decomposition;
%     L_L.Stat.Met.Preconditioner        = @LLE_Zero_Velocity_Predonditioner;
    L_L.Stat.Met.Newton_Matrix         = @Chi3_LLE_Bloch_Stat_Newton_Matrix;
    
    L_L.Stat.Met.Prop_Gen              = @Chi3_LLE_Stat_Prop_Gen;
    L_L.Stat.Met.Ev_Stat_From_Dyn      = @Stat_In_Guess_Chi_3_LLE_From_Dyn;
    L_L.Stat.Met.Stab_Method           = @LLE_Bloch_Full_Stability;  
    L_L.Stat.Met.Stab_Matrix           = @LLE_Bloch_Full_Stability_Matrix;    
    L_L.Stat.Met.Sol_In_point          = @Chi3_LLE_Bloch_Stat_In_Guess_From_CW_Defined;    
    L_L.Stat.Met.Branch_Starting_points = @Chi3_LLE_Stat_Turing_Starting_Points_CaF_2E3;    
    
    L_L.Temp.Met.Ev_Core              = @Chi_3_LLE_Kuar;          
    L_L.Temp.Met.Ev_Start_Point       = @Chi_3_LLE_Start_Point_CW;
    L_L.Temp.Met.Ev_Save              = @Chi_3_LLE_Dyn_Saving;    
    

%    L_L.Temp.Met.Plot.Fields_Spectrums     = @Plot_Dynamics_Result_LinePlots_Spectrums;
%    L_L.Temp.Met.Plot.Carpets              = @Plot_Dynamics_Result_pcolors;
%    L_L.Temp.Met.Plot.Integrative_Dynamics = @Plot_Dynamics_Result_Amplitude_Field_Dynamics;
    
end

    
    
    
