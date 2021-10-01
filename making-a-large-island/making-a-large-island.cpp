class Solution {
public:
    
    int g[505][505], grp, res;
    
    unordered_map<int,int> sz;
    
    void dfs(int x, int y, vector<vector<int>>& grid) {
        
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||g[x][y]!=0||grid[x][y]==0)
            return;
        
        g[x][y]=grp;
        
        sz[grp]++;
        
        dfs(x-1,y,grid);
        dfs(x+1,y,grid);
        dfs(x,y+1,grid);
        dfs(x,y-1,grid);
        
        res=max(res,sz[grp]);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        memset(g,0,sizeof(g));
        
        res=0;
        grp=2;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ++grp;
                    dfs(i,j,grid);
                }
            }
        }
        
        for(int x=0;x<grid.size();x++){
            for(int y=0;y<grid[0].size();y++){
                if(grid[x][y]==0){
                    
                    int val=0;
                    
                    map<int,int> seen;
                    
                    if(x-1>=0&&!seen[g[x-1][y]]){
                        seen[g[x-1][y]]++;
                        val+=sz[g[x-1][y]];
                    }
                    
                    if(x+1<grid.size()&&!seen[g[x+1][y]]){
                        seen[g[x+1][y]]++;
                        val+=sz[g[x+1][y]];
                    }
                    
                    if(y-1>=0&&!seen[g[x][y-1]]){
                        seen[g[x][y-1]]++;
                        val+=sz[g[x][y-1]];
                    }
                    
                    if(y+1<grid[0].size()&&!seen[g[x][y+1]]){
                        seen[g[x][y+1]]++;
                        val+=sz[g[x][y+1]];
                    }
                    
                    res=max(res,val+1);
                }
            }
        }
        
        return res;
    }
};