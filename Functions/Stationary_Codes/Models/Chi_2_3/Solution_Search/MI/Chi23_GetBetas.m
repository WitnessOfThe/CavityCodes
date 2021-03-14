function Stab = Chi23_GetBetas(CW,mxmn)    
    CW = CW.Met.Norm(CW)
    Dfp = CW.In.delta_o + 1/2*CW.Space.k.^2*CW.In.Do(2);
    Dsp = CW.In.delta_e + CW.Space.k*(CW.In.De(1) - CW.In.Do(1))+ 1/2*CW.Space.k.^2*CW.In.Do(2);
    
    Dfm = CW.In.delta_o + 1/2*CW.Space.k.^2*CW.In.Do(2);
    Dsm = CW.In.delta_e - CW.Space.k*(CW.In.De(1) - CW.In.Do(1))+ 1/2*CW.Space.k.^2*CW.In.De(2);
    
    CW  = Chi2_CW(CW);
    Om =     mxmn(CW.Sol.Omega);
    OmMup = sqrt( (Dfp - Dsp).^2 + abs(Om).^2 );
    OmMum = sqrt( (Dfm - Dsm).^2 + abs(Om).^2 );
    
    Stab.beta(1,:) = 1/2*( Dfp + Dsp )  + 1/2*OmMup;
    Stab.beta(2,:) = 1/2*( Dfp + Dsp )  - 1/2*OmMup;
    Stab.beta(3,:) = -1/2*( Dfm + Dsm ) + 1/2*OmMum;
    Stab.beta(4,:) = -1/2*( Dfm + Dsm ) - 1/2*OmMum;

        
end
