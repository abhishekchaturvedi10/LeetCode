class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l=0, r=0, subarraySum=0, res=INT_MAX;

        while(r<nums.size()) {
            subarraySum += nums[r];
            while(r>=l&&subarraySum>=target) {
                res=min(res,r-l+1);
                subarraySum-=nums[l];
                l++;
            }
            r++;
        }

        return res==INT_MAX?0:res;
    }
};