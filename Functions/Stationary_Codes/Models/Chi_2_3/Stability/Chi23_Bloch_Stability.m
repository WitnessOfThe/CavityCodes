function Stab = Chi23_Bloch_Stability(Stat)
            
     n = [0:1:floor(Stat.In.mu_bl/2)] ;%[-floor(Stat.In.mu_bl):1:floor(Stat.In.mu_bl)];
 %   if Stat.In.mu_bl == 1 || Stat.In.mu_bl == 0
 for i = 1:size(n,2)
%        i =1;
        Stat.In.n                     = n(i);

      % n = 1000;
     % A = mp(sprand(n,n,0.25));
    %  F = precomputeLU(A);          % Toolbox's routine for computing and storing LU for efficient re-use.
%      Afun = @(x) F\x;        
 %     [E_vectors_raw,E_values_raw]  = eigs(@(x)Stat.Met.Stab_Matrix(x,Stat)...
  %         ,4*Stat.Space.N,4*Stat.Space.N,'largestreal');
        AA = eye(4*Stat.Space.N);
        for ii = 1:4*Stat.Space.N
            AA(:,ii) = Stat.Met.Stab_Matrix(AA(:,ii),Stat);
        end
        A = AA;
      [E_vectors_raw,E_values_raw]  = eig(A);
       
        E_vectors                     = (E_vectors_raw(1:Stat.Space.N,:))...
            + conj( E_vectors_raw(Stat.Space.N+1:2*Stat.Space.N,:));
        Stab(i).mum = zeros(1,size(E_vectors,2));
        
        for i_k = 1:size(E_vectors,2)
            
            [~,Ind]       = max(abs(E_vectors(:,i_k)));
            Stab(i).mum(1,i_k) = Stat.Space.k(Ind);
            
        end
        
        [Stab(i).mum,Sort_I] = sort(Stab(i).mum,'ascend');
        
        Stab(i).In.n                  = n(i);
        Stab(i).E_values              = diag(E_values_raw)*Stat.Eq.norm;
%       [~,in_im]                      = maxk(real(Stab(i).E_values),10);
 %      Stab(i).E_vectors              = E_vectors_raw(:,in_im);%;
 end        
   %     Stab(i).E_values      = Stab(i).E_values(Sort_I);        
    %    Stab(i).E_values(Stab(i).E_values == 0 + 1i*0) = NaN+1i*NaN;
  %      if n(i) == 0
   %         [~,ind_zero ] = min(abs(Stab(i).E_values ));
    %        Stab(i).E_values(ind_zero)      = 0;
    %    end
     %   Stab(i).E_vectors     = Stab(i).E_vectors(:,Sort_I);

%    end
   
%   if Stat.In.mu_bl <2
%      for i =1:size(n,2)
%         Stat.In.n                     = n(i);
%         
%        [E_vectors_raw,E_values_raw]  = eigs(@(x)Stat.Met.Stab_Matrix(x,Stat)...
%            ,4*Stat.Space.N,4*Stat.Space.N,'largestreal');
%        
%         E_vectors                     = (E_vectors_raw(1:Stat.Space.N,:))...
%             + conj( E_vectors_raw(Stat.Space.N+1:2*Stat.Space.N,:));
%         Stab(i).mum = zeros(1,size(E_vectors,2));
%         
%         for i_k = 1:size(E_vectors,2)
%             
%             [~,Ind]       = max(abs(E_vectors(:,i_k)));
%             Stab(i).mum(1,i_k) = Stat.Space.k(Ind);
%             
%         end
%         
%         [Stab(i).mum,Sort_I] = sort(Stab(i).mum,'ascend');
%         
%         Stab(i).In.n                  = n(i);
%         Stab(i).E_values              = diag(E_values_raw)*Stat.Eq.norm;
%         
%    
%     end
%     if Stat.In.mu_bl > 1
%         
%             Stat     = Stat(1);
%             N        = 2^8;
%             Psi_o    = zeros(1,N);
%             Psi_e    = zeros(1,N);
%             Psi_o(1) = Stat.Sol.Psi_o(1,1);
%             Psi_e(1) = Stat.Sol.Psi_e(1,1);
%             mu       = Stat.In.mu_bl;
%             
%             for i = 1:round(N/2/mu)
% 
%                 Psi_o(1,1+i*mu)  = Stat.Sol.Psi_o(1+i);
%                 Psi_e(1,1+i*mu) =  Stat.Sol.Psi_e(1+i);
%                 
%                 Psi_o(1,end-i*mu+1)  = Stat.Sol.Psi_o(end-i+1);
%                 Psi_e(1,end-i*mu+1) =  Stat.Sol.Psi_e(end-i+1);
%                 
%             end
%             
%             Stat.In.mu_bl  = 1;
%             Stat.Sol.Psi_o = Psi_o;
%             Stat.Sol.Psi_e = Psi_e;
% 
%             Stat.In.N         = N;
%             Stat              = Stat.Met.Norm(Stat);
% %   Stat.Sol.Psi_o          = ifft(Stat.Sol.Psi_o*Stat.Space.N);
% %     Stat.Sol.Psi_e          = ifft(Stat.Sol.Psi_e*Stat.Space.N);
% %     
% %     Slv_Start               = [real(Stat.Sol.Psi_o),imag(Stat.Sol.Psi_o)...
% %                     ,real(Stat.Sol.Psi_e),imag(Stat.Sol.Psi_e),Stat.Sol.V];%
% % 
% %     [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Stat);
% %     
% %     Stat.Sol.Psi_o   = fft(Slv(1:Stat.Space.N) + 1i*Slv(Stat.Space.N+1:2*Stat.Space.N))/Stat.Space.N;
% %     Stat.Sol.Psi_e   = fft(Slv(2*Stat.Space.N+1:3*Stat.Space.N) + 1i*Slv(3*Stat.Space.N+1:4*Stat.Space.N))/Stat.Space.N;
% %     
% %     Stat.Sol.V       = Slv(end);
% %     Stat.Sol.eps_f   = eps_f;
% %     
% %     Stat.Sol.Exitflag = Exitflag;
% 
%         i =1;
%         Stat.In.n                     = 0;
%         
%        [E_vectors_raw,E_values_raw]  = eigs(@(x)Stat.Met.Stab_Matrix(x,Stat)...
%            ,4*Stat.Space.N,4*Stat.Space.N,'largestreal');
%        
%         E_vectors                     = (E_vectors_raw(1:Stat.Space.N,:))...
%             + conj( E_vectors_raw(Stat.Space.N+1:2*Stat.Space.N,:));
%         Stab(i).mum = zeros(1,size(E_vectors,2));
%         
%         for i_k = 1:size(E_vectors,2)
%             
%             [~,Ind]       = max(abs(E_vectors(:,i_k)));
%             Stab(i).mum(1,i_k) = Stat.Space.k(Ind);
%             
%         end
%         
%         [Stab(i).mum,Sort_I] = sort(Stab(i).mum,'ascend');
%         
%         Stab(i).In.n                  = n(i);
%         Stab(i).E_values              = diag(E_values_raw)*Stat.Eq.norm;
%        [~,in_im]                      = maxk(real(Stab(i).E_values),10);
%        Stab(i).E_vectors              = E_vectors_raw(:,in_im);%;

    end
  
%end
