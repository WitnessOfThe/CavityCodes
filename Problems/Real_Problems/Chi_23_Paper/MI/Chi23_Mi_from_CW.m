    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_JuanjuanLiNbd;
    Res.CW.In.eps     = 2*pi*85E9;
    Res.CW.In.delta_o = -1.16*Res.CW.In.ko;%-1.785*Res.CW.In.ko
    Res.CW.In.W       =  130E-3;%2E4*Res.CW.In.W_Star;
    
    Res.CW.In.kMI     = [1:16];
    Res.CW.In.N       = [16];
    Res.CW            = Res.CW.Met.Norm(Res.CW);
%%
    delta_vector = linspace(-1.20,-1.1562,100);
    [Omega,lambda] = Get_Chi2Mi(Res.CW,delta_vector);

%%
figure;plot(delta_vector,Omega)

%%
%  figure;plot(Res.CW.In.kMI,(lambda(:,40)));
%  figure;pcolor(delta_vector,(Res.CW.In.kMI),(lambda));shading interp;
 figure;hold on;
 for il =1:4

    plot(delta_vector,(lambda(il,:)));
 end
 plot([min(delta_vector),max(delta_vector)],[0,0],'Color',[0,0,0])
 %%
function [Omega,lambda] = Get_Chi2Mi(CW,delta_vector)
    lambda = zeros(CW.In.N,size(delta_vector,2));
    for i = 1:size(delta_vector,2)
        CW.In.delta_o = delta_vector(i)*CW.In.ko;
        CW            = CW.Met.Norm(CW);
%
        CW = Chi23_CW_Track_fromLower2Point(CW,[CW.In.W,CW.In.W]/CW.In.Wf_Star,[-2,delta_vector(i)])  ;  
      % CW            = CW.Met.Solve_Chi2(CW);
        [Omega(i),ind]       = max(CW.Sol.Omega);
        CW.Met.MI_Matrix=       @Chi23_MI_Matrix;
        Stab          = Chi23_MI( CW);
        lambda(:,i)   = max(real(Stab(ind).Value),[],2);
    end
end