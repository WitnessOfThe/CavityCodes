function [tt_1,tt_2] = Plot_Dynamics_Rf_Spectrums(Temp,k_probe,ind_t)
%%
    for i=1:size(k_probe,2)
        
        ind(i) = find(Temp.Space.k(Temp.Eq.mode_range) == k_probe(i));
        
    end
    
   tt_1 = proPlot(Temp.Sol.t(ind_t)/Temp.Eq.norm,real(Temp.Sol.Psi(ind_t,ind(1))).' );
   
   for i = 2:size(ind,2)
       
       tt_1 = tt_1.addData(Temp.Sol.t(ind_t)/Temp.Eq.norm,real(Temp.Sol.Psi(ind_t,ind(i))).' );
       
   end
   i=1;
 %%  
   N_t = size(ind_t,2);
   
   f = [0:N_t/2-1,-N_t/2:-1]/( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) )*Temp.Eq.norm/1E3;
        dt =  (Temp.Sol.t(ind_t(2)) - Temp.Sol.t(ind_t(1)))/Temp.Eq.norm;
        tau = ( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) )/Temp.Eq.norm;
   
   i=1; 
   Temp_Psi = (ifft(Temp.Sol.Psi(ind_t,ind(i)))*N_t)*dt/tau;
   tt_2 = proPlot(fftshift(f),fftshift( 10*log10(abs( Temp_Psi).^2*2*pi)));
   
   
   for i = 2:size(ind,2)
       
       Temp_Psi = (ifft(Temp.Sol.Psi(ind_t,ind(i)))*N_t)*dt/tau;
       tt_2 = tt_2.addData(fftshift(f),fftshift( 10*log10(abs( Temp_Psi).^2*2*pi)) );
       
   end
   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    tt_1 = tt_1.changeAxisOptions('XLabelText','Time (s)',...
                         'YLabelText','Power (W)',...  
                         'FontSize',13 );
    tt_2 = tt_2.changeAxisOptions('XLabelText','RF (kHz)',...
                         'YLabelText','Power (W)',...  
                         'FontSize',13,'YLim',[-80,10],'XLim',[-250,250] );                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    tt_1 = tt_1.addInset(tt_1,[0,0,1,1])
    figure('Name','RF_Spectrums');
    CF = conFigure([tt_1,tt_2],1,2, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);

    

end
