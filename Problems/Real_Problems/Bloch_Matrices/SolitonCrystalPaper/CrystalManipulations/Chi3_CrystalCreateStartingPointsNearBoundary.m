function Stat = Chi3_CrystalCreateStartingPointsNearBoundary(R,FDVec,MP)

    CW  = R.CW;
    NN = size(FDVec,2);
    
    parfor i = 1:NN
        
        warning('off');
        
        CWW = CW;
        
        CWW.In.kappa       = CWW.In.D(2)/FDVec(i);
        CWW.In.delta       = -CWW.In.kappa*1.5;
        CWW.In.P           = R.Stat.In.W_WStar*pi/(CWW.In.eta*CWW.In.D(1)/CWW.In.kappa)*CWW.In.kappa/CWW.In.gamma;  
        
        [delta,FlagSide] = Get_MuDeltaTreshold(CWW);
        
        RR = R;
        RR.CW.In      = CWW.In; 
        RR.CW.In.delta = delta*CWW.In.kappa-0.1E-3*FlagSide*CWW.In.kappa;
%        RR.Stat.In.W     = W;
       
        Stat(i) =Chi3_CrystalCreator(RR,MP,i);
        [i,Stat(i).Sol.eps_f]
    end
end

function [delta,FlagSide] = Get_MuDeltaTreshold(CW)   

    flag  = 0;
    h     = 1E-1;
    coeff = 1;
    
    while flag == 0
        
        CW.In.delta                 = ((CW.In.delta/CW.In.kappa) + coeff*h)*CW.In.kappa;    
        CW                          = CW.Met.Norm(CW);        
        CW                          = CW.Met.Solve(CW);        
        CW                          = MI(CW);
        
        ind                         =  find(~isnan(CW.Sol.g)==1);
        if length(ind) > 1
            ind = 1;
        end
        
        [lambda,~]                  = max(real(CW.Stab(ind).Value(CW.Space.k == CW.In.mu_bl,:) ));
        
        if max(lambda) > 0
            
            if coeff*h <= 1E-6
                
                flag   = 1;
                ReLam = lambda(lambda>0);
                [MReLam]   = min(ReLam);
                mu    = CW.Space.k(find(lambda == MReLam));
                delta = CW.In.delta/CW.In.kappa;
                mu    = mu(1);
                delta = delta(1);
                W = CW.In.P;
                H2 = CW.In.H.^2;
                [lambda,~]                  = max(real(CW.Stab(ind).Value(CW.Space.k == 2*CW.In.mu_bl,:)));
                
                if lambda > 0
                    
                    FlagSide = 1;
                    
                else
                    FlagSide = -1;                    
                end
                            
                break;
                
            else
                CW.In.delta                 = ((CW.In.delta/CW.In.kappa) - coeff*h)*CW.In.kappa;    
                coeff                       = coeff/2;                          
            end
        else
            flag   = 0;
        end
        if CW.In.delta/CW.In.kappa > CW.In.W_WStar 
                mu    = NaN;
                delta = NaN;
                W     = NaN;
                H2     = NaN;
                break;
        end
    end
end