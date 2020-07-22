function [x0,eps_f,Output]    = Newton_Switcher(Dir,x0,L_L,Delta,Equation,options)
warning('off','MATLAB:bicgstabl:tooSmallTolerance');
    switch Delta.Newton
        
        case 'fsolve'

            [x0,eps_f,Output,~] = fsolve(@(x)Equation(Dir,L_L,x),x0,options);
            
        case 'Manual'
            
            [x0,eps_f,Output]   = Newton_Manual(Equation,Dir,L_L,x0,Delta);
            
        case 'Bc_Grad'
            
            [x0,eps_f,Output]   = Newton_Manual_bicgstab(Equation,L_L,x0,Delta);
             
    end
    
end

function [x0,eps_f,SolveFlag] = Newton_Manual(Equation,Dir,L_L,x0,Delta)

    [fun,Jc] = Equation(Dir,L_L,x0);
    eps_f    =  max(abs(fun));
    
    SolveFlag = 1;
    j = 0;
    
    Check = sum(abs(fun) > Delta.Newton_tol );
    
    while Check > 1
        
        dx = -Jc\fun;
        x0(1:end) = x0' + dx;
        [fun,Jc] = Equation(Dir,L_L,x0);
        eps_f = max(abs(fun));
        
        if j == Delta.Newton_iter
            
            SolveFlag = -1;
            break;
            
        end
        
        Check =  sum(abs(fun) > Delta.Newton_tol );
        j = j+1;
            
    end

end

    function [x0,eps_f,SolveFlag] = Newton_Manual_bicgstab(Equation,L_L,x0,Delta)
    
        
        Liniar_decomp = Delta.Liniar_Decomposition;
        fun           = Equation(x0,L_L);
        eps_f         =  max(abs(fun));
        
        SolveFlag = 1;
        j = 0;
    
        Check = sum(abs(fun) > Delta.Newton_tol );
        
        while Check > 1
            
            [dx,flag,relres,iter,resvec] =  bicgstabl(@(t)Liniar_decomp(t,x0,L_L),Equation(x0,L_L),10^-11,300,@(t)LLE_Full_Dispersion_Predonditioner(t,L_L,x0));%,,,,,,,
            
            x0(1,1:end)     = x0' - dx;
            fun             = Equation(x0,L_L);
            eps_f           =  sum(abs(fun));
            
            if j == 10
        
                SolveFlag = -1;
                break;
            
            end
        
           Check =  sum(abs(fun) > Delta.Newton_tol );
           j = j+1;
        
        end
        
    end
