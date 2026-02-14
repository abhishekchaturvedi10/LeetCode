class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1000000);
        dp[0]=0;
        for(int i=0;i<amount;i++) {
            for(int& c:coins) {
                if(c<=amount&&i+c<=amount) {
                    dp[i+c]=min(dp[i+c],dp[i]+1);
                }
            }
        }
        return dp[amount]==1000000?-1:dp[amount];
    }
};