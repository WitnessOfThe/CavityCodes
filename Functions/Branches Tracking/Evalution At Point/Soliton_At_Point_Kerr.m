    function [Slv,L_L]   = Soliton_At_Point_Kerr(L_L,Delta,options)
    
        Dir                = Finite_Derivatives(L_L.Space.N,L_L.Space.dphi);
        NN                 = 50;
        
        kappa_vector = linspace(0,L_L.Eq.kappa,NN);
        h_vector     = linspace(0,L_L.Eq.h,NN);
        D4_vector    = linspace(0,L_L.Eq.D(4),NN);
        L_L.Eq.D(4)   = 0;
        L_L.Eq.kappa = 0;
        L_L.Eq.h     = 0;
        
        Slv          = Trials(L_L,Delta.Sol_Flag);
        %Slv(2*L_L.Space.N+1 ) = 0;
        
         
        for ii = 1:NN
            
            L_L.Eq.h = h_vector(ii);
            Slv      = Newton_Switcher(Dir,Slv,L_L,Delta,@L_L_Soliton_Kerr,options);
            
        end
        
        for ii = 1:NN
            
            L_L.Eq.kappa = kappa_vector(ii);
            Slv      = Newton_Switcher(Dir,Slv,L_L,Delta,@L_L_Soliton_Kerr,options);
            
        end
        
        for ii = 1:NN
            
            L_L.Eq.D(4) = D4_vector(ii);
            Slv      = Newton_Switcher(Dir,Slv,L_L,Delta,@L_L_Soliton_Kerr,options);
            
        end
        
        
%        Slv(2*L_L.Space.N+1 ) = 0;
        L_L              = Prop_gen(L_L,Slv,Delta);  
        %%
        figure;
        plot(Slv);
        
        end
