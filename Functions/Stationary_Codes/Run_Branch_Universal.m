function Stat = Run_Branch_Universal(Stat)
           
    x_0             =  set_up(Stat);  
        
        switch func2str(Stat(1).Met.Equation)
            case   'LLE_Zero_Velocity_Equation'
    Stat_1          =   Branch([real(Stat.Sol.Psi_k),imag(Stat.Sol.Psi_k)]*Stat.Space.N,x_0,Stat, 1);    
    Stat_2          =   Branch([real(Stat.Sol.Psi_k),imag(Stat.Sol.Psi_k)]*Stat.Space.N,x_0,Stat,-1);
            case   'LLE_Full_Dispersion_Equation'
    Stat_1          =   Branch([real(Stat.Sol.Psi_k),imag(Stat.Sol.Psi_k),0]*Stat.Space.N,x_0,Stat, 1);    
    Stat_2          =   Branch([real(Stat.Sol.Psi_k),imag(Stat.Sol.Psi_k),0]*Stat.Space.N,x_0,Stat,-1);
        end
    
    if size(Stat_1,2) ~= 0 && size(Stat_2,2) ~= 0 
        Stat            =   [fliplr(Stat_1),Stat_2];
    end
    if size(Stat_1,2) == 0
        Stat            =   [Stat_2];
    end
    if size(Stat_2,2) == 0
        Stat            =   [fliplr(Stat_1)];
    end
 
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
