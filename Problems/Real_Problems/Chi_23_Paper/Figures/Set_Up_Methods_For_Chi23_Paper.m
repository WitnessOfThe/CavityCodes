function Res = Set_Up_Methods_For_Chi23_Paper

    Res.CW.Met.Norm        = @Chi23_CW_Normalization;
    Res.Temp.Met.Norm      = @Chi23_Temp_Normalization;
    Res.Stat.Met.Norm      = @Chi23_Stat_Normalization;
    
%%    
    Res.CW.Met.Newton_Matrix     = @Chi23_CW_Newton_Matrix;
    Res.CW.Met.MI                = @Chi23_MI;
    Res.CW.Met.MI_Matrix         = @Chi2_MI_Matrix;
%    Res.CW.Met.MI_Matrix_Chi2    = @Chi23_MI_Matrix;
    
    Res.CW.Met.Solve_Chi2        = @Chi2_CW;
    Res.CW.Met.Solve             = @Chi23_Solve_CW_Eq;
    Res.CW.Met.Prop_Gen          = @Chi23_CW_Prop_Gen;
    Res.CW.Met.Newton_Fail_Check = @fail_CW_check;
%    Res.CW.Met.Newton_Matrix     = @Chi23_Stat_Newton_Matrix;
    
%     L_L.Stat.Met.Newton_Matrix        = @Chi3_LLE_Bloch_Stat_Newton_Matrix;

%     L_L.CW.Met.MI_Matrix   = @Chi23_MI_Matrix;     % Method which define
%     
%                 % Method which define
%     L_L.Met.T_MI                  = @Chi_3_LLE_MI_Boundary;
%     L_L.Met.T_Syn                 = @Chi_3_LLE_Synch_Boundary;
%     L_L.CW.Met.Mi_Formula         = @Chi_3_LLE_MI_Formula;
%     L_L.CW.Met.Plot.Dressed_State = @Plot_LLE_Dressed_State;
%     
    Res.Stat.Met.Equation             = @Chi23_Full_Dispersion_Equation_RS;
    Res.Stat.Met.Liniar_Decomposition = @Chi23_Full_Dispersion_Liniar_Decomposition_RS;
    Res.Stat.Met.Preconditioner       = @Chi23_Full_Dispersion_Preconditioner_RS;
    Res.Stat.Met.Stab_Matrix          = @Chi23_Linear_Stability;    
    Res.Stat.Met.Stab_Method          = @Chi23_Stability;
    Res.Stat.Met.Prop_Gen             = @Chi23_Stat_Prop_Gen;
    Res.Stat.Met.Newton_Fail_Check    = @fail_Stat_check;
%     L_L.Stat.Met.Ev_Stat_From_Dyn     = @Stat_In_Guess_Chi_3_LLE_From_Dyn;

%                                      
%     L_L.Temp.Met.Ev_Core        = @Chi_3_LLE_Kuar;          
%     L_L.Temp.Met.Ev_Start_Point = @Chi_3_LLE_Start_Point_Stat;
%     L_L.Temp.Met.Ev_Save        = @Chi_3_LLE_Dyn_Saving;    
% 
%     L_L.Temp.Met.Plot.Fields_Spectrums     = @Plot_Dynamics_Result_LinePlots_Spectrums;
%     L_L.Temp.Met.Plot.Carpets              = @Plot_Dynamics_Result_pcolors;
%     L_L.Temp.Met.Plot.Integrative_Dynamics = @Plot_Dynamics_Result_Amplitude_Field_Dynamics;
     
end
    
    function [Flag] = fail_CW_check(Stat,i,x,Exitflag)
       if ~(i>=2)
           
           Logic.r_1 = 0;%sum(abs(Stat(i).Sol.Psi_k(2:end)).^2) <= 1E-10;
       else
           Logic.r_1 = abs(Stat(2).Sol.Omega)<abs(Stat(1).Sol.Omega);%sum(abs(Stat(i).Sol.Psi_k(2:end)).^2) <= 1E-10;
       end
       Logic.r_2  = ~(Stat(end).Par.top_boundary > x) ;            
       Logic.r_3  =  Exitflag <= 0;
       Logic.r_4  = ~(Stat(end).Par.bot_boundary < x);
       Logic.r_5  = 0;
       Logic.r_6  = i == Stat(1).Par.i_max;

        Flag = (Logic.r_1 || Logic.r_2 || Logic.r_3 || Logic.r_4 || Logic.r_5 || Logic.r_6 );%|| Logic.r_7 || Logic.r_8

    end
     function [Flag] = fail_Stat_check(Stat,i,x,Exitflag)
       if ~(i>=2)
           Logic.r_1 = 0;%sum(abs(Stat(i).Sol.Psi_k(2:end)).^2) <= 1E-10;
       else
           Logic.r_1 = sum(abs(Stat(2).Sol.Psi_o(2:end)).^2) <= 1E-10;
       end
       Logic.r_2  = ~(Stat(end).Par.top_boundary > x) ;            
       Logic.r_3  =  Exitflag <= 0;
       Logic.r_4  = ~(Stat(end).Par.bot_boundary < x);
       Logic.r_5  = 0;
       Logic.r_6  = i == Stat(1).Par.i_max;

        Flag = (Logic.r_1 || Logic.r_2 || Logic.r_3 || Logic.r_4 || Logic.r_5 || Logic.r_6 );%|| Logic.r_7 || Logic.r_8

    end
    
