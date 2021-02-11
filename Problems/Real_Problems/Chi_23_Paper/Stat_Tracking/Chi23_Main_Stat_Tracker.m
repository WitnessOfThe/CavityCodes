    clear all;

%%
    Res = Set_Up_Methods_For_Chi23_Paper;
    
%%
    
    Res.CW.In         = Params_LiNbd;
    Res.CW.In.eps     = -2*pi*10E9;
    Res.CW.In.delta_o = 0;
    Res.CW.In.N       = 2^6;
    Res.CW.In.W       = 100000*Res.CW.In.W_Star;
    
%%
    Res.CW.Par.Equation_string  = 'Chi23_CW';
    Res.CW.Met.Equation         = @Chi23_CW;
    Res.CW.Met.InitialGuess     = @Chi_3_Stat_In_Guess_Chi_3_LLE_From_CW;    
    Res.CW.Met.Newton           = @fsolve;%'fsolve'
    Res.CW.Par.Change_Space     = 0;
    
    Res.CW.Par.variable         = 'delta_o';  %%'Pump Power';
    Res.CW.Par.first_step       = 0.05; % step for delta measured in delta/kappa
    Res.CW.Par.step_tol         = 0.001;
    Res.CW.Par.step_inc         = 0.00;
    Res.CW.Par.step_dec         = 0.5;

    Res.CW.Par.bot_boundary     = -40; % bottom boundary for delta to search
    Res.CW.Par.top_boundary     =  40; % top boundary for delta to search
    Res.CW.Par.Sol_Re_Sign      = '-';
    Res.CW.Par.Stability        = false;
    Res.CW.Par.Newton_iter      = 30;      
    Res.CW.Par.Newton_tol       = 5E-11;  
    Res.CW.Par.i_max            = 1000;
    
    Res.CW.Par.fsolveoptions     = optimoptions('fsolve','CheckGradients',...
    false,'Display','none','UseParallel',false,'SpecifyObjectiveGradient',false,...
    'Algorithm','trust-region-dogleg','FunValCheck','on',...
    'MaxIterations',1000,'StepTolerance',1E-25,'OptimalityTolerance',1E-25,'FunctionTolerance',10^(-10));

%%
    W_Finish     = 10000;
    delta_Finish = 3;
   
    W                 = [1.3E5,1.738E5];
    delta             = [20,6.852];
    
    Res = Get_to_point(Res,W,delta);
   
