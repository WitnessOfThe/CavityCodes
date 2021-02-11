    function M = Chi23_Full_Dispersion_Preconditioner(t,Stat,x0)
    
        ddt = 10^4;        
        
        Lo   =  Stat.Eq.mask.*(abs( Stat.Eq.Lo  - Stat.Space.k.*x0(end) ));%
        Le   =  Stat.Eq.mask.*(abs( Stat.Eq.Le  - Stat.Space.k.*x0(end) ));%
%        Lo   =Stat.Eq.mask.*(abs(-Stat.Space.k.*x0(end)- Stat.Space.k.*Stat.Eq.d/2 + Stat.Space.k.^2*1/2*Stat.Eq.Do(2)));
%        Le   =Stat.Eq.mask.*(abs(-Stat.Space.k.*x0(end)+ Stat.Space.k.*Stat.Eq.d/2 + Stat.Space.k.^2*1/2*Stat.Eq.De(2)));
  %%      
  
        m_psio = t(1:Stat.Space.N)                  + 1i.*t(Stat.Space.N+1:2*Stat.Space.N);  
        m_psie = t(2*Stat.Space.N+1:3*Stat.Space.N) + 1i.*t(3*Stat.Space.N+1:4*Stat.Space.N);  
        
        M_psio = ddt.*m_psio./(eps +  1. + ddt*abs(Lo).' );
        M_psie = ddt.*m_psie./(eps +  1. + ddt*abs(Le).' );
        
        M     = [Stat.Eq.mask'.*real(M_psio);Stat.Eq.mask'.*imag(M_psio);Stat.Eq.mask'.*real(M_psie);Stat.Eq.mask'.*imag(M_psie);t(4*Stat.Space.N+1)];%;%;t(2*L_L.Space.N+1)
        
    end