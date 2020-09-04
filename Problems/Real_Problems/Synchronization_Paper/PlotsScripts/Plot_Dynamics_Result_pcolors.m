function Plot_Dynamics_Result_pcolors(Temp)
%%  
    tt_1 = proPlot(fftshift(Temp.Space.k),Temp.Sol.t,10*log10(abs(fftshift(Temp.Sol.Psi,2)).^2*2*pi),'PlotType','pcolor');
    tt_2 = proPlot(Temp.Space.phi,Temp.Sol.t,abs(ifft(Temp.Sol.Psi/Temp.Space.N,[],2)).^2,'PlotType','pcolor' );
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    tt_1 = tt_1.changeAxisOptions('XLabelText','Mode Number',...
                         'YLabelText','Time (s)',...  
                         'FontSize',13 );
    tt_2 = tt_2.changeAxisOptions('XLabelText','$\theta$',...
                         'YLabelText','Time (s)',...  
                         'FontSize',13,'XLim',[-pi,pi] );                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    figure('Name','Fields_Spectrums_Carpets');
    CF = conFigure([tt_1,tt_2],1,2, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);
    

end
