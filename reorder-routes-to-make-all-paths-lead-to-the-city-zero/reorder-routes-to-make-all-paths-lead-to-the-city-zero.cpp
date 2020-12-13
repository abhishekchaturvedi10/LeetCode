class Solution {
public:
    map<int,vector<int>> g,g1; map<int,int> vis; int ans=0;
    void dfs(int val){
        if(vis[val])
            return;
        vis[val]++;
        for(int i:g[val])
            if(!vis[i]){
                int f=0;
                for(int j:g1[val])
                    if(j==i)
                        f=1;
                if(f)
                    ans++;
                dfs(i);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();i++){
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
            g1[connections[i][0]].push_back(connections[i][1]);
        }
        dfs(0);
        return ans;
    }
};
