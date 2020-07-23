function plot_D1_Delta(L_L_Split) 

    mode_range = 10000:25000;
    ii         = 1;
    
    tau        = (L_L_Split(ii).Solution.Temporal.t(mode_range(end))...
                    - L_L_Split(ii).Solution.Temporal.t(mode_range(1)));
    
    f   =  [0:(size(L_L_Split(ii).Solution.Temporal.E_s(mode_range,36),1)/2-1),...
       -size(L_L_Split(ii).Solution.Temporal.E_s(mode_range,36),1)/2:-1]...
                                                                 *2*pi/tau;
    
    for ii = 1:size(L_L_Split,2)
        
        detunning(ii)  = L_L_Split(ii).In.delta/2/pi;
        Power(ii)      = L_L_Split(ii).In.P;
        
        psi_hat_35_pl     = ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,36)*L_L_Split(ii).Space.N)' ; 
        psi_hat_35_mi     = ifft(L_L_Split(ii).Solution.Temporal.E_s(mode_range,990)*L_L_Split(ii).Space.N)'; 
        
        d_t_phi_35_pl     = trapz(f.*abs(psi_hat_35_pl).^2)./trapz(abs(psi_hat_35_pl).^2)*L_L_Split(ii).In.norm_coeff/2/pi;
        d_t_phi_35_mi     = trapz(f.*abs(psi_hat_35_mi).^2)./trapz(abs(psi_hat_35_mi).^2)*L_L_Split(ii).In.norm_coeff/2/pi;
        
        Delta_D1(ii)      = abs(d_t_phi_35_pl - d_t_phi_35_mi)/70;
        
%         if (Delta_D1(ii) > 10) && (Delta_D1(ii) < 100)
%             Flag(i1) = ii;
%             i1 = i1 +1;
%         end
    end
%    [det_grid,power_grid] =  meshgrid(detunning,Power);
%    figure;plot(detunning(Flag)/1E6 ,Power(Flag),'LineStyle','none','Marker','x')
    figure;plot(detunning(41:50)/1E6, Delta_D1(41:50))
    hold on ;plot(detunning(51:60)/1E6, Delta_D1(51:60))
    hold on ;plot(detunning(61:70)/1E6, Delta_D1(61:70))
%    hold on;plot(detunning(Flag(51:60))/1E6,Delta_D1(51:60))
%    hold on;plot(detunning(Flag(61:70))/1E6,Delta_D1(61:70))
    
end
