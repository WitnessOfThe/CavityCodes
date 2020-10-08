function [tt_1,tt_2] = Plot_Dynamics_Result_LinePlots_Spectrums(Temp,Flag)
%%  
    Psi_k = zeros(2,Temp.Space.N); 
    
    for i = 1:1
        
        Psi_k(1,Temp.Eq.mode_range) = Temp.Sol.Psi(end-1,:);
        
    end
    tt_1 = 0;
    ind_Min_y = find(10*log10(abs(fftshift(Psi_k(end-1,:),2)).^2*2*pi)> -50,1,'first');
    ind_Max_y = find(10*log10(abs(fftshift(Psi_k(end-1,:),2)).^2*2*pi)> -50,1,'last');
    k = fftshift(Temp.Space.k);
    x_Bound= max( abs(k([ind_Min_y,ind_Max_y])) )+5;

   tt_1 = proPlot(     Temp.Space.phi,abs( ifft(Temp.Space.N*Psi_k(1,:))).^2 );    
   tt_1 = tt_1.addData(Temp.Space.phi,abs( ifft(Temp.Space.N*Psi_k(floor(end/2),:))).^2 );
   tt_1 = tt_1.addData(Temp.Space.phi,abs( ifft(Temp.Space.N*Psi_k(end-1,:))).^2 );
    
    tt_2 = proPlot(     fftshift(Temp.Space.k),10*log10(fftshift( abs(Psi_k(1,:)).^2           *2*pi)),'PlotType','stem','BaseValue',-80,'Marker','none');
    tt_2 = tt_2.addData(fftshift(Temp.Space.k),10*log10(fftshift( abs(Psi_k(floor(end/2),:)).^2*2*pi)),'PlotType','stem','BaseValue',-80,'Marker','none');
    tt_2 = tt_2.addData(fftshift(Temp.Space.k),10*log10(fftshift( abs(Psi_k(end-1,:)).^2         *2*pi)),'PlotType','stem','BaseValue',-80,'Marker','none');
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

   tt_1 = tt_1.changeAxisOptions('XLabelText','$\theta$',...
                        'YLabelText','Power (W)',...  
                        'FontSize',13,'XLim',[-pi,pi] );
    tt_2 = tt_2.changeAxisOptions('XLabelText','Mode Number',...
                         'YLabelText','Power (db)',...  
                         'FontSize',13,'YLim',[-50,10*log10(max(max(abs(Temp.Sol.Psi).^2))*2*pi)+5],'XLim',[-x_Bound,x_Bound] );                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if Flag
        figure('Name','Fields_Spectrums');
        CF = conFigure([tt_2,tt_1],1,2, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);
    end

end
