function Chi_3_LLE_Assynch_Paralell_exec(CaF,delta_matrix,power_matrix,ii,Path,Sim_zone,N_Mode,Runge)

      if Sim_zone == 1 && ~isfile(strcat(Path,'/Data/',num2str(ii),'.mat'))
          
                CaF.Temp.Met    =                                          [];
                CaF.Temp.In.delta = delta_matrix;
                CaF.Temp.In.P     = power_matrix;
      %          tic  
                CaF.Temp        =    Chi_3_LLE_Normalization(CaF.Temp,N_Mode);        
                CaF             =               Chi_3_LLE_Start_Point_CW(CaF);    
                CaF(1).Temp.Sol =    Chi_3_LLE_Runge_Kuarong_mex(CaF.Temp,N_Mode,Runge);
                mu_Save = CaF.CW.Space.k(CaF.CW.An.Omega_mu(1,:) == 0);
                Chi_3_LLE_Runge_Save_Long_Run(Path,CaF,ii,mu_Save)
          %      toc
         %       ii

      end
end
