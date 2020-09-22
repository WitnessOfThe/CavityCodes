function CW = Chi_3_LLE_MI_Formula(CW,N)
    
    CW = CW.Met.Norm(CW,N);    
    CW.In.Delta  =     CW.In.delta + 1/2*CW.Space.k.^2*CW.In.D(2);
    
    if CW.In.g == 0
        
        CW.An.Lambda_mu(1:2,:) = zeros(2,N);
        CW.An.Omega_mu(1,:) = CW.In.Delta;
        CW.An.Omega_mu(2,:) =-CW.In.Delta;
        
    else

        CW.An.Lambda_mu(1,:) = sqrt(3*( CW.In.Delta - CW.In.g).*(CW.In.g - 1/3*CW.In.Delta));
        CW.An.Lambda_mu(2,:) = - CW.An.Lambda_mu(1,:);

        CW.An.Omega_mu(1,:) = sqrt(3*(CW.In.g - CW.In.Delta).*(CW.In.g - 1/3*CW.In.Delta));
        CW.An.Omega_mu(2,:) = - CW.An.Omega_mu(1,:);

        CW.An.Omega_mu(1,(1/3*CW.In.Delta < CW.In.g) & (CW.In.Delta > CW.In.g)) = 0;
        CW.An.Omega_mu(2,(1/3*CW.In.Delta < CW.In.g) & (CW.In.Delta > CW.In.g)) = 0;

        CW.An.Lambda_mu(1,(1/3*CW.In.Delta > CW.In.g) | (CW.In.g > CW.In.Delta) ) = 0;
        CW.An.Lambda_mu(2,(1/3*CW.In.Delta > CW.In.g) | (CW.In.g > CW.In.Delta) ) = 0;
    end   
        CW.An.lambda_mu = - 1/2*CW.In.kappa - (CW.An.Lambda_mu+1i*CW.An.Omega_mu); 
end
% function CW = Chi_3_LLE_MI_Formula(CW,N)
%     
%     CW = CW.Met.Norm(CW,N);    
%     CW.In.Delta  =     CW.In.delta + 1/2*CW.Space.k.^2*CW.In.D(2);
%     
%     if CW.In.g == 0
%         
%         CW.An.Lambda_mu(1:2,:) = zeros(2,N);
%         CW.An.Omega_mu(1,:) = CW.In.Delta;
%         CW.An.Omega_mu(2,:) =-CW.In.Delta;
%         CW.An.lambda_mu = - 1/2*CW.In.kappa - (CW.An.Lambda_mu+1i*CW.An.Omega_mu); 
% 
%         
%     else
%         CW.An.lambda_mu = zeros(2,CW.Space.N);
%         ind = (1/3*CW.In.Delta < CW.In.g) & (CW.In.Delta > CW.In.g);
%         
%         CW.An.lambda_mu(1,ind) = - 1/2*CW.In.kappa + 1i*sqrt(3*( CW.In.Delta(ind)-CW.In.g ).*( CW.In.g - 1/3*CW.In.Delta(ind) )); 
%         CW.An.lambda_mu(2,ind) = - 1/2*CW.In.kappa - 1i*sqrt(3*( CW.In.Delta(ind)-CW.In.g ).*( CW.In.g - 1/3*CW.In.Delta(ind) )); 
%         
%         ind = (1/3*CW.In.Delta > CW.In.g) | (CW.In.Delta < CW.In.g);
%         
%         CW.An.lambda_mu(1,ind) = - 1/2*CW.In.kappa + 1i*sqrt(3*( CW.In.g-CW.In.Delta(ind) ).*( CW.In.g - 1/3*CW.In.Delta(ind) )); 
%         CW.An.lambda_mu(2,ind) = - 1/2*CW.In.kappa - 1i*sqrt(3*( CW.In.g-CW.In.Delta(ind) ).*( CW.In.g - 1/3*CW.In.Delta(ind) )); 
% 
%         CW.An.Lambda_mu = real(CW.An.lambda_mu);
%         CW.An.Omega_mu  = imag(CW.An.lambda_mu);
%  
%         CW.An.Omega_mu(1,(1/3*CW.In.Delta < CW.In.g) & (CW.In.Delta > CW.In.g)) = 0;
%         CW.An.Omega_mu(2,(1/3*CW.In.Delta < CW.In.g) & (CW.In.Delta > CW.In.g)) = 0;
% 
%       %  CW.An.Lambda_mu(1,(1/3*CW.In.Delta > CW.In.g) | (CW.In.g > CW.In.Delta) )  = 0;
%    %     CW.An.Lambda_mu(2,(1/3*CW.In.Delta > CW.In.g) | (CW.In.g > CW.In.Delta) )  = 0;
%         
%         CW.An.lambda_mu = CW.An.Lambda_mu + 1i*CW.An.Omega_mu;
%     end   
% end
