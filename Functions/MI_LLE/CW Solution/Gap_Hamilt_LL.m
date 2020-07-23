function L_L = Gap_Hamilt_LL(L_L,Space)

phi = acos(-L_L.Eq.h/2*sqrt(27/L_L.Eq.delta^3));
g   = 2*sqrt(L_L.Eq.delta/3)*cos( (phi-2*pi)/3 );

L_L.Gap.V_m = sqrt(L_L.Eq.d./4./Space.k.*(Space.k.^2 + 1/pi/L_L.Eq.d.*(L_L.Eq.delta - 3*g^2)).*(Space.k.^2 + 1/pi/L_L.Eq.d.*(L_L.Eq.delta - g^2)) );

end

