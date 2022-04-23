class Solution {
public:
    
    int shortestPath(vector<vector<int>>& g, int k) {
        
        vector<vector<int>> dir;
        
        dir={{-1,0},{0,-1},{0,1},{1,0}};
        
        queue<vector<int>> q;
        
        q.push({0,0,k,0});
        
        map<vector<int>,int> vis;
        
        vis[{0,0}]=k;
        
        int steps=0;
        
        while(!q.empty()){
            
            int len=q.size();
            
            while (len--) {

                auto v = q.front();

                q.pop();

                if (v[0] == g.size() - 1 && v[1] == g[0].size() - 1)
                    return v[3];

                for (auto d : dir) {

                    int x = v[0] + d[0], y = v[1] + d[1];

                    if (x<0||y<0||x>=g.size()||y>=g[0].size())
                        continue;
                    
                    if (g[x][y] == 1) {

                        if (v[2] == 0||(vis.find({x,y})!=vis.end()&&vis[{x,y}]>=v[2]-1))
                            continue;

                        q.push({x, y, v[2] - 1, v[3]+1});
                        
                        vis[{x,y}]=v[2]-1;
                    }
                    else {

                        if(vis.find({x,y})!=vis.end()&&vis[{x,y}]>=v[2])
                            continue;
                        
                        q.push({x, y, v[2],v[3]+1});
                        
                        vis[{x,y}]=v[2];
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};