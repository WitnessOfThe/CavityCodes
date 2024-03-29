function Stat  = Chi3_CrystalChangeParameter(R,MP,Var)

%%       
       SP   = Chi3_CrystalPathGenerator(R.Stat,MP);
       Stat = importdata(strcat(SP,'Starter.mat'));
       
       switch Var
           case 'FD'
               
               Stat.Par.variable         = 'Fin_Dlog';
               Stat.Par.first_step       = 0.5E-1;
               Stat.Par.max_step         = 0.5E-1;
               Stat.Par.i_max            = 3000;
               Stat.Par.step_tol         = 1E-16;
               Stat.Par.step_inc         = 1.1;  
               Stat.Par.Newton_iter      = 30;  
               Stat.Par.Newton_tol       = 1.1E-12;         
               Stat.Sol.Stab             = NaN;
               Stat.Par.step_dec         = 0.1;  
               Stat                      = Stat(1).Met.Norm(Stat);
               x_0                       = Stat.Eq.Fin_Dlog;
               Stat.Met.Newton_Fail_Check    = @fail_Stat_checkFD;
               
         %      Stat = Run_Branch_Universal_Turning(Stat);
               Stat                      = BranchTurning([real(Stat.Sol.Psi_k)...
                   ,imag(Stat.Sol.Psi_k)]*Stat.Space.N,x_0,Stat,1);
               
               SP = strcat(SP,'/FDScan/');
           case 'delta'
               Stat.Par.variable         = 'delta';
               Stat.Par.first_step       = 0.001;
               Stat.Par.max_step         = 0.01;
               Stat.Par.i_max            = 3000;
               Stat.Par.step_tol         = 1E-4;
               Stat.Par.step_inc         = 1.1;  
               Stat.Par.Newton_iter      = 100;  
               Stat.Par.Newton_tol       = 1E-10;         
               Stat.Sol.Stab             = NaN;
               Stat.Par.step_dec         = 0.5;  
               Stat                      = Stat(1).Met.Norm(Stat);
               Stat.Met.Newton_Fail_Check    = @fail_Stat_checkDelta;
               Stat = Run_Branch_Universal_Turning(Stat);
               
               SP = strcat(SP,'/deltaScan/');
               
               
       end
%%       
       
       
       
       for iSt =1:size(Stat,2)

           Na = IndexToChar(iSt+26^2*27+26);
           SaveStat = Stat(iSt);
           save(strcat(SP,Na{1},'.mat'),'SaveStat');

       end
        
