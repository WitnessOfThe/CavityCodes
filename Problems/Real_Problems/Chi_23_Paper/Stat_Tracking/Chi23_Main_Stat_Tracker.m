    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = 2*pi*5E9;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 2^7;
    Res.CW.In.W       = 100000*Res.CW.In.W_Star;
    
%%
    Res.CW.Par.Equation_string  = 'Chi23_CW';
    Res.CW.Met.Equation         = @Chi23_CW;
    Res.CW.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    Res.CW.Met.Newton           = @fsolve;%'fsolve'
    Res.CW.Par.Change_Space     = 0;
    
    Res.CW.Par.variable         = 'delta_o';  %%'Pump Power';
    Res.CW.Par.first_step       = 0.02; % step for delta measured in delta/kappa
    Res.CW.Par.step_tol         = 0.001;
    Res.CW.Par.step_inc         = 1.01;
    Res.CW.Par.step_dec         = 0.1;

    Res.CW.Par.bot_boundary     = -120; % bottom boundary for delta to search
    Res.CW.Par.top_boundary     =  200; % top boundary for delta to search
    Res.CW.Par.Sol_Re_Sign      = '-';
    Res.CW.Par.Stability        = true;
    Res.CW.Par.Newton_iter      = 25;      
    Res.CW.Par.Newton_tol       = 1E-10;
    Res.CW.Par.i_max            = 1000;
    Res.CW.Par.Turning = 0;

    Res.CW.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',false,'SpecifyObjectiveGradient',false,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-25,'OptimalityTolerance',1E-25,'FunctionTolerance',10^(-10));

%%
    W_Finish     = 10000;
    delta_Finish = 3;
   
    %    W                 = [1.3E5,6000000];
    %    delta             = [-100,-15];
    
    W                = [1.3E3,30E6];
    delta            = [100,93];
   
    Res = Get_to_point(Res,W,delta);
   
