    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = -2*pi*5E9;
    Res.CW.In.delta_o = 0;
     Res.CW.In.N      = 2^8;
    Res.CW.In.mu_bl   = 5;     
    Res.CW.In.W       = 100000*Res.CW.In.W_Star;
    
%%
 
    W_Finish     = 10000;
    delta_Finish = 3;
    
    W                 = [1.3E2,5E7];%6.8088e+05
    delta             = [-100,-55 ];%-11.6907
    
    Res.CW            = Chi23_CW_Track_fromLower2Point(Res.CW,W,delta);
    
%%
%     Res.Stat.In           = Res.CW.In;
%     Res.Stat.Par.Turning    = 0;
%     Res.Stat.Par.variable         = 'eps';  %%'Pump Power';
%     Res.Stat.Par.bot_boundary     =  100; % bottom boundary for delta to search
%     Res.Stat.Par.top_boundary     =  30000; % top boundary for delta to search
%     
%     Res.Stat.Par.first_step         = 10;
%     Res.Stat.Par.step_tol         = 0.01;
%     Res.Stat.Par.step_inc         = 1.1;  
%     Res.Stat.In.N         = 2^6;

    Res.Stat.In           = Res.CW.In;
    Res.Stat.Par.Newton_tol       = 1E-10;  
     Res.Stat.Par.Turning    = 0;
    Res.Stat.Par.variable         = 'delta_o';  %%'Pump Power';
    Res.Stat.Par.bot_boundary     =  -100; % bottom boundary for delta to search
    Res.Stat.Par.top_boundary     =  100; % top boundary for delta to search
    
     Res.Stat.Par.Stability = 1;
    Res.Stat.Par.Newton_iter       = 100;
    Res.Stat.Par.first_step       = 0.1;
    Res.Stat.Par.step_tol         = 1E-2;
    Res.Stat.Par.step_inc         = 1.1;  
    Res.Stat.In.N                 = 2^8;
    
    coeff_bound = [0.0001,1];
    Flag = false;
     ii =0;
    while Flag == 0
        
        coeff       = coeff_bound(1) + (coeff_bound(2) - coeff_bound(1))/2;
        Res                 = Chi23_Turing_From_CW(Res,coeff,2);
        ii                  = ii + 1
        Logic.p1            = Res.Stat.Sol.Exitflag >= 0;
        Logic.p2            = sum(abs(Res.Stat.Sol.Psi_o(2:end))) > 1E-3;
        
        if (Logic.p1 && Logic.p2) || (ii == 30)
            
            break;
            
        end
        
        if Logic.p1 == 1 && Logic.p2 == 0
            
            coeff_bound(1) = coeff;
            
        end
        if Logic.p1 == 0 && Logic.p2 == 1
            
            coeff_bound(2) = coeff;
            
        end
        if Logic.p1 == 0 && Logic.p2 == 0
            
            coeff_bound(2) = coeff;
            
        end
        
    end
        Res.Stat              = Run_Branch_Universal(Res.Stat);

%%    
    NN = 500;
    delta_vector = linspace(-2.0884,-7,NN);%W(2)delta(2)
    Power_vector = linspace(23E3,1E5,NN);
    eps_vector   = linspace(Res.Stat.In.eps,Res.Stat.In.eps,NN);
    
    Psi_o           = ifft(Res.Stat.Sol.Psi_o*Res.Stat.Space.N);
    Psi_e           = ifft(Res.Stat.Sol.Psi_e*Res.Stat.Space.N);
  
    Slv              = [real(Psi_o),imag(Psi_o)...
                    ,real(Psi_e),imag(Psi_e),Res.Stat.Sol.V];%
    for i = 1:NN
        
        Res.Stat.In.delta_o  = delta_vector(i)*Res.Stat.In.ko;
        Res.Stat.In.W        = Power_vector(i)*Res.Stat.In.W_Star;
        Res.Stat              = Res.Stat.Met.Norm(Res.Stat);

         
        [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,Res.Stat);
        [i,eps_f]
    end
