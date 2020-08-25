function Stat = Run_Branch_Universal(L_L)
           
    x_0             =   set_up(L_L.Stat);  
    L_L             =  L_L.Stat.Met.InitialGuess(L_L);
    
    Slv_Start       =  [real(L_L.Stat.Sol.Psi_k(end,:))*L_L.Temp.Space.N,imag(L_L.Stat.Sol.Psi_k(end,:))*L_L.Temp.Space.N,L_L.Stat.Sol.V];
    
    Stat_1          =   Branch(Slv_Start,x_0,L_L.Stat, 1);    
    Stat_2          =   Branch(Slv_Start,x_0,L_L.Stat,-1);
    
    Stat            =   [fliplr(Stat_1),Stat_2];

end

function x_0 = set_up(Stat)

    switch Stat.Par.variable

        case 'delta'

            x_0 = Stat.Eq.delta;

        case 'gamma'

            x_0 = Stat.Eq.gamma;

        case 'h'

            x_0 = Stat.Eq.h;

        case 'd'

            x_0 = Stat.Eq.d;

        case 'V'

            x_0 = Stat.Eq.V;                

    end

end
