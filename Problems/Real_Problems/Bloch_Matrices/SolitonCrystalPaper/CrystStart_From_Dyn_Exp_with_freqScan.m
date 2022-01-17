%%
    clear Temp0;
%    Freq = linspace(25,35,5*72);
%%
    clear Scans Temp Temp0;
    R.Stat.In.indphi = [];
    R.Stat.In        = rmfield(R.Stat.In,'indphi');
%    mu_vec = [-24:1:24];%[-4:1:7];%-4
    
    for iS = 14:59
        
        Freq = linspace(f_bound(iS).Fmin,f_bound(iS).Fmax,19);
        Freq(10) = f_peakExact(iS);
        
        tic
        parfor i = 1:size(Freq,2)

            Temp0(i)                 = Run(R.Stat,Freq(i),mu_vec(iS));
            Temp0(i).Sol.Psimu(1,:)  = Temp0(i).Sol.Psi(1:end,Temp0(i).Space.k(Temp0(i).Eq.mode_range)==Temp0(i).Space.k(Temp0(i).Par.indmu1));
            Nc                       = size(Temp0(i).Sol.Psi,1);
            Temp0(i).Sol.Psi         = Temp0(i).Sol.Psi([1,Nc/2,Nc],:);
            
        end
        toc
        
        Scans(iS).Temp = Temp0;
        Scans(iS).mu   = mu_vec(iS);
        clear Temp0;
    end
%%
    clear Scans Temp Temp0;
    R.Stat.In.indphi = [];
    R.Stat.In        = rmfield(R.Stat.In,'indphi');
    mu_vec = [2];%[-4:1:7];%-4
    maxNumCompThreads(32)
    for iS = 1
        
        Freq = linspace(29.85,29.85,1);
%        Freq(10) = f_peakExact(iS);
        
        tic
        for i = 1:size(Freq,2)

            Temp0(i)                 = Run(R.Stat,Freq(i),mu_vec(iS));
%            Temp0(i).Sol.Psimu(1,:)  = Temp0(i).Sol.Psi(1:end,Temp0(i).Space.k(Temp0(i).Eq.mode_range)==Temp0(i).Space.k(Temp0(i).Par.indmu1));
 %           Nc                       = size(Temp0(i).Sol.Psi,1);
  %          Temp0(i).Sol.Psi         = Temp0(i).Sol.Psi([1,Nc/2,Nc],:);
            
        end
        toc
        
        Scans(iS).Temp = Temp0;
        Scans(iS).mu   = mu_vec(iS);
        clear Temp0;
    end

%    parfor i =1:size(Freq,2)
       % Temp1(i) = Run(R.Stat,Freq(i),1);
 %       Temp1(i).Sol.Psi(:,26:end) = [];
 %   end

%%
for iS = 1:size(Scans,2)
    for i =1:size(Scans(iS).Temp,2)
            Scans(iS).Temp(i).Sol.Psi  = [];
    end
end
%%
for i =1:400
        Temp0(i).Sol.Power       = TempO(i).Sol.Power;
end
%%
    for i =1:size(Freq,2)
        Temp(i).Sol.Psi(:,26:end) = [];
    end

  %%
  plotMuT(Scans(1).Temp,Freq,-10)
  
%%
  plotMuT(Temp0(1:200),Freq(1:200))

%  plotMuT(Temp1,Freq,1)
   %%
  
  figure;%pcolor(Temp(1).Space.phi,Temp(1).Sol.t,abs(ifft(Temp(1).Sol.Psi,[],2)) );shading interp
hold on;plot(log10(abs(Temp0(20).Sol.Psi(end,:)).^2))

%%
Psi = (Scans.Temp(1).Sol.Psi);
%%
figure;hold on
plot(abs(ifft(Psi(1,:))).^2)
plot(abs(ifft(Psi(end,:))).^2)

