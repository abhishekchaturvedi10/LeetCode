class Solution {
public:
    vector<vector<int>> ans;
    map<int, int> m;
    void helper(vector<int> &a, int n){
        if(n==a.size()){
            ans.push_back(a);
            return;
        }
        for(auto i:m){
            if(i.second){
                a.push_back(i.first);
                int c=i.second;
                m[i.first]=c-1;
                helper(a, n);
                m[i.first]=c;
                a.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i:nums)
            m[i]++;
        vector<int> a;
        helper(a, nums.size());
        return ans;
    }
};