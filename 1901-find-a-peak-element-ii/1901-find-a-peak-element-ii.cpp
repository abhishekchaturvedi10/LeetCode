class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        queue<vector<int>> q;
        vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size()));

        q.push({0,0});

        while(!q.empty()) {

            int x = q.front()[0], y = q.front()[1];
            q.pop();

            if(vis[x][y]) {
                continue;
            }

            vis[x][y] = 1;

            bool isPeak = true;

            if(x>0 && mat[x-1][y] > mat[x][y]) {
                isPeak = false;
                if(!vis[x-1][y]) {
                    q.push({x-1,y});
                }
            }

            if(y>0 && mat[x][y-1] > mat[x][y]) {
                isPeak = false;
                if(!vis[x][y-1]) {
                    q.push({x,y-1});
                }
            }

            if(x<mat.size()-1 && mat[x+1][y] > mat[x][y]) {
                isPeak = false;
                if(!vis[x+1][y]) {
                    q.push({x+1,y});
                }
            }

            if(y<mat[0].size()-1 && mat[x][y+1] > mat[x][y]) {
                isPeak = false;
                if(!vis[x][y+1]) {
                    q.push({x,y+1});
                }
            }

            if(isPeak) {
                return {x,y};
            }
        }

        return {-1,-1};
    }
};