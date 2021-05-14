    clear all;
    
    ResT = Set_Up_Methods_For_Chi23_Paper;
        
    ResT.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
    ResT.Temp.Par.dt            = 1E-5;
    ResT.Temp.Par.s_t           = 0.001;
    ResT.Temp.Par.T             = 5;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%4*50
    ResT.Temp.In.N              = 2^8;
    
    ResT.Temp.Par.dd            = ResT.Temp.Par.T/ResT.Temp.Par.s_t;
    ResT.Temp.Par.CW_num        = 1;
    Runge                       = Define_Runge_Coeff(ResT.Temp.Par);

    load('Prop3.mat');
    i_vec = [1:3];
    
    parfor ii = 1:3
        
        i = i_vec(ii); 
        Temp(ii) = Start_From_Bloch_Stat(ResT.Temp,ResD.Stat(i));
        
    end
    
    Res.Temp = Temp;
    Temp     = [];
%%

        Plot_Res_temp(ResSave(1).Temp(1));
   
%%
        N = Temp.In.N;
        Temp.In               = Stat.In;
        Temp.In.N             = N;
        Temp                  = Temp.Met.Norm(Temp);   
        Temp                  = Chi23_Temp_Start_Bloch(Temp,Stat);
        Temp.Met              = [];
        Runge                 = Define_Runge_Coeff(Temp.Par);
        Temp.Eq.Lo            =  Temp.Eq.Lo;
        Temp.Eq.Le            =  Temp.Eq.Le;
        Temp.Eq.L             =  [Temp.Eq.Lo,Temp.Eq.Le]; 
   
%%

%%
    function Temp = Start_From_Bloch_Stat(Temp,Stat)
        N = Temp.In.N;
        Temp.In               = Stat.In;
        Temp.In.N             = N;
        Temp                  = Temp.Met.Norm(Temp);   
        Temp                  = Chi23_Temp_Start_Bloch(Temp,Stat);
        Temp.Met              = [];
        Runge                 = Define_Runge_Coeff(Temp.Par);
        Temp.Eq.Lo            =  Temp.Eq.Lo;
        Temp.Eq.Le            =  Temp.Eq.Le;
        Temp.Eq.L             =  [Temp.Eq.Lo,Temp.Eq.Le]; 


        tic
        Temp.Sol              = Chi23_Runge_Kuarong_mex(Temp,Runge);
        toc
        
    end
    function Temp = Chi23_Temp_Start_Bloch(Temp,Stat)
    
        Psio    = zeros(1,Temp.Space.N);
        Psie    = zeros(1,Temp.Space.N);
        
        Psio(1) = Stat.Sol.Psi_o(1);
        Psie(1) = Stat.Sol.Psi_e(1);
        
        for i = 1:floor(Temp.Space.N/2/Stat.In.mu_bl)
            
            Psio(1+Stat.In.mu_bl*i)     =  Stat.Sol.Psi_o(1+i);
            Psie(1+Stat.In.mu_bl*i)     =  Stat.Sol.Psi_e(1+i);
            Psio(end-Stat.In.mu_bl*i+1) =  Stat.Sol.Psi_o(end-i+1);
            Psie(end-Stat.In.mu_bl*i+1) =  Stat.Sol.Psi_e(end-i+1);
            
        end
        
        Temp.In.Psi_Start                                = zeros(1,Temp.Space.N*2);
        Temp.In.Psi_Start(1:Temp.Space.N)                = Psio*Temp.Space.N;
        Temp.In.Psi_Start(Temp.Space.N+1:Temp.Space.N*2) = Psie*Temp.Space.N;
