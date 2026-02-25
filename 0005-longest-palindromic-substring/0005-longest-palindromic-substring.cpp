class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        string res;

        for(int i=0;i<n;i++)
            dp[i][i]=1, res=s.substr(i,1);

        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1])
                dp[i][i+1]=1, res=s.substr(i,2);

        for(int i=2;i<n;i++){
            for(int j=0;j<n&&j+i<n;j++) {
                if(s[j]==s[j+i] && dp[j+1][j+i-1]) {
                    dp[j][j+i]=1, res=s.substr(j,i+1);
                }
            }
        }

        return res;
    }
};