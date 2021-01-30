class Solution {
public:
    vector<vector<int>> res;
    void helper(int n, int k, vector<int> &cur, int start){
        if(k==0){
            res.push_back(cur);
            return;
        }
        if(n-start+1<k)
            return;
        for(int i=start;i<=n;i++){
            cur.push_back(i);
            helper(n, k-1, cur, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        helper(n, k, cur, 1);
        return res;
    }
};
