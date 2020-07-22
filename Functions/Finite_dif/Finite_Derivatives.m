function Dir = Finite_Derivatives(N,dphi)

    temp_dir1 = [ 4/5*ones(1,1),zeros(1,N-1);
                 -1/5*ones(1,2),zeros(1,N-2);
                  4/105*ones(1,3),zeros(1,N-3);
                 -1/280*ones(1,4),zeros(1,N-4);
                  1/280*ones(1,N-4),zeros(1,4);
                 -4/105*ones(1,N-3),zeros(1,3);
                  1/5*ones(1,N-2),zeros(1,2);
                 -4/5*ones(1,N-1),zeros(1,1);
                  0*ones(1,N);
                  zeros(1,1),4/5*ones(1,N-1);
                  zeros(1,2),-1/5*ones(1,N-2);  
                  zeros(1,3),4/105*ones(1,N-3);
                  zeros(1,4),-1/280*ones(1,N-4)
                  zeros(1,N-4),1/280*ones(1,4);
                  zeros(1,N-3),-4/105*ones(1,3);
                  zeros(1,N-2),1/5*ones(1,2);
                  zeros(1,N-1),-4/5*ones(1,1)]';

    temp_dir2 = [ 8/5*ones(1,1),zeros(1,N-1);
                 -1/5*ones(1,2),zeros(1,N-2);
                  8/315*ones(1,3),zeros(1,N-3);
                 -1/560*ones(1,4),zeros(1,N-4);
                 -1/560*ones(1,N-4),zeros(1,4);
                  8/315*ones(1,N-3),zeros(1,3);
                 -1/5*ones(1,N-2),zeros(1,2);
                  8/5*ones(1,N-1),zeros(1,1);
                 -205/72*ones(1,N);
                  zeros(1,1),8/5*ones(1,N-1);
                  zeros(1,2),-1/5*ones(1,N-2);
                  zeros(1,3),8/315*ones(1,N-3);
                  zeros(1,4),-1/560*ones(1,N-4);
                  zeros(1,N-4),-1/560*ones(1,4);
                  zeros(1,N-3),8/315*ones(1,3);
                  zeros(1,N-2),-1/5*ones(1,2);
                  zeros(1,N-1),8/5*ones(1,1)]';
    temp_dir3 = [
                 -61/30*ones(1,1),zeros(1,N-1);
                  169/120*ones(1,2),zeros(1,N-2);
                 -3/10*ones(1,3),zeros(1,N-3);
                  7/240*ones(1,4),zeros(1,N-4);
                 -7/240*ones(1,N-4),zeros(1,4);
                  3/10*ones(1,N-3),zeros(1,3);
                 -169/120*ones(1,N-2),zeros(1,2);
                  61/30*ones(1,N-1),zeros(1,1);
                  0*ones(1,N);
                  zeros(1,1),-61/30*ones(1,N-1);
                  zeros(1,2),169/120*ones(1,N-2);
                  zeros(1,3),-3/10*ones(1,N-3);
                  zeros(1,4),7/240*ones(1,N-4);
                  zeros(1,N-4),-7/240*ones(1,4)
                  zeros(1,N-3),3/10*ones(1,3);
                  zeros(1,N-2),-169/120*ones(1,2);
                  zeros(1,N-1),61/30*ones(1,1)]';
    temp_dir4 = [
                 -122/15*ones(1,1),zeros(1,N-1);
                  169/60*ones(1,2),zeros(1,N-2);
                  -2/5*ones(1,3),zeros(1,N-3);
                  7/240*ones(1,4),zeros(1,N-4);
                  7/240*ones(1,N-4),zeros(1,4);
                  -2/5*ones(1,N-3),zeros(1,3);
                  169/60*ones(1,N-2),zeros(1,2);
                 -122/15*ones(1,N-1),zeros(1,1);
                  91/8*ones(1,N);
                  zeros(1,1),-122/15*ones(1,N-1);
                  zeros(1,2),169/60*ones(1,N-2);
                  zeros(1,3),-2/5*ones(1,N-3);
                  zeros(1,4),7/240*ones(1,N-4)
                  zeros(1,N-4),7/240*ones(1,4)
                  zeros(1,N-3),-2/5*ones(1,3);
                  zeros(1,N-2),169/60*ones(1,2);
                  zeros(1,N-1),-122/15*ones(1,1);
                  ]';


    Dir.d1 = spdiags(temp_dir1,[-N+1;-N+2;-N+3;-N+4;-4;-3;-2;-1;0;1;2;3;4;N-4;N-3;N-2;N-1],N,N)/(dphi);
    Dir.d2 = spdiags(temp_dir2,[-N+1;-N+2;-N+3;-N+4;-4;-3;-2;-1;0;1;2;3;4;N-4;N-3;N-2;N-1],N,N)/(dphi).^2;
    Dir.d3 = spdiags(temp_dir3,[-N+1;-N+2;-N+3;-N+4;-4;-3;-2;-1;0;1;2;3;4;N-4;N-3;N-2;N-1],N,N)/(dphi).^3;
    Dir.d4 = spdiags(temp_dir4,[-N+1;-N+2;-N+3;-N+4;-4;-3;-2;-1;0;1;2;3;4;N-4;N-3;N-2;N-1],N,N)/(dphi).^4;
    Dir.d5 = Dir.d1*Dir.d4;
    
end


