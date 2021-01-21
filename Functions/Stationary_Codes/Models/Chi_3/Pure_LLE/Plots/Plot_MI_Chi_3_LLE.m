function Plot_MI_Chi_3_LLE(CW)

    figure; 
    plot([CW.Space.k;CW.Space.k],real(CW.Stab(3).Value).');

end