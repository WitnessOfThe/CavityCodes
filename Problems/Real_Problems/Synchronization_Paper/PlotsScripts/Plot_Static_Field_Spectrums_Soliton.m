function [tt_1,tt_2,tt_3] = Plot_Static_Field_Spectrums_Soliton(Stat,Flag)
    ome_rev              = zeros(1,Stat.Space.N);
    ome_rev(2:end/2)     = fliplr(Stat.In.omega_int(end/2+2:end));
    ome_rev(end/2+3:end) = fliplr(Stat.In.omega_int(2:end/2-1));
    ome_rev(1)           = Stat.In.omega_int(1);
    
    Stat.In.Delta_p  =  Stat.In.omega_int;
    Stat.In.Delta_m  = ome_rev;

%%  
    Bot_thld = -70;
    Psi_k    = zeros(2,Stat.Space.N); 
    
    ind_Min_y = find(10*log10(abs(fftshift(Stat.Sol.Psi_k,2)).^2*2*pi) > Bot_thld,1,'first');
    ind_Max_y = find(10*log10(abs(fftshift(Stat.Sol.Psi_k,2)).^2*2*pi) > Bot_thld,1,'last');
    
    k = fftshift(Stat.Space.k);
    
    x_Bound= max( abs(k([ind_Min_y,ind_Max_y])) )+5;
    
    Psi_k = Stat.Sol.Psi_k;
    Psi_2 =  ifft(Stat.Space.N*Psi_k(1,:));
    
    tt_1 = proPlot(     Stat.Space.phi, abs(Psi_2).^2 );   
    
    Write = strcat('V$/2\pi$=',num2str(Stat.Sol.V*Stat.Eq.norm),'Hz');
    
    tt_1 = tt_1.addData([-3.14,max(abs(Psi_2).^2),0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox','String', Write,'FontSize',18);
    
    tt_2 = proPlot(     fftshift(Stat.Space.k),10*log10(fftshift( abs(Psi_k(1,:)).^2*2*pi)),'PlotType','stem','BaseValue',Bot_thld,'Marker','none');
    
    tt_1 = tt_1.addData(     Stat.Space.phi,real(Psi_2));
    tt_1 = tt_1.addData(     Stat.Space.phi,imag(Psi_2));

    tt_3 = proPlot(k,fftshift(Stat.In.omega_int/Stat.In.kappa.*Stat.Eq.mask),'Color',[0,0,0],'LineWidth',1,'Marker','.');
    tt_3 = tt_3.addData(k,fftshift(Stat.In.Delta_p+Stat.In.Delta_m)/Stat.In.kappa/2,'Color',[0,0,1],'LineWidth',1,'Marker','.','MarkerSize',25);
        
    tt_3 = tt_3.addData(k,(Stat.Eq.delta+k.*Stat.Sol.V*Stat.Eq.norm)/Stat.In.kappa,'Color',[1,0,0],'LineWidth',2);
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

   tt_1 = tt_1.changeAxisOptions('XLabelText','$\theta$',...
                        'YLabelText','Power (W)',...  
                        'FontSize',13,'XLim',[-pi,pi] );
    tt_2 = tt_2.changeAxisOptions('XLabelText','Mode Number',...
                         'YLabelText','Power (db)',...  
                         'FontSize',13,'YLim',[Bot_thld,10*log10(max(max(abs(Psi_k).^2))*2*pi)+5],'XLim',[-x_Bound,x_Bound] );                     
    tt_3 = tt_3.changeAxisOptions('XLabelText','Mode Number',...
                         'YLabelText','$D_{int}/\kappa$',...  
                         'FontSize',13,'XLim',[-x_Bound,x_Bound],'YLim',[-5,5]);                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if Flag
        figure('Name','Fields_Spectrums');
        CF = conFigure([tt_2,tt_1,tt_3],1,3, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);
    end

end
