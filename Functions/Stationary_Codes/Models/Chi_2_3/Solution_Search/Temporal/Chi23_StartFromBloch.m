function Temp = Chi23_StartFromBloch(Stat,Temp)
    
    Temp.In.Psi_Start = 1E-6*zeros(1,Temp.Space.N*2);
    Temp.In.Psi_Start(Temp.Eq.mode_range) = 1E-6;
    
    Temp.In.Psi_Start(1)              = Stat.Sol.Psi_o(1)*Temp.Space.N;
        
    Temp.In.Psi_Start(Temp.Space.N+1) = Stat.Sol.Psi_e(1)*Temp.Space.N;
    if Stat.In.mu_bl ~= 0
        for i = 1:round(Stat.Space.N/Stat.In.mu_bl/2)

            Temp.In.Psi_Start(1+Stat.In.mu_bl*i)              = ...
                                                Stat.Sol.Psi_o(i+1)*Temp.Space.N;

            Temp.In.Psi_Start(Temp.Space.N+1+Stat.In.mu_bl*i) = ...
                                                Stat.Sol.Psi_e(i+1)*Temp.Space.N;

            Temp.In.Psi_Start(Temp.Space.N-Stat.In.mu_bl*i+1)              = ...
                                                Stat.Sol.Psi_o(end-(i-1))*Temp.Space.N;

            Temp.In.Psi_Start(2*Temp.Space.N-Stat.In.mu_bl*i+1) = ...
                                                Stat.Sol.Psi_e(end-(i-1))*Temp.Space.N;

        end
    end    
        Temp.In.t_start                   = 0;
        
end