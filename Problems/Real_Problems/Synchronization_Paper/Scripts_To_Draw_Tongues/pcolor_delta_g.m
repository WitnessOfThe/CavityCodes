    clc;
    clear all;
    
%% Define Input Parameters in Physical Units

    L_L       =  Set_Up_Methods_For_Synchronization_Paper;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input Parameters for CaF

    L_L.CW.In         = Params_CaF;
    L_L.CW.In.kappa   =  1E3*2*pi;%2*1E3*2*pi;%
    L_L.CW.In.P       = 0.00000000001; 

%%
  N = 200;   
  N_Mode = 30;
  
  delta_vector  = linspace(-3.8,4,N);
  P_vector      = linspace(0,1,N);
  
  Mumber_Of_Modes = zeros(N);
  tic
  parfor i = 1:N
      CW = L_L.CW;        
      CW.In.delta =  delta_vector(i)*2*pi*1E6;
      
      for ii = 1:N
          
          CW.In.P = P_vector(ii);
          CW      = MI(CW,N_Mode);
          [~,ind]     = min(abs(CW.Sol.Psi));
          Mumber_Of_Modes(ii,i) = sum( abs(imag(CW.Stab(ind).Value(1:end/2-1,1))) < 1E-13 );
          
      end
             
  end
   toc
%%
pp4 = proPlot(delta_vector,P_vector, Mumber_Of_Modes, 'PlotType','pcolor');
    
%%
figure;
pp4.plotData
