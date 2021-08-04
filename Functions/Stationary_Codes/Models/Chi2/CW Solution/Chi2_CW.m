    function CW = Chi2_CW(CW)
    
        CW         = CW.Met.Norm(CW);
                
%        coef       = [4/CW.In.k_o^2/CW.In.Omega_S^2/abs(CW.In.Omega_e)^2,...
 %               4*abs(CW.In.Omega_o).^2/CW.In.k_o^2/CW.In.Omega_S^2*real(2/(CW.In.Omega_o*CW.In.Omega_e)),...
 %               4*abs(CW.In.Omega_o).^2/CW.In.k_o^2/CW.In.Omega_S^2,-(CW.In.W/CW.In.W_Star)];
 
        coef = [CW.In.Wf_Star*4*abs(CW.In.Omega_f).^2/CW.In.ko^2/CW.In.Omega_Star^2*[1/(abs(CW.In.Omega_f).^2*abs(CW.In.Omega_s).^2),-real(2/(CW.In.Omega_s*CW.In.Omega_f)),1],-CW.In.W];
        
        Omega      = roots( coef );
        Omega(imag(Omega) ~= 0) = NaN;
        
        CW.Sol.Omega    = sqrt(Omega);        
        CW.Sol.Psi_o    = CW.Sol.Omega./CW.In.Omega_Star*CW.In.H_Star;
        CW.Sol.Psi_e    = CW.Sol.Omega.^2/CW.In.Omega_s/CW.In.gam2o;
        CW.Sol.g        = CW.In.gam2o.*abs(CW.Sol.Psi_e);        
        
    end
    
