    function Res = Chi23_Turing_From_CW(Res,coeff)
    
    Res.Stat.Sol.Psi_o     =  1E-10*ones(1,Res.Stat.Space.N);
    Res.Stat.Sol.Psi_e     =  1E-10*ones(1,Res.Stat.Space.N);
    
    
%    [i_k,i_c] = find(real(Res.CW.Stab.Value) == max(max(real(Res.CW.Stab.Value))));
%    if Res.CW.In.eps >= 0
        
 %       sg = -1;
  %      i_k = Res.Stat.Space.N-Res.Stat.In.mu_bl+1;% Res.Stat.In.mu_bl+1;
        
   % else
        
    %    sg = 1;        
 %        i_k = +1;% Res.Stat.In.mu_bl+1;
   
    %end
    
    i_kp = find(Res.CW.In.kMI ==  Res.Stat.In.mu_bl);
    i_km = find(Res.CW.In.kMI == -Res.Stat.In.mu_bl);
    
    
    [~,i_Vp]  = max(real(Res.CW.Stab.Value(i_kp(1),:)) );
    [~,i_Vm]  = max(real(Res.CW.Stab.Value(i_km(1),:)) );
    
    Res.Stat.Sol.Psi_o(1)  = Res.CW.Sol.Psi_o;       
    Res.Stat.Sol.Psi_e(1)  = Res.CW.Sol.Psi_e;      
    
    Res.Stat.Sol.Psi_o(2)  = Res.CW.Stab.Vector(i_kp).V(1,i_Vp)*coeff;       %+ Res.CW.Stab.Vector(i_k(2)).V(1,i_c(2) )    
    %Res.Stat.Sol.Psi_e(2)  = Res.CW.Stab.Vector(i_Vp(1)).V(3,i_Vp)*coeff;     %+ Res.CW.Stab.Vector(i_k(2)).V(2,i_c(2) )
    
    Res.Stat.Sol.Psi_o(end)  = Res.CW.Stab.Vector(i_km).V(1,i_Vm)*coeff;       %+ Res.CW.Stab.Vector(i_k(2)).V(1,i_c(2) )    
  %  Res.Stat.Sol.Psi_e(end)  = Res.CW.Stab.Vector(i_Vm(1)).V(3,i_Vm)*coeff;     %+ Res.CW.Stab.Vector(i_k(2)).V(2,i_c(2) )
            
    Res.Stat.Sol.Psi_o           = ifft(Res.Stat.Sol.Psi_o*Res.Stat.Space.N);
    Res.Stat.Sol.Psi_e           = ifft(Res.Stat.Sol.Psi_e*Res.Stat.Space.N);
    
    V = (imag(Res.CW.Stab.Value(i_kp(1),i_Vp)) - imag(Res.CW.Stab.Value(i_km(1),i_Vm)))/2/Res.Stat.In.mu_bl;
    Slv_Start               = [real(Res.Stat.Sol.Psi_o),imag(Res.Stat.Sol.Psi_o)...
                    ,real(Res.Stat.Sol.Psi_e),imag(Res.Stat.Sol.Psi_e),V];%

    [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Res.Stat);
    
    Res.Stat.Sol.Psi_o   = fft(Slv(1:Res.Stat.Space.N) + 1i*Slv(Res.Stat.Space.N+1:2*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.Psi_e   = fft(Slv(2*Res.Stat.Space.N+1:3*Res.Stat.Space.N) + 1i*Slv(3*Res.Stat.Space.N+1:4*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.V       = Slv(end);
    
    Res.Stat.Sol.eps_f   = eps_f;
    Res.Stat.Sol.Exitflag= Exitflag;
  
    switch Res.Stat.Par.Stability

        case 1

            Res.Stat.Stab                 = Stability_Switcher(Res.Stat);

        case 0

            Res.Stat.Stab.E_values  = NaN;
            Res.Stat.Stab.E_vectors = NaN;

    end    
end