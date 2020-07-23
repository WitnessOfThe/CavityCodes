function L_L =  V_Cr(L_L)
     psi = acos(L_L.Eq.h/2*sqrt( 27*L_L.Eq.gamma_3/L_L.Eq.delta^3));
     g = 2*sqrt( L_L.Eq.delta/L_L.Eq.gamma_3/3 )*cos( (psi-2*pi)/3  );
     L_L.Eq.V_cr = 1/2*sqrt(L_L.Eq.D2/pi)*(sqrt(L_L.Eq.delta-3*g^2*L_L.Eq.gamma_3) + sqrt(L_L.Eq.delta-g^2*L_L.Eq.gamma_3) );
end