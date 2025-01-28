class Solution {
public:
    map<pair<string,int>,bool> dp;
    bool dfs(string& s, map<string,bool>& m, string cur, int i) {
        if(i==s.size()) {
            return m[cur];
        }
        if(dp.find({cur,i})!=dp.end()) {
            return dp[{cur,i}];
        }
        if(m[cur]==1) {
            return dp[{cur,i}]=dfs(s,m,string(1,s[i]),i+1)||dfs(s,m,cur+s[i],i+1);
        } else {
            return dp[{cur,i}]=dfs(s,m,cur+s[i],i+1);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool> m;
        for(string s: wordDict) {
            m[s]=true;
        }
        return dfs(s,m,"",0);
    }
};