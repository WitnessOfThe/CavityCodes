function Temp = Chi_3_LLE_Dyn_Saving( F_e,Temp,ni)

    
    if ni == 0
    tic    
        Temp.Sol.Psi = zeros(Temp.Par.T/Temp.Par.s_t,size(Temp.In.Psi_Start,2));
        Temp.Sol.t   = zeros(1,Temp.Par.T/Temp.Par.s_t);
        
    elseif ( mod(ni,Temp.Par.s_t/Temp.Par.dt ) == 0) && (ni ~= 0)
    toc     
        
        Temp.Sol.Psi(round(ni*Temp.Par.dt/Temp.Par.s_t),:) = F_e/Temp.Space.N;
        Temp.Sol.t(  round(ni*Temp.Par.dt/Temp.Par.s_t))   = Temp.Par.dt*ni;
        
    tic
    end
    
end
