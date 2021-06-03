class Solution {
public:
    
    #define ll long long
    
    int maxProductPath(vector<vector<int>>& g) {
        
        vector<vector<vector<ll>>> dp(g.size(), vector<vector<ll>>(g[0].size()));
        
        dp[0][0]={(ll)g[0][0],(ll)g[0][0]};
        
        for(int i=1;i<g[0].size();i++)
            dp[0][i]={min(g[0][i]*dp[0][i-1][0], g[0][i]*dp[0][i-1][1]), max(g[0][i]*dp[0][i-1][0], g[0][i]*dp[0][i-1][1])};
        
        for(int i=1;i<g.size();i++)
            dp[i][0]={min(g[i][0]*dp[i-1][0][0], g[i][0]*dp[i-1][0][1]), max(g[i][0]*dp[i-1][0][0], g[i][0]*dp[i-1][0][1])};
        
        for(int i=1;i<g.size();i++){
            for(int j=1;j<g[0].size();j++){
                dp[i][j]={min({g[i][j]*dp[i-1][j][0], g[i][j]*dp[i-1][j][1], g[i][j]*dp[i][j-1][0], g[i][j]*dp[i][j-1][1]}), max({g[i][j]*dp[i-1][j][0], g[i][j]*dp[i-1][j][1], g[i][j]*dp[i][j-1][0], g[i][j]*dp[i][j-1][1]})};
            }
        }
        
        ll res=max(dp[g.size()-1][g[0].size()-1][0],dp[g.size()-1][g[0].size()-1][1]);
        
        return res<0?-1:res%1000000007;
    }
};