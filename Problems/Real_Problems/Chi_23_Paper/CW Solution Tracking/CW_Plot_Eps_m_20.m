    clear all;

%%
    
%%
    NN = 1E4;
    
    eps_Vec = [100]*1E9;
    hold on;
    for i = 1:3
        
        Res = Set_Up_Methods_For_Chi23_Paper;
        Res.CW.In         = Params_LiNbd;
        Res.CW.In.eps     = eps_Vec(i)*2*pi;
        Res.CW.In.N       = 2^2;
        Res.CW.In.W       = 1E5*Res.CW.In.W_Star;
        
        Br = Chi2_Get_CW_Point2Point(Res.CW,[-100,20]*Res.CW.In.ko,NN);  
        
        plot(Br.delta_vector/Res.CW.In.ko,Br.Omega(:,1)/Res.CW.In.Omega_Star,'Color',[1,0,0])
        plot(Br.delta_vector/Res.CW.In.ko,Br.Omega(:,2)/Res.CW.In.Omega_Star,'Color',[1,0,0])
        plot(Br.delta_vector/Res.CW.In.ko,Br.Omega(:,3)/Res.CW.In.Omega_Star,'Color',[1,0,0])
        
    end
    
%%

    Res.CW.Par.Equation_string  = 'Chi23_CW';
    Res.CW.Met.Equation         = @Chi23_CW;
    Res.CW.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    Res.CW.Met.Newton           = @fsolve;%'fsolve'
    Res.CW.Par.Change_Space     = 0;
    
    Res.CW.Par.variable         = 'delta_o';  %%'Pump Power';
    Res.CW.Par.first_step       = 0.01; % step for delta measured in delta/kappa
    Res.CW.Par.step_tol         = 0.001;
    Res.CW.Par.step_inc         = 0.001;
    Res.CW.Par.step_dec         = 0.5;

    Res.CW.Par.bot_boundary     = -5; % bottom boundary for delta to search
    Res.CW.Par.top_boundary     =  20; % top boundary for delta to search
    Res.CW.Par.Sol_Re_Sign      = '-';
    Res.CW.Par.Stability        = false;
    Res.CW.Par.Newton_iter      = 30;      
    Res.CW.Par.Newton_tol       = 1E-10;  
    Res.CW.Par.i_max            = 10000;
    
    Res.CW.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',false,'SpecifyObjectiveGradient',false,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-25,'OptimalityTolerance',1E-25,'FunctionTolerance',10^(-10));


  %%
  
    NN                  = 1E4;
    Sa2.delta_vector     = linspace(-100,20,NN)*Res.CW(1).In.ko;
    
    Sa2.U_f_2    =   NaN(NN,3);
    Sa2.U_s_2    =   NaN(NN,3);
    U_f_23       =   zeros(NN,3);
    U_s_23       =   zeros(NN,3);
    
    for i =1:NN
         
        Res.CW.In.delta_o = Sa2.delta_vector(i);
        Res.CW            = Res.CW.Met.Solve_Chi2(Res.CW);
        Sa2.U_f_2(i,:)    = Res.CW.Sol.Psi_o;
        Sa2.U_s_2(i,:)    = Res.CW.Sol.Psi_e;  
        Sa2.Omega(i,:)    = Res.CW.Sol.Omega;
    end
    
%%
%     fgr = 5;
%     Res.CW.In.delta_o = fgr*Res.CW(1).In.ko;
%     Res.CW            = Res.CW.Met.Solve_Chi2(Res.CW);
%     
%     for i = [1:3]
%         
%         CWF                 = strcat('CW',num2str(i));
%         Res.(CWF)           = Res.CW;
%         Res.(CWF).Sol.Psi_o = Res.CW.Sol.Psi_o(i);
%         Res.(CWF).Sol.Psi_e = Res.CW.Sol.Psi_e(i);
%         Res.(CWF)           = Run_Branch_Universal( Res.(CWF));
%         
%     end
    fgr = -0;
    Res.CW.In.delta_o = fgr*Res.CW(1).In.ko;
    Res.CW            = Res.CW.Met.Solve_Chi2(Res.CW);
    
%     for i = 1
%         
%         CWF                 = strcat('CW',num2str(i));
%         Res.(CWF)           = Res.CW;
%         Res.(CWF).Sol.Psi_o = Res.CW.Sol.Psi_o(3);
%         Res.(CWF).Sol.Psi_e = Res.CW.Sol.Psi_e(3);
%         Res.(CWF)           = Run_Branch_Universal( Res.(CWF));
%         
%     end
%     
%     fgr = 3;
%     Res.CW.In.delta_o = fgr*Res.CW(1).In.ko;
%     Res.CW            = Res.CW.Met.Solve_Chi2(Res.CW);
%     
%     for i = [2:3]   
%         
%         CWF                 = strcat('CW',num2str(i));
%         Res.(CWF)           = Res.CW;
%         Res.(CWF).Sol.Psi_o = Res.CW.Sol.Psi_o(i);
%         Res.(CWF).Sol.Psi_e = Res.CW.Sol.Psi_e(i);
%         Res.(CWF)           = Run_Branch_Universal( Res.(CWF));
%         
%     end



