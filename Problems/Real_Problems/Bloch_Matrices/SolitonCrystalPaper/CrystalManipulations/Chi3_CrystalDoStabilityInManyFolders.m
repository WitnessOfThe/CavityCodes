function Chi3_CrystalDoStabilityInManyFolders(SSP,Var)

    NN = numel(dir(strcat(SSP,'*.mat')));

    parfor iSt = 1:NN
        
        NaiSt= IndexToChar(iSt+26^2*27+26);
        SSSP = strcat(SSP,NaiSt{1},'_Parameter',Var,'/');
        tic
        Chi3_CrystalDoStabilityInFolder(SSSP);
        iSt
        toc
    end
end
