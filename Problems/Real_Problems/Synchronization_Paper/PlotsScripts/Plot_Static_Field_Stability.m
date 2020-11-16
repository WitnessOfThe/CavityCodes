function [tt_1,tt_2,tt_3,tt_4] = Plot_Static_Field_Stability(Stat,Flag,mu)
%%  
    k = fftshift(Stat.Space.k);
    Bot_thld = -70;
    tt_1 = proPlot( real(Stat.Stab.E_values)/Stat.In.kappa,imag(Stat.Stab.E_values)/Stat.In.kappa,[],'LineStyle','none','Marker','*');    

       
    x_Bound        = 4*mu;
    
    ind_Bound_Real = find(real(Stat.Stab.E_values) > 0);

    Re_Bound   = abs(max(real(Stat.Stab.E_values( ind_Bound_Real)))*1.5);
    Im_Bound   = abs(max(imag(Stat.Stab.E_values( ind_Bound_Real)))*1.5)+0;
    
    if Re_Bound <  2* Stat.In.kappa 
        
        Re_Bound = 2*Stat.In.kappa;
        
    end
    
    if Im_Bound < 20*Stat.In.kappa
        
        Im_Bound = 20*Stat.In.kappa;
        
    end
    
    if  isempty(Re_Bound )
        
        Re_Bound = 2*Stat.In.kappa;
        
    end
    
    if  isempty(Im_Bound )
        
        Im_Bound = 20*Stat.In.kappa;
        
    end    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

   L_Re_pos             = real(Stat.Stab.Dres_Spec.lam);
   L_Re_pos(L_Re_pos<=0)= NaN;
   L_Re_pos(L_Re_pos>0) = 1;
   
   tt_2 = proPlot(      k,fftshift(imag(Stat.Stab.Dres_Spec.lam)/Stat.In.kappa,2),'Color',[0,0,0],'LineStyle','none','Marker','.');    
   tt_2 = tt_2.addData( k,fftshift(imag(Stat.Stab.Dres_Spec.lam).*L_Re_pos/Stat.In.kappa,2),'Color',[1,0,0],'LineStyle','none','Marker','.');    
   
   tt_3 = proPlot(      k,fftshift(real(Stat.Stab.Dres_Spec.lam),2)/Stat.In.kappa,'Color',[0,0,0],'LineStyle','none','Marker','.'); 
   tt_3 = tt_3.addData( k,fftshift(real(Stat.Stab.Dres_Spec.lam).*L_Re_pos/Stat.In.kappa,2),'Color',[1,0,0],'LineStyle','none','Marker','.'); 

   
   tt_4 =  proPlot([],[],[]);
    Y_Vect_Value = 0;
   if size(Stat.Stab.E_vectors,2) >= 2
       Pert_Vect(1:2,1:Stat.Space.N) = Stat.Stab.E_vectors(1:Stat.Space.N,1:2).'+conj(Stat.Stab.E_vectors(Stat.Space.N+1:2*Stat.Space.N,1:2)).';
       tt_4 = tt_4.addData( k,fftshift( 10*log10(abs(Pert_Vect(1,:)).^2) ),'Color',[0,0,1],'PlotType','stem','BaseValue',-70); 
       tt_4 = tt_4.addData( k,fftshift( 10*log10(abs(Pert_Vect(2,:)).^2) ),'Color',[1,0,0],'PlotType','stem','BaseValue',-70); 
   Y_Vect_Value = max([10*log10(abs(Pert_Vect(2,:)).^2),10*log10(abs(Pert_Vect(2,:)).^2)]);
   end
   if size(Stat.Stab.E_vectors,2) >= 4
       Pert_Vect(1:4,1:Stat.Space.N) = Stat.Stab.E_vectors(1:Stat.Space.N,1:4).'+conj(Stat.Stab.E_vectors(Stat.Space.N+1:2*Stat.Space.N,1:4)).';
       tt_4 = tt_4.addData( k,fftshift( 10*log10(abs(Pert_Vect(1,:)).^2) ),'Color',[0,0,1],'PlotType','stem','BaseValue',-70); 
       tt_4 = tt_4.addData( k,fftshift( 10*log10(abs(Pert_Vect(2,:)).^2) ),'Color',[0,0,1],'PlotType','stem','BaseValue',-70); 
       tt_4 = tt_4.addData( k,fftshift( 10*log10(abs(Pert_Vect(3,:)).^2) ),'Color',[1,0,0],'PlotType','stem','BaseValue',-70); 
       tt_4 = tt_4.addData( k,fftshift( 10*log10(abs(Pert_Vect(4,:)).^2) ),'Color',[1,0,0],'PlotType','stem','BaseValue',-70); 
       Y_Vect_Value = max([10*log10(abs(Pert_Vect(2,:)).^2),10*log10(abs(Pert_Vect(2,:)).^2)]);
   end
   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

   tt_1 = tt_1.changeAxisOptions('XLabelText','Re[$\lambda_\mu/\kappa$]',...
                        'YLabelText','Im[$\lambda_\mu/\kappa$]',...  
                        'FontSize',13,'XLim',[-Re_Bound,Re_Bound]/Stat.In.kappa,'YLim',[-Im_Bound,Im_Bound]/Stat.In.kappa );%'YLim',[-1000,1000]
   tt_2 = tt_2.changeAxisOptions('XLabelText','Mode Number',...
                        'YLabelText','Im[$\lambda_{\mu}/\kappa$]',...  
                        'FontSize',13,'XLim',[-x_Bound,x_Bound],'YLim',[-Im_Bound,Im_Bound]/Stat.In.kappa);     %,'YLim',[Y_max-100,Y_max]                
   tt_3 = tt_3.changeAxisOptions('XLabelText','Mode Number',...
                        'YLabelText','Re[$\lambda_{\mu}/\kappa$]',...  
                        'FontSize',13,'XLim',[-x_Bound,x_Bound],'YLim',[-Re_Bound,Re_Bound]/Stat.In.kappa);                   %,'XLim',[-100,100]  
   tt_4 = tt_4.changeAxisOptions('XLabelText','Mode Number',...
                        'YLabelText','Eigen vect Amplitude',...  
                        'FontSize',13,'XLim',[-x_Bound,x_Bound],'YLim',[Y_Vect_Value-50,Y_Vect_Value+10]);                   %,'XLim',[-100,100]  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if Flag
        figure('Name','Fields_Spectrums');
        CF = conFigure([tt_1,tt_2,tt_3,tt_4],1,4, 'UniformPlots', true, 'Height', 7, 'Width', 25,'Labels',false);
    end

end
