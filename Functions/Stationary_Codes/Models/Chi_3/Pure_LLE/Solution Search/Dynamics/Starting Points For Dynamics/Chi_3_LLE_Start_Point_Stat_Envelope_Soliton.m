function L_L =  Chi_3_LLE_Start_Point_Stat_Envelope_Soliton(L_L)

    L_L.Temp.In.Psi_Start = L_L.Stat.Sol.Psi_k*L_L.Temp.Space.N;
    L_L.Temp.In.t_start      = 0;
    L_L.Temp.In.Psi_Start(10*log10(abs(L_L.Stat.Sol.Psi_k).^2)<= -70) = sqrt(10^(-70/10))*L_L.Temp.Space.N;
    
    [~,ind_mu] = max( L_L.Stat.Sol.Psi_k(2:end/2));
    ind_mu = ind_mu+1;
    mu = L_L.Stat.Space.k(ind_mu);
    Q_mu   = 4*sqrt( (L_L.CW.Eq.delta+real(L_L.CW.Eq.omega_j(ind_mu)))/(0.5*L_L.CW.Eq.gamma_3)).*...
            sech(L_L.CW.Space.phi*sqrt( (L_L.CW.Eq.delta+real(L_L.CW.Eq.omega_j(ind_mu)))/(0.5*2*L_L.CW.Eq.D(2)) ));
    Q      =    fft(Q_mu.*exp(1i*L_L.Temp.Space.phi*mu)+Q_mu.*exp(-1i*L_L.Temp.Space.phi*mu));
    
    L_L.Temp.In.Psi_Start = L_L.Temp.In.Psi_Start + Q;
    L_L.Temp.In.t_start = 0;

end
