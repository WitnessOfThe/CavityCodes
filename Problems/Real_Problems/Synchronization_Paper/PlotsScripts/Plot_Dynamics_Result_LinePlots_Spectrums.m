function Plot_Dynamics_Result_LinePlots_Spectrums(Temp)
%%  
    tt = proPlot(fftshift(Temp.Space.k),10*log10(fftshift(abs(Temp.Sol.Psi(1,:)).^2*2*pi)));
    tt = tt.addData(fftshift(Temp.Space.k),10*log10(fftshift(abs(Temp.Sol.Psi(floor(end/2),:)).^2*2*pi)));
    tt = tt.addData(fftshift(Temp.Space.k),10*log10(fftshift(abs(Temp.Sol.Psi(end,:)).^2*2*pi)));
%%%%%%%%    
    tt.axis1Options.FontSize = 18;
    tt.axis1Options.XLabelText = 'Mode Number';
    tt.axis1Options.YLabelText = 'Power (dB)';
figure;
tt.plotData;
    

end
