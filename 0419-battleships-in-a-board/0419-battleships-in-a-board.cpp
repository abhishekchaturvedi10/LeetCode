class Solution {
public:

    void dfs(vector<vector<char>>& board, int x, int y, pair<int,int> dir) {
        if(x>=board.size()||y>=board[0].size()) {
            return;
        }
        if(board[x][y]!='X') {
            return;
        }
        board[x][y]='A';
        dfs(board,x+dir.first,y+dir.second,dir);
    }

    int countBattleships(vector<vector<char>>& board) {

        int m=board.size(), n=board[0].size(), res=0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]=='X') {
                    res++;
                    board[i][j]='A';
                    if(i<board.size()-1 && board[i+1][j]=='X') {
                        dfs(board,i+1,j,{1,0});
                    } else if (j<board[0].size()-1 && board[i][j+1]=='X') {
                        dfs(board,i,j+1,{0,1});
                    }
                }
            }
        }

        return res;
    }
};