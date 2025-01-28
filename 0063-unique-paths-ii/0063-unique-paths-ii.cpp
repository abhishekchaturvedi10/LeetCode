class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        if(g[0][0]==1) {
            return 0;
        }
        vector<vector<int>> dp(g.size(),vector<int>(g[0].size(),0));
        dp[0][0]=1;
        for(int i=1;i<g.size();i++) {
            if(g[i][0]==1) {
                break;
            }
            dp[i][0]=1;
        }
        for(int i=1;i<g[0].size();i++) {
            if(g[0][i]==1) {
                break;
            }
            dp[0][i]=1;
        }
        for(int i=1;i<g.size();i++) {
            for(int j=1;j<g[0].size();j++) {
                if(g[i][j]==1) {
                    continue;
                }
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1]);
            }
        }
        return dp[g.size()-1][g[0].size()-1];
    }
};