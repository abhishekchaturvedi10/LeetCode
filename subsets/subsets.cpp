class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> nums, vector<int> a, int i){
        if(i==nums.size())
            return;
        a.push_back(nums[i]);
        ans.push_back(a);
        for(int j=i+1;j<nums.size();j++){
            helper(nums, a, j);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        ans.push_back(a);
        for(int i=0;i<nums.size();i++)
            helper(nums,a,i);
        return ans;
    }
};
