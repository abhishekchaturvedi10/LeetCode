class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        map<vector<int>, int> vis;
        
        pq.push({grid[0][0], 0, 0});
        
        int res=0;
        
        while(!pq.empty()){
            
            auto v = pq.top();
            
            res = max(res, v[0]);
            
            if(v[1]==grid.size()-1&&v[2]==grid[0].size()-1)
                return res;
            
            pq.pop();
            
            vis[{v[1], v[2]}] = 1;
            
            if(v[1]>0&&!vis[{v[1]-1, v[2]}])
                pq.push({grid[v[1]-1][v[2]], v[1]-1, v[2]});
            
            if(v[1]+1<grid.size()&&!vis[{v[1]+1, v[2]}])
                pq.push({grid[v[1]+1][v[2]], v[1]+1, v[2]});
            
            if(v[2]>0&&!vis[{v[1], v[2]-1}])
                pq.push({grid[v[1]][v[2]-1], v[1], v[2]-1});
            
            if(v[2]+1<grid[0].size()&&!vis[{v[1], v[2]+1}])
                pq.push({grid[v[1]][v[2]+1], v[1], v[2]+1});
        }
        
        return res;
    }
};