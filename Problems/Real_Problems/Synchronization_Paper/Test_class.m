classdef Test_class
    %UNTITLED9 Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        L_L
    end
    
    methods
        
        function L_L = Norm(L_L)
            
                L_L = Chi_3_LLE_Normalization(L_L);
                
        end
        
        function L_L = CW(L_L)
            
            L_L.CW.Eq = Norm(L_L);
            L_L.CW    = L_L.CW.Met.Solve(L_L.CW);
            
        end
        
        function L_L = Mi(L_L)
            
            L_L.CW.Eq = Norm(L_L);
            L_L.CW    = L_L.CW.Met.Solve(L_L.CW);
            
        end
        
    end
end

