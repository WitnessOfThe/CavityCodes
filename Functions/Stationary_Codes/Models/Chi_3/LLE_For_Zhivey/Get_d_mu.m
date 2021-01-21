function d_mu = Get_d_mu(L_L_Split) 

    mode_range = 15001:25000;
    ii         = 1;
    
    tau        = (L_L_Split(ii).Solution.Temporal.t(mode_range(end))...
                    - L_L_Split(ii).Solution.Temporal.t(mode_range(1)));
    
    f   =  [0:(size(L_L_Split(ii).Solution.Temporal.E_s(mode_range,36),1)/2-1),...
       -size(L_L_Split(ii).Solution.Temporal.E_s(mode_range,36),1)/2:-1]...
                                                                 *2*pi/tau;
    
        
        detunning(ii)  = L_L_Split(ii).In.delta/2/pi;
        Power(ii)      = L_L_Split(ii).In.P;
        
        psi_hat_35_pl     = ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,36)*L_L_Split(ii).Space.N)' ; 
        psi_hat_35_mi     = ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,end-35+1)*L_L_Split(ii).Space.N)'; 
        
        d_t_phi_35_pl     = trapz(f.*abs(psi_hat_35_pl).^2)./trapz(abs(psi_hat_35_pl).^2)*L_L_Split(ii).In.norm_coeff/2/pi;
        d_t_phi_35_mi     = trapz(f.*abs(psi_hat_35_mi).^2)./trapz(abs(psi_hat_35_mi).^2)*L_L_Split(ii).In.norm_coeff/2/pi;
        
        d_mu(ii)      = abs(d_t_phi_35_pl - d_t_phi_35_mi)/70;
        
    
end
