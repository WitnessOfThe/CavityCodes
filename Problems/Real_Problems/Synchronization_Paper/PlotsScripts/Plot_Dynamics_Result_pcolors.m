function Plot_Dynamics_Result_pcolors(Temp)
%%  
    tt_1 = proPlot(fftshift(Temp.Space.k),Temp.Sol.t,10*log10(abs(fftshift(Temp.Sol.Psi,2)).^2*2*pi),'PlotType','pcolor');
    tt_2 = proPlot(Temp.Space.phi,Temp.Sol.t,abs(ifft(Temp.Sol.Psi/Temp.Space.N,[],2)).^2,'PlotType','pcolor' );
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    tt_1 = tt_1.changeAxisOptions('XLabelText','Mode Number',...
                         'YLabelText','Power (dB)',...  
                         'FontSize',18 );
    tt_2 = tt_2.changeAxisOptions('XLabelText','$\theta$',...
                         'YLabelText','Power (W)',...  
                         'FontSize',18,'XLim',[-pi,pi] );                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    tt_1 = tt_1.addInset(tt_1,[0,0,1,1])
    figure(1);
    tt_1.plotData();
    figure(2);
    tt_2.plotData();
    

end
