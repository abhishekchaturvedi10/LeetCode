class Solution {
public:
        
    long long dp[55][55][55];
    
    long long rec(int x, int y, int m, int n, int k){
        
        if(k<0)
            return 0;
                
        if(x<0||y<0||x>=m||y>=n)
            return 1;
        
        if(dp[x][y][k]!=-1)
            return dp[x][y][k];
                
        return dp[x][y][k]=(rec(x-1,y,m,n,k-1)+rec(x,y-1,m,n,k-1)+rec(x+1,y,m,n,k-1)+rec(x,y+1,m,n,k-1))%1000000007;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof(dp));
        
        return rec(startRow, startColumn, m, n, maxMove);
    }
};