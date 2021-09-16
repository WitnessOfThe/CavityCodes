function M = Chi23_Zero_Mode_Preconditioner_RS_delta(t,Stat,x0)

    ddt = 10^6;        

    Lo   =  (abs( Stat.Eq.Lo(1) ));%
    Le   =  (abs( Stat.Eq.Le(1) ));%


    m_psio = ([0]  + 1i.*t(2));  
    m_psie = (t(3) + 1i.*t(4));  

    M_psio = (ddt.*m_psio./(eps +  1. + ddt*abs(Lo(1)).' ));
    M_psie = (ddt.*m_psie./(eps +  1. + ddt*abs(Le(1)).' ));

    M     = [t(1);imag(M_psio);real(M_psie);imag(M_psie)];%;%;t(2*L_L.Space.N+1)
end