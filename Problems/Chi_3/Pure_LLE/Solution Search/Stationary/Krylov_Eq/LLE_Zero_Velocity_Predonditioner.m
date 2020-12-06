    function M = LLE_Zero_Velocity_Predonditioner(t,L_L,x0)
    
        ddt = 10^4;        
        
        L                   =  L_L.Eq.mask.*(1i.*L_L.Space.k.*x0(end) - 1i*L_L.Eq.L);
  %%      
        m_psi = t(1:L_L.Space.N) + 1i.*t(L_L.Space.N+1:2*L_L.Space.N);  
        M_psi = ddt.*m_psi./(  1. + ddt*abs(L).' );
        
        M     = [L_L.Eq.mask'.*real(M_psi);L_L.Eq.mask'.*imag(M_psi);t(2*L_L.Space.N+1)];%;%;t(2*L_L.Space.N+1)
         
    end
