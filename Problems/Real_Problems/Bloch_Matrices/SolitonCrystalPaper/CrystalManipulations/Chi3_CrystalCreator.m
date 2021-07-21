function [Stat,coeff] = Chi3_CrystalCreator(R,MP,i)

    R.Stat.Par.Equation_string      = 'Kerr_Full_Dispersion';    
    R.Stat.Met.Newton               = @Newton_Manual_bicgstab;

    R.Stat(1).Par.Newton_tol       = 1E-10;  
    R.Stat(1).Par.Stability        = 0;    
    R.Stat(1).Par.Newton_iter      = 200;

    
    [R,coeff] = Chi3_Stat_StartFromCW(R);
    Stat = R.Stat;
    if i == 0
        SP = Chi3_CrystalPathGenerator(R.Stat,MP);
        save(strcat(SP,'Starter.mat'),'Stat');
    else
%        SP = Chi3_CrystalPathGenerator(R.Stat,MP);
        NaiSt= IndexToChar(i+26^2*27+26);
        save(strcat(MP,NaiSt{1},'.mat'),'Stat');
    end
end
