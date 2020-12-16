function [tt_1,tt_2] = Plot_Static_Field_Spectrums(Stat,ax)
%%  
    Bot_thld = -70;
    Psi_k    = zeros(2,Stat.Space.N); 
    
    ind_Min_y = find(10*log10(abs(fftshift(Stat.Sol.Psi_k,2)).^2*2*pi) > Bot_thld,1,'first');
    ind_Max_y = find(10*log10(abs(fftshift(Stat.Sol.Psi_k,2)).^2*2*pi) > Bot_thld,1,'last');
    
    k = fftshift(Stat.Space.k);
    
    x_Bound= max( abs(k([ind_Min_y,ind_Max_y])) )+5;
    
    Psi_k = Stat.Sol.Psi_k;
    Psi_2 =  ifft(Stat.Space.N*Psi_k(1,:));
    
%    tt_1 = proPlot(     Stat.Space.phi, abs(Psi_2).^2 );   
    
    Write_2 = strcat('V$/2\pi$=',num2str(Stat.Sol.V*Stat.Eq.norm),'Hz');
    Write_1 = strcat('Err=',num2str(Stat.Sol.eps));
    
 %    tt_1 = tt_1.addData([min(Stat.Space.phi)*0.9,max(abs(Psi_2).^2),0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox','String', Write_1,'FontSize',18);
    text(min(Stat.Space.phi)*0.9,max(abs(Psi_2)), Write_1,'FontSize',10,'Parent',ax(1),'Interpreter','latex');
    
    stem(fftshift(Stat.Space.k),10*log10(fftshift( abs(Psi_k(1,:)).^2*2*pi)),'BaseValue',Bot_thld,'Marker','none','Parent',ax(2));
    
%    tt_2 = proPlot(     fftshift(Stat.Space.k),10*log10(fftshift( abs(Psi_k(1,:)).^2*2*pi)),'PlotType','stem','BaseValue',Bot_thld,'Marker','none');
%    tt_2 = tt_2.addData([Stat.Space.k(end),Bot_thld+40,0,0], [], [], 'PlotType', 'Annotation', 'AnnotationType', 'textbox','String', Write_2,'FontSize',18);
    
%    tt_1 = tt_1.addData(     Stat.Space.phi,real(Psi_2));
%    tt_1 = tt_1.addData(     Stat.Space.phi,imag(Psi_2));
%    plot(Stat.Space.phi,imag(Psi_2),'Parent',ax(1));
    
    plot(Stat.Space.phi,abs(Psi_2).^2,'Parent',ax(1));
    plot(Stat.Space.phi,real(Psi_2),'Parent',ax(1));
    plot(Stat.Space.phi,imag(Psi_2),'Parent',ax(1));
    legend(ax(1),'Power','Re','Im','Orientation','horizontal','Location','northoutside');
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

         ax(1).XLabel.String = '$\theta$';
         ax(1).YLabel.String = 'Power (W)';
         ax(1).YLabel.Interpreter = 'latex';
         ax(1).XLim        = [min(Stat.Space.phi),max(Stat.Space.phi)];
         ax(1).FontSize             = 13;
         ax(1).XLabel.Interpreter   = 'latex';
         ax(1).TickLabelInterpreter = 'latex';
         ax(1).Box =                    'on';

         ax(2).XLabel.String = 'Mode Number';
         ax(2).YLabel.String ='Power (db)';
         ax(2).YLabel.Interpreter = 'latex';
         ax(2).XLim        = [-x_Bound,x_Bound];
         ax(2).YLim        = [Bot_thld,10*log10(max(max(abs(Psi_k).^2))*2*pi)+5];
         ax(2).FontSize             = 13;
         ax(2).XLabel.Interpreter   = 'latex';
         ax(2).TickLabelInterpreter = 'latex';
         ax(2).Box =                    'on';
         
%     tt_1 = tt_1.changeAxisOptions('XLabelText','$\theta$',...
%                         'YLabelText','Power (W)',...  
%                         'FontSize',13,'XLim',[min(Stat.Space.phi),max(Stat.Space.phi)] );
%     tt_2 = tt_2.changeAxisOptions('XLabelText','Mode Number',...
%                          'YLabelText','Power (db)',...  
%                          'FontSize',13,'YLim',[Bot_thld,10*log10(max(max(abs(Psi_k).^2))*2*pi)+5],'XLim',[-x_Bound,x_Bound] );                     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    if Flag
%        figure('Name','Fields_Spectrums');
%        CF = conFigure([tt_2,tt_1],1,2, 'UniformPlots', true, 'Height', 7, 'Width', 18,'Labels',false);
%    end

end
