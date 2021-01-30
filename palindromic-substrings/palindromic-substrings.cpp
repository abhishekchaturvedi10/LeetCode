class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        int ans=n;
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1])
                dp[i][i+1]=1, ans++;
        for(int i=2;i<n;i++){
            for(int j=0;j<n;j++){
                if(j+i>n)
                    break;
                if(s[j]==s[j+i]&&dp[j+1][j+i-1])
                    dp[j][j+i]=1, ans++;
            }
        }
        return ans;
    }
};