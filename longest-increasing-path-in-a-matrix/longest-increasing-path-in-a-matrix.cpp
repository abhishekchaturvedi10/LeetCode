class Solution {
public:
    
    int dp[205][205];
    
    int dfs(vector<vector<int>>& m, int x, int y){
        
        if(x<0||y<0||x>=m.size()||y>=m[0].size())
            return 0;
        
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        dp[x][y]=0;
        
        if(x-1>=0&&m[x-1][y]>m[x][y])
            dp[x][y]=max(dp[x][y],1+dfs(m,x-1,y));
        
        if(y-1>=0&&m[x][y-1]>m[x][y])
            dp[x][y]=max(dp[x][y],1+dfs(m,x,y-1));
        
        if(x+1<m.size()&&m[x][y]<m[x+1][y])
            dp[x][y]=max(dp[x][y],1+dfs(m,x+1,y));
        
        if(y+1<m[0].size()&&m[x][y]<m[x][y+1])
            dp[x][y]=max(dp[x][y],1+dfs(m,x,y+1));
        
        return dp[x][y]=max(1,dp[x][y]);
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& m) {
        
        memset(dp,-1,sizeof(dp));
        
        int res=0;
        
        for(int i=0;i<m.size();i++)
            for(int j=0;j<m[0].size();j++)
                res=max(res,dp[i][j]==-1?dfs(m,i,j):dp[i][j]);
        
        return res;
    }
};