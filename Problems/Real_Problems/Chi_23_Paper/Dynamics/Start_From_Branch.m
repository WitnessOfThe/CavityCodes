    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = -2*pi*5E9;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 2^6;
    Res.CW.In.mu_bl     = 5;     
    Res.CW.In.W       = 100000*Res.CW.In.W_Star;
    
%%
 
    W_Finish     = 10000;
    delta_Finish = 3;
    
    W                 = [1.3E5,23E6];
    delta             = [-100,-53.5];
    
    Res.CW            = Chi23_CW_Track_fromLower2Point(Res.CW,W,delta);
    
%%
    Res.Stat.In           = Res.CW.In;
   
    Res.Stat.In.N         = 2^6;
    
    coeff_bound = [0.1,10];
    Flag = false;
     ii =0;
    while Flag == 0
        coeff       = coeff_bound(1) + (coeff_bound(2) - coeff_bound(1))/2;
        Res                 = Chi23_Turing_From_CW(Res,coeff);
        ii                  = ii + 1;
        Logic.p1            = Res.Stat.Sol.Exitflag >= 0;
        Logic.p2            = sum(abs(Res.Stat.Sol.Psi_o(2:end))) > 1E-5;
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
    
%%
    Res.Temp.In                = Res.Stat.In;    
    Res.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    Res.Temp.Par.dt            = 2E-5;
    Res.Temp.Par.s_t           = 0.01;
    Res.Temp.Par.T             = 100;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
    Res.Temp.Par.dd            = Res.Temp.Par.T/Res.Temp.Par.s_t;
    Res.Temp.Par.CW_num        = 1;
    Runge                      = Define_Runge_Coeff(Res.Temp.Par);

 %%
    Res.Temp.In.N     = 2^8;
    Res.Temp          = Res.Temp.Met.Norm(Res.Temp);   
    Res.Temp          = Chi23_StartFromBloch(Res.Stat,Res.Temp);
    
    Res.Temp.Met      = [];

    tic
    Res.Temp.Sol      = Chi23_Runge_Kuarong_mex(Res.Temp,Runge);
    toc
    
%% Plot Dynamics
    indmu = 16;
    figure('Position',[0,0,1000,800/2],'Color',[1,1,1]);
    
    Panel = tiledlayout(2,2,'TileSpacing','none','Padding','none');   
   
    ax(1) = nexttile(Panel,1,[1,2]);hold(ax(1),'on');  
    ax(2) = nexttile(Panel,3,[1,1]);hold(ax(2),'on');  
    ax(3) = nexttile(Panel,4,[1,1]);hold(ax(3),'on');  
    
    plot(Res.Temp.Sol.t, (abs(Res.Temp.Sol.Psio(:,indmu)).^2),'Parent',ax(1));
    plot(Res.Temp.Sol.t, (abs(Res.Temp.Sol.Psie(:,indmu)).^2),'Parent',ax(1));

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
