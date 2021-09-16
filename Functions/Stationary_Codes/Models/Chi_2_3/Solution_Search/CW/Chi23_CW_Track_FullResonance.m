function CW = Chi23_CW_Track_FullResonance(CW,W,delta)    
    
    NN = 1000;
    delta_vector          = linspace(delta(1),delta(2),NN);
    W_vector              = linspace(W(1),W(2),NN);
    
    CW.In.W               = W(1)*CW.In.W_Star;        
    CW.In.delta_o         = delta(1)*CW.In.ko;        
    
    CW                    = CW.Met.Solve_Chi2(CW); 

    [~,ind]               = min(abs(CW.Sol.Omega));

    CW.Sol.Omega      =  CW.Sol.Omega(ind);    
    CW.Sol.Psi_o      =  CW.Sol.Psi_o(ind);    
    CW.Sol.Psi_e      =  CW.Sol.Psi_e(ind);
    
    Exit = 0;    
    sg = 1;
    dd = 1E-2;
    
    while Exit == 0
            
            CW.In.delta_o    =  CW.In.delta_o + sg*dd*CW.In.ko;            
            CW.In.W          = W_vector(i_d)*CW.In.W_Star;            
            CW               = CW.Met.Norm(CW);  
            Psi_1              = real(CW.Sol.Psi_o(1));
            [Slv,eps_f,Exitflag] = Newton_Switcher([real(CW.Sol.Psi_o(1)),imag(CW.Sol.Psi_o(1)),real(CW.Sol.Psi_e(1)),imag(CW.Sol.Psi_e(1))],CW);
            CW                   = CW.Met.Prop_Gen(Slv,CW);          
            Psi_2                = real(CW.Sol.Psi_o(1));
            
            if eps_f > 1E-5                
                
            end
             
            if abs(CW.In.delta_o) > abs(delta(2)*CW.In.ko)
                  break;
            end
    end
        
    end
 