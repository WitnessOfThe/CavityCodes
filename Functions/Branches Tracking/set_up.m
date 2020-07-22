    function [x_0,Slv,Equation] = set_up(L_L,Delta,options)
    
        switch Delta.variable
            
            case 'delta'
                
                x_0 = L_L.Eq.delta;
                
            case 'gamma'
                
                x_0 = L_L.Eq.gamma;
                
            case 'h'
                
                x_0 = L_L.Eq.h;
                
            case 'd'
                
                x_0 = L_L.Eq.d;
                
            case 'V'
                
                x_0 = L_L.Eq.V;                

        end
        
                Slv_start       =   Delta.Initial_Guess;
                Equation        =   Delta.Equation;
                Slv             =   Slv_start(L_L,Delta,options);
                
    end
