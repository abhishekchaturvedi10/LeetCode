class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        if(s.size()==1)
            return 1;
        int ans=0, n=s.size();
        vector<int> dp(n, 0);
        dp[0]=1;
        if(stoi(s.substr(0,2))>=10 && stoi(s.substr(0,2))<=26 && s[1]=='0')
            dp[1]=1;  
        if(stoi(s.substr(0,2))>=10 && stoi(s.substr(0,2))<=26 && s[1]!='0')
            dp[1]=2;
        if(stoi(s.substr(0,2))>26 && s[1]=='0')
            dp[1]=0;
        if(stoi(s.substr(0,2))>26 && s[1]!='0')
            dp[1]=1;
        //cout<<dp[1];
        for(int i=2;i<n;i++){
            if(s[i]-'0'>0)
                dp[i]+=dp[i-1];
            if(stoi(s.substr(i-1,2))>=10 && stoi(s.substr(i-1,2))<=26 && s[i-1]!='0')
                dp[i]+=dp[i-2];
        }
        return dp[n-1];
    }
};
