function Chi_3_LLE_Assynch_Paralell_exec(CaF,delta_matrix,power_matrix,ii,Path,Sim_zone,N_Mode,Runge)

      if Sim_zone == 1 && ~isfile(strcat(Path,'/Data/',num2str(ii),'.mat'))
          
                CaF.Temp.In.delta = delta_matrix;
                CaF.Temp.In.P     = power_matrix;
                CaF.Temp          = Chi_3_LLE_Normalization(CaF.Temp,N_Mode);       
                

                CaF.CW.In         = CaF.Temp.In;
                CaF.CW            = CaF.CW.Met.Solve(CaF.CW,CaF.Temp.Space.N);
                CaF.CW.In.g       = CaF.CW.Sol.g(CaF.Temp.Par.CW_num)*CaF.CW.Eq.norm;   
                CaF.CW            = CaF.CW.Met.Mi_Formula(CaF.CW,CaF.Temp.Space.N);   
                
                CaF             =          CaF.Temp.Met.Ev_Start_Point(CaF);  
                
                CaF.Temp.Met    =                                       [];
                
                CaF(1).Temp.Sol =    Chi_3_LLE_Runge_Kuarong_mex(CaF.Temp,N_Mode,Runge);
                
                Chi_3_LLE_Runge_Save_Long_Run(Path,CaF,ii)

      end
      
end
