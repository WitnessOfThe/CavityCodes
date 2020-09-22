function Plot_Dynamics_Result_Amplitude_Field_Dynamics(Temp,ind_t)
%%
    Psi_k = zeros(size(Temp.Sol.Psi,1),Temp.Space.N); 
    
    for i = 1:size(Temp.Sol.Psi,1)
        
        Psi_k(i,Temp.Eq.mode_range) = Temp.Sol.Psi(i,:);
        
    end

   Psi_Space  = ifft(Psi_k,[],2)*Temp.Space.N;
   tt_2 = proPlot(Temp.Sol.t(ind_t)/Temp.Eq.norm,(2*real(Psi_Space(ind_t,1)).'));
%%   
      N_t = size(ind_t,2);
   
   f = [0:N_t/2-1,-N_t/2:-1]/( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) )*Temp.Eq.norm/1E6;
   tt_1 = proPlot(fftshift(f),fftshift(  10*log10(abs(ifft(Psi_Space(ind_t,1))).^2*2*pi) )) ;

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