%%
    Res.Stat.In           = Res.CW.In;
    Res.Stat.Par          = Res.CW.Par;
    
    Res.Stat.In.N         = 2^8;
    Res.Stat.Met.Newton   = @Newton_Manual_bicgstab;%'fsolve'
    
    Res.Stat              = Res.Stat.Met.Norm(Res.Stat);
    
    Res.Stat.Sol.Psi_o    = 1E-10*ones(1,Res.Stat.Space.N);
    Res.Stat.Sol.Psi_e    = 1E-10*ones(1,Res.Stat.Space.N);
    
  %  Res.Stat.Sol.Psi_o = Res.CW.Sol.Psi_o;
   % Res.Stat.Sol.Psi_e = Res.CW.Sol.Psi_e; 
   
     Res.Stat.Sol.Psi_o(1:Res.Stat.Space.N)   = ifft([0.0201616035172094 - 0.238800049902429i,3.05207871681182e-19 + 1.79573732856171e-19i,-6.06926497607961e-19 - 4.62742307515767e-18i,-1.59234486145857e-19 + 3.41764468275900e-19i,-3.36587661197488e-19 - 9.87864562581597e-20i,-2.65524950849610e-19 - 5.46144452019341e-19i,4.20483220758962e-19 - 8.70875592251739e-20i,4.79729168099241e-20 - 5.96301701648138e-19i,-1.60537592142074e-18 + 3.68198633928891e-18i,5.43352077233490e-21 - 1.09147190015600e-18i,2.49502435485074e-19 + 8.31641205744910e-20i,-2.37483024457086e-18 + 1.59779809559350e-17i,-3.43613535899487e-20 - 1.67841610427415e-19i,-0.0279795377792360 - 0.0413390144488696i,6.15606479526012e-20 + 2.69482970873644e-20i,-9.67428582814157e-19 + 3.58910224868393e-17i,2.94874047480841e-19 - 1.67056955554799e-19i,8.73615083601242e-19 + 2.25808474314067e-19i,1.88121681810220e-20 - 2.72360362991676e-20i,1.78928450709789e-19 - 3.25634894817019e-19i,-6.11292950805499e-20 - 5.60071317922035e-20i,-5.05666600197863e-19 + 5.03171653000048e-19i,-5.05120798750842e-21 - 2.54026110033283e-20i,1.80187141676089e-20 - 1.45485815960540e-19i,5.03956207729208e-19 - 4.23056708459823e-19i,4.20543125331992e-20 - 7.48597389178954e-20i,-5.54646358432541e-05 + 0.00116481169461240i,2.64055298764180e-21 + 7.63372689730783e-21i,3.35322713630391e-19 - 3.50338977416804e-19i,1.26286122035903e-19 - 2.48694906426957e-19i,-9.34663406201370e-21 - 2.65058151659960e-20i,2.38853213289719e-22 + 4.87633608300497e-21i,-7.77927219439386e-22 + 3.51247113625041e-21i,1.68866796119893e-20 + 1.34964071486905e-20i,1.52446339396559e-20 - 7.78829007010522e-21i,-2.52628332064341e-21 - 5.93397976710079e-21i,-1.16297110372904e-21 + 4.04213271403057e-21i,-3.23463793625899e-20 + 4.60510941177708e-21i,-7.76630726884255e-21 + 1.37545496588173e-20i,5.74701629714486e-06 + 4.76440185578445e-06i,3.95095046485534e-22 - 1.41783999403171e-21i,8.68022834687211e-21 - 1.72962832447105e-20i,-1.76464509952788e-20 - 1.21464207597809e-20i,3.50764533147859e-21 + 4.35791961126497e-23i,-3.11004705531891e-23 - 4.36293150574970e-22i,-8.76487237152931e-21 + 5.35815552748363e-20i,-3.36234196607748e-21 - 2.73757751499911e-21i,-7.47580473938962e-22 + 3.84511323408290e-22i,-6.07377331684527e-21 - 4.50522706840835e-21i,4.00602170991210e-21 + 3.39340087829004e-21i,9.23177198233513e-22 + 1.58247083377221e-21i,7.59427868787727e-21 - 4.56741102558626e-21i,-2.20545893101433e-08 - 8.32352057193207e-08i,-2.50344415024885e-21 - 1.64375155081148e-20i,-2.68590186227953e-21 - 6.02377305823059e-21i,-3.29716450807018e-21 - 1.76401018687696e-21i,2.07362603394501e-21 + 7.99372546695345e-21i,3.18472871769395e-21 - 3.53411598576657e-21i,5.58018181904052e-21 - 9.74412128188570e-22i,-1.63483999230818e-21 + 9.30451315724881e-22i,5.81343342260152e-22 + 1.73195086077032e-21i,-3.45107770076130e-21 - 9.23054238785777e-21i,-2.80159038927927e-21 + 5.72677622533241e-22i,1.01349323639386e-21 - 3.13751984717825e-21i,2.56398860283496e-22 + 3.57660079843167e-21i,1.07279336109001e-10 + 4.94065968507807e-10i,-2.91332605913686e-21 - 5.39446400456381e-23i,-2.50878657968320e-22 + 4.08796790772794e-21i,4.98528231048948e-21 + 3.95452565689140e-21i,4.69445061869770e-21 - 1.81915739287458e-20i,-2.84684504495255e-21 - 1.54431578646189e-21i,-5.28524412224504e-21 - 2.09333172552580e-21i,-1.28944105088120e-20 - 8.59766549957756e-22i,1.70921015723939e-21 - 1.41333853689530e-21i,5.33626878379509e-21 + 2.16163161532972e-22i,5.39404955461580e-21 + 3.06959126023058e-21i,-1.31872020171349e-21 + 2.48453831307890e-21i,2.43624506112272e-20 + 2.52506102908662e-21i,-6.06265440149780e-13 - 5.98158109962451e-12i,-3.71034433271124e-21 + 4.59060935467910e-22i,1.88293100440630e-21 - 5.69795910518464e-22i,3.81146785615353e-21 - 1.56625982037816e-21i,2.51184832859818e-21 + 1.12396527835379e-21i,3.47432145866434e-22 - 5.71737635236693e-21i,3.96610861704946e-22 - 3.90076984406420e-22i,-1.04344266512447e-20 + 1.02276784896467e-21i,1.01963089724410e-21 + 2.83682782827733e-21i,4.49509606877951e-21 - 2.58230955719392e-22i,-2.40860102100100e-20 + 4.94062024279828e-21i,-4.80802904541506e-21 + 5.99602033571382e-22i,-6.12600658053667e-21 - 4.73298197734052e-21i,-4.46502678186203e-14 + 4.60486259343242e-14i,4.07745830407705e-21 - 2.57782748793490e-21i,-1.92619542980843e-20 + 1.33427235425719e-20i,-1.73816103045057e-22 - 1.02021059548233e-21i,1.46409861303944e-21 + 2.55260267174035e-21i,-7.55421537377610e-21 + 1.03231773428473e-20i,4.30750742478317e-21 + 2.90752339996071e-22i,-6.74926806398471e-22 + 1.36121611740431e-21i,2.04452360451706e-21 + 5.49542118328218e-21i,1.20835158738534e-21 - 1.00050024461049e-21i,-2.25876654662071e-21 - 3.18545930272815e-21i,3.73756136048929e-22 - 4.32535689410783e-22i,-1.33656707290448e-21 + 4.62454850054202e-21i,3.74691641536390e-16 + 1.64485861002676e-16i,-1.31377892891674e-21 - 1.06278553681315e-21i,2.89227418065655e-21 - 1.91412151003307e-21i,-2.69119898963813e-21 - 3.62356154842673e-21i,-2.18207688428572e-21 + 3.04586477639984e-21i,1.32236375116052e-21 - 2.35164695815908e-20i,3.66280877017842e-21 - 4.07290030873830e-22i,4.70782923953950e-21 - 1.36689929894955e-21i,-3.18290548500512e-21 - 2.92665952203217e-21i,4.78812650799249e-22 - 3.08229283017975e-21i,-2.72535137004071e-21 - 6.64984062767997e-22i,1.59981801861229e-21 + 1.40032264106790e-21i,9.05494385612241e-22 - 2.09905343785453e-21i,-8.81751160248765e-19 - 2.60798716795944e-18i,2.54250480017398e-21 + 1.43565277334907e-21i,4.26027761130456e-21 - 1.36864352866112e-21i,-1.12370473817907e-20 - 1.34839059404238e-21i,1.58076790806549e-21 + 3.66524425627331e-21i,6.82769559617198e-21 - 1.56448331474185e-21i,1.57797487784497e-21 - 8.80241594776450e-22i,2.36017807775505e-21 + 9.16923772449799e-22i,1.51061524377390e-21 - 1.79460842320237e-20i,9.46444724372776e-22 + 3.78462715680066e-20i,-3.62712096344042e-22 - 7.48623281675061e-22i,-1.73802864443260e-20 - 3.40835650388802e-21i,-7.64357164977971e-22 + 9.99831819749974e-21i,3.00394891868348e-21 + 2.62378682651126e-20i,-8.70639652955810e-21 - 3.13981176860323e-21i,1.61136725817531e-21 + 9.85056608082800e-22i,-4.15068295586259e-20 + 2.60222440886137e-20i,6.74875483808704e-22 + 9.75095665784670e-22i,-3.03474806758175e-22 + 1.62908634771311e-21i,-4.42516250044923e-21 - 3.63703725412388e-21i,5.07673213521269e-21 + 2.08870142045116e-21i,6.82341164670226e-21 + 1.69233801904229e-21i,1.74280112174509e-18 - 2.39450120248013e-18i,2.38219571313603e-21 - 5.10432200820948e-21i,-1.33626961214206e-20 + 1.13351521769242e-20i,-4.52204236604925e-22 - 4.76224613459028e-22i,5.12510328976922e-23 + 2.20019187439455e-21i,1.83778868345501e-21 + 5.97992880595110e-21i,9.78229615170530e-22 + 1.98234931129960e-21i,-1.68622711163737e-21 - 9.21288260863597e-22i,1.66355694305865e-21 + 8.57236254502414e-21i,-6.83477970894440e-22 + 3.39529634906436e-21i,7.69934005797631e-22 + 7.90535414415139e-21i,-8.85840213123062e-22 + 2.15760007585738e-21i,-6.31124709768555e-21 + 1.11323609148052e-22i,-1.45338907277351e-16 + 6.62218943276129e-17i,-1.87569212179823e-21 - 3.13325124110004e-22i,-3.07044063177334e-21 - 4.08570813983538e-21i,2.99712130737368e-21 + 6.01767121247655e-21i,3.94141961516643e-21 + 3.59822846890160e-22i,-1.48027460540526e-20 - 1.99280796125563e-20i,-7.00653925770447e-22 + 2.30021348674353e-21i,-2.35133794669943e-21 - 9.58677054302653e-22i,4.39169095354485e-21 - 2.13104911431553e-21i,-1.84109769168984e-21 - 1.90964969758661e-22i,6.21145375421384e-21 + 3.81527818242892e-21i,3.83372142059165e-21 + 5.32904482776954e-21i,2.96922460647820e-21 + 4.84169435681948e-23i,2.71261291985720e-14 - 1.63117235751994e-15i,-2.27118296496475e-22 + 7.50967931924401e-22i,4.17500511048459e-21 - 1.17382272574693e-22i,1.95150811569555e-20 + 2.25373963479299e-21i,7.68658263667722e-21 + 7.31337502157902e-22i,-3.31664596043693e-24 + 8.36276369403211e-21i,-2.10169485835368e-21 + 3.04920360103079e-21i,9.96069705908130e-22 + 4.60802422937203e-21i,1.04417017311265e-20 - 1.53563945859757e-20i,1.54187441342799e-21 + 1.87091403730974e-21i,-3.34295652775071e-21 - 2.05066676297679e-24i,2.36349318093862e-21 - 5.46456688427491e-21i,-6.19671071878308e-21 + 1.06529926935674e-21i,-4.28445353530180e-12 - 2.74713169489309e-12i,9.29522218219764e-21 + 1.71057085882429e-21i,-2.76785425523578e-21 - 5.02000264949368e-21i,6.17199042949609e-20 - 1.20571377039085e-20i,-5.27584495412205e-22 - 2.53589215086547e-21i,2.20129235219806e-21 - 4.91207967960333e-21i,-1.70022895589708e-20 - 3.28096899415514e-22i,5.22282766638424e-22 + 2.06203884940220e-21i,4.28198372013321e-21 - 3.44544418864684e-21i,4.26216382934166e-22 + 1.38411405629663e-21i,-3.47171694319310e-22 + 1.32166740780613e-21i,-1.87828230249203e-21 - 9.73630995855197e-21i,-2.36037225178012e-21 + 5.40841247530869e-22i,7.53264637135524e-11 + 3.44876097266298e-10i,8.54359850241195e-21 + 9.99277134334153e-21i,2.22352475783860e-21 + 4.51003096114045e-21i,-3.34253694438872e-21 - 3.62513808435400e-21i,-3.67793833731759e-22 + 8.05768500353201e-21i,5.26572526617606e-21 - 2.70831745282007e-21i,7.48517151347988e-21 - 1.46156226079285e-20i,-4.10449933984280e-22 - 2.30269352577941e-21i,-1.98552406005829e-21 - 1.86112534375224e-21i,-1.60297287029039e-20 + 1.17463900607341e-20i,5.80897458815997e-21 + 1.50678552787280e-21i,-6.16852981548897e-21 + 1.89731918674251e-21i,2.32168347561255e-20 - 1.45516421117528e-20i,-4.70195006927451e-08 - 5.06063669846879e-08i,1.14558821501033e-20 + 2.34100027592515e-20i,-2.26023840148460e-21 + 2.98113316394246e-21i,7.45954153955957e-21 - 4.42734548445996e-21i,3.62042957530731e-21 + 1.29507101514949e-20i,-5.25922394076674e-21 - 2.05728207905472e-21i,8.17105524253382e-22 + 1.75546841501995e-21i,1.69524269106001e-20 - 2.20267444072136e-21i,2.65184543451468e-21 - 5.54864116593970e-22i,2.20294220098846e-21 - 1.21920473403090e-20i,3.68995273569491e-21 - 6.35935411746524e-21i,-9.59272950212236e-21 + 4.66131767236018e-21i,7.14965043674351e-21 + 1.47397397241956e-20i,2.83027105113085e-06 + 6.72849001464627e-06i,2.97521750806623e-22 - 3.72680773578364e-20i,-7.49539565636949e-21 - 4.36617885344713e-21i,1.19896405277550e-21 + 3.37421928240342e-21i,3.01342960305552e-20 + 2.99776848365748e-20i,3.63097427133032e-21 - 5.58806092616900e-22i,-2.33554453662385e-21 + 5.33844971793324e-21i,5.44894663554277e-21 - 7.19408594561980e-21i,-1.13745108730151e-20 + 1.11694447247825e-21i,-2.86103805860653e-21 + 1.43359412515207e-21i,-1.37834381614196e-22 - 8.41213334807556e-22i,6.00586570643908e-20 + 8.98176825543516e-20i,2.07045081042481e-20 - 3.37699406177006e-20i,0.000105485035576332 - 0.000206211875006682i,-1.38233480115752e-20 + 7.34352340928299e-21i,1.22058781342375e-19 + 9.23812356983866e-20i,-6.54676843510546e-21 + 3.53125656491164e-20i,1.98390651287849e-20 + 2.58830592703001e-20i,6.62624851507634e-20 - 9.57526448103711e-20i,-1.54049278193258e-20 + 1.06895428930805e-20i,1.94817166439929e-20 + 4.64008598366033e-19i,-6.48483685570218e-20 + 6.23887410685878e-20i,1.73416668231770e-19 + 1.95675105712542e-19i,-2.77941291182582e-19 - 2.85805114867298e-19i,-5.50730870865375e-19 - 2.55833323159707e-18i,-1.85062673021041e-19 - 1.08801031482310e-19i,0.0239108343246830 + 0.0444922998907871i,-2.41590411307526e-19 + 2.12975748481941e-20i,7.31332989602150e-19 + 4.51628324235779e-19i,-3.40140732027513e-20 - 7.26000065225335e-20i,-3.80157119844011e-19 - 1.49081519985389e-19i,-1.22792875993083e-18 + 2.37391571829138e-18i,3.36280959909893e-19 - 4.46199523726894e-19i,-3.61729672296147e-18 - 1.10676812895461e-18i,-2.26560741136934e-19 - 9.22982715515656e-20i,7.34567423760628e-20 - 1.22093697218161e-19i,7.60578712322072e-19 + 1.61382804040995e-18i,1.76227525134307e-17 - 2.65601939260971e-17i,-5.08239878817805e-20 + 1.27563980974242e-19i])*256;%
     Res.Stat.Sol.Psi_e(1:Res.Stat.Space.N)   = ifft([-0.00162569349076908 - 0.000423911667446987i,2.55925612764348e-20 - 2.95225961971369e-20i,-2.43483148048353e-19 - 7.36400973605062e-21i,-1.45777623280639e-20 - 1.37415442196956e-20i,-2.17082603201514e-20 - 2.01499448216283e-20i,2.36139693977892e-20 + 3.58226840798086e-20i,-1.04093031794626e-19 + 6.62754690076667e-20i,-4.38622631307441e-21 + 6.62798806969818e-20i,2.27286152811698e-18 + 2.39977619546614e-18i,1.31783289462828e-19 + 3.65060683724228e-20i,-2.69431947772446e-20 + 5.52278891231042e-20i,-1.24542364868809e-18 - 5.46611844067697e-19i,5.37362948088691e-20 + 1.29295159547294e-19i,0.00209025718265576 - 0.00117961920796770i,8.73050766231502e-20 - 6.91967551398020e-21i,-9.93530712085080e-19 - 9.74974660479283e-20i,6.00115134825925e-20 + 7.90204005425952e-21i,-3.31969525373322e-20 + 1.54681866579551e-19i,3.02610452786269e-20 + 1.18668042944069e-19i,-1.39644159558903e-19 + 4.25767657031935e-20i,1.72979147869856e-19 + 3.10216627974205e-20i,-8.04524227675968e-20 + 1.06395998676380e-19i,7.55142477862322e-21 + 3.43823604869104e-20i,2.27927126533026e-20 + 7.02533476187370e-20i,-1.66022992221007e-19 + 3.51212515979562e-19i,5.50694238442126e-20 - 4.54618033182648e-20i,6.92506589909143e-06 - 4.46074739499602e-05i,1.24334516528395e-19 - 3.64585722255678e-21i,-1.99991156343395e-19 + 9.49557963651929e-20i,4.10925960369532e-20 - 4.91713054509374e-20i,3.74729178195255e-20 - 5.76566333467311e-20i,2.19745377299631e-20 - 5.74042964261264e-20i,-1.36680648768714e-19 - 1.35776040080676e-19i,-1.92511696639097e-20 + 2.02646384098335e-20i,-9.45321408860315e-20 - 1.58349938468938e-20i,8.41223084876842e-20 + 4.40757133405335e-21i,-7.42229191969062e-21 - 1.26039601172575e-19i,-8.06098710756321e-21 - 6.21579162437655e-20i,-1.20709240139702e-20 + 8.24007611019240e-20i,-1.04879200280370e-06 + 6.50374823075638e-07i,-1.97982199610029e-19 + 8.80006994623635e-20i,-8.03302824009217e-20 + 4.13782800130215e-20i,6.73168665950821e-20 - 5.97359298178437e-20i,2.48436625320098e-21 + 1.91002751815253e-20i,-1.26739543164127e-19 - 6.69510112749091e-20i,-9.07397913339721e-20 + 3.58048518487039e-20i,-5.32860665629645e-20 - 4.95981223074553e-20i,-9.03126893129853e-20 - 5.45933536968645e-21i,7.96935725854308e-20 - 2.63942297694034e-20i,-1.71126266337154e-19 + 2.34951323757670e-21i,2.66505993450788e-20 - 6.50527254390724e-20i,-4.08305259800235e-20 - 2.52693148936224e-20i,9.38378622594288e-09 + 6.12723244549524e-09i,1.25951608553936e-19 + 1.37304240649149e-19i,1.60366448879076e-20 - 1.82006956747917e-20i,2.21352951147213e-21 - 5.17736748804806e-20i,-4.88235084509951e-21 - 5.14615828580229e-20i,6.40910400303857e-21 + 3.20668691349375e-20i,-6.37313679116762e-20 + 2.04315533519602e-20i,-3.55012142058779e-20 + 1.32679170741731e-19i,1.01863874895875e-19 - 3.97482031974708e-20i,2.33671695455887e-19 + 2.30412874585460e-20i,-6.47379166050068e-20 - 1.08968030869267e-19i,4.46301203976082e-20 + 3.44958783175137e-20i,3.34625473428463e-19 - 1.88125253632590e-19i,9.27454736491048e-11 - 1.04501508483972e-10i,5.05277860311239e-20 - 1.04304319661577e-19i,1.76039934442654e-19 + 5.14877628913389e-20i,-1.59886452912063e-20 - 3.81815851880196e-20i,-9.96568324330289e-20 + 1.36011008080158e-19i,6.31256942816471e-20 - 7.89996490240269e-20i,-2.15686031816820e-20 + 7.03597286315138e-20i,-1.30646860760383e-19 + 2.84113217745821e-20i,2.22700158402858e-20 + 9.16691762108235e-20i,6.47913061301147e-20 - 6.89587148462115e-22i,-5.22439322358055e-20 - 1.27219351630949e-19i,-6.14827646786922e-20 + 1.13471389473043e-20i,7.84858295491119e-20 + 7.76125236307825e-20i,-1.04281413547098e-12 + 1.04371908691687e-13i,5.50687981068768e-21 - 2.16241831581119e-20i,2.58433349689578e-19 + 4.29641864766426e-20i,1.34656932682005e-20 + 5.13727512445166e-20i,-7.03849679565246e-20 - 2.91948282130898e-21i,7.31835139030686e-20 + 1.56939147959398e-19i,2.08635175072424e-20 - 3.72710313063254e-20i,-2.73287660794102e-20 - 8.45949183584552e-23i,6.11122253815381e-20 + 1.97567516168518e-20i,-6.93248394778254e-20 - 4.08206022349164e-20i,7.30960494194586e-20 + 8.89901893717884e-20i,-5.41829480272857e-20 + 2.39031442333775e-20i,7.29407990408996e-20 - 5.13321463909193e-20i,3.89603888491798e-15 + 2.06465258184829e-15i,-9.91185264250266e-20 - 2.32752014451777e-20i,-3.82897362411649e-20 - 1.61148281325884e-21i,2.85514402797777e-20 + 3.38272217796926e-20i,8.48229233255050e-20 - 2.43946210651585e-20i,6.43020350682491e-21 + 3.59643199950058e-20i,7.04438423637597e-20 + 1.48660137926127e-20i,-3.79819949794683e-20 - 2.96018843100968e-20i,-1.02992027508933e-19 - 7.62970536339928e-21i,8.75811796057093e-20 - 1.37130799842340e-19i,-7.69087294994161e-20 + 5.67008818232604e-20i,-1.27384024610248e-20 + 7.66835995375201e-20i,2.98420563639664e-21 + 5.33173361532826e-20i,-3.28578010785772e-17 - 3.31943374977708e-17i,5.61575502420248e-20 + 4.96693165962125e-20i,3.70925272647491e-20 + 3.85293724609255e-20i,1.18989653112423e-19 + 5.44714027054329e-20i,5.92322217431347e-20 + 1.14086782253647e-19i,5.38893579885696e-20 + 6.75143070887575e-21i,-3.45516650848297e-20 - 1.29361268846715e-20i,8.99444543145426e-21 + 1.96248138235688e-20i,1.89246335209859e-19 + 6.75672027304851e-20i,-7.03271379612093e-20 + 5.12969074030598e-20i,4.05268734584375e-21 - 1.66229924237873e-19i,-2.50186484442677e-19 + 1.10323830208985e-19i,5.40624684634823e-21 - 1.29761103211659e-19i,-7.98446107345854e-20 + 7.27442352759278e-19i,-1.68806588931179e-20 + 8.37615023036900e-21i,-2.19311160990970e-21 + 5.19154897843232e-20i,6.06945990640518e-20 + 4.00986747879454e-20i,8.57735827254343e-20 - 4.63084215341684e-20i,-4.42020084192818e-20 + 8.55484332624631e-20i,7.49094934516877e-20 - 6.84698101006159e-20i,-5.91520695686082e-20 - 1.09982589095572e-20i,7.10834074199499e-20 - 1.47215257060488e-19i,-1.03598884061393e-20 - 6.02699037489159e-20i,-6.80738960757171e-20 + 3.43528908704246e-20i,-1.86404572288276e-19 - 2.49049310534776e-19i,-2.77348870956206e-20 + 7.48390845670457e-20i,3.60073340441633e-21 - 3.17901189788245e-21i,4.62674718767554e-20 + 2.29124697207587e-21i,1.02174597920388e-19 - 3.45219780008808e-20i,1.88037414825895e-20 - 9.43581416836599e-20i,-6.77332709869675e-20 + 3.45921907714593e-20i,1.84900777157734e-20 + 1.09113350960099e-20i,-5.32775418909345e-21 + 9.47079003756241e-21i,-1.55345447683747e-20 + 3.71928159454473e-20i,5.81549254209953e-20 + 1.62048706398791e-20i,3.97173133592249e-20 - 3.62585982343040e-19i,1.45223645536179e-20 - 1.07716030949894e-19i,2.05958199285722e-20 - 1.09125652857252e-20i,-3.90022121737697e-20 + 5.89686149549382e-21i,5.16706415595164e-22 - 9.44238967764574e-20i,2.22318762653436e-19 + 3.22832279533873e-20i,-4.32862102993502e-20 - 6.64006724126390e-21i,-1.05215097527081e-20 - 1.21549406246341e-20i,-6.99349991337099e-20 + 1.39052397925456e-19i,-6.52285807120791e-20 - 6.77381238451070e-20i,-4.94066050385241e-20 - 8.34834292270619e-21i,7.26091314798153e-21 + 4.53942888252531e-20i,3.09704744673023e-20 + 4.02931023664557e-20i,-1.35443051974568e-17 + 3.00694773860880e-17i,-8.60710798402947e-21 + 1.41171315264719e-20i,-1.29379354529678e-19 + 3.86585303353516e-20i,9.47136541083293e-20 - 5.90899333372346e-20i,-3.69028370995821e-20 + 1.11683012170356e-20i,1.63373755943314e-19 + 1.01109129351865e-19i,-7.51935275987046e-20 - 1.65717933130938e-19i,-4.64572881026749e-20 + 7.06005864678570e-20i,9.53207589619369e-20 - 3.19438131321343e-20i,9.74969051805899e-20 - 4.64551908666869e-20i,-2.59413164501499e-20 + 1.02625437803569e-19i,1.02498659089500e-19 - 5.79696284216449e-20i,-7.25881053284856e-20 - 3.16609876500186e-20i,1.83447894897593e-15 - 4.19837241199333e-15i,-4.88916242115896e-20 + 2.30964755342177e-20i,9.31302452365070e-21 - 1.36701966068426e-20i,-1.59292183910541e-19 - 4.90930269617821e-20i,6.63485304257652e-20 + 5.86684956391022e-20i,-3.35570275641130e-21 + 5.33903940613160e-20i,-3.08497516886664e-20 + 7.81793661532013e-21i,2.44390123817907e-20 - 4.70826299961275e-20i,-7.75275404643349e-20 + 1.07977575373135e-19i,5.86910352278665e-20 - 1.06776339447058e-19i,-6.95358009075744e-20 - 1.40958258410349e-20i,-1.53520769064924e-19 + 3.06221880635083e-20i,-9.81603867924854e-20 - 3.68437193284912e-20i,-3.31488902115796e-13 + 2.46712703017710e-13i,6.31483063933409e-21 - 4.17569626759562e-20i,-2.00859306126858e-20 + 2.71115690712205e-20i,-1.25158184870457e-19 - 2.31174100533554e-20i,4.53896897036794e-20 - 1.80898153053431e-20i,-5.44747679271810e-20 - 1.05275997164514e-21i,1.61170630511793e-20 - 2.43982779579627e-19i,2.35380384199222e-20 + 2.04593792267309e-21i,6.65999788444620e-20 + 2.77299876508602e-20i,-1.00588243732523e-19 - 4.52765081447069e-20i,4.43107811603379e-20 - 9.28114497764597e-20i,1.37910167867125e-20 + 1.95864456782098e-20i,-3.91387902727770e-20 + 3.69638344828242e-20i,2.32984201583632e-11 - 2.56178555581130e-11i,-2.58314421851452e-20 - 1.63354142017755e-19i,-2.00599671275791e-20 - 4.16061443481377e-20i,3.57828496368425e-20 + 6.07195036075248e-20i,-1.10962134187973e-20 - 2.01533291257728e-20i,-1.83499551547893e-20 + 1.40040135100418e-19i,2.02799020493694e-20 + 1.42752731679162e-19i,-9.74255014872651e-21 + 9.32748473131699e-21i,-6.18128098595686e-20 - 6.56597864741952e-20i,5.70865338739764e-20 + 1.16714426390338e-19i,3.56699382821999e-21 - 4.18494666801476e-20i,5.53120644143457e-20 - 6.26107201785311e-20i,-6.51707364453276e-20 + 5.35756493659122e-22i,-2.53019724191221e-09 + 2.67353797590860e-09i,5.01084270645048e-20 + 3.60095974912983e-20i,-6.17365092022609e-20 + 3.65903098700999e-20i,-6.83555248342876e-20 + 2.90708244327980e-20i,1.58652566080561e-19 + 1.04327738878041e-19i,-1.53850061239209e-21 - 4.71111136360514e-20i,1.83722437082875e-20 + 3.66834155017293e-20i,3.89450371744389e-20 + 2.65953929833031e-21i,3.30198695126935e-20 - 7.29043933131309e-20i,4.09545341431041e-20 - 6.90568029223973e-21i,-2.10577360333929e-21 - 4.96358019969498e-20i,2.10650981227354e-21 + 7.64380208828566e-20i,-4.88247330050901e-20 + 1.08369920802161e-19i,1.64025160845991e-07 - 9.47203735839715e-09i,3.49116486258918e-20 + 3.18663493115955e-20i,-5.77311899139936e-20 + 9.58166758406313e-21i,4.51620641884855e-20 - 9.30154824120677e-21i,8.47199814564313e-20 - 1.12277753366354e-19i,-3.50226370628372e-20 - 7.71761460801911e-20i,-1.46083700269959e-21 + 7.62357963260373e-21i,-2.22015669789829e-20 - 4.65018473148371e-20i,-8.09175583158171e-21 - 5.26703991146098e-20i,1.47915974134248e-19 + 1.00470485918470e-19i,-7.90829288258892e-20 - 6.47168309738405e-21i,-5.22869210599528e-21 - 1.25040032665355e-19i,2.75728125469488e-20 + 9.62309332654963e-21i,-1.25360514281478e-05 + 1.72571852662674e-05i,6.88826863682008e-20 - 1.14209244101012e-19i,-8.51548842754466e-20 - 1.98938861037298e-19i,9.38730961330942e-21 - 2.93377321754779e-21i,1.21605567940394e-19 - 8.61358883147441e-20i,6.58165432093229e-20 + 1.00160956693924e-19i,3.64011715777562e-20 + 1.22612213412444e-19i,9.13877673437760e-20 - 6.67725480820355e-20i,-2.74603918743914e-20 + 5.41198842765534e-20i,-1.25521928024426e-19 + 3.52754792543515e-20i,1.20853397083919e-19 - 1.20354668861523e-19i,5.22699515439559e-20 + 3.00193427928549e-20i,1.69293924770326e-20 + 2.01137720136272e-20i,0.000289514840965645 - 0.000125397966855681i,1.22072611919369e-19 - 3.63368259605470e-20i,1.15492668427112e-19 - 4.79868554856624e-20i,-1.27551241269996e-20 + 3.59231888641155e-20i,-1.01937342861523e-19 - 3.40470950013722e-20i,7.29490485897147e-20 - 3.36934499161004e-20i,-4.58770067996856e-20 + 2.47005958916823e-20i,1.30707487842345e-20 + 3.01251881241791e-20i,-9.63518551699581e-20 + 4.58640068157281e-20i,-5.00347888053731e-20 + 2.16358449620372e-20i,4.44976166955686e-20 - 1.70194280020566e-19i,-3.87333543774482e-19 - 2.72865926911880e-19i,8.83052063752345e-20 + 1.69896686605416e-20i])*256;
    
    Slv_Start               = [real(Res.Stat.Sol.Psi_o),imag(Res.Stat.Sol.Psi_o)...
                    ,real(Res.Stat.Sol.Psi_e),imag(Res.Stat.Sol.Psi_e),0];
    
    [Slv,eps_f,Exitflag] = Newton_Switcher(Slv_Start,Res.Stat);
    
   Res.Stat.Sol.Psi_o   = (Slv(1:Res.Stat.Space.N) + 1i*Slv(Res.Stat.Space.N+1:2*Res.Stat.Space.N));
   Res.Stat.Sol.Psi_e   = (Slv(2*Res.Stat.Space.N+1:3*Res.Stat.Space.N) + 1i*Slv(3*Res.Stat.Space.N+1:4*Res.Stat.Space.N));
   Res.Stat.Sol.V       =  Slv(end);
    
    Res.Stat.Stab         = Stability_Switcher(Res.Stat);
    Res.CW.Met.MI_Matrix   = @Chi23_MI_Matrix;
    Res.CW.Stab            = Chi23_MI(Res.CW);

    PoPert               = (Res.Stat.Stab.E_vectors(1:Res.Stat.Space.N,1)).';% + 1i*abs(Res.Stat.Stab.E_vectors(Res.Stat.Space.N+1:Res.Stat.Space.N*2,1)).';
    PePert               = (Res.Stat.Stab.E_vectors(2*Res.Stat.Space.N+1:Res.Stat.Space.N*3,1)).';%+ 1i*abs(Res.Stat.Stab.E_vectors(3*Res.Stat.Space.N+1:Res.Stat.Space.N*4,1)).';
