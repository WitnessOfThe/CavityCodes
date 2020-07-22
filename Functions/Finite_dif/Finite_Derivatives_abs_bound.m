function Dir = Finite_Derivatives_abs_bound(N)
%dir1 8th order
%dir2 8th order
%dir3 6th order
%dir4 6th order
%dir5 6th order
%dir5 6th order

%   Detailed explanation goes here
N_sparse = sparse(N,N);

temp_dir1 = [ 
              1/280*ones(1,N-4),zeros(1,4);
             -4/105*ones(1,N-3),zeros(1,3);
              1/5*ones(1,N-2),zeros(1,2);
             -4/5*ones(1,N-1),zeros(1,1);
              0*ones(1,N);
              zeros(1,1),4/5*ones(1,N-1);
              zeros(1,2),-1/5*ones(1,N-2);  
              zeros(1,3),4/105*ones(1,N-3);
              zeros(1,4),-1/280*ones(1,N-4)]';
temp_dir2 = [
             -1/560*ones(1,N-4),zeros(1,4);
              8/315*ones(1,N-3),zeros(1,3);
             -1/5*ones(1,N-2),zeros(1,2);
              8/5*ones(1,N-1),zeros(1,1);
             -205/72*ones(1,N);
              zeros(1,1),8/5*ones(1,N-1);
              zeros(1,2),-1/5*ones(1,N-2);
              zeros(1,3),8/315*ones(1,N-3);
              zeros(1,4),-1/560*ones(1,N-4);
             ]';
temp_dir3 = [
             -7/240*ones(1,N-4),zeros(1,4);
              3/10*ones(1,N-3),zeros(1,3);
             -169/120*ones(1,N-2),zeros(1,2);
              61/30*ones(1,N-1),zeros(1,1);
              0*ones(1,N);
              zeros(1,1),-61/30*ones(1,N-1);
              zeros(1,2),169/120*ones(1,N-2);
              zeros(1,3),-3/10*ones(1,N-3);
              zeros(1,4),7/240*ones(1,N-4)]';
temp_dir4 = [
              7/240*ones(1,N-4),zeros(1,4);
              -2/5*ones(1,N-3),zeros(1,3);
              169/60*ones(1,N-2),zeros(1,2);
             -122/15*ones(1,N-1),zeros(1,1);
              91/8*ones(1,N);
              zeros(1,1),-122/15*ones(1,N-1);
              zeros(1,2),169/60*ones(1,N-2);
              zeros(1,3),-2/5*ones(1,N-3);
              zeros(1,4),7/240*ones(1,N-4)]';
temp_dir5 = [
             -13/288*ones(1,N-5),zeros(1,5);
              19/36*ones(1,N-4),zeros(1,4);
             -87/32*ones(1,N-3),zeros(1,3);
              13/2*ones(1,N-2),zeros(1,2);
             -323/48*ones(1,N-1),zeros(1,1);
              0*ones(1,N);
              zeros(1,1),323/48*ones(1,N-1);
              zeros(1,2),-13/2*ones(1,N-2);
              zeros(1,3),87/32*ones(1,N-3);
              zeros(1,4),-19/36*ones(1,N-4);
              zeros(1,5),13/288*ones(1,N-5)]';
temp_dir6 = [
              13/240*ones(1,N-5),zeros(1,5);
             -19/24*ones(1,N-4),zeros(1,4);
              87/16*ones(1,N-3),zeros(1,3);
             -39/2*ones(1,N-2),zeros(1,2);
              323/8*ones(1,N-1),zeros(1,1);
              -1023/20*ones(1,N);
              zeros(1,1),323/8*ones(1,N-1);
              zeros(1,2),-39/2*ones(1,N-2);
              zeros(1,3),87/16*ones(1,N-3);
              zeros(1,4),-19/24*ones(1,N-4);
              zeros(1,5),13/240*ones(1,N-5)]';

Dir.d1 = spdiags(temp_dir1,[-4;-3;-2;-1;0;1;2;3;4],N,N);%/(1/N);
Dir.d2 = spdiags(temp_dir2,[-4;-3;-2;-1;0;1;2;3;4],N,N);%/(1/N).^2;
Dir.d3= spdiags(temp_dir3,[-4;-3;-2;-1;0;1;2;3;4],N,N);%/(1/N);
Dir.d4 = spdiags(temp_dir4,[-4;-3;-2;-1;0;1;2;3;4],N,N);%/(1/N).^2;
Dir.d5 = spdiags(temp_dir5,[-5;-4;-3;-2;-1;0;1;2;3;4;5],N,N);%/(1/N);
Dir.d6 = spdiags(temp_dir6,[-5;-4;-3;-2;-1;0;1;2;3;4;5],N,N);%/(1/N).^2;
end


