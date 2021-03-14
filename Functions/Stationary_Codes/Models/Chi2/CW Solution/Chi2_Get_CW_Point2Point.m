function Sa2 = Chi2_Get_CW_Point2Point(CW,delta,NN)
  
    Sa2.delta_vector     = linspace(delta(1),delta(2),NN);
    
    Sa2.U_f_2    =   NaN(NN,3);
    Sa2.U_s_2    =   NaN(NN,3);
    Sa2.Omega    =   NaN(NN,3);
    
    for i = 1:NN
         
        CW.In.delta_o = Sa2.delta_vector(i);
        CW            = CW.Met.Solve_Chi2(CW);
        
        Sa2.U_f_2(i,:)    = CW.Sol.Psi_o;
        Sa2.U_s_2(i,:)    = CW.Sol.Psi_e;  
        Sa2.Omega(i,:)    = CW.Sol.Omega;
        
    end
    
end