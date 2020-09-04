function Plot_Dynamics_Rf_Spectrums(Temp,k_probe,ind_t)
%%
    for i=1:size(k_probe,2)
        
        ind(i) = find(Temp.Space.k == k_probe(i));
        
    end
   tt_1 = proPlot(Temp.Sol.t(ind_t)/Temp.Eq.norm,real(Temp.Sol.Psi(ind_t,ind(1))).' );
   
   for i = 2:size(ind,2)
       
       tt_1 = tt_1.addData(Temp.Sol.t(ind_t)/Temp.Eq.norm,real(Temp.Sol.Psi(ind_t,ind(i))).' );
       
   end
   i=1;
   
   tt_2 = proPlot(Temp.Sol.t/Temp.Eq.norm, fftshift(10*log10(abs(ifft((Temp.Sol.Psi(:,ind(i))).^2.')/size(Temp.Sol.Psi(:,ind(i)),2)).^2*2*pi)));
   
   N_t = size(ind_t,2);
   
   f = [0:N_t/2-1,-N_t/2:-1]/( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) )*Temp.Eq.norm/1E9;
   
   for i = 1:size(ind,2)
       
       tt_2 = tt_2.addData(fftshift(f),fftshift( 10*log10(abs(ifft((Temp.Sol.Psi(ind_t,ind(i))).^2.')/size(Temp.Sol.Psi(:,ind(i)),2)).^2*2*pi)));
       
   end
   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    tt_1 = tt_1.changeAxisOptions('XLabelText','Time (s)',...
                         'YLabelText','Power (W)',...  
                         'FontSize',13 );
    tt_2 = tt_2.changeAxisOptions('XLabelText','RF (GHz)',...
                         'YLabelText','Power (W)',...  
                         'FontSize',13,'YLim',[-80,10],'XLim',[-10,6] );                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    tt_1 = tt_1.addInset(tt_1,[0,0,1,1])
    figure('Name','RF_Spectrums');
    CF = conFigure([tt_1,tt_2],1,2, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);

    

end
