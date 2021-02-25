function Res = Chi23_Turing_From_CW(Res,coeff)
    
    Res.Stat              = Res.Stat.Met.Norm(Res.Stat);
        
    Res.CW.Met.MI_Matrix   = @Chi23_MI_Matrix;
    Res.CW.Stab            =  Chi23_MI(Res.CW);
    Res.Stat.Sol.Psi_o     =  1E-10*ones(1,Res.Stat.Space.N);
    Res.Stat.Sol.Psi_e     =  1E-10*ones(1,Res.Stat.Space.N);
    
    
%    [i_k,i_c] = find(real(Res.CW.Stab.Value) == max(max(real(Res.CW.Stab.Value))));
    i_k = Res.Stat.In.mu_bl+1;
    i_k = find(abs(Res.Stat.Space.k) == abs(Res.Stat.Space.k(i_k)));
    
    i_c = zeros(1,2);
    
    [~,i_c(1)]  = max(real(Res.CW.Stab.Value(i_k(1),:)) );
    [~,i_c(2)]  = max(real(Res.CW.Stab.Value(i_k(2),:)) );
    
    Res.Stat.Sol.Psi_o(1)  = Res.CW.Sol.Psi_o*Res.Stat.Space.N;       
    Res.Stat.Sol.Psi_e(1)  = Res.CW.Sol.Psi_e*Res.Stat.Space.N;      
    
%   coeff = 1.51;
    
    Res.Stat.Sol.Psi_o(2)  = (Res.CW.Stab.Vector(i_k(1)).V(1,i_c(1))  )*coeff*Res.Stat.Space.N;       %+ Res.CW.Stab.Vector(i_k(2)).V(1,i_c(2) )
    Res.Stat.Sol.Psi_e(2)  = (Res.CW.Stab.Vector(i_k(1)).V(2,i_c(1)))*coeff*Res.Stat.Space.N;     %+ Res.CW.Stab.Vector(i_k(2)).V(2,i_c(2) )
    
    Res.Stat.Sol.Psi_o(end)  = (Res.CW.Stab.Vector(i_k(1)).V(3,i_c(1)) )*coeff*Res.Stat.Space.N;       %+ Res.CW.Stab.Vector(i_k(2)).V(3,i_c(2))
    Res.Stat.Sol.Psi_e(end)  = (Res.CW.Stab.Vector(i_k(1)).V(4,i_c(1)))*coeff*Res.Stat.Space.N;    %+ Res.CW.Stab.Vector(i_k(2)).V(4,i_c(2))  
    
    Res.Stat.Sol.Psi_o           = ifft(Res.Stat.Sol.Psi_o);
    Res.Stat.Sol.Psi_e           = ifft(Res.Stat.Sol.Psi_e);
    
    if Res.CW.In.eps >= 0
        
        sg = -1;
        
    else
        
        sg = 1;
        
    end
    Slv_Start               = [real(Res.Stat.Sol.Psi_o),imag(Res.Stat.Sol.Psi_o)...
                    ,real(Res.Stat.Sol.Psi_e),imag(Res.Stat.Sol.Psi_e),sg*abs(imag(Res.CW.Stab.Value(i_k(1),i_c(1))))/Res.Stat.In.mu_bl];
    
    [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Res.Stat);
    
    Res.Stat.Sol.Psi_o   = fft(Slv(1:Res.Stat.Space.N) + 1i*Slv(Res.Stat.Space.N+1:2*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.Psi_e   = fft(Slv(2*Res.Stat.Space.N+1:3*Res.Stat.Space.N) + 1i*Slv(3*Res.Stat.Space.N+1:4*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.V       = Slv(end);
    Res.Stat.Sol.eps_f   = eps_f;
    Res.Stat.Sol.Exitflag= Exitflag;
  
    switch Res.Stat.Par.Stability

        case 1

            Res.Stat.Sol.Linear_Stability = struct;
            Res.Stat.Stab                 = Stability_Switcher(Res.Stat);

        case 0

            Res.Stat.Stab.E_values  = NaN;
            Res.Stat.Stab.E_vectors = NaN;

    end    
end