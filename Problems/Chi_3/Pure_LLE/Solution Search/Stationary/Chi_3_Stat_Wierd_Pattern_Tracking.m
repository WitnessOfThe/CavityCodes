function Stat =  Chi_3_Stat_Wierd_Pattern_Tracking(Stat,delta_vector,power_vector)

    for i = 1:size(delta_vector,2)
        
        Stat(i).In.delta = delta_vector(i);
        Stat(i).In.P     = power_vector(i);
        
        Stat(i)     = Stat(i).Met.Norm(Stat(i),Stat(i).Space.N);    
        
        x0                       =  Stat(i).Space.N*[real(Stat(i).In.Psi_Start),imag(Stat(i).In.Psi_Start),0];
        
        [x,eps_f,SolveFlag]      = Stat(i).Met.Newton(Stat(i),x0);
        
        Stat(i).Sol.Flag         =   SolveFlag;
        Stat(i).Sol.eps          =       eps_f;
        
        [i,eps_f,SolveFlag]
        
        Stat(i)                  = Chi3_LLE_Stat_Prop_Gen(x,Stat(i));    
      %  Stat(i)                  =    Stability_Switcher(Stat(i));
        
        if i ~= size(delta_vector,2)

            Stat(i+1)                         = Stat(i);
            Stat(i+1).Sol                     = [];
            Stat(i+1).In.Psi_Start(:)    =  Stat(i).Sol.Psi_k;

        end
        
    end
    
end
