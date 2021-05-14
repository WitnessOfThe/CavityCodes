    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = 2*pi*23E9; 
%   Res.CW.In.delta_o = -10.122*Res.CW.In.ko;%-1.785*Res.CW.In.ko
%   Res.CW.In.W       = 3.1E6*Res.CW.In.W_Star;%2E4*Res.CW.In.W_Star;
%    Res.CW.In.delta_o = 12* Res.CW.In.ko;%-1.785*Res.CW.In.ko
%    Res.CW.In.W       = 3.1E6*Res.CW.In.W_Star;%2E4*Res.CW.In.W_Star;
%     Res.CW.In.delta_o = -40.13*Res.CW.In.ko;%-1.785*Res.CW.In.ko
%     Res.CW.In.W       = 3.1E7*Res.CW.In.W_Star;%2E4*Res.CW.In.W_Star;
%   Res.CW.In.delta_o = -10.122*Res.CW.In.ko;%-1.785*Res.CW.In.ko
%   Res.CW.In.W       = 3.1E6*Res.CW.In.W_Star;%2E4*Res.CW.In.W_Star;

    Res.CW.In.delta_o = 3.18*Res.CW.In.ko;%-1.785*Res.CW.In.ko
    Res.CW.In.W       = 333E-6;%5E5*Res.CW.In.W_Star;%2E4*Res.CW.In.W_Star;
    Res.CW.In.N       = 2^8;
    Res.Stat.In.N     = 2^8;
   
    Res.CW.In.mu_bl   = 1;
%
%    load('Soliton_50.mat');
  %  Res = ;
 %   Res.Stat = Start_From_Temp(ResSave(3).Temp,Res.Stat,1);
    
  % delta_vec = linspace(Res.Stat.In.delta_o,Res.CW.In.delta_o,100);
  % Res.Stat = ChangeDelta(Res.Stat,delta_vec);
%   Power_vec = linspace(Res.Stat.In.W,6E-3,200);
%   Res.Stat = ChangePower(Res.Stat,Power_vec);
% %%    
%     delta_vec = linspace(Res.Stat.In.delta_o,-9*Res.CW.In.ko,100);
%     Res.Stat = ChangeDelta(Res.Stat,delta_vec);
%    Res = Start_From_CW(Res);
     Br                   = Chi2_Get_CW_Point2Point(Res.CW,-[8*Res.CW.In.ko,0*Res.CW.In.ko],1000);    
%     
    figure;hold on;
  plot(Br.delta_vector/Res.CW.In.ko,Br.Omega(:,1)/2/pi/1E6,'Color','m','LineWidth',2);
  plot(Br.delta_vector/Res.CW.In.ko,Br.Omega(:,2)/2/pi/1E6,'Color','m','LineWidth',2);
  plot(Br.delta_vector/Res.CW.In.ko,Br.Omega(:,3)/2/pi/1E6,'Color','m','LineWidth',2);
% 
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

    Res.Stat(1).Par.Newton_tol       = 9E-13;  
    Res.Stat(1).Par.Turning          =    0;
    Res.Stat(1).Par.variable         = 'delta_o';  %%'Pump Power';
    Res.Stat(1).Par.bot_boundary     = -1E8; % bottom boundary for delta to search
    Res.Stat(1).Par.top_boundary     =  1E8; % top boundary for delta to search
    
    Res.Stat(1).Par.Stability        = 0;
    Res.Stat(1).Par.Newton_iter      = 200;
    Res.Stat(1).Par.first_step       = 1E-1;
    Res.Stat(1).Par.max_step         = 0.2;
    Res.Stat(1).Par.step_tol         = 1E-9;
    Res.Stat(1).Par.step_inc         = 1.1;  
    Res.Stat.Par.i_max               = 1000;
        
%    Res.Stat.In.N                 = 2^7;   
    

%%    
     Res = Start_From_CW(Res,0);
%    load('Soliton_25.mat');
%    Res.Stat = Start_From_Temp(ResSave(1).Temp,Res.Stat,1);
    Res.Stat              = Run_Branch_Universal_Turning(Res.Stat);

   %%
   Res.Stat = Res.Stat.Met.Norm(Res.Stat);
   x_0 = Res.Stat.Eq.(Res.Stat.Par.variable);
   %%
   PlotSome(Res(1));
