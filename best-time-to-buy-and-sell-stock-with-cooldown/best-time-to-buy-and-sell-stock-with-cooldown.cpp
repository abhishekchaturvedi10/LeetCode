class Solution {
public:
    
    int dp[5005][2];
    
    int rec(vector<int>& prices, int i, int isBought){
        
        if(i>=prices.size())
            return 0;
        
        if(dp[i][isBought]!=-1)
            return dp[i][isBought];
        
        dp[i][isBought]=rec(prices, i+1, isBought);
        
        if(isBought)
            dp[i][isBought]=max(dp[i][isBought], prices[i]+rec(prices, i+2, 0));
        else
            dp[i][isBought]=max(dp[i][isBought], -prices[i]+rec(prices, i+1, 1));
        
        return dp[i][isBought];
    }
    
    int maxProfit(vector<int>& prices) {
        
        memset(dp,-1,sizeof(dp));
        
        return rec(prices, 0, 0);
    }
};