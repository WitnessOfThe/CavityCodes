    function M = Chi23_Zero_Mode_Preconditioner(t,Stat,x0)
    
        ddt = 10^3;        
        
        Lo   =  (abs( Stat.Eq.Lo(1) ));%
        Le   =  (abs( Stat.Eq.Le(1)));%
%        Lo   =Stat.Eq.mask.*(abs(-Stat.Space.k.*x0(end)- Stat.Space.k.*Stat.Eq.d/2 + Stat.Space.k.^2*1/2*Stat.Eq.Do(2)));
%        Le   =Stat.Eq.mask.*(abs(-Stat.Space.k.*x0(end)+ Stat.Space.k.*Stat.Eq.d/2 + Stat.Space.k.^2*1/2*Stat.Eq.De(2)));
  %%      
  
        m_psio = (t(1)                  + 1i.*t(2));  
        m_psie = (t(3) + 1i.*t(4));  
        
        M_psio =(ddt.*m_psio./(eps +  1. + ddt.*abs(Lo(1)).' ));
        M_psie =(ddt.*m_psie./(eps +  1. + ddt.*abs(Le(1)).' ));
        
        M     = [real(M_psio);imag(M_psio);real(M_psie);imag(M_psie)];%;%;t(2*L_L.Space.N+1)
        
    end