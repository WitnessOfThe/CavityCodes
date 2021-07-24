function Crystals = Chi3_CrystalCollect2DData(SP,ST,Var,indstep)
    
    SSP = strcat(SP,ST);
    tt = dir(SSP);
    NN = numel(dir(strcat(SSP,'*.mat')));
    NN =min(numel(tt([tt(:).isdir]))-2,NN);
    IndVec= 1:indstep:NN;
    parfor i = 1:size(IndVec,2)
        
        iSt = IndVec(i);
        NaiSt= IndexToChar(iSt+26^2*27+26);
        SSSP = strcat(SSP,NaiSt{1},'_Parameter',Var,'/');
        Crystals(i).Tracks = Chi3_CrystalCollect1DData(SSSP);
        
        iSt
        
    end
    
    save(strcat(SP,'Crystal',Var),'Crystals')
    
end