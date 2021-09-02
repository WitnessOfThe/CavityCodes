function M = Chi23_Full_Dispersion_Preconditioner_RS_delta(t,Stat,x0)

    ddt = 10^6;        

    Lo   =  Stat.Eq.mask.*(abs( Stat.Eq.Lo - Stat.Space.k.*x0(end) ));%
    Le   =  Stat.Eq.mask.*(abs( Stat.Eq.Le - Stat.Space.k.*x0(end) ));%


    m_psio = fft([0;t(2:Stat.Space.N)]                  + 1i.*t(Stat.Space.N+1:2*Stat.Space.N));  
    m_psie = fft(t(2*Stat.Space.N+1:3*Stat.Space.N) + 1i.*t(3*Stat.Space.N+1:4*Stat.Space.N));  

    M_psio = ifft(ddt.*m_psio./(eps +  1. + ddt*abs(Lo).' ));
    M_psie = ifft(ddt.*m_psie./(eps +  1. + ddt*abs(Le).' ));

    M     = [t(1);real(M_psio(2:Stat.Space.N));imag(M_psio);real(M_psie);imag(M_psie);t(4*Stat.Space.N+1)];%;%;t(2*L_L.Space.N+1)
%t(4*Stat.Space.N+2)
end