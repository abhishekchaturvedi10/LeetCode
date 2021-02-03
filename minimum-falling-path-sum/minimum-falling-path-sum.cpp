class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int x=INT_MAX, y=matrix[i-1][j], z=INT_MAX;
                if(j-1>=0)
                    x=matrix[i-1][j-1];
                if(j+1<n)
                    z=matrix[i-1][j+1];
                matrix[i][j]+=min({x, y, z});
            }
        }
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());        
    }
};