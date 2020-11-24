function Stab = Stability_Switcher(Stat)

    switch func2str(Stat.Met.Stab_Method)
        
        case  'LLE_Full_Stability'
            
            Stab  =  LLE_Full_Stability(Stat);
            
        case 'LLE_Bloch_Full_Stability' 
            
            Stab  =  LLE_Bloch_Full_Stability(Stat);
            
    end
    
end

