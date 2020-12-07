class Solution {
public:
    
    int g[50][50], ans=0;
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if(x>=grid.size() || y>=grid[0].size() ||  x<0 || y<0 || g[x][y]==1 || grid[x][y]==0) 
            return 0;
​
        g[x][y]=1; 
        
        return 1+dfs(grid,x+1,y)+dfs(grid,x-1,y)+dfs(grid,x,y+1)+dfs(grid,x,y-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        for(int i=0;i<50;i++) 
            for(int j=0;j<50;j++) 
                g[i][j]=0;
        
        for(int i=0;i<grid.size();i++) 
            for(int j=0;j<grid[0].size();j++) 
                    ans=max(dfs(grid,i,j), ans);
        
        return ans;
    }
};
