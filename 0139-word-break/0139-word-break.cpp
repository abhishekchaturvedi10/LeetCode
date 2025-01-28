class Solution {
public:
    map<pair<string,int>,bool> dp;
    bool dfs(string& s, map<string,int>& m, string cur, int i) {
        if(i==s.size()) {
            if(m[cur]==1) {
                return true;
            } else {
                return false;
            }
        }
        if(dp.find({cur,i})!=dp.end()) {
            return dp[{cur,i}];
        }
        if(m[cur]==1) {
            string s1="";
            s1+=s[i];
            cur+=s[i];
            return dp[{cur,i}]=dfs(s, m, s1,i+1) || dfs(s,m,cur,i+1);
        } else {
            cur+=s[i];
            return dp[{cur,i}]=dfs(s,m,cur,i+1);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int> m;
        for(string s: wordDict) {
            m[s]=1;
        }
        return dfs(s,m,"",0);
    }
};