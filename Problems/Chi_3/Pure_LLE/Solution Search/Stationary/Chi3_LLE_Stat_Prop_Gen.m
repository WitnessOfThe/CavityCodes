function Stat = Chi3_LLE_Stat_Prop_Gen(x0,Stat)

    N              = (size(x0,2)-1)/2;
    Stat.Sol.Psi_k = (x0(1:N) + 1i*x0(N+1:2*N))/N;
    Stat.Sol.V     = x0(end);
    
end