class Solution {
public:
    
    map<int,int> parent;
    map<string, int> seen;
    
    int find(int i){
        
        if(parent[i]==i)
            return i;
        
        return parent[i]=find(parent[i]);
    }
    
    void Union(int i, int j){
        parent[i]=j;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        for(int i=0;i<accounts.size();i++){
            
            parent[i]=i;
            
            for(int j=1;j<accounts[i].size();j++){
                
                if(seen.find(accounts[i][j])!=seen.end()){
                    parent[find(i)]=find(seen[accounts[i][j]]);
                }
                else
                    seen[accounts[i][j]]=i;
            }
        }
        
        unordered_map<int, vector<string>> mres;
        
        for (auto it : seen) {
            int f = find(it.second);
            mres[f].push_back(it.first);
        }
        
        vector<vector<string>> res;
        
        for (auto it : mres) {
            
            sort(it.second.begin(), it.second.end());
            
            vector<std::string> tmp = {accounts[it.first][0]};
            
            for (auto i : it.second) 
                tmp.push_back(i);
            
            res.push_back(tmp);
        }
        
        return res;
    }
};