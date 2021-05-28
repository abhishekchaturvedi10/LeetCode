class Solution {
public:
    
    int dp[50005][2];
    
    int rec(vector<int>& prices, int fee, int i, int isBought){
        
        if(i==prices.size())
            return 0;
        
        if(dp[i][isBought]!=-1)
            return dp[i][isBought];
        
        
        // Do nothing
        dp[i][isBought]=rec(prices, fee, i+1, isBought);
        
        if(isBought)
            dp[i][isBought]=max(dp[i][isBought], prices[i]-fee+rec(prices, fee, i+1, 0)); // Sell the stock and get profit of prices[i]-fee
        else
            dp[i][isBought]=max(dp[i][isBought], rec(prices, fee, i+1, 1)-prices[i]); // Buy the stock by paying amount of prices[i]
                
        return dp[i][isBought];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        memset(dp,-1, sizeof(dp));
        
        return rec(prices, fee, 0, 0);
    }
};