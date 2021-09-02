function Save_Power = Chi23_GetMiPowerPlane(Res,epsilon_vector,Power_max,delta_max,delta_min,kvector,NNP,NND)


    switch func2str(Res.CW.Met.MI_Matrix)
        
        case 'Chi2_MI_Matrix'
            
            Res.CW.In.gam3o          = 0;
            Res.CW.In.gam3e          = 0;
                                    
    end
    for ii = 1:size(epsilon_vector,2)
        
        Res.CW.In.eps       = epsilon_vector(ii);
        Power_Vector        = 10.^(linspace(-30,10*log10(Power_max),NNP)/10);
        delta_vector        = linspace(delta_min(ii),delta_max(ii),NND)*Res.CW(1).In.ko;

        Save_Power(ii).epsilon = epsilon_vector(ii);
        Save_Power(ii).delta   = delta_vector;
        Save_Power(ii).Power   = Power_Vector;
        
        for ik =1:size(kvector,2)
            
            CW              = Res.CW;
            CW.In.kMI       = kvector(ik); 
            Mumber          = NaN(NNP,NND);
            ReLam           = NaN(NNP,NND);
            
            parfor i_p = 1:NNP
                
                CWW = CW;
                CWW.In.W = Power_Vector(i_p);
                
                [CWW,S]          = Chi23_CW_TrackToPoint(CWW,...
                                    [CWW.In.W,CWW.In.W]/CWW.In.Wf_Star,...
                                      [delta_min,delta_max],NND);
                
                for i_d = 1:NND

                    CWW.In.delta_o     = S.deltaVect(i_d)*CWW.In.ko;
                    CWW.Sol.Psi_o      = S.PsiO(i_d);
                    CWW.Sol.Psi_e      = S.PsiE(i_d); 
                    CWW.Sol.Omega      = S.Omega(i_d); 
                    
                    if isnan( CWW.Sol.Psi_o)
                        
                        break;
                        
                    end
                    
                    [Mumber(i_p,i_d),ReLam(i_p,i_d)] =  Evaluate_MI_Power(CWW);
                    
                end

            end
            
            kMI(ik).Res                  = Res;        
            kMI(ik).Mumber               = Mumber;
            
        end
        
        Save_Power(ii).kMI = kMI;
        
    end
    

end
function [Mumber,Lam] =  Evaluate_MI_Power(CW)

    CW            = CW.Met.Norm(CW);
    CW.Stab       = Chi23_MI(CW);

    [ReLam]       = max(real(CW.Stab.Value),[],'all');
    [i1,i2]       = find(real(CW.Stab.Value) == ReLam);

    Lam           = CW.Stab.Value(i1(1),i2(1));

    if ReLam > 1E-6

        Mumber = 1;

    else

        Mumber = 0;

    end

end
