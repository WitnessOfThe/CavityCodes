function Chi3_CrystalStartDynamicsFromFolder(SSP,Par)

    NN = numel(dir(strcat(SSP,'*.mat')));
    
    if NN ~= 0
        
        if NN > Par.NN
            dd = NN/Par.NN;
            dd =1;
        else
            dd = 1;
        end
        
    
        parfor iSt=1:NN

            indRun(iSt) =LoadAndCheck(SSP,iSt,dd,Par);

        end

        NNRun = sum(indRun);
        iStvec = 1:NN;
        iStvec = iStvec(indRun ==1);
        
        if ~isempty(iStvec)
            if sum(iStvec) >5
                parfor i=1:NNRun
            
                    iSt =iStvec(i);
                    LoadAndRun(SSP,iSt,dd,Par);
                end
            
            end
        end
    end

end
function LoadAndRun(SSSP,iSt,dd,Par)
        NaiSt= IndexToChar(floor(iSt/dd)+26^2*27+26);
        
        Res                   = Set_Up_Methods_For_Bloch_Matrices;

        Res.Temp.Par.Runge_Type    = 'Runge SSPRK3';    
        Res.Temp.Par.dt            = 1E-3;
        Res.Temp.Par.s_t           = 0.1;
        Res.Temp.Par.T             = Par.T;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        Res.Temp.Par.dd            = Res.Temp.Par.T/Res.Temp.Par.s_t;
        Res.Temp.Par.CW_num        = 1;
        Runge                      = Define_Runge_Coeff(Res.Temp.Par);

        Stat = importdata(strcat(SSSP,NaiSt{1},'.mat'));  
        
             Res.Stat = Stat;
             Res.Temp.In = Res.Stat.In;
             Res.Temp.In.N_mode = Par.N;
             Res.Temp.In.mu_bl = 1;
             Res.Temp = Res.Temp.Met.Norm(Res.Temp);
             
             Res             = Chi3_LLE_Start_Point_Bloch(Res);
             Res.Temp.Met    = [];
             Temp = Res.Temp;
             
             tic
             Temp.Sol = Chi_3_LLE_Runge_Kuarong_mex(Res.Temp,Runge);
             toc
             
             Temp = GenerateHandyOutcome(Temp);
             if ~exist(strcat(SSSP,'Dynamics/'),'dir')
        
                mkdir(strcat(SSSP,'Dynamics/'));
        
             end
             
             save(strcat(SSSP,'Dynamics/',NaiSt{1},'.mat'),'Temp');
             
end
function Temp =GenerateHandyOutcome(Temp)
    NN      =   size(Temp.Sol.t,2);
    ind_t   = (3/4*NN+1):1:NN;
    T   = (Temp.Sol.t(ind_t(end))- Temp.Sol.t(ind_t(1)));
    dt  = (Temp.Sol.t(2)- Temp.Sol.t(1));
    
    Nt  = size(ind_t,2);
    f   = 2*pi/T*[0:Nt/2-1,-Nt/2:-1];
    
    for i =1:size(Temp.Sol.Psi,2)
        Temp.Sol.Psi_t(i) = trapz(abs(Temp.Sol.Psi(ind_t,i)).^2)/T*dt;
        [~,ind]            = max(abs(fft(Temp.Sol.Psi(ind_t,i))).^2);
        Temp.Sol.omega(i)  = f(ind);
    end
    Temp.Sol.fullBeat = sum(abs(Temp.Sol.Psi(ind_t,:)).^2,2);
    Temp.Sol.Psi = Temp.Sol.Psi([1,NN],:);
    Temp.Sol.T   = T;
    Temp.Sol.dt  = dt;
end
function Flag = LoadAndCheck(SSSP,iSt,dd,Par)
        NaiSt= IndexToChar(floor(iSt/dd)+26^2*27+26);

         if isfile(strcat(SSSP,NaiSt{1},'.mat'))
            Stat = importdata(strcat(SSSP,NaiSt{1},'.mat'));  
            if max(max(real(Stat.Stab.Values)/Stat.Eq.norm)) > 1E-4        
                Flag = 1;
            else
                Flag = 0;
            end
         else
            Flag = 0;   
         end
%         if isfile(strcat(SSSP,'Dynamics/',NaiSt{1},'.mat'))
%             Flag = 0;                
%         end
end