%%
           indt  = 3001:4000;
           Nt    = length(indt);
           dt    = Scans(1).Temp(1).Sol.t(2)-Scans(1).Temp(1).Sol.t(1);
           df    = 1/dt/Nt;
           f     = 2*pi*[0:Nt/2-1,-Nt/2:-1]*df;
            figure; hold on
               %plot(fftshift(f),fftshift(10*log10(abs(fft(Temp0(20).Sol.Psimu(1,indt))).^2) ));shading interp
           for iss = 1+[0:4:222]
               psi = fft(Temp0(20).Sol.Psi(indt,iss));
               plot(fftshift(f),fftshift(10*log10(abs(psi).^2./max(abs(psi).^2) )) );shading interp
           end
%%


        Res                   = Set_Up_Methods_For_Bloch_Matrices;

        Res.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
        Res.Temp.Par.dt         = 2*pi/abs(500*Freq(1)); 
        Res.Temp.Par.s_t           = 2*pi/abs(Freq(1))/10;
        Res.Temp.Par.T             = 2*pi/abs(Freq(1))*5; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        Res.Temp.Par.freq_probe    = Freq(1);
        Res.Temp.Par.dd            = Res.Temp.Par.T/Res.Temp.Par.s_t;
        Res.Temp.Par.CW_num        = 1;
        Runge                      = Define_Runge_Coeff(Res.Temp.Par);
        
        Res.Stat = Stat(1);
        
        Res.Temp.In = Res.Stat.In;
        Res.Temp.In.N_mode = 2^14;   
        Res.Temp.In.mu_bl = 1;%24
        
        Res.Temp = Res.Temp.Met.Norm(Res.Temp);
        Res.Temp.Par.indmu1         = find(Res.Temp.Space.k == abs(Res.Temp.In.mu_bl*mu));
        Res.Temp.Par.indmu2         = find(Res.Temp.Space.k == -abs(Res.Temp.In.mu_bl*mu));

        Res             =  Start_Point_Bloch(Res);
        Res.Temp.Met    = [];
        
        Temp = Res.Temp;
        
 function plotMuT(Temp,Freq,mu)
 figure;hold on
       Power = 0;
  for i =1:size(Freq,2)
% 
       indmu = find(Temp(i).Space.k == Temp(i).In.mu_bl*mu);
%       ind1  = [1];
 %      ind2  = [400];
  %     [tt11,ind11] = max(abs(Temp(i).Sol.Psi([ind1:ind1+10999],indmu)));
   %    [tt22,ind22] = max(abs(Temp(i).Sol.Psi([ind2:ind2+10999],indmu)));
%       indt = (ind1+ind11-1):(ind2+ind22-1);
%       if Temp(i).Sol.Psi(end,1) == 0
 %          indt = 450:size(Temp(i).Sol.Psi,1)-1;
  %     else
           indt = 2501:size(Temp(i).Sol.Psimu,2);
   %    end

       Nt    = length(indt);
       if mod(Nt,2) == 0
            dt    = Temp(i).Sol.t(2)-Temp(i).Sol.t(1);
           df    = 1/dt/Nt;
           f     = 2*pi*[0:Nt/2-1,-Nt/2:-1]*df;
%           Spectrum    = fft(sum(abs(Temp(i).Sol.Psi(indt,indmu)).^2,2)/size(indmu,2))/Nt;
           Spectrum    = abs(fft(Temp(i).Sol.Psimu(indt))).^2/Nt;
           
       end
