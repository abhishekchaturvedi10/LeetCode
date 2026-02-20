class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int startCol = 0, endCol = mat[0].size()-1;

        while(endCol>=startCol) {

            int maxRow = 0, midCol = startCol + (endCol-startCol)/2;

            for(int r=0;r<mat.size();r++) {
                if(mat[r][midCol] >= mat[maxRow][midCol]) {
                    maxRow = r;
                }
            }

            bool moveLeft = false, moveRight = false;

            if(midCol>0 && mat[maxRow][midCol-1]>mat[maxRow][midCol]) {
                moveLeft = true;
            }

            if(midCol<mat[0].size()-1 && mat[maxRow][midCol+1]>mat[maxRow][midCol]) {
                moveRight = true;
            }

            if(!moveLeft && !moveRight) {
                return {maxRow, midCol};
            }

            if(moveLeft) {
                endCol = midCol-1;
            } else {
                startCol = midCol+1;
            }
        }

        return {-1,-1};
    }
};