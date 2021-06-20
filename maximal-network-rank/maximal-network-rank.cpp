class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,unordered_set<int>> m;
        
        for(auto &i:roads){
            m[i[0]].insert(i[1]);
            m[i[1]].insert(i[0]);
        }
        
        int res=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(i==j)
                    continue;
                
                if(m[i].find(j)!=m[i].end())
                    res=max(res,(int)m[i].size()+(int)m[j].size()-1);
                else
                    res=max(res,(int)m[i].size()+(int)m[j].size());
            }
        }
        
        return res;
    }
};