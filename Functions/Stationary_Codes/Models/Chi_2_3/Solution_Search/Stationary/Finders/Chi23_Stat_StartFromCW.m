function Res = Chi23_Stat_StartFromCW(Res)
    
    coeff_start = 0.0;
    Flag = false;
        
   W                 = [Res.CW.In.W/ Res.CW.In.Wf_Star, Res.CW.In.W/ Res.CW.In.Wf_Star];
   delta             = [10,Res.CW.In.delta_o/Res.CW.In.ko];
    
    Res.CW            = Chi23_CW_Track_fromLower2Point(Res.CW,W,delta);
  %  Res.CW            = Res.CW.Met.Solve(Res.CW);
%     Res.CW.Sol.Omega  = Res.CW.Sol.Omega(3);
%     Res.CW.Sol.Psi_o  = Res.CW.Sol.Psi_o(3);
%     Res.CW.Sol.Psi_e  = Res.CW.Sol.Psi_e(3);
    N                 = Res.Stat.In.N;
    
    Res.Stat.In       = Res.CW.In;
    Res.Stat.In.N     = N;    
    
    Res.Stat          = Res.Stat.Met.Norm(Res.Stat);
        
    Res.CW.Met.MI_Matrix   = @Chi23_MI_Matrix;
    Res.CW.Stab            =  Chi23_MI(Res.CW);
        dd = 0.5E-1;
    coeff = coeff_start-dd;
    for i_try = 1:1
        
        coeff_bound = coeff_start;
            ii   = 0;
        while Flag == 0

       %     coeff               = coeff_bound(1) + (coeff_bound(2) - coeff_bound(1))/2;
            coeff               = coeff  + dd;
            Res                 = Chi23_Turing_From_CW(Res,coeff);
            ii                  = ii + 1;
            Logic.p1            = Res.Stat.Sol.Exitflag >= 0;
            Logic.p2            = sum(abs(Res.Stat.Sol.Psi_o(2:end))) > 1E-3;

            if (Logic.p1 && Logic.p2) || (ii == 500)
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
        if Flag ~= 0
            break;
        end
    end


end