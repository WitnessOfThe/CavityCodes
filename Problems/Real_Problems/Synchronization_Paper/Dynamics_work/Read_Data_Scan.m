clear all
%%
  load('/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Real_Problems/Synchronization_Paper/Dynamics_work/Tongues_Scan/Starter_CaF.mat');

%%

d_mu = zeros(44,341);
ind_t  = 15001:30000;

parfor i =1:44*341
    if  Sim_zone(i) == 1
        tt=load(strcat('/home/dp710/Data_Storage/CaF_35_Segment_1_L/Data/',num2str(i),'.mat'));
        N_t = size(ind_t,2);
        dt =  (tt.Save.Temp.Sol.t(ind_t(2)) - tt.Save.Temp.Sol.t(ind_t(1)))/tt.Save.Temp.Eq.norm;
        
        tau = ( tt.Save.Temp.Sol.t(ind_t(end)) - tt.Save.Temp.Sol.t(ind_t(1)) )/tt.Save.Temp.Eq.norm;
        f = [0:N_t/2-1,-N_t/2:-1]/tau*2*pi;
        
        Temp_Psi_1 = ifft(tt.Save.Temp.Sol.Psi_mu(ind_t,1)).'*N_t*dt/tau;
        Temp_Psi_2 = ifft(tt.Save.Temp.Sol.Psi_mu(ind_t,2)).'*N_t*dt/tau;
        
        omega_mu_p = trapz(f.*abs(Temp_Psi_1).^2)./trapz(abs(Temp_Psi_1).^2);
        omega_mu_m = trapz(f.*abs(Temp_Psi_2).^2)./trapz(abs(Temp_Psi_2).^2);
        d_mu(i)    = (omega_mu_p - omega_mu_m)/70;
        i
    end
    
end