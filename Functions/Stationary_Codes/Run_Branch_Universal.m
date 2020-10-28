function Stat = Run_Branch_Universal(Stat,N_mode)
           
    x_0             =  set_up(Stat);  
        
    Stat_1          =   Branch([real(Stat.Sol.Psi_k),imag(Stat.Sol.Psi_k),0]*Stat.Space.N,x_0,Stat, 1);    
    Stat_2          =   Branch([real(Stat.Sol.Psi_k),imag(Stat.Sol.Psi_k),0]*Stat.Space.N,x_0,Stat,-1);
    
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
