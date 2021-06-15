function Save = Chi23_CW_OPO_Lorentian(CW,W,delta)
    
    NN = 5000;
    Save.delta_vector          = linspace(delta(1),delta(2),NN);
    Save.W_vector              = linspace(W(1),W(2),NN);
    

    delta_e = 2*Save.delta_vector  - CW.In.eps;
    Hs      = sqrt(CW.In.eta/pi*CW.In.Finess_e*Save.W_vector);
    
    Save.g       = abs(CW.In.gam2o*CW.In.ke/2.*Hs./(delta_e - 1i*CW.In.ke/2));
 
 % psi_s = -i*1/2*CW.In.ke*Hs/(delta_e - 1i*CW.In.ke/2)   
    
end