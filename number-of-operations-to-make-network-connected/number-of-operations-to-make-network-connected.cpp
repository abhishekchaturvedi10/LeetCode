class Solution {
public:
    int parent[100005];
    int find(int i){
        if(parent[i]!=i) parent[i]=find(parent[i]);
        return parent[i];
    }
    void Union(int x, int y){
        parent[x]=y;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        int ans=0;
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(auto i:connections){
            int x=find(i[0]), y=find(i[1]);
            if(x==y)
                ans++;
            else
                Union(x, y);
        }
        return ans-(connections.size()-n+1);
    }
};
