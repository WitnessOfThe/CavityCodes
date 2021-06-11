    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_AlN;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 150;
    Res.CW.In.W       = 7000*Res.CW.In.W_Star;
    NNP               = 1000/2;%
    NND               = 1000/2;%
    
    
%    epsilon_vector      = 2*pi*[-1E9,-10E9,-5E9,-7E9,-9E9,-10E9,-15E9,-20E9];   
 %   omega_max           = [30,100,100,150,150,150,150,150];
  %  delta_min           = [70,80,80,120,1220,120,120,120];
   % delta_max           = [-70,-80,-80,-120,-120,-120,-120,-120];
    %Power_max_vect      = [1E7,1E7,3E7,6E7,8E7,15E7,20E7,30E7];
%     epsilon_vector      = 2*pi*[1E9,2E9,3E9,4E9,5E9,10E9,20E9];   
%     omega_max           = [150,150,150,150,150,150,150];
%     delta_min           = [-150,-150,-150,-150,-150,-150,-150];
%     delta_max           = [150,150,150,150,150,150,150,150];
%     Power_max_vect      = [5E7,5E7,5E7,5E7,5E7,5E7,5E7];
%     epsilon_vector      = 2*pi*[5E9,100E9,150E9,200E9]*10;   
%     omega_max           = [320,320,320,320]*3;    
%     delta_min           = [-40,-20,-20,-20];
%     delta_max           = [20,10,10,10];
%     Power_max_vect      = [10E7];

    kvector             = [0:50];
    epsilon_vector      = -120;   
    omega_max           =  40*2;
    delta_min           = -40;
    delta_max           =  90;
    Save_Omega          = GetMiOmegaPlane(Res,epsilon_vector,omega_max,delta_max,delta_min,kvector,NNP,NND);
%%
%     Res.CW.Par.Equation_string  = 'Chi23_CW';
%     Res.CW.Met.Equation         = @Chi23_CW;
%     Res.CW.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
%     Res.CW.Met.Newton           = @fsolve;%'fsolve'
%     Res.CW.Par.Change_Space     = 0;
%     
%     Res.CW.Par.variable         = 'delta_o';  %%'Pump Power';
%     Res.CW.Par.first_step       = 0.05; % step for delta measured in delta/kappa
%     Res.CW.Par.step_tol         = 0.001;
%     Res.CW.Par.step_inc         = 0.00;
%     Res.CW.Par.step_dec         = 0.5;
% 
%     Res.CW.Par.bot_boundary     = -40; % bottom boundary for delta to search
%     Res.CW.Par.top_boundary     =  40; % top boundary for delta to search
%     Res.CW.Par.Sol_Re_Sign      = '-';
%     Res.CW.Par.Stability        = false;
%     Res.CW.Par.Newton_iter      = 30;      
%     Res.CW.Par.Newton_tol       = 1E-10;  
%     Res.CW.Par.i_max            = 1000;
%     
%     Res.CW.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
%     false,'Display','none','UseParallel',false,'SpecifyObjectiveGradient',false,...
%     'Algorithm','trust-region-dogleg','FunValCheck','on',...
%     'MaxIterations',1000,'StepTolerance',1E-25,'OptimalityTolerance',1E-25,'FunctionTolerance',10^(-10));

%%

%% Omega_Scan
  save(strcat('Mi_Omega_Turing','eps=p25m25','Delta=m100p100'),'Save_Omega');%,'_eps=',num2str(Res.CW.In.eps/2/pi)
%%
    clear delta_vector W_Vector
    for iii = 1:size(epsilon_vector,2)
