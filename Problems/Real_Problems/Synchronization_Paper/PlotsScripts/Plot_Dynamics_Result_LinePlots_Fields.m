function Plot_Dynamics_Result_LinePlots_Fields(Temp)
%%  
    tt = proPlot(Temp.Space.phi,abs(ifft(Temp.Sol.Psi(1,:))/Temp.Space.N).^2 );
    tt = tt.addData(Temp.Space.phi,abs(ifft(Temp.Sol.Psi(floor(end/2),:))/Temp.Space.N).^2 );
    tt = tt.addData(Temp.Space.phi,abs(ifft(Temp.Sol.Psi(end,:))/Temp.Space.N).^2  );
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    tt = tt.changeAxisOptions('XLabelText','$\theta$',...
                         'YLabelText','Power (W)',...  
                         'FontSize',18,...
                         'XLim',[-pi,pi]);
figure(1);
tt.plotData();
    

end
