function CrystalTrack =  Chi3_CrystalReadDynamicsFromFolder(SSSP)
    if exist(strcat(SSSP,'Dynamics/') ,'dir')
        
        NN = numel(dir(strcat(SSSP,'Dynamics/','*.mat')));
    
        tt = dir(strcat(SSSP,'Dynamics/','*.mat'));
    
        parfor iSt = 1:NN
        
            CrystalTrack(iSt) = ReadData(strcat(strcat(tt(iSt).folder),'/',tt(iSt).name));     
        
        end
        
    else
        
        CrystalTrack(1).In  = NaN;
        CrystalTrack(1).Eq  = NaN;
        CrystalTrack(1).Sol = NaN;
        
    end
    
end
function Crystal = ReadData(SSSP)

    Temp = importdata(SSSP);
    
    
    Crystal.In   = Temp.In;
    Crystal.Eq   = Temp.Eq;
    Crystal.Sol  = Temp.Sol;
    
end