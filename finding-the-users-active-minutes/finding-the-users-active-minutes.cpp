class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        unordered_map<int,unordered_set<int>> res;
        
        for(auto i:logs)
            res[i[0]].insert(i[1]);
        
        vector<int> ans(k);
        
        for(auto i:res)
            if(i.second.size())
                ans[i.second.size()-1]++;
        
        return ans;
    }
};