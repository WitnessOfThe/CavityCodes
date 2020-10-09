function [tt_1,tt_2] = Plot_Static_Field_Stability(Stat,Flag)
%%  
    k = fftshift(Stat.Space.k);

   tt_1 = proPlot( real(Stat.Stab.E_values)/2/pi/1E3,imag(Stat.Stab.E_values)/2/pi/1E3,[],'LineStyle','none','Marker','*');    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

   Pertur = zeros(Stat.Space.N,1);
   for i =1:1:size(Stat.Stab.E_vectors,2)
       
       Pertur = Pertur + Stat.Stab.E_vectors(1:Stat.Space.N,i)+ conj(Stat.Stab.E_vectors(Stat.Space.N+1:2*Stat.Space.N,i));
       
   end
   Y_max = max(10*log10(abs(Pertur).^2));
   if abs(Y_max) == abs(Inf)
       Y_max =0;
   end
   tt_2 = proPlot( k,fftshift(10*log10(abs(Pertur).^2))...
       ,'PlotType','stem','BaseValue',max(10*log10(abs(Pertur).^2))-100);    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

   tt_1 = tt_1.changeAxisOptions('XLabelText','Re[$\lambda_\mu/2\pi$ (kHz)]',...
                        'YLabelText','Im[$\lambda_\mu/2\pi$ (kHz)]',...  
                        'FontSize',13,'YLim',[-1000,1000] );
   tt_2 = tt_2.changeAxisOptions('XLabelText','Mode Number',...
                        'YLabelText','Relative Power (db)',...  
                        'FontSize',13,'XLim',[-100,100],'YLim',[Y_max-100,Y_max]);                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if Flag
        figure('Name','Fields_Spectrums');
        CF = conFigure([tt_1,tt_2],1,2, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);
    end

end
