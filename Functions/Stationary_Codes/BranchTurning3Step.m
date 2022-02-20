    function L_L_1 = BranchTurning3Step(Slv_start,x_0,L_L,sg)

        Slv        = Slv_start;
        i          = 0;
        Exitflag   = 1;
        x_step     = L_L.Par.first_step;
        x          = x_0;
        L_L.Sol.Dir.d1 = NaN;
        L_L.Sol.Dir.d2 = NaN;
        L_L_1      = L_L;
                
        while Exitflag ~= 0
            i
            Exitflag = 0;
            i = i+1;
            
            if i >= 2
                
                L_L_1(i)    = L_L_1(i-1);
                
            end
                        
            Slv_0     = Slv;
            FlagReduce = 1;
           
            x_step     = L_L.Par.step_inc*x_step;
            
            if abs(x_step) > L_L.Par.max_step
                    x_step = L_L.Par.max_step;
            end
            
            x0 = x;
            while  FlagReduce == 1 
        
%                if i == 1
 %               end
                                    
                [L_L_1(i),x,Slv,Exitflag] = MakeNSteps(x,x_step,L_L_1(i),Slv,sg);
               % (Stat,x_step,i)
                [FlagReduce,FlagStop,Logic] = L_L.Met.Newton_Fail_Check(L_L_1(i),x_step,i);
                
                L_L_1(i).Logic = Logic;
                L_L_1(i).Logic.Turning = 0;
                 
                if FlagReduce
                    
                    Slv        = Slv_0;
                    x          = x0;
                    x_step     = x_step*L_L.Par.step_dec;            
                    
                    if i >= 2
                
                        L_L_1(i)    = L_L_1(i-1);
            
                    end
                end
                
                if FlagStop
                    
                    Exitflag = 0;
                    break;
                    
                end
                                
                if Logic.TurnTime  == 1 && FlagReduce == 0
         %         Exitflag = 0;
          %            break;          
      %
                     for it = 1:size(L_L_1,2) 
                        maxvec(it) = y_eval(L_L_1(it));
              %           Psi        =ifft(L_L_1(it).Sol.Psi_o*L_L_1(it).Space.N);
                      %   maxvec(it) = real( Psi(1));
                         devec(it) =  L_L_1(it).Eq.(L_L_1(it).Par.variable);
                      end

                     [Slv,L_L_Turn]    = Turning_Regime(Slv,L_L_1(i),x_step);
                     
                     if size(L_L_Turn,2) == 1
                            Exitflag = 0;
                            break;          
                     end
                     Nturn = size(L_L_Turn,2);
                     x =L_L_Turn(end).Eq.(L_L_Turn(end).Par.variable);
                     x_step = abs(L_L_Turn(end).Eq.(L_L_Turn(end).Par.variable)...
                        -L_L_Turn(end-1).Eq.(L_L_Turn(end).Par.variable));
                   % x_step = x_step/10;
                     sg = sign(L_L_Turn(end).Eq.(L_L_Turn(end).Par.variable)...
                         -L_L_Turn(end-1).Eq.(L_L_Turn(end).Par.variable));   
                     L_L_1(i+1:i+Nturn)   =  L_L_Turn;   
                     i = i + Nturn;
                     
                     if L_L_Turn(end).Logic.Resid == 1 %|| L_L_Turn(end).Logic.rCW
                        Exitflag = 0;
                        break;
                     end
                  %     x_step =   1E-6;
%                     i  = i + 1;
%                     L_L_1(i) = L_L_Turn(end);
%                     
%                     sg   = - sg;
%                     Turn = 0;
% 
%                     [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,L_L_1(i));
%                     L_L_1(i)             = L_L.Met.Prop_Gen(Slv,L_L_1(i));     
                    
                end
            end
                       
