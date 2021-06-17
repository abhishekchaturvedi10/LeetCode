class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        unordered_map<int,int> m;
        
        int mx=0, cur=0;
        
        for(auto &i:wall){
            for(int j=0;j<i.size()-1;j++){
                cur+=i[j];
                m[cur]++;
            }
            mx=max(cur,mx);
            cur=0;
        }
            
        int res=wall.size();
        
        for(auto &i:m)
            res=min(res,(int)wall.size()-i.second);
        
        return res;
    }
};