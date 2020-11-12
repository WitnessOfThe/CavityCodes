function CW = Chi_3_LLE_MI_Formula(CW,N)
    
    CW = CW.Met.Norm(CW,N);    
    ome_rev              = zeros(1,N);
    ome_rev(2:end/2)     = fliplr(CW.In.omega_int(end/2+2:end));
    ome_rev(end/2+3:end) = fliplr(CW.In.omega_int(2:end/2-1));
    ome_rev(1)           = CW.In.omega_int(1);
    
    CW.In.Delta_p  = CW.In.delta + CW.In.omega_int;
    CW.In.Delta_m  = CW.In.delta + ome_rev;
 
    
%     if CW.In.g == 0
%         
%         CW.An.Lambda_mu(1:2,:) = zeros(2,N);
%         CW.An.Omega_mu(1,:) = CW.In.Delta_p;
%         CW.An.Omega_mu(2,:) =-CW.In.Delta_m;
%         
%     else
% 
% %        CW.An.Lambda_mu(1,:) = sqrt(3*( CW.In.Delta_p - CW.In.g).*(CW.In.g - 1/3*CW.In.Delta));
%  %       CW.An.Lambda_mu(2,:) = - CW.An.Lambda_mu(1,:);
% 
%   %      CW.An.Omega_mu(1,:) = sqrt(3*(CW.In.g - CW.In.Delta).*(CW.In.g - 1/3*CW.In.Delta));
%    %     CW.An.Omega_mu(2,:) = - CW.An.Omega_mu(1,:);
% 
%     %    CW.An.Omega_mu(1,(1/3*CW.In.Delta < CW.In.g) & (CW.In.Delta > CW.In.g)) = 0;
%      %   CW.An.Omega_mu(2,(1/3*CW.In.Delta < CW.In.g) & (CW.In.Delta > CW.In.g)) = 0;
% 
%       %  CW.An.Lambda_mu(1,(1/3*CW.In.Delta > CW.In.g) | (CW.In.g > CW.In.Delta) ) = 0;
%        % CW.An.Lambda_mu(2,(1/3*CW.In.Delta > CW.In.g) | (CW.In.g > CW.In.Delta) ) = 0;
%         b = CW.In.Delta_p - CW.In.Delta_m - 1i*2*CW.In.kappa;
%         c = (CW.In.Delta_p - 2*CW.In.g - 1i*CW.In.kappa).*(-CW.In.Delta_m + 2*CW.In.g - 1i*CW.In.kappa)+CW.In.g^2;
%         
%         CW.An.lambda_mu(1,:) = (b+sqrt(b.^2-4*c))/2; 
%         CW.An.lambda_mu(2,:) = (b-sqrt(b.^2-4*c))/2;
%        
%     end   
        a =  (CW.In.Delta_p - 2*CW.In.g -1i*CW.In.kappa*1/2);
        b = -CW.In.g;
        d = (-CW.In.Delta_m + 2*CW.In.g -1i*CW.In.kappa*1/2);
        c = CW.In.g;
        
        CW.An.lambda_mu(1,:) = -1i*(((a+d)+sqrt((a+d).^2-4*(a.*d-b.*c)))/2); 
        CW.An.lambda_mu(2,:) = -1i*(((a+d)-sqrt((a+d).^2-4*(a.*d-b.*c)))/2);
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
