class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int x, int y) {
        
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]!=1)
            return;
        
        grid[x][y]=0;
        
        dfs(grid,x-1,y);
        dfs(grid,x+1,y);
        dfs(grid,x,y-1);
        dfs(grid,x,y+1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
            
        for(int i=0;i<grid.size();i++)
            dfs(grid,i,0), dfs(grid,i,grid[0].size()-1);
        
        for(int i=1;i<grid[0].size()-1;i++)
            dfs(grid,0,i), dfs(grid,grid.size()-1,i);
            
        int res=0;
        
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
                    res++;
        
        return res;
    }
};