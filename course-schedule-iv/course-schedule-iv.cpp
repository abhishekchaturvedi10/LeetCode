class Solution {
public:
        
    bool dfs(vector<vector<int>> &graph, int u, int v, vector<int> &vis){
                
        if(u==v)
            return true;
        
        vis[u]=true;
        
        for(int vv:graph[u])
            if(!vis[vv]&&dfs(graph, vv, v, vis))
                return true;
        
        return false;
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        
        int n=numCourses;
        
        vector<vector<int>> graph(n);
            
        for(auto p:prereq)
            graph[p[0]].emplace_back(p[1]);
        
        vector<bool> res;
        
        for(int i=0;i<queries.size();i++){
            cout<<i<<endl;
            vector<int> vis(n);
            res.emplace_back(dfs(graph,queries[i][0],queries[i][1],vis));
        }
        
        return res;
    }
};