%%    
   PoPert               = Res.Stat.Sol.Psi_o*Res.Stat.Space.N;
   PePert               = Res.Stat.Sol.Psi_e*Res.Stat.Space.N;
   PoPert([1,256-12])   = (1+1i);
   PePert([1,256-12])            = (1+1i);
   Slv_Start              = [real(PoPert),imag(PoPert),real(PePert),imag(PePert),0.15];
   [Slv,eps_f,Exitflag]   = Newton_Switcher(Slv_Start,Res.Stat);
    

%%    
function Res = Get_to_point(Res,W,delta)    
    
    NN = 1000;
    delta_vector          = linspace(delta(1),delta(2),NN);
    W_vector              = linspace(W(1),W(2),NN);
    
    Res.CW.In.W           = W(1)*Res.CW.In.W_Star;        
    Res.CW.In.delta       = delta(1)*Res.CW.In.ko;        
    
    Res.CW                = Res.CW.Met.Solve_Chi2(Res.CW ); 

    [~,ind]               = min(abs(Res.CW.Sol.Omega));

    Res.CW.Sol.Omega      =  Res.CW.Sol.Omega(ind);    
    Res.CW.Sol.Psi_o      =  Res.CW.Sol.Psi_o(ind);    
    Res.CW.Sol.Psi_e      =  Res.CW.Sol.Psi_e(ind);

        for i_d = 1:NN

            Res.CW.In.delta_o    = delta_vector(i_d)*Res.CW.In.ko;            
            Res.CW.In.W         = W_vector(i_d)*Res.CW.In.W_Star;            
            Res.CW               = Res.CW.Met.Norm(Res.CW);  
            [Slv,eps_f,Exitflag] = Newton_Switcher([real(Res.CW.Sol.Psi_o(1)),imag(Res.CW.Sol.Psi_o(1)),real(Res.CW.Sol.Psi_e(1)),imag(Res.CW.Sol.Psi_e(1))],Res.CW);
            Res.CW               = Res.CW.Met.Prop_Gen(Slv,Res.CW);          
            
            if eps_f > 1E-5
                
                break;
                
            end        
        end
        
    end
 
