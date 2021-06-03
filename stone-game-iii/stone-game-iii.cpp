class Solution {
public:
    
    int dp[50005];
    
    int rec(vector<int>& s, int i){
        
        if(i>=s.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
                
        int res=INT_MIN;
        
        // Current player will take the stone(s) and twill leave the minimum for the other
        
        if(i<s.size())
            res=max(res, s[i]+min({rec(s,i+2), rec(s,i+3), rec(s,i+4)}));

        if(i+1<s.size())
            res=max(res, s[i]+s[i+1]+min({rec(s,i+3), rec(s,i+4), rec(s,i+5)}));

        if(i+2<s.size())
            res=max(res, s[i]+s[i+1]+s[i+2]+min({rec(s,i+4), rec(s,i+5), rec(s,i+6)}));

        return dp[i]=res;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        
        memset(dp,-1,sizeof(dp));
        
        int res=rec(stoneValue,0);
        
        int tot=0;
        
        for(int i:stoneValue)
            tot+=i;
        
        // cout<<res;
        
        if((tot-res)==res)
            return "Tie";
        else if((tot-res)-res<0)
            return "Alice";
        
        return "Bob";
    }
};