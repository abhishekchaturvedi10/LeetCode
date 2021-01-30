class Solution {
public:
    vector<vector<int>> res;
    void helper(int k, int n, int start, vector<int> &cur){
        if(n<0)
            return;
        if(k==0){
            if(n==0)
                res.push_back(cur);
            return;
        }
        for(int i=start;i<=9;i++){
            if(i>n)
                return;
            cur.push_back(i);
            helper(k-1, n-i, i+1, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45)
            return res;
        vector<int> cur;
        helper(k, n, 1, cur);
        return res;
    }
};