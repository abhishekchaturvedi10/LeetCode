class Solution {
public:
    
    int dp[10005];
    
    int fun(int amt,vector<int>& coins){
        
        if(amt==0)
            return 0;
        
        if(dp[amt]!=-1)
            return dp[amt];
        
        dp[amt]=10005;
        
        for(int i:coins){
            
            if(i>amt)
                continue;
            
            dp[amt]=min(1+fun(amt-i,coins),dp[amt]);
        }
        
        return dp[amt];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        memset(dp,-1,sizeof(dp));
        
        int x = fun(amount, coins);
        
        if(x>10000)
            return -1;
        
        return x;
    }
};