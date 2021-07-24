function Crystals =Chi3_CrystalReadDynamicsFromMultiFolder(SSP,Var)
    NN = numel(dir(strcat(SSP,'*.mat')));
 %   NN = min(numel(tt([tt(:).isdir]))-2,NN);
    
    for iSt = 1:NN
        
        NaiSt= IndexToChar(iSt+26^2*27+26);
        SSSP = strcat(SSP,NaiSt{1},'_Parameter',Var,'/');
        Crystals(iSt).Tracks = Chi3_CrystalReadDynamicsFromFolder(SSSP);
        iSt
    end
end