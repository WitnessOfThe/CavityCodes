function Res = Chi_3_Stat_In_Guess_LLE_From_EigenVectors(Res)    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    x0                       = Res.Stat.Space.N*[real(Res.Stat.In.Psi_Start),...
                                            imag(Res.Stat.In.Psi_Start),0];
                                        
    [x,eps_f,SolveFlag]      =   Res.Stat.Met.Newton(Res.Stat,x0);
    eps_f
    
    Res.Stat                 = Chi3_LLE_Stat_Prop_Gen(x,Res.Stat);    
    
    Res.Stat.Stab            =       Stability_Switcher(Res.Stat);
    
    Res.Stat.In.Psi_Start    = ( Res.Stat.Sol.Psi_k + ...
                      (Res.Stat.Stab.E_vectors(1:Res.Stat.Space.N,1).'+...
    conj(Res.Stat.Stab.E_vectors(Res.Stat.Space.N+1:Res.Stat.Space.N*2,1)).'));                       
    
    x0                       = Res.Stat.Space.N*[real(Res.Stat.In.Psi_Start),...
                                            imag(Res.Stat.In.Psi_Start),0];
    
    [x,eps_f,SolveFlag]      =   Res.Stat.Met.Newton(Res.Stat,x0);
    eps_f


    Res.Stat                 = Chi3_LLE_Stat_Prop_Gen(x,Res.Stat);    
    
    
    Res.Stat.Sol.Flag        = SolveFlag;
    Res.Stat.Sol.eps         =     eps_f
                                   
    
end
