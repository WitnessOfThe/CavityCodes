function Temporal = Full_Runge_Cubic(F_e,dt,nt,NN,NNN,N,Runge,Delta,gamma_cubic,kappa,Delta_Laser,Pump,omega_j,Omega_start,File_name,h_delta,t_acc)
    
    b      = Runge.b;
    c      = Runge.c;
    a      = Runge.a;
    s      = size(b,1); 
    d      = zeros(s,N);
    tic;
    
%%    
    omega_j             = [omega_j,zeros(1,N-size(omega_j,2))]; 
    mask                =  abs(omega_j./omega_j);
    
    mask(isnan(mask))   = 0;    
    F_e                 =  mask.*F_e;
    
    [~,max_ind]        = max(Pump);
    
    for i1 = 1:size(a,2)
        
        exp_plus_omega(i1,:)  = mask.*exp(1i*omega_j*a(i1)*dt) ;           
        exp_minus_omega(i1,:) = mask.*exp(-1i*omega_j*a(i1)*dt);           
        
    end
    
    shift_back = mask.*exp(-1i*omega_j*dt);
%%

    l      = [0:(N/2-1)];

%% Preallocation !!!
    
    N_t      = 2^15;
    j        = NN;    
    
    N_min = find(omega_j,1,'first');
    N_max = find(omega_j,1,'last');
    
    mode_range = [N_min:N_max];
    
    Nonlinear_term      = zeros(1,N); 
    Pump_term           = zeros(1,N); 
    E_0                 = zeros(1,2*N);
    g_delta             = zeros(size(a,2),1);
    
    F_s                 = zeros(round(nt/NNN/NN),size(mode_range,2)) + 1i*zeros(round(nt/NNN/NN),size(mode_range,2));

    t_s                 = zeros(1,round(nt/NNN/NN));
    U_max               = zeros(1,round(nt));
    
    l_m                 = [50:10:100,109,110,112,120:10:320,327,330:10:370];%,350,400,450,500,550,600,650];
    
    for i = 1:size(l_m,2)
        
        indexes(i) =  mode_range(l(mode_range) == l_m(i));
        
    end
    
    U_m                 = zeros(round(nt),size(l_m,2));
    
    omega_max_vector    = zeros(round(nt/N_t),size(mode_range,2));  
    Amplitude           = zeros(round(nt/N_t),size(mode_range,2)); 
    t_t                 = zeros(1,round(nt/N_t));
    
%% The Main Runge Loop
    
%    h = waitbar(0,'');
 %   fig = figure('Name','Amp_scan','Position',[0,0,400,300]);  
  %  ax1 = axes('Parent',fig,'Position',[0.15,0.6,0.8,0.3]);
   % ax3 = axes('Parent',fig,'Position',[0.15,0.15,0.8,0.3]);
    
    i1    = 1;
    j_2   = 1;
    
%    hold(ax1,'on')
    i_t   = 0; 
    
    saver_index = 0;
    
%%

 %   F_e_t    =                          zeros(N_t,size(mode_range,2));
 %   omega_t  = -[0:N_t/2-1,-N_t/2:-1]*2*pi/(N_t*dt);
    
%    for i = 1:size(mode_range,2)
        
 %       omega_t_j_matrix(1:N_t,i)         =  omega_t  + l(mode_range(i))*2*pi ;% ; %
        
  %  end
    tic
    i2    = 1;
    for ni = 1:nt 
        
            
            for iiii = 1:size(a,2)

                g_delta(iiii,1)         = h_Omega_Laser(Omega_start,t_acc +(ni-1)*dt+a(iiii)*dt,nt*dt,Pump(max_ind),h_delta,Delta_Laser);

            end            
            
            F_e                         = Runge_Kuarong_Kerr_step(F_e,dt);

            U_max(ni)       =  max(abs(Get_Field(N,F_e)).^2);
            U_m(ni,:)       =  F_e(indexes).*exp(1i*omega_j(indexes)*dt*ni);
            
            
%            F_e_t(mod((ni-1),N_t) + 1,:) = F_e(mode_range).*exp(1i*omega_j(mode_range)*dt*ni);
            i_t = i_t + 1;
            
%             if mod(ni,N_t) == 0                
%                       ni/nt
% 
%                 [Amplitude(i2,:),omega_max_vector(i2,:)] =  Get_Real_Spectrum(F_e_t,omega_t_j_matrix);
%                 t_t(i2)                                  =  ni*dt;
%                 i2                                       =  i2 + 1;
%                 
%            end
            
            if j == NN
                [t_s,F_s,i1,j_2,i_t] =  Save_data(F_s...
                          ,N,NN,NNN,i1,j_2,F_e,ni,nt,Delta,...
                                    t_acc,dt,mode_range,t_s...
                                                    );
                j = 0;                    
            end
            
            j=j+1;
            
    end
    
    Temporal.t_abs       = [1:nt]*dt;
