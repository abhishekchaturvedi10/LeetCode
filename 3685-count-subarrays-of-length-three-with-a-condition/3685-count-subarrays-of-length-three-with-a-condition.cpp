class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int res=0;
        for(int i=0;i+2<nums.size();i++) {
            res+=(nums[i]+nums[i+2])*2==nums[i+1];
        }
        return res;
    }
};