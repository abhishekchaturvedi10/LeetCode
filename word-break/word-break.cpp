class Solution {
public:
    
    int dp[305];
    
    unordered_map<string,int> dic;
    
    bool rec(int i, string &s){
        
        if(i==s.size())
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        
        for(int j=i;j<s.size();j++)
            if(dic[s.substr(i,j-i+1)]&&rec(j+1,s))
                return dp[i]=1;
        
        return dp[i]=0;
    }
    
    bool wordBreak(string &s, vector<string>& wordDict) {
        
        for(auto i:wordDict)
            dic[i]++;
        
        memset(dp,-1,sizeof(dp));
        
        return rec(0,s);
    }
};