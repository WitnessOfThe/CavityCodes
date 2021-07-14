function CW = Chi23_Stat_OPO_AnalyticsTurings(CW)

    CW = CW.Met.Norm(CW);
    CW = Chi2_CW_OPOSingleField(CW);
    
    if CW.In.mu_bl == 0
        Coeff = 1;
    else
        Coeff = 2;
    end
   
    k    = [0,CW.In.mu_bl];
    
%    CW.In.g_mu = sqrt( (CW.In.delta_o + 1/2*CW.In.Do(2)*k(2).^2).^2 + 1/4*CW.In.ko.^2); 
    
    CW.In.Deltafmu   = CW.In.delta_o + 1/2*CW.In.Do(2)*k.^2 - 1i/2*CW.In.ko;     
    
    CW.In.Deltasmu   = CW.In.delta_e + ((CW.In.De(1)-CW.In.Do(1) )*k + 1/2*CW.In.De(2)*k.^2) - 1i/2*CW.In.ke;
    
    Psi_s0             = CW.In.Deltafmu(2)./CW.In.gam2o;  
    
    Psi_muf2(1)      = (real(CW.In.Deltafmu(2).*CW.In.Deltasmu(1)) +...
                        sqrt(1/4*CW.In.ke.^2*CW.In.gam2o.^2*CW.In.H_s.^2 - imag(CW.In.Deltafmu(2).*CW.In.Deltasmu(1)).^2 ))/CW.In.gam2o/CW.In.gam2e/Coeff;
                         
    Psi_muf2(2)      = (real(CW.In.Deltafmu(2).*CW.In.Deltasmu(1)) -...
                        sqrt(1/4*CW.In.ke.^2*CW.In.gam2o.^2*CW.In.H_s.^2 - imag(CW.In.Deltafmu(2).*CW.In.Deltasmu(1)).^2 ))/CW.In.gam2o/CW.In.gam2e/Coeff;
                         
    exp_a                 = -1i*1/2*CW.In.ke*CW.In.gam2o*CW.In.H_s./...
       (CW.In.Deltafmu(2).*CW.In.Deltasmu(1) - Coeff.*CW.In.gam2o*CW.In.gam2e*abs(Psi_muf2));
    
    exp_a(imag(sqrt(Psi_muf2))~=0)    = NaN;
    Psi_muf2(imag(sqrt(Psi_muf2))~=0) = NaN;
    exp_a(Psi_muf2<0)    = NaN;
    Psi_muf2(Psi_muf2<0) = NaN;

    
    CW.Sol.PsiF           = sqrt(abs(Psi_muf2)).*exp_a;
    
    CW.Sol.PsiS(1)        = Psi_s0(1).*exp_a(1);
    CW.Sol.PsiS(2)        = Psi_s0(1).*exp_a(2);
    
    CW.Sol.expA           = exp_a;
end