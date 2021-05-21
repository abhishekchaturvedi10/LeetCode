class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
                
        vector<vector<vector<int>>> g(n);
        
        for(auto const& edge:edges)
            g[edge[0]].push_back({edge[1],edge[2]}), g[edge[1]].push_back({edge[0],edge[2]});
        
        int res, maxCount=INT_MAX;
        
        for(int i=0;i<n;i++){
            
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
            
            q.push({0,i});
            
            int count=0;
            
            vector<int> vis(n);
            
            while(!q.empty()){
                
                auto u=q.top();
                                        
                q.pop();
                    
                if(vis[u.second])
                    continue;
                    
                vis[u.second]=1;
                    
                count++;
                                        
                for(auto i:g[u.second])
                    if(u.first+i[1]<=distanceThreshold&&!vis[i[0]])
                        q.push({u.first+i[1],i[0]});
            }
                        
            if(count<=maxCount)
                maxCount=count, res=i;
        }
        
        return res;
    }
};