%%   
  sg= -1;
  for i = 5:10
      if i > 1
        sg = sign(Res(i).Stat(end).In.eps - Res(i).Stat(end-1).In.eps);
      end
      x_0 = Res(i).Stat(end).Eq.(Res(i).Stat(end).Par.variable);
      Res(i+1).Stat          =   BranchTurning([real(ifft(Res(i).Stat(end).Sol.Psi_o))...
          ,imag(ifft(Res(i).Stat(end).Sol.Psi_o)),real(ifft(Res(i).Stat(end).Sol.Psi_e))...
          ,imag(ifft(Res(i).Stat(end).Sol.Psi_e)),Res(i).Stat(end).Sol.V...
          /Res(i).Stat(end).Space.N]*Res(i).Stat(end).Space.N,x_0,Res(i).Stat(end), sg);                
    PlotSome(Res(i+1));
      
  end
%%    
 % 
 
%   PlotBrSone(Res.Stat(1));
   
i1 = 5;
ii = 100;
plot(Res(i1).Stat(ii).In.eps/2/pi/1E9,...
max(abs(ifft(Res(i1).Stat(ii).Sol.Psi_o*2^8)).^2),'Marker','*','Color',[0,0,0])
%%
figure;
plot(Res(i1).Stat(ii).Space.phi,...
abs(ifft(Res(i1).Stat(ii).Sol.Psi_o*2^8)).^2)

%%

    Res.Stat              = Run_Branch_Universal_Turning(Res.Stat);

   %%
%    ind = 10;
%     Res.Stat(ind).Par.Newton_tol       = 1E-10;  
%     Res.Stat(ind).Par.Turning          =    0;
%     Res.Stat(ind).Par.variable         = 'delta_o';  %%'Pump Power';
%     Res.Stat(ind).Par.bot_boundary     = -100E7; % bottom boundary for delta to search
%     Res.Stat(ind).Par.top_boundary     =  100E7; % top boundary for delta to search
%     
%     Res.Stat(ind).Par.Stability        = 0;
%     Res.Stat(ind).Par.Newton_iter      = 200;
%     Res.Stat(ind).Par.first_step       = 1E-3;
%     Res.Stat(ind).Par.step_tol         = 1E-6;
%     Res.Stat(ind).Par.step_inc         = 1.01;  
%     Res1.Stat                        = Run_Branch_Universal(Res.Stat(ind));
% %%
%     indd = 486;
%     Res1.Stat(indd).Par.Newton_tol       = 1E-10;  
%     Res1.Stat(indd).Par.Turning          =    0;
%     Res1.Stat(indd).Par.variable         = 'W';  %%'Pump Power';
%     Res1.Stat(indd).Par.bot_boundary     = 0; % bottom boundary for delta to search
%     Res1.Stat(indd).Par.top_boundary     = 100E7; % top boundary for delta to search
%     
%     Res1.Stat(indd).Par.Stability        = 0;
%     Res1.Stat(indd).Par.Newton_iter      = 200;
%     Res1.Stat(indd).Par.first_step       = 1E-12;
%     Res1.Stat(indd).Par.step_tol         = 1E-18;
%     Res1.Stat(indd).Par.step_inc         = 1.01;  
%     Res2.Stat                           = Run_Branch_Universal(Res1.Stat(indd));
% %%
%     indd = 1350;
%     Res3.Stat(indd).Par.Newton_tol       = 1E-10;  
%     Res3.Stat(indd).Par.Turning          =    0;
%     Res3.Stat(indd).Par.variable         = 'delta_o';  %%'Pump Power';
%     Res3.Stat(indd).Par.bot_boundary     = -10E7; % bottom boundary for delta to search
%     Res2.Stat(indd).Par.top_boundary     = 100E7; % top boundary for delta to search
%     
%     Res2.Stat(indd).Par.Stability        = 0;
%     Res2.Stat(indd).Par.Newton_iter      = 200;
%     Res2.Stat(indd).Par.first_step       = 1E-1;
%     Res2.Stat(indd).Par.step_tol         = 1E-4;
%     Res2.Stat(indd).Par.step_inc         = 1.01;  
%     Res3.Stat                           = Run_Branch_Universal(Res2.Stat(indd));
% 
    
