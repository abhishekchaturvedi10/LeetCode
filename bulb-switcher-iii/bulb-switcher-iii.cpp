class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        
        long long int x=0, t=0;
        int res=0;
        
        for(int i=1;i<=light.size();i++){
            
            x+=light[i-1];
            
            t+=i;
                        
            if(x==t)
                res++;
        }
        
        return res;
    }
};