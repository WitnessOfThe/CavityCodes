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
    
    if  Sim_zone(i) == 1 && isfile(strcat('/home/dp710/Data_Storage/CaF_Scan_from_0.4_to_0_2_synch_zone/Data/',num2str(i),'.mat')) 
        
        tt=load(strcat('/home/dp710/Data_Storage/CaF_Scan_from_0.4_to_0_2_synch_zone/Data/',num2str(i),'.mat'));
        [a,b] =ind2sub(size(power_matrix),i);
        for i_t = 1:NN
            
            t_Save(a,b).D_mu(i_t)   = d_mu_from_Dyn(tt,ind_t(i_t).ind);
            
        end
            t_Save(a,b).abs_Psi_2_int  = sum(abs(tt.Save.Temp.Sol.Psi_end).^2);    
            i
    end
    
end
%%
d_mu = abs(d_mu_mean);
flag_mu= NaN(61,347);
%flag_mu(d_mu > 1) = 5;
%flag_mu(d_mu <= 1) = 2;
%%
flag_mu(d_mu > 1)= 1;
flag_mu(d_mu_std >1)= 2;
flag_mu(d_mu <= 1)= 0;
%d_mu(d_mu < 10) = -2;
%%
d_m = NaN(141,1716);
for i=1:141
    for j=1:1716
        if ~isempty(t_Save(i,j).abs_Psi_2_int)
            d_m(i,j)= mean(t_Save(i,j).D_mu);
        end
    end
end
        
