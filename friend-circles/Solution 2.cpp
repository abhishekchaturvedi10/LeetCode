class Solution {
public:
    int parent[205];
    int find(int i){
        if(parent[i]==-1)
            return i;
        return find(parent[i]);
    }
    void Union(int i,int j){
        parent[i]=j;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int ans=0;
        memset(parent,-1,sizeof(parent));
        vector<pair<int,int>> edges;
        for(int i=0;i<M.size()-1;i++)
            for(int j=i+1;j<M.size();j++)
                if(M[i][j]){
                    int x=find(i), y=find(j);
                    if(x!=y)
                        Union(x,y);
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