%%
  %  Res.Stat = Stat_1(1,1:end);
 %
   PlotSome(Res(1));
%%   %   PlotSome(Res(1));

   PlotBrSone(Res.Stat(10));
%%

%%
Stat_1 = Res.Stat
    parfor i = 1:size(Stat_1,2)
        tic
            Stat_1(i).Stab                 = Stability_Switcher(Stat_1(i));            
        toc
    end
    Res.Stat= Stat_1;
%%
for i = 1:size(Res.Stat,2)
    deltao(i)      = Res.Stat(i).In.eps/2/pi/1E9;
    PsiO(i,:)      = ifft(Res.Stat(i).Sol.Psi_e);
end
%
figure;pcolor(Res.Stat(1).Space.phi,deltao ,abs(PsiO));shading interp
%%
    
  function PlotSome(Res)
%%  a
%    Res.Stat(1:700) = [];
    a = 1000;
    f1 = figure('Position',[0,0,a,a*0.618],'Color',[1,1,1]);
    Panel = tiledlayout(1,4,'TileSpacing','none','Padding','none','Parent',f1);  
    
    for i = 1:4
        
        ax(i) = nexttile(Panel,i,[1,1]);  
        hold(ax(i),'on');
        
    end
%%
    E_Values = zeros(size(Res.Stat,2),10);
    
    for i = 1:size(Res.Stat,2)
        
        Psi_hat_o(i,:)    = Res.Stat(i).Sol.Psi_o;
        Psi_hat_e(i,:)    = Res.Stat(i).Sol.Psi_e;
        delta_vector(i)   = Res.Stat(i).Eq.delta_o;%W/Res.Stat(i).In.W_Star;%delta_o/ Res.Stat(i).In.ko;%/2/pi/1E9;%delta_o;%.eps/2/pi/1E9
        V_vector(i)       = Res.Stat(i).Sol.V; %Res.Stat(i).Sol.V;
  %      [~,]              = max(abs(Res.Stat(i).Stab(1).E_values));
        [V_zero_value(i),ind]   = min(abs(Res.Stat(i).Stab(1).E_values));
