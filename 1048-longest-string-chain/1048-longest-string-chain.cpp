class Solution {
public:
    
    static bool cmp(string& s, string& t) {
        return s.size()<t.size();
    }
    
    bool func(string& s, string& t) {
        
        if(t.size()!=s.size()+1)
            return 0;
        
        int f1=0,f2=0;
        
        int i=0;
        
        while(i<s.size()) {
            if(f1) {
                if(s[i]==t[i+1]) 
                    i++;
                else {
                    f2=1;
                    break;
                }
            }
            else {
                if(s[i]==t[i])
                    i++;
                else
                    f1=1;
            }
        }
        
        return !f2;
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),cmp);
        
        int n=words.size();
        
        vector<int> dp(n,1);
        
        int res=1;
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(func(words[j],words[i])) {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        
        return res;
    }
};