class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int prev=n&1;
        
        n>>=1;
        
        bool res=1;
        
        while(n){
                        
            if((n&1)==prev)
                res=0;
            
            prev=n&1;
                
            n>>=1;
        }
        
        return res;
    }
};