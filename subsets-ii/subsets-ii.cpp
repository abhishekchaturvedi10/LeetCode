class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, vector<int>& a, int i){
        if(i>nums.size())
            return;
        ans.push_back(a);
        for(int j=i;j<nums.size();j++){
            if(j>i and nums[j]==nums[j-1])
                continue;
            a.push_back(nums[j]);
            helper(nums, a, j+1);
            a.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> a;
        sort(nums.begin(), nums.end());
        helper(nums,a,0);
        return ans;
    }
};