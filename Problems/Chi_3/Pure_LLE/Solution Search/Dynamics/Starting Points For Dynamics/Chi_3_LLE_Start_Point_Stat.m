function L_L =  Chi_3_LLE_Start_Point_Stat(L_L,i)

    L_L.Temp.In           = L_L.Stat(i).In;
    L_L.Temp              = L_L.CW.Met.Norm(L_L.Temp,L_L.Stat(i).Space.N);    

    
    
    L_L.Temp.In.Psi_Start = L_L.Temp.Space.N*L_L.Stat(i).Sol.Psi_k;
    L_L.Temp.In.t_start   = 0;
    
end
