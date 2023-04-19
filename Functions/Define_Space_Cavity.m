function   Space  =  Define_Space_Cavity(N,L)
% N   is the number of Grid Points
% L   is the Cavity Lenght

        Space.N        = N;
        Space.lenght   = L;
        Space.dphi     = Space.lenght/Space.N;
%        Space.phi      = Space.dphi*( 0:1:Space.N-1);
        Space.phi      = Space.dphi*( 0:1:Space.N-1);
        Space.dk       = 2*pi/Space.lenght;   
        Space.k        = Space.dk*[0:Space.N/2-1, -Space.N/2:-1];
        
end