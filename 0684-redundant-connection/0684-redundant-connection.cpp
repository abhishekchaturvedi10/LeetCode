class Solution {
public:
    int find(int parent[], int i){
        if(parent[i]==-1)
            return i;
        return parent[i]=find(parent,parent[i]);
    }
    void Union(int parent[], int x, int y){
        parent[x]=y;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int parent[edges.size()+1];
        memset(parent,-1,sizeof(parent));
        for(auto i:edges){
            int x=find(parent, i[0]),y=find(parent, i[1]);
            if(x==y)
                return i;
            else
                Union(parent, x, y);
        }
        return edges[0];
    }
};