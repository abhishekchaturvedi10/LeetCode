class Solution {
public:
    
    int dp[2005][2005];
    
    unordered_map<int, int> m;
    
    int rec(vector<int>& stones, int i, int k){
        
        if(i==stones.size()-1)
            return 1;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
                
        dp[i][k]=0;
        
        if(k-1>=0)
            if(m.find(stones[i]+k-1)!=m.end())
                dp[i][k]|=rec(stones, m[stones[i]+k-1], k-1);
            
        if(m.find(stones[i]+k)!=m.end())
                dp[i][k]|=rec(stones, m[stones[i]+k], k);
        
        if(m.find(stones[i]+k+1)!=m.end())
                dp[i][k]|=rec(stones, m[stones[i]+k+1], k+1);
                
        return dp[i][k];
    }
    
    bool canCross(vector<int>& stones) {
        
        if(stones[1]>1)
            return 0;
        
        for(int i=0;i<stones.size();i++)
            m[stones[i]]=i;
        
        memset(dp,-1,sizeof(dp));
        
        return rec(stones, 1, 1);
    }
};