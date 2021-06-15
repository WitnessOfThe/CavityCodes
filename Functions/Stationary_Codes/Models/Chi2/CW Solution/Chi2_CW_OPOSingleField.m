function CW = Chi2_CW_OPOSingleField(CW)
    
    CW = CW.Met.Norm(CW);
%    Hs = CW.In.eta/pi*CW.In.Finess_e*CW.In.W;
    
    CW.Sol.Psi_o = 0;
    CW.Sol.Psi_e = -1i*1/2*CW.In.ke*CW.In.H_s/(CW.In.delta_e - 1i*CW.In.ke/2);
    CW.Sol.g     =  abs(CW.In.gam2o/2*CW.In.ke.*CW.In.H_s./(CW.In.delta_e - 1i*CW.In.ke/2)); 
    
end