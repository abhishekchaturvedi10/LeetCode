class Solution {
public:
    
    int check(int x, int y, int n, int m) {
        
        if(x<0||y<0||x>=n||y>=m)
            return 0;
        
        return 1;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n=heights.size(), m=heights[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        dist[0][0]=0;
        
        pq.push({0,0,0});
        
        const int x[4] = {-1,0,1,0}, y[4] = {0,1,0,-1};
        
        while(!pq.empty()) {
            
            vector<int> v=pq.top();
            
            pq.pop();
            
            if(v[1]==n-1&&v[2]==m-1)
                return v[0];
            
            for(int i=0;i<4;i++) {
                
                if(check(v[1]+x[i], v[2]+y[i], n, m)&&dist[v[1]+x[i]][v[2]+y[i]]>max(v[0],abs(heights[v[1]+x[i]][v[2]+y[i]]-heights[v[1]][v[2]]))) {
                    
                    dist[v[1]+x[i]][v[2]+y[i]]=max(v[0],abs(heights[v[1]+x[i]][v[2]+y[i]]-heights[v[1]][v[2]]));
                    
                    pq.push({dist[v[1]+x[i]][v[2]+y[i]], v[1]+x[i], v[2]+y[i]});
                }
            }
        }
        
        return 0;
    }
};