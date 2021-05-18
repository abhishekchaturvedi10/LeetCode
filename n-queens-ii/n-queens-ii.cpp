class Solution {
public:
    
    char mat[10][10];

    int res;

    bool canPlace(int row, int column, int n) {

        int r = row - 1;

        while (r > -1) {
            if (mat[r][column] == 'Q') {
                return false;
            }
            r--;
        }

        r = row - 1; int c = column - 1;

        while (r > -1 && c > -1) {
            if (mat[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }

        r = row - 1, c = column + 1;

        while (r > -1 && c < n) {
            if (mat[r][c] == 'Q') {
                return false;
            }
            r--;
            c++;
        }

        return true;
    }

    void rec(int row, int n) {

        if (row == n) {
            res++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (canPlace(row, i, n)) {
                mat[row][i] = 'Q';
                rec(row + 1, n);
                mat[row][i] = '*';
            }
        }
    }
    
    int totalNQueens(int n) {
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = '*';
            }
        }
        
        res=0;
        
        rec(0, n);
        
        return res;
    }
};