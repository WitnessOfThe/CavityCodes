function Crystals = Chi3_CrystalCollect2DData(SSP,Var)
    
    
    NN = numel(dir(strcat(SSP,'*.mat')));

    for iSt = 1:NN
        
        NaiSt= IndexToChar(iSt+26^2*27+26);
        SSSP = strcat(SSP,NaiSt{1},'_Parameter',Var,'/');
        Crystals(iSt).Tracks = Chi3_CrystalCollect1DData(SSSP);
        iSt
    end

end