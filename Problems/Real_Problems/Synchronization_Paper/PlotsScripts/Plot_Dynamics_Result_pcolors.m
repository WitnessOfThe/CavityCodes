function Plot_Dynamics_Result_pcolors(Temp,step)
%%  
    tt_1 = proPlot(fftshift(Temp.Space.k),Temp.Sol.t(1:step:end)/Temp.Eq.norm,10*log10(abs(fftshift(Temp.Sol.Psi(1:step:end,:),2)).^2*2*pi),'PlotType','pcolor');
    tt_2 = proPlot(Temp.Space.phi,Temp.Sol.t(1:step:end)/Temp.Eq.norm,abs(ifft(Temp.Sol.Psi(1:step:end,:)/Temp.Space.N,[],2)),'PlotType','pcolor' );
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    tt_1 = tt_1.changeAxisOptions('XLabelText','Mode Number',...
                         'YLabelText','Time (s)',...  
                         'FontSize',13 ,'CAxis', [-80,10],'XLim',[-20,20]);
    tt_2 = tt_2.changeAxisOptions('XLabelText','$\theta$',...
                         'YLabelText','Time (s)',...  
                         'FontSize',13,'XLim',[-pi,pi]);                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    figure('Name','Fields_Spectrums_Carpets');
    CF = conFigure([tt_1,tt_2],1,2, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);
    

end
