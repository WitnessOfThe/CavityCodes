function CW = Chi_3_LLE_Synch_Boundary(CW,N)
    
    CW = CW.Met.Norm(CW,N);    

    CW.In.Delta  =     CW.In.delta + 1/2*CW.Space.k.^2*CW.In.D(2);
    
    CW.In.g_Synch(1,:) =     CW.In.Delta;
    CW.In.g_Synch(2,:) = 1/3*CW.In.Delta;
        
    CW.In.H_Synch    = real(sqrt( (CW.In.g_Synch + 4*CW.In.g_Synch.*(CW.In.delta - CW.In.g_Synch).^2/CW.In.kappa.^2)/CW.In.gamma ));

    for i = 1:CW.Space.N
        
       if CW.In.H_Synch (1,i) == CW.In.H_Synch(2,i)
           
           CW.In.H_Synch (:,i) = 0;
           
       end
       if CW.In.g_Synch(2,i) > CW.In.g_Synch(1,i)
           CW.In.g_Synch(1,i) = 0;
           CW.In.g_Synch(2,i) = 0;
           CW.In.H_Synch (:,i) = 0;
           
       end
    end

%     for i = 1:CW.Space.N-1
%         
%         if CW.Space.k(i) >= 0 
%             
%            if CW.In.H_Synch (1,i) > CW.In.H_Synch (2,i+1)
%                
%               if  i > 1
%                   
%                 if ( CW.In.H_Synch (1,i-1) < CW.In.H_Synch (2,i)) 
%                     
%                     CW.In.H_Synch (1,i)             = sqrt(4*g(2,i)*CW.In.delta.^2/CW.In.kappa^2/CW.In.gamma);
%                     %sqrt(pi*abs(CW.In.D(2))^3*abs(CW.Space.k(i)).^5/(2*CW.In.gamma*CW.In.D(1)*CW.In.eta*CW.In.kappa))*sqrt(CW.In.eta*CW.In.Finess/pi);
%                     CW.In.H_Synch (2,i+1:(end/2-1)) = 0;
%                     
%                 else
%                   
%                     CW.In.H_Synch (2,i+1:(end/2-1)) = 0;
%                     CW.In.H_Synch (1,i:(end/2-1)) = 0;
%                 end
%                 
%               else
%                   
%                     CW.In.H_Synch (2,i+1:(end/2-1)) = 0;
%                     CW.In.H_Synch (1,i:(end/2-1)) = 0;
% 
%               end
%              end
%            
%         end 
%     end
    CW.In.g_Synch(CW.In.g_Synch==0) = NaN;
    CW.In.H_Synch(CW.In.H_Synch==0) = NaN;    
    CW.In.W_Synch    = CW.In.H_Synch.^2*pi/CW.In.eta/CW.In.Finess;

end
