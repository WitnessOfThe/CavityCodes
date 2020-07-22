function Field = Real_Field(E_j,N_min,N_max)
    % N_min mode number in arrat
    Field_half = zeros(1,N_max/2);
    Field_conj = zeros(1,N_max/2);
    
    Field_half(N_min:(size(E_j,2)-1 + N_min) ) = E_j;
    Field_conj(2:N_max/2 )         = conj(flip(Field_half(2:end)));
    
    Field                           = ifft([Field_half,Field_conj],'symmetric')*N_max; 
    
end

    