%%
    Res.Stat.In           = Res.CW.In;
    Res.Stat.Par          = Res.CW.Par;    
    Res.Stat.In.mu_bl     = 43;    
    Res.Stat.In.N         = 2^6;
    Res.Stat.Met.Newton   = @Newton_Manual_bicgstab;%'fsolve'
    
    Res.Stat              = Res.Stat.Met.Norm(Res.Stat);
        
    Res.CW.Met.MI_Matrix   = @Chi23_MI_Matrix;
    Res.CW.Stab            =  Chi23_MI(Res.CW);
    Res.Stat.Sol.Psi_o     =  1E-10*ones(1,Res.Stat.Space.N);
    Res.Stat.Sol.Psi_e     =  1E-10*ones(1,Res.Stat.Space.N);
    
    
    [i_k,i_c] = find(real(Res.CW.Stab.Value) == max(max(real(Res.CW.Stab.Value))));
    i_k = Res.Stat.In.mu_bl+1;
    i_k = find(abs(Res.Stat.Space.k) == abs(Res.Stat.Space.k(i_k)));
    
    i_c = zeros(1,2);
    
    [~,i_c(1)]  = max(real(Res.CW.Stab.Value(i_k(1),:)) );
    [~,i_c(2)]  = max(real(Res.CW.Stab.Value(i_k(2),:)) );
    
    Res.Stat.Sol.Psi_o(1)  = Res.CW.Sol.Psi_o*Res.Stat.Space.N;       
    Res.Stat.Sol.Psi_e(1)  = Res.CW.Sol.Psi_e*Res.Stat.Space.N;      
    
    coeff = 1.51;
    
    Res.Stat.Sol.Psi_o(2)  = (Res.CW.Stab.Vector(i_k(1)).V(1,i_c(1)) )*coeff*Res.Stat.Space.N;       %+ Res.CW.Stab.Vector(i_k(2)).V(1,i_c(2) )
    Res.Stat.Sol.Psi_e(2)  = (Res.CW.Stab.Vector(i_k(1)).V(2,i_c(1)) )*coeff*Res.Stat.Space.N;     %+ Res.CW.Stab.Vector(i_k(2)).V(2,i_c(2) )
    
    Res.Stat.Sol.Psi_o(end)  = (Res.CW.Stab.Vector(i_k(1)).V(3,i_c(1)) )*coeff*Res.Stat.Space.N;       %+ Res.CW.Stab.Vector(i_k(2)).V(3,i_c(2))
    Res.Stat.Sol.Psi_e(end)  = (Res.CW.Stab.Vector(i_k(1)).V(4,i_c(1)) )*coeff*Res.Stat.Space.N;    %+ Res.CW.Stab.Vector(i_k(2)).V(4,i_c(2))  
    
    Res.Stat.Sol.Psi_o           = ifft(Res.Stat.Sol.Psi_o);
    Res.Stat.Sol.Psi_e           = ifft(Res.Stat.Sol.Psi_e);
    
    Slv_Start               = [real(Res.Stat.Sol.Psi_o),imag(Res.Stat.Sol.Psi_o)...
                    ,real(Res.Stat.Sol.Psi_e),imag(Res.Stat.Sol.Psi_e),(imag(Res.CW.Stab.Value(i_k(1),i_c(1))))/Res.Stat.In.mu_bl];
    
    [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Res.Stat);
    
    Res.Stat.Sol.Psi_o   = fft(Slv(1:Res.Stat.Space.N) + 1i*Slv(Res.Stat.Space.N+1:2*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.Psi_e   = fft(Slv(2*Res.Stat.Space.N+1:3*Res.Stat.Space.N) + 1i*Slv(3*Res.Stat.Space.N+1:4*Res.Stat.Space.N))/Res.Stat.Space.N;
    Res.Stat.Sol.V       = Slv(end);
    
%    Res.Stat.Stab        = Stability_Switcher(Res.Stat);

%%    
   Res.Stat              = Run_Branch_Universal(Res.Stat);
    
%%
    E_Values = zeros(size(Res.Stat,2),10);
    
    for i = 1:size(Res.Stat,2)
        
        Psi_hat_o(i,:)    = Res.Stat(i).Sol.Psi_o;
        Psi_hat_e(i,:)    = Res.Stat(i).Sol.Psi_e;
        delta_vector(i)   = Res.Stat(i).Eq.delta_o;
        
        for j = 1:size(Res.Stat(i).Stab,2)
            
           E_Values(i,:) =  maxk([E_Values(i,:).';real(Res.Stat(i).Stab(j).E_values)],10);
           
        end
        
        if max(E_Values(i,:)) > 1E4
            
            Stable(i) = false;
            
        else
            
            Stable(i) = true;
            
        end        
    end
    
    Psi_thetao = ifft(Psi_hat_o,[],2)*Res.Stat(1).Space.N;
    Psi_thetae = ifft(Psi_hat_e,[],2)*Res.Stat(1).Space.N;
    
    U_maxo     = max(abs(Psi_thetao).^2,[],2);
    U_maxe     = max(abs(Psi_thetae).^2,[],2);

    figure('Position',[0,0,1600,900],'Color',[1,1,1]);
    Panel = tiledlayout(3,5,'TileSpacing','none','Padding','none');  
    
    for i = 1:15
        
        ax(i) = nexttile(Panel,i,[1,1]);  
        hold(ax(i),'on');
        
    end
    
    ind_show = [2,Res.Stat(1).Space.N - 1 ];
    
    plot(delta_vector,abs(Psi_hat_o(:,1)).^2,'Parent',ax(1));
    plot(delta_vector,abs(Psi_hat_e(:,1)).^2,'Parent',ax(1));     
    plot(delta_vector,sum(abs(Psi_hat_o(:,:)).^2,2),'Parent',ax(1));
    plot(delta_vector,sum(abs(Psi_hat_e(:,:)).^2,2),'Parent',ax(1));

    plot(delta_vector(Stable),abs(Psi_hat_o(Stable,1)).^2,'Parent',ax(1),'LineStyle','none','MarkerSize',20,'Marker','.');
    plot(delta_vector(Stable),abs(Psi_hat_e(Stable,1)).^2,'Parent',ax(1),'LineStyle','none','MarkerSize',20,'Marker','.');
    
    plot(delta_vector(Stable),sum(abs(Psi_hat_o(Stable,:)).^2,2),'Parent',ax(1),'LineStyle','none','MarkerSize',20,'Marker','.');
    plot(delta_vector(Stable),sum(abs(Psi_hat_e(Stable,:)).^2,2),'Parent',ax(1),'LineStyle','none','MarkerSize',20,'Marker','.');
    
    legend(ax(1),'$|\psi^o_{\mu=0}|^2$','$|\psi^e_{\mu=0}|^2$','$\sum|\psi^o_{\mu=0}|^2$','$\sum|\psi^e_{\mu=0}|^2$','Interpreter','latex');
    
    plot(delta_vector,abs(Psi_hat_e(:,1)).^2./abs(Psi_hat_o(:,1)).^2,'Parent',ax(2));
    plot(delta_vector,sum(abs(Psi_hat_e(:,:)).^2,2)./sum(abs(Psi_hat_o(:,:)).^2,2),'Parent',ax(2));
    
    plot(delta_vector(Stable),abs(Psi_hat_e(Stable,1)).^2./abs(Psi_hat_o(Stable,1)).^2,'Parent',ax(2),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
    plot(delta_vector(Stable),sum(abs(Psi_hat_e(Stable,:)).^2,2)./sum(abs(Psi_hat_o(Stable,:)).^2,2),'Parent',ax(2),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
    
    legend(ax(2),'$|\psi^e_{\mu=0}|^2/|\psi^o_{\mu=0}|^2$','$\sum|\psi^e_{\mu=0}|^2/\sum|\psi^o_{\mu=0}|^2$','Interpreter','latex');
    
    plot(delta_vector,abs(Psi_hat_o(:,2)).^2,'Parent',ax(6));
    plot(delta_vector,abs(Psi_hat_e(:,2)).^2,'Parent',ax(6));
    
    plot(delta_vector(Stable),abs(Psi_hat_o(Stable,2)).^2,'Parent',ax(6),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
    plot(delta_vector(Stable),abs(Psi_hat_e(Stable,2)).^2,'Parent',ax(6),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
    
    legend(ax(6),strcat('$|\psi^o_{\mu=',num2str(Res.Stat(1).Space.k(2)),'}|^2$'),strcat('$|\psi^e_{\mu=',num2str(Res.Stat(1).Space.k(2)),'}|^2$')...
        ,'Interpreter','latex');
    
    plot(delta_vector,abs(Psi_hat_e(:,2)).^2./abs(Psi_hat_o(:,2)).^2,'Parent',ax(7));
    
    plot(delta_vector(Stable),abs(Psi_hat_e(Stable,2)).^2./abs(Psi_hat_o(Stable,2)).^2,'Parent',ax(7),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
    
    legend(ax(7),strcat('$|\psi^e_{\mu=',num2str(Res.Stat(1).Space.k(2)),'}|^2/|\psi^o_{\mu=',num2str(Res.Stat(1).Space.k(2)),'}|^2$')...
        ,'Interpreter','latex');
    
    plot(delta_vector,abs(Psi_hat_o(:,Res.Stat(1).Space.N)).^2,'Parent',ax(11));
    plot(delta_vector,abs(Psi_hat_e(:,Res.Stat(1).Space.N)).^2,'Parent',ax(11));
    
    plot(delta_vector(Stable),abs(Psi_hat_o(Stable,Res.Stat(1).Space.N)).^2,'Parent',ax(11),'LineStyle','none','MarkerSize',20,'Marker','.');
    plot(delta_vector(Stable),abs(Psi_hat_e(Stable,Res.Stat(1).Space.N)).^2,'Parent',ax(11),'LineStyle','none','MarkerSize',20,'Marker','.');
    
    legend(ax(11),strcat('$|\psi^o_{\mu=',num2str(Res.Stat(1).Space.k(end)),'}|^2$'),strcat('$|\psi^e_{\mu=',num2str(Res.Stat(1).Space.k(end)),'}|^2$')...
        ,'Interpreter','latex');
    
    plot(delta_vector,abs(Psi_hat_e(:,Res.Stat(1).Space.N)).^2./abs(Psi_hat_o(:,Res.Stat(1).Space.N)).^2,'Parent',ax(12));
    plot(delta_vector(Stable),abs(Psi_hat_e(Stable,Res.Stat(1).Space.N)).^2./abs(Psi_hat_o(Stable,Res.Stat(1).Space.N)).^2,'Parent',ax(12),'LineWidth',2,'LineStyle','none','MarkerSize',20,'Marker','.');
    
    legend(ax(12),strcat('$|\psi^e_{\mu=',num2str(Res.Stat(1).Space.k(end)),'}|^2/|\psi^o_{\mu=',num2str(Res.Stat(1).Space.k(end)),'}|^2$')...
        ,'Interpreter','latex');
    
    ind_show = 5;
    
    plot(Res.Stat(1).Space.phi,abs(Psi_thetae(ind_show,:)),'Parent',ax(3));
    plot(Res.Stat(1).Space.phi,real(Psi_thetae(ind_show,:)),'Parent',ax(3));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetae(ind_show,:)),'Parent',ax(3));
    plot(Res.Stat(1).Space.phi,abs(Psi_thetao(ind_show,:)),'Parent',ax(4));
    plot(Res.Stat(1).Space.phi,real(Psi_thetao(ind_show,:)),'Parent',ax(4));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetao(ind_show,:)),'Parent',ax(4));
    
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_o(ind_show,:)).^2),'Parent',ax(5),'BaseValue',-70,'Marker','none','Color',[1,0,0]);
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_e(ind_show,:)).^2),'Parent',ax(5),'BaseValue',-70,'Marker','none','Color',[0,1,0]);
    
    
    delta_avg    = (max(delta_vector()) - min(delta_vector))/2+min(delta_vector);
    
    [~,ind_show] = mink(abs(delta_vector - delta_avg),2 );
    ind_show     = ind_show(2);
    
    plot(Res.Stat(1).Space.phi,abs(Psi_thetae(ind_show,:)),'Parent',ax(8));
    plot(Res.Stat(1).Space.phi,real(Psi_thetae(ind_show,:)),'Parent',ax(8));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetae(ind_show,:)),'Parent',ax(8));
    
    plot(Res.Stat(1).Space.phi,abs(Psi_thetao(ind_show,:)),'Parent',ax(9));
    plot(Res.Stat(1).Space.phi,real(Psi_thetao(ind_show,:)),'Parent',ax(9));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetao(ind_show,:)),'Parent',ax(9));
    
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_o(ind_show,:)).^2),'Parent',ax(10),'BaseValue',-70,'Marker','none','Color',[1,0,0]);
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_e(ind_show,:)).^2),'Parent',ax(10),'BaseValue',-70,'Marker','none','Color',[0,1,0]);

    ind_show = size(Res.Stat,2)-5;
    
    plot(Res.Stat(1).Space.phi,abs(Psi_thetae(ind_show,:)),'Parent',ax(13));
    plot(Res.Stat(1).Space.phi,real(Psi_thetae(ind_show,:)),'Parent',ax(13));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetae(ind_show,:)),'Parent',ax(13));
    
    plot(Res.Stat(1).Space.phi,abs(Psi_thetao(ind_show,:)),'Parent',ax(14));
    plot(Res.Stat(1).Space.phi,real(Psi_thetao(ind_show,:)),'Parent',ax(14));
    plot(Res.Stat(1).Space.phi,imag(Psi_thetao(ind_show,:)),'Parent',ax(14));
    
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_o(ind_show,:)).^2),'Parent',ax(15),'BaseValue',-70,'Marker','none','Color',[1,0,0]);
    stem(Res.Stat(1).Space.k,10*log10(abs(Psi_hat_e(ind_show,:)).^2),'Parent',ax(15),'BaseValue',-70,'Marker','none','Color',[0,1,0]);
            
    ylim(ax(15),[-70,15]);
    ylim(ax(10),[-70,15]);
    ylim(ax(5), [-70,15]);
    
    xlim(ax(5),  5*[-Res.Stat(1).Space.k(2),Res.Stat(1).Space.k(2)] );
    xlim(ax(15),10*[-Res.Stat(1).Space.k(2),Res.Stat(1).Space.k(2)] );    
    xlim(ax(10),15*[-Res.Stat(1).Space.k(2),Res.Stat(1).Space.k(2)] );
 
    legend(ax(3),'$abs[\psi(\theta)]$','$Re[\psi(\theta)]$','$Im[\psi(\theta)]$','Interpreter','latex')
     
     
    ax(1).XLabel.String = '$\delta/\kappa_o$';
    ax(2).XLabel.String = '$\delta/\kappa_o$';
    ax(6).XLabel.String = '$\delta/\kappa_o$';
    ax(7).XLabel.String = '$\delta/\kappa_o$';
    ax(11).XLabel.String = '$\delta/\kappa_o$';
    ax(12).XLabel.String = '$\delta/\kappa_o$';

    ax(3).XLabel.String = '$\theta$';
    ax(4).XLabel.String = '$\theta$';
    ax(8).XLabel.String = '$\theta$';
    ax(9).XLabel.String = '$\theta$';
    ax(13).XLabel.String = '$\theta$';
    ax(14).XLabel.String = '$\theta$';

    ax(5).XLabel.String  = '$\mu$';
    ax(10).XLabel.String = '$\mu$';
    ax(15).XLabel.String = '$\mu$';
    
    ax(5).YLabel.String  = 'Power (db)';
    ax(10).YLabel.String = 'Power (db)';
    ax(15).YLabel.String = 'Power (db)';
    
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
    
