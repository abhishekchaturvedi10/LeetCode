class Solution {
public:
    
    int dp[505][505];
    
    int rec(vector<int>& satisfaction, int i, int time){
        
        if(i>=satisfaction.size())
            return 0;
        
        if(dp[i][time]!=-1)
            return dp[i][time];
        
        return dp[i][time]=max(rec(satisfaction, i+1, time), satisfaction[i]*(time+1)+rec(satisfaction, i+1, time+1));
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        
        memset(dp,-1,sizeof(dp));
        
        sort(satisfaction.begin(), satisfaction.end());
        
        return rec(satisfaction, 0, 0);
    }
};