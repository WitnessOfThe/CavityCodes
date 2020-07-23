function   L_L  =  Define_Space_Cavity(L_L,N,L)
% L_L is the input Class
% N   is the number of Grid Points
% L   is the Cavity Lenght

        L_L.Space.N        = N;
        L_L.Space.lenght   = L;
        L_L.Space.dphi     = L_L.Space.lenght/L_L.Space.N;
        L_L.Space.phi      = L_L.Space.dphi*( - L_L.Space.N/2:1:L_L.Space.N/2-1);
        L_L.Space.dk       = 2*pi/L_L.Space.lenght;   
        L_L.Space.k        = L_L.Space.dk*[0:L_L.Space.N/2-1, -L_L.Space.N/2:-1];
        
end