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
    Res.Stat.Met.Newton               = @Newton_Manual_bicgstab;
    
    Res.Stat.Met.Equation_Mod             = @Chi23_Full_Dispersion_Equation_RS_delta;
    Res.Stat.Met.Liniar_Decomposition_Mod = @Chi23_Full_Dispersion_Liniar_Decomposition_RS_delta;
    Res.Stat.Met.Preconditioner_Mod       = @Chi23_Full_Dispersion_Preconditioner_RS_delta;
    Res.Stat.Met.Evaluate_trend           = @Peak_Trend;
    
    Res.Stat.Met.Stab_Matrix          = @Chi23_Bloch_Stability_Matrix;    
    Res.Stat.Met.Stab_Method          = @Chi23_Bloch_Stability;
    Res.Stat.Met.Prop_Gen             = @Chi23_Stat_Prop_Gen;
    Res.Stat.Met.Newton_Fail_Check    = @fail_Stat_check;
    Res.Stat.Met.Newton_Turning_Fail_Check   = @fail_Stat_Turning_check;
%     L_L.Stat.Met.Ev_Stat_From_Dyn     = @Stat_In_Guess_Chi_3_LLE_From_Dyn;

%                                      
%     L_L.Temp.Met.Ev_Core        = @Chi_3_LLE_Kuar;          
%     L_L.Temp.Met.Ev_Start_Point = @Chi_3_LLE_Start_Point_Stat;
%     L_L.Temp.Met.Ev_Save        = @Chi_3_LLE_Dyn_Saving;    
% 
%     L_L.Temp.Met.Plot.Fields_Spectrums     = @Plot_Dynamics_Result_LinePlots_Spectrums;
%     L_L.Temp.Met.Plot.Carpets              = @Plot_Dynamics_Result_pcolors;
%     L_L.Temp.Met.Plot.Integrative_Dynamics = @Plot_Dynamics_Result_Amplitude_Field_Dynamics;
%%
    Res.CW.Par.Equation_string  = 'Chi23_CW';
    Res.CW.Met.Equation         = @Chi23_CW;
    Res.CW.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    Res.CW.Met.Newton           = @fsolve;%'fsolve'

    Res.CW.Par.variable         = 'delta_o';  %%'Pump Power';
    Res.CW.Par.first_step       = 0.05; % step for delta measured in delta/kappa
    Res.CW.Par.step_tol         = 0.001;
    Res.CW.Par.step_inc         = 1;
    Res.CW.Par.step_dec         = 0.1;
Res.CW.Par.Turning =1;
    Res.CW.Par.bot_boundary     = -250; % bottom boundary for delta to search
    Res.CW.Par.top_boundary     =  150; % top boundary for delta to search
    Res.CW.Par.Sol_Re_Sign      = '-';
    Res.CW.Par.Stability        = false;
    Res.CW.Par.Newton_iter      = 20;      
    Res.CW.Par.Newton_tol       = 1E-10;  
    Res.CW.Par.i_max            = 3000;
    
    Res.CW.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',false,'SpecifyObjectiveGradient',false,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-25,'OptimalityTolerance',1E-25,'FunctionTolerance',10^(-15));

%%
    Res.Stat.Par              =  Res.CW.Par;
    Res.CW.Par.Change_Space = 0;    
end
    
    function [Flag,Logic] = fail_CW_check(Stat,i,x,Exitflag)
       if ~(i>=2)
           
           Logic.r_1 = 0;%sum(abs(Stat(i).Sol.Psi_k(2:end)).^2) <= 1E-10;
       else
           Logic.r_1 = abs(Stat(2).Sol.Omega) < abs(Stat(1).Sol.Omega);%sum(abs(Stat(i).Sol.Psi_k(2:end)).^2) <= 1E-10;
       end
       Logic.r_2  = ~(Stat(end).Par.top_boundary > x) ;            
       Logic.r_3  =  Exitflag <= 0;
       Logic.r_4  = ~(Stat(end).Par.bot_boundary < x);
       Logic.r_5  = 0;
       Logic.r_6  = i == Stat(1).Par.i_max;

        Flag = (Logic.r_1 || Logic.r_2 || Logic.r_3 || Logic.r_4 || Logic.r_5 || Logic.r_6 );%|| Logic.r_7 || Logic.r_8

    end
     function [FlagReduce,Logic] = fail_Stat_check(Stat,i,x_step)
     
           
           Logic.Dir.d2    = NaN;
           Logic.Dir.d11   = NaN;
           Logic.Dir.d12   = NaN;
           Logic.Smooth    = 0;
           Logic.zero_step = 0;
           Logic.TurnTime  = 0;
           Logic.Resid     =   Stat(end).Sol.eps_f > Stat(end).Par.Newton_tol;
           
           if i >= 2
               
               Logic.Dir.y2 = max(abs(ifft(Stat(2).Sol.Psi_o)*Stat(2).Space.N).^2);
               Logic.Dir.y1 = max(abs(ifft(Stat(1).Sol.Psi_o)*Stat(1).Space.N).^2);
               
               Logic.Dir.x2 = Stat(2).Eq.(Stat(2).Par.variable);
               Logic.Dir.x1 = Stat(1).Eq.(Stat(2).Par.variable);
               
               Logic.Dir.d11 = (Logic.Dir.y2 - Logic.Dir.y1)/(Logic.Dir.x2 - Logic.Dir.x1);
           
               Logic.zero_step   = x_step == 0;
               
               if i >= 3

                   Logic.Dir.y3  = max(abs(ifft(Stat(3).Sol.Psi_o)*Stat(3).Space.N).^2);
                   
                   Logic.Dir.x3  = Stat(3).Eq.(Stat(3).Par.variable);
                   Logic.Dir.d12 = (Logic.Dir.y3 - Logic.Dir.y2)/(Logic.Dir.x3 - Logic.Dir.x2);
                   
                   Logic.Dir.d2     = (Logic.Dir.d12 - Logic.Dir.d11)/(Logic.Dir.x3 - Logic.Dir.x1);
                   
                       
                  if abs(Logic.Dir.d12) < 0.5
                       
                      Logic.Smooth      = 0;
                      
                      if sign(Logic.Dir.d12) ~= sign(Logic.Dir.d11)
                          
                          if abs(abs(Logic.Dir.d12)-abs(Logic.Dir.d11)) > 5E-2
                              
                              Logic.Smooth      = 1;
                              
                          else
                              
                              Logic.Smooth      = 0;
                              
                          end
                          
                      end
                  end
                  if abs(Logic.Dir.d12) >= 0.5
                      
                       Logic.Smooth      = abs(abs(Logic.Dir.d12)-abs(Logic.Dir.d11)) >= 0.2;      
                                              
                  end

                   Logic.TurnTime      = abs(Logic.Dir.d12) > 10 && Logic.Smooth == 0;
