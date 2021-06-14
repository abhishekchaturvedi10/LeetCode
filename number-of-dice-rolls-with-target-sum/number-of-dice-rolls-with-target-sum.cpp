class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        
        long long int dp[d+1][target+1];
        
        memset(dp,0,sizeof(dp));
        
        dp[0][0]=1;
        
        for(int i=1;i<=d;i++){
            for(int j=i;j<=f*i;j++){
                if(j>target)
                    break;
                for(int k=1;k<=f;k++){
                    if(j-k>=0){
                        // dp[i-1][j-k]%=1000000007;
                        dp[i][j]=dp[i][j]%1000000007+dp[i-1][j-k]%1000000007;
                        dp[i][j]%=1000000007;
                    }
                }
            }
        }
        
        return dp[d][target];
    }
};