class Solution {
public:    
    double dp[26][26][105];
    
    double rec(int x, int y, int n, int k){
        
        if(x<0||y<0||x>=n||y>=n)
            return 0;
        
        if(k==0)
            return 1;
        
        if(dp[x][y][k]!=-1)
            return dp[x][y][k];
            
        dp[x][y][k]=0;
        
        dp[x][y][k]+=rec(x-2,y-1,n,k-1);
        
        dp[x][y][k]+=rec(x+2,y-1,n,k-1);
        
        dp[x][y][k]+=rec(x-2,y+1,n,k-1);
        
        dp[x][y][k]+=rec(x+2,y+1,n,k-1);
        
        dp[x][y][k]+=rec(x-1,y-2,n,k-1);
        
        dp[x][y][k]+=rec(x-1,y+2,n,k-1);
        
        dp[x][y][k]+=rec(x+1,y-2,n,k-1);
        
        dp[x][y][k]+=rec(x+1,y+2,n,k-1);
        
        return dp[x][y][k]/=8;        
    }
    
    double knightProbability(int n, int k, int row, int column) {
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                for(int z=0;z<=k;z++)
                    dp[i][j][z]=-1;
        
        return rec(row, column, n, k);
    }
};