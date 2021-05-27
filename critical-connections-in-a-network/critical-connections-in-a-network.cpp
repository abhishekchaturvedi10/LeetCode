class Solution {
public:
    
    int par[200005], vis[200005], disc[200005], low[200005], time;
    
    vector<vector<int>> graph, res;
    
    void dfs(int u){
        
        vis[u]=1;
        
        low[u]=disc[u]=time++;
        
        for(int v:graph[u]){
            
            if(!vis[v]){
                
                par[v]=u;
                
                dfs(v);
                
                low[u]=min(low[v],low[u]);
                
                if(low[v]>disc[u])
                    res.push_back({u,v});
            }
            else if(par[u]!=v)
                low[u]=min(low[u],disc[v]);
                
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        memset(vis,0,sizeof(vis));
        memset(par,-1,sizeof(par));
        
        graph.resize(n);
        
        for(auto i:connections)
            graph[i[0]].push_back(i[1]), graph[i[1]].push_back(i[0]);
        
        time=0;
        
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(i);
        
        return res;
    }
};