%    Temporal.t_t         = t_t;
    Temporal.t           = t_s;
    Temporal.U_max       = U_max;
    Temporal.U_m         = U_m;
    Temporal.l_s         = l_m;
    Temporal.E_s         = F_s;
 %   Temporal.omega_max   = omega_max_vector;
%    Temporal.E_t         = Amplitude;
    
    
    function     E_f    =    Runge_Kuarong_Kerr_step(B_E,dt)

        E_f    =   B_E;    
        E_temp =   B_E;
        
        d(1,:) =   Equation_with_Cubic(E_temp,exp_plus_omega(1,:),g_delta(1,:),exp_minus_omega(1,:));
        
        for i = 2:s

            for ii = 1:s-1

                if b(i,ii) ~= 0

                    E_temp(mode_range) = E_temp(mode_range) + dt*b(i,ii).*d(ii,mode_range);

                end

            end
            
            d(i,:) =   Equation_with_Cubic(E_temp,exp_plus_omega(i,:),g_delta(i,:),exp_minus_omega(i,:));
            
            E_temp = B_E;
            
        end 

        for i = 1:s

            if c(i)  ~=0 

                E_f(mode_range)    = E_f(mode_range) + dt*c(i).*d(i,mode_range);

            end

        end    
        
           E_f(mode_range) = shift_back(mode_range).*E_f(mode_range); 
           
    end  

    function k_e = Equation_with_Cubic(E_j,exp_plus_omega,g_c,exp_minus_omega)
        
         E_j(mode_range)     =          exp_minus_omega(mode_range).*E_j(mode_range);
        
         E_0                 =        Get_Field(N,E_j);
          
         F_E_0_3             =      fft(E_0.^3)/2/N;%
            
         k_e              =          zeros(1,N);
         
         Nonlinear_term(mode_range)      = 1i*gamma_cubic(mode_range).*F_E_0_3(mode_range);%tt.*
        
         Pump_term(max_ind) =  g_c;        
         k_e(mode_range)    =  exp_plus_omega(mode_range).*( - kappa(mode_range)/2.* E_j(mode_range)+Pump_term(mode_range) + Nonlinear_term(mode_range));

    end

end

function [Amplitude,omega_max_vector] = Get_Real_Spectrum(F_e_t,omega_t_j_matrix)
  
    omega_f_e_t               = fft(F_e_t,[],1)/size(F_e_t,1);    
%   omega_f_e_t               = fftshift(omega_f_e_t,1);    
    [Amplitude,ind_vector]    = max(omega_f_e_t,[],1);
     omega_max_vector         = zeros(1,size(omega_f_e_t,2));
     
    for i = 1:size(omega_f_e_t,2)
        
        omega_max_vector(i)          = omega_t_j_matrix(ind_vector(i),i);
        
    end
end

function Pump = h_Omega_Laser(Omega_start,t,Loops,h_start,Delta_h,Delta_Laser)

    omega  = Omega_start - t/Loops*Delta_Laser;
    h_time = h_start     + t/Loops*Delta_h;
    Pump   = h_time*exp(-1i*omega*t);

end

function Field = Get_Field(N,F_e)

   F_e_shifted         =   zeros(1,N);
   F_e_shifted(2:N)    =   flip(conj(F_e(2:N)));
   Field               =   ifft([F_e,F_e_shifted],'symmetric')*2*N;

end

function    [t_s,F_s,i1,j_2,i_t] =  Save_data(F_s,N,NN,NNN,i1,j_2,F_e,ni,nt,Delta,t_acc,dt,mode_range,t_s,h)
 %  toc          
                  ni/nt
                 t_s(i1)         =                  t_acc + dt*ni;
                 F_s(i1,:)       =                F_e(mode_range);                 
                 
                 
    %             plot(t_s(i1),U_max(ni),'Parent',ax1,'Marker','.','LineStyle','none','Color',[0,0,0]);
   %              plot([-N:N-1]*pi/N,Get_Fie%ld(N,F_e),'Parent',ax3);

%                 waitbar(ni/nt,h,strcat(Delta.Initial_Guess,Delta.Physics,Delta.Runge_Type,'|||',sprintf('%.4f',ni/nt*100),'%' ))

%                  if (j_2 == nt/NN/NNN) && (NNN ~= 1)
% 
%                     L_L.Solution.Temporal.F_s   = F_s;
%                     L_L.Solution.Temporal.U_max = U_max;
%                     L_L.Solution.Temporal.t     = t_s;
% 
%                     L_L.Solution.Temporal.Laser_Shift    = -Delta_Laser*ni/nt;
%                     saver_index = saver_index + 1;
%                     save(strcat(File_name,'/',num2str(saver_index),'.mat'),'L_L');   
% 
%                     i1  = 0;
%                     j_2 = 0;
% 
%                  end

                 i1          = i1  + 1;
                 j_2         = j_2 + 1;
                 i_t         = 0;

%   tic
end
