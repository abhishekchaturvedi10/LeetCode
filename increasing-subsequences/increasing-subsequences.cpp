class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &nums, int i, vector<int> &a){
        if(a.size()>1)
            res.push_back(a);
        if(i==nums.size())
            return;
        map<int, int> seen;
        for(int j=i;j<nums.size();j++){
            if(seen[nums[j]])
                continue;
            if(a.size()>0&&a.back()>nums[j])
                continue;
            a.push_back(nums[j]);
            helper(nums, j+1, a);
            a.pop_back();
            seen[nums[j]]++;
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> a;
        helper(nums, 0, a);
        return res;
    }
};