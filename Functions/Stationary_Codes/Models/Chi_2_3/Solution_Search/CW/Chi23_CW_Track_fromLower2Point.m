function CW = Chi23_CW_Track_fromLower2Point(CW,W,delta)    
    
    NN = 100;
    delta_vector          = linspace(delta(1),delta(2),NN);
    W_vector              = linspace(W(1),W(2),NN);
    
    CW.In.W               = W(1)*CW.In.Wf_Star;        
    CW.In.delta_o         = delta(1)*CW.In.ko;        
    
    CW                    = CW.Met.Solve_Chi2(CW); 

    [~,ind]               = min(abs(CW.Sol.Omega));
%ind =2;
    CW.Sol.Omega      =  CW.Sol.Omega(ind);    
    CW.Sol.Psi_o      =  CW.Sol.Psi_o(ind);    
    CW.Sol.Psi_e      =  CW.Sol.Psi_e(ind);

        for i_d = 1:NN

            CW.In.delta_o        = delta_vector(i_d)*CW.In.ko;            
            CW.In.W              = W_vector(i_d)*CW.In.Wf_Star;            
            CW                   = CW.Met.Norm(CW);  
            [Slv,eps_f,Exitflag] = Newton_Switcher([real(CW.Sol.Psi_o(1)),imag(CW.Sol.Psi_o(1)),real(CW.Sol.Psi_e(1)),imag(CW.Sol.Psi_e(1))],CW);
            CW                   = CW.Met.Prop_Gen(Slv,CW);          
            
            if eps_f > 1E-5
                
                break;
                
            end        
        end
        
    end
 