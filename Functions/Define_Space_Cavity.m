function   Space  =  Define_Space_Cavity(N,L)
% L_L is the input Class
% N   is the number of Grid Points
% L   is the Cavity Lenght

        Space.N        = N;
        Space.lenght   = L;
        Space.dphi     = Space.lenght/Space.N;
        Space.phi      = Space.dphi*( - Space.N/2:1:Space.N/2-1);
        Space.dk       = 2*pi/Space.lenght;   
        Space.k        = Space.dk*[0:Space.N/2-1, -Space.N/2:-1];
        
end