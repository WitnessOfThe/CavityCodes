

%%
    path = 'C:\Users\dp710\Documents\For_Papp_meeting\With_Almost_Paper_Geometry\Data\';
  
%  path = 'C:\Users\dp710\Documents\For_Papp_meeting\D4_Only\';
  
  NN = 72;
    Power_Vector = linspace(0.01,0.4,NN);
    Delta_Vector = linspace(1,10,NN);

    for i = 1:72*72

        if  isfile(strcat(path,num2str(i),'.mat')) 

            tt    = load(strcat(path,num2str(i),'.mat'));
            [a,b] = ind2sub([NN,NN],i);

                t_Save(a,b)   = tt.Save;            
                i
        end

    end
%%%
%%
for i_p =1:NN
    for i_d = 60
        if ~isempty(t_Save(i_p,i_d).Temp)
            delta_matrix( i_p ,i_d) =  t_Save( i_p ,i_d).Temp.In.delta/t_Save( i_p ,i_d).Temp.In.kappa;
            power_matrix( i_p ,i_d) =  t_Save( i_p ,i_d).Temp.In.P;
            Conv( i_p ,i_d) = t_Save( i_p ,i_d).Temp.Sol.Power(1)./sum(t_Save( i_p ,i_d).Temp.Sol.Power);
            Power( i_p ,i_d) = sum(t_Save( i_p ,i_d).Temp.Sol.Power);            
         %   phi( i_p ,i_d)  =  trapz(k(tt.Save.Temp.Eq.mode_range).*t_Save(i_p ,i_d).Psi(1:end))./trapz(t_Save(i_p ,i_d).Psi(1:end));
        end
    end
end
%%
Power(Power==0) = NaN;
figure;mesh(delta_matrix,power_matrix,Power)
%%
i_p = 8;
%i_p = 42;
i_d = 27;
pp4= proPlot((fftshift([0:99,-100:-1])*1E12+t_Save(i_p,i_d).Temp.In.omega_p/2/pi)/1E12,fftshift(10*log10(t_Save(i_p,i_d).Temp.Sol.Power/max(t_Save(i_p,i_d).Temp.Sol.Power))),[],'PlotType','stem','BaseValue',-70,'Marker','none');
pp4=pp4.changeAxisOptions('FontSize',15,...
                          'XLabelText', '$\omega$ (THz)',...
                          'YLabelText', 'Power/max(Power) (dB)','YLim',[-70,5],'XLim',[100,270]);
Psi = zeros(1,256);
Psi(t_Save(i_p,i_d).Temp.Eq.mode_range) = t_Save(i_p,i_d).Temp.Sol.Psi_end;
Psi                                     = ifft(Psi)*256;

pp5= proPlot(linspace(-pi,pi,256),abs(Psi).^2,[],'Marker','none');
pp5=pp5.changeAxisOptions('FontSize',15,...
                          'XLabelText', '$\theta$',...
                          'YLabelText', 'Power [W]');
figure;
CF = conFigure([pp4,pp5],1,2, 'UniformPlots', true, 'Labels', false,'Height',10,'Width',40);

