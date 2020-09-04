function Plot_Dynamics_Result_LinePlots_Spectrums(Temp)
%%  
    tt_1 = proPlot(Temp.Space.phi,abs(ifft(Temp.Sol.Psi(1,:))).^2 );
    tt_1 = tt_1.addData(Temp.Space.phi,abs(ifft(Temp.Space.N*Temp.Sol.Psi(floor(end/2),:))).^2 );
    tt_1 = tt_1.addData(Temp.Space.phi,abs(ifft(Temp.Space.N*Temp.Sol.Psi(end,:))).^2  );
    
    tt_2 = proPlot(fftshift(Temp.Space.k),10*log10(fftshift(abs(Temp.Sol.Psi(1,:)).^2*2*pi)));
    tt_2 = tt_2.addData(fftshift(Temp.Space.k),10*log10(fftshift(abs(Temp.Sol.Psi(floor(end/2),:)).^2*2*pi)));
    tt_2 = tt_2.addData(fftshift(Temp.Space.k),10*log10(fftshift(abs(Temp.Sol.Psi(end,:)).^2*2*pi)));
    
%%%%%%%%    
    tt_1 = tt_1.changeAxisOptions('XLabelText','$\theta$',...
                         'YLabelText','Power (W)',...  
                         'FontSize',13 );
    tt_2 = tt_2.changeAxisOptions('XLabelText','Mode Number',...
                         'YLabelText','Power (db)',...  
                         'FontSize',13,'YLim',[-80,10*log10(max(max(abs(Temp.Sol.Psi).^2))*2*pi)+5] );                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    figure('Name','Fields_Spectrums');
    CF = conFigure([tt_1,tt_2],1,2, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);
    

end