%             
%             switch L_L.Par.Stability
%                 
%                 case 1
%                     
%                     L_L_1(i).Stab                 = Stability_Switcher(L_L_1(i));
%                     
%                 case 0
%                     
%                     L_L_1(i).Stab.E_values  = NaN;
%                     L_L_1(i).Stab.E_vectors = NaN;
%                     
%             end
                                   
        end
        
        L_L_1(i+1:end) = [];
        
    
        
        
    
       
        function [Slv,Stat] = Turning_Regime(Slv_Start,Stat,x_step)
            Slv  = [0,Slv_Start(2:end)];
            
            Stat.Met.Equation             = L_L.Met.Equation_Mod;             
            Stat.Met.Liniar_Decomposition = L_L.Met.Liniar_Decomposition_Mod;
            Stat.Met.Preconditioner       = L_L.Met.Preconditioner_Mod;           
            
%            Stat.Met.Newton_Matrix       = L_L.Met.Newton_Matrix_Mod;            
            ii = 1;
            
            if  Stat(ii).Sol.Dir.d1 ~= 0
                
                stepPsi = Stat(ii).Sol.Dir.d1*x_step/2;
                
            else
                
                stepPsi = Stat(ii).Sol.Dir.d1s*x_step;
                 
            end
             stepPsi =  stepPsi/10;
            if  abs(stepPsi) < 1E-12
                 stepPsi = sign(Stat(ii).Sol.Dir.d1s)*1e-9;
            end
            smcoeff   = 1.0;
            FlagStop =1;
            
            while FlagStop
                
                ii = ii+1;
                Stat(ii) = Stat(ii-1);
                StepStop = 1;
                SlvStart = Slv;
                stepPsi = stepPsi*1.001;
                
                while StepStop
                    
                    StepStop                    = 0;
                    [Stat(ii),Slv,ExitflagTurn] = MakeNTurningSteps(stepPsi,Stat(ii),Slv);               
                    [~,~,Logic]                 = L_L.Met.Newton_Fail_Check(Stat(ii),ii,stepPsi);
                    
                    if Logic.Resid 
                        StepStop = 1;
                        stepPsi  = stepPsi/2;
                        Stat(ii) = Stat(ii-1);
                        Slv      =SlvStart;
                    else
                    if (abs(Stat(ii).Sol.Dir.d1) <50) && ii> 5 %&& (Stat(ii).Sol.Dir.d1 ~= 0) && (ii >5)) || stepPsi < 1E-11
                        FlagStop = 0;
                    end
%                         if (abs(Stat(ii).Sol.Dir.d1) < 0.01) %&& (Stat(ii).Sol.Dir.d1 ~= 0) && (ii >5)) || stepPsi < 1E-11
%                             FlagStop = 0;
%                         end
                    end
                end
                ii
            end
            
 %% if something wrong
                      for it = 1:size(Stat,2)
                        maxvec(it) = y_eval(Stat(it));
%                         Psi        = ifft(Stat(it).Sol.Psi_o*Stat(it).Space.N);
 %                        maxvec(it) = real(Stat(it).Sol.Psi_o(1));
                         devec(it)  =  Stat(it).Eq.(Stat(it).Par.variable);
                      end

%             devec =  [];   
%             maxvec = [];
%             
%             for it = 1:size(Stat,2)
%                 maxvec(it) = real(Stat(it).Sol.Psi_k(1));
%                 devec(it) =  Stat(it).Eq.(Stat(it).Par.variable);
%             end
            
            %%
            Stat(end).Met.Equation             = L_L.Met.Equation;             
            Stat(end).Met.Liniar_Decomposition = L_L.Met.Liniar_Decomposition;
            Stat(end).Met.Preconditioner       = L_L.Met.Preconditioner;    
            Stat(end).Met.Newton_Matrix        = L_L.Met.Newton_Matrix;        
            Slv(1)                             = Stat(end).Eq.PsioMax;
 %           Slv(1)                             = Stat(end).Eq.PsioMax;
            [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,Stat(end));
            Stat(end)            = Stat(end).Met.Prop_Gen(Slv,Stat(end));                 

            
        end
    end
    
    function [Stat,x,Slv,Exitflag] = MakeNSteps(x,x_step,Stat,Slv,sg)
    
        N_Step = 4;
        x_step = x_step/N_Step;
        Flag   = 1;
        StatS = Stat;
        x0    = x;
        y_vec = zeros(1,N_Step);
        
        for i = 1:N_Step
            
                x          = x0 + sg*x_step*i;                
                Stat(i)    = step_eq(Stat(i),x);
                                  
                [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,Stat(i));
                
                Stat(i).Sol.eps_f = eps_f;
                Stat(i)           = Stat(i).Met.Prop_Gen(Slv,Stat(i));     
                
                if eps_f >  Stat(end).Par.Newton_tol
                    Flag = 0;
                    break;
                end
                
                
                Stat(i+1)         = Stat(i);
                y_vec(i)          = y_eval(Stat(i));
