function S = Chi3_Start_FromBlochVector(S,k)

    
    Space = Define_Space_Cavity(2^10,2*pi);
    Ish  = find(S.Stab.k == k);
    
    Soliton   = TransferToResontor(S.Sol.Psi_k,S.In.mu_bl);      
    
    Vect1 = fft(ifft(TransferToResontor(S.Stab.Vk(Ish).Vectors(1:S.Space.N,1),S.In.mu_bl)).*exp(1i*Space.phi*k));   
    
    coef  = 1E-2;
    Vect1 = Vect1/max(Vect1)*coef;
    Ish  = find(S.Stab.k == -k);
    Vect2 = fft(ifft(TransferToResontor(S.Stab.Vk(Ish).Vectors(S.Space.N+1:S.Space.N*2,1),S.In.mu_bl)).*exp(-1i*Space.phi*k));
    
    Vect2 = Vect2/max(Vect2)*coef;
    
    Soliton  = Soliton + Vect1+Vect2;
    
    S.In.mu_bl = 1;
    S.In.N_mode     = 2^10;
    S          = S.Met.Norm(S);    
    x0         = [real(Soliton),imag(Soliton),1E-3]*S.In.N_mode;

    [x,eps_f,SolveFlag] =    Newton_Switcher(x0,S);
    S.Sol.Exitflag      =                SolveFlag;
    S.Sol.eps           =                    eps_f;
    
    S                 = S.Met.Prop_Gen(x,S);    
    
end
function Psi = TransferToResontor(Psimu,mubl)

    
    Psi     = 1E-12*ones(1,2^10);
    Psi(1)  = Psimu(1);
    for i = 1:floor(2^10/mubl/2)
        Psi(1+mubl*i)     =   Psimu(i+1);
        Psi(end-mubl*i+1) =   Psimu(end+1-i);
    end

end
