class Solution {
public:
    int dp[305][5005];
    int rec(int i,int amount, vector<int>& coins){
        if(i==-1){
            return 0;
        }
        if(amount==0){
            return 1;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        if(coins[i]>amount){
            return dp[i][amount]=rec(i-1,amount,coins);
        }
        else{
            return dp[i][amount]=rec(i-1,amount,coins)+rec(i,amount-coins[i],coins);
        }
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return rec(coins.size()-1,amount,coins);
    }
};