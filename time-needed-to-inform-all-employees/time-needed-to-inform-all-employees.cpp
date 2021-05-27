class Solution {
public:
    
    vector<vector<int>> graph;
    
    int res;
    
    void dfs(int u, int par, int val, vector<int>& informTime){
        
        if(!graph[u].size())
            res=max(res, val);
                
        for(int v:graph[u])
            if(v!=par)
                dfs(v,u,val+informTime[v],informTime);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        res=0;
        
        graph.resize(n);
        
        for(int i=0;i<n;i++)
            if(manager[i]!=-1)
                graph[manager[i]].push_back(i);
        
        int head;
        
        for(int i=0;i<n;i++)
            if(manager[i]==-1)
                head=i;
        
        dfs(head,-1,informTime[head],informTime);
        
        return res;
    }
};