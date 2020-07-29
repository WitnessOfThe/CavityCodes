function L_L = Run_Branch_Back(L_L,Delta,options)

%    warning('off','all');
%    warning;
 %   format short e
           
    [x_0,Slv_start,Equation] = set_up(L_L,Delta,options);
    
    Dir                      = Finite_Derivatives(L_L.Space.N,L_L.Space.dphi); 
    
    L_L_2            = Branch(Dir,Slv_start,x_0,Delta,L_L,-1,Equation,options);
    
    L_L                      = [L_L_2];

end
