function [CW,S] = Chi23_CW_TrackToPoint(CW,W,delta,NN)    
    
    delta_vector          = linspace(delta(1),delta(2),NN);
    W_vector              = linspace(W(1),W(2),NN);
    
    CW.In.W           = W(1);        
    CW.In.delta       = delta(1)*CW.In.ko;        
    
    CW                = CW.Met.Solve_Chi2(CW); 
    [~,ind]               = min(abs(CW.Sol.Omega));
    
    CW.Sol.Omega      =  CW.Sol.Omega(ind);    
    CW.Sol.Psi_o      =  CW.Sol.Psi_o(ind);    
    CW.Sol.Psi_e      =  CW.Sol.Psi_e(ind);

    S.deltaVect       = delta_vector;
    
    S.PsiO            = NaN(1,NN);
    S.PsiE            = NaN(1,NN);
    S.Omega           = NaN(1,NN);
     S.delta          = delta_vector ;
    for i_d = 1:NN

        CW.In.delta_o    = delta_vector(i_d)*CW.In.ko;            
        CW.In.W          = W_vector(i_d);            
        CW               = CW.Met.Norm(CW);  
        [Slv,eps_f,~] = Newton_Switcher([real(CW.Sol.Psi_o(1)),imag(CW.Sol.Psi_o(1)),real(CW.Sol.Psi_e(1)),imag(CW.Sol.Psi_e(1))],CW);
        CW               = CW.Met.Prop_Gen(Slv,CW);          

        
        if eps_f > 1E-5
            
            CW.Sol.Psi_o      =  NaN;    
            CW.Sol.Psi_e      =  NaN;

           break;

        end        
        
        S.PsiO(i_d)            = CW.Sol.Psi_o;
        S.PsiE(i_d)            = CW.Sol.Psi_e;
        S.Omega(i_d)           = CW.Sol.Omega;
        
    end
        
end
