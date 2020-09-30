function [tt_1,tt_2] = Plot_Dynamics_Result_pcolors(Temp,step,Flag)
%%  
    Psi_k = zeros(size(Temp.Sol.Psi,1),Temp.Space.N); 
    
    for i = 1:size(Temp.Sol.Psi,1)
        
        Psi_k(i,Temp.Eq.mode_range) = Temp.Sol.Psi(i,:);
        
    end
    ind_Min_y = find(10*log10(abs(fftshift(Psi_k(end-1,:),2)).^2*2*pi)> -50,1,'first');
    ind_Max_y = find(10*log10(abs(fftshift(Psi_k(end-1,:),2)).^2*2*pi)> -50,1,'last');
    k = fftshift(Temp.Space.k);
    x_Bound= max( abs(k([ind_Min_y,ind_Max_y])) )+5;
    tt_1 = proPlot(k,Temp.Sol.t(1:step:end)/Temp.Eq.norm,10*log10(abs(fftshift(Psi_k,2)).^2*2*pi),'PlotType','pcolor','DownSample2DPlot',[5000 5000]);
    tt_2 = proPlot(Temp.Space.phi,Temp.Sol.t(1:step:end)/Temp.Eq.norm,abs(ifft(Psi_k/Temp.Space.N,[],2)),'PlotType','pcolor','DownSample2DPlot',[5000 5000]);
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    tt_1 = tt_1.changeAxisOptions('XLabelText','Mode Number',...
                         'YLabelText','Time (s)',...  
                         'FontSize',13 ,'CAxis', [-50,15],'XLim',[-x_Bound,x_Bound],'YLim',[min(Temp.Sol.t(1:step:end)/Temp.Eq.norm),max(Temp.Sol.t(1:step:end)/Temp.Eq.norm)]);
    tt_2 = tt_2.changeAxisOptions('XLabelText','$\theta$',...
                         'YLabelText','Time (s)',...  
                         'FontSize',13,'XLim',[-pi,pi],'YLim',[min(Temp.Sol.t(1:step:end)/Temp.Eq.norm),max(Temp.Sol.t(1:step:end)/Temp.Eq.norm)]);                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if Flag 
        figure('Name','Fields_Spectrums_Carpets');
        CF = conFigure([tt_1,tt_2],1,2, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);
    end

end
