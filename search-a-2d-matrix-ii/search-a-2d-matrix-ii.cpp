class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            int ind=lower_bound(matrix[i].begin(), matrix[i].end(), target)-matrix[i].begin();
            if(ind<matrix[i].size()&&matrix[i][ind]==target)
                return true;
        }
        return false;
    }
};