tic
            
    Res.CW.In.eps       = epsilon_vector(iii);
    delta_vector        = linspace(delta_max(iii),delta_min(iii),NND)*Res.CW(1).In.ko;
    W_Vector            = linspace(600,Power_max_vect(iii),NNP);
    Mumber2             = NaN(NNP,NND);
    Mumber23            = NaN(NNP,NND);
    
    parfor i_p = 1:NNP
        
        Res_S                   = Res;
        Res_S.CW.In.W           = W_Vector(i_p)*Res_S.CW.In.W_Star;        
        Res_S.CW                = Res_S.CW.Met.Solve_Chi2(Res_S.CW ); 
         Ext                    = @max;
        [~,ind]                 = Ext(abs(Res_S.CW.Sol.Omega));
        
        Res_S.CW.Sol.Omega      =  Res_S.CW.Sol.Omega(ind);    
        Res_S.CW.Sol.Psi_o      =  Res_S.CW.Sol.Psi_o(ind);    
        Res_S.CW.Sol.Psi_e      =  Res_S.CW.Sol.Psi_e(ind);
        
        for i_d = 1:NND
            
            Res_S.CW.In.delta_o    = delta_vector(i_d);            
            Res_S.CW               = Res.CW.Met.Norm(Res_S.CW);  
            [Slv,eps_f,Exitflag]   = Newton_Switcher([real(Res_S.CW.Sol.Psi_o(1)),imag(Res_S.CW.Sol.Psi_o(1)),real(Res_S.CW.Sol.Psi_e(1)),imag(Res_S.CW.Sol.Psi_e(1))],Res_S.CW);
            Res_S.CW               = Res_S.CW.Met.Prop_Gen(Slv,Res_S.CW);      
            
%            Psi_o(i_p,i_d)         = Res_S.CW.Sol.Psi_o;
            if eps_f > 1E-8
                
                break;
                
            end        
            [Mumber2(i_p,i_d),Mumber23(i_p,i_d)]      = Evaluate_MI_Power( Res_S,Ext);
        end
    end
    
    Save_Upper(iii).Res                  = Res;
    Save_Upper(iii).delta_vector         = delta_vector; 
    Save_Upper(iii).W_Vector             = W_Vector;
    Save_Upper(iii).Mumber2              = Mumber2;
    Save_Upper(iii).Mumber23             = Mumber23;
    
    toc 
    end
   
     clear delta_vector W_Vector
   for iii = 1:size(epsilon_vector,2)
            
    Res.CW.In.eps       = epsilon_vector(iii);
    delta_vector        = linspace(delta_min(iii),delta_max(iii),NND)*Res.CW(1).In.ko;
    W_Vector            = linspace(600,Power_max_vect(iii),NNP);
    
    tic
    Mumber2             = NaN(NNP,NND);
    Mumber23            = NaN(NNP,NND);
    
    parfor i_p = 1:NNP
        
        Res_S                   = Res;
        Res_S.CW.In.W           = W_Vector(i_p)*Res_S.CW.In.W_Star;        
        Res_S.CW                = Res_S.CW.Met.Solve_Chi2(Res_S.CW ); 
        Ext                     = @min;
        [~,ind]                 = Ext(abs(Res_S.CW.Sol.Omega));
        
        Res_S.CW.Sol.Omega      =  Res_S.CW.Sol.Omega(ind);    
        Res_S.CW.Sol.Psi_o      =  Res_S.CW.Sol.Psi_o(ind);    
        Res_S.CW.Sol.Psi_e      =  Res_S.CW.Sol.Psi_e(ind);
        
         for i_d = 1:NND
            
            Res_S.CW.In.delta_o    = delta_vector(i_d);            
            Res_S.CW               = Res.CW.Met.Norm(Res_S.CW);  
            [Slv,eps_f,Exitflag]   = Newton_Switcher([real(Res_S.CW.Sol.Psi_o(1)),imag(Res_S.CW.Sol.Psi_o(1)),real(Res_S.CW.Sol.Psi_e(1)),imag(Res_S.CW.Sol.Psi_e(1))],Res_S.CW);
            Res_S.CW               = Res_S.CW.Met.Prop_Gen(Slv,Res_S.CW);      
            
            if eps_f > 1E-8
                
                break;
                
            end        
            [Mumber2(i_p,i_d),Mumber23(i_p,i_d)]      = Evaluate_MI_Power( Res_S,Ext);
        end
    end
    
    Save_Lower(iii).Res                  = Res;
    Save_Lower(iii).delta_vector         = delta_vector; 
    Save_Lower(iii).W_Vector             = W_Vector;
    Save_Lower(iii).Mumber2              = Mumber2;
    Save_Lower(iii).Mumber23             = Mumber23;
    
    end

    Is = 1;
