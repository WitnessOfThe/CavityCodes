function Chi3_CrystalStartDynamicsFromMultiFolder(SSP,Var,Par)
    tt = dir(SSP);
    NN = numel(dir(strcat(SSP,'*.mat')));
 %   NN = min(numel(tt([tt(:).isdir]))-2,NN);
    
    for iSt = 1:NN
        
        NaiSt= IndexToChar(iSt+26^2*27+26);
        SSSP = strcat(SSP,NaiSt{1},'_Parameter',Var,'/');
        Chi3_CrystalStartDynamicsFromFolder(SSSP,Par)
        NN - iSt
    end
end