%%
%%
function Res = Get_to_point(Res,W,delta)    
    
    NN = 1000;
    delta_vector          = linspace(delta(1),delta(2),NN);
    W_vector              = linspace(W(1),W(2),NN);
    
    Res.CW.In.W           = W(1)*Res.CW.In.W_Star;        
    Res.CW.In.delta       = delta(1)*Res.CW.In.ko;        
    
    Res.CW                = Res.CW.Met.Solve_Chi2(Res.CW ); 

    [~,ind]               = min(abs(Res.CW.Sol.Omega));

    Res.CW.Sol.Omega      =  Res.CW.Sol.Omega(ind);    
    Res.CW.Sol.Psi_o      =  Res.CW.Sol.Psi_o(ind);    
    Res.CW.Sol.Psi_e      =  Res.CW.Sol.Psi_e(ind);

        for i_d = 1:NN

            Res.CW.In.delta_o    = delta_vector(i_d)*Res.CW.In.ko;            
            Res.CW.In.W         = W_vector(i_d)*Res.CW.In.W_Star;            
            Res.CW               = Res.CW.Met.Norm(Res.CW);  
            [Slv,eps_f,Exitflag] = Newton_Switcher([real(Res.CW.Sol.Psi_o(1)),imag(Res.CW.Sol.Psi_o(1)),real(Res.CW.Sol.Psi_e(1)),imag(Res.CW.Sol.Psi_e(1))],Res.CW);
            Res.CW               = Res.CW.Met.Prop_Gen(Slv,Res.CW);          
            
            if eps_f > 1E-5
                
                break;
                
            end        
        end
        
    end
 