%     for i = 1:NN
%         
%         Res.Stat.In.eps      =  eps_vector(i);
%         Res.Stat              = Res.Stat.Met.Norm(Res.Stat);
% 
%          
%         [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,Res.Stat);
%         eps_f
%     end
    
    Res.Stat.Sol.Psi_o   = fft(Slv(1:Res.Stat.Space.N) + 1i*Slv(Res.Stat.Space.N+1:2*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.Psi_e   = fft(Slv(2*Res.Stat.Space.N+1:3*Res.Stat.Space.N) + 1i*Slv(3*Res.Stat.Space.N+1:4*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.V       = Slv(end);
    Res.Stat.Sol.eps_f   = eps_f;
    Res.Stat.Sol.Exitflag= Exitflag;
  
%%
clear delta_vector

for i = 1:size(Res.Stat,2)
        

        delta_vector(i)   = Res.Stat(i).In.delta_o/Res.Stat(i).In.ko;
      % delta_(i)   = Res1.Stat(i).Eq.delta_o;
       Max_vector(i)     =  max(abs(ifft(Res.Stat(i).Sol.Psi_o*Res.Stat(i).Space.N)).^2);
    %   Logic_vector(i)     = Res1.Stat(i).Logic.Dir.dif;
     %  Logic_vector2(i)     = abs(Res1.Stat(i).Logic.Dir.current)*0.1;
end
    figure;plot(delta_vector,Max_vector)

%    figure;plot(delta_vector,Max_vector)
%%    
    Res.Stat = Res.Stat;
    Res.Stat.In           = Res.CW.In;
    Res.Stat.Par.Turning    = 0;
    Res.Stat.Par.variable         = 'delta_o';  %%'Pump Power';
    Res.Stat.Par.bot_boundary     =  -100; % bottom boundary for delta to search
    Res.Stat.Par.top_boundary     =  100; % top boundary for delta to search
    
    Res.Stat.Par.first_step         = 0.1;
    Res.Stat.Par.step_tol         = 0.001;
    Res.Stat.Par.step_inc         = 1.1;  
    Res.Stat.In.N         = 2^8;    
    Res2.Stat              = Run_Branch_Universal(Res.Stat);
    
%%
    
   eps_vec     = [25E9,20E9,15E9,10E9]*2*pi;
 %  delt_vec     = -20.8265*ones(1,6);
   index_start = 1*ones(1,4);
     ResMet = Set_Up_Methods_For_Chi23_Paper;
  
   parfor i = 1:4
        
        ReSave(i)               = ResMet;
        ReSave(i).Temp.In       = Res.Stat(index_start(i)).In;
    %    ReSave(i).Temp.In.delta_o       = delt_vec(i)*ReSave(i).Temp.In.ko;
        ReSave(i).Temp.In.eps           =  eps_vec(i);
        
        ReSave(i).Temp.Par.Runge_Type    = 'Runge SSPRK3';        
        ReSave(i).Temp.Par.dt            = 1E-5;
        ReSave(i).Temp.Par.s_t           = 0.001;
        ReSave(i).Temp.Par.T             = 30; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
        ReSave(i).Temp.Par.dd            = ReSave(i).Temp.Par.T/ReSave(i).Temp.Par.s_t;
        ReSave(i).Temp.Par.CW_num        = 1;
        Runge                            = Define_Runge_Coeff(ReSave(i).Temp.Par);

 
         ReSave(i).Temp.In.N     = 2^8;
         ReSave(i).Temp          =  ReSave(i).Temp.Met.Norm( ReSave(i).Temp);   
         ReSave(i).Temp.Eq.Lo    =  ReSave(i).Temp.Eq.Lo - Res.Stat(index_start(i)).Sol.V*ReSave(i).Temp.Space.k;
         ReSave(i).Temp.Eq.Le    =  ReSave(i).Temp.Eq.Le - Res.Stat(index_start(i)).Sol.V*ReSave(i).Temp.Space.k;
         ReSave(i).Temp.Eq.L               = [ReSave(i).Temp.Eq.Lo,ReSave(i).Temp.Eq.Le]; 
         ReSave(i).Temp.In.Psi_Start = [Res.Stat(index_start(i)).Sol.Psi_o,Res.Stat(index_start(i)).Sol.Psi_e]*ReSave(i).Temp.In.N  ;
         ReSave(i).Temp.In.t_start = 0;
         ReSave(i).Temp.Met      = [];
        
   end
 
   parfor i = 1:4
        

        tic
         ReSave(i).Temp.Sol      = Chi23_Runge_Kuarong_mex( ReSave(i).Temp,Runge);
        toc
        
    end
    
%% Plot Dynamics
    indmu = 6;
    figure('Position',[0,0,1000,800/2],'Color',[1,1,1]);
    
    Panel = tiledlayout(2,2,'TileSpacing','none','Padding','none');   
   
    ax(1) = nexttile(Panel,1,[1,2]);hold(ax(1),'on');  
    ax(2) = nexttile(Panel,3,[1,1]);hold(ax(2),'on');  
    ax(3) = nexttile(Panel,4,[1,1]);hold(ax(3),'on');  
    
    plot(Res.Temp.Sol.t, (abs(Res.Temp.Sol.Psio(:,indmu)).^2),'Parent',ax(1));
%    plot(Res.Temp.Sol.t, (abs(Res.Temp.Sol.Psie(:,indmu)).^2),'Parent',ax(1));

  %  plot(Res.Temp.Sol.t, sum(abs(Res.Temp.Sol.Psio(:,[indmu,end-11])).^2,2),'Parent',ax(1));
  %  plot(Res.Temp.Sol.t, sum(abs(Res.Temp.Sol.Psie(:,[indmu,end-11])).^2,2),'Parent',ax(1));

    plot(fftshift(Res.Temp.Space.k),fftshift(10*log10(abs(Res.Temp.Sol.Psio(end-1,:)).^2 )),'Parent',ax(2),'Color',[1,0,0]); 
    plot(fftshift(Res.Temp.Space.k),fftshift(10*log10(abs(Res.Temp.Sol.Psie(end-1,:)).^2 )),'Parent',ax(3),'Color',[0,1,0]); 

    ax(1).XLabel.String = '$t,(s \cdot k_o)$';
    ax(1).YLabel.String = '$|\psi_\mu|^2$';
    
    ax(2).XLabel.String = 'Mode Number';
    ax(2).YLabel.String = 'Power (db)';
    
    ax(3).XLabel.String = 'Mode Number';
    ax(3).YLabel.String = 'Power (db)';
%   colorbar(ax(i));
    ax(3).YLim  = [-70,4];
    ax(2).YLim  = [-70,4];
    for i = 1:size(ax,2)
       axes_Style(ax(i));
       shading(ax(i),'interp');
    end
    
function axes_Style(ax)

     ax.Box      = 'on';
     ax.FontSize = 15;
     ax.TickLabelInterpreter = 'latex';
     ax.XLabel.Interpreter   = 'latex';
     ax.YLabel.Interpreter   = 'latex';
     
end
%%
