function Plot_Dynamics_Result_LinePlots_Fields(Temp)
%%  
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    tt_1 = tt_1.changeAxisOptions('XLabelText','$\theta$',...
                         'YLabelText','Power (W)',...  
                         'FontSize',18,...
                         'XLim',[-pi,pi]);
figure(1);
tt_1.plotData();
    

end
