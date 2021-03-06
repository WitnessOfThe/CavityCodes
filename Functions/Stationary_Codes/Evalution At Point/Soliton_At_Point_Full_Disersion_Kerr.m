function Stat   = Soliton_At_Point_Full_Disersion_Kerr(Stat,Delta,options)
    
        Dir                = Finite_Derivatives(Stat.Space.N,Stat.Space.dphi);
        NN                 = 30;
        
        kappa_vector       = linspace(0,Stat.Eq.kappa_vector(Stat.In.pump_index),NN);
        h_vector           = linspace(0,Stat.Eq.h,NN);
        
%       D3           = linspace(0,Stat.Eq.D(3),NN);
%       D4           = linspace(0,Stat.Eq.D(4),NN);
%       D5           = linspace(0,L_L.Eq.D5,NN);

        D = Stat.Eq.D;

        Stat.Eq.kappa        = 0;
        Stat.Eq.h            = 0;
        Stat.Eq.D(3:end)     = 0;
        Slv                  = Trials(Stat,Delta.Sol_Flag);
        
        Delta.Newton  = 'fsolve';
        
        for ii = 1:NN
            
            Stat.Eq.h = h_vector(ii);
            Slv       = Newton_Switcher(Dir,Slv,Stat,Delta,@L_L_Soliton_Kerr,options);
            
        end
        
        for ii = 1:NN
            
            Stat.Eq.kappa = kappa_vector(ii);
            Slv      = Newton_Switcher(Dir,Slv,Stat,Delta,@L_L_Soliton_Kerr,options);

        end
        
        
         Slv(2*Stat.Space.N+1) = 0;

        Delta.Newton      = 'Bc_Grad'; %'fsolve'
        Delta.Newton_tol  = 1E-14;  
        
           t  = Slv(1:Stat.Space.N) + 1i*Slv(Stat.Space.N+1:2*Stat.Space.N);
           t   = fft(t);
            
           Slv(1:Stat.Space.N)                 =  Stat.Eq.Shifted.mask.*real(t);
           Slv(Stat.Space.N+1:Stat.Space.N*2)  =  Stat.Eq.Shifted.mask.*imag(t);
           

           Slv                  = Newton_Switcher(Dir,Slv,Stat,Delta,@LLE_Full_Dispersion_Equation,options);
           
           

        Stat              = Prop_gen(Stat,Slv,Delta);
    
        figure;
        subplot(1,2,1);plot(Stat.Space.phi,abs(Stat.Solution.Psi).^2);
        subplot(1,2,2);plot(Stat.Space.k,10*log10(abs(Stat.Solution.E_j).^2));
        
end
