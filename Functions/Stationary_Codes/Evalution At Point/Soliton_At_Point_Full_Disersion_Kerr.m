function [Slv,L_L]   = Soliton_At_Point_Full_Disersion_Kerr(L_L,Delta,options)
    
        Dir                = Finite_Derivatives(L_L.Space.N,L_L.Space.dphi);
        NN                 = 30;
        
        kappa_vector = linspace(0,L_L.Eq.kappa_vector(L_L.In.pump_index),NN);
        h_vector     = linspace(0,L_L.Eq.h,NN);
        D3           = linspace(0,L_L.Eq.D(3),NN);
        D4           = linspace(0,L_L.Eq.D(4),NN);
%        D5           = linspace(0,L_L.Eq.D5,NN);

        D = L_L.Eq.D;

        L_L.Eq.kappa   = 0;
        L_L.Eq.h       = 0;
        L_L.Eq.D(3:end)    = 0;        
        Slv                  = Trials(L_L,Delta.Sol_Flag);
        
        Delta.Newton  = 'fsolve';
        for ii = 1:NN
            
            L_L.Eq.h = h_vector(ii);
            Slv      = Newton_Switcher(Dir,Slv,L_L,Delta,@L_L_Soliton_Kerr,options);
            
        end
        
        for ii = 1:NN
            
            L_L.Eq.kappa = kappa_vector(ii);
            Slv      = Newton_Switcher(Dir,Slv,L_L,Delta,@L_L_Soliton_Kerr,options);

        end
        
%         for ii = 1:NN
%             
%            L_L.Eq.D(4)    = D4(ii);
%            Slv      = Newton_Switcher(Dir,Slv,L_L,Delta,@L_L_Soliton_Kerr,options);
%            
%        end    
% %                         
         Slv(2*L_L.Space.N+1) = 0;
% %         
% % options                      = optimoptions(@fsolve,'CheckGradients',false,'Display',...
% %                                    'iter','UseParallel',true,'SpecifyObjectiveGradient',true,...
% %                                    'Algorithm','trust-region-dogleg','FunctionTolerance',Delta.Newton_tol,...
% %                                    'MaxIterations',Delta.Newton_iter,'StepTolerance',1E-20,'OptimalityTolerance',1E-25);%,        for ii = 1:NN
% %             
%         for ii = 2:NN
%             
%            L_L.Eq.D(3)    = D3(ii);
%            Slv            = Newton_Switcher(Dir,Slv,L_L,Delta,@L_L_Soliton_Full_Dispersion,options);
%             
%         end
%         
        Delta.Newton      = 'Bc_Grad'; %'fsolve'
        Delta.Newton_tol  = 1E-14;  
        
           t  = Slv(1:L_L.Space.N) + 1i*Slv(L_L.Space.N+1:2*L_L.Space.N);
           t   = fft(t);
            
           Slv(1:L_L.Space.N)                =  L_L.Eq.Shifted.mask.*real(t);
           Slv(L_L.Space.N+1:L_L.Space.N*2)  =  L_L.Eq.Shifted.mask.*imag(t);
           

           Slv                  = Newton_Switcher(Dir,Slv,L_L,Delta,@LLE_Full_Dispersion_Equation,options);
           
           

        L_L              = Prop_gen(L_L,Slv,Delta);
    
        figure;
        subplot(1,2,1);plot(abs(L_L.Solution.Psi).^2);
        subplot(1,2,2);plot(L_L.Space.k,10*log10(abs(L_L.Solution.E_j).^2));
        
end
