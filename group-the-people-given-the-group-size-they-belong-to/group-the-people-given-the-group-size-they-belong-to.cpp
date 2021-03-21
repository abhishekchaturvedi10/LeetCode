class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>> a(n+1);
        for(int i=0;i<n;i++){
            a[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(int i=0;i<=n;i++){
            vector<int> cur;
            for(int j=0;j<a[i].size();j++){
                cur.push_back(a[i][j]);
                if(cur.size()==i){
                    res.push_back(cur);
                    cur.clear();
                }
            }
        }
        return res;
    }
};