function [F_s,t_s] = Full_Runge_Kerr(F_e,gamma_3,Pump,L,dt,nt,NN,Loops,per_loop,N,Runge,Delta)
%% Runge-Kutta Coefficicents
           
%%        
    i1      = 1;
    j        = NN;    
    F_s      = zeros(Loops*per_loop,N) + 1i*zeros(Loops*per_loop,N);
    t_s      = zeros(1,Loops*per_loop);
    
%% Define Time Steps inside the runge

    b      = Runge.b;
    c      = Runge.c;
    
    iter_l = size(b,1);
    iter_2 = size(b,2);
    k_r    = zeros(iter_l,N);

%%
    
%tic
h = waitbar(0,'');
    for ni=1:nt  
        
        F_e = Runge_Kuarong_Kerr_step(F_e,dt);
        
        if (j == NN)     
        %     toc
             F_s(i1,1:N) = F_e;
             t_s(i1)     = dt*ni;
             i1          = i1+1;
             j           = 0;     
             waitbar(ni/nt,h,strcat(Delta.Initial_Guess,Delta.Physics,Delta.Runge_Type,'|||',sprintf('%.4f',ni/nt*100),'%' ))
        end
         
        j=j+1;     
        
    end
close(h)
    function     B_f    =    Runge_Kuarong_Kerr_step(B_E,dt)
        
        B_f      = B_E;    
        k_r(1,:)    = dt*Equation_with_Kerr(B_E);

    for i = 2:iter_l
        
        B_E_temp = B_E;
        
        for ii= 1:iter_2
            if b(i,ii) ~=0 
                B_E_temp = B_E_temp + b(i,ii).*k_r(ii,:);
            end
        end
        
        k_r(i,:) = dt*Equation_with_Kerr(B_E_temp);
        
    end 
    
    for i = 1:iter_l
        if c(i)  ~=0 
            B_f    = B_f + c(i).*k_r(i,:);
        end
    end    
            
    end    
        
    function k_e = Equation_with_Kerr( F_Psi )

        Psi         = ifft(F_Psi);
        abs_Psi_2   = abs(Psi).^2;
        k_e         = -1i*L.*F_Psi + 1i*fft( gamma_3*abs_Psi_2.*Psi + Pump ); 

    end
    
    end
