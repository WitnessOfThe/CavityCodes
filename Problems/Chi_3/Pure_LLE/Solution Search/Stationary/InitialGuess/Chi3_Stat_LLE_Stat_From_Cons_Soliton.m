function Stat   = Chi3_Stat_LLE_Stat_From_Cons_Soliton(Stat)
    
        Stat               = Stat.Met.Norm(Stat);    
        
        NN                 = 30;
        
        kappa_vector = linspace(0,Stat.Eq.kappa,NN);
        h_vector     = linspace(0,Stat.Eq.h,NN);

        D = Stat.Eq.D;

        Stat.Eq.kappa        = 0;
        Stat.Eq.h            = 0;
        Stat.Eq.D(3:end)     = 0;        
        Slv                  = Trials(Stat,Stat.Par.Sol_Re_Sign);
        
        Psi_m               = fft( Slv(1:Stat.Space.N) + 1i*Slv(Stat.Space.N+1:Stat.Space.N*2));
        Slv                  = [real(Psi_m),imag(Psi_m)];
        Stat.Met.Equation    = @L_L_Soliton_Kerr;
        Stat.Met.Newton      = @fsolve;
        
        for ii = 1:NN
            
            Stat.Eq.h                = h_vector(ii);
            [Slv,eps_f,Output]       = Newton_Switcher(Slv,Stat);
            [ii,eps_f,Output]
            
        end
        
        for ii = 1:NN
            
            Stat.Eq.kappa       = kappa_vector(ii);
            [Slv,eps_f,Output]  = Newton_Switcher(Slv,Stat);
            [ii,eps_f,Output]

        end
        
        Stat.Met.Newton      = @Newton_Manual_bicgstab;
        Stat.Met.Equation    = @LLE_Full_Dispersion_Equation;

        Slv(2*Stat.Space.N+1) = 0;
        
 %       t  = Slv(1:Stat.Space.N) + 1i*Slv(Stat.Space.N+1:2*Stat.Space.N);
  %      t   = fft(t);
            
%        Slv(1:Stat.Space.N)                =  Stat.Eq.mask.*real(Slv(1:Stat.Space.N));
 %       Slv(Stat.Space.N+1:Stat.Space.N*2) =  Stat.Eq.mask.*imag(Slv(Stat.Space.N+1:Stat.Space.N*2));
           

        [Slv,eps_f,Output]                = Newton_Switcher(Slv,Stat);
        [eps_f,Output]
        Stat(1).Sol.Flag        =                               Output;
        Stat(1).Sol.eps         =                                    eps_f;


        Stat              = Chi3_LLE_Stat_Prop_Gen(Slv,Stat);
            
end
