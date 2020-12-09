class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(); if(n==0) return ""; int start=0,maxlength=1;
        bool dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                dp[i][j]=false;
            }
        }
        for(int i=0;i<n;i++) {dp[i][i]=true;} 
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) {
                dp[i][i+1]=true; start=i; maxlength=2;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(dp[i+1][j-1]==true && s[i]==s[j]){
                    dp[i][j]=true;
                    if(k>maxlength){
                        maxlength=k; start=i;
                    }
                }
            }
        }
        return s.substr(start,maxlength);
    }
};
