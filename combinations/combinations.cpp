class Solution {
public:
    vector<vector<int>> res;
    void helper(int n, int k, vector<int> &cur){
        if(k<=0){
            res.push_back(cur);
            return;
        }
        int j=1;
        if(cur.size())
            j=cur.back()+1;
        for(int i=j;i<=n;i++){
            cur.push_back(i);
            helper(n, k-1, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        helper(n, k, cur);
        return res;
    }
};