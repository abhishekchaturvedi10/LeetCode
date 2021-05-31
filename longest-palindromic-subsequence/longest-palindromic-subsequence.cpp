class Solution {
public:
    
    int dp[1005][1005];
    
    int rec(int s, int e, string& str){
        
        if(s>e)
            return 0;
        
        // Must have come from two outmost of 3 characters being different (abc)
        if(s==e)
            return 1;
        
        if(dp[s][e]!=-1)
            return dp[s][e];
        
        if(str[s]==str[e])
            return dp[s][e]=2+rec(s+1,e-1,str);
        
        return dp[s][e]=max(rec(s+1,e,str), rec(s,e-1,str));
    }
    
    int longestPalindromeSubseq(string s) {
     
        memset(dp,-1,sizeof(dp));
        
        return rec(0, s.size()-1, s);
    }
};