function CW = Chi_3_LLE_MI_Boundary(CW)
    N                 = CW.In.N_mode;
    CW                = CW.Met.Norm(CW);        
    
    ome_rev              = zeros(1,N);
    ome_rev(2:end/2)     = fliplr(CW.In.omega_int(end/2+2:end));
    ome_rev(end/2+3:end) = fliplr(CW.In.omega_int(2:end/2-1));
    ome_rev(1)           = CW.In.omega_int(1);
    
    CW.In.Delta_pl  = CW.In.delta + CW.In.omega_int;
    CW.In.Delta_mn  = CW.In.delta + ome_rev;
    
    CW.In.g_MI(1,:) = 2/3*(CW.In.Delta_pl+CW.In.Delta_mn)/2 + 1/3*sqrt( ((CW.In.Delta_pl+CW.In.Delta_mn)/2).^2 - 3/4*CW.In.kappa.^2 );
    CW.In.g_MI(2,:) = 2/3*(CW.In.Delta_pl+CW.In.Delta_mn)/2 - 1/3*sqrt( ((CW.In.Delta_pl+CW.In.Delta_mn)/2).^2 - 3/4*CW.In.kappa.^2 );
    

    CW.In.H_MI_Tongue  =   real(sqrt( (CW.In.g_MI + 4*CW.In.g_MI.*(CW.In.delta - CW.In.g_MI).^2/CW.In.kappa.^2)/CW.In.gamma ));
    
        
        if CW.In.D(2) > 0
            for i = 1:CW.Space.N-1

               if (real(CW.In.g_MI(1,i)) == real(CW.In.g_MI(2,i))) || (CW.In.g_MI(1,i) <= 0)

                   CW.In.g_MI (:,i)   = 0;

               end
               
               if CW.In.H_MI_Tongue (1,i) == CW.In.H_MI_Tongue(2,i)

                   CW.In.H_MI_Tongue (:,i)   = 0;

               end

            end
        end
        
        if CW.In.D(2) < 0
            
            for i =  1:CW.Space.N-1
               if (real(CW.In.g_MI(1,i)) == real(CW.In.g_MI(2,i))) || (CW.In.g_MI(1,i) <= 0)

                   CW.In.g_MI (:,i)   = 0;

               end
               if CW.In.H_MI_Tongue (1,i) == CW.In.H_MI_Tongue(2,i)

                   CW.In.H_MI_Tongue (:,i)   = 0;

               end              
            end
            CW.In.H_MI_Tongue(CW.In.H_MI_Tongue==0) = NaN;    
            [~,ind_min] =  min( CW.In.H_MI_Tongue(2,1:end/2-1));
            if   sum(CW.In.H_MI_Tongue(1,ind_min) > CW.In.H_MI_Tongue(2,1:end/2-1))  > 1 
                CW.In.H_MI_Tongue (2,[1:ind_min-1,ind_min+1:end]) = 0;
                CW.In.H_MI_Tongue (1,[1:end]) = 0;
            else
                CW.In.H_MI_Tongue (2,[1:ind_min-2,ind_min+1:end]) = 0;
                CW.In.H_MI_Tongue (1,[1:ind_min-1,ind_min+1:end]) = 0;
            end
            
        end
        
    CW.In.g_MI(CW.In.g_MI==0) = NaN;    
    CW.In.H_MI_Tongue(CW.In.H_MI_Tongue==0) = NaN;    
    
    CW.In.W_MI_Tongue    = CW.In.H_MI_Tongue.^2*pi/CW.In.eta/CW.In.Finess;
    
    
