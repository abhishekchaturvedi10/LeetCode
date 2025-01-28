class Solution {
public:
    bool check(int x, int y, int n, int m) {
        if(x<0||y<0||x>=n||y>=m) {
            return false;
        }
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) {
            return -1;
        }
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({0,0});
        int res=0;
        vector<int> x = {0,0,1,1,1,-1,-1,-1};
        vector<int> y = {1,-1,1,0,-1,-1,0,1};
        while(!q.empty()) {
            res++;
            int len=q.size();
            while(len--) {
                auto p = q.front();
                if(p.first==n-1&&p.second==m-1) {
                    return res;
                }
                q.pop();
                for(int i=0;i<8;i++) {
                    if(check(p.first+x[i],p.second+y[i],n,m)&&grid[p.first+x[i]][p.second+y[i]]==0) {
                        q.push({p.first+x[i],p.second+y[i]});
                        grid[p.first+x[i]][p.second+y[i]]=1;
                    }
                }
            }
        } 
        return -1;
    }
};