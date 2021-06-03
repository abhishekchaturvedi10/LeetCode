class Solution {
public:
        
    long long res;
    
    int vis[20][20];
    
    void rec(int x, int y, vector<vector<int>>& g, long long p, int m, int n){
        
        if(vis[x][y])
            return;
        
        p*=g[x][y];
        
        if(x==m-1&&y==n-1){
            
            if(p>=0)
                res=max(res,p);
            
            return;
        }
        
        if(p==0){
            res=max(res,p);
            return;
        }
        
        vis[x][y]=1;
        
        if(x+1<m)
            rec(x+1,y,g,p,m,n);
        if(y+1<n)
            rec(x,y+1,g,p,m,n);
        
        vis[x][y]=0;
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        
        res=-1;
        
        memset(vis,0,sizeof(vis));
        
        rec(0,0,grid,1,grid.size(),grid[0].size());
        
        return res%1000000007;
    }
};