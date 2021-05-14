class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int a=x^y, res=0;
        
        while(a){
            if(a&1)
                res++;
            a>>=1;
        }
        
        return res;
    }
};