function SP = Chi3_CrystalPathGenerator(Stat,MP)

    SP = strcat(MP,'CrystalMu=',num2str(Stat.In.mu_bl),...
                        '_Fd=',num2str(round(Stat.In.D(2)/Stat.In.kappa,3)),...
                        '_Delta=',num2str(round(Stat.In.delta/Stat.In.kappa,3)),...
                        '_Power=',num2str(Stat.In.W_WStar),'/');
                    
    SpFDScan = strcat(SP,'/FDScan/');
    SpdeltaScan = strcat(SP,'/deltaScan/');
    SpFDDeltaScan = strcat(SP,'/FDDeltaScan/');
    
    if ~exist(SP,'dir')
        
        mkdir(SP)
        
    end
    
    if ~exist(SpFDDeltaScan ,'dir')
        
        mkdir(SpFDDeltaScan )
        
    end
    
    if ~exist(SpFDScan ,'dir')
        
        mkdir(SpFDScan )
        
    end
    if ~exist(SpdeltaScan ,'dir')
        
        mkdir(SpdeltaScan )
        
    end

end