function L_L = Chi3_LLE_Bloch_Stat_In_Guess_From_CW_Defined(L_L,N_Mode)

    L_L.CW.In                       = L_L.Stat.In;
    
    L_L.Stat                        = L_L.CW.Met.Norm(L_L.Stat,N_Mode);    
    L_L.CW                          = L_L.CW.Met.Norm(L_L.CW,2^8);    
    
    
    L_L.CW                          = MI(L_L.CW,2^8);
    L_L.CW.In.g                     = L_L.CW.Sol.g(L_L.Stat.Par.CW_num)*L_L.Stat.Eq.norm;
    
    L_L.CW                          = L_L.CW.Met.Mi_Formula(L_L.CW,2^8); 
    
    
    
    ind(1)                          =  find(L_L.CW.Space.k == L_L.Stat.In.mu_bl(1));
    ind(2)                          =  find(L_L.CW.Space.k == -L_L.Stat.In.mu_bl(1));
  %  ind(3)                          =  find(L_L.CW.Space.k == 2*L_L.Stat.In.mu_bl(1));
 %   ind(4)                          =  find(L_L.CW.Space.k == 2*L_L.Stat.In.mu_bl(2));
    
    
    for i = 1:4
        
        if i>1 
            
            L_L.Stat(i) = L_L.Stat(i-1); 
            
        end
        
        L_L.Stat(i)                        = L_L.Stat(i).Met.Norm(L_L.Stat(i),N_Mode);    
        L_L.Stat(i).In.Psi_Start           = zeros(1,N_Mode)*1E-10;
        
        L_L.Stat(i).In.Psi_Start(1)      = L_L.CW.Sol.Psi(L_L.Stat(i).Par.CW_num);    
        
        L_L.Stat(i).In.Psi_Start(2)   = L_L.CW.Stab(3).Vector(ind(1)).Vect(i);
        L_L.Stat(i).In.Psi_Start(end) = L_L.CW.Stab(3).Vector(ind(2)).Vect(i);

 %      L_L.Stat(i).In.Psi_Start(ind(3)) = L_L.CW.Stab(3).Vector(ind(1)).Vect(i);
 %      L_L.Stat(i).In.Psi_Start(ind(4)) = L_L.CW.Stab(3).Vector(ind(2)).Vect(i);
        
        L_L.Stat(i).In.t_start      = 0;
        
        vel =   (imag(L_L.CW.Stab(3).Value(ind(2))) ...
            - imag(L_L.CW.Stab(3).Value(ind(1))))/2/L_L.Stat(i).In.mu_bl/L_L.Stat(i).Space.N;
        
        x0                       = [real(L_L.Stat(i).In.Psi_Start)...
            ,imag(L_L.Stat(i).In.Psi_Start),vel ]*L_L.Stat(i).Space.N;
    
        [x,eps_f,SolveFlag]         =    L_L.Stat(i).Met.Newton(L_L.Stat(i),x0);
        L_L.Stat(i).Sol.Flag        =    SolveFlag;
        L_L.Stat(i).Sol.eps         =        eps_f;
    
        eps_f      
        L_L.Stat(i)                 = L_L.Stat(i).Met.Prop_Gen(x,L_L.Stat(i));    
        
    end
    
end
