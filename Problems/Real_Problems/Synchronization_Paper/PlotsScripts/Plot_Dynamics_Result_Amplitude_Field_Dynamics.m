function Plot_Dynamics_Result_Amplitude_Field_Dynamics(Temp)
%%

   tt_1 = proPlot(Temp.Sol.t/Temp.Eq.norm,sum(abs(Temp.Sol.Psi).^2*2*pi,2).' );
   tt_2 = proPlot(Temp.Sol.t/Temp.Eq.norm,max(abs(Temp.Sol.Psi).^2,[],2).');
   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    tt_1 = tt_1.changeAxisOptions('XLabelText','Time (s)',...
                         'YLabelText','Power (W)',...  
                         'FontSize',13 );
    tt_2 = tt_2.changeAxisOptions('XLabelText','Time (s)',...
                         'YLabelText','Power (W)',...  
                         'FontSize',13 );                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    tt_1 = tt_1.addInset(tt_1,[0,0,1,1])
    figure('Name','Integrative_Quant');
    CF = conFigure([tt_1,tt_2],1,2, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);

    

end
