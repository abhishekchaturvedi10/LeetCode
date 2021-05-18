class Solution {
public:
    
    // A path is considered valid if it has visited every non obstacle cell once
    
    int res, count;
    
    void rec(vector<vector<int>> &m, int x, int y, int n, int mm, vector<vector<int>> &vis, int cnt) {
        
        if (x < 0 || x == n || y < 0 || y == mm || m[x][y] == -1 || vis[x][y]) 
            return;
        
        if(m[x][y]==2){
            if(cnt==count)
                res++;
            return;
        }

        vis[x][y] = 1;
        
        if(m[x][y]==0)
            cnt++;

        rec(m, x + 1, y, n, mm, vis, cnt);
        rec(m, x, y - 1, n, mm, vis, cnt);
        rec(m, x, y + 1, n, mm, vis, cnt);
        rec(m, x - 1, y, n, mm, vis, cnt);

        vis[x][y] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), 0));
        
        res=0;
        
        count=0;
        
        int sx,sy;
        
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
                else if(grid[i][j]==0){
                    count++;
                }
            }
        }

        rec(grid, sx, sy, grid.size(), grid[0].size(), vis, 0);

        return res;   
    }
};