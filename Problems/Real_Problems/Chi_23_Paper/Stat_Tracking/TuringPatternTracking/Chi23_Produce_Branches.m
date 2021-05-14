    clear all;

%%
     
   
%%  
    delta_start  = -3.9;

    parfor i = 21:30
       Res(i) =  CallTrack(i);
    end
    
%%
    parfor ir = 1:size(Res,2)
        for is = 1:size(Res(ir).Stat,2)
        tic
            Res(ir).Stat(is).Stab                 = Stability_Switcher(Res(ir).Stat(is));
            ir           
        toc
        end
    end
%%
    a = 1000;
    f1 = figure('Position',[0,0,a,a*0.618],'Color',[1,1,1]);
    Panel = tiledlayout(1,2,'TileSpacing','none','Padding','none','Parent',f1);  
    
    for i = 1:2
        
        ax(i) = nexttile(Panel,i,[1,1]);  
        hold(ax(i),'on');
        
    end

    for ir = 1:size(Res,2)
        
        PlotSome(Res(ir),ax)
        
    end
    
    for i = 1:size(ax,2)
        
       axes_Style(ax(i));
       
    end

%%
    
    function axes_Style(ax)

         ax.Box                  = 'on';
         ax.FontSize             = 15;
         ax.TickLabelInterpreter = 'latex';
         ax.XLabel.Interpreter   = 'latex';
         ax.YLabel.Interpreter   = 'latex';

    end

 function PlotSome(Res,ax)
%%
    E_Values = zeros(size(Res.Stat,2),10);
    
    for i = 1:size(Res.Stat,2)
        
        Psi_hat_o(i,:)    = Res.Stat(i).Sol.Psi_o;
        Psi_hat_e(i,:)    = Res.Stat(i).Sol.Psi_e;
        delta_vector(i)   = Res.Stat(i).In.eps/2/pi/1E9;%/2/pi/1E9;%delta_o;%.eps/2/pi/1E9
        V_vector(i)       = Res.Stat(i).Sol.V; %Res.Stat(i).Sol.V;
  %      [~,]              = max(abs(Res.Stat(i).Stab(1).E_values));
        [V_zero_value(i),ind]   = min(abs(Res.Stat(i).Stab(1).E_values));
%        V_zero_value(i)         = 
        Res.Stat(i).Stab(1).E_values(ind) = [];
        max_psi(i) = max(abs(ifft( Psi_hat_o(i,:))*Res.Stat(i).Space.N).^2);
        Sum_power(i) = sum(abs(Res.Stat(i).Sol.Psi_e(1:end)).^2);
        
        for j = 1:size(Res.Stat(i).Stab,2)
            
           E_Values(i,:) =  maxk([E_Values(i,:).';real(Res.Stat(i).Stab(j).E_values)],10);
           
        end
        
        if max(E_Values(i,:)) > 0
            
            Stable(i) = false;
            
        else
            
            Stable(i) = true;
            
        end        
    end
%%    
    dd            = delta_vector;
    dd(Stable==0) = NaN;
    mp            = max_psi;
    mp(Stable==0) = NaN;
    
    plot(delta_vector,max_psi,'Parent',ax(1),'Color',[0,0,0])
    plot(dd,mp,'Parent',ax(1),'Color',[0,0,0],'LineWidth',2)
%%
    mpow            = Sum_power;
    mpow(Stable==0) = NaN;
    
    plot(delta_vector,Sum_power,'Parent',ax(2),'Color',[0,0,0])
    plot(dd,mpow,'Parent',ax(2),'Color',[0,0,0],'LineWidth',2)

  end
%%    
    function Res = CallTrack(i)
        load(strcat('Soliton_',num2str(i),'.mat'));
        
        Res = Set_Up_Methods_For_Chi23_Paper;
        ResSave(1).Stat.In = ResSave(1).Temp.In;
        ResSave(1).Stat.In.N = 2^8;
        
        Res.Stat = Start_From_Temp(ResSave(1).Temp,ResSave(1).Stat,1);
    
        delta_vec = linspace(Res.Stat.In.delta_o,-3.9*Res.Stat.In.ko,100);
        Res.Stat  = ChangeDelta(Res.Stat,delta_vec);

        Res.Stat.Par.Newton_tol       = 1E-10;  
        Res.Stat.Par.Turning          =    0;
        Res.Stat.Par.variable         = 'eps';  %%'Pump Power';
        Res.Stat.Par.bot_boundary     = -100E7; % bottom boundary for delta to search
        Res.Stat.Par.top_boundary     =  100E7; % top boundary for delta to search

        Res.Stat.Par.Stability        = 0;
        Res.Stat.Par.Newton_iter      = 200;
        Res.Stat.Par.first_step       = 0.01;
        Res.Stat.Par.step_tol         = 1E-9;
        Res.Stat.Par.step_inc         = 1.1;  
        Res.Stat              = Run_Branch_Universal(Res.Stat);
        
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