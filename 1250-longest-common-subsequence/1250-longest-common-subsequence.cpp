class Solution {
public:
    int rec(string& s1, int i1, string& s2, int i2, vector<vector<int>>& dp) {
        if(i1==s1.size()) {
            return 0;
        }
        if(i2==s2.size()) {
            return 0;
        }
        if(dp[i1][i2]!=-1) {
            return dp[i1][i2];
        }
        if(s1[i1]==s2[i2]) {
            return dp[i1][i2] = 1+rec(s1,i1+1,s2,i2+1,dp);
        }
        return dp[i1][i2] = max({rec(s1,i1+1,s2,i2,dp), rec(s1,i1,s2,i2+1,dp)});
    }
    int longestCommonSubsequence(string& s1, string& s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return rec(s1,0,s2,0,dp);
    }
};