%%    
    Is = 1;
    mu_res = -1;
    mu_vec = [0:Save_Omega(Is).Res.CW.In.N/2];
    
    for i = 1:2
        mu(i).mu = mu_vec(i);
        mu(i).k = zeros(size(Save_Omega(Is).k,1),size(Save_Omega(Is).k,2));
        
        for ip = 1:size(Save_Omega(Is).k,1)

            for id = 1:size(Save_Omega(Is).k,2)
                    mu(i).k(ip,id) =  sum(Save_Omega(Is).k(ip,id).k == mu_vec(i)) > 0;
            end
            ip
        end
        if  mu_vec(i) ~= mu_res
            [indy,indx] = find(mu(i).k == 1);
            k = boundary(indx,indy,0.6);
            mu(i).delta = Save_Omega(Is).delta_vector(indx(k))/Save_Omega(Is).Res.CW.In.ko;
            mu(i).Omega = Save_Omega(Is).W_Vector(indy(k));
        end 
        
    end
    
%%    

    parfor i = 1:Save_Omega(Is).Res.CW.In.N/2
        if  mu_vec(i) ~= mu_res
            [indy,indx] = find(mu(i).k == 1);
            k = boundary(indx,indy,0.6);
            mu(i).delta = Save_Omega(Is).delta_vector(indx(k))/Save_Omega(Is).Res.CW.In.ko;
            mu(i).Omega = Save_Omega(Is).W_Vector(indy(k));
        end 
       if mu(i).mu ==  mu_res
           
            [indy,indx] = find(mu(i).kp == 1);
            k = boundary(indx,indy,0.6);
            mu(i).deltap = Save_Omega(Is).delta_vector(indx(k))/Save_Omega(Is).Res.CW.In.ko;
            mu(i).Omegap = Save_Omega(Is).W_Vector(indy(k));
           
            [indy,indx] = find(mu(i).km == 1);
            k = boundary(indx,indy,0.6);
            mu(i).deltam = Save_Omega(Is).delta_vector(indx(k))/Save_Omega(Is).Res.CW.In.ko;
            mu(i).Omegam = Save_Omega(Is).W_Vector(indy(k));

       end
    end

%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Save_Omega = GetMiOmegaPlane(Res,epsilon_vector,omega_max,delta_max,delta_min,kvector,NNP,NND)

    for ii = 1:size(epsilon_vector,2)
        
        Res.CW.In.eps       = epsilon_vector(ii)*Res.CW.In.ko;
        Omega_Vector        = linspace(0,omega_max(ii),NNP)*Res.CW.In.Omega_Star;
        delta_vector        = linspace(delta_max(ii),delta_min(ii),NND)*Res.CW(1).In.ko;

        Save_Omega(ii).epsilon = epsilon_vector(ii);
        Save_Omega(ii).delta   = delta_vector;
        Save_Omega(ii).Omega   = Omega_Vector;
        
        for ik =1:size(kvector,2)
            
            CW              = Res.CW;
            CW.In.kMI       = kvector(ik); 
            Mumber          = zeros(NNP,NND);
            ReLam           = zeros(NNP,NND);
            
            parfor i_p = 1:NNP
                CWW = CW;
                for i_d = 1:NND

                    CWW.In.delta_o     = delta_vector(i_d);
                    CWW.Sol.Omega      = Omega_Vector(i_p);      
                    
                    [Mumber(i_p,i_d),ReLam(i_p,i_d), ~] =  Evaluate_MI_Omega(CWW);
                    %
                end  

            end
            
            kMI(ik).Res                  = Res;        
            kMI(ik).Mumber               = Mumber;
            
        end
        
        Save_Omega(ii).kMI = kMI;
        
    end

end
function [Mumber,ReLam,ImLam] =  Evaluate_MI_Omega(CW)
    
    CW            = CW.Met.Norm(CW);
    CW.Stab       = Chi23_MI(CW);
%    [~,1]       = max(abs(CW.Sol.Omega));
    ReLam         = max(real(CW.Stab.Value));
    ImLam         = uniquetol(imag(CW.Stab.Value));
    
    if ReLam > 1E-6
        Mumber = 1;
    else
        Mumber = 0;
    end
%    Mumber        = sum(sum(uniquetol(real(Res.CW.Stab(ind).Value))>1E-6));
    
    
%     if Mumber > 0
%         
%         [ir,ic]         = find(Res.CW.Stab(ind).Value > 0);  
%         
%         k               = Res.CW.Space.k(ir);
%         k               = k(k>=0);               
%         vectors         = zeros(4,length(ir));
%         value           = zeros(1,length(ir));
%         
%         for iv = 1:length(ir)
% 
%             value(iv)     = Res.CW.Stab(ind).Value(ir(iv),ic(iv));
%             vectors(:,iv) = Res.CW.Stab(ind).Vector(ir(iv)).V(:,ic(iv));
% 
%         end
%         
%         
%     else
%                 
%         value     = NaN;
%         k         = NaN;        
%         vectors   = NaN;
%         
%     end
end
    

