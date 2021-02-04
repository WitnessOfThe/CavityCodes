    function M = Chi23_Full_Dispersion_Preconditioner(t,Stat,x0)
    
        ddt = 10^4;        
        
        Lo   =  Stat.Eq.mask.*(1i.*Stat.Space.k.*x0(end) - 1i*Stat.Eq.Lo);
        Le   =  Stat.Eq.mask.*(1i.*Stat.Space.k.*x0(end) - 1i*Stat.Eq.Le);
  %%      
        m_psio = t(1:Stat.Space.N) + 1i.*t(Stat.Space.N+1:2*Stat.Space.N);  
        m_psie = t(2*Stat.Space.N+1:3*Stat.Space.N) + 1i.*t(3*Stat.Space.N+1:4*Stat.Space.N);  
        M_psio = ddt.*m_psio./(  1. + ddt*abs(Lo).' );
        M_psie = ddt.*m_psie./(  1. + ddt*abs(Le).' );
        
        M     = [Stat.Eq.mask'.*real(M_psio);Stat.Eq.mask'.*imag(M_psio);Stat.Eq.mask'.*real(M_psie);Stat.Eq.mask'.*imag(M_psie);t(2*Stat.Space.N+1)];%;%;t(2*L_L.Space.N+1)
        
    end