function Temp = Chi_3_LLE_Dyn_Saving( F_e,Temp,ni)

    if ni == 0
        
        Temp.Sol.Psi = zeros(Temp.Par.T/Temp.Par.s_t,size(Temp.In.Psi_Start,2));
        Temp.Sol.t   = zeros(1,Temp.Par.T/Temp.Par.s_t);
        
    elseif (mod(ni,Temp.Par.s_t ) == 0) && (ni ~= 0)
        
        Temp.Sol.Psi(floor(ni*Temp.Par.dt/Temp.Par.s_t)+1,:) = F_e;
        Temp.Sol.t(floor(ni*Temp.Par.dt/Temp.Par.s_t)+1)   = Temp.Par.dt*ni;
        
        
    end
    
end