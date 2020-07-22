function Dir = Finite_Derivatives_fft(N,k)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
% F = 1;
% for i=1:log(N)/log(2)
%     val = omega_func(2^i);
%     omega = spdiags(val',0,2^(i-1),2^(i-1));
%     F = [speye(2^(i-1),2^(i-1)),omega;
%          speye(2^(i-1),2^(i-1)),-omega]*[F,sparse(2^(i-1),2^(i-1));
%                                        sparse(2^(i-1),2^(i-1)),F];
% end
freq = spdiags(k',0,N,N); 
fft_matrix  = dftmtx(N) ;
ifft_matrix = conj(fft_matrix)/N;
Dir.first =  1i*ifft_matrix*(freq*fft_matrix);
Dir.second = -ifft_matrix*(freq.^2*fft_matrix);
end


    