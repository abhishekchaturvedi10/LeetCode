class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        
        vector<int> dp(n+1,10000000000);
        dp[0]=0;

        for(int i=0;i<n;i++) {
            for(int j=1;j<=3;j++) {
                if(i+j>n) {
                    continue;
                }
                int curCost=j*j+cost[i+j-1];
                dp[i+j] = min(dp[i+j],dp[i]+curCost);
            }
        }

        return dp[n];
    }
};