%               x_vec(i)          = Stat(i).Eq.(Stat(i).Par.variable);
%               y_vec(i)          = real(Stat(i).Sol.Psi_k(1));
 %               Psi               = ifft(Stat(i).Sol.Psi_o*Stat(i).Space.N);
%                y_vec(i)          = real(Psi(1));
        end
        
        Stat = Stat(end);
        Dir1 = [-1/3;3/2;-3;11/6];  
        Dir2 = [-1;4;-5;2];
        
 %      y_vec = y_vec./abs(y_vec(end));
        if Flag == 1
           
            Stat.Sol.Dir.d1 = y_vec*Dir1/(x_step);
            Stat.Sol.Dir.d2 = y_vec*Dir2/(x_step).^2;
            Stat.Sol.Dir.d1s = StatS.Sol.Dir.d1;
            Stat.Sol.Dir.d2s = StatS.Sol.Dir.d2;

        end
    end
    
    function [Stat,Slv,Exitflag] = MakeNTurningSteps(stepPsi, StatS,Slv)
    
        N_Step = 4;
        Flag   = 1;
        Stat = StatS;
       % stepPsi = stepPsi;
        
        for i = 1:N_Step
            
                Stat(i).Eq.PsioMax = y_eval(Stat(i)) + ...
                    + stepPsi; 
    %            Psi               = ifft(Stat(i).Sol.Psi_o*Stat(i).Space.N);
    %            Psi               = real(Stat(i).Sol.Psi_o);
 
                %Stat(i).Eq.PsioMax =  real(Psi(1)) + ...
               %     + stepPsi;

                
                [Slv,eps_f,Exitflag] = Newton_Switcher(Slv,Stat(i));
                
                Stat(i).Sol.eps_f = eps_f;
                Stat(i)           = Stat(i).Met.Prop_Gen(Slv,Stat(i));  
                
                if eps_f >  Stat(end).Par.Newton_tol
                    
                    Flag = 0;
                    break;
                    
                end
                
                Stat(i+1)         = Stat(i);
                x_vec(i)          = Stat(i).Eq.(Stat(i).Par.variable);
                y_vec(i)          = y_eval(Stat(i));
%                Psi               = ifft(Stat(i).Sol.Psi_o*Stat(i).Space.N);
 %               y_vec(i)          =  real(Psi(1));
                
        end
        
        Stat = Stat(end);
        Dir1 = [-1/3;3/2;-3;11/6];  
        Dir2 = [-1;4;-5;2];
        
        if Flag == 1
           
            Stat.Sol.Dir.d1 = (y_vec(end)-y_vec(1))/(x_vec(end)-x_vec(1));
            Stat.Sol.Dir.d2 = y_vec*Dir2/stepPsi.^2;
            
        end
    end
    
    function Stat   = step_eq(Stat,x)

        switch Stat.Par.variable
            case 'h'
                
