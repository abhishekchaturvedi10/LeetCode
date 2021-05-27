class Solution {
public:
    
    int vis[100005];
    
    vector<vector<int>> graph;
    
    static bool comp(pair<int,int>& a, pair<int,int>& b){
        return a.first>b.first;
    }
    
    void dfs(int u){
        
        vis[u]=1;
                
        for(int v:graph[u])
            if(!vis[v])
                dfs(v);
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        memset(vis,0,sizeof(vis));
        
        graph.resize(n);
        
        vector<pair<int,int>> indeg(n);
        
        for(int i=0;i<n;i++)
            indeg[i]={0,i};
        
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            indeg[i[1]].first++;
        }
        
        sort(indeg.begin(),indeg.end());
        
        vector<int> res;
        
        for(int i=0;i<n;i++){
            if(!vis[indeg[i].second]){
                res.push_back(indeg[i].second);
                dfs(indeg[i].second);
            }
        }
        
        return res;
    }
};