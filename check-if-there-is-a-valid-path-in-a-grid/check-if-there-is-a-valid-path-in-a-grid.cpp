class Solution {
public:
    
    int vis[305][305], res;
    
    void check(int x, int y, vector<vector<int>>& grid) {
        
        if(x==grid.size()-1&&y==grid[0].size()-1){
            res=1;
            return;
        }
        
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||vis[x][y])
            return;
                
        vis[x][y]=1;
        
        if(grid[x][y]==1){
            if(y+1<grid[0].size()&&(grid[x][y+1]==1||grid[x][y+1]==3||grid[x][y+1]==5))
                check(x,y+1,grid);
            
            if(y-1>=0&&(grid[x][y-1]==1||grid[x][y-1]==4||grid[x][y-1]==6))
                check(x,y-1,grid);
        }
        
        if(grid[x][y]==2){
            if(x+1<grid.size()&&(grid[x+1][y]==2||grid[x+1][y]==6||grid[x+1][y]==5)){
                check(x+1,y,grid);
            }
            
            if(x-1>=0&&(grid[x-1][y]==2||grid[x-1][y]==3||grid[x-1][y]==4)){
                check(x-1,y,grid);
            }
        }
        
        if(grid[x][y]==3){
            if(y-1>=0&&(grid[x][y-1]==1||grid[x][y-1]==4||grid[x][y-1]==6))
                check(x,y-1,grid); 
            
            if(x+1<grid.size()&&(grid[x+1][y]==2||grid[x+1][y]==5||grid[x+1][y]==6))
                check(x+1,y,grid);
        }
        
        if(grid[x][y]==4) {
            if(y+1<grid[0].size()&&(grid[x][y+1]==1||grid[x][y+1]==3||grid[x][y+1]==5))
                check(x,y+1,grid);
            
            if(x+1<grid.size()&&(grid[x+1][y]==2||grid[x+1][y]==6||grid[x+1][y]==5))
                check(x+1,y,grid);
        }
        
        if(grid[x][y]==5) {
            if(y-1>=0&&(grid[x][y-1]==1||grid[x][y-1]==4||grid[x][y-1]==6))
                check(x,y-1,grid);
            
            if(x-1>=0&&(grid[x-1][y]==2||grid[x-1][y]==3||grid[x-1][y]==4))
                check(x-1,y,grid);
        }
        
            
        if(grid[x][y]==6) {
            if(y+1<grid[0].size()&&(grid[x][y+1]==1||grid[x][y+1]==3||grid[x][y+1]==5))
                check(x,y+1,grid); 
            
            if(x-1>=0&&(grid[x-1][y]==2||grid[x-1][y]==3||grid[x-1][y]==4))
                check(x-1,y,grid);
        }
        
        vis[x][y]=0;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        
        memset(vis,0,sizeof(vis));
        
        res=0;
        
        check(0,0,grid);
        
        return res;
    }
};