end
  function [FlagReduce,FlagStop,Logic] = fail_Stat_checkDelta(Stat,i,x_step)
     
           
           Logic.Dir.d2    = NaN;
           Logic.Dir.d11   = NaN;
           Logic.Dir.d12   = NaN;
           
           Logic.Smooth    = 0;
           Logic.zero_step = 0;
           Logic.TurnTime  = 0;
           Logic.Stop      = 0;
           Logic.Resid     =   Stat(end).Sol.eps_f > Stat(end).Par.Newton_tol;
           
           if i >= 2
               
               Logic.Dir.y2 = real(Stat(2).Sol.Psi_k(1));
               Logic.Dir.y1 = real(Stat(1).Sol.Psi_k(1));
               
               Logic.Dir.x2 = Stat(2).Eq.(Stat(2).Par.variable);
               Logic.Dir.x1 = Stat(1).Eq.(Stat(2).Par.variable);
               
               Logic.Dir.d11 = (Logic.Dir.y2 - Logic.Dir.y1)/(Logic.Dir.x2 - Logic.Dir.x1)/Logic.Dir.y1 ;
           
               Logic.zero_step   = x_step == 0;
               
               if i >= 3

                   Logic.Dir.y3  = real(Stat(3).Sol.Psi_k(1));

                   
                   Logic.Dir.x3  = Stat(3).Eq.(Stat(3).Par.variable);
                   Logic.Dir.d12 = (Logic.Dir.y3 - Logic.Dir.y2)/(Logic.Dir.x3 - Logic.Dir.x2)/Logic.Dir.y1 ;                   
                   Logic.Dir.d2  = (Logic.Dir.d12 - Logic.Dir.d11)/(Logic.Dir.x3 - Logic.Dir.x1);
                   
                       
                   if  sign(Logic.Dir.d12) == sign(Logic.Dir.d11) 
                       if Logic.Dir.d11 <=1
                          Logic.Smooth      = abs(abs(Logic.Dir.d12)-abs(Logic.Dir.d11)) >= 0.3;
                       end
                       if Logic.Dir.d11 > 1
                           if abs(Logic.Dir.d12) >= abs(Logic.Dir.d11)
                                Logic.Smooth      = abs(Logic.Dir.d12)/abs(Logic.Dir.d11) >= 1.3;
                           else
                                Logic.Smooth      = abs(Logic.Dir.d11)/abs(Logic.Dir.d12) >= 1.3;
                           end
                       end
                       
                   end
                   
                   if  sign(Logic.Dir.d12) ~= sign(Logic.Dir.d11)
                      
                       Logic.Smooth      = abs(abs(Logic.Dir.d12)-abs(Logic.Dir.d11)) >= 0.1;
                                              
                   end

                   Logic.TurnTime      = abs(Logic.Dir.d12) > 15 && Logic.Smooth == 0;
                   
                   if Logic.Dir.d12 == 0
                       Logic.TurnTime     = 1;
                   end
                   if isnan(Logic.Dir.d12)
                       Logic.TurnTime     = 1;
                   end
                   if isinf(Logic.Dir.d12)
                       Logic.TurnTime     = 1;
                   end
               end
           end
           Logic.step        = x_step <Stat(end).Par.step_tol;
             
           Logic.rCW         = sum(abs(Stat(end).Sol.Psi_k(2:end)).^2) <= 1E-10;
           Logic.MaxIter     = i > Stat(1).Par.i_max;           
           FlagReduce        = (Logic.Smooth + Logic.Resid) > 0 ;
           FlagStop          = Logic.MaxIter  + Logic.Stop+Logic.rCW+Logic.step;
     end
 function [FlagReduce,FlagStop,Logic] = fail_Stat_checkFD(Stat,i,x_step)
     
           
           Logic.Dir.d2    = NaN;
           Logic.Dir.d11   = NaN;
           Logic.Dir.d12   = NaN;
           
           Logic.Smooth    = 0;
           Logic.zero_step = 0;
           Logic.TurnTime  = 0;
           Logic.Stop      = 0;
           Logic.Resid     =   Stat(end).Sol.eps_f > Stat(end).Par.Newton_tol;
           
           if i >= 2
               
               Logic.Dir.y2 = real(Stat(2).Sol.Psi_k(1));
               Logic.Dir.y1 = real(Stat(1).Sol.Psi_k(1));
               
               Logic.Dir.x2 = Stat(2).Eq.(Stat(2).Par.variable);
               Logic.Dir.x1 = Stat(1).Eq.(Stat(2).Par.variable);
               
               Logic.Dir.d11 = (Logic.Dir.y2 - Logic.Dir.y1)/(Logic.Dir.x2 - Logic.Dir.x1)/Logic.Dir.y1 ;
           
               Logic.zero_step   = x_step == 0;
               
               if i >= 3

                   Logic.Dir.y3  = real(Stat(3).Sol.Psi_k(1));

                   
                   Logic.Dir.x3  = Stat(3).Eq.(Stat(3).Par.variable);
                   Logic.Dir.d12 = (Logic.Dir.y3 - Logic.Dir.y2)/(Logic.Dir.x3 - Logic.Dir.x2)/Logic.Dir.y1 ;                   
                   Logic.Dir.d2  = (Logic.Dir.d12 - Logic.Dir.d11)/(Logic.Dir.x3 - Logic.Dir.x1);
                   
                       
                   if  sign(Logic.Dir.d12) == sign(Logic.Dir.d11) 
                       if Logic.Dir.d11 <=1
                          Logic.Smooth      = abs(abs(Logic.Dir.d12)-abs(Logic.Dir.d11)) >= 0.3;
                       end
                       if Logic.Dir.d11 > 1
                           if abs(Logic.Dir.d12) >= abs(Logic.Dir.d11)
                                Logic.Smooth      = abs(Logic.Dir.d12)/abs(Logic.Dir.d11) >= 1.3;
                           else
                                Logic.Smooth      = abs(Logic.Dir.d11)/abs(Logic.Dir.d12) >= 1.3;
                           end
                       end
                       
                   end
                   
                   if  sign(Logic.Dir.d12) ~= sign(Logic.Dir.d11)
                      
                       Logic.Smooth      = abs(abs(Logic.Dir.d12)-abs(Logic.Dir.d11)) >= 0.1;
                                              
                   end

                   Logic.TurnTime      = abs(Logic.Dir.d12) > 15 && Logic.Smooth == 0;
                   
                   if Logic.Dir.d12 == 0
                        Logic.Smooth      = 0;
                       Logic.TurnTime     = 1;
                   end
                   if isnan(Logic.Dir.d12)
                        Logic.Smooth      = 0;
                       Logic.TurnTime     = 1;
                   end
                   if isinf(Logic.Dir.d12)
                        Logic.Smooth      = 0;                       
                       Logic.TurnTime     = 1;
                   end
               end
           end
             
           Logic.step        = x_step <Stat(end).Par.step_tol;
           Logic.rCW         = sum(abs(Stat(end).Sol.Psi_k(2:end)).^2) <= 1E-10;
           Logic.MaxIter     = i > Stat(1).Par.i_max;           
           FlagReduce        = (Logic.Smooth + Logic.Resid+ Logic.rCW) > 0 ;
           FlagStop          = Logic.MaxIter  + Logic.Stop+Logic.step;
     end
