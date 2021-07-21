 function [Res,coeff] = Chi3_Stat_StartFromCW(Res)
  
    coeff_bound_s = [1E-9,10];
    Flag = false;
            
    Res.CW            = Res.CW.Met.Solve(Res.CW);
    
    N                 = Res.Stat.In.N_mode;
    Res.Stat.In       = Res.CW.In;
    Res.Stat          = Res.Stat.Met.Norm(Res.Stat);
    Res.Stat.In.N     = N;    
    
        
    coeff_bound = coeff_bound_s;
    ii          = 0;
        
    while Flag == 0

        coeff  = coeff_bound(1) + (coeff_bound(2) - coeff_bound(1))/2;
        Res.Stat.Par.In.Rel_ampl = coeff;
        
        Res                 = Chi3_LLE_Bloch_Stat_In_Guess_From_CW_Defined(Res);
        ii                  = ii + 1;
        
        Logic.p1            = Res.Stat.Sol.Exitflag >= 0;
        Logic.p2            = sum(abs(Res.Stat.Sol.Psi_k(2))) > 1E-6;

        if (Logic.p1 && Logic.p2) || (ii == 70)
            
            Flag =1;
            break;

        end

        if Logic.p1 == 1 && Logic.p2 == 0

            coeff_bound(1) = coeff;

        end
        if Logic.p1 == 0 && Logic.p2 == 1

            coeff_bound(2) = coeff;

        end
        if Logic.p1 == 0 && Logic.p2 == 0

            coeff_bound(2) = coeff;

        end

    end

  end