function CW = Chi_3_LLE_MI_Boundary(CW,N)
    
    CW = CW.Met.Norm(CW,N);    
    CW.In.Delta  =     CW.In.delta + 1/2*CW.Space.k.^2*CW.In.D(2);
    
    CW.In.g_MI(1,:) = 2/3*CW.In.Delta + 1/3*sqrt( CW.In.Delta.^2 - 3/4*CW.In.kappa.^2 );
    CW.In.g_MI(2,:) = 2/3*CW.In.Delta - 1/3*sqrt( CW.In.Delta.^2 - 3/4*CW.In.kappa.^2 );
    

    CW.In.H_MI_Tongue  =   real(sqrt( (CW.In.g_MI + 4*CW.In.g_MI.*(CW.In.delta - CW.In.g_MI).^2/CW.In.kappa.^2)/CW.In.gamma ));
    
    if  CW.In.D(2)/CW.In.kappa > 0.05
        for i = 1:CW.Space.N-1

           if (real(CW.In.g_MI(1,i)) == real(CW.In.g_MI(2,i))) || (CW.In.g_MI(1,i) <= 0)

               CW.In.g_MI (:,i)   = 0;

           end
           if CW.In.H_MI_Tongue (1,i) == CW.In.H_MI_Tongue(2,i)

               CW.In.H_MI_Tongue (:,i)   = 0;

           end

            if CW.Space.k(i) >= 0 

               if CW.In.H_MI_Tongue (1,i) > CW.In.H_MI_Tongue (2,i+1)

                    CW.In.H_MI_Tongue (2,i+1:(end/2-1)) = 0;
                    CW.In.H_MI_Tongue (1,i:(end/2-1)) = 0;

               end
               if CW.In.g_MI (1,i) > CW.In.g_MI(2,i+1)

                  CW.In.g_MI (2,i+1) = 0;
                  CW.In.g_MI (1,i) = 0;

               end

            end        
        end
    end
    if  CW.In.D(2)/CW.In.kappa <= 0.05
         for i = 1:CW.Space.N-1
     
           if (real(CW.In.g_MI(1,i)) == real(CW.In.g_MI(2,i))) || (CW.In.g_MI(1,i) <= 0)

               CW.In.g_MI (:,i)   = 0;

           end
            if CW.In.H_MI_Tongue (1,i) == CW.In.H_MI_Tongue(2,i)

               CW.In.H_MI_Tongue (:,i)   = 0;

           end

         end
    end
    CW.In.g_MI(CW.In.g_MI==0) = NaN;    
    CW.In.H_MI_Tongue(CW.In.H_MI_Tongue==0) = NaN;    
    
    CW.In.W_MI_Tongue    = CW.In.H_MI_Tongue.^2*pi/CW.In.eta/CW.In.Finess;
    
    
end