%        if mod(Nt,2) == 1
%             dt    = Temp(i).Sol.t(2)-Temp(i).Sol.t(1);
%            df    = 1/dt/Nt;
%            f     = 2*pi*[0:Nt/2,-Nt/2:-1]*df;
%            Spectrum    = fft(sum(abs(Temp(i).Sol.Psi(indt,indmu)).^2,2)/size(indmu,2))/Nt;
%            
%        end
%       ind_block = find(f>-20);
%       Spectrum(ind_block) = 0;
%       
%       [Power(i),ind]    = max(abs(Spectrum(:)).^2);
% %      fb(i) = f(ind);
% %      ind_up = find()
%       indmu = ind-45:ind+45;
%       
%       Power(i) = trapz(f(indmu),abs(Spectrum(indmu)).^2);
%      Spectrum   = fft((abs(Temp(i).Sol.Power(indt))))/Nt;
% %      fb(i) = f(ind);
% %      ind_up = find()
      Spectrum(1:3)= 0;
%      Spectrum(end-4:end)= 0;
      plot(f,10*log10(abs(Spectrum)))
       [Power(i),ind]    = max(abs(Spectrum(:)));
% %       Power(i) = 
%        indmu = ind-250:ind+250;
%        
%        Power(i) = trapz(f(indmu),abs(Spectrum(indmu)).^2);
  end
 figure;
 hold on;plot(Freq,10*log10(Power))
  end

function Temp = Run(Stat,Freq,mu)
        
        Res                   = Set_Up_Methods_For_Bloch_Matrices;

        Res.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
        Res.Temp.Par.dt            = 2*pi/abs(500*Freq(1));
        Res.Temp.Par.s_t           = 2*pi/abs(Freq(1))/10;
        Res.Temp.Par.T             = 2*pi/abs(Freq(1))*15000;%*40*5; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        Res.Temp.Par.freq_probe    = Freq;
        Res.Temp.Par.dd            = Res.Temp.Par.T/Res.Temp.Par.s_t;
        Res.Temp.Par.CW_num        = 1;
        Runge                      = Define_Runge_Coeff(Res.Temp.Par);
        
        Res.Stat = Stat(1);
        
        Res.Temp.In = Res.Stat.In;
        Res.Temp.In.N_mode = 2^14;   
        Res.Temp.In.mu_bl = 1;%24
        
        Res.Temp = Res.Temp.Met.Norm(Res.Temp);
        
        Res.Temp.Par.indmu1         = find(Res.Temp.Space.k == (Res.Temp.In.mu_bl*mu));
        Res.Temp.Par.indmu2         = find(Res.Temp.Space.k == -abs(Res.Temp.In.mu_bl*mu));

        Res             =  Start_Point_Bloch(Res);
        Res.Temp.Met    = [];
        Res.Temp.Eq.L   = Res.Temp.Eq.L - Stat.Sol.V*Res.Temp.Space.k;        
        Temp = Res.Temp;
    
      %  tic
        Temp.Sol = Chi_3_LLE_Runge_Kuarong_with_Scan_mex(Temp,Runge);
       % toc
        

end
 function R =  Start_Point_Bloch(R)
 
    
    R.Temp.In.Psi_Start          = zeros(1,R.Temp.Space.N);
    
    for i = 1:floor(R.Temp.Space.N/2/R.Stat.In.mu_bl*R.Temp.In.mu_bl)
        R.Temp.In.Psi_Start(R.Temp.Space.k == R.Stat.Space.k(i))=R.Stat.Sol.Psi_k(i);
        R.Temp.In.Psi_Start(R.Temp.Space.k == R.Stat.Space.k(end-i+1))= R.Stat.Sol.Psi_k(end-i+1);        
    end
    
  %  for i = 1:floor(L_L.Temp.Space.N/2/L_L.Stat.In.mu_bl)
   %     L_L.Temp.In.Psi_Start(L_L.Temp.Space.k == L_L.Stat.Space.k(i))  = L_L.Stat.Sol.Psi_k(i);
    %    L_L.Temp.In.Psi_Start(L_L.Temp.Space.k == L_L.Stat.Space.k(end-i+1))= L_L.Stat.Sol.Psi_k(end-i+1);        
    %end
    
    R.Temp.In.Psi_Start = (R.Temp.In.Psi_Start)*R.Temp.Space.N;
    R.Temp.In.t_start   = 0;
    
end