%                Stat.Eq.h    = x;%;%%;*sqrt(L_L.In.gamma/L_L.In.kappa)
          %      h = 1/2*Stat.In.kappa*Stat.In.H/Stat.Eq.norm
                Stat.In.H           = x*Stat.Eq.norm*2/Stat.In.kappa;
                Stat.In.P            = pi/(Stat.In.eta*Stat.In.Finess)*Stat.In.H^2;
             %   Stat.In.P    = x*(1/2*Stat.In.kappa*sqrt(Stat.In.eta*Stat.In.Finess/pi)/Stat.Eq.norm).^-2;
                Stat         = Stat.Met.Norm(Stat);

            case 'Fin_D'
                        Stat.In.Fin_D     = x;
                        Stat.In.kappa     = Stat.In.D(2)/Stat.In.Fin_D;
                        Stat.In.delta     = Stat.In.kappa*Stat.Eq.delta;
                        Stat.In.P         = Stat.In.W_WStar*pi/(Stat.In.eta*Stat.In.D(1)/Stat.In.kappa)*Stat.In.kappa/Stat.In.gamma; 
                        Stat              = Stat.Met.Norm(Stat);
            case 'Fin_Dlog'
                        Stat.Eq.Fin_Dlog     = x;
                        Stat.In.kappa     = Stat.In.D(2)/10^(Stat.Eq.Fin_Dlog);
                        Stat.In.delta     = Stat.In.kappa*Stat.Eq.delta;
                        Stat.In.P         = Stat.In.W_WStar*pi/(Stat.In.eta*Stat.In.D(1)/Stat.In.kappa)*Stat.In.kappa/Stat.In.gamma; 
                        Stat = Stat.Met.Norm(Stat);
            case 'delta_e'
                
                Stat.Eq.delta_e = x;
                Stat.In.delta_e = Stat.Eq.delta_e*Stat.Eq.norm;
                Stat.In.delta_o = (Stat.In.delta_e + Stat.In.eps)/2;
                Stat            = Stat.Met.Norm(Stat);
                
           case 'gam2o'
                
                Stat.Eq.gam2o = x;
                Stat.Eq.gam2e = x;
                
                Stat.In.gam2o = Stat.Eq.gam2o*Stat.Eq.norm;
                Stat.In.gam2e = Stat.Eq.gam2e*Stat.Eq.norm;
                Stat            = Stat.Met.Norm(Stat);
            case 'D3Kerr'
                
                Stat.In.D(3)      = x*Stat.Eq.norm;
                Stat            = Stat.Met.Norm(Stat);


                
             otherwise

                Stat.Eq.(Stat.Par.variable) = x;
                Stat.In.(Stat.Par.variable) = Stat.Eq.norm*Stat.Eq.(Stat.Par.variable);
                Stat = Stat.Met.Norm(Stat);

        end

    end
    function y = y_eval(Stat)
        switch func2str(Stat.Met.Equation)            
            case 'Chi23_Zero_Mode_Equation'
                y = real(Stat.Sol.Psi_o(1));
            case 'Chi23_Zero_Mode_Equation_RS_delta'
                y = real(Stat.Sol.Psi_o(1));
            case 'Chi23_Full_Dispersion_Equation_RS'
                Psi       = ifft(Stat(1).Sol.Psi_o*Stat(1).Space.N);
                y          = real(Psi(1));
            case 'Chi23_Full_Dispersion_Equation_RS_delta'
                Psi       = ifft(Stat(1).Sol.Psi_o*Stat(1).Space.N);
                y          = real(Psi(1));
            case 'Chi23_Full_Dispersion_Equation_RS_OPO'
                Psi       = ifft(Stat(1).Sol.Psi_o*Stat(1).Space.N);
                y          = real(Psi(1));
            case 'Chi23_Full_Dispersion_Equation_RS_delta_OPO'
                Psi       = ifft(Stat(1).Sol.Psi_o*Stat(1).Space.N);
                y          = real(Psi(1));
            case 'LLE_Full_Dispersion_Equation'
                y          = real(Stat(1).Sol.Psi_k(1));
            case 'LLE_Full_Dispersion_Equation_Turndelta'
                y          = real(Stat(1).Sol.Psi_k(1));
            case 'LLE_Zero_Velocity_Equation'
                y          = real(Stat(1).Sol.Psi_k(1));                
        end
    end