%%    
    

function [Mumber1,Mumber2,k1,k2] =  Evaluate_MI(Res)

    Res.CW2           = Res.CW.Met.Norm(Res.CW);  
    Res.CW23          = Res.CW2;
    
    Res.CW2.Met.MI_Matrix   = @Chi2_MI_Matrix;
    Res.CW23.Met.MI_Matrix  = @Chi23_MI_Matrix;
    
    Res.CW2           = Res.CW.Met.Solve_Chi2(Res.CW2);    
    Res.CW2.Stab      = Chi23_MI(Res.CW2);    
    Res.CW23.Stab     = Chi23_MI(Res.CW23);
    
    [~,ind]           = min(abs(Res.CW2.Sol.Omega));
    
    Mumber1           = sum(sum(real(Res.CW2.Stab(ind).Value)>1E-6));
    Mumber2           = sum(sum(real(Res.CW23.Stab(1).Value)>1E-6));
    
    [m_ind1,ind1_t]   = max(real(Res.CW2.Stab(ind).Value),[],1);
    [~,ind1]          = max(m_ind1);
    k1                = Res.CW2.Space.k(ind1_t(ind1));
    
    [m_ind1,ind1_t]   = max(real(Res.CW23.Stab.Value),[],1);
    [~,ind1]          = max(m_ind1);
    k2                = Res.CW23.Space.k(ind1_t(ind1));
    
end

    
        
%%
function Chi23_Stat_From_CW(Res)
    
end