%%    
    

function [Mumber1,Mumber2,k1,k2] =  Evaluate_MI(Res)

    Res.CW2           = Res.CW.Met.Norm(Res.CW);  
    Res.CW23          = Res.CW2;
    
    Res.CW2.Met.MI_Matrix   = @Chi2_MI_Matrix;
    Res.CW23.Met.MI_Matrix  = @Chi23_MI_Matrix;
    
    Res.CW2           = Res.CW.Met.Solve_Chi2(Res.CW2);    
    Res.CW2.Stab      = Chi23_MI(Res.CW2);    
    Res.CW23.Stab     = Chi23_MI(Res.CW23);
    
    [~,ind]           = min(abs(Res.CW2.Sol.Omega));
    
    Mumber1           = sum(sum(real(Res.CW2.Stab(ind).Value)>1E-6));
    Mumber2           = sum(sum(real(Res.CW23.Stab(1).Value)>1E-6));
    
    [m_ind1,ind1_t]   = max(real(Res.CW2.Stab(ind).Value),[],1);
    [~,ind1]          = max(m_ind1);
    k1                = Res.CW2.Space.k(ind1_t(ind1));
    
    [m_ind1,ind1_t]   = max(real(Res.CW23.Stab.Value),[],1);
    [~,ind1]          = max(m_ind1);
    k2                = Res.CW23.Space.k(ind1_t(ind1));
    
end

    
        
%%
function Chi23_Stat_From_CW(Res)
    
end