%        V_zero_value(i)         = 
        Res.Stat(i).Stab(1).E_values(ind) = [];
        max_psi(i) = max(abs(ifft( Res.Stat(i).Sol.Psi_o)*Res.Stat(i).Space.N).^2);
        
        for j = 1:size(Res.Stat(i).Stab,2)
            
           E_Values(i,:) =  maxk([E_Values(i,:).';real(Res.Stat(i).Stab(j).E_values)],10);
           
        end
        
        if max(E_Values(i,:)) > 0
            
            Stable(i) = false;
            
        else
            
            Stable(i) = true;
            
        end        
    end
    
    plot(delta_vector,Psi_hat_o(:,end),'Color',[1,0,0],'Parent',ax(1));
%    plot(delta_vector,abs(Psi_hat_e(:,end)).^2,'Color',[.39 .83 .07],'Parent',ax(1));
 %   plot(delta_vector(Stable),abs(Psi_hat_o(Stable,2)).^2,'Color',[1,0,0],'Parent',ax(1),'LineWidth',2);
%    plot(delta_vector,abs(Psi_hat_e(:,2)).^2,'Color',[0,0,1],'Parent',ax(1));
 %   plot(delta_vector(Stable),abs(Psi_hat_e(Stable,2)).^2,'Color',[0,0,1],'Parent',ax(1),'LineWidth',2);

    plot(delta_vector,V_zero_value,'Color',[0,0,0],'Parent',ax(2));
  %  plot(delta_vector(Stable),V_vector(Stable),'Color',[0,0,0],'Parent',ax(2),'LineWidth',2);
    plot(delta_vector,max_psi.','Color',[1,0,0],'Parent',ax(3),'LineWidth',1,'MarkerSize',20);
    dd = delta_vector;
    dd(Stable==0) =NaN;
    mp =max_psi;
    mp(Stable==0) =NaN;
    plot(dd,mp.','Color',[1,0,0],'Parent',ax(3),'LineWidth',2,'MarkerSize',20);

    plot(E_Values,'Color',[0,0,0],'Parent',ax(4),'LineStyle','none','Marker','.','MarkerSize',20);
 
    for i = 1:size(ax,2)
        
       axes_Style(ax(i));
       
    end
    
    function axes_Style(ax)

         ax.Box                  = 'on';
         ax.FontSize             = 15;
         ax.TickLabelInterpreter = 'latex';
         ax.XLabel.Interpreter   = 'latex';
         ax.YLabel.Interpreter   = 'latex';

    end
  end
  function Stat = Start_From_Temp(Temp,Stat,mu)
  
    Stat              = Stat(1);
    N                 = Stat(1).In.N;
    Stat.In           = Temp.In;
    Stat.In.N         = N;
    Stat.Sol.Psi_o    = zeros(1,N);
    Stat.Sol.Psi_e    = zeros(1,N);
    Stat.Sol.Psi_o(1) = Temp.Sol.Psio(end-1,1);
    Stat.Sol.Psi_e(1) = Temp.Sol.Psie(end-1,1);
    if mu == 1

            Stat.Sol.Psi_o = Temp.Sol.Psio(end-1,:);
            Stat.Sol.Psi_e = Temp.Sol.Psie(end-1,:);
        
    else
        for i = 1:round(Temp.Space.N/2/mu)

            Stat.Sol.Psi_o(1+i) = Temp.Sol.Psio(end-1,1+i*mu);
            Stat.Sol.Psi_e(1+i) = Temp.Sol.Psie(end-1,1+i*mu);
            Stat.Sol.Psi_o(end-i+1) = Temp.Sol.Psio(end-1,end-i*mu+1);
            Stat.Sol.Psi_e(end-i+1) = Temp.Sol.Psie(end-1,end-i*mu+1);

        end 
    end
    
    Stat                    = Stat.Met.Norm(Stat);
    Stat.Sol.Psi_o          = ifft(Stat.Sol.Psi_o*Stat.Space.N);
    Stat.Sol.Psi_e          = ifft(Stat.Sol.Psi_e*Stat.Space.N);
    
    Slv_Start               = [real(Stat.Sol.Psi_o),imag(Stat.Sol.Psi_o)...
                    ,real(Stat.Sol.Psi_e),imag(Stat.Sol.Psi_e),0.];%

    [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Stat);
    
    Stat.Sol.Psi_o   = fft(Slv(1:Stat.Space.N) + 1i*Slv(Stat.Space.N+1:2*Stat.Space.N))/Stat.Space.N;
    Stat.Sol.Psi_e   = fft(Slv(2*Stat.Space.N+1:3*Stat.Space.N) + 1i*Slv(3*Stat.Space.N+1:4*Stat.Space.N))/Stat.Space.N;
    
    Stat.Sol.V       = Slv(end);
    Stat.Sol.eps_f   = eps_f;
    
    Stat.Sol.Exitflag = Exitflag;
  
  
  end  
  function Res = Start_From_CW(Res,muh)
  
    coeff_bound_s = [1E-10,0.32];
    Flag = false;
        
    W                 = [1.3E4, Res.CW.In.W/ Res.CW.In.W_Star];
    delta             = [10,Res.CW.In.delta_o/Res.CW.In.ko];
    
    Res.CW            = Chi23_CW_Track_fromLower2Point(Res.CW,W,delta);
    
    N                 = Res.Stat.In.N;
    Res.Stat.In       = Res.CW.In;
    Res.Stat.In.N     = N;    
    
    for i_try = 1:2
        
        coeff_bound = coeff_bound_s;
            ii   = 0;
        
        while Flag == 0

            coeff               = coeff_bound(1) + (coeff_bound(2) - coeff_bound(1))/2;
            Res                 = Chi23_Turing_From_CW(Res,coeff,i_try,muh);
            ii                  = ii + 1;
            Logic.p1            = Res.Stat.Sol.Exitflag >= 0;
            Logic.p2            = sum(abs(Res.Stat.Sol.Psi_o(2:end))) > 1E-3;

            if (Logic.p1 && Logic.p2) || (ii == 30)
                Flag =1;
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
        if Flag ~= 0
            break;
        end
    end

  end
  function Stat = ChangePower(Stat,Power_vec)
  
    Stat.Sol.Psi_o          = ifft(Stat.Sol.Psi_o*Stat.Space.N);
    Stat.Sol.Psi_e          = ifft(Stat.Sol.Psi_e*Stat.Space.N);
    
    Slv_Start               = [real(Stat.Sol.Psi_o),imag(Stat.Sol.Psi_o)...
                    ,real(Stat.Sol.Psi_e),imag(Stat.Sol.Psi_e),0.];%
    for i = 1:size(Power_vec,2)
        Stat.In.W = Power_vec(i);
        Stat                    = Stat.Met.Norm(Stat);
        [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Stat);
        [i,eps_f]
    end
    
    Stat.Sol.Psi_o   = fft(Slv(1:Stat.Space.N) + 1i*Slv(Stat.Space.N+1:2*Stat.Space.N))/Stat.Space.N;
    Stat.Sol.Psi_e   = fft(Slv(2*Stat.Space.N+1:3*Stat.Space.N) + 1i*Slv(3*Stat.Space.N+1:4*Stat.Space.N))/Stat.Space.N;
    
    Stat.Sol.V       = Slv(end);
    Stat.Sol.eps_f   = eps_f
    
    Stat.Sol.Exitflag = Exitflag;

  end
 function Stat = ChangeDelta(Stat,delta_vec)
  
    Stat.Sol.Psi_o          = ifft(Stat.Sol.Psi_o*Stat.Space.N);
    Stat.Sol.Psi_e          = ifft(Stat.Sol.Psi_e*Stat.Space.N);
    
    Slv_Start               = [real(Stat.Sol.Psi_o),imag(Stat.Sol.Psi_o)...
                    ,real(Stat.Sol.Psi_e),imag(Stat.Sol.Psi_e),0.];%
    for i = 1:size(delta_vec,2)
        Stat.In.delta_o = delta_vec(i);
        Stat                    = Stat.Met.Norm(Stat);
        [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Stat);
        [i,eps_f]
    end
    
    Stat.Sol.Psi_o   = fft(Slv(1:Stat.Space.N) + 1i*Slv(Stat.Space.N+1:2*Stat.Space.N))/Stat.Space.N;
    Stat.Sol.Psi_e   = fft(Slv(2*Stat.Space.N+1:3*Stat.Space.N) + 1i*Slv(3*Stat.Space.N+1:4*Stat.Space.N))/Stat.Space.N;
    
    Stat.Sol.V       = Slv(end);
    Stat.Sol.eps_f   = eps_f;
    
    Stat.Sol.Exitflag = Exitflag;

  end
  
    function PlotBrSone(Stat)
%%  a
    a = 1000;
    f1 = figure('Position',[0,0,a,a*0.618],'Color',[1,1,1]);
    Panel = tiledlayout(1,3,'TileSpacing','none','Padding','none','Parent',f1);  
    
    for i = 1:3
        
        ax(i) = nexttile(Panel,i,[1,1]);  
        hold(ax(i),'on');
        
    end
    
%%
  for i = 1:size(Stat.Stab,2)
      
      nu(i)   = Stat.Stab(i).In.n;
      Evalues(i,:) = Stat.Stab(i).E_values;
       
  end
    plot( nu,imag( Evalues),'Color',[0,0,0],'Parent',ax(1),'LineStyle','none','Marker','.','MarkerSize',10);
    plot( nu,real( Evalues),'Color',[0,0,0],'Parent',ax(2),'LineStyle','none','Marker','.','MarkerSize',10);
    plot( real( Evalues(:,:)),imag(Evalues(:,:)),'Color',[0,0,0],'Parent',ax(3),'LineStyle','none','Marker','.','MarkerSize',10);
     
    for i = 1:size(ax,2)
        
       axes_Style(ax(i));
       
    end
    
    function axes_Style(ax)

         ax.Box                  = 'on';
         ax.FontSize             = 15;
         ax.TickLabelInterpreter = 'latex';
         ax.XLabel.Interpreter   = 'latex';
         ax.YLabel.Interpreter   = 'latex';

    end
  end
