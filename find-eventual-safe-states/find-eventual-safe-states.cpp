class Solution {
public:
    
    unordered_map<int,int> inCycle;
    
    bool dfs(vector<vector<int>>& graph, int u, vector<int> &vis){
        
        vis[u]=1;
        
        if(!graph[u].size())
            return 0;
        
        inCycle.insert({u,1});
        
        bool res=0;
        
        for(int v:graph[u]){
            
            if(inCycle.find(v)!=inCycle.end()){
                res=1;
                continue;
            }
            
            if(vis[v]){
                // return/ 1;
                continue;
            }
            
            res|=dfs(graph, v, vis);
        }
        
        if(!res)
            inCycle.erase(u);
                
        // vis[u]=0;
        
        return res;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int> vis(graph.size());
        
        for(int i=0;i<graph.size();i++)
            if(!vis[i]&&inCycle.find(i)==inCycle.end())
                dfs(graph, i, vis);
    
        vector<int> res;
        
        for(int i=0;i<graph.size();i++)
            if(inCycle.find(i)==inCycle.end())
                res.push_back(i);
        
        return res;
    }
};