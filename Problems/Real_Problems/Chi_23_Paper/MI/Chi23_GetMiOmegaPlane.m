function Save_Omega = Chi23_GetMiOmegaPlane(Res,epsilon_vector,omega_max,delta_max,delta_min,kvector,NNP,NND)

    for ii = 1:size(epsilon_vector,2)
        
        Res.CW.In.eps       = epsilon_vector(ii);
        Omega_Vector        = linspace(0,omega_max(ii),NNP)*Res.CW.In.Omega_Star;
        delta_vector        = linspace(delta_max(ii),delta_min(ii),NND)*Res.CW(1).In.ko;

        Save_Omega(ii).epsilon = epsilon_vector(ii);
        Save_Omega(ii).delta   = delta_vector;
        Save_Omega(ii).Omega   = Omega_Vector;
        
        for ik =1:size(kvector,2)
            
            CW              = Res.CW;
            CW.In.kMI       = kvector(ik); 
            Mumber          = zeros(NNP,NND);
            ReLam           = zeros(NNP,NND);
            
            parfor i_p = 1:NNP
                
                CWW = CW;
                
                for i_d = 1:NND

                    CWW.In.delta_o     = delta_vector(i_d);
                    CWW.Sol.Omega      = Omega_Vector(i_p);      
                    
                    [Mumber(i_p,i_d),ReLam(i_p,i_d)] =  Evaluate_MI_Omega(CWW);
                    %
                end  

            end
            
            kMI(ik).Res                  = Res;        
            kMI(ik).Mumber               = Mumber;
            
        end
        
        Save_Omega(ii).kMI = kMI;
        
    end
    

end
function [Mumber,Lam] =  Evaluate_MI_Omega(CW)

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
