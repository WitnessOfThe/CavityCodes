    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    L_L.CW.In         = Params_SiN;
    L_L.CW.In.kappa   =  1E7*2*pi;%2*1E3*2*pi;%
    L_L.CW.In.P       = 2.5; 
    
%%
  NN = 1000;

  delta_vector  = linspace(-2,1000,NN);
  
  Mumber_Of_Modes_D2_Pos = zeros(1,NN);
  N_Mode                 = 2^10;
  tic
  
  W_MI_vector_1 = zeros(NN,size(N_Mode/2,2));
  W_MI_vector_2 = zeros(NN,size(N_Mode/2,2));

  parfor i = 1:NN
      
      SiN = L_L;        
      SiN.CW.In.delta =  delta_vector(i)*2*pi*1E9;
      
      SiN.CW       = SiN.CW.Met.Solve(SiN.CW,N_Mode);          
      [~,ind]   = max(abs(SiN.CW.Sol.Psi));
      
      SiN.CW.In.g  = SiN.CW.Sol.g(ind)*SiN.CW.Eq.norm;
      SiN.CW      = SiN.CW.Met.Mi_Formula(SiN.CW,N_Mode);          
      Mumber_Of_Modes_D2_Pos(i) = sum( (SiN.CW.An.Omega_mu(1,1:(end/2-1)) == 0 ));
      
      W_MI_vector_1 = zeros(NN,size(1:N_Mode/2,2));
      W_MI_vector_2 = zeros(NN,size(1:N_Mode/2,2));
      SiN =  [];    
  end
   toc
%%
tic
  Mumber_Of_Modes_D2_Neg = zeros(1,NN);
  L_L.CW.In.D(2)         = -L_L.CW.In.D(2);
  parfor i = 1:NN
      
      SiN = L_L;        
      SiN.CW.In.delta =  delta_vector(i)*2*pi*1E9;
      
      SiN.CW       = SiN.CW.Met.Solve(SiN.CW,N_Mode);          
      [~,ind]      = max(abs(SiN.CW.Sol.Psi));
      if SiN.CW.In.delta > 0 
          SiN.CW.In.g  = SiN.CW.Sol.g(3)*SiN.CW.Eq.norm;
      else
          SiN.CW.In.g  = SiN.CW.Sol.g(1)*SiN.CW.Eq.norm;
      end
      
      SiN.CW      = SiN.CW.Met.Mi_Formula(SiN.CW,N_Mode);          
      Mumber_Of_Modes_D2_Neg(i) = sum( (SiN.CW.An.Omega_mu(1,1:(end/2-1)) == 0 ));
       SiN =  [];    
         
  end
toc
%%

%%
pp_1 = proPlot(delta_vector,Mumber_Of_Modes_D2_Pos,'LineStyle','none','Marker','.');

pp_2 = proPlot(delta_vector,Mumber_Of_Modes_D2_Neg,'LineStyle','none','Marker','.');

    pp_1 = pp_1.changeAxisOptions('YLabelText','Synch Modes',...
        'FontSize',15,'XLabelText','','XLim',[min(delta_vector),max(delta_vector)]);
    
    pp_1 = pp_1.changeFigOptions('Height',8,...
                     'Width',18);
                 
    pp_2 = pp_2.changeAxisOptions('YLabelText','Synch Modes','FontSize',15,'XLabelText','$\delta_0$ (GHz)','XLim',[min(delta_vector),max(delta_vector)]);
    
    pp_2 = pp_2.changeFigOptions('Height',8,...
                     'Width',18);
cf = conFigure([pp_1,pp_2], 2,1, 'Height', 28, 'Width', 18, 'separation', 0,'Labels',false);

%%

%%
%save('H:\Documents\MATLAB\Matlab_Repo\Problems\Cavity_Codes\Problems\Real_Problems\Synchronization_Paper\Scripts_To_Draw_Tongues\delta_power_plate_3E8.mat','pp4')
