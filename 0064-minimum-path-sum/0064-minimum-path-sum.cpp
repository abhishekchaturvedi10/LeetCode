class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0) {
            return 0;
        }
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i>0&&j>0) {
                    grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
                } else if(i<1&&j>0) {
                    grid[i][j]+=grid[i][j-1];
                } else if(j<1&&i>0) {
                    grid[i][j]+=grid[i-1][j];
                }
            }
        }
        return grid[n-1][m-1];
    }
};