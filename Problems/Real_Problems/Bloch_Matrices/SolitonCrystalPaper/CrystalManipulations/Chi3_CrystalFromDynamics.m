function R = Chi3_CrystalFromDynamics(R,TempLocation,MP)

       Temp = importdata(TempLocation);
       N = R.Stat.In.N_mode; 
       R.Stat.In                  = Temp.In;
       R.Stat.In.N_mode = N; 
       R.Stat                     = R.Stat.Met.Norm(R.Stat);
       
       R.Stat.In.Psi_Start        = zeros(1,R.Stat.In.N_mode)*1E-10;
%       R.Stat.In.Psi_Start(Temp.Eq.mode_range) = Temp.Sol.Psi(2,:);
        R.Stat.In.Psi_Start(1:(N/2-1)) = Temp.Sol.Psi(2,1:(N/2-1));
        R.Stat.In.Psi_Start(N/2:N) = Temp.Sol.Psi(2,(size(Temp.Sol.Psi,2)-N/2:1:size(Temp.Sol.Psi,2)));
       
%       R.Stat.In.Psi_Start        = Temp.Sol.Psi(2,:);   
                
       R.Stat.In.t_start      = 0;
        
       vel =  1E-2;% (imag(R.CW.Stab(R.Stat.Par.CW_num).Value(ind(2)))        - imag(R.CW.Stab(R.Stat.Par.CW_num).Value(ind(1))))/2/R.Stat.In.mu_bl/R.Stat.Space.N;
        switch func2str(R.Stat.Met.Equation)
            
            
            case               'LLE_Zero_Velocity_Equation'
                
            x0  = full([real(R.Stat.In.Psi_Start),imag(R.Stat.In.Psi_Start)]*R.Stat.Space.N);
            
            case               'LLE_Full_Dispersion_Equation'
                
            x0  = full([real(R.Stat.In.Psi_Start),imag(R.Stat.In.Psi_Start),vel/R.Stat.Space.N]*R.Stat.Space.N);
            
        end
        [x,eps_f,SolveFlag]         =    Newton_Switcher(x0,R.Stat);
        R.Stat.Sol.Exitflag         =    SolveFlag;
        R.Stat.Sol.eps_f            =        eps_f;
    
        eps_f;
        
        R.Stat                 = R.Stat.Met.Prop_Gen(x,R.Stat);
        MP  =strcat(MP,'FromDyn/');
        SP  = Chi3_CrystalPathGenerator(R.Stat,MP);
        Stat = R.Stat;
        save(strcat(SP,'Starter'),'Stat');
end