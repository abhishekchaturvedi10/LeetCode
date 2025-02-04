class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int curSum=nums[0], res=0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]>nums[i-1]) {
                curSum+=nums[i];
            } else {
                res=max(res,curSum);
                curSum=nums[i];
            }
        }
        return max(res,curSum);
    }
};