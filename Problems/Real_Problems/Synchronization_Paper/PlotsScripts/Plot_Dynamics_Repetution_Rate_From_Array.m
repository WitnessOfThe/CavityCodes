function Plot_Dynamics_Repetution_Rate_From_Array(SiN,k_probe,ind_t)
%%
        for i=1:size(k_probe,2)
        
            ind(i) = find(SiN(1).Temp.Space.k == k_probe(i));
        
        end
        
        N_t = size(ind_t,2);
   %%
        tau = (SiN(1).Temp.Sol.t(ind_t(end)) - SiN(1).Temp.Sol.t(ind_t(1)));
        f = [0:N_t/2-1,-N_t/2:-1]/tau;
    
        for j =1:size(SiN,2)

                psi_hat_plus     = ifft(SiN(j).Temp.Sol.Psi(ind_t,ind(1)))' ;         
                psi_hat_minus    = ifft(SiN(j).Temp.Sol.Psi(ind_t,ind(2)))' ;         
                d_t_phi_plus     = trapz(f.*abs(psi_hat_plus).^2)./trapz(abs(psi_hat_plus).^2);
                d_t_phi_minus     = trapz(f.*abs(psi_hat_minus).^2)./trapz(abs(psi_hat_minus).^2);
                d_mu(j)  = (d_t_phi_plus-d_t_phi_minus)/(tau*(k_probe(1)-k_probe(2)) )*SiN(1).Temp.Eq.norm/1E3;
                delta_vector(j)  = SiN(j).Temp.In.delta/2/pi/1E9;
                
        end        
%%
t_pl = proPlot(delta_vector,d_mu,'LineStyle','none','Marker','o');
        
%%
        t_pl = t_pl.changeAxisOptions('XLabelText','$\delta_0$ (GHz)',...
                             'YLabelText','$d_\mu$ (kHz)',...  
                             'FontSize',13 );
                         
%%
    figure('Name','Nonlinear Dispersion');
    t_pl.plotData

end
