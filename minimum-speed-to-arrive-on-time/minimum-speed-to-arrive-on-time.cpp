class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int l=0, r=1000000000, res=INT_MAX;
        
        while(r>=l) {
            
            int m=l+(r-l)/2;
            
            double x=0;
            
            for(int i=0;i<dist.size()-1;i++)
                x+=(dist[i]*1.0/m*1.0), x=ceil(x);
            
            x+=(dist[dist.size()-1]*1.0/m*1.0);
                        
            if(x<=hour) {
                r=m-1;
                res=m;
            }
            else
                l=m+1;
        }
        
        return res==INT_MAX?-1:res;
    }
};