class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res=0, inc=1, dec=1, n=nums.size();
        for(int i=1;i<n;i++) {
            if(nums[i]>nums[i-1]) {
                inc++;
            } else {
                res=max(res,inc);
                inc=1;
            }
            if(nums[i-1]>nums[i]) {
                dec++;
            } else {
                res=max(res,dec);
                dec=1;
            }
        }
        return max({res,dec,inc});
    }
};