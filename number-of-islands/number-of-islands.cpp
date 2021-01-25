class Solution {
public:
    void helper(vector<vector<char>>& grid, int x, int y){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
            return;
        if(grid[x][y]=='0')
            return;
        grid[x][y]='0';
        helper(grid, x-1, y);
        helper(grid, x+1, y);
        helper(grid, x, y-1);
        helper(grid, x, y+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    helper(grid, i, j);
                }
            }
        }
        return ans;
    }
};
