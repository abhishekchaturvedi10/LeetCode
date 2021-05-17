class Solution {
public:
    
    stack<int> s;
    
    bool cycleDetected;
    
    int vis[2004];
    
    bool instack[2004];
    
    void toposort(vector<vector<int>> &graph, int u){
        
        vis[u]=1;
        
        instack[u]=true;
        
        for(int v:graph[u]){
            if(!vis[v]){
                toposort(graph,v);
            }
            else{
                if(instack[v]){
                    cycleDetected=true;
                }
            }
        }
        
        instack[u]=false;
        
        s.push(u);
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        
        vector<vector<int>> graph(n,vector<int>());
                
        for(auto i:prereq){
            graph[i[0]].push_back(i[1]);
        }
        
        memset(vis, sizeof(vis), 0);
        
        memset(instack, sizeof(instack), false);
        
        cycleDetected=false;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                toposort(graph,i);
            }
        }
        
        if(cycleDetected)
            return {};
        
        vector<int> res;
        
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};