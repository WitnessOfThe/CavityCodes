    function M = LLE_Zero_Velocity_Predonditioner_TurnDelta(t,Stat,x0)
    
        ddt = 10^3;        
        
        L                   =  Stat.Eq.mask.*(- 1i*Stat.Eq.L);
  %%      
        m_psi = [0;t(2:Stat.Space.N)] + 1i.*t(Stat.Space.N+1:2*Stat.Space.N);  
        M_psi = ddt.*m_psi./(  1. + ddt*abs(L).' );
       % ;t(end)
        M     = [t(1);real(M_psi(2:end));imag(M_psi)];%;%;t(2*L_L.Space.N+1)
         
    end
