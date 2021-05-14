    function M = Chi23_Full_Dispersion_Preconditioner_RS(t,Stat,x0)
    
        ddt = 10^6;        
        
        Lo   =  Stat.Eq.mask.*(abs( Stat.Eq.Lo - Stat.Space.k.*x0(end) ));%
        Le   =  Stat.Eq.mask.*(abs( Stat.Eq.Le - Stat.Space.k.*x0(end) ));%
%        Lo   =Stat.Eq.mask.*(abs(-Stat.Space.k.*x0(end)- Stat.Space.k.*Stat.Eq.d/2 + Stat.Space.k.^2*1/2*Stat.Eq.Do(2)));
%        Le   =Stat.Eq.mask.*(abs(-Stat.Space.k.*x0(end)+ Stat.Space.k.*Stat.Eq.d/2 + Stat.Space.k.^2*1/2*Stat.Eq.De(2)));
  %%      
  
        m_psio = fft(t(1:Stat.Space.N)                  + 1i.*t(Stat.Space.N+1:2*Stat.Space.N));  
        m_psie = fft(t(2*Stat.Space.N+1:3*Stat.Space.N) + 1i.*t(3*Stat.Space.N+1:4*Stat.Space.N));  
        
        M_psio = ifft(Stat.Eq.mask.'.*ddt.*m_psio./(eps +  1. + ddt.*abs(Lo).' ));
        M_psie = ifft(Stat.Eq.mask.'.*ddt.*m_psie./(eps +  1. + ddt.*abs(Le).' ));
        
        M     = [real(M_psio);imag(M_psio);real(M_psie);imag(M_psie);t(4*Stat.Space.N+1)];%;%;t(2*L_L.Space.N+1)
        
    end