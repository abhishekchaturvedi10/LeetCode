class Solution {
public:
    
    map<pair<int,int>,pair<int,int>> parent;
    
    pair<int,int> find(pair<int,int> p){
        
        if(parent[p]==p)
            return p;
        
        return parent[p]=find(parent[p]);
    }
    
    void unite(pair<int,int> p1, pair<int,int> p2){
        parent[find(p1)]=find(p2);
    }
    
    int countServers(vector<vector<int>>& grid) {
        
        int m=grid.size(), n=grid[0].size();
        
        unordered_map<int,vector<pair<int,int>>> row;
        unordered_map<int,vector<pair<int,int>>> col;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)
                    row[i].push_back({i,j}), col[j].push_back({i,j});
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                parent[{i,j}]={i,j};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(auto k:row[i])
                        unite(k,{i,j});
                    for(auto k:col[j])
                        unite(k,{i,j});
                }
            }
        }
        
        int res=0;
        
        map<pair<int,int>,int> sizes; 
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]&&find({i,j})!=make_pair(i,j))
                    sizes[find({i,j})]++;
        
        for(auto i:sizes)
            res+=i.second+1;
        
        return res;
    }
};