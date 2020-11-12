function In = Params_SiN_Modes(Mode_number,N_mode)

    In.eta             = 0.5;                                       
    Space              = Define_Space_Cavity(N_mode,2*pi);
    D                  = 2*pi*[1E12,20E6,0,-120E3,5.3E3,-150];
    
    Dir = Finite_Derivatives(N_mode,1); 
    
    In.omega       = 193E12*2*pi;
    
    for i = 1:size(D,2)
            
           In.omega = In.omega + Space.k.^i.*...
           D(i)/factorial(i);
           
    end
    
    In.omega   = circshift(In.omega,Mode_number);
    In.omega_p = In.omega(1);
    In.omega   = In.omega - In.omega_p;
    
    D_1        = Dir.d1*fftshift(In.omega).';
    D_2        = Dir.d2*fftshift(In.omega).';
    
    In.D(1)    =  D_1(N_mode/2+1);
    In.D(2)    =  D_2(N_mode/2+1);
      
    In.omega_int = In.omega - Space.k*In.D(1);

    In.gamma           = 20E6*2*pi;        
    In.range           =  100;
    
end