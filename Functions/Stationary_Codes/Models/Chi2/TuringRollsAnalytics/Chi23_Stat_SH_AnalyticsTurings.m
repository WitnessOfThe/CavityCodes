function CW = Chi23_Stat_SH_AnalyticsTurings(CW)

    CW = CW.Met.Norm(CW);
  %  CW = Chi2_CW(CW);
   
    k    = [0,CW.In.mu_bl];
    CW.In.Deltafmu   = CW.In.delta_o + 1/2*CW.In.Do(2)*k.^2 - 1i/2*CW.In.ko;     
    CW.In.Deltasmu   = CW.In.delta_e + ((CW.In.De(1)-CW.In.Do(1) )*k + 1/2*CW.In.De(2)*k.^2) - 1i/2*CW.In.ke;
    
    CW.In.g_mu = sqrt( (CW.In.delta_o + 1/2*CW.In.Do(2)*k(2).^2).^2 + 1/4*CW.In.ko.^2 ); 
    
    
    Psi_s0             = CW.In.Deltafmu(2)./CW.In.gam2o;  
    
    Psi_f0             = 1i*CW.In.H_f.*...
                          1/2*CW.In.ko.*(CW.In.Deltafmu(2) - conj(CW.In.Deltafmu(1)) )./...
                          (abs(CW.In.Deltafmu(2)).^2 - abs(CW.In.Deltafmu(1)).^2 );  
    
    Psi_muf2(1)      = (real(CW.In.Deltafmu(2).*CW.In.Deltasmu(1)) +...
                        sqrt(CW.In.gam2o.^2*CW.In.gam2e.^2.*abs(Psi_f0).^4 -imag(CW.In.Deltafmu(2).*CW.In.Deltasmu(1)).^2 ))/CW.In.gam2o/CW.In.gam2e/2;
                         
    Psi_muf2(2)        = (real(CW.In.Deltafmu(2).*CW.In.Deltasmu(1)) -...
                        sqrt(CW.In.gam2o.^2*CW.In.gam2e.^2.*abs(Psi_f0).^4 -imag(CW.In.Deltafmu(2).*CW.In.Deltasmu(1)).^2 ))/CW.In.gam2o/CW.In.gam2e/2;
                         
%     exp_a(1)              = -1i*CW.Sol.g.*abs( CW.In.Deltasmu(1) )./...
%         (1i*imag( CW.In.Deltafmu(2).*CW.In.Deltasmu(1)) - sqrt( abs(CW.In.Deltasmu(1)).^2*(CW.Sol.g.^2- CW.In.g_mu.^2 ) + real(CW.In.Deltafmu(2).*CW.In.Deltasmu(1)).^2 ) );
%     exp_a(2)              = -1i*CW.Sol.g.*abs( CW.In.Deltasmu(1) )./...
%         (1i*imag( CW.In.Deltafmu(2).*CW.In.Deltasmu(1)) + sqrt( abs(CW.In.Deltasmu(1)).^2*(CW.Sol.g.^2- CW.In.g_mu.^2 ) + real(CW.In.Deltafmu(2).*CW.In.Deltasmu(1)).^2 ) );
%     
%     exp_a(imag(sqrt(Psi_muf2))~=0)    = NaN;

    Psi_muf2(imag(sqrt(Psi_muf2))~=0) = NaN;
    
    CW.Sol.PsiS(1)        = Psi_s0(1);%;.*exp_a(1);
    CW.Sol.PsiS(2)        = Psi_s0(1);%.*exp_a(2);
    
    CW.Sol.PsiFo(1)        =Psi_f0 (1);%;.*exp_a(1);
    CW.Sol.PsiFo(2)        = Psi_f0 (1);%.*exp_a(2);
    CW.Sol.PsiF           = sqrt(Psi_muf2);
%    CW.Sol.expA           = exp_a;
    
end