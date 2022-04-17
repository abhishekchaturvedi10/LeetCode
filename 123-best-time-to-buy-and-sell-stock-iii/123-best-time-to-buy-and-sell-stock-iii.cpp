class Solution {
public:
    
    int dp[100005][5];
    
    int rec(vector<int>& prices, int i, int cur, int have){
        
        if(cur>=4||i==prices.size())
            return 0;
        
        if(dp[i][cur]!=-1)
            return dp[i][cur];
        
        dp[i][cur]=rec(prices,i+1,cur,have);
        
        if(have==1)
            dp[i][cur]=max(dp[i][cur], prices[i]+rec(prices,i+1,cur+1,0));
        else 
            if(cur==0||cur==2)
                dp[i][cur]=max(dp[i][cur], -prices[i]+rec(prices,i+1,cur+1,1));
                    
        return dp[i][cur];
    }
    
    int maxProfit(vector<int>& prices) {
        
        memset(dp,-1,sizeof(dp));
        
        return rec(prices,0,0,0);
    }
};