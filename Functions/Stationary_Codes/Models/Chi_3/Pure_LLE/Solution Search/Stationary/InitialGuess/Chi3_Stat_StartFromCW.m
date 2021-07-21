 function [Res,coeff] = Chi3_Stat_StartFromCW(Res)

    coeff_bound_s = [0,2];
    Flag = false;

    Res.CW            = Res.CW.Met.Solve(Res.CW);
%     if isnan(Res.CW.Sol.Psi(Res.Stat.Par.CW_num) )
%         if Res.Stat.Par.CW_num ==1
%             Res.Stat.Par.CW_num =3;
%         else
%             Res.Stat.Par.CW_num =1;
%         end
%     end
     N                 = Res.Stat.In.N_mode;
    Res.Stat.In       = Res.CW.In;
    Res.Stat.In.N_mode     = N;
    Res.Stat          = Res.Stat.Met.Norm(Res.Stat);


    coeff_bound = coeff_bound_s;
    ii          = 0;
    d = 1E-1;

    while Flag == 0
%ii*d;%
        coeff  = coeff_bound(1) + ii*d;%(coeff_bound(2) - coeff_bound(1))/2;
        Res.Stat.Par.In.Rel_ampl = coeff;

        Res                 = Chi3_LLE_Bloch_Stat_In_Guess_From_CW_Defined(Res);
        ii                  = ii + 1;

        Logic.p1            = Res.Stat.Sol.Exitflag >= 0;
        Logic.p2            = sum(abs(Res.Stat.Sol.Psi_k(2))) > 1E-4;

        if (Logic.p1 && Logic.p2) || (ii == 100)

            Flag =1;
            break;

        end

        if Logic.p1 == 1 && Logic.p2 == 0

    %        coeff_bound(1) = coeff;

        end
        if Logic.p1 == 0 && Logic.p2 == 1

            coeff_bound(2) = coeff;
            d = d/2;

        end
        if Logic.p1 == 0 && Logic.p2 == 0

            coeff_bound(2) = coeff;
            d = d/2;

        end

    end

  end
