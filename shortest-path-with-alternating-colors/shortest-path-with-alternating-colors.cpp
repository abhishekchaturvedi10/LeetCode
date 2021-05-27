class Solution {
public:
    
    vector<int> res1, res2;
    
    vector<vector<int>> rg, bg;
    
    void dfs(int u, int prev, int dist){
                         
        if(prev==0&&res1[u]<dist)
            return;
        
        if(prev==1&&res2[u]<dist)
            return;
        
        // cout<<u<<" ";
        
        if(prev==0)
            res1[u]=min(res1[u],dist);
        else
            res2[u]=min(res2[u],dist);
        
        if(prev==0)
            for(int i:bg[u])
                dfs(i, 1, dist+1);
        else
            for(int i:rg[u])
                dfs(i, 0, dist+1);
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
        rg.resize(n);
        bg.resize(n);
        
        for(auto const &edge:red_edges)
            rg[edge[0]].push_back(edge[1]);
        
        for(auto const &edge:blue_edges)
            bg[edge[0]].push_back(edge[1]);
        
        res1.assign(n, INT_MAX);
        res2.assign(n, INT_MAX);
        
        dfs(0, 1, 0);
        // cout<<endl;
        dfs(0, 0, 0);
        
        vector<int> res(n);
        
        for(int i=0;i<n;i++){
            int mini=min(res1[i],res2[i]);
            res[i]=mini==INT_MAX?-1:mini;
        }
        
        return res;
    }
};