%     [i_r,i_c]         = find(Res.CW.Stab(ind).Value > 0);
%     
%     k      = zeros(1,length(i_r));
%     lambda = zeros(1,length(i_r));
%     Vector = zeros(4,length(i_r));
%     
%     if ~isempty(i_r) > 0
%         for i = 1:length(i_r)
%             
%            k(i)         = Res.CW.Space.k(i_r(i));
%            lambda(i)    = Res.CW.Stab.Value(i_r(i),i_c(i));
%            Vector(:,i)  = Res.CW.Stab.Vector(i_r(i)).V(:,i_c(i));
%             
%         end
%     end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [Mumber2,Mumber23] =  Evaluate_MI_Power(Res,Ext)

    Res.CW2           = Res.CW.Met.Norm(Res.CW);  
    Res.CW23          = Res.CW;
    
    Res.CW2.Met.MI_Matrix   = @Chi2_MI_Matrix;
    Res.CW23.Met.MI_Matrix  = @Chi23_MI_Matrix;
    
    Res.CW2           = Res.CW.Met.Solve_Chi2(Res.CW2);    
    Res.CW2.Stab      = Chi2_MI(Res.CW2);    
    Res.CW23.Stab     = Chi23_MI(Res.CW23);
    
    [~,ind]           = Ext(abs(Res.CW2.Sol.Omega));
    
    Mumber2           = sum(sum(real(Res.CW2.Stab(ind).Value)> 1E-6));
    Mumber23          = sum(sum(real(Res.CW23.Stab(1).Value) > 1E-6));
    
    
%     
%     lambda1 = NaN;
%     Vector1 = NaN;
% 
%     if ~isempty(i_r) > 0
%         k1      = zeros(1,length(i_r));
%         lambda1 = zeros(1,length(i_r));
%         Vector1 = zeros(4,length(i_r));
%         for i = 1:length(i_r)
% 
%            k1(i)         = Res.CW2.Space.k(i_r(i));
%            lambda1(i)    = Res.CW2.Stab(ind).Value(i_r(i),i_c(i));
%            Vector1(:,i)  = Res.CW2.Stab(ind).Vector(i_r(i)).V(:,i_c(i));
% 
%         end
%     end
%     
%     [i_r,i_c]         = find(Res.CW23.Stab.Value > 0);
% 
%     k2      = NaN;
%     lambda2 = NaN;
%     Vector2 = NaN;
% 
%     if ~isempty(i_r) > 0
%         k2      = zeros(1,length(i_r));
%         lambda2 = zeros(1,length(i_r));
%         Vector2 = zeros(4,length(i_r));
%         for i = 1:length(i_r)
% 
%            k2(i)         = Res.CW23.Space.k(i_r(i));
%            lambda2(i)    = Res.CW23.Stab.Value(i_r(i),i_c(i));
%            Vector2(:,i)  = Res.CW23.Stab.Vector(i_r(i)).V(:,i_c(i));
% 
%         end
%     end
end
function [Mumber] =  Evaluate_MI_PowerCHi23(Res,Ext)
%lambda1,Vector1,Mumber2,k2,lambda2,Vector2
%,k,value,vectors
    Res.CW           = Res.CW.Met.Norm(Res.CW);  
    
    Res.CW.Met.MI_Matrix  = @Chi23_MI_Matrix;
    
    Res.CW.Stab     = Chi23_MI(Res.CW);
    
    Mumber           = sum(sum(real(Res.CW.Stab(1).Value)>1E-6));
    
%     if Mumber > 0
%         
%         [ir,ic]         = find(Res.CW.Stab.Value > 0);  
%         
%         k               = Res.CW.Space.k(ir);
%                 
%         vectors         = zeros(4,length(ir));
%         value           = zeros(1,length(ir));
%         
%         for iv = 1:length(ir)
% 
%             value(iv)     = Res.CW.Stab.Value(ir(iv),ic(iv));
%             vectors(:,iv) = Res.CW.Stab.Vector(ir(iv)).V(:,ic(iv));
% 
%         end
%         
%         
%     else
%                 
%         value     = NaN;
%         k         = NaN;        
%         vectors   = NaN;
%         
%     end
    
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
