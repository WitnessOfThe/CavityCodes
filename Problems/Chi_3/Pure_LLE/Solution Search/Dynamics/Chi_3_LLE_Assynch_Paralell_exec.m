function Chi_3_LLE_Assynch_Paralell_exec(Res,delta_matrix,power_matrix,ii,Path,Sim_zone,N_Mode,Runge,CaF_1D_Upper,CaF_1D_Lower,mu)

      if Sim_zone == 1 && ~isfile(strcat(Path,'/Data/',num2str(ii),'.mat'))
          
                Res.Temp.In.delta = delta_matrix;
                Res.Temp.In.P     = power_matrix;
                Res.Temp          = Chi_3_LLE_Normalization(Res.Temp,N_Mode);       
                

                Res.CW.In         = Res.Temp.In;
                Res.CW            = Res.CW.Met.Solve(Res.CW,Res.Temp.Space.N);
                Res.CW.In.g       = Res.CW.Sol.g(Res.Temp.Par.CW_num)*Res.CW.Eq.norm;   
                Res.CW            = Res.CW.Met.Mi_Formula(Res.CW,Res.Temp.Space.N);   
                
                Res             =          Res.Temp.Met.Ev_Start_Point(Res);  
                
                Res.Temp.Met    =                                       [];
                
                Res(1).Temp.Sol =    Chi_3_LLE_Runge_Kuarong_mex(Res.Temp,N_Mode,Runge);
                
                Chi_3_LLE_Runge_Save_Long_Run_from_Stat(Path,Res,ii,CaF_1D_Upper,CaF_1D_Lower,mu)

      end
      
end
