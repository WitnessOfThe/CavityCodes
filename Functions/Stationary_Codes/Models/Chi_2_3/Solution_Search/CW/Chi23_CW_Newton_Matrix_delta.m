function f  = Chi23_CW_Newton_Matrix_delta(CW,x)
    
      psi_o = CW.Eq.PsioMax + 1i*x(2);
      psi_e = x(3) + 1i*x(4);
      
      delta               = x(1);     %    
 
      g(1) = (CW.Eq.delta_o+delta).*psi_o - CW.Eq.gam2o.*(conj(psi_o).*psi_e) ...
          - CW.Eq.gam3o*(abs(psi_o).^2 + 2*abs(psi_e).^2).*psi_o ...
          -1i*1/2*CW.Eq.ko*(psi_o-CW.In.H_f);
      
      g(2) = (CW.Eq.delta_e+2*delta).*psi_e - CW.Eq.gam2e*psi_o.^2 ...
           - CW.Eq.gam3e*(2*abs(psi_o).^2 + abs(psi_e).^2).*psi_e ...
           -1i*1/2*CW.Eq.ke*psi_e;
      
      f(1) = real(g(1));
      f(2) = imag(g(1));
      
      f(3) = real(g(2));
      f(4) = imag(g(2));
            
end