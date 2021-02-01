class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Checking row wise 
        for(int i=0;i<9;i++){
            map<char, int> seen;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                if(seen[board[i][j]])
                    return false;
                seen[board[i][j]]++;
            }
        }
        // Checking column wise
        for(int i=0;i<9;i++){
            map<char, int> seen;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')
                    continue;
                if(seen[board[j][i]])
                    return false;
                seen[board[j][i]]++;
            }
        }
        // Checking box wise
        vector<map<int, int>> seen(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')
                    continue;
                int x=(i/3)*3+j/3;
                if(seen[x][board[j][i]])
                    return false;
                seen[x][board[j][i]]++;
            }
        }
        return true;
    }
};