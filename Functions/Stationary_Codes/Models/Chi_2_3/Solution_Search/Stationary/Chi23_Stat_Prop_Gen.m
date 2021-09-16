function Stat = Chi23_Stat_Prop_Gen(x0,Stat)
   
    switch func2str(Stat.Met.Equation)
        
        case 'Chi23_Full_Dispersion_Equation_RS_OPO'
            
            Stat.Sol.Psi_o  = fft(x0(1:Stat.Space.N) + 1i*x0(Stat.Space.N+1:2*Stat.Space.N))/Stat.Space.N;
            Stat.Sol.Psi_e  = fft(x0(2*Stat.Space.N+1:3*Stat.Space.N) + 1i*x0(3*Stat.Space.N+1:4*Stat.Space.N))/Stat.Space.N;
            Stat.Sol.V      = x0(end);
        case 'Chi23_Full_Dispersion_Equation_RS'
            
            Stat.Sol.Psi_o  = fft(x0(1:Stat.Space.N) + 1i*x0(Stat.Space.N+1:2*Stat.Space.N))/Stat.Space.N;
            Stat.Sol.Psi_e  = fft(x0(2*Stat.Space.N+1:3*Stat.Space.N) + 1i*x0(3*Stat.Space.N+1:4*Stat.Space.N))/Stat.Space.N;
            Stat.Sol.V      = x0(end);
            
        case 'Chi23_Full_Dispersion_Equation_RS_delta'
            
            
            Stat.Sol.Psi_o  = fft([Stat.Eq.PsioMax ,x0(2:Stat.Space.N)] + 1i*x0(Stat.Space.N+1:2*Stat.Space.N))/Stat.Space.N;
            Stat.Sol.Psi_e  = fft(x0(2*Stat.Space.N+1:3*Stat.Space.N) + 1i*x0(3*Stat.Space.N+1:4*Stat.Space.N))/Stat.Space.N;
            Stat.Sol.V      = x0(end);
            
         %   Stat.Eq.delta_e = Stat.Eq.delta_e + x0(1);
         %   Stat.In.delta_e = Stat.Eq.delta_e*Stat.Eq.norm;
        %    Stat.In.delta_o = (Stat.In.delta_e + Stat.In.eps)/2;
            Stat.Eq.delta_o = Stat.Eq.delta_o + x0(1);            
            Stat.In.delta_o = (Stat.Eq.delta_o)*Stat.Eq.norm;
            Stat            = Stat.Met.Norm(Stat);
        case 'Chi23_Zero_Mode_Equation'
            
            Stat.Sol.Psi_o  = x0(1)+1i*x0(2);
            Stat.Sol.Psi_e  = x0(3)+1i*x0(4);
            Stat.Sol.V      = 0;
        case 'Chi23_Zero_Mode_Equation_RS_delta'
            
            Stat.Sol.Psi_o  = Stat.Eq.PsioMax+1i*x0(2);
            Stat.Sol.Psi_e  = x0(3)+1i*x0(4);
            Stat.Sol.V      = 0;
            
            Stat.Eq.delta_o = Stat.Eq.delta_o + x0(1);            
            Stat.In.delta_o = (Stat.Eq.delta_o)*Stat.Eq.norm;
            Stat            = Stat.Met.Norm(Stat);
            
    end
                   
end