%         Temp.In.Psi_Start(Temp.In.Psi_Start == 0)       = 1E-2;
        Temp.In.t_start                                  = 0;

    
    end
    function Plot_Res_temp(Temp)
    
    indmu = 17;
    indt  = 1;
    ind_t = [1:4:size(Temp.Sol.Psio,1)];
    Nt    = size(ind_t,2);
    T     = ( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) );
    dt    =   Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(end-1));
    
    f = 2*pi*Temp.Eq.norm/( Temp.Sol.t(ind_t(end)) - Temp.Sol.t(ind_t(1)) )/Temp.In.ko*[0:Nt/2-1,-Nt/2:-1];
    
    PsiO = ifft(Temp.Sol.Psio,[],2);
    PsiE = ifft(Temp.Sol.Psie,[],2);
    
    PsiOt = zeros(Nt,Temp.Space.N);
    PsiEt = zeros(Nt,Temp.Space.N);
    
    for i = 1:Temp.Space.N
        
        PsiOt(:,i)    = ifft(Temp.Sol.Psio(ind_t,i)*Temp.Space.N );        
        PsiEt(:,i)    = ifft(Temp.Sol.Psie(ind_t,i)*Temp.Space.N );
        PowerOmuavg(i) = dt/T*sum(abs(Temp.Sol.Psio(ind_t,i)).^2);
        PowerEmuavg(i) = dt/T*sum(abs(Temp.Sol.Psie(ind_t,i)).^2);
        
    end
    
    f1 = figure('Position',[0,0,1000,1000],'Color',[1,1,1]);
    
    Panel = tiledlayout(5,2,'TileSpacing','none','Padding','none','Parent',f1);   
   
    ax(1) = nexttile(Panel,1,[1,2]);hold(ax(1),'on');  
    ax(2) = nexttile(Panel,3,[1,1]);hold(ax(2),'on');  
    ax(3) = nexttile(Panel,4,[1,1]);hold(ax(3),'on');  
    ax(4) = nexttile(Panel,5,[1,1]);hold(ax(4),'on');  
    ax(5) = nexttile(Panel,6,[1,1]);hold(ax(5),'on');  
    ax(6) = nexttile(Panel,7,[1,1]);hold(ax(6),'on');  
    ax(7) = nexttile(Panel,8,[1,1]);hold(ax(7),'on');  
    
  %  plot(Temp.Sol.t(1:end-1),  sum(abs(Temp.Sol.Psie(1:end-1,:)).^2,2),'Parent',ax(1),'Color',[0,1,0]);
    plot(Temp.Sol.t(1:end-1),  (real(Temp.Sol.Psio(1:end-1,indmu))),'Parent',ax(1),'Color',[1,0,0]);

   % ylim(ax(1),[0,sum(abs(Temp.Sol.Psio(end-1,:)).^2*1.4,2)])
    
    stem(fftshift(Temp.Space.k),fftshift(10*log10(abs(Temp.Sol.Psio(end-1,:)).^2 )),'Parent',ax(2),'Color',[1,0,0],'BaseValue',-100,'Marker','none'); 
    stem(fftshift(Temp.Space.k),fftshift(10*log10(abs(Temp.Sol.Psie(end-1,:)).^2 )),'Parent',ax(2),'Color',[0,1,0],'BaseValue',-100,'Marker','none'); 
    
    stem(fftshift(Temp.Space.k),fftshift(10*log10( PowerOmuavg)),'Parent',ax(3),'Color',[1,0,0],'BaseValue',-100,'Marker','none'); 
    stem(fftshift(Temp.Space.k),fftshift(10*log10( PowerEmuavg)),'Parent',ax(3),'Color',[0,1,0],'BaseValue',-100,'Marker','none'); 

    plot((Temp.Space.phi),abs(ifft(Temp.Sol.Psio(end-1,:)*Temp.Space.N)).^2 ,'Parent',ax(4),'Color',[1,0,0]); 
    plot((Temp.Space.phi),abs(ifft(Temp.Sol.Psie(end-1,:)*Temp.Space.N)).^2 ,'Parent',ax(5),'Color',[0,1,0]); 
    
  %  pcolor(fftshift(Temp.Space.k),fftshift(f),fftshift(fftshift(10*log10(abs(PsiOt).^2),1),2),'Parent',ax(6))
   % pcolor(fftshift(Temp.Space.k),fftshift(f),fftshift(fftshift(10*log10(abs(PsiEt).^2),1),2),'Parent',ax(7))
    
    ax(1).XLabel.String = '$t,(s \cdot k_o)$';
    ax(1).YLabel.String = '$|\psi_\mu|^2$';
    
    ax(2).XLabel.String = 'Mode Number';
    ax(2).YLabel.String = 'Power (db)';
    
    ax(3).XLabel.String = 'Mode Number';
    ax(3).YLabel.String = 'Power (db)';
%   colorbar(ax(i));
    ax(3).YLim  = [-100,4];
    ax(2).YLim  = [-100,4];
    
    ax(3).XLim  = [-80,80];
    ax(2).XLim  = [-80,80];
    ax(5).XLim  = [-pi,pi];
    ax(4).XLim  = [-pi,pi];
    
    ax(6).XLim  = [-80,80];
    ax(7).XLim  = [-80,80];
    ax(6).YLim  = [-100,100];
    ax(7).YLim  = [-100,100];
    
    caxis(ax(6),[-100,4]);
    
    caxis(ax(7),[-100,4]);
    
     f2 = figure('Position',[0,0,500,500*0.618],'Color',[1,1,1]);

    Panel2 = tiledlayout(1,2,'TileSpacing','none','Padding','none','Parent',f2);   
    
    ax(8) = nexttile(Panel2 ,1,[1,1]);hold(ax(8),'on');  
    ax(9) = nexttile(Panel2 ,2,[1,1]);hold(ax(9),'on');  
    
    mesh(Temp.Space.phi,Temp.Sol.t(1:4:end-1),abs(PsiO(1:4:end-1,:)*Temp.Space.N).^2,'Parent',ax(8));
    mesh(Temp.Space.phi,Temp.Sol.t(1:4:end-1),abs(PsiE(1:4:end-1,:)*Temp.Space.N).^2,'Parent',ax(9));
    ax(8).XLim = [-pi,pi];
    ax(9).XLim = [-pi,pi];
    
   for i = 1:size(ax,2)
      axes_Style(ax(i));
      shading(ax(i),'flat');
   end

end    

function axes_Style(ax)

     ax.Box      = 'on';
     ax.FontSize = 15;
     ax.TickLabelInterpreter = 'latex';
     ax.XLabel.Interpreter   = 'latex';
     ax.YLabel.Interpreter   = 'latex';
     
end
    