function Stat = Chi23_Stat_Prop_Gen(x0,Stat)
   
    Stat.Sol.Psi_o  = fft(x0(1:Stat.Space.N) + 1i*x0(Stat.Space.N+1:2*Stat.Space.N))/Stat.Space.N;
    Stat.Sol.Psi_e  = fft(x0(2*Stat.Space.N+1:3*Stat.Space.N) + 1i*x0(3*Stat.Space.N+1:4*Stat.Space.N))/Stat.Space.N;
    Stat.Sol.V      = x0(end);
    
end