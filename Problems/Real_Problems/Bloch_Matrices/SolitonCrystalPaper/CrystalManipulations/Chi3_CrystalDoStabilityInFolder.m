function Chi3_CrystalDoStabilityInFolder(SSSP)

    NN = numel(dir(strcat(SSSP,'*.mat')));
    
    parfor iSt = 1:NN
        
        PerformStability(SSSP,iSt);     
        
    end
    
end
function PerformStability(SSSP,iSt)

    NaiSt= IndexToChar(iSt+26^2*27+26);
    Stat = importdata(strcat(SSSP,NaiSt{1},'.mat'));
    if ~isfield(Stat,'Stab')
        Stat.Stab = Stability_Switcher(Stat);
    end
    save(strcat(SSSP,NaiSt{1},'.mat'),'Stat');
    
end