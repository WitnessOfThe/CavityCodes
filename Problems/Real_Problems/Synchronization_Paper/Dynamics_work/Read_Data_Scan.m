clear all
%%
  load('/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Real_Problems/Synchronization_Paper/Dynamics_work/Tongues_Scan/Starter_CaF_Big_Scan.mat');

%%

d_mu_mean = NaN(size(delta_matrix));
d_mu_std = NaN(size(delta_matrix));
%t_Save.D_mu = zeros(1,1);
NN = 1;
for i_t = 1:NN
    ind_t(i_t).ind = [(10001+i_t):(19000+i_t)];
end
%t_Save =struct(1,61*347);
%%
for i =1:size(delta_matrix,1)*size(delta_matrix,2)
    
    if  Sim_zone(i) == 1 && isfile(strcat('/home/dp710/Data_Storage/CaF_Scan_from_0.4_to_0_2_synch_zone_fixed/Data/',num2str(i),'.mat')) 
        
        tt=load(strcat('/home/dp710/Data_Storage/CaF_Scan_from_0.4_to_0_2_synch_zone_fixed/Data/',num2str(i),'.mat'));
        [a,b] =ind2sub(size(power_matrix),i);
            
            t_Save(a,b).Psi   = tt.Save.Temp.Sol.Power;            
            t_Save(a,b).freq  = tt.Save.Temp.Sol.freq;         
            i
    end
    
end
%%
N_p = 141;
N_d = 795;
Conv         = NaN(N_p,N_d);
Power        = NaN(N_p,N_d);
Power_assym = NaN(N_p,N_d);
k = [0:511,-512:-1];
for i_p =1:N_p
    for i_d = 1:N_d
        if ~isempty(t_Save(i_p,i_d).Psi)
            Conv( i_p ,i_d) = t_Save( i_p ,i_d).Psi(1)./sum(t_Save(i_p ,i_d).Psi(2:end));
            Power( i_p ,i_d) = sum(t_Save(i_p ,i_d).Psi(1:end));            
            phi( i_p ,i_d)  =  trapz(k(tt.Save.Temp.Eq.mode_range).*t_Save(i_p ,i_d).Psi(1:end))./trapz(t_Save(i_p ,i_d).Psi(1:end));
        end
    end
end
%%
figure;
pcolor(delta_matrix(1:N_p,1:N_d),power_matrix(1:N_p,1:N_d),Conv);shading flat
caxis([0.8,20])
%%
figure;
pcolor(delta_matrix(1:N_p,1:N_d),power_matrix(1:N_p,1:N_d),Power);shading flat
%caxis([0.8,20])
%%
figure;
pcolor(delta_matrix(1:N_p,1:N_d)/2/pi,power_matrix(1:N_p,1:N_d),abs(phi));shading flat
