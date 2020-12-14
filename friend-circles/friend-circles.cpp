class Solution {
public:
    int parent[205];
    int find(int i){
        if(parent[i]==i)
            return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int i,int j){
        parent[i]=j;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int ans=0;
        for(int i=0;i<=M.size();i++)
            parent[i]=i;
        vector<pair<int,int>> edges;
        for(int i=0;i<M.size()-1;i++)
            for(int j=i+1;j<M.size();j++)
                if(M[i][j])
                    edges.push_back({i,j});
        for(auto i:edges){
            cout<<i.first<<" "<<i.second<<endl;
            int x=find(i.first), y=find(i.second);
            cout<<x<<" "<<y<<endl;
            if(x!=y)
                Union(x,y);
            cout<<parent[i.first]<<" "<<parent[i.second]<<endl<<endl;
        }
        map<int,int> m;
        for(int i=0;i<M.size();i++){
            if(!m[find(i)])
                ans++;
            m[find(i)]++;
        }
        return ans;
    }
};
