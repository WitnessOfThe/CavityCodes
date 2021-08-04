function Res = Set_Up_Methods_For_Bloch_Matrices

    Res.Met.Norm           = @Chi_3_LLE_Normalization_Bloch; % Method which Apply
    Res.CW.Met.Norm        = @Chi_3_LLE_Normalization; % Method which Apply
    Res.Temp.Met.Norm      = @Chi_3_LLE_Normalization_Bloch; % Method which Apply
    Res.Stat.Met.Norm      = @Chi_3_LLE_Normalization_BlochStat; % Method which Apply
    
    Res.CW.Met.MI_Matrix   = @Chi_3_LLE_MI_Matrix;     % Method which define
    % MI matrix to solve
    
    Res.CW.Met.Solve              = @Chi_3_LLE_CW;            % Method which define
    Res.CW.Met.T_MI                  = @Chi_3_LLE_MI_Boundary;
    Res.CW.Met.T_Syn                 = @Chi_3_LLE_Synch_Boundary;
    Res.CW.Met.Mi_Formula            = @Chi_3_LLE_MI_Formula;
    Res.CW.Met.Plot.Dressed_State = @Plot_LLE_Dressed_State;
    
   Res.Stat.Met.Equation              = @LLE_Full_Dispersion_Equation;
   Res.Stat.Met.Liniar_Decomposition  = @LLE_Full_Dispersion_Liniar_Decomposition;
   Res.Stat.Met.Preconditioner        = @LLE_Full_Dispersion_Predonditioner;
% 
    Res.Stat.Met.Equation              = @LLE_Zero_Velocity_Equation;
    Res.Stat.Met.Liniar_Decomposition  = @LLE_Zero_Vel_Liniar_Decomposition;
    Res.Stat.Met.Preconditioner        = @LLE_Zero_Velocity_Predonditioner;

    Res.Stat.Met.Equation_Mod             = @LLE_Zero_Velocity_Equation_Turndelta;
    Res.Stat.Met.Liniar_Decomposition_Mod = @LLE_Zero_Vel_Liniar_Decomposition_TurnDelta;
    Res.Stat.Met.Preconditioner_Mod       = @LLE_Zero_Velocity_Predonditioner_TurnDelta;
    
    Res.Stat.Met.Newton_Matrix         = @Chi3_LLE_Bloch_Stat_Newton_Matrix;
    Res.Stat.Met.Newton                 = @Newton_Manual_bicgstab;
    Res.Stat.Met.Prop_Gen              = @Chi3_LLE_Stat_Prop_Gen;
    Res.Stat.Met.Ev_Stat_From_Dyn      = @Stat_In_Guess_Chi_3_LLE_From_Dyn;
    Res.Stat.Met.Stab_Method           = @LLE_Bloch_Full_Stability;  
    Res.Stat.Met.Stab_Matrix           = @LLE_Bloch_Full_Stability_Matrix;    
    Res.Stat.Met.Sol_In_point          = @Chi3_LLE_Bloch_Stat_In_Guess_From_CW_Defined;    
    Res.Stat.Met.Branch_Starting_points = @Chi3_LLE_Stat_Turing_Starting_Points_CaF_2E3;    
    
    Res.Temp.Met.Ev_Core              = @Chi_3_LLE_Kuar;          
    Res.Temp.Met.Ev_Start_Point       = @Chi3_LLE_Start_Point_Bloch;
    Res.Temp.Met.Ev_Save              = @Chi_3_LLE_Dyn_Saving;   
    Res.Stat.Met.Newton_Fail_Check    = @fail_Stat_check;
        
end
 
   function [FlagReduce,FlagStop,Logic] = fail_Stat_check(Stat,i,x_step)
     
           
           Logic.Dir.d2    = NaN;
           Logic.Dir.d11   = NaN;
           Logic.Dir.d12   = NaN;
           
           Logic.Smooth    = 0;
           Logic.zero_step = 0;
           Logic.TurnTime  = 0;
           Logic.Stop      = 0;
           Logic.Resid     =   Stat(end).Sol.eps_f > Stat(end).Par.Newton_tol;
           
           if i >= 2
               
               Logic.Dir.y2 = real(Stat(2).Sol.Psi_k(1));
               Logic.Dir.y1 = real(Stat(1).Sol.Psi_k(1));
               
               Logic.Dir.x2 = Stat(2).Eq.(Stat(2).Par.variable);
               Logic.Dir.x1 = Stat(1).Eq.(Stat(2).Par.variable);
               
               Logic.Dir.d11 = (Logic.Dir.y2 - Logic.Dir.y1)/(Logic.Dir.x2 - Logic.Dir.x1)/Logic.Dir.y1 ;
           
               Logic.zero_step   = x_step == 0;
               
               if i >= 3

                   Logic.Dir.y3  = real(Stat(3).Sol.Psi_k(1));

                   
                   Logic.Dir.x3  = Stat(3).Eq.(Stat(3).Par.variable);
                   Logic.Dir.d12 = (Logic.Dir.y3 - Logic.Dir.y2)/(Logic.Dir.x3 - Logic.Dir.x2)/Logic.Dir.y1 ;                   
                   Logic.Dir.d2  = (Logic.Dir.d12 - Logic.Dir.d11)/(Logic.Dir.x3 - Logic.Dir.x1);
                   
                       
                   if  sign(Logic.Dir.d12) == sign(Logic.Dir.d11) 
                       if Logic.Dir.d11 <=1
                          Logic.Smooth      = abs(abs(Logic.Dir.d12)-abs(Logic.Dir.d11)) >= 0.3;
                       end
                       if Logic.Dir.d11 > 1
                           if abs(Logic.Dir.d12) >= abs(Logic.Dir.d11)
                                Logic.Smooth      = abs(Logic.Dir.d12)/abs(Logic.Dir.d11) >= 1.3;
                           else
                                Logic.Smooth      = abs(Logic.Dir.d11)/abs(Logic.Dir.d12) >= 1.3;
                           end
                       end
                       
                   end
                   
                   if  sign(Logic.Dir.d12) ~= sign(Logic.Dir.d11)
                      
                       Logic.Smooth      = abs(abs(Logic.Dir.d12)-abs(Logic.Dir.d11)) >= 0.1;
                                              
                   end

                   Logic.TurnTime      = abs(Logic.Dir.d12) > 15 && Logic.Smooth == 0;
                   
                   if Logic.Dir.d12 == 0
                       Logic.TurnTime     = 1;
                   end
                   if isnan(Logic.Dir.d12)
                       Logic.TurnTime     = 1;
                   end
                   if isinf(Logic.Dir.d12)
                       Logic.TurnTime     = 1;
                   end
               end
           end
             
           Logic.rCW         = sum(abs(Stat(end).Sol.Psi_k(2:end)).^2) <= 1E-10;
           Logic.MaxIter     = i > Stat(1).Par.i_max;           
           FlagReduce        = (Logic.Smooth + Logic.Resid+ Logic.rCW) > 0 ;
           FlagStop          = Logic.MaxIter  + Logic.Stop;
     end
    
    
    
