class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m=matrix.size(), n=matrix[0].size(), row=0;

        while(row<m) {
            int l=0, r=n-1;
            while(r>=l) {
                int mid=l+(r-l)/2;
                if(matrix[row][mid]==target) {
                    return true;
                }
                if(matrix[row][mid]>target) {
                    r=mid-1;
                } else {
                    l=mid+1;
                }
            }
            row++;
        }

        return false;
    }
};