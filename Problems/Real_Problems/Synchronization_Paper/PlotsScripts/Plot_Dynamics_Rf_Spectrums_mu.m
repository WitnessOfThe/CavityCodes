function  Plot_Dynamics_Rf_Spectrums_mu(Temp,ind_t)

        N_t = size(ind_t,2);
   
        f = [0:N_t/2-1,-N_t/2:-1]/( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) )*Temp.Eq.norm/1E6;
    
        
        for i = 1:Temp.Space.N
            psi_hat     = ifft(Temp.Sol.Psi(ind_t,i))' ; 
        
            d_t_phi(i)     = trapz(f.*abs(psi_hat).^2)./trapz(abs(psi_hat).^2);
        
        end        
        
        d_t_phi(isnan(d_t_phi)) =0;
        t_pl = proPlot(fftshift(Temp.Space.k),fftshift(d_t_phi));
        
%%
        t_pl = t_pl.changeAxisOptions('XLabelText','$\mu$',...
                             'YLabelText','$<\partial\phi_\mu>$ (MHz)',...  
                             'FontSize',13,'XLim',[-15,15] );
                         
%%
    figure('Name','Nonlinear Dispersion');
    t_pl.plotData
end
