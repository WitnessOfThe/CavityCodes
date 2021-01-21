function Temp = Chi_3_LLE_Start_mu_Envelope_Soliton(CW,Temp,mu)
    ind_mu = find(CW.Space.k == mu);
    Q_mu   = 10*sqrt( (CW.Eq.delta+real(CW.Eq.omega_j(ind_mu)))/(0.5*CW.Eq.gamma_3)).*...
            sech(CW.Space.phi*sqrt( (CW.Eq.delta+real(CW.Eq.omega_j(ind_mu)))/(0.5*2*CW.Eq.D(2)) ));
    Q      =    fft(CW.Sol.Psi(Temp.Par.CW_num) + Q_mu.*exp(1i*Temp.Space.phi*mu)+Q_mu.*exp(-1i*Temp.Space.phi*mu) );
        %
    Temp.In.Psi_Start = Q;
    Temp.In.t_start = 0;
    
end