    function M = LLE_Full_Dispersion_Predonditioner(t,L_L,x0)
    
        mask           = L_L.Eq.mask;
        ddt = 10^4;
        
        
        L                   = L_L.Eq.omega_j  + L_L.Eq.delta ;%omega_j;%;();
        L                   =  (1i.*L_L.Space.k.*x0(end) - 1i*L);
%%
        L                   =  mask.*( L  );%L_L.Eq.delta +  - 1i*L_L.Eq.kappa/2   %L_L.Eq.delta +       %- 1i*L_L.Eq.Shifted.kappa_vector/2                            
  %%      
        m_psi = t(1:L_L.Space.N) + 1i.*t(L_L.Space.N+1:2*L_L.Space.N);  
        
        %M_psi = fft(m_psi);
        
        M_psi = ddt.*m_psi./(  1. + ddt*abs(L).' );
        
        %M_psi = ifft(mask'.*M_psi);
        
        M     = [mask'.*real(M_psi);mask'.*imag(M_psi);t(2*L_L.Space.N+1)];%;%;t(2*L_L.Space.N+1)
        
    end
