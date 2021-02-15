function Stat = Run_Branch_Universal(Stat)
    Stat = Stat.Met.Norm(Stat);
%    x_0             =  set_up(Stat);  
    x_0 = Stat.Eq.(Stat.Par.variable);
        
        switch func2str(Stat(1).Met.Equation)
            case   'LLE_Zero_Velocity_Equation'
                Stat_1          =   Branch([real(Stat.Sol.Psi_k),imag(Stat.Sol.Psi_k)]*Stat.Space.N,x_0,Stat, 1);    
                Stat_2          =   Branch([real(Stat.Sol.Psi_k),imag(Stat.Sol.Psi_k)]*Stat.Space.N,x_0,Stat,-1);
            case   'LLE_Full_Dispersion_Equation'
                Stat_1          =   Branch([[real(Stat.Sol.Psi_k),imag(Stat.Sol.Psi_k)]*Stat.Space.N,Stat.Sol.V],x_0,Stat, 1);    
                Stat_2          =   Branch([[real(Stat.Sol.Psi_k),imag(Stat.Sol.Psi_k)]*Stat.Space.N,Stat.Sol.V],x_0,Stat,-1);
            case   'Chi23_CW'
                Stat_1          =   Branch([real(Stat.Sol.Psi_o),imag(Stat.Sol.Psi_o),real(Stat.Sol.Psi_e),imag(Stat.Sol.Psi_e)],x_0,Stat, 1);    
                Stat_2          =   Branch([real(Stat.Sol.Psi_o),imag(Stat.Sol.Psi_o),real(Stat.Sol.Psi_e),imag(Stat.Sol.Psi_e)],x_0,Stat,-1);
            case   'Chi23_Full_Dispersion_Equation_RS'
                Stat_1          =   Branch([real(ifft(Stat.Sol.Psi_o)),imag(ifft(Stat.Sol.Psi_o)),real(ifft(Stat.Sol.Psi_e)),imag(ifft(Stat.Sol.Psi_e)),Stat.Sol.V/Stat.Space.N]*Stat.Space.N,x_0,Stat, 1);    
                Stat_2          =   Branch([real(ifft(Stat.Sol.Psi_o)),imag(ifft(Stat.Sol.Psi_o)),real(ifft(Stat.Sol.Psi_e)),imag(ifft(Stat.Sol.Psi_e)),Stat.Sol.V/Stat.Space.N]*Stat.Space.N,x_0,Stat,-1);
        end
        
        
        if size(Stat_1,2) ~= 0 && size(Stat_2,2) ~= 0
        Stat            =   [fliplr(Stat_1),Stat_2];
    end
    if size(Stat_1,2) == 0
        Stat            =   Stat_2;
    end
    if size(Stat_2,2) == 0
        Stat            =   [fliplr(Stat_1)];
    end
 
end
