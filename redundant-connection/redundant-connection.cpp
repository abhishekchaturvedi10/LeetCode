class Solution {
public:
    int find(int parent[], int i){
        if(parent[i]==-1)
            return i;
        return find(parent,parent[i]);
    }
    void Union(int parent[], int x, int y){
        parent[x]=y;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int parent[edges.size()+1];
        for(int i=1;i<=edges.size();i++)
            parent[i]=-1;
        for(auto i:edges){
            int x=find(parent, i[0]),y=find(parent, i[1]);
            if(x==y)
                return i;
            else
                Union(parent, x,y);
        }
        return edges[0];
    }
};
