class Solution {
public:
    
    int dp[55][55];
    
    int rec(vector<vector<int>>& costs, int i, int j) {
        
        if(i+j>=costs.size())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int n=costs.size()/2;
        
        if(i>=n) 
            return dp[i][j] = costs[i+j][1] + rec(costs,i,j+1);
        else if(j>=n) 
            return dp[i][j] = costs[i+j][0] + rec(costs,i+1,j);
        else 
            return dp[i][j] = min(costs[i+j][0]+rec(costs,i+1,j), costs[i+j][1]+rec(costs,i,j+1));
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        memset(dp,-1,sizeof(dp));
        
        return rec(costs,0,0);
    }
};