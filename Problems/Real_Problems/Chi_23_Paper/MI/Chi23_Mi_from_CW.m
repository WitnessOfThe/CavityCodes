   clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = 2*pi*0.0E9;
    Res.CW.In.delta_o = -1.001*Res.CW.In.ko;%-1.785*Res.CW.In.ko
    Res.CW.In.W       = 3.1E4*Res.CW.In.W_Star;%2E4*Res.CW.In.W_Star;
    
    Res.CW.In.N       = 2^7;
    Res.CW = Res.CW.Met.Norm(Res.CW);
%%
    delta_vector = linspace(-70,70,100);
    [Omega,lambda] = Get_Chi2Mi(Res.CW,delta_vector);

%%
 figure;plot(fftshift(Res.CW.Space.k),fftshift(lambda(:,10)));
  figure;pcolor(delta_vector,fftshift(Res.CW.Space.k),fftshift(lambda(:,:),1));shading interp;

%%
function [Omega,lambda] = Get_Chi2Mi(CW,delta_vector)
    lambda = zeros(CW.In.N,size(delta_vector,2));
    for i = 1:size(delta_vector,2)
        CW.In.delta_o = delta_vector(i)*CW.In.ko;
        CW            = CW.Met.Norm(CW);
        CW            = CW.Met.Solve_Chi2(CW);
        [Omega(i),ind]       = max(CW.Sol.Omega);
        Stab          = Chi23_MI( CW);
        lambda(:,i)   = max(real(Stab(ind).Value),[],2);
    end
end