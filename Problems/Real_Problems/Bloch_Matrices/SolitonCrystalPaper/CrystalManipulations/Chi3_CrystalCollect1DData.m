function CrystalTrack =  Chi3_CrystalCollect1DData(SSSP)

    NN = numel(dir(strcat(SSSP,'*.mat')));
    
    parfor iSt = 1:NN
        
        CrystalTrack(iSt) = ReadData(SSSP,iSt);     
        
    end
    
end
function Crystal = ReadData(SSSP,iSt)

    NaiSt= IndexToChar(iSt+26^2*27+26);
    Stat = importdata(strcat(SSSP,NaiSt{1},'.mat'));
    
    Stat.In.omega = [];
    Stat.In.omega_int = [];
    Stat.In.Psi_Start = [];
    
    Stat.Eq.gamma_Kerr = [];
    Stat.Eq.L = [];
    Stat.Eq.mode_range = [];
    Stat.Eq.mask = [];
    Stat.Eq.kappa_vector = [];
    Stat.Eq.omega_j = [];
    
    Crystal.In   = Stat.In;
    Crystal.Eq   = Stat.Eq;
    Crystal.Sol  = Stat.Sol;
    
    if isfield(Stat,'Stab')
        
        Crystal.Stab.NMode = sum(sum(real(Stat.Stab.Values(:,:)>0)));
        Crystal.Stab.MaxRe = max(max(real(Stat.Stab.Values(:,:))));
        Crystal.Stab.kmax  = max(max(real(Stat.Stab.Values(:,:))));
        
        if real(Crystal.Stab.MaxRe) > 1

            [t_raw,t_col]      = find(real(Stat.Stab.Values(:,:)) == Crystal.Stab.MaxRe);
            Crystal.Stab.MaxRe = Stat.Stab.Values(t_raw(1),t_col(1));
            Crystal.Stab.kmax  = Stat.Stab.k(t_raw(1));
            Crystal.Stab.lamk0 = Stat.Stab.Values(1,real(Stat.Stab.Values(1,:))  == max( real(Stat.Stab.Values(1,:))) );
        else

            Crystal.Stab.MaxRe = 0;
            Crystal.Stab.kmax  = NaN;
        end
    
    else
        Crystal.Stab.NMode = NaN;
        Crystal.Stab.MaxRe = NaN;
    end
end