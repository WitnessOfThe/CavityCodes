function Stat = Run_Branch_Universal(L_L,N_mode)
           
%    L_L             =  L_L.Stat.Met.InitialGuess(L_L,N_mode);
    x_0             =  set_up(L_L.Stat);  
        
    Stat_1          =   Branch([real(L_L.Stat.Sol.Psi_k),imag(L_L.Stat.Sol.Psi_k),0]*L_L.Stat.Space.N,x_0,L_L.Stat, 1);    
    Stat_2          =   Branch([real(L_L.Stat.Sol.Psi_k),imag(L_L.Stat.Sol.Psi_k),0]*L_L.Stat.Space.N,x_0,L_L.Stat,-1);
    
    Stat            =   [fliplr(Stat_1),Stat_2];
    
end

function x_0 = set_up(Stat)

    switch Stat.Par.variable

        case 'delta'

            x_0 = Stat.Eq.delta;

        case 'gamma'

            x_0 = Stat.Eq.gamma;

        case 'Pump Power'

            x_0 = Stat.Eq.h;

        case 'd'

            x_0 = Stat.Eq.d;

        case 'V'

            x_0 = Stat.Eq.V;                

    end

end
