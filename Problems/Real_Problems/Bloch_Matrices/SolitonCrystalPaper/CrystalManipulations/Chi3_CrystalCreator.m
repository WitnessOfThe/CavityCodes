function R = Chi3_CrystalCreator(R,MP)

    R.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    R.Stat.Met.Newton               = @Newton_Manual_bicgstab;

    R.Stat(1).Par.Newton_tol       = 3E-11;  
    R.Stat(1).Par.Stability        = 0;    
    R.Stat(1).Par.Newton_iter      = 200;

    SP = Chi3_CrystalPathGenerator(R.Stat,MP);
    
    [R,coeff] = Chi3_Stat_StartFromCW(R);
    Stat = R.Stat;
    save(strcat(SP,'Starter.mat'),'Stat');
    
end
