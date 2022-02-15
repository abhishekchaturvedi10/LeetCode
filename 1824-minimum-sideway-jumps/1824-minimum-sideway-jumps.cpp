class Solution {
public:
    
    int minSideJumps(vector<int>& obstacles) {
       
        int n=obstacles.size();
        
        int dp[n][4];
        
        memset(dp,0,sizeof(dp));
        
        dp[0][1]=1;
        dp[0][2]=0;
        dp[0][3]=1;
        
        for(int i=1;i<n;i++) {
            
            dp[i][1]=dp[i-1][1];
            
            if(obstacles[i]==1)
                dp[i][1]=INT_MAX/2;
            
            if(dp[i][1]!=INT_MAX/2) 
                dp[i][1]=min(dp[i][1],dp[i-1][2]+1), dp[i][1]=min(dp[i][1],dp[i-1][3]+1);
            
            dp[i][2]=dp[i-1][2];
            
            if(obstacles[i]==2)
                dp[i][2]=INT_MAX/2;
            
            if(dp[i][2]!=INT_MAX/2) 
                dp[i][2]=min(dp[i][2],dp[i-1][1]+1), dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
            
            dp[i][3]=dp[i-1][3];
            
            if(obstacles[i]==3)
                dp[i][3]=INT_MAX/2;
            
            if(dp[i][3]!=INT_MAX/2) 
                dp[i][3]=min(dp[i][3],dp[i-1][2]+1), dp[i][3]=min(dp[i][3],dp[i-1][1]+1);
            
            if(obstacles[i]!=1)
                dp[i][1]=min({dp[i][1],dp[i][2]+1,dp[i][3]+1});
            
            if(obstacles[i]!=2)
                dp[i][2]=min({dp[i][2],dp[i][1]+1,dp[i][3]+1});
            
            if(obstacles[i]!=3)
                dp[i][3]=min({dp[i][3],dp[i][2]+1,dp[i][1]+1});
        }
        
        return min({dp[n-1][1], dp[n-1][2], dp[n-1][3]});
    }
};