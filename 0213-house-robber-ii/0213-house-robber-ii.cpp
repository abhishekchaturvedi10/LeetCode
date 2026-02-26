class Solution {
public:

    int helper(vector<int>& nums, int l, int r) {
        vector<int> dp;
        dp.push_back(nums[l]);
        dp.push_back(max(nums[l],nums[l+1]));
        for(int i=l+2;i<=r;i++) {
            int x=dp.size();
            dp.push_back(max(dp[x-1],nums[i]+dp[x-2]));
        }
        return dp.back();
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) {
            return nums[0];
        }
        if(n==2) {
            return max(nums[0],nums[1]);
        }
        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};