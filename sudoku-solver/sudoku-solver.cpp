class Solution {
public:
    
    bool rec(vector<vector<char>> &grid, int x, int y) {
        
        if (x == 8 && y > 8)
            return true;

        if (y == 9) {
            y = 0;
            x++;
        }

        if (grid[x][y] != '.')
            return rec(grid, x, y + 1);

        vector<int> v(10, 1);

        for (int i = 0; i < 9; i++) {
            if (grid[i][y] != '.')
                v[grid[i][y]-'0'] = 0;
            if (grid[x][i] != '.')
                v[grid[x][i]-'0'] = 0;
        }

        if (x >= 0 && x <= 2) {
            if (y >= 0 && y <= 2) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (grid[i][j] != '.')
                            v[grid[i][j]-'0'] = 0;
                    }
                }
            }
            else if (y > 2 && y < 6) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 3; j < 6; j++) {
                        if (grid[i][j] != '.')
                            v[grid[i][j]-'0'] = 0;
                    }
                }
            }
            else {
                for (int i = 0; i < 3; i++) {
                    for (int j = 6; j < 9; j++) {
                        if (grid[i][j] != '.')
                            v[grid[i][j]-'0'] = 0;
                    }
                }
            }
        }
        else if (x > 2 && x < 6) {
            if (y >= 0 && y <= 2) {
                for (int i = 3; i < 6; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (grid[i][j] != '.')
                            v[grid[i][j]-'0'] = 0;
                    }
                }
            }
            else if (y > 2 && y < 6) {
                for (int i = 3; i < 6; i++) {
                    for (int j = 3; j < 6; j++) {
                        if (grid[i][j] != '.')
                            v[grid[i][j]-'0'] = 0;
                    }
                }
            }
            else {
                for (int i = 3; i < 6; i++) {
                    for (int j = 6; j < 9; j++) {
                        if (grid[i][j] != '.')
                            v[grid[i][j]-'0'] = 0;
                    }
                }
            }
        }
        else {
            if (y >= 0 && y <= 2) {
                for (int i = 6; i < 9; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (grid[i][j] != '.')
                            v[grid[i][j]-'0'] = 0;
                    }
                }
            }
            else if (y > 2 && y < 6) {
                for (int i = 6; i < 9; i++) {
                    for (int j = 3; j < 6; j++) {
                        if (grid[i][j] != '.')
                            v[grid[i][j]-'0'] = 0;
                    }
                }
            }
            else {
                for (int i = 6; i < 9; i++) {
                    for (int j = 6; j < 9; j++) {
                        if (grid[i][j] != '.')
                            v[grid[i][j]-'0'] = 0;
                    }
                }
            }
        }

        for (int i = 1; i <= 9; i++) {
            if (v[i] == 1) {
                
                grid[x][y] = i+'0';
                
                if (rec(grid, x, y + 1))
                    return true;
            }
        }

        grid[x][y] = '.';

        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        rec(board, 0, 0);
    }
};