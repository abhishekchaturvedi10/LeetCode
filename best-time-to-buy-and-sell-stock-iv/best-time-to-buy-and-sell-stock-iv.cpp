class Solution {
public:
    
    int dp[10005][2][105];
    
    int rec(int cur, int k, vector<int>& prices, int i, int isBought){
        
        if(i>=prices.size())
            return 0;
        
        if(dp[i][isBought][cur]!=-1)
            return dp[i][isBought][cur];
        
        dp[i][isBought][cur]=rec(cur,k,prices,i+1,isBought);
        
        if(isBought)
            dp[i][isBought][cur]=max(dp[i][isBought][cur], prices[i]+rec(cur,k,prices,i+1,0));
        
        else if(!isBought&&cur<k)
           dp[i][isBought][cur]=max(dp[i][isBought][cur], -prices[i]+rec(cur+1,k,prices,i+1,1)); 
        
        return dp[i][isBought][cur];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        if(k==0||prices.empty())
            return 0;
        
        memset(dp,-1,sizeof(dp));
        
        return rec(0,k,prices,0,0);
    }
};