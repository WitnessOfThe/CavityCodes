    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = 2*pi*25E9;
    Res.CW.In.delta_o = 0;
     Res.CW.In.N       = 2^8;
    Res.CW.In.mu_bl     = 1;     
    Res.CW.In.W       = 100000*Res.CW.In.W_Star;
    
%%
 
    W_Finish     = 10000;
    delta_Finish = 3;
    
    W                 = [1.3E2,23000];
    delta             = [-100,-2.8951];
    
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
    Res.Stat.Par.Turning    = 0;
    Res.Stat.Par.variable         = 'delta_o';  %%'Pump Power';
    Res.Stat.Par.bot_boundary     =  -100; % bottom boundary for delta to search
    Res.Stat.Par.top_boundary     =  100; % top boundary for delta to search
    
    Res.Stat.Par.first_step         = 0.01;
    Res.Stat.Par.step_tol         = 1E-4;
    Res.Stat.Par.step_inc         = 1.01;  
    Res.Stat.In.N         = 2^8;
    
    coeff_bound = [0.0001,1];
    Flag = false;
     ii =0;
    while Flag == 0
        
        coeff       = coeff_bound(1) + (coeff_bound(2) - coeff_bound(1))/2;
        Res                 = Chi23_Turing_From_CW(Res,coeff,1);
        ii                  = ii + 1;
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
    NN = 200;
    delta_vector = linspace(delta(2),-30,NN);
    Power_vector = linspace(W(2),13E5,NN);
    eps_vector   = linspace(Res.Stat.In.eps,30E9*2*pi,NN);
    Psi_o           = ifft(Res.Stat.Sol.Psi_o*Res.Stat.Space.N);
    Psi_e           = ifft(Res.Stat.Sol.Psi_e*Res.Stat.Space.N);
  
    Slv              = [real(Psi_o),imag(Psi_o)...
                    ,real(Psi_e),imag(Psi_e),Res.Stat.Sol.V];%
    for i = 1:NN
        
        Res.Stat.In.delta_o  = delta_vector(i)*Res.Stat.In.ko;
        Res.Stat.In.W        = Power_vector(i)*Res.Stat.In.W_Star;
        Res.Stat              = Res.Stat.Met.Norm(Res.Stat);

         
        [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,Res.Stat);
        eps_f
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
  
    Res1.Stat              = Run_Branch_Universal(Res.Stat);
%%
for i = 1:size(Res1.Stat,2)
        

  %      delta_vector(i)   = Res.Stat(i).In.eps/2/pi/1E9;
       delta_(i)   = Res1.Stat(i).Eq.delta_o;
       Max_vector(i)     =  max(abs(ifft(Res1.Stat(i).Sol.Psi_o*Res1.Stat(i).Space.N)).^2);
       Logic_vector(i)     = Res1.Stat(i).Logic.Dir.dif;
       Logic_vector2(i)     = abs(Res1.Stat(i).Logic.Dir.current)*0.1;
end
    figure;plot(delta_,Max_vector)

    figure;plot(delta_, Logic_vector, delta_,Logic_vector2)
%%    
    Res.Stat = Res1.Stat(10);
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

    for i = 83
        Res.Temp.In                = Res.Stat(i).In;    
        Res.Temp.Par.Runge_Type    = 'Runge SSPRK3';        
        Res.Temp.Par.dt            = 2E-5;
        Res.Temp.Par.s_t           = 0.01;
        Res.Temp.Par.T             = 100;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
        Res.Temp.Par.dd            = Res.Temp.Par.T/Res.Temp.Par.s_t;
        Res.Temp.Par.CW_num        = 1;
        Runge                      = Define_Runge_Coeff(Res.Temp.Par);

 
        Res.Temp.In.N     = 2^8;
        Res.Temp          = Res.Temp.Met.Norm(Res.Temp);   
        Res.Temp          = Chi23_StartFromBloch(Res.Stat(i),Res.Temp);   
        Res.Temp.Met      = [];

        tic
        Res.Temp.Sol      = Chi23_Runge_Kuarong_mex(Res.Temp,Runge);
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
