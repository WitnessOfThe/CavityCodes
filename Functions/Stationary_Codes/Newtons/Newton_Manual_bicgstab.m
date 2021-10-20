    function [x0,eps_f,SolveFlag] = Newton_Manual_bicgstab(Stat,x0)
    
      %  [Stat.Eq.abs_psi2,Stat.Eq.ind] = max(abs(x0(1:Stat.Space.N)+1i*x0(Stat.Space.N+1:2*Stat.Space.N)).^2);
        
        fun           =  Stat.Met.Equation(x0,Stat);
        eps_f         =  max(abs(fun));
        
        SolveFlag = 1;
        j = 0;
        

        Check = sum(abs(fun) > Stat.Par.Newton_tol );
        while Check > 0 %||abs(fun(end)) >= 1E-14
  %      [Stat.Eq.abs_psi2,Stat.Eq.ind] = max(abs(x0(1:Stat.Space.N)+1i*x0(Stat.Space.N+1:2*Stat.Space.N)).^2);
        
  %          [Stat.Eq.abs_psi2,Stat.Eq.ind] = max(abs(x0(1:Stat.Space.N)+1i*x0(Stat.Space.N+1:2*Stat.Space.N)).^2);
% %      

              [dx,flag,relres,iter,resvec] = gmres(@(t)Stat.Met.Liniar_Decomposition...
              (t,x0,Stat),Stat.Met.Equation(x0,Stat),[],1E-5,Stat.Space.N*4+1,@(t)Stat.Met.Preconditioner(t,Stat,x0));%%,...
            
%                 [dx,flag,relres,iter,resvec] = gmres(@(t)Stat.Met.Liniar_Decomposition...
%                 (t,x0,Stat),Stat.Met.Equation(x0,Stat),[],1E-14);%%,...
          %[dx,flag,relres,iter,resvec] =  bicgstab(@(t)Stat.Met.Liniar_Decomposition...
           %   (t,x0,Stat),Stat.Met.Equation(x0,Stat),10^-2,300,@(t)Stat.Met.Preconditioner(t,Stat,x0));%%,...
 %                %
            %
            x0(1,1:end)     = x0.' - dx;
            fun             = Stat.Met.Equation(x0,Stat);
            eps_f           = max(abs(fun));
%             
            if j == Stat.Par.Newton_iter || eps_f > 1E6
        
                SolveFlag = -1;
                break;
                
            end
%                 
        
           Check =  sum(abs(fun) > Stat.Par.Newton_tol ) ;
           j = j+1;
        
         end
        
%         j = 0;
%         
%         while Check > 1
%             
%             [dx,flag,relres,iter,resvec] =  bicgstabl(@(t)Stat.Met.Liniar_Decomposition(t,x0,Stat),Stat.Met.Equation(x0,Stat),10^-3,100,@(t)Stat.Met.Preconditioner(t,Stat,x0) );
%             
%             x0(1,1:end)     = x0' - dx;
%             fun             = Stat.Met.Equation(x0,Stat);
%             eps_f           = sum(abs(fun));
%             
%             if j == 30
%         
%                 SolveFlag = -1;
%                 break;
%             
%             end
%         
%            Check =  sum(abs(fun) > Stat.Par.Newton_tol );
%            j = j+1;
%         
%         end
%         

    end
