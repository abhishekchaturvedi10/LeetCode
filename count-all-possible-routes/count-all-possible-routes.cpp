class Solution {
public:
    
    int dp[105][205];
    
    int rec(vector<int>& locations, int finish, int loc, int fuel){
        
        if(fuel<0)
            return 0;
        
        if(dp[loc][fuel]!=-1)
            return dp[loc][fuel];
        
        dp[loc][fuel]=0;
        
        if(loc==finish)
            (dp[loc][fuel]+=1)%1000000007;
        
        for(int i=0;i<locations.size();i++){
            if(i!=loc){
                dp[loc][fuel]%=1000000007;
                int x=(rec(locations, finish, i, fuel-abs(locations[i]-locations[loc]))%1000000007);
                (dp[loc][fuel]+=x)%1000000007;
            }
        }
            
        return dp[loc][fuel]%1000000007;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        memset(dp,-1,sizeof(dp));
        
        return rec(locations, finish, start, fuel);
    }
};