%                    
                   if  isnan(Logic.Dir.d12) || Logic.Dir.d12 == 0 
                       
                      Logic.TurnTime    = 1;
                      Logic.Smooth      = 0;
                      
                   end
                   if Stat(1).Par.step_tol > x_step
                      Logic.Smooth      = 0;
                      Logic.TurnTime    = 1;
                   end
               end
    
           end
           
           Logic.Turn = 0;
  
           Logic.rCW         = sum(abs(Stat(end).Sol.Psi_o(2:end)).^2) <= 1E-10;
           Logic.MaxIter     = i > Stat(1).Par.i_max;
           
           FlagReduce        = (Logic.Smooth + Logic.Resid) > 0 ;

     end
    function PsioMax =  Peak_Trend(Stat,sg)
    
        for i = 1:size(Stat,2)            
            
            Peak_Val(i)  = max(abs(ifft(Stat(i).Sol.Psi_o)*Stat(i).Space.N).^2); 
            delta_vec(i) = Stat(i).Eq.delta_o; 
            
        end
        PsioMax  = Peak_Val(end)+sg*(Peak_Val(end) - Peak_Val(end-1));
    end
     function [Flag,Logic] = fail_Stat_Turning_check(Stat,i,Exitflag)
     
           Logic.rCW = sum(abs(Stat(end).Sol.Psi_o(2:end)).^2) <= 1E-6;
           Logic.r_8 =0;
           Logic.r_9 =0;
           Logic.Dir.current  = NaN;
           Logic.Dir.dif = NaN;
           
       if ~(i>=2)
           
           Logic.r_5 = 0;%sum(abs(Stat(i).Sol.Psi_k(2:end)).^2) <= 1E-10;
           Logic.r_7 = 0;%sum(abs(Stat(i).Sol.Psi_k(2:end)).^2) <= 1E-10;
           
       else
           
           Logic.Dir.current = (max( abs( ifft(Stat(2).Sol.Psi_o)*Stat(2).Space.N).^2 ) - ... 
           max( abs( ifft(Stat(1).Sol.Psi_o)*Stat(1).Space.N ).^2 ) )/...
           (Stat(2).Eq.(Stat(2).Par.variable) - Stat(1).Eq.(Stat(1).Par.variable));
           
           Logic.r_5 = sum(abs(Stat(2).Sol.Psi_o(2:end)).^2)/sum(abs(Stat(1).Sol.Psi_o(2:end)).^2) > 1.1 || sum(abs(Stat(2).Sol.Psi_o(2:end)).^2)/sum(abs(Stat(1).Sol.Psi_o(2:end)).^2) < 0.9;
           Logic.r_7 = abs(Stat(2).Sol.Psi_o(1)).^2/abs(Stat(1).Sol.Psi_o(1)).^2 > 1.1 || abs(Stat(2).Sol.Psi_o(1)).^2/abs(Stat(1).Sol.Psi_o(1)).^2 < 0.9;
           
           if i >= 3
               
               Logic.r_5 = 0;%sum(abs(Stat(2).Sol.Psi_o(2:end)).^2)/sum(abs(Stat(1).Sol.Psi_o(2:end)).^2) > 1.1 || sum(abs(Stat(2).Sol.Psi_o(2:end)).^2)/sum(abs(Stat(1).Sol.Psi_o(2:end)).^2) < 0.9;
               Logic.r_7 = 0;%abs(Stat(2).Sol.Psi_o(1)).^2/abs(Stat(1).Sol.Psi_o(1)).^2 > 1.1 || abs(Stat(2).Sol.Psi_o(1)).^2/abs(Stat(1).Sol.Psi_o(1)).^2 < 0.9;               
               Logic.Dir.dif = abs(abs(Stat(1).Logic.Dir.current) - abs(Logic.Dir.current)); 
               Logic.r_8 = 0;
               Logic.r_9 = abs(Logic.Dir.current) < 0.01;
                
           end
           
       end
       
       Logic.r_3  =  Exitflag <= 0;
       Logic.r_6  = i == Stat(1).Par.i_max;
       
 
        Flag = (Logic.rCW || Logic.r_3 || Logic.r_5 || Logic.r_6 || Logic.r_7 || Logic.r_8|| Logic.r_9);%|| Logic.r_7 

    end
