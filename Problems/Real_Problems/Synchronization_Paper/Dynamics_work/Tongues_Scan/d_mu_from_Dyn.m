function d_mu_1 = d_mu_from_Dyn(tt,ind_t_1)
        N_t = size(ind_t_1,2);
        dt =  (tt.Save.Temp.Sol.t(ind_t_1(2)) - tt.Save.Temp.Sol.t(ind_t_1(1)))/tt.Save.Temp.Eq.norm;
        
        tau = ( tt.Save.Temp.Sol.t(ind_t_1(end)) - tt.Save.Temp.Sol.t(ind_t_1(1)) )/tt.Save.Temp.Eq.norm;
        f = [0:N_t/2-1,-N_t/2:-1]/tau*2*pi;
        
        Temp_Psi_1 = ifft(tt.Save.Temp.Sol.Psi_mu(ind_t_1,1)).'*N_t*dt/tau;
        Temp_Psi_2 = ifft(tt.Save.Temp.Sol.Psi_mu(ind_t_1,2)).'*N_t*dt/tau;
        
        omega_mu_p = trapz(f.*abs(Temp_Psi_1).^2)./trapz(abs(Temp_Psi_1).^2);
        omega_mu_m = trapz(f.*abs(Temp_Psi_2).^2)./trapz(abs(Temp_Psi_2).^2);
        
        d_mu_1    = (omega_mu_p - omega_mu_m)/70;
end
