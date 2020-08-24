    function [x0,eps_f,SolveFlag] = Newton_Manual_bicgstab(Stat,x0)
    
        fun           =  Stat.Met.Equation(x0,Stat);
        eps_f         =  max(abs(fun));
        
        SolveFlag = 1;
        j = 0;
    
        Check = sum(abs(fun) > Stat.Par.Newton_tol );
        
        while Check > 1
            
            [dx,flag,relres,iter,resvec] =  bicgstabl(@(t)Stat.Met.Liniar_Decomposition(t,x0,Stat),Stat.Met.Equation(x0,Stat),10^-11,300,@(t)Stat.Met.Preconditioner(t,Stat,x0));
            
            x0(1,1:end)     = x0' - dx;
            fun             = Stat.Met.Equation(x0,Stat);
            eps_f           = sum(abs(fun));
            
            if j == 10
        
                SolveFlag = -1;
                break;
            
            end
        
           Check =  sum(abs(fun) > Stat.Par.Newton_tol );
           j = j+1;
        
        end
        
    end