function [x0,eps_f,SolveFlag] = Newton_Manual(L_L,x0)

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
