function Stat = Chi3_LLE_Stat_Prop_Gen(x0,Stat)

   if mod(size(x0,2),2) == 0 
        
        Stat.Sol.V     = 0;
        N              = (size(x0,2))/2;
        
   else
        N              = (size(x0,2)-1)/2;
        Stat.Sol.V     = x0(end);
   end
    Stat.Sol.Psi_k = (x0(1:N) + 1i*x0(N+1:2*N))/N;
    
end