end
% function CW = Chi_3_LLE_MI_Boundary(CW,N)
% 
%     CW              = CW.Met.Norm(CW,N);    
%     CW.In.Delta     = CW.In.delta + 1/2*CW.Space.k.^2*CW.In.D(2);
% 
%     CW.In.g_MI(1,:) = 2/3*CW.In.Delta + 1/3*sqrt( CW.In.Delta.^2 - 3/4*CW.In.kappa.^2 );
%     CW.In.g_MI(2,:) = 2/3*CW.In.Delta - 1/3*sqrt( CW.In.Delta.^2 - 3/4*CW.In.kappa.^2 );
%     %%
%     
%     F_d      = CW.In.D(2)/CW.In.kappa;
%     alpha_mu(1:2^7)       = F_d.*([0:2^7-1]+1/2);
%  
%     for ii = 1:N/2
% 
%     for i_2 = 1:ii
%         
%     	alpha_mu_upgr       = i_2*alpha_mu+F_d*(i_2-1)*i_2/2;
%         
%     end
%     
%     delta_0C_1(ii,:)    = L_L.CW.In.kappa*( sqrt( 1 + ( alpha_mu_upgr ).^2 ) ...
%                       - alpha_mu_upgr/2 - 1/2*F_d*[0:2^7-1].^2);
% 
%     for i = 2:size(delta_0C_1,2)
% 
%         CaF             =  L_L;
%         CaF.CW.In.delta =  delta_0C_1(ii,i);
% 
%         CaF.CW          = CaF.Met.T_MI (CaF.CW,N_Mode);
% 
%     if alpha_mu(i) <= 1/sqrt(3)
% 
%         G_MI(ii,i)       = CaF.CW.In.g_MI(2,i);
%         W_MI(ii,i)       = CaF.CW.In.g_MI(2,i);
% 
%     else
% 
%         G_MI(ii,i)       = CaF.CW.In.g_MI(1,i);              
%         W_MI(ii,i)       = CaF.CW.In.W_MI_Tongue(1,i);        
% 
%     end
% 
%     end    
%     end
% 
% 
% %%
% 
%     CW.In.H_MI_Tongue  =   real(sqrt( (CW.In.g_MI + 4*CW.In.g_MI.*(CW.In.delta - CW.In.g_MI).^2/CW.In.kappa.^2)/CW.In.gamma ));
%     
%         
%     if CW.In.D(2) > 0
% 
%         for i = 1:CW.Space.N-1
%            
%            if (real(CW.In.g_MI(1,i)) == real(CW.In.g_MI(2,i))) || (CW.In.g_MI(1,i) <= 0)
%            
%                CW.In.g_MI(:,i)          = 0;
%            
%            end
%            
%            if CW.In.H_MI_Tongue (1,i) == CW.In.H_MI_Tongue(2,i)
%            
%                CW.In.H_MI_Tongue(:,i)   = 0;
%            
%            end
% 
% %                 if CW.Space.k(i) >= 0 
% %                     if CW.In.H_MI_Tongue (2,i) > CW.In.H_MI_Tongue (2,i+1)
% %                          CW.In.H_MI_Tongue (1,i) = 0;
% %                          CW.In.H_MI_Tongue (2,i) = 0;
% %                     else
% %                        if CW.In.H_MI_Tongue (1,i) > CW.In.H_MI_Tongue (2,i+1)
% % 
% %                             CW.In.H_MI_Tongue (2,i+1) = 0;
% %                             CW.In.H_MI_Tongue (1,i) = 0;
% % 
% %                        end
% %                        if CW.In.g_MI (1,i) > CW.In.g_MI(2,i+1)
% % 
% %                           CW.In.g_MI (2,i+1) = 0;
% %                           CW.In.g_MI (1,i) = 0;
% % 
% %                        end
% %                     end
% % 
% %                 end
%     
%         end
% 
%     end
%         
% %         if CW.In.D(2) < 0
% %             
% %             for i =  1:CW.Space.N-1
% %                 
% %                if (real(CW.In.g_MI(1,i)) == real(CW.In.g_MI(2,i))) || (CW.In.g_MI(1,i) <= 0)
% % 
% %                    CW.In.g_MI (:,i)   = 0;
% % 
% %                end
% %                
% %                if CW.In.H_MI_Tongue (1,i) == CW.In.H_MI_Tongue(2,i)
% % 
% %                    CW.In.H_MI_Tongue (:,i)   = 0;
% % 
% %                end
% %                
% %             end
% %             
% %             CW.In.H_MI_Tongue(CW.In.H_MI_Tongue==0) = NaN;    
% %             [~,ind_min] =  min( CW.In.H_MI_Tongue(2,1:end/2-1));
% %             
% %             if   sum(CW.In.H_MI_Tongue(1,ind_min) > CW.In.H_MI_Tongue(2,1:end/2-1))  > 1 
% %                 
% %                 CW.In.H_MI_Tongue (2,[1:ind_min-1,ind_min+1:end]) = 0;
% %                 CW.In.H_MI_Tongue (1,[1:end]) = 0;
% %                 
% %             else
% %                 
% %                 CW.In.H_MI_Tongue (2,[1:ind_min-2,ind_min+1:end]) = 0;
% %                 CW.In.H_MI_Tongue (1,[1:ind_min-1,ind_min+1:end]) = 0;
% %                 
% %             end
% %             
% %         end
%         
%     CW.In.g_MI(CW.In.g_MI==0)               = NaN;    
%     CW.In.H_MI_Tongue(CW.In.H_MI_Tongue==0) = NaN;    
%     
%     CW.In.W_MI_Tongue    = CW.In.H_MI_Tongue.^2*pi/CW.In.eta/CW.In.Finess;
%     
%     
% end