%%

%     for i = 1:3
%         
%         CWF                 = strcat('CW',num2str(i));
%         
%         Sa23(i).delta         = NaN(1,size(Res.(CWF),2));
%         Sa23(i).Psi_o         = NaN(1,size(Res.(CWF),2));
%         Sa23(i).Psi_e         = NaN(1,size(Res.(CWF),2));
%         
%         for i_d = 1:size(Res.(CWF),2)
%             
%            Sa23(i).delta(i_d) = Res.(CWF)(i_d).In.delta_o/Res.(CWF)(i_d).In.ko;
%            Sa23(i).Psi_o(i_d) = Res.(CWF)(i_d).Sol.Psi_o;
%            Sa23(i).Psi_e(i_d) = Res.(CWF)(i_d).Sol.Psi_e;
%             
%         end
%         
%     end
% %%
   
%     for i = 1:1
%         
%         plot(Sa2(i).delta_vector/Res.CW(1).In.ko,abs(Sa2(i).Omega)/sqrt(2*Res.CW.In.ko*Res.CW.In.ke),'LineStyle','--','Color',[1,0,0])
%     
%     end
    
  % plot(delta_vector/Res.CW(1).In.ko,abs(U_f_2).^2,'LineStyle','none','Marker','.','Color',[1,0,0]);hold on;

%%
ax(1) = gca;
hold on;
plot(Sa2.delta_vector/Res.CW(1).In.ko,Sa2.Omega/Res.CW.In.Omega_Star,'Parent',ax(1),'LineStyle','none','Marker','.','Color','m');hold on;
%plot(Sa2.delta_vector/Res.CW(1).In.ko,abs(Sa2.U_s_2).^2,'LineStyle','none','Marker','.','Color',[0,1,0]);
%hold on;plot(delta_vector,abs(U_f_23).^2,'LineStyle','none','Marker','.','Color',[0,0,0]);
    
%%
%        Res.CW_23         = Res.CW;
%         for i_s = 1:3
%             
%             if ~isnan(Res.CW_23.Sol.Psi_o(i_s))
%                 
%                 [Slv,eps_f,Exitflag]  = Newton_Switcher([real(Res.CW.Sol.Psi_o(i_s)),imag(Res.CW.Sol.Psi_o(i_s)),real(Res.CW.Sol.Psi_e(i_s)),imag(Res.CW.Sol.Psi_e(i_s))],Res.CW_23);
%                 U_f_23(i,i_s)         = Slv(1) + 1i*Slv(2);
%                 U_s_23(i,i_s)         = Slv(3) + 1i*Slv(4); 
%                 
%             else
%                 
%                 U_f_23(i,i_s)         = NaN;
%                 U_s_23(i,i_s)         = NaN; 
%                 
%             end
%         end        

%%
function [Omega2_max,delta2_max,Omega23_max,delta23_max] = max_val(Res)

    NN = 1E5;
    Res.CW = Res.CW.Met.Norm(Res.CW);
    
    delta_vector = linspace( Res.CW.Par.bot_boundary, Res.CW.In.H*1.5,NN)*Res.CW.In.ko;
    Res.CW2      = Res.CW;
    
    Omega2  = zeros(1,NN); 
    
    for i = 1:NN
        
        Res.CW2.In.delta_o = delta_vector(i);
        Res.CW2          = Res.CW2.Met.Solve_Chi2(Res.CW2);
        Omega2(i)        = max(abs(Res.CW2.Sol.Omega));
        
    end

    
    [Omega2_max,ind]  = max(Omega2);    
    delta2_max        = delta_vector(ind);
    
    Res.CW.Par.bot_boundary     = delta2_max/Res.CW.In.ko; % bottom boundary for delta to search    
    Res.CW.In.delta_o = delta2_max;     
    Res.CW            = Res.CW.Met.Solve_Chi2(Res.CW);
    [~,ind]           = max(abs(Res.CW.Sol.Omega));    
    
    Res.CW.Sol.Psi_o  = Res.CW.Sol.Psi_o(ind);
    Res.CW.Sol.Psi_e  = Res.CW.Sol.Psi_e(ind);
    
    Res.CW            = Res.CW.Met.Norm(Res.CW);
    x_0               = Res.CW.Eq.(Res.CW.Par.variable);
    Res.CW            =  Branch([real(Res.CW.Sol.Psi_o),imag(Res.CW.Sol.Psi_o),real(Res.CW.Sol.Psi_e),imag(Res.CW.Sol.Psi_e)],x_0,Res.CW,1);
    
    delta_vector      = zeros(1,size(Res.CW,2));
    Omega23           = zeros(1,size(Res.CW,2));
    
    for i = 1:size(Res.CW,2)
        
        delta_vector(i)   = Res.CW(i).In.delta_o;
        Omega23(i)        = Res.CW(i).Sol.Omega;
        
    end
    
    [Omega23_max,ind] = max(Omega23);
    delta23_max       = delta_vector(ind);
    
end