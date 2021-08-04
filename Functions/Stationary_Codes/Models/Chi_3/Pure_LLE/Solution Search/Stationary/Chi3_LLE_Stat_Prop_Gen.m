function Stat = Chi3_LLE_Stat_Prop_Gen(x0,Stat)
    
    switch func2str(Stat.Met.Equation)
        
        case 'LLE_Zero_Velocity_Equation'
            
            Stat.Sol.V     = 0;
            Stat.Sol.Psi_k = (x0(1:Stat.Space.N) + 1i*x0(Stat.Space.N+1:2*Stat.Space.N))/Stat.Space.N;
            
        case 'LLE_Full_Dispersion_Equation'
            
            Stat.Sol.V     = x0(end);
            Stat.Sol.Psi_k = (x0(1:Stat.Space.N) + 1i*x0(Stat.Space.N+1:2*Stat.Space.N))/Stat.Space.N;
            
        case 'LLE_Zero_Velocity_Equation_Turndelta'
            
            Stat.Sol.V     = 0;
            Stat.Sol.Psi_k = ([Stat.Eq.PsioMax*Stat.Space.N,x0(2:Stat.Space.N)] + 1i*x0(Stat.Space.N+1:2*Stat.Space.N))/Stat.Space.N;
            switch Stat.Par.variable
                case 'Fin_D'
                            Stat.In.Fin_D     = x;
                            Stat.In.kappa     = Stat.In.D(2)/Stat.In.Fin_D;
                            Stat.In.delta     = Stat.In.kappa*Stat.Eq.delta;
                            Stat.In.P         = Stat.In.W_WStar*pi/(Stat.In.eta*Stat.In.D(1)/Stat.In.kappa)*Stat.In.kappa/Stat.In.gamma; 
                            Stat = Stat.Met.Norm(Stat);
                case 'Fin_Dlog'
                            Stat.Eq.Fin_Dlog   = Stat.Eq.Fin_Dlog+ x0(1);
                            Stat.In.kappa     = Stat.In.D(2)/10^(Stat.Eq.Fin_Dlog);
                            Stat.In.delta     = Stat.In.kappa*Stat.Eq.delta;
                            Stat.In.P         = Stat.In.W_WStar*pi/(Stat.In.eta*Stat.In.D(1)/Stat.In.kappa)*Stat.In.kappa/Stat.In.gamma; 
                            Stat = Stat.Met.Norm(Stat);
                otherwise
                    
                Stat.Eq.(Stat.Par.variable) = Stat.Eq.(Stat.Par.variable)+ x0(1);
                Stat.In.(Stat.Par.variable) = Stat.Eq.norm*Stat.Eq.(Stat.Par.variable);            
                Stat                        = Stat.Met.Norm(Stat);
                    
